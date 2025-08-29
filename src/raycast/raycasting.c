#include "game.h"
#include "graphics.h"
#include "maths.h"

static void sky_floor(game *game)
{
    int           vertical_offset;
    int           width;
    int           height;
    int           total;
    int           i;
    unsigned int *pix;

    vertical_offset = game->player.jump_height;
    width = game->display.ds_px->clipable.clip_width;
    height = game->display.ds_px->clipable.clip_height;
    total = (width * height) - 1;
    i = (width * height) / 2 + vertical_offset * width;
    pix = (unsigned int *)game->display.ds_px->pixels;
    while (total > i) {
        pix[total] = BLACK;
        total -= 1;
    }
    while (i >= 0) {
        pix[i] = BLUE;
        i -= 1;
    }
}

static void draw_wall(game *game, int size_wall, int player_pos, t_accurate_pos ray)
{
    unsigned int     color;
    t_bunny_position pix;
    int              vertical_offset;
    int              width, height;
    int              wall_type;
    int              i;

    i = 0;
    wall_type = get_cell(&game->maps.map[game->player.current_map_index], ray);
    vertical_offset = game->player.jump_height;
    width = game->display.ds_px->clipable.clip_width;
    height = game->display.ds_px->clipable.clip_height;
    pix.x = width - player_pos;
    pix.y = (height / 2) + vertical_offset;
    if (wall_type == 2) {
        color = mk_colour(255, 0, 0, 255);
    }
    else if (wall_type == 1) {
        color = mk_colour(255, 255, 255, 255);
    }
    else {
        color = mk_colour(255, 255, 0, 255);
    }
    fprintf(stderr, "size_wall: %d\n", size_wall);
    while (i <= size_wall / 2) {

        pix.y += 1;
        i += 1;
    }
    i = 0;
    pix.y = (height / 2) + vertical_offset;
    while (i <= size_wall / 2) {
        put_pixel(game->display.ds_px, &pix, color);
        pix.y -= 1;
        i += 1;
    }
}

static double compute_wall_size(game *game, ray_result result, double ray_angle)
{
    double corrected_distance;
    double wall_size;

    corrected_distance = result.distance * cos(game->player.angle - ray_angle);

    if (corrected_distance < 0.0001)
        corrected_distance = 0.0001;

    wall_size = (game->display.ds_px->clipable.clip_height / corrected_distance) * 0.75;

    if (wall_size > game->display.ds_px->clipable.clip_height)
        wall_size = game->display.ds_px->clipable.clip_height;

    return wall_size;
}

static void fov(game *game)
{
    double angle, coef;
    int    i;

    i = 0;
    coef = deg_to_rads(game->fov) / (double)game->display.ds_px->clipable.clip_width;
    angle = deg_to_rads(game->player.angle) - deg_to_rads(game->fov / 2);

    while (i < game->display.ds_px->clipable.clip_width) {
        ray_result result =
            send_ray(&game->maps.map[game->player.current_map_index], &game->player.pos, angle);

        double size_wall = compute_wall_size(game, result, angle);

        draw_wall(game, size_wall, i, result.pos);

        angle += coef;
        i++;
    }
}

void raycasting(game *game)
{
    clear_pixelarray(game->display.ds_px, 0x000000FF);
    sky_floor(game);
    fov(game);
}

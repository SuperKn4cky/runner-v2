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
        color = mk_colour(255, 0, 0, 1);
    }
    else if (wall_type == 1 || wall_type == 0) {
        color = mk_colour(255, 255, 255, 1);
    }
    else {
        color = mk_colour(255, 255, 0, 1);
    }
    while (i <= size_wall / 2) {
        put_pixel(game->display.ds_px, &pix, color);
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

static void fov(game *game)
{
    double angle, coef, size_wall;
    int    i;

    i = 0;
    coef = game->fov / (double)game->display.ds_px->clipable.clip_width;
    angle = game->player.angle - (game->fov / 2);
    while (i < game->display.ds_px->clipable.clip_width) {
        ray_result result = send_ray(&game->maps.map[game->player.current_map_index], &game->player.pos, deg_to_rads(angle));
        size_wall = ((game->display.ds_px->clipable.clip_height / result.distance) *
                     (double)(cos(deg_to_rads(angle)) - deg_to_rads(angle))) *
                    0.75;
        if (size_wall > game->display.ds_px->clipable.clip_height) {
            size_wall = game->display.ds_px->clipable.clip_height;
        }
        draw_wall(game, size_wall, i, result.pos);
        angle += coef;
        i += 1;
    }
}

void raycasting(game *game)
{
    clear_pixelarray(game->display.ds_px, 0x000000FF);
    sky_floor(game);
    fov(game);
}

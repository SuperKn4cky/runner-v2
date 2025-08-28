#include "game.h"

void game_cleanup(game *game)
{
    if (!game)
        return;
    if (game->display.ds_win || game->display.ds_px) {
        display_cleanup(&game->display);
    }
    if (game->map.grid) {
        for (unsigned int i = 0; i < game->map.height; i++) {
            free(game->map.grid[i]);
        }
        free(game->map.grid);
    }
}

t_bunny_response handle_input(game *game, t_bunny_keysym keycode, t_bunny_event_state state)
{
    (void)state;
    if (!game)
        return (EXIT_ON_ERROR);

    switch (keycode) {
    case BKS_ESCAPE:
        game->pause = !game->pause;
        bunny_set_mouse_visibility(game->display.ds_win, game->pause);
        break;
    case BKS_UP:
    case BKS_Z:
        // Move forward
        break;
    case BKS_DOWN:
    case BKS_S:
        // Move backward
        break;
    case BKS_LEFT:
    case BKS_Q:
        // Rotate left
        break;
    case BKS_RIGHT:
    case BKS_D:
        // Rotate right
        break;
    case BKS_SPACE:
        // Start jump
        break;
    default:
        break;
    }
    return (GO_ON);
}

bool game_init(game *game)
{
    if (load_map_from_file(&game->map, "map.txt")) {
        return false;
    }

    if (display_init(&game->display)) {
        return false;
    }

    if (player_init(&game->player, game->map.player_spawn)) {
        display_cleanup(&game->display);
        return false;
    }

    game->game_speed = 60;
    game->fov = 60;
    game->pause = false;
    game->end = false;

    return true;
}
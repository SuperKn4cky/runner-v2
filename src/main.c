#include "game.h"

t_bunny_response key_event(t_bunny_event_state state, t_bunny_keysym keycode, void *data)
{
    game *game;

    game = data;
    handle_input(game, keycode, state);
    return (GO_ON);
}

t_bunny_response loop(void *data)
{
    game *game;

    game = data;
    if (!game->pause && !game->end) {
        render(game);
        display_refresh(&game->display);
    }
    return GO_ON;
}

int main(void)
{
    // Initialize game
    game my_game;
    if (!game_init(&my_game)) {
        game_cleanup(&my_game);
        return EXIT_FAILURE;
    }

    // Main game loop
    bunny_set_key_response(key_event);
    bunny_set_loop_main_function(loop);
    bunny_loop(my_game.display.ds_win, 60, &my_game);
    bunny_stop(my_game.display.ds_win);

    return EXIT_SUCCESS;
}

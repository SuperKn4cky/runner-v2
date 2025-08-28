#ifndef GAME_H_
#define GAME_H_

#include "display.h"
#include "map.h"
#include "player.h"
#include "types.h"
#include <lapin.h>

typedef struct {
    display      display;
    player       player;
    maps         maps;
    unsigned int game_speed;
    unsigned int fov;
    bool         pause;
    bool         end;
} game;

bool             game_init(game *g);
t_bunny_response handle_input(game *g, t_bunny_keysym keycode, t_bunny_event_state state);
void             render(game *g);
void             game_cleanup(game *g);

#endif /* !GAME_H_ */

#ifndef MAP_H_
#define MAP_H_

#include "types.h"
#include <lapin.h>

typedef struct {
    t_bunny_pixelarray *background;
    t_bunny_position    player_spawn;
    double              spawn_angle;
    unsigned int        width;
    unsigned int        height;
    unsigned int       *grid;
} map;

typedef struct {
    int  map_count;
    map *map;
} maps;

bool         load_maps_from_file(maps *m, const char *filename);
bool         is_wall(t_accurate_pos pos);
bool         is_within_bounds(t_accurate_pos pos);
unsigned int get_cell(t_accurate_pos pos);

#endif /* !MAP_H_ */

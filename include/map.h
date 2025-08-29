#ifndef MAP_H_
#define MAP_H_

#include "player.h"
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

typedef struct {
    t_accurate_pos pos;
    double         distance;
} ray_result;

bool         load_maps_from_file(maps *maps, const char *filename);
bool         is_within_bounds(map *map, t_accurate_pos pos);
bool         is_wall(map *map, t_accurate_pos pos);
unsigned int get_cell(map *map, t_accurate_pos pos);
ray_result   send_ray(map *map, const t_accurate_pos *start, double angle);

#endif /* !MAP_H_ */

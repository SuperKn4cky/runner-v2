#include "map.h"
#include <stdio.h>

bool load_maps_from_file(maps *m, const char *filename)
{
    FILE *file;
    int   map_count;

    if (!m || !filename)
        return false;

    file = fopen(filename, "r");
    if (!file) {
        perror("Failed to open map file");
        return false;
    }

    if (fscanf(file, "%d\n", &map_count) != 1 || map_count <= 0) {
        fclose(file);
        fprintf(stderr, "Invalid map count in file\n");
        return false;
    }

    m->map = malloc(sizeof(map) * map_count);
    if (!m->map) {
        fclose(file);
        perror("Failed to allocate memory for maps");
        return false;
    }
    m->map_count = map_count;

    for (int i = 0; i < map_count; i++) {
        unsigned int width, height;
        if (fscanf(file, "%u %u\n", &width, &height) != 2 || width == 0 || height == 0) {
            fclose(file);
            fprintf(stderr, "Invalid dimensions for map %d\n", i);
            return false;
        }

        m->map[i].width = width;
        m->map[i].height = height;
        m->map[i].grid = malloc(sizeof(unsigned int) * width * height);
        if (!m->map[i].grid) {
            fclose(file);
            perror("Failed to allocate memory for map grid");
            return false;
        }

        for (unsigned int y = 0; y < height; y++) {
            for (unsigned int x = 0; x < width; x++) {
                if (fscanf(file, "%u", &m->map[i].grid[y * width + x]) != 1) {
                    fclose(file);
                    fprintf(stderr, "Invalid grid data for map %d at (%u, %u)\n", i, x, y);
                    return false;
                }
            }
        }

        if (fscanf(file, "%u %u %lf\n", &m->map[i].player_spawn.x, &m->map[i].player_spawn.y,
                   &m->map[i].spawn_angle) != 3) {
            fclose(file);
            fprintf(stderr, "Invalid spawn data for map %d\n", i);
            return false;
        }
    }

    fclose(file);
    return true;
}
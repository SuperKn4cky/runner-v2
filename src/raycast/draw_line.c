#include <lapin.h>
#include <stdlib.h>
#include <unistd.h>
#include "line.h"
#include "maths.h"
#include "graphics.h"

static void width(struct line *line, t_bunny_pixelarray *px, unsigned int color)
{
    if (line->width_diff >= line->height_diff) {
        line->position.x = line->good_pos_a.x;
        while (line->position.x <= line->good_pos_b.x) {
            line->ratio = get_ratio(line->pos_a.x, line->pos_b.x, line->position.x);
            line->position.y = get_value(line->pos_a.y, line->pos_b.y, line->ratio);
            put_pixel(px, &line->position, color);
            line->position.x += 1;
        }
    }
}

static void height(struct line *line, t_bunny_pixelarray *px, unsigned int color)
{
    if (line->width_diff < line->height_diff) {
        line->position.y = line->good_pos_a.y;
        while (line->position.y <= line->good_pos_b.y) {
            line->ratio = get_ratio(line->pos_a.y, line->pos_b.y, line->position.y);
            line->position.x = get_value(line->pos_a.x, line->pos_b.x, line->ratio);
            put_pixel(px, &line->position, color);
            line->position.y += 1;
        }
    }
}

void stu_draw_line(t_bunny_pixelarray *px, t_bunny_position *pos_a, t_bunny_position *pos_b,
                   unsigned int color)
{
    struct line line;

    line.pos_a = *pos_a;
    line.pos_b = *pos_b;
    line.good_pos_a = *pos_a;
    line.good_pos_b = *pos_b;
    if (pos_b->x >= pos_a->x) {
        line.width_diff = pos_b->x - pos_a->x;
    }
    else if (pos_b->x < pos_a->x) {
        line.width_diff = pos_a->x - pos_b->x;
        line.good_pos_a.x = pos_b->x;
        line.good_pos_b.x = pos_a->x;
    }
    if (pos_b->y >= pos_a->y) {
        line.height_diff = pos_b->y - pos_a->y;
    }
    else if (pos_b->y < pos_a->y) {
        line.height_diff = pos_a->y - pos_b->y;
        line.good_pos_a.y = pos_b->y;
        line.good_pos_b.y = pos_a->y;
    }
    width(&line, px, color);
    height(&line, px, color);
}

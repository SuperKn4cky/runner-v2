#include <lapin.h>

void put_pixel(t_bunny_pixelarray *pxa, t_bunny_position *pos, unsigned int color)
{
    int           width;
    int           height;
    int           position;
    unsigned int *pixel;

    if (pos->x < 0 || pos->y < 0) {
        fprintf(stderr, "Error: negative position\n");
        return;
    }
    width = pxa->clipable.clip_width;
    height = pxa->clipable.clip_height;
    pixel = (unsigned int *)pxa->pixels;
    position = (width * pos->y) + pos->x;
    if (position < (width * height) && pos->x < width && pos->y < height) {
        pixel[position] = color;
    }
    else {
        fprintf(stderr, "Error: position out of bounds\n");
    }
}

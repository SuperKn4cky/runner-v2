#include <lapin.h>

void clear_pixelarray(t_bunny_pixelarray *pxa, unsigned int color)
{
    int           width;
    int           height;
    int           total;
    unsigned int *pix;

    width = pxa->clipable.clip_width;
    height = pxa->clipable.clip_height;
    total = width * height;
    pix = (unsigned int *)pxa->pixels;
    for (int i = 0; i < total; i++) {
        pix[i] = color;
    }
}

#ifndef GRAPHICS_H_
#define GRAPHICS_H_

#include "game.h"
#include "types.h"
#include <lapin.h>

void         raycasting(game *game);
unsigned int mk_colour(unsigned char r, unsigned char g, unsigned char b, unsigned char a);
void         clear_pixelarray(t_bunny_pixelarray *pxa, unsigned int color);
void         put_pixel(t_bunny_pixelarray *pxa, t_bunny_position *pos, unsigned int color);

#endif /* !GRAPHICS_H_ */
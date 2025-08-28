unsigned int mk_colour(unsigned char r, unsigned char g, unsigned char b, unsigned char a)
{
    return ((unsigned int)r << 24) | ((unsigned int)g << 16) | ((unsigned int)b << 8) |
           ((unsigned int)a);
}

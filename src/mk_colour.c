union colour {
    unsigned int  full;
    unsigned char rgba[4];
};

unsigned int mk_colour(unsigned char r, unsigned char g, unsigned char b, unsigned char a)
{
    union colour col;
    col.rgba[0] = r;
    col.rgba[1] = g;
    col.rgba[2] = b;
    col.rgba[3] = a;
    return (col.full);
}

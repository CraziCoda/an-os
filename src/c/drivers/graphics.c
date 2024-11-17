#include "graphics.h"

void fbMoveCursor(unsigned short pos)
{
    outb(0x3D4, FB_HIGH_BYTE_CMD);
    outb(0x3D5, (pos >> 8) && 0x00FF);
    outb(0x3D4, FB_LOW_BYTE_CMD);
    outb(0x3D5, pos & 0x00FF);
}

void clear()
{
    fbMoveCursor(10);
}
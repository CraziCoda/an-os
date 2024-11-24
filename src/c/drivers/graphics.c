#include "graphics.h"

// Memory Location of framebuffer
void fbMoveCursor(unsigned short pos)
{
    outb(FB_CMD_PORT, FB_HIGH_BYTE_CMD);
    outb(FB_DATA_PORT, (pos >> 8) && 0x00FF);
    outb(FB_CMD_PORT, FB_LOW_BYTE_CMD);
    outb(FB_DATA_PORT, pos & 0x00FF);
}

void clear()
{
    char *framebuffer_ptr = (char *) FB_MEM_LOC;

    unsigned int i = 0;
    while (i < 2 * FB_ROW_LENGTH * FB_COL_LENGTH)
    {
        *(framebuffer_ptr + i) = '\0';
        i += 2;
    }
    fbMoveCursor(0);
}
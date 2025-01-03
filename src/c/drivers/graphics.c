#include "graphics.h"

char *framebuffer_ptr = (char *)FB_MEM_LOC;
unsigned int cursor_pos = 0;

// Memory Location of framebuffer
void fbMoveCursor(unsigned short pos)
{
    outb(FB_CMD_PORT, FB_HIGH_BYTE_CMD);
    outb(FB_DATA_PORT, (pos >> 8) && 0x00FF);
    outb(FB_CMD_PORT, FB_LOW_BYTE_CMD);
    outb(FB_DATA_PORT, pos & 0x00FF);

    cursor_pos = pos;
}

void clear()
{
    unsigned int i = 0;
    while (i < 2 * FB_ROW_LENGTH * FB_COL_LENGTH)
    {
        *(framebuffer_ptr + i) = '\0';
        i += 2;
    }
    fbMoveCursor(0);
}

void setMoniterColor(char color)
{
    unsigned int i = 1;
    while (i < 2 * FB_ROW_LENGTH * FB_COL_LENGTH)
    {
        *(framebuffer_ptr + i) = color;
        i += 2;
    }
}

void print(char *str)
{
    unsigned int i = 0;
    while (str[i] != '\0')
    {
        *(framebuffer_ptr + (cursor_pos * 2)) = str[i];
        fbMoveCursor(cursor_pos + 1);
        i++;
    }
}
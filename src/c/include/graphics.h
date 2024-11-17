#ifndef GRAPHICS_DRIVER_H
#define GRAPHICS_DRIVER_H
#include "io.h"

// Framebuffer memory location
#define FB_MEM_LOC 0xb8000
// Framebuffer Command Port
#define FB_CMD_PORT 0x3D4
// Framebuffer Data Port
#define FB_DATA_PORT 0x3D5

// I/O command to write to the higher byte.
#define FB_HIGH_BYTE_CMD 14
// I/O command to write to the low byte.
#define FB_LOW_BYTE_CMD 15

// Framebuffer Row length
#define FB_ROW_LENGTH 80
// Framebuffer Column length
#define FB_COL_LENGTH 25

/**
 *  Moves the cursor for the framebuffer in text mode
 *
 * @param pos Position to move the cursor to.
 * @returns void
 */
void fbMoveCursor(unsigned short pos);

void clear();
void setMoniterColor(char);

void print(char);

#endif
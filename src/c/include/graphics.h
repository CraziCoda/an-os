#ifndef GRAPHICS_DRIVER_H
#define GRAPHICS_DRIVER_H
#include "io.h"

// I/O command to write to the higher byte.
#define FB_HIGH_BYTE_CMD 14
// I/O command to write to the low byte.
#define FB_LOW_BYTE_CMD 15

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
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

/**
 *  Clears the framebuffer
 *
 * @returns void
 */
void clear();

/**
 * Sets the color of the moniter
 * @param color The color to set the moniter to
 * @returns void
 */
void setMoniterColor(char color);

/**
 * Prints a character to the framebuffer
 * @param c The character to print
 * @returns void
 */
void printChar(char c);

/**
 * Prints a character to the framebuffer with a given color
 * @param c The character to print
 * @param color The color to print the character in
 * @returns void
 */
void printCharWithColor(char c, char color);

/**
 * Prints a string to the framebuffer
 * @param str The string to print
 * @returns void
 */
void print(char *str);

/**
 * Prints a string to the framebuffer with a given color
 * @param str The string to print
 * @param color The color to print the string in
 * @returns void
 */
void printWithColor(char *str, char color);

#endif
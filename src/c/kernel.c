#include "graphics.h"

int kmain()
{
    clear();
    setMoniterColor(0x0F);
    print("Welcome to the kernel! \t");
    print("This is a test string. \n");
    print("This is another test string.");
    printWithColor("This is a test string with color", (char)0x0A);
    return 0;
}
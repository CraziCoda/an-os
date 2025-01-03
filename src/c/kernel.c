#include "graphics.h"

int kmain()
{
    clear();
    setMoniterColor(0x0F);
    print("Welcome to the kernel! \t");
    print("This is a test string. \t");
    print("This is another test string.");
    return 0;
}
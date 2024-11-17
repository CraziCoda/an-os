#include "graphics.h"

int kmain()
{
    clear();

    char *video_memory = (char *)0xb8000;
    *video_memory = 'A';
    *(video_memory + 1) = 0xb5;
    
    return 0;
}
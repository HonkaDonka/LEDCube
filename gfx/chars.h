#include <stdint.h>

#define CHARS_FRAME_COUNT 56
#define CHARS_FRAME_WIDTH 5
#define CHARS_FRAME_HEIGHT 5

/* Piskel data for "LED Cube" */

static const uint32_t chars_data[56][25] = {
{
0x00000000, 0xff000000, 0xff000000, 0xff000000, 0x00000000, 
0xff000000, 0x00000000, 0x00000000, 0x00000000, 0xff000000, 
0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 
0xff000000, 0x00000000, 0x00000000, 0x00000000, 0xff000000, 
0xff000000, 0x00000000, 0x00000000, 0x00000000, 0xff000000
},
{
0xff000000, 0xff000000, 0xff000000, 0xff000000, 0x00000000, 
0xff000000, 0x00000000, 0x00000000, 0x00000000, 0xff000000, 
0xff000000, 0xff000000, 0xff000000, 0xff000000, 0x00000000, 
0xff000000, 0x00000000, 0x00000000, 0x00000000, 0xff000000, 
0xff000000, 0xff000000, 0xff000000, 0xff000000, 0x00000000
},
{
0x00000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 
0xff000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
0xff000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
0xff000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
0x00000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000
},
{
0xff000000, 0xff000000, 0xff000000, 0xff000000, 0x00000000, 
0xff000000, 0x00000000, 0x00000000, 0x00000000, 0xff000000, 
0xff000000, 0x00000000, 0x00000000, 0x00000000, 0xff000000, 
0xff000000, 0x00000000, 0x00000000, 0x00000000, 0xff000000, 
0xff000000, 0xff000000, 0xff000000, 0xff000000, 0x00000000
},
{
0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 
0xff000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
0xff000000, 0xff000000, 0xff000000, 0x00000000, 0x00000000, 
0xff000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000
},
{
0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 
0xff000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
0xff000000, 0xff000000, 0xff000000, 0x00000000, 0x00000000, 
0xff000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
0xff000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000
},
{
0x00000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 
0xff000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
0xff000000, 0x00000000, 0x00000000, 0xff000000, 0xff000000, 
0xff000000, 0x00000000, 0x00000000, 0x00000000, 0xff000000, 
0x00000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000
},
{
0xff000000, 0x00000000, 0x00000000, 0x00000000, 0xff000000, 
0xff000000, 0x00000000, 0x00000000, 0x00000000, 0xff000000, 
0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 
0xff000000, 0x00000000, 0x00000000, 0x00000000, 0xff000000, 
0xff000000, 0x00000000, 0x00000000, 0x00000000, 0xff000000
},
{
0x00000000, 0xff000000, 0xff000000, 0xff000000, 0x00000000, 
0x00000000, 0x00000000, 0xff000000, 0x00000000, 0x00000000, 
0x00000000, 0x00000000, 0xff000000, 0x00000000, 0x00000000, 
0x00000000, 0x00000000, 0xff000000, 0x00000000, 0x00000000, 
0x00000000, 0xff000000, 0xff000000, 0xff000000, 0x00000000
},
{
0x00000000, 0x00000000, 0xff000000, 0xff000000, 0xff000000, 
0x00000000, 0x00000000, 0x00000000, 0xff000000, 0x00000000, 
0x00000000, 0x00000000, 0x00000000, 0xff000000, 0x00000000, 
0xff000000, 0x00000000, 0x00000000, 0xff000000, 0x00000000, 
0x00000000, 0xff000000, 0xff000000, 0x00000000, 0x00000000
},
{
0xff000000, 0x00000000, 0x00000000, 0x00000000, 0xff000000, 
0xff000000, 0x00000000, 0x00000000, 0xff000000, 0x00000000, 
0xff000000, 0xff000000, 0xff000000, 0x00000000, 0x00000000, 
0xff000000, 0x00000000, 0x00000000, 0xff000000, 0x00000000, 
0xff000000, 0x00000000, 0x00000000, 0x00000000, 0xff000000
},
{
0xff000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
0xff000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
0xff000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
0xff000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000
},
{
0xff000000, 0x00000000, 0x00000000, 0x00000000, 0xff000000, 
0xff000000, 0xff000000, 0x00000000, 0xff000000, 0xff000000, 
0xff000000, 0x00000000, 0xff000000, 0x00000000, 0xff000000, 
0xff000000, 0x00000000, 0x00000000, 0x00000000, 0xff000000, 
0xff000000, 0x00000000, 0x00000000, 0x00000000, 0xff000000
},
{
0xff000000, 0x00000000, 0x00000000, 0x00000000, 0xff000000, 
0xff000000, 0xff000000, 0x00000000, 0x00000000, 0xff000000, 
0xff000000, 0x00000000, 0xff000000, 0x00000000, 0xff000000, 
0xff000000, 0x00000000, 0x00000000, 0xff000000, 0xff000000, 
0xff000000, 0x00000000, 0x00000000, 0x00000000, 0xff000000
},
{
0x00000000, 0xff000000, 0xff000000, 0xff000000, 0x00000000, 
0xff000000, 0x00000000, 0x00000000, 0x00000000, 0xff000000, 
0xff000000, 0x00000000, 0x00000000, 0x00000000, 0xff000000, 
0xff000000, 0x00000000, 0x00000000, 0x00000000, 0xff000000, 
0x00000000, 0xff000000, 0xff000000, 0xff000000, 0x00000000
},
{
0xff000000, 0xff000000, 0xff000000, 0xff000000, 0x00000000, 
0xff000000, 0x00000000, 0x00000000, 0x00000000, 0xff000000, 
0xff000000, 0xff000000, 0xff000000, 0xff000000, 0x00000000, 
0xff000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
0xff000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000
},
{
0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 
0xff000000, 0x00000000, 0x00000000, 0x00000000, 0xff000000, 
0xff000000, 0x00000000, 0xff000000, 0x00000000, 0xff000000, 
0xff000000, 0x00000000, 0x00000000, 0xff000000, 0x00000000, 
0xff000000, 0xff000000, 0xff000000, 0x00000000, 0xff000000
},
{
0xff000000, 0xff000000, 0xff000000, 0xff000000, 0x00000000, 
0xff000000, 0x00000000, 0x00000000, 0x00000000, 0xff000000, 
0xff000000, 0xff000000, 0xff000000, 0xff000000, 0x00000000, 
0xff000000, 0x00000000, 0x00000000, 0x00000000, 0xff000000, 
0xff000000, 0x00000000, 0x00000000, 0x00000000, 0xff000000
},
{
0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 
0xff000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 
0x00000000, 0x00000000, 0x00000000, 0x00000000, 0xff000000, 
0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000
},
{
0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 
0x00000000, 0x00000000, 0xff000000, 0x00000000, 0x00000000, 
0x00000000, 0x00000000, 0xff000000, 0x00000000, 0x00000000, 
0x00000000, 0x00000000, 0xff000000, 0x00000000, 0x00000000, 
0x00000000, 0x00000000, 0xff000000, 0x00000000, 0x00000000
},
{
0xff000000, 0x00000000, 0x00000000, 0x00000000, 0xff000000, 
0xff000000, 0x00000000, 0x00000000, 0x00000000, 0xff000000, 
0xff000000, 0x00000000, 0x00000000, 0x00000000, 0xff000000, 
0xff000000, 0x00000000, 0x00000000, 0x00000000, 0xff000000, 
0x00000000, 0xff000000, 0xff000000, 0xff000000, 0x00000000
},
{
0xff000000, 0x00000000, 0x00000000, 0x00000000, 0xff000000, 
0xff000000, 0x00000000, 0x00000000, 0x00000000, 0xff000000, 
0x00000000, 0xff000000, 0x00000000, 0xff000000, 0x00000000, 
0x00000000, 0xff000000, 0x00000000, 0xff000000, 0x00000000, 
0x00000000, 0x00000000, 0xff000000, 0x00000000, 0x00000000
},
{
0xff000000, 0x00000000, 0x00000000, 0x00000000, 0xff000000, 
0xff000000, 0x00000000, 0x00000000, 0x00000000, 0xff000000, 
0xff000000, 0x00000000, 0xff000000, 0x00000000, 0xff000000, 
0xff000000, 0x00000000, 0xff000000, 0x00000000, 0xff000000, 
0x00000000, 0xff000000, 0x00000000, 0xff000000, 0x00000000
},
{
0xff000000, 0x00000000, 0x00000000, 0x00000000, 0xff000000, 
0x00000000, 0xff000000, 0x00000000, 0xff000000, 0x00000000, 
0x00000000, 0x00000000, 0xff000000, 0x00000000, 0x00000000, 
0x00000000, 0xff000000, 0x00000000, 0xff000000, 0x00000000, 
0xff000000, 0x00000000, 0x00000000, 0x00000000, 0xff000000
},
{
0xff000000, 0x00000000, 0x00000000, 0x00000000, 0xff000000, 
0xff000000, 0x00000000, 0x00000000, 0x00000000, 0xff000000, 
0x00000000, 0xff000000, 0x00000000, 0xff000000, 0x00000000, 
0x00000000, 0x00000000, 0xff000000, 0x00000000, 0x00000000, 
0x00000000, 0x00000000, 0xff000000, 0x00000000, 0x00000000
},
{
0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 
0x00000000, 0x00000000, 0x00000000, 0xff000000, 0x00000000, 
0x00000000, 0x00000000, 0xff000000, 0x00000000, 0x00000000, 
0x00000000, 0xff000000, 0x00000000, 0x00000000, 0x00000000, 
0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000
},
{
0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 
0xff000000, 0x00000000, 0x00000000, 0xff000000, 0xff000000, 
0xff000000, 0x00000000, 0xff000000, 0x00000000, 0xff000000, 
0xff000000, 0xff000000, 0x00000000, 0x00000000, 0xff000000, 
0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000
},
{
0x00000000, 0x00000000, 0xff000000, 0x00000000, 0x00000000, 
0x00000000, 0xff000000, 0xff000000, 0x00000000, 0x00000000, 
0x00000000, 0x00000000, 0xff000000, 0x00000000, 0x00000000, 
0x00000000, 0x00000000, 0xff000000, 0x00000000, 0x00000000, 
0x00000000, 0xff000000, 0xff000000, 0xff000000, 0x00000000
},
{
0xff000000, 0xff000000, 0xff000000, 0xff000000, 0x00000000, 
0x00000000, 0x00000000, 0x00000000, 0x00000000, 0xff000000, 
0x00000000, 0xff000000, 0xff000000, 0xff000000, 0x00000000, 
0xff000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000
},
{
0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 
0x00000000, 0x00000000, 0x00000000, 0x00000000, 0xff000000, 
0x00000000, 0xff000000, 0xff000000, 0xff000000, 0x00000000, 
0x00000000, 0x00000000, 0x00000000, 0x00000000, 0xff000000, 
0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000
},
{
0xff000000, 0x00000000, 0x00000000, 0xff000000, 0x00000000, 
0xff000000, 0x00000000, 0x00000000, 0xff000000, 0x00000000, 
0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 
0x00000000, 0x00000000, 0x00000000, 0xff000000, 0x00000000, 
0x00000000, 0x00000000, 0x00000000, 0xff000000, 0x00000000
},
{
0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 
0xff000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
0x00000000, 0xff000000, 0xff000000, 0xff000000, 0x00000000, 
0x00000000, 0x00000000, 0x00000000, 0x00000000, 0xff000000, 
0xff000000, 0xff000000, 0xff000000, 0xff000000, 0x00000000
},
{
0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 
0xff000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 
0xff000000, 0x00000000, 0x00000000, 0x00000000, 0xff000000, 
0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000
},
{
0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 
0x00000000, 0x00000000, 0x00000000, 0x00000000, 0xff000000, 
0x00000000, 0x00000000, 0x00000000, 0xff000000, 0x00000000, 
0x00000000, 0x00000000, 0xff000000, 0x00000000, 0x00000000, 
0x00000000, 0x00000000, 0xff000000, 0x00000000, 0x00000000
},
{
0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 
0xff000000, 0x00000000, 0x00000000, 0x00000000, 0xff000000, 
0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 
0xff000000, 0x00000000, 0x00000000, 0x00000000, 0xff000000, 
0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000
},
{
0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 
0xff000000, 0x00000000, 0x00000000, 0x00000000, 0xff000000, 
0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 
0x00000000, 0x00000000, 0x00000000, 0x00000000, 0xff000000, 
0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000
},
{
0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000
},
{
0x00000000, 0x00000000, 0xff000000, 0x00000000, 0x00000000, 
0x00000000, 0x00000000, 0xff000000, 0x00000000, 0x00000000, 
0x00000000, 0x00000000, 0xff000000, 0x00000000, 0x00000000, 
0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
0x00000000, 0x00000000, 0xff000000, 0x00000000, 0x00000000
},
{
0x00000000, 0xff000000, 0x00000000, 0x00000000, 0x00000000, 
0x00000000, 0xff000000, 0x00000000, 0x00000000, 0x00000000, 
0x00000000, 0x00000000, 0xff000000, 0x00000000, 0x00000000, 
0x00000000, 0x00000000, 0x00000000, 0xff000000, 0x00000000, 
0x00000000, 0x00000000, 0x00000000, 0xff000000, 0x00000000
},
{
0x00000000, 0xff000000, 0x00000000, 0xff000000, 0x00000000, 
0x00000000, 0xff000000, 0x00000000, 0xff000000, 0x00000000, 
0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000
},
{
0x00000000, 0xff000000, 0x00000000, 0xff000000, 0x00000000, 
0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 
0x00000000, 0xff000000, 0x00000000, 0xff000000, 0x00000000, 
0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 
0x00000000, 0xff000000, 0x00000000, 0xff000000, 0x00000000
},
{
0xff000000, 0x00000000, 0x00000000, 0x00000000, 0xff000000, 
0x00000000, 0x00000000, 0x00000000, 0xff000000, 0x00000000, 
0x00000000, 0x00000000, 0xff000000, 0x00000000, 0x00000000, 
0x00000000, 0xff000000, 0x00000000, 0x00000000, 0x00000000, 
0xff000000, 0x00000000, 0x00000000, 0x00000000, 0xff000000
},
{
0x00000000, 0x00000000, 0xff000000, 0x00000000, 0x00000000, 
0x00000000, 0x00000000, 0xff000000, 0x00000000, 0x00000000, 
0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000
},
{
0x00000000, 0x00000000, 0xff000000, 0x00000000, 0x00000000, 
0x00000000, 0xff000000, 0x00000000, 0x00000000, 0x00000000, 
0x00000000, 0xff000000, 0x00000000, 0x00000000, 0x00000000, 
0x00000000, 0xff000000, 0x00000000, 0x00000000, 0x00000000, 
0x00000000, 0x00000000, 0xff000000, 0x00000000, 0x00000000
},
{
0x00000000, 0x00000000, 0xff000000, 0x00000000, 0x00000000, 
0x00000000, 0x00000000, 0x00000000, 0xff000000, 0x00000000, 
0x00000000, 0x00000000, 0x00000000, 0xff000000, 0x00000000, 
0x00000000, 0x00000000, 0x00000000, 0xff000000, 0x00000000, 
0x00000000, 0x00000000, 0xff000000, 0x00000000, 0x00000000
},
{
0x00000000, 0x00000000, 0xff000000, 0x00000000, 0x00000000, 
0x00000000, 0x00000000, 0xff000000, 0x00000000, 0x00000000, 
0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 
0x00000000, 0x00000000, 0xff000000, 0x00000000, 0x00000000, 
0x00000000, 0x00000000, 0xff000000, 0x00000000, 0x00000000
},
{
0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
0x00000000, 0x00000000, 0xff000000, 0x00000000, 0x00000000, 
0x00000000, 0x00000000, 0xff000000, 0x00000000, 0x00000000
},
{
0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
0x00000000, 0xff000000, 0xff000000, 0xff000000, 0x00000000, 
0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000
},
{
0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
0x00000000, 0x00000000, 0xff000000, 0x00000000, 0x00000000
},
{
0x00000000, 0x00000000, 0x00000000, 0xff000000, 0x00000000, 
0x00000000, 0x00000000, 0x00000000, 0xff000000, 0x00000000, 
0x00000000, 0x00000000, 0xff000000, 0x00000000, 0x00000000, 
0x00000000, 0xff000000, 0x00000000, 0x00000000, 0x00000000, 
0x00000000, 0xff000000, 0x00000000, 0x00000000, 0x00000000
},
{
0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
0x00000000, 0x00000000, 0xff000000, 0x00000000, 0x00000000, 
0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
0x00000000, 0x00000000, 0xff000000, 0x00000000, 0x00000000, 
0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000
},
{
0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
0x00000000, 0x00000000, 0xff000000, 0x00000000, 0x00000000, 
0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
0x00000000, 0x00000000, 0xff000000, 0x00000000, 0x00000000, 
0x00000000, 0x00000000, 0xff000000, 0x00000000, 0x00000000
},
{
0x00000000, 0x00000000, 0x00000000, 0xff000000, 0x00000000, 
0x00000000, 0x00000000, 0xff000000, 0x00000000, 0x00000000, 
0x00000000, 0xff000000, 0x00000000, 0x00000000, 0x00000000, 
0x00000000, 0x00000000, 0xff000000, 0x00000000, 0x00000000, 
0x00000000, 0x00000000, 0x00000000, 0xff000000, 0x00000000
},
{
0x00000000, 0xff000000, 0x00000000, 0x00000000, 0x00000000, 
0x00000000, 0x00000000, 0xff000000, 0x00000000, 0x00000000, 
0x00000000, 0x00000000, 0x00000000, 0xff000000, 0x00000000, 
0x00000000, 0x00000000, 0xff000000, 0x00000000, 0x00000000, 
0x00000000, 0xff000000, 0x00000000, 0x00000000, 0x00000000
},
{
0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 
0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 
0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000
},
{
0x00000000, 0xff000000, 0xff000000, 0xff000000, 0x00000000, 
0x00000000, 0x00000000, 0x00000000, 0xff000000, 0x00000000, 
0x00000000, 0x00000000, 0xff000000, 0x00000000, 0x00000000, 
0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
0x00000000, 0x00000000, 0xff000000, 0x00000000, 0x00000000
}
};

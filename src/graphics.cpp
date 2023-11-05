#include "../power/graphics.h"
#include "../power/color.h"

#include <Arduino.h>
#include <Adafruit_NeoPixel.h>
#include <Adafruit_NeoMatrix.h>

#define CUBE_SIZE 5
#define PIXEL_PIN D6

extern Adafruit_NeoMatrix cube = Adafruit_NeoMatrix(CUBE_SIZE, CUBE_SIZE, CUBE_SIZE, 1, PIXEL_PIN,
                                                    NEO_MATRIX_TOP + NEO_MATRIX_LEFT +
                                                        NEO_MATRIX_COLUMNS + NEO_MATRIX_ZIGZAG,
                                                    NEO_RGB + NEO_KHZ800);

state_t state = state_t::INACTIVE;

void Graphics::setLED(int x, int y, int z, Color mycolor)
{
    if (z % 2)
        cube.drawPixel((z + 1) * 5 - x - 1, 4 - y, cube.Color(mycolor.red, mycolor.green, mycolor.blue));
    else
        cube.drawPixel(x + (z * 5), y, cube.Color(mycolor.red, mycolor.green, mycolor.blue));
}

void Graphics::setLED(Vector3 coords, Color mycolor)
{
    int intx = (int)coords.x;
    int inty = (int)coords.y;
    int intz = (int)coords.z;

    if (intz % 2)
        cube.drawPixel((intz + 1) * 5 - intx - 1, 4 - inty, cube.Color(mycolor.red, mycolor.green, mycolor.blue));
    else
        cube.drawPixel(intx + (intz * 5), inty, cube.Color(mycolor.red, mycolor.green, mycolor.blue));
}
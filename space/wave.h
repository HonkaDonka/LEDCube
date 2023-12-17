#ifndef WAVE_h
#define WAVE_h

#include "Arduino.h"
#include "../power/graphics.h"

class Wave : public Graphics
{
private:
    // Time the animation lasts
    Timer timer_running;
    // Speed of the ripple
    float runTime;

public:
    void init()
    {
        state = state_t::RUNNING;
        timer_running = 20.0;
    }

    void draw(float dt, bool loop = false)
    {

        runTime += 1.0 * 10000 / 1000000;
        static int hue16 = 0;
        hue16 += dt * 5 * 255;

        cube.clear();
        // Map the sin wave out where the height at each coordinate is a function of the sine of the distance from the center plus time.
        for (uint8_t x = 0; x < 5; x++)
        {
            for (uint8_t y = 0; y < 5; y++)
            {
                float zfloat = 1.25 * sin(.75 * (x - 2) + 3 * runTime) + 1.25 * cos(.75 * (y - 2) + 3 * runTime) + 2;

                int z = int(zfloat + .5);
                // Change the color using color palette as a base
                Color c = Color((hue16 >> 8) + (int8_t)(y * 5), RainbowGradientPalette);

                setLED(x, y, z, c);
            }
        }

        if (timer_running.update() && !loop)
        {
            state = state_t::ENDING;
        }

        if (state == state_t::ENDING)
        {
            cube.clear();
            state = state_t::INACTIVE;
        }
    }

    void end()
    {
        state = state_t::ENDING;
    }
};

#endif
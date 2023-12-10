#ifndef RAINFALL_h
#define RAINFALL_h

#include "Arduino.h"
#include "../power/graphics.h"

class Rainfall : public Graphics
{
private:
    // Time between each firework
    Timer timer_interval;
    // Time the animation lasts
    Timer timer_running;

    int activedrops;

    // Source and target for the missile
    Vector3 gravity;

    // Max number of debris
    Particle raindrops[5][5];

public:
    void init()
    {
        state = state_t::RUNNING;
        timer_interval = 0.05;
        timer_running = 20.0;
        gravity = Vector3(0, -0.25f, 0);
        activedrops = 0;
    }

    void draw(float dt)
    {
        uint8_t brightness = 255;

        cube.clear();

        for (uint8_t x = 0; x < 5; x++)
        {
            for (uint8_t y = 0; y < 5; y++)
            {

                if (raindrops[x][y].position.y > -1.0f)
                {
                    raindrops[x][y].move(dt, gravity);
                }
                else
                {
                    raindrops[x][y].position.y = -1.0f;
                }
                if (raindrops[x][y].position.y <= 0)
                {
                    raindrops[x][y].brightness = 0;
                    activedrops--;
                }
                setLED(raindrops[x][y].position.x, raindrops[x][y].position.z, raindrops[x][y].position.y, Color(0, 0, 100));
            }
        }

        if (random(0, 20) < 5 && activedrops < 20 && timer_interval.update() && state != state_t::ENDING)
        {
            uint8_t x = random(0, 5);
            uint8_t y = random(0, 5);

            Vector3 temp = Vector3(x, 5, y);
            raindrops[x][y] = {temp, Vector3(0, random(-0.125, 0), 0), 0, 1.0f, 1.0f};
            activedrops++;
        }

        if (timer_running.update())
        {
            state = state_t::ENDING;
        }

        if (state == state_t::ENDING && activedrops <= 0)
        {
            state = state_t::INACTIVE;
        }
    }

    void end()
    {
        state = state_t::ENDING;
    }
};

#endif
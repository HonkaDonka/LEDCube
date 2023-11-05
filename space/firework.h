#ifndef FIREWORK_h
#define FIREWORK_h

#include "Arduino.h"
#include "../power/graphics.h"

class Firework : public Graphics
{
private:
    // Time between each firework
    Timer timer_interval;
    // Time the animation lasts
    Timer timer_running;
    // Number of debris created on explosion
    uint16_t numDebris;

    // Source and target for the missile
    Vector3 source;

    Vector3 target;

    Vector3 velocity;

    Vector3 gravity;

    Particle missile;
    
    // Max number of debris
    Particle debris[50];

    boolean exploded;

    Noise noise;

public:
    void init()
    {
        state = state_t::RUNNING;
        timer_interval = 2.0;
        timer_running = 20.0;
        fireArrow();
    }

    void fireArrow()
    {
        // Create a source and a target for the initial missile
        source = Vector3(2, -1.0, 2);
        target = Vector3(2, 4, 2);
        // Assign a time in seconds to reach the target
        float t = noise.nextGaussian(0.80f, 0.40f);
        // Determine directional velocities in pixels per second
        velocity = (target - source) / (2 * t);
        // Set missile source and velocity
        missile.position = source;
        missile.velocity = velocity;
        // Set some system gravity
        gravity = Vector3(0, -0.25f, 0);
        exploded = false;
        cube.clear();
    }

    void draw(float dt)
    {
        uint8_t brightness = 255;

        if (!exploded)
        {
            Vector3 temp = missile.position;
            // Move missile
            missile.move(dt, gravity);
            // If missile falls back to earth or moved past the target, explode it
            if ((temp.y > missile.position.y) | (missile.position.y > target.y))
            {
                exploded = true;
                // Generate a number of debris formed when exploding
                numDebris = random((sizeof(debris) / sizeof(Particle)) / 2,
                                   sizeof(debris) / sizeof(Particle));
                // Overall exploding power of particles for all debris
                float pwr = noise.nextRandom(0.40f, 0.90f);
                // Starting position in the hue color palette
                uint8_t hue = (uint8_t)random(0, 256);
                // Generate debris with power and hue
                for (uint16_t i = 0; i < numDebris; i++)
                {
                    // Debris has random velocities depending on pwr
                    Vector3 explode =
                        Vector3(noise.nextRandom(-pwr, pwr), noise.nextRandom(-pwr, pwr),
                                noise.nextRandom(-pwr, pwr));
                    debris[i] = {temp, explode, uint8_t(hue + random(0, 64)), 1.0f,
                                 noise.nextRandom(1.0f, 2.0f)};
                }
            }
            else
            {
                // Switch y and z since the cube is rotated
                setLED(missile.position.x, missile.position.z, missile.position.y, Color::WHITE);
            }
        }

        if (exploded)
        {
            uint16_t visible = 0;

            cube.clear();

            for (uint16_t i = 0; i < numDebris; i++)
            {
                // Move debris downwards towards the ground
                if (debris[i].position.y > -1.0f)
                    debris[i].move(dt, gravity);
                else
                    debris[i].position.y = -1.0f;
                // Fade out debris
                if (debris[i].brightness > 0)
                {
                    visible++;
                    debris[i].brightness -= dt * (1 / debris[i].seconds);
                }
                Color c = Color(debris[i].hue, RainbowGradientPalette);
                // Add some random sparkles
                if (random(0, 20) == 0)
                {
                    c = Color::WHITE;
                }
                // Clear off debris on the ground
                if (debris[i].position.y <= 0)
                {
                    debris[i].brightness = 0;
                }
                c.scale(debris[i].brightness * brightness);
                setLED(debris[i].position.x, debris[i].position.z, debris[i].position.y, c);
            }

            if (timer_running.update())
            {
                state = state_t::ENDING;
            }

            if (visible == 0)
            {
                if (state == state_t::ENDING)
                {
                    cube.clear();
                    state = state_t::INACTIVE;
                }
                // Fire another arrow
                else if (timer_interval.update())
                {
                    fireArrow();
                }
            }
        }
    }

    void end()
    {
        state = state_t::ENDING;
        cube.clear();
    }
};

#endif
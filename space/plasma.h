#ifndef PLASMA_h
#define PLASMA_h

#include "Arduino.h"
#include "../power/graphics.h"

class Plasma : public Graphics
{
private:
    Timer timer_starting;
    // Time between each firework
    Timer timer_running;
    // Time the animation lasts
    Timer timer_ending;
    // Number of debris created on explosion
    Noise noise;

    float speed_offset;
    float speed_offset_speed;
    // Scale_p represents the distance between each pixel in the noise map
    float scale_p;
    // Speed is how fast the movement is over the axis in the noise map
    float speed_x;
    float speed_y;
    float speed_z;
    float speed_w;

    // Start somewhere in the noise map
    float noise_x = noise.nextRandom(0, 255);
    float noise_y = noise.nextRandom(0, 255);
    float noise_z = noise.nextRandom(0, 255);
    float noise_w = noise.nextRandom(0, 255);
    
    // Allocate noise memory
    uint8_t noise_map[5][5][5];

    int hue16 = 0;

public:

    

    void init()
    {
        state = state_t::STARTING;
        timer_starting = 2.0;
        timer_running = 26;
        timer_ending = 2.0;
        scale_p = 0.15;
        speed_x = 0.10;
        speed_y = 0.20;
        speed_z = 0.30;
        speed_w = 0.40;
        speed_offset = 0;
        speed_offset_speed = 0.002 / 50;
    }

    void draw(float dt)
    {
        uint8_t brightness = 255;

        if (state == state_t::STARTING) {
            if (timer_starting.update()) {
                state = state_t::RUNNING;
                timer_running.reset();
            } else {
                brightness *= timer_starting.ratio();
            }
        }
        if (state == state_t::RUNNING) {
            if (timer_running.update()) {
                state = state_t::ENDING;
                timer_ending.reset();
            }
        }
        if (state == state_t::ENDING) {
            if (timer_ending.update()) {
                state = state_t::INACTIVE;
                cube.clear();
                brightness = 0;
            } else {
                brightness *= (1 - timer_ending.ratio());
            }
        }
        updateNoise(dt);
        makeNoise();
        drawNoise(brightness);
    }

    void updateNoise(float dt) {
        speed_offset += dt * speed_offset_speed;
        // use same speed offset, but offset each in the noise map
        speed_x = 2 * (noise.noise1(speed_offset + 000) - 0.5);    //  -1 to 1
        speed_y = 2 * (noise.noise1(speed_offset + 050) - 0.5);    //  -1 to 1
        speed_z = 2 * (noise.noise1(speed_offset + 100) - 0.5);    //  -1 to 1
        speed_w = 2 * (noise.noise1(speed_offset + 150) - 0.5);    //  -1 to 1
        scale_p = .15 + (noise.noise1(speed_offset + 200) / 6.6);  // .15 to .30

        noise_x += speed_x * dt;
        noise_y += speed_y * dt;
        noise_z += speed_z * dt;
        noise_w += speed_w * dt;
    }

    void makeNoise() {
        for (int x = 0; x < 5; x++) {
            float xoffset = noise_x + scale_p * x;
            for (int y = 0; y < 5; y++) {
                float yoffset = noise_y + scale_p * y;
                for (int z = 0; z < 5; z++) {
                    float zoffset = noise_z + scale_p * z;
                    noise_map[x][y][z] =
                        noise.noise4(xoffset, yoffset, zoffset, noise_w) * 255;
                }
            }
        }
    }

    void drawNoise(uint8_t brightness) {
        for (int x = 0; x < 5; x++) {
            for (int y = 0; y < 5; y++) {
                for (int z = 0; z < 5; z++) {
                    // The index at (x,y,z) is the index in the color palette
                    uint8_t index = noise_map[x][y][z];
                    // The value at (y,x,z) is the overlay for the brightness
                    setLED(x, y, z,
                            Color((hue16 >> 8) + index, LavaPalette)
                                .scale(noise_map[y][x][z])
                                .scale(brightness));
                }
            }
        }
    }

    void end()
    {
        state = state_t::ENDING;
        timer_ending.reset();
    }
};

#endif
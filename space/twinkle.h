#ifndef TWINKLE_h
#define TWINKLE_h

#include "Arduino.h"
#include "../power/graphics.h"

// Store all the colors and times for each pixel
Color colors[5][5][5];
// Store the times each pixel was active
float times[5][5][5];

class Twinkle : public Graphics
{
private:
  // Time between each pixel added
  Timer timer_interval;
  // Time the animation lasts
  Timer timer_running;
  // Amount of time it takes to fade in a pixel to max
  float fade_in_speed;
  // Amount of time it takes to fade out a pixel to min
  float fade_out_speed;

  // Store all the colors and times for each pixel
  Color colors[5][5][5];
  // Store the times each pixel was active
  float times[5][5][5];

public:

  

  void init()
  {
    fade_in_speed = 5;
    fade_out_speed = 9;
    state = state_t::RUNNING;
    timer_interval = 0.05;
    timer_running = 20.0;
  }

  void draw(float dt)
  {

    uint8_t brightness = 255;

    uint8_t pixels_active = 0;
    // Fade in/out each pixel
    for (uint8_t x = 0; x < 5; x++)
    {
      for (uint8_t y = 0; y < 5; y++)
      {
        for (uint8_t z = 0; z < 5; z++)
        {
          if (!colors[x][y][z].isBlack())
          {
            if (times[x][y][z] < fade_in_speed)
            {
              float t = times[x][y][z] / fade_in_speed;
              setLED(x, y, z, colors[x][y][z].scaled(brightness * t));
              times[x][y][z] += dt;
              pixels_active++;
            }
            else if (times[x][y][z] < (fade_in_speed + fade_out_speed))
            {
              float t = (times[x][y][z] - fade_in_speed) / fade_out_speed;
              setLED(x, y, z, colors[x][y][z].scaled(brightness * (1 - t)));
              times[x][y][z] += dt;
              pixels_active++;
            }
            else
            {
              times[x][y][z] = 0;
              setLED(x, y, z, Color::BLACK);
              colors[x][y][z] = Color::BLACK;
            }
          }
        }
      }
    }

    // If the animation is over, reset the times and colors
    if (timer_running.update())
    {
      state = state_t::ENDING;
    }

    if (state != state_t::ENDING)
    {
      int x = random(0, 5);
      int y = random(0, 5);
      int z = random(0, 5);
      // Add a new pixel
      if (times[x][y][z] == 0 && timer_interval.update())
      {
        pixels_active++;
        colors[x][y][z] = Color(0, 255);
      }
    }
    else if (state == state_t::ENDING && pixels_active == 0)
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
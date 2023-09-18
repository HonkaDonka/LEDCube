#ifndef GRAPHICS_H
#define GRAPHICS_H

#include "color.h"
#include "particle.h"
#include "timer.h"
#include "math3d.h"
#include "noise.h"
/*---------------------------------------------------------------------------------------
 * Graphics CLASS
 *---------------------------------------------------------------------------------------
 * Graphics is a base class for all animations. It provides a common interface
 *
 * Each animation is a class that will follow the same function structure
 *-------------------------------------------------------------------------------------*/
#include <Adafruit_NeoPixel.h>
#include <Adafruit_NeoMatrix.h>

// Initialize cube object as part of the Adafruit_NeoMatrix class
extern Adafruit_NeoMatrix cube;

// Task states for animations
enum class state_t : uint8_t{
  INACTIVE = 0,
  STARTING = 1,
  RUNNING = 2,
  ENDING = 3
};

class Graphics
{
    public:
        virtual void init();
        virtual void draw(float dt);
        virtual void end();
        state_t state;
        void setLED(int x, int y, int z, Color mycolor);
        void setLED(Vector3 coords, Color mycolor);

};
#endif
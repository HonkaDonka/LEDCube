#ifndef SPECTRUM_h
#define SPECTRUM_h

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
       
    }

    void draw(float dt)
    {

    }

    void end()
    {
        
    }
};

#endif
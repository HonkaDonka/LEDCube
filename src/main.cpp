#include <env.h>
#include <Arduino.h>
#include <WiFi.h>
#include <BlynkSimpleEsp32.h>

#include <../power/math8.h>
#include <../power/color.h>
#include <../power/math3d.h>
#include <../power/timer.h>
#include <../power/graphics.h>
#include <../power/particle.h>

#include <../space/twinkle.h>
#include <../space/ripple.h>
#include <../space/firework.h>
#include <../space/plasma.h>

// Animations
Twinkle twinkle;
Ripple ripple;
Firework firework;
Plasma plasma;

Graphics *Animations[] = {&twinkle, &plasma, &ripple, &firework};

const uint8_t numAnimations = sizeof(Animations) / sizeof(Graphics *);

uint8_t currentAnim = 0;

void playNext();

// Blynk Platform & WiFi
char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = WIFI_SSID;
char pass[] = WIFI_PASS;

#define SKIPPIN V0
#define BACKPIN V1

void setup()
{
  WiFi.begin(ssid, pass);
  while(WiFi.status() != WL_CONNECTED) {}
  Blynk.config(auth);
  Blynk.connect();

  Serial.begin(9600);
  // while (!Serial){}
  cube.begin();
  cube.setBrightness(20);
  cube.clear();
}

void loop()
{
  Blynk.run();
  
  uint8_t activeAnims = 0;
  
  for (int i = 0; i < numAnimations; i++)
  {
    Graphics &animation = *Animations[i];
    if (animation.state != state_t::INACTIVE)
    {
      animation.draw(0.05);
    }

    if (animation.state != state_t::INACTIVE)
    {
      activeAnims++;
    }
  }
  
  if (activeAnims == 0)
  {
    playNext();
  }

  cube.show();
}

void playNext()
{
  if (currentAnim + 1 >= numAnimations)
  {
    currentAnim = 0;
  } else {
    currentAnim++;
  }

  Graphics &animation = *Animations[currentAnim];

  if (animation.state == state_t::INACTIVE)
  {
    animation.init();
  }
}

BLYNK_WRITE(SKIPPIN)
{
  if (param.asInt())
  {
    for (int i = 0; i < numAnimations; i++)
    {
      Graphics &animation = *Animations[i];

      if (animation.state != state_t::INACTIVE)
      {
        animation.end();
      }
    }

    Blynk.virtualWrite(SKIPPIN, 0);
  }
}

BLYNK_WRITE(BACKPIN)
{
  if (param.asInt())
  {
    Graphics &animation = *Animations[currentAnim];

    if (animation.state != state_t::INACTIVE)
    {
      animation.end();
    }

    if (currentAnim - 1 < 0)
    {
      currentAnim = numAnimations - 1;

      Graphics &animation = *Animations[currentAnim];

      animation.init();
    } else {
      currentAnim -= 2;
    }

    Blynk.virtualWrite(BACKPIN, 0);
  }
}
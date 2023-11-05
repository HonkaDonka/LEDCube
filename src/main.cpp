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
#include <../space/text.h>

// Animations
Twinkle twinkle;
Ripple ripple;
Firework firework;
Plasma plasma;
Text text;

Graphics *Animations[] = {&twinkle, &plasma, &ripple, &firework};

const uint8_t numAnimations = sizeof(Animations) / sizeof(Graphics *);

uint8_t currentAnim = 0;

void playNext();
void skipAnim();
void backAnim();

// Blynk Platform & WiFi
char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = WIFI_SSID;
char pass[] = WIFI_PASS;

#define SKIPPIN V0
#define BACKPIN V1
#define PLAYERPIN V2
#define CURRANIMPIN V3

void setup()
{
  WiFi.begin(ssid, pass);
  while (WiFi.status() != WL_CONNECTED)
  {
  }
  Blynk.config(auth);
  Blynk.connect();

  // Serial.begin(9600);
  // while (!Serial){}

  cube.begin();
  cube.setBrightness(20);
  cube.clear();

  text.init();
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

  // text.draw(0.5);

  cube.show();
}

void playNext()
{
  if (currentAnim + 1 >= numAnimations)
  {
    currentAnim = 0;
  }
  else
  {
    currentAnim++;
  }

  Graphics &animation = *Animations[currentAnim];

  if (animation.state == state_t::INACTIVE)
  {
    // Blynk.virtualWrite(CURRANIMPIN, animationName);
    animation.init();
  }
}

void skipAnim()
{
  for (int i = 0; i < numAnimations; i++)
  {
    Graphics &animation = *Animations[i];

    if (animation.state != state_t::INACTIVE)
    {
      animation.end();
    }
  }
}

void backAnim()
{
  Graphics &animation = *Animations[currentAnim];

  if (animation.state != state_t::INACTIVE)
  {
    animation.end();
  }

  if (currentAnim - 1 < 0)
  {
    currentAnim = numAnimations - 2;
  }
  else
  {
    currentAnim -= 2;
  }
}

BLYNK_WRITE(PLAYERPIN)
{
  String value = param.asStr();

  if (value == "play")
  {
    Serial.println("'play' button pressed");
  }
  else if (value == "stop")
  {
    Serial.println("'stop' button pressed");
  }
  else if (value == "prev")
  {
    backAnim();
  }
  else if (value == "next")
  {
    skipAnim();
  }
}
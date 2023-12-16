#include <env.h>
#include <Arduino.h>
#include <WiFi.h>
#include <BlynkSimpleEsp32.h>
#include <ezTime.h>

#include <../power/math8.h>
#include <../power/color.h>
#include <../power/math3d.h>
#include <../power/timer.h>
#include <../power/graphics.h>
#include <../power/particle.h>

#include <../space/text.h>
#include <../space/twinkle.h>
#include <../space/ripple.h>
#include <../space/firework.h>
#include <../space/plasma.h>
#include <../space/rainfall.h>

// Animations
Text text;
Twinkle twinkle;
Ripple ripple;
Firework firework;
Plasma plasma;
Rainfall rainfall;

Graphics *Animations[] = {&twinkle, &plasma, &firework, &rainfall, &ripple};

const uint8_t numAnimations = sizeof(Animations) / sizeof(Graphics *);

uint8_t currentAnim = 0;

// Animation Table
struct anim_det_t
{
  const char *name;
  Graphics *object;
};

const anim_det_t anim_table[] = {
    {"TWINKLES", &twinkle},
    {"PLASMA", &plasma},
    {"FIREWORKS", &firework},
    {"RAINFALL", &rainfall},
    {"RIPPLES", &ripple},
};

// Animation Player Functions
void playNext();
void skipAnim();
void backAnim();

// Time Display
Timezone local;
BlynkTimer timer;
bool isTimeMode = false;

void getTime();

// Blynk Platform & WiFi
char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = WIFI_SSID;
char pass[] = WIFI_PASS;

#define TIMEMODEPIN V0
#define PLAYERPIN V1
#define CURRANIMPIN V2
#define RUNTIMEPIN V3
#define CUBEBRIGHT V4
#define TEXTRGB V5

// Misc
bool loopAnim = false;
int runTime = 0;
int cubeBrightness = 20;

void setup()
{
  WiFi.begin(ssid, pass);
  while (WiFi.status() != WL_CONNECTED) {}

  Blynk.config(auth);
  Blynk.connect();

  Serial.begin(9600);
  // while (!Serial) {}

  cube.begin();
  cube.setBrightness(20);
  cube.clear();

  text.init();
  text.set_color(Color::WHITE);

  waitForSync();
  local.setLocation(F(TIMEZONE));
  timer.setInterval(1000, getTime);

  Blynk.virtualWrite(CURRANIMPIN, anim_table[currentAnim].name);
  Blynk.virtualWrite(CUBEBRIGHT, cubeBrightness);
  Blynk.virtualWrite(TIMEMODEPIN, 0);
  Blynk.virtualWrite(TEXTRGB, 255, 255, 255);
  Blynk.virtualWrite(V1, "play");
}

void loop()
{
  Blynk.run();
  timer.run();

  if (!Blynk.connected())
  {
    Blynk.connect();
  }

  if (millis() - runTime * 1000 > 1000)
  {
    runTime = millis() / 1000;
    Blynk.virtualWrite(RUNTIMEPIN, runTime);
  }

  if (!isTimeMode)
  {
    uint8_t activeAnims = 0;

    for (int i = 0; i < numAnimations; i++)
    {
      Graphics &animation = *Animations[i];
      if (animation.state != state_t::INACTIVE)
      {
        animation.draw(0.05, loopAnim);
      }

      if (animation.state != state_t::INACTIVE)
      {
        activeAnims++;
      }
    }

    if (activeAnims == 0 && !loopAnim)
    {
      playNext();
    } 
  }
  else
  {
    text.draw(0.05);
  }

  cube.show();
}

void playNext()
{
  if (currentAnim >= numAnimations - 1)
  {
    currentAnim = 0;
  }
  else
  {
    currentAnim++;
  }

  anim_det_t animdet = anim_table[currentAnim];

  if (animdet.object->state == state_t::INACTIVE)
  {
    Blynk.virtualWrite(CURRANIMPIN, animdet.name);
    animdet.object->init();
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

void getTime()
{
  if (isTimeMode)
  {
    text.set_text(local.dateTime("g:i A"));
  }
}

BLYNK_WRITE(PLAYERPIN)
{
  String value = param.asStr();

  if (value == "play")
  {
    if (!isTimeMode)
    {
      loopAnim = false;
    }
  }
  else if (value == "stop")
  {
    if (!isTimeMode)
    {
      loopAnim = true;
    }
  }
  else if (value == "prev")
  {
    if (!isTimeMode)
    {
      backAnim();
    }
  }
  else if (value == "next")
  {
    if (!isTimeMode)
    {
      skipAnim();
    }
  }
}

BLYNK_WRITE(TIMEMODEPIN)
{
  if (param.asInt())
  {
    Blynk.virtualWrite(CURRANIMPIN, "TIME");
    isTimeMode = true;
  }
  else
  {
    Blynk.virtualWrite(CURRANIMPIN, anim_table[currentAnim].name);
    isTimeMode = false;
  }
}

BLYNK_WRITE(CUBEBRIGHT)
{
  cubeBrightness = param.asInt();
  cube.setBrightness(cubeBrightness);
}

BLYNK_WRITE(TEXTRGB)
{
  int r = param[0].asInt();
  int g = param[1].asInt();
  int b = param[2].asInt();

  text.set_color(Color(r, g, b));
}
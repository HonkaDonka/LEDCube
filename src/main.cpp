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

// Animations
Twinkle twinkle;
Ripple ripple;
Firework firework;

Graphics *Animations[] = {&twinkle, &ripple, &firework};

const uint8_t numAnimations = sizeof(Animations) / sizeof(Graphics *);

uint8_t currentAnim = 0;

void playNext();

// Blynk Platform & WiFi
char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = WIFI_SSID;
char pass[] = WIFI_PASS;

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

// void helix()
// {
//   uint8_t brightness = 255;
//
//   static float phase = 0;
//   static float angle = 0;
//   static int hue16 = 0;
//   static Timer timer_running = 30.0;
//   static bool state = false;
//
//   static uint8_t bottom;
//   static uint8_t top;
//   static uint8_t thickness;
//   static uint8_t stage;
//
//   phase += dt * 2.0;
//   angle += dt * 0.0;
//   hue16 += dt * 30 * 255;
//
//   Quaternion q1 = Quaternion(180, Vector3(0, 1, 0));
//   Quaternion q2 = Quaternion(angle, Vector3(1, 0, 0));
//
//   // Resize the function to be big enough to have the rotated version fit
//   // sqrt(3) * 7.5 * 2 => 26 is big enough but more resolution is better
//   for (uint16_t y = bottom; y <= top; y++)
//   {
//     float xf = sinf(phase + mapf(y, 0, 30, 0, 2 * PI));
//     float zf = cosf(phase + mapf(y, 0, 30, 0, 2 * PI));
//     Vector3 p0 = Vector3(xf, 2 * (y / 30) - 1, zf) * 5;
//     Vector3 p1 = q2.rotate(p0);
//     Vector3 p2 = (q2 * q1).rotate(p0);
//     Color c1 = Color((hue16 >> 8) + y * 2 + 000, RainbowGradientPalette);
//     Color c2 = Color((hue16 >> 8) + y * 2 + 128, RainbowGradientPalette);
//
//
//     setLED(p1.x, 0, p1.z, c1.scale(brightness));
//
//     Serial.print(p1.x);
//     Serial.print(" ");
//     Serial.print(p1.y - 327670);
//     Serial.print(" ");
//     Serial.print(p1.z);
//     Serial.println(" ");
//
//
//   //   radiate(p1, c1.scale(brightness), 1.0f + (float)thickness / 20.0f);
//   //   radiate(p2, c2.scale(brightness), 1.0f + (float)thickness / 20.0f);
//   }
//   if (timer_interval.update())
//   {
//     int progress = 0;
//     if (stage == progress++)
//       top <= 30 ? top++ : stage++;
//     if (stage == progress++)
//       thickness <= 16 ? thickness++ : stage++;
//     if (stage == progress++)
//       if (timer_running.update() || (state == false))
//         stage++;
//     if (stage == progress++)
//       bottom <= 30 ? bottom++ : stage++;
//     if (stage == progress++)
//       state = true;
//   }
// }
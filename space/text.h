#ifndef TEXT_h
#define TEXT_h

#include "Arduino.h"
#include "../power/graphics.h"
#include "../gfx/chars.h"

class Text : public Graphics
{
private:
    float radius;

    float text_rotation;

    float text_rotation_speed;

    Timer timer_interval;
    // Time the animation lasts
    Timer timer_running;

    Timer timer_starting;
    // Time between each firework
    // Time the animation lasts
    Timer timer_ending;

    String text = "A";

public:
    void init()
    {
        state = state_t::STARTING;
        timer_starting = 0.5;
        timer_running = 30;
        timer_ending = 2;
        radius = 2;
        text_rotation = -90;
        text_rotation_speed = 45;
    }

    void set_text(String s) { text = s; }

    void draw(float dt)
    {
        uint8_t brightness = 255;

        // if (state == state_t::STARTING)
        // {
        //     if (timer_starting.update())
        //     {
        //         state = state_t::RUNNING;
        //         timer_running.reset();
        //     }
        //     else
        //     {
        //         brightness *= timer_starting.ratio();
        //     }
        // }
        // if (state == state_t::RUNNING)
        // {
        //     if (timer_running.update())
        //     {
        //         state = state_t::ENDING;
        //         timer_ending.reset();
        //     }
        // }
        // if (state == state_t::ENDING)
        // {
        //     if (timer_ending.update())
        //     {
        //         state = state_t::INACTIVE;
        //         brightness = 0;
        //     }
        //     else
        //     {
        //         brightness *= (1 - timer_ending.ratio());
        //     }
        // }

        // // Amount of degrees the text has been rotated
        // text_rotation += text_rotation_speed * dt;
        // // Full circle resolution (radius 15) in amount of pixels
        // // ø = (sin)^-1*(1/15) -> 360 / 2 * ø ≈ 47 for radius 7.5
        // // for radius 15 -> 47 * 2 ≈ 94. (changes height of charset)
        // float circle_resolution = 94.16f;
        // // Angle adjustment in degrees for each line
        // float line_angle_adj = 360 / circle_resolution;
        // // Amount of pixels the text has been rotated
        // float pixel_start = text_rotation / line_angle_adj;
        // // Start of the line_angle at a bit over 90 degrees
        // float line_angle = 90;
        // // Fine adjustment for angles between lines.
        // // Ignore because this will add a lot of jittering.
        // // line_angle += fmod(text_rotation, line_angle_adj);

        // // Adjust for negative rotation (inserts blanks at begin text)
        // int16_t pixel_line = pixel_start;
        // if (pixel_line < 0)
        // {
        //     line_angle += line_angle_adj * pixel_line;
        //     pixel_line = 0;
        // }
        // //  Insert an amount of blank_lines after every character
        // const uint16_t blank_lines = 1;

        // uint16_t text_lines = (CHARS_FRAME_HEIGHT + blank_lines) * text.length();
        // while (line_angle > -line_angle_adj)
        // {
        //     uint16_t text_offset = pixel_line % text_lines;
        //     uint16_t char_offset = text_offset / (CHARS_FRAME_HEIGHT + blank_lines);
        //     uint16_t t = match_char(text.charAt(char_offset));
        //     uint16_t y = pixel_line++ % (CHARS_FRAME_HEIGHT + blank_lines);
        //     if (y < CHARS_FRAME_HEIGHT)
        //     {
        //         Quaternion q = Quaternion(line_angle, Vector3::X);
        //         for (uint8_t x = 0; x < CHARS_FRAME_WIDTH; x++)
        //         {
        //             uint32_t data = chars_data[t][y * CHARS_FRAME_WIDTH + x];
        //             if (data & 0xff000000)
        //             {
        //                 Color c = Color(100, 100, 100);
        //                 // Vector3 pixel = q.rotate(Vector3(x / 15.0f, 0, -1) * radius);
        //                 Vector3 pixel = q.rotate(Vector3(0, 0, 0));
        //                 // pixel += Vector3(-radius / 2, -radius / 2, radius / 2);
        //                 Serial.print(pixel.x);
        //                 Serial.print(" ");
        //                 Serial.print(pixel.y);
        //                 Serial.print(" ");
        //                 Serial.print(pixel.z);
        //                 Serial.println();

        //                 setLED(pixel, c.scale(brightness).gamma());
        //             }
        //         }
        //     }
        //     line_angle -= line_angle_adj;
        // }

        for (uint8_t x = 0; x < CHARS_FRAME_WIDTH; x++) {
            for (uint8_t y = 0; y < CHARS_FRAME_HEIGHT; y++) {
                uint32_t data = chars_data[match_char(text.charAt(0))][y * CHARS_FRAME_WIDTH + x];
                if (data & 0xff000000) {
                    Color c = Color(100, 100, 100);
                    Vector3 pixel = Vector3(x / 15.0f, 0, -1) * radius;
                    setLED(pixel, c.scale(brightness).gamma());
                }
            }
        }
    }

    uint16_t match_char(uint16_t chr)
    {
        if (chr >= ' ' && chr <= 'Z')
            return chr - ' ';
        else
            return '#' - ' ';
    }

    void end()
    {
        state = state_t::ENDING;
        timer_ending.reset();
    }
};

#endif
#ifndef TEXT_h
#define TEXT_h

#include "Arduino.h"
#include "../power/graphics.h"
#include "../gfx/chars.h"

class Text : public Graphics
{
private:
    // Time between each frame
    Timer timer_interval;
    // Time the animation lasts
    Timer timer_running;

    String text = "HELLO WORLD!  ";
    // Current state of the animation
    int text_index;
    int x_offset;
    bool add_blank = false;
    // Store all the colors for each pixel
    Color colors[5][5][5];

public:
    void init()
    {
        state = state_t::STARTING;
        timer_running = 30;
        text_index = 0;
        x_offset = 0;
        timer_interval = 0.2;
    }

    void draw(float dt)
    {
        if (timer_interval.update())
        {
            // Add a blank after every new letter
            if (add_blank == false) {
                // Clear everything in the back of the cube
                for (uint8_t y = 0; y < 5; y++)
                {
                    colors[4][0][y] = Color::BLACK;
                    setLED(4, 0, y, Color::BLACK);
                }

                set_line();
                rotate_matrix();

                if (x_offset + 1 >= 5)
                {
                    x_offset = 0;

                    if (text_index < text.length() - 1)
                    {
                        text_index++;
                    }
                    else
                    {
                        text_index = 0;
                    }
                    add_blank = true;
                }
                else
                {
                    x_offset++;
                }
            } else {
                rotate_matrix();
                add_blank = false;
            }
        }
    }

    void set_line()
    {
        for (uint8_t y = 0; y < CHARS_FRAME_HEIGHT; y++)
        {
            uint32_t data = chars_data[match_char(text[text_index])][y * CHARS_FRAME_WIDTH + x_offset];
            if (data & 0xff000000)
            {
                Color c = Color(255, 255, 255);

                // Flip the y coordinate so that it is upright
                Vector3 pixel = Vector3(4, 4, -y + 4);
                colors[4][4][-y + 4] = c;
                setLED(pixel, c);
            }
        }
    }

    void rotate_matrix()
    {
        for (uint8_t y = 0; y < 5; y++)
        {
            int m = 5, n = 5;

            int row = 0, col = 0;
            Color prev, curr;

            while (row < m && col < n)
            {

                if (row + 1 == m || col + 1 == n)
                {
                    break;
                }

                prev = colors[col][row + 1][y];

                // Move elements of first row from the remaining rows
                for (int i = col; i < n; i++)
                {
                    curr = colors[i][row][y];
                    colors[i][row][y] = prev;
                    prev = curr;
                }
                row++;

                for (int i = row; i < m; i++)
                {
                    curr = colors[n - 1][i][y];
                    colors[n - 1][i][y] = prev;
                    prev = curr;
                }
                n--;

                if (row < m)
                {
                    for (int i = n - 1; i >= col; i--)
                    {
                        curr = colors[i][m - 1][y];
                        colors[i][m - 1][y] = prev;
                        prev = curr;
                    }
                }
                m--;

                if (col < n)
                {
                    for (int i = m - 1; i >= row; i--)
                    {
                        curr = colors[col][i][y];
                        colors[col][i][y] = prev;
                        prev = curr;
                    }
                }
                col++;
            }

            // Set the LEDs of the layer to the rotated matrix
            for (uint8_t i = 0; i < 5; i++)
            {
                for (uint8_t z = 0; z < 5; z++)
                {
                    setLED(i, z, y, colors[i][z][y]);
                }
            }
        }
    }

    void set_text(String s) { text = s + "  "; }

    uint16_t match_char(uint16_t chr)
    {
        // Return ASCII Values - 32 for the index of the character in the charset
        if (chr >= ' ' && chr <= 'Z')
        {
            return chr - ' ';
        }
        else
        {
            return '#' - ' ';
        }
    }

    void end()
    {
        state = state_t::ENDING;
    }
};
#endif
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

    String text = "HELLO WORLD";

    int text_index = 0;

    Color colors[5][5][5];

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

    void draw(float dt)
    {
        uint8_t brightness = 255;

        for (uint8_t x = 0; x < CHARS_FRAME_WIDTH; x++) {
            for (uint8_t y = 0; y < CHARS_FRAME_HEIGHT; y++) {
                uint32_t data = chars_data[match_char(text[text_index])][y * CHARS_FRAME_WIDTH + x];
                if (data & 0xff000000) {
                    Color c = Color(100, 100, 100);

                    // Flip the y coordinate so that it is upright
                    Vector3 pixel = Vector3(4, 4, -y + 4);
                    colors[4][4][-y + 4] = c;
                    setLED(pixel, c);
                }
            }

            // Delete row before corner before rotating 
            for (uint8_t y = 0; y < 5; y++) {
                colors[4][3][y] = Color::BLACK;
                setLED(4, 3, y, Color::BLACK);
            }

            // Rotate the matrix clockwise for each layer
            rotate_matrix();
        }

        // for (uint8_t y = 0; y < 5; y++) {
        //     colors[4][4][y] = Color::BLACK;
        //     setLED(4, 4, y, Color::BLACK);
        // }

        // rotate_matrix();

        // text_index++;
    }

    void rotate_matrix() {
        for (uint8_t y = 0; y < 5; y++) {
                int m = 5, n = 5;

                int row = 0, col = 0;
                Color prev, curr;

                while(row < m && col < n) {

                    if (row + 1 == m || col + 1 == n) {
                        break;
                    }

                    prev = colors[row + 1][col][y]; 

                    // Move elements of first row from the remaining rows
                    for (int i = col; i < m; i++) 
                    { 
                        curr = colors[i][row][y]; 
                        colors[i][row][y] = prev; 
                        prev = curr; 
                    } 
                    row++; 

                    for (int i = row; i < m; i++) 
                    { 
                        curr = colors[n-1][i][y]; 
                        colors[n-1][i][y] = prev; 
                        prev = curr; 
                    } 
                    n--; 

                    if (row < m) 
                    { 
                        for (int i = n-1; i >= col; i--) 
                        { 
                            curr = colors[i][m-1][y]; 
                            colors[i][m-1][y] = prev; 
                            prev = curr; 
                        } 
                    } 
                    m--; 

                    if (col < n) 
                    { 
                        for (int i = m-1; i >= row; i--) 
                        { 
                            curr = colors[col][i][y]; 
                            colors[col][i][y] = prev; 
                            prev = curr; 
                        } 
                    } 
                    col++;  
                }

                // Set the LEDs of the layer to the rotated matrix
                for (uint8_t i = 0; i < 5; i++) {
                    for (uint8_t z = 0; z < 5; z++) {
                        setLED(i, z, y, colors[i][z][y]);
                    }
                }        
            }
    }

    void set_text(String s) { text = s;}
    
    uint16_t match_char(uint16_t chr)
    {
        // Return ASCII Values - 32 for the index of the character in the charset
        if (chr >= ' ' && chr <= 'Z') {
            return chr - ' ';
        } else {
            return '#' - ' ';
        }
    }

    void end()
    {
        state = state_t::ENDING;
        timer_ending.reset();
    }
};
#endif
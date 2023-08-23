//
//  graphics.h:
//      graphics window class declaration (video 2)
/*
    Rendering in SDL_2:
    Every frame, we render everything.
    - First we clear whatever it is in the render.
    - blit Surface will render the things.
    - flip will draw it on the screen.
 */
//  Story_Cave_Remake
//
//  Created by José Moreno on 21/11/18.
//  Copyright (c) 2018 José Moreno. All rights reserved.
//

#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>

#include <iostream>
#include <map>
#include <string>

#include "Player.h"
#include "vector.h"
#include "Globals.h"

// Class Graphics: SDL tools to render, load images and draw them in the screen.
class Graphics
{
public:
    Graphics();
    ~Graphics();

    // void blitSurface
    //   Draws a texture to a part of the screen, the destination rectangle.
    void draw_texture(SDL_Texture *texture, SDL_Rect *source_rectangle, SDL_Rect *destination_rectangle);

    // SDL_Surface *LoadCircuit
    //   Loads the circuit from an image and returns it as a Surface
    SDL_Texture *load_circuit_img(char file_path[]);

    // void set_color
    //   Changes the color of the render
    void set_render_color(SDL_Color);

    // void draw_vector
    //   Draws the vector representation of the player
    void draw_vector(vector *);
    // void draw_line
    //   Draw a line between two coordinates
    void draw_line(Coordinate *, Coordinate *);

    // void flip
    //   Renders everything to the screen.
    void flip();

    // void clear
    //   Clears the screen.
    void clear();

    // SDL_Renderer* getRender
    //   Return the _renderer.
    SDL_Renderer *get_renderer() const;

    // SDL_Rect
    //   Returns a rectangle
    SDL_Rect make_sdl_rect(int X, int Y, int W, int H);

    // SDL_Texture
    //   Return the loaded Circuit as a texture
    SDL_Texture *get_circuit_img() const;

private:
    SDL_Window *_window;     // window object
    SDL_Renderer *_renderer; // drawing in the window
    SDL_Color _clear_color;  // used to clear the render

    SDL_Texture *_circuit_img; //

    // This was in Cave Story
    std::map<std::string, SDL_Surface *> _sprite_sheets; // this will keep the loaded images so it doesn't reload them every time.

    // Helper methods:
    void take_screen_shot();
};

#endif // #ifndef GRAPHICS_H

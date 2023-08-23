//
//  graphics.cpp
//      graphics window class definition (modified from Cave Story Remake)
//  vector Race
//
//  Created by José Moreno on 21/11/18.
//  Copyright (c) 2018 José Moreno. All rights reserved.
//

#include "graphics.h"

SDL_Rect make_sdl_rect(int X, int Y, int W, int H);

// Graphics class:
//   Holds all the information related with the graphics in the game.

Graphics::Graphics()
{
    SDL_CreateWindowAndRenderer(SCREEN_WIDTH, SCREEN_HEIGHT, 0, &this->_window, &this->_renderer);

    SDL_SetWindowTitle(this->_window, "vector Race");

    _clear_color.r = 0;
    _clear_color.g = 0;
    _clear_color.b = 0;
    _clear_color.a = SDL_ALPHA_OPAQUE;

    _circuit_img = nullptr;

    clear();
}

Graphics::~Graphics()
{
    SDL_DestroyWindow(this->_window);
}

void Graphics::draw_texture(SDL_Texture *texture, SDL_Rect *source_rectangle, SDL_Rect *destination_rectangle)
{
    SDL_RenderCopy(this->_renderer, texture, source_rectangle, destination_rectangle);
}

SDL_Texture *Graphics::load_circuit_img(char file_path[])
{
    _circuit_img = SDL_CreateTextureFromSurface(_renderer, IMG_Load((file_path)));
    if (_circuit_img == NULL)
    {
        std::cout << "Error loading Circuit: " << file_path << std::endl;
        std::cout << "SDL_GetError(): " << SDL_GetError() << std::endl;
    }

    return _circuit_img;
}

void Graphics::set_render_color(SDL_Color new_color)
{
    SDL_SetRenderDrawColor(_renderer, new_color.r, new_color.g, new_color.b, new_color.a);
}

void Graphics::draw_vector(vector *vector)
{
    SDL_RenderDrawLine(_renderer, vector->get_origin().x, vector->get_origin().y, vector->get_origin().x + vector->get_speed().x, vector->get_origin().y + vector->get_speed().y);
    return;
}

void Graphics::draw_line(Coordinate *start, Coordinate *end)
{
    SDL_RenderDrawLine(_renderer, start->x, start->y, end->x, end->y);
    return;
}

void Graphics::flip()
{
    SDL_RenderPresent(this->_renderer);
}

void Graphics::clear()
{
    set_render_color(_clear_color);
    SDL_RenderClear(this->_renderer);
}

SDL_Renderer *Graphics::get_renderer() const { return this->_renderer; }

SDL_Rect Graphics::make_sdl_rect(int X, int Y, int W, int H)
{
    SDL_Rect rect;
    rect.x = X;
    rect.y = Y;
    rect.w = W;
    rect.h = H;
    return rect;
}

SDL_Texture *Graphics::get_circuit_img() const { return _circuit_img; }

void Graphics::take_screen_shot()
{
    SDL_Surface *s_shot = SDL_CreateRGBSurface(0, SCREEN_WIDTH, SCREEN_HEIGHT, 32, 0x00ff0000, 0x0000ff00, 0x000000ff, 0xff000000);
    SDL_RenderReadPixels(_renderer, NULL, SDL_PIXELFORMAT_ARGB8888, s_shot->pixels, s_shot->pitch);

    SDL_SaveBMP(s_shot, "screenshot.bmp");
    SDL_FreeSurface(s_shot);

    return;
}
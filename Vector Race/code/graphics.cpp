//
//  graphics.cpp
//      graphics window class definition (modified from Cave Story Remake)
//  Vector Race
//
//  Created by José Moreno on 21/11/18.
//  Copyright (c) 2018 José Moreno. All rights reserved.
//

#include "graphics.h"

const int SCREEN_WIDTH = 400;
const int SCREEN_HEIGHT = 400;

//Graphics class:
//  Holds all the information related with the graphics in the game.

Graphics::Graphics()
{
    SDL_CreateWindowAndRenderer(SCREEN_WIDTH
                                , SCREEN_HEIGHT
                                , 0
                                , &this->_window
                                , &this->_renderer);
    
    SDL_SetWindowTitle(this->_window, "Vector Race");
    
}

Graphics::~Graphics()
{
    SDL_DestroyWindow(this->_window);
}

void Graphics::DrawSurface(SDL_Texture* texture, SDL_Rect* sourceRectangle, SDL_Rect* destinationRectangle)
{
    SDL_RenderCopy(this->_renderer, texture, sourceRectangle, destinationRectangle);
}

void Graphics::DrawVector(Player player)
{
    return;
}

void Graphics::Render()
{
    SDL_RenderPresent(this->_renderer);
}

void Graphics::Clear()
{
    SDL_RenderClear(this->_renderer);
}

SDL_Renderer* Graphics::GetRenderer() const
{
    return this->_renderer;
}
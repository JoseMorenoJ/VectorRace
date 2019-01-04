//
//  graphics.cpp
//      graphics window class definition (modified from Cave Story Remake)
//  Vector Race
//
//  Created by José Moreno on 21/11/18.
//  Copyright (c) 2018 José Moreno. All rights reserved.
//

#include "graphics.h"

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

SDL_Rect MakeSDLRect(int X, int Y, int W, int H);

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
    
    _clearColor.r = 0;
    _clearColor.g = 0;
    _clearColor.b = 0;
    _clearColor.a = 255; //SDL_ALPHA_OPAQUE
    
    Clear();
    
}

Graphics::~Graphics()
{
    SDL_DestroyWindow(this->_window);
}

void Graphics::DrawSurface(SDL_Texture* texture, SDL_Rect* sourceRectangle, SDL_Rect* destinationRectangle)
{
    SDL_RenderCopy(this->_renderer, texture, sourceRectangle, destinationRectangle);
}

void Graphics::LoadMap(std::string &filePath)
{
    _loadedMap = SDL_CreateTextureFromSurface( _renderer, IMG_Load("resources/TestMap.png") );
    
    SDL_Rect destRect = MakeSDLRect(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
    
    SDL_SetRenderDrawColor(_renderer, 255, 255, 255, 255); //SDL_ALPHA_OPAQUE
    SDL_RenderFillRect(_renderer, &destRect);
    
    return;
}

void Graphics::SetRenderColor(SDL_Color newColor)
{
    SDL_SetRenderDrawColor(_renderer
                           , newColor.r
                           , newColor.g
                           , newColor.b
                           , newColor.a);
    std::cout << newColor << std::endl;
}

void Graphics::DrawVector(Vector* vector)
{
    SDL_RenderDrawLine(_renderer
                       , vector->GetTail().x
                       , vector->GetTail().y
                       , vector->GetTail().x + vector->GetSpeed().x
                       , vector->GetTail().y + vector->GetSpeed().y);
    return;
}

void Graphics::DrawLine(Coordinate* start, Coordinate* end)
{
    SDL_RenderDrawLine(_renderer
                       , start->x
                       , start->y
                       , end->x
                       , end->y);
    return;
}


void Graphics::Flip()
{
    SDL_RenderPresent(this->_renderer);
}

void Graphics::Clear()
{
    SetRenderColor(_clearColor);
    SDL_RenderClear(this->_renderer);
}

SDL_Renderer* Graphics::GetRenderer() const { return this->_renderer; }

SDL_Rect MakeSDLRect(int X, int Y, int W, int H)
{
    SDL_Rect rect;
    rect.x = X;
    rect.y = Y;
    rect.w = W;
    rect.h = H;
    return rect;
}
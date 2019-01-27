//
//  graphics.cpp
//      graphics window class definition (modified from Cave Story Remake)
//  Vector Race
//
//  Created by José Moreno on 21/11/18.
//  Copyright (c) 2018 José Moreno. All rights reserved.
//

#include "graphics.h"

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
    _clearColor.a = SDL_ALPHA_OPAQUE;
    
    _circuitIMG = nullptr;
    
    Clear();
    
}

Graphics::~Graphics()
{
    SDL_DestroyWindow(this->_window);
}

void Graphics::DrawTexture(SDL_Texture* texture, SDL_Rect* sourceRectangle, SDL_Rect* destinationRectangle)
{
    SDL_RenderCopy(this->_renderer, texture, sourceRectangle, destinationRectangle);
}

SDL_Texture* Graphics::LoadCircuitIMG(char filePath[])
{
    _circuitIMG = SDL_CreateTextureFromSurface( _renderer, IMG_Load((filePath)) );
    if(_circuitIMG == NULL)
    {
        std::cout << "Error loading Circuit: " << filePath << std::endl;
        std::cout << "SDL_GetError(): " << SDL_GetError() << std::endl;
    }
    
    return _circuitIMG;
}

void Graphics::SetRenderColor(SDL_Color newColor)
{
    SDL_SetRenderDrawColor(_renderer
                           , newColor.r
                           , newColor.g
                           , newColor.b
                           , newColor.a);
}

void Graphics::DrawVector(Vector* vector)
{
    SDL_RenderDrawLine(_renderer
                       , vector->GetOrigin().x
                       , vector->GetOrigin().y
                       , vector->GetOrigin().x + vector->GetSpeed().x
                       , vector->GetOrigin().y + vector->GetSpeed().y);
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

SDL_Rect Graphics::MakeSDLRect(int X, int Y, int W, int H)
{
    SDL_Rect rect;
    rect.x = X;
    rect.y = Y;
    rect.w = W;
    rect.h = H;
    return rect;
}

SDL_Texture* Graphics::GetCircuitIMG() const { return _circuitIMG; }

void Graphics::TakeScreenshot()
{
    SDL_Surface *sshot = SDL_CreateRGBSurface(0, SCREEN_WIDTH, SCREEN_HEIGHT, 32, 0x00ff0000, 0x0000ff00, 0x000000ff, 0xff000000);
    SDL_RenderReadPixels(_renderer, NULL, SDL_PIXELFORMAT_ARGB8888, sshot->pixels, sshot->pitch);
    
    SDL_SaveBMP(sshot, "screenshot.bmp");
    SDL_FreeSurface(sshot);

    return;
}
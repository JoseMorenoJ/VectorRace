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

#ifndef Story_Cave_Remake_graphics_h
#define Story_Cave_Remake_graphics_h

#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>

#include <map>
#include <string>

#include "Player.h"

//Class Graphics: SDL tools to render, load images and draw them in the screen.
class Graphics
{
public:
    Graphics();
    ~Graphics();
    
    //void blitSurface
    //  Draws a texture to a part of the screen, the destination rectangle.
    void DrawSurface(SDL_Texture* texture
                     , SDL_Rect* sourceRectangle
                     , SDL_Rect* destinationRectangle);
    
    //void DrawVector
    //Draws the vector representation of the player
    void DrawVector(Player);
    
    //void flip
    //  Renders everything to the screen.
    void Render();
    
    //void clear
    //  Clears the screen.
    void Clear();
    
    //SDL_Renderer* getRender
    //  Return the _renderer.
    SDL_Renderer* GetRenderer() const;
    
private:
    SDL_Window* _window; //window object
    SDL_Renderer* _renderer; //drawing in the window
    
    //This was in Cave Story
    std::map<std::string, SDL_Surface*> _spriteSheets; //this will keep the loaded images so it doesn't reload them every time.
    
};

#endif

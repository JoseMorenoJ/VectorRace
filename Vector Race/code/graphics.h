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

#include <iostream>
#include <map>
#include <string>

#include "Player.h"
#include "Vector.h"
#include "Globals.h"

//Class Graphics: SDL tools to render, load images and draw them in the screen.
class Graphics
{
public:
    Graphics();
    ~Graphics();
    
    //void blitSurface
    //  Draws a texture to a part of the screen, the destination rectangle.
    void DrawTexture(SDL_Texture* texture
                     , SDL_Rect* sourceRectangle
                     , SDL_Rect* destinationRectangle);
    
    //SDL_Surface *LoadCircuit
    //  Loads the circuit from an image and returns it as a Surface
    SDL_Texture* LoadCircuitIMG(char filePath[]);
    
    //void SetColor
    //  Changes the color of the render
    void SetRenderColor(SDL_Color);
    
    //void DrawVector
    //  Draws the vector representation of the player
    void DrawVector(Vector*);
    //void DrawLine
    //  Draw a line between two coordinates
    void DrawLine(Coordinate*, Coordinate*);
    
    //void flip
    //  Renders everything to the screen.
    void Flip();
    
    //void clear
    //  Clears the screen.
    void Clear();
    
    //SDL_Renderer* getRender
    //  Return the _renderer.
    SDL_Renderer* GetRenderer() const;
    
    //SDL_Rect
    //  Returns a rectangle
    SDL_Rect MakeSDLRect(int X, int Y, int W, int H);
    
    //SDL_Texture
    //  Return the loaded Circuit as a texture
    SDL_Texture* GetCircuitIMG() const;
    
private:
    SDL_Window* _window; //window object
    SDL_Renderer* _renderer; //drawing in the window
    SDL_Color _clearColor; //used to clear the render
    
    SDL_Texture* _circuitIMG; //
    
    //This was in Cave Story
    std::map<std::string, SDL_Surface*> _spriteSheets; //this will keep the loaded images so it doesn't reload them every time.
    
    //Helper methods:
    void TakeScreenshot();
    
    
};

#endif //Story_Cave_Remake_graphics_h


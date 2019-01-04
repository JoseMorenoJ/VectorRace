//
//  Player.h
//  Vector Race
//
//  Created by José Moreno on 28/12/18.
//  Copyright (c) 2018 José Moreno. All rights reserved.
//

#ifndef __Vector_Race__Player__
#define __Vector_Race__Player__

#include <stdio.h>
#include <list>

#include <SDL2/SDL.h>

#include "Vector.h"

class Player
{
public:
    
    Player();
    ~Player();
    
    //Setters
    void SetVector(Vector);
    void SetLastVector(Vector);
    void SetColor(SDL_Color);
    void SetColor(Uint8 r, Uint8 g, Uint8 b, Uint8 a);
    void SetActive(bool);
    
    //Getters
    Vector* GetVector();
    Vector* GetLastVector();
    SDL_Color GetColor() const;
    Uint8 GetColorR() const;
    Uint8 GetColorG() const;
    Uint8 GetColorB() const;
    Uint8 GetColorA() const;
    bool IsActive() const;
    Coordinate GetTrace();
    std::list<Coordinate> * GetTraceList();
    
    //Movement
    void Up();
    void Down();
    void Left();
    void Right();
    
    //Hit Enter:
    void Enter();
    
private:
    Vector _vector; //the vector representation.
    Vector _lastVector; //last movement.
    SDL_Color _color; //color in which the player will be drawn
    bool _bActive; //determine if it is its turn or not.
    std::list<Coordinate> _trace; //list of the coordinates
    
    //Helper Methods
    void AddToTrace(Coordinate);
};

#endif /* defined(__Vector_Race__Player__) */

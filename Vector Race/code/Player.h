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
    void SetActive(bool);
    
    //Getters
    Vector* GetVector();
    Vector* GetLastVector();
    bool IsActive() const;
    
    //Movement
    void Up();
    void Down();
    void Left();
    void Right();
    
    //Hit Enter:
    void Enter();
    
private:
    Vector _vector; //The vector representation.
    Vector _lastVector; //last movement.
    bool _bActive; //Determine if it is its turn or not.
    
    SDL_Scancode _pressedKey; //to keep track of the pressed key before the Enter
    
};

#endif /* defined(__Vector_Race__Player__) */

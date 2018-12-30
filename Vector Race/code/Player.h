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
#include "Vector.h"

class Player
{
public:
    
    Player();
    ~Player();
    
    //Setters
    void SetVector(Vector);
    void SetLastCoordinate(Coordinate);
    void SetActive(bool);
    
    //Getters
    Vector GetVector() const;
    Coordinate GetLastCoordinate() const;
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
    Coordinate _lastCoordinate; //Keep track of the previous position.
    int _speedX;
    int _speedY;
    bool _bActive; //Determine if it is its turn or not.
    
};

#endif /* defined(__Vector_Race__Player__) */

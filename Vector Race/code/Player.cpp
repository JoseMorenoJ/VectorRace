//
//  Player.cpp
//  Vector Race
//
//  Created by José Moreno on 28/12/18.
//  Copyright (c) 2018 José Moreno. All rights reserved.
//

#include <iostream>

#include "Player.h"

//Constructor
Player::Player()
{
    _vector.SetTail( Coordinate(100,100) );
    _vector.SetSpeed( Coordinate(0,0) );
    _lastVector = _vector;
    SetColor(255, 255, 255, 255);
    _trace.push_back(_vector.GetTail());
    
    std::cout << "Player()" << std::endl;
    
    return;
}

//Destructor
Player::~Player()
{
    std::cout << "~Player()" << std::endl;

    return;
}

//Setters
void Player::SetVector(Vector newVector) { _vector = newVector; }
void Player::SetLastVector(Vector newVector) { _lastVector = newVector; }
void Player::SetColor(SDL_Color newColor) { _color = newColor; }
void Player::SetColor(Uint8 r, Uint8 g, Uint8 b, Uint8 a)
{
    _color.r = r;
    _color.g = g;
    _color.b = b;
    _color.a = a;
}
void Player::SetActive(bool newActive) { _bActive = newActive; }

//Getters
Vector* Player::GetVector() { return &_vector; }
Vector* Player::GetLastVector() { return &_lastVector; }
SDL_Color Player::GetColor() const { return _color; }
Uint8 Player::GetColorR() const { return _color.r; }
Uint8 Player::GetColorG() const { return _color.g; }
Uint8 Player::GetColorB() const { return _color.b; }
Uint8 Player::GetColorA() const { return _color.a; }
bool Player::IsActive() const { return _bActive; }
Coordinate Player::GetTrace() { return _trace.front(); }
std::list<Coordinate> * Player::GetTraceList() { return &_trace; }

//Movement
void Player::Up()
{
    _vector = _lastVector;
    _vector.SetSpeed(_vector.GetSpeed() + Coordinate(0, -10) );
    
    return;
}
void Player::Down()
{
    _vector = _lastVector;
    _vector.SetSpeed(_vector.GetSpeed() + Coordinate(0, 10) );
    
    return;
}

void Player::Left()
{
    _vector = _lastVector;
    _vector.SetSpeed(_vector.GetSpeed() + Coordinate(-10, 0) );

    return;
}
void Player::Right()
{
    _vector = _lastVector;
    _vector.SetSpeed(_vector.GetSpeed() + Coordinate(10, 0) );
    
    return;
}

//Hit Enter:
void Player::Enter()
{
    _vector.SetTail( _vector.GetTail() + _vector.GetSpeed() );
    
    _lastVector = _vector;
    
    //Add to the trace:
    AddToTrace(_vector.GetTail());
    
    std::cout << "Speed:" << _vector.GetSpeed() << std::endl;
    std::cout << "Position:" << _vector.GetTail() << std::endl;
    
    return;
}

void Player::AddToTrace(Coordinate point)
{
    //Add the coordinate to the trace
    _trace.push_back(point);
    
    return;
}

//
//  Player.cpp
//  Vector Race
//
//  Created by José Moreno on 28/12/18.
//  Copyright (c) 2018 José Moreno. All rights reserved.
//

#include <iostream>

#include "Player.h"
#include "Globals.h"

//Constructor
Player::Player()
{
    //std::cout << "Player()" << std::endl;
    
    _vector.SetOrigin( Coordinate(140,140) );
    _vector.SetSpeed( Coordinate(0,0) );
    _lastVector = _vector;
    SetColor(255, 255, 255, SDL_ALPHA_OPAQUE);
    _trace.push_back(_vector.GetOrigin());
}

//Destructor
Player::~Player() { std::cout << "~Player()" << std::endl; }

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
    //Update to the new position
    _vector.SetOrigin( _vector.GetOrigin() + _vector.GetSpeed() );
    _lastVector = _vector;
    
    AddToTrace(_vector.GetOrigin());
    
    std::cout << "Position:" << _vector.GetOrigin() << std::endl;
    
    return;
}

void Player::OnCrash()
{
    //Check that the vector is inside the screen limits
    if (_vector.GetOrigin().x < 0)
        _vector.SetOrigin( Coordinate(0, _vector.GetOrigin().y) );
    
    if (_vector.GetOrigin().y < 0)
        _vector.SetOrigin( Coordinate(_vector.GetOrigin().x, 0) );
    
    if (_vector.GetOrigin().x > SCREEN_WIDTH)
        _vector.SetOrigin( Coordinate(SCREEN_WIDTH, _vector.GetOrigin().y) );
    
    if (_vector.GetOrigin().x > SCREEN_HEIGHT)
        _vector.SetOrigin( Coordinate(_vector.GetOrigin().x, SCREEN_HEIGHT) );
    
    //Set speed to 0.
    _vector.SetSpeed(Coordinate(0,0));
}

inline void Player::AddToTrace(Coordinate point) { _trace.push_back(point); }

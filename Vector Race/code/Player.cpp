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
    _pressedKey = SDL_SCANCODE_0;
    
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
void Player::SetActive(bool newActive) { _bActive = newActive; }

//Getters
Vector* Player::GetVector() { return &_vector; }
Vector* Player::GetLastVector() { return &_lastVector; }
bool Player::IsActive() const { return _bActive; }

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
    
    _vector.SetTail(_vector.GetTail() + _vector.GetSpeed());
    
    _lastVector = _vector;
    
    std::cout << "Speed:" << _vector.GetSpeed().x << ", " << _vector.GetSpeed().y << std::endl;
    std::cout << "Position:" << _vector.GetTail().x << ", "
              << _vector.GetTail().y << std::endl;
    
    return;
}

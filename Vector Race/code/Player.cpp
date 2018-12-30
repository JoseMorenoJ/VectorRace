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
Player::Player() { return; }

//Destructor
Player::~Player() { return; }

//Setters
void Player::SetVector(Vector newVector) { _vector = newVector; }
void Player::SetLastCoordinate(Coordinate newCoord) { _lastCoordinate = newCoord; }
void Player::SetActive(bool newActive) { _bActive = newActive;}

//Getters
Vector Player::GetVector() const { return _vector; }
Coordinate Player::GetLastCoordinate() const { return _lastCoordinate; }
bool Player::IsActive() const { return _bActive; }

//Movement
void Player::Up()
{
    //Draws the vector head y - 1
    std::cout<<"x: " << _vector.GetHead().x << " y: " << _vector.GetHead().y - 1 << std::endl;
    return;
}
void Player::Down()
{
    //Draws the vector head y + 1
    std::cout<<"x: " << _vector.GetHead().x << " y: " << _vector.GetHead().y + 1 << std::endl;
    return;
}

void Player::Left()
{
    //Draws the vector head x - 1
    std::cout<<"x: " << _vector.GetHead().x - 1 << " y: " << _vector.GetHead().y << std::endl;
    return;
}
void Player::Right()
{
    //Draws the vector head x + 1
    std::cout<<"x: " << _vector.GetHead().x + 1 << " y: " << _vector.GetHead().y << std::endl;
    return;
}

//Hit Enter:
void Player::Enter()
{
    std::cout<<"Enter\n";
    //Sets the new head and the new speed
    Coordinate new_position(1,1);
    _vector.SetHead(new_position);
    std::cout << "new position" << new_position.x << ", " << new_position.y << std::endl;
    return;
}

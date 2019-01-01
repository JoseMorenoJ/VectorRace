//
//  Vector.cpp
//  Vector Race
//      this is the representation of the vector in the circuit
//
//  Created by José Moreno on 28/12/18.
//  Copyright (c) 2018 José Moreno. All rights reserved.
//

#include "Vector.h"

//Setters
void Vector::SetSpeed(Coordinate newSpeed) { _speed = newSpeed; }
void Vector::SetTail(Coordinate newTail)  { _tail = newTail; }
void Vector::SetColor(SDL_Color newColor) { _color = newColor; }
void Vector::SetColor(Uint8 r, Uint8 g, Uint8 b, Uint8 a)
{
    _color.r = r;
    _color.g = g;
    _color.b = b;
    _color.a = a;
}

//Getters
Coordinate Vector::GetSpeed() const { return _speed; }
Coordinate Vector::GetTail() const { return _tail; }
SDL_Color Vector::GetColor() const { return _color; }
Uint8 Vector::GetColorR() const { return _color.r; }
Uint8 Vector::GetColorG() const { return _color.g; }
Uint8 Vector::GetColorB() const { return _color.b; }
Uint8 Vector::GetColorA() const { return _color.a; }

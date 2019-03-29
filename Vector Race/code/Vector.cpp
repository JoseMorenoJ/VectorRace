//
//  Vector.cpp
//  Vector Race
//      this is the representation of the vector in the circuit
//
//  Created by José Moreno on 28/12/18.
//  Copyright (c) 2018 José Moreno. All rights reserved.
//

#include "Vector.h"

Vector::Vector() { /*std::cout << "Vector()" << std::endl;*/ }
Vector::~Vector() { /*std::cout << "~Vector()" << std::endl;*/ }

//Setters
void Vector::SetSpeed(Coordinate newSpeed) { _speed = newSpeed; }
void Vector::SetOrigin(Coordinate newTail)  { _origin = newTail; }

//Getters
Coordinate Vector::GetSpeed() const { return _speed; }
Coordinate Vector::GetOrigin() const { return _origin; }

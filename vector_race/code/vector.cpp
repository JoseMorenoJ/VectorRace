//
//  vector.cpp
//  vector Race
//      this is the representation of the vector in the circuit
//
//  Created by José Moreno on 28/12/18.
//  Copyright (c) 2018 José Moreno. All rights reserved.
//

#include "vector.h"

vector::vector()
{ /*std::cout << "vector()" << std::endl;*/
}
vector::~vector()
{ /*std::cout << "~vector()" << std::endl;*/
}

// Setters
void vector::set_speed(Coordinate newSpeed) { _speed = newSpeed; }
void vector::set_origin(Coordinate newTail) { _origin = newTail; }

// Getters
Coordinate vector::get_speed() const { return _speed; }
Coordinate vector::get_origin() const { return _origin; }

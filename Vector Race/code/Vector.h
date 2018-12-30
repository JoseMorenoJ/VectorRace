//
//  Vector.h
//  Vector Race
//      this is the representation of the vector in the circuit
//
//  Created by José Moreno on 28/12/18.
//  Copyright (c) 2018 José Moreno. All rights reserved.
//

#ifndef __Vector_Race__Vector__
#define __Vector_Race__Vector__

#include <stdio.h>


//Only valid coordinates are multiples of 5.
struct Coordinate {
    Coordinate(int x = 0, int y = 0): x(x), y(y){};
    int x;
    int y;
};

class Vector
{
public:
    //Setters
    void SetSpeed(Coordinate);
    void SetTail(Coordinate);
    
    //Getters
    Coordinate GetSpeed() const;
    Coordinate GetTail() const;
    
private:
    Coordinate _speed; //speed of the vector, its module
    Coordinate _tail; //position of the tail, origin point of the vector
};

#endif /* defined(__Vector_Race__Vector__) */

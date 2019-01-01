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
#include <SDL2/SDL.h>


//Only valid coordinates are multiples of 5.
struct Coordinate {
    Coordinate(int x = 0, int y = 0): x(x), y(y) {};
    int x;
    int y;
};

class Vector
{
public:
    //Setters
    void SetSpeed(Coordinate);
    void SetTail(Coordinate);
    void SetColor(SDL_Color);
    void SetColor(Uint8 r, Uint8 g, Uint8 b, Uint8 a);
    
    //Getters
    Coordinate GetSpeed() const;
    Coordinate GetTail() const;
    SDL_Color GetColor() const;
    Uint8 GetColorR() const;
    Uint8 GetColorG() const;
    Uint8 GetColorB() const;
    Uint8 GetColorA() const;
    
private:
    Coordinate _speed; //speed of the vector, its module
    Coordinate _tail; //position of the tail, origin point of the vector
    SDL_Color _color; //color in which the vector will be drawn
};


//Overload the Coordinate + operators
inline Coordinate operator+(Coordinate lhs, const Coordinate& rhs)
{
    lhs.x += rhs.x;
    lhs.y += rhs.y;
    return lhs;
}


#endif /* defined(__Vector_Race__Vector__) */

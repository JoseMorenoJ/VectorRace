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

#include <iostream>

#include <SDL2/SDL.h>


//Only valid coordinates are multiples of 5.
struct Coordinate {
    Coordinate(int x = 0, int y = 0): x(x), y(y) {};
    Coordinate(Coordinate const &c): x(c.x), y(c.y) { x = c.x; y = c.y; };
    int x;
    int y;
};

class Vector
{
public:
    Vector();
    ~Vector();
    
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


//Overload the Coordinate + operators
inline Coordinate operator+(Coordinate lhs, const Coordinate& rhs)
{
    lhs.x += rhs.x;
    lhs.y += rhs.y;
    return lhs;
}

inline std::ostream& operator<< (std::ostream& stream, const Coordinate& coord)
{
    stream << "(" << coord.x << ", " << coord.y << ")";
    return stream;
}

inline std::ostream& operator<< (std::ostream& stream, const SDL_Color& color)
{
    stream << "(" << (int)color.r << ", " << (int)color.g << ", " << (int)color.b << ")";
    return stream;
}


#endif /* defined(__Vector_Race__Vector__) */

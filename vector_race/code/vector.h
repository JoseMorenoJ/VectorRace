//
//  vector.h
//  Vector Race
//      this is the representation of the vector in the circuit
//
//  Created by José Moreno on 28/12/18.
//  Copyright (c) 2018 José Moreno. All rights reserved.
//

#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>

#include <SDL2/SDL.h>

// Coordinates in pixels on the screen.
struct Coordinate
{
    Coordinate(int x = 0, int y = 0) : x(x), y(y){};
    Coordinate(Coordinate const &c) : x(c.x), y(c.y)
    {
        x = c.x;
        y = c.y;
    };
    int x;
    int y;
};

class vector
{
public:
    vector();
    ~vector();

    // Setters
    void set_speed(Coordinate);
    void set_origin(Coordinate);

    // Getters
    Coordinate get_speed() const;
    Coordinate get_origin() const;

private:
    Coordinate _speed;  // speed of the vector, its module
    Coordinate _origin; // position of the origin point of the vector
};

// Overload the Coordinate + operators
inline Coordinate operator+(Coordinate lhs, const Coordinate &rhs)
{
    lhs.x += rhs.x;
    lhs.y += rhs.y;
    return lhs;
}

inline std::ostream &operator<<(std::ostream &stream, const Coordinate &coord)
{
    stream << "(" << coord.x << ", " << coord.y << ")";
    return stream;
}

inline std::ostream &operator<<(std::ostream &stream, const SDL_Color &color)
{
    stream << "(" << (int)color.r << ", " << (int)color.g << ", " << (int)color.b << ")";
    return stream;
}

#endif // #ifndef VECTOR_H

//
//  Player.h
//  vector Race
//
//  Created by José Moreno on 28/12/18.
//  Copyright (c) 2018 José Moreno. All rights reserved.
//

#ifndef PLAYER_H
#define PLAYER_H

#include <stdio.h>
#include <list>

#include <SDL2/SDL.h>

#include "vector.h"

class Player
{
public:
    Player();
    ~Player();

    // Setters
    void set_vector(vector);
    void set_last_vector(vector);
    void set_color(SDL_Color);
    void set_color(Uint8 r, Uint8 g, Uint8 b, Uint8 a);
    void set_active(bool);

    // Getters
    vector *get_vector();
    vector *get_last_vector();
    SDL_Color get_color() const;
    Uint8 get_color_r() const;
    Uint8 get_color_g() const;
    Uint8 get_color_b() const;
    Uint8 get_color_a() const;
    bool is_active() const;
    Coordinate get_trace();
    std::list<Coordinate> *get_trace_list();

    // Movement
    void up();
    void down();
    void left();
    void right();

    // Hit enter:
    void enter();

    void on_crash();

private:
    vector _vector;               // the vector representation.
    vector _lastvector;           // last movement.
    SDL_Color _color;             // color in which the player will be drawn
    bool _b_active;               // determine if it is its turn or not.
    std::list<Coordinate> _trace; // list of the coordinates

    // Helper Methods
    void add_to_trace(Coordinate);
};

#endif // #ifndef PLAYER_H

//
//  Player.cpp
//  vector Race
//
//  Created by José Moreno on 28/12/18.
//  Copyright (c) 2018 José Moreno. All rights reserved.
//

#include <iostream>

#include "Player.h"
#include "Globals.h"

// Constructor
Player::Player()
{
    // std::cout << "Player()" << std::endl;

    _vector.set_origin(Coordinate(140, 140));
    _vector.set_speed(Coordinate(0, 0));
    _lastvector = _vector;
    set_color(255, 255, 255, SDL_ALPHA_OPAQUE);
    _trace.push_back(_vector.get_origin());
}

// Destructor
Player::~Player() { std::cout << "~Player()" << std::endl; }

// Setters
void Player::set_vector(vector new_vector) { _vector = new_vector; }
void Player::set_last_vector(vector new_vector) { _lastvector = new_vector; }
void Player::set_color(SDL_Color new_color) { _color = new_color; }
void Player::set_color(Uint8 r, Uint8 g, Uint8 b, Uint8 a)
{
    _color.r = r;
    _color.g = g;
    _color.b = b;
    _color.a = a;
}
void Player::set_active(bool new_active) { _b_active = new_active; }

// Getters
vector *Player::get_vector() { return &_vector; }
vector *Player::get_last_vector() { return &_lastvector; }
SDL_Color Player::get_color() const { return _color; }
Uint8 Player::get_color_r() const { return _color.r; }
Uint8 Player::get_color_g() const { return _color.g; }
Uint8 Player::get_color_b() const { return _color.b; }
Uint8 Player::get_color_a() const { return _color.a; }
bool Player::is_active() const { return _b_active; }
Coordinate Player::get_trace() { return _trace.front(); }
std::list<Coordinate> *Player::get_trace_list() { return &_trace; }

// Movement
void Player::up()
{
    _vector = _lastvector;
    _vector.set_speed(_vector.get_speed() + Coordinate(0, -10));

    return;
}
void Player::down()
{
    _vector = _lastvector;
    _vector.set_speed(_vector.get_speed() + Coordinate(0, 10));

    return;
}

void Player::left()
{
    _vector = _lastvector;
    _vector.set_speed(_vector.get_speed() + Coordinate(-10, 0));

    return;
}

void Player::right()
{
    _vector = _lastvector;
    _vector.set_speed(_vector.get_speed() + Coordinate(10, 0));

    return;
}

// Hit enter:
void Player::enter()
{
    // Update to the new position
    _vector.set_origin(_vector.get_origin() + _vector.get_speed());
    _lastvector = _vector;

    add_to_trace(_vector.get_origin());

    std::cout << "Position:" << _vector.get_origin() << std::endl;

    return;
}

void Player::on_crash()
{
    // Check that the vector is inside the screen limits
    if (_vector.get_origin().x < 0)
        _vector.set_origin(Coordinate(0, _vector.get_origin().y));

    if (_vector.get_origin().y < 0)
        _vector.set_origin(Coordinate(_vector.get_origin().x, 0));

    if (_vector.get_origin().x > SCREEN_WIDTH)
        _vector.set_origin(Coordinate(SCREEN_WIDTH, _vector.get_origin().y));

    if (_vector.get_origin().x > SCREEN_HEIGHT)
        _vector.set_origin(Coordinate(_vector.get_origin().x, SCREEN_HEIGHT));

    // Set speed to 0.
    _vector.set_speed(Coordinate(0, 0));
}

inline void Player::add_to_trace(Coordinate point) { _trace.push_back(point); }

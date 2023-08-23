//
//  Circuit.h
//  vector Race
//
//  Created by José Moreno on 29/12/18.
//  Copyright (c) 2018 José Moreno. All rights reserved.
//

#ifndef CIRCUIT_H
#define CIRCUIT_H

#include <stdio.h>
#include <vector>

#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>

#include "vector.h"
#include "Globals.h"

typedef enum : int
{
    INVALID = 0,
    VALID = 1,
    OTHER = 2,
} GridElementState;

struct GridElement
{
    Coordinate point;
    GridElementState state;
};

class Circuit
{

public:
    Circuit(char *);
    Circuit();
    ~Circuit();

    bool is_inside(Coordinate);

private:
    // this represents every possible position in the circuit
    int _grid[SCREEN_WIDTH / 10][SCREEN_HEIGHT / 10];
    std::vector<GridElement> _circuit_grid; // the circuit loaded from the png file

    std::vector<GridElement> read_bmp(char *filename);
    void init_grid();
};

#endif // #ifndef CIRCUIT_H

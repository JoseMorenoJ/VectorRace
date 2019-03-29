//
//  Circuit.h
//  Vector Race
//
//  Created by José Moreno on 29/12/18.
//  Copyright (c) 2018 José Moreno. All rights reserved.
//

#ifndef __Vector_Race__Circuit__
#define __Vector_Race__Circuit__

#include <stdio.h>
#include <vector>

#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>

#include "Vector.h"
#include "Globals.h"

typedef enum : int {
    INVALID = 0,
    VALID = 1,
    OTHER = 2,
} GridElementState;

struct GridElement {
    Coordinate point;
    GridElementState state;
};

class Circuit {
    
public:
    Circuit(char*);
    Circuit();
    ~Circuit();
    
    bool IsInside(Coordinate);
    
private:
    //this represents every possible position in the circuit
    int _grid[SCREEN_WIDTH/10][SCREEN_HEIGHT/10];
    std::vector <GridElement> _CircuitGrid; //the circuit loaded from the png file
    
    std::vector<GridElement> readBMP(char* filename);
    void InitGrid();
    
};

#endif /* defined(__Vector_Race__Circuit__) */

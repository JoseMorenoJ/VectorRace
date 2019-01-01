//
//  Map.cpp
//  Vector Race
//
//  Created by José Moreno on 29/12/18.
//  Copyright (c) 2018 José Moreno. All rights reserved.
//

#include <iostream>

#include "Map.h"

void Map::InitGrid()
{
    const int ROWS = sizeof(_grid)/sizeof(_grid[0]); // whole grid / first row
    const int COLS = sizeof(_grid[0])/sizeof(int);   // first row / element
        
    for (int row = 0; row < ROWS; ++row) {
        for (int col = 0; col < COLS; ++col) {
            _grid[col][row] = 0;
        }
    }
    return;
}

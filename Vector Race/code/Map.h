//
//  Map.h
//  Vector Race
//
//  Created by José Moreno on 29/12/18.
//  Copyright (c) 2018 José Moreno. All rights reserved.
//

#ifndef __Vector_Race__Map__
#define __Vector_Race__Map__

#include <stdio.h>
#include <vector>

struct GridElement {
    int x;
    int y;
    int state;
};

class Map {
    
public:
    void InitGrid();
    
private:
    int _grid[10][10]; //this represents every possible position in the map
    
};

#endif /* defined(__Vector_Race__Map__) */

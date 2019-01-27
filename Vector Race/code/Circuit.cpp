//
//  Circuit.cpp
//  Vector Race
//
//  Created by José Moreno on 29/12/18.
//  Copyright (c) 2018 José Moreno. All rights reserved.
//

#include <iostream>

#include "Circuit.h"

Circuit::Circuit(char *filePath) {
    //read BMP and create the grid
}
Circuit::Circuit(){};

Circuit::~Circuit(){};

void Circuit::InitGrid()
{
    const int ROWS = sizeof(_grid)/sizeof(_grid[0]); // whole grid / first row
    const int COLS = sizeof(_grid[0])/sizeof(int);   // first row / element
    
    std::cout << "Rows: " << ROWS << "\tCols:" << COLS << std::endl;
    
    //_grid: 0 = OK; >0 = not OK;
    
    //init all with 0 until we are able to read the png/bmp file.
    for (int row = 0; row < ROWS; ++row) {
        for (int col = 0; col < COLS; ++col) {
            _grid[col][row] = 0;
        }
    }
    return;
}

bool Circuit::IsInside(Coordinate coord)
{
    //Screen limits
    if(coord.x < 0 || coord.y < 0)
        return false;
    if (coord.x > SCREEN_WIDTH || coord.y > SCREEN_HEIGHT)
        return false;
    
    //Circuit shape
    if(_grid[coord.x/10][coord.y/10])
        return true;
    else return false;
}

std::vector<GridElement> Circuit::readBMP(char* filename)
{
    int i;
    FILE* f = fopen(filename, "rb");
    unsigned char info[54];
    fread(info, sizeof(unsigned char), 54, f); // read the 54-byte header
    
    // extract image height and width from header
    int width = *(int*)&info[18];
    int height = *(int*)&info[22];
    
    int size = 3 * width * height;
    unsigned char* data = new unsigned char[size]; // allocate 3 bytes per pixel
    fread(data, sizeof(unsigned char), size, f); // read the rest of the data at once
    fclose(f);
    
    for(i = 0; i < size; i += 3)
    {
        unsigned char tmp = data[i];
        data[i] = data[i+2];
        data[i+2] = tmp;
    }
    
    return data;
}
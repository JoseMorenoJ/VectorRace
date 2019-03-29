//
//  Circuit.cpp
//  Vector Race
//
//  Created by José Moreno on 29/12/18.
//  Copyright (c) 2018 José Moreno. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <exception>

#include "Circuit.h"

Circuit::Circuit(char *filePath) {
    //read BMP and create the grid
    std::cout << "Circuit(filepaht)" << std::endl;
    readBMP(filePath);
    InitGrid();
}

Circuit::Circuit(){};

Circuit::~Circuit(){};

void Circuit::InitGrid()
{
    const int ROWS = sizeof(_grid)/sizeof(_grid[0]); // whole grid / first row
    const int COLS = sizeof(_grid[0])/sizeof(int);   // first row / element
    
    std::cout << "Rows: " << ROWS << "\tCols:" << COLS << std::endl;
    
    //_grid: 0 = not OK; >0 = OK and others;
    
    //init all with 0 until we are able to read the bmp file.
    for (int row = 0; row < ROWS; ++row) {
        for (int col = 0; col < COLS; ++col) {
            _grid[col][row] = 1;
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

//TODO: read the bmp files and
std::vector<GridElement> Circuit::readBMP(char* filename)
{
    std::fstream fich;
    fich.open(filename);
    //fich.open("resources/Test_Circuit.png");
    
    try {
        fich.open(filename);
    } catch (std::exception &e) {
        std::cout << e.what() << "Error with bmp file, trying with png" << std::endl;
        fich.open("resources/Test_Circuit.png");
    }
    //*********************************
    // get length of file:
    fich.seekg (0, fich.end);
        int length = fich.tellg(); //libc++abi.dylib: terminating with uncaught exception of type std::bad_alloc: std::bad_alloc
        fich.seekg (0, fich.beg);
        
        char * buffer = new char [length];
        
        std::cout << "Reading " << length << " characters... ";
        // read data as a block:
        fich.read (buffer,length);
        
        if (fich)
            std::cout << "all characters read successfully.";
        else
            std::cout << "error: only " << fich.gcount() << " could be read";
        fich.close();
        
        // ...buffer contains the entire file...
        
        delete[] buffer;

    //*********************************
    /*
    unsigned char info[54];
    fread(info, sizeof(unsigned char), 54, f); // read the 54-byte header
    std::cout << "info:" << info << std::endl;
    
    // extract image height and width from header
    int width = *(int*)&info[18];
    int height = *(int*)&info[22];
    std::cout << "width:" << width << " height:" << height << std::endl;
    
    int size = 3 * width * height;
    unsigned char* data = new unsigned char[size]; // allocate 3 bytes per pixel
    fread(data, sizeof(unsigned char), size, f); // read the rest of the data at once
    fclose(f);
    
    for(int i = 0; i < size; i += 3)
    {
        unsigned char tmp = data[i];
        data[i] = data[i+2];
        data[i+2] = tmp;
        std::cout << "\t" << (int)data[i];
    }
    */
    return _CircuitGrid;
}
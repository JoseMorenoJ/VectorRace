//
//  VectorRace.h
//  Vector Race
//      VectorRace class: Game manager of the Vector Race game. Main loop.
//
//  Created by José Moreno on 28/12/18.
//  Copyright (c) 2018 José Moreno. All rights reserved.
//

#ifndef __Vector_Race__VectorRace__
#define __Vector_Race__VectorRace__

#include <stdio.h>

#include <SDL2/SDL.h>

#include "Player.h"

class VectorRace
{
public:
    
    void NewGame();
    void PrepareRace(Player*, Player*);
        
    bool isGameOver();
    
    void processKey(SDL_Scancode, Player);
    
private:
    bool _bGameOver;
    
    //Helper Functions:
    Player GetActivePlayer();
    
};

#endif /* defined(__Vector_Race__VectorRace__) */

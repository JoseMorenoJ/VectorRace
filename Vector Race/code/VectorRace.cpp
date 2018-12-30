//
//  VectorRace.cpp
//  Vector Race
//      VectorRace class: Game manager of the Vector Race game. Main loop.
//
//  Created by José Moreno on 28/12/18.
//  Copyright (c) 2018 José Moreno. All rights reserved.
//

#include <SDL2/SDL.h>
#include <iostream>

#include "VectorRace.h"
#include "graphics.h"
#include "Map.h"

void VectorRace::NewGame()
{
    SDL_Event event;
    SDL_Scancode pressedKey;
    
    Graphics graphics;
    
    //TODO: Update to a vector of players.
    Player player1, player2;
    
    Player activePlayer;
    
    //To control the time between frames. To limit the fps
    int LAST_UPDATE_TIME = SDL_GetTicks(); // it gets the ticks since the last get
    const int FPS = 30;
    
    //Load the circuit and set the players
    PrepareRace(&player1, &player2);
    
    //main game loop
    while ( !isGameOver() )
    {
        if( SDL_PollEvent(&event) ) //true = pending events, false = no events.
        {
            //activePlayer = GetActivePlayer();
            activePlayer = player1;
            if (event.type == SDL_KEYDOWN)
            {
                pressedKey = event.key.keysym.scancode;
                processKey(pressedKey, activePlayer);
            }
        }
        //Control the fps
        const int CURRENT_TIME_MS = SDL_GetTicks();
        int ELAPSED_TIME_MS = CURRENT_TIME_MS - LAST_UPDATE_TIME;
        if(ELAPSED_TIME_MS < 1000/FPS)
        {
            //wait until we have the fps that we want
        }
    }
    //Present results?
    
    //Cleanup
}

void VectorRace::PrepareRace(Player* p1, Player* p2)
{
    Map circuit;
    
    circuit.InitGrid();
    
    return;
}

bool VectorRace::isGameOver()
{
    return _bGameOver;
}

void VectorRace::processKey(SDL_Scancode pressedKey, Player activePlayer)
{
    switch (pressedKey) {
        case SDL_SCANCODE_UP:
            activePlayer.Up();
            break;
            
        case SDL_SCANCODE_DOWN:
            activePlayer.Down();
            break;
            
        case SDL_SCANCODE_LEFT:
            activePlayer.Left();
            break;
            
        case SDL_SCANCODE_RIGHT:
            activePlayer.Right();
            break;
            
        case SDL_SCANCODE_RETURN:
            activePlayer.Enter();
            break;
            
        case SDL_SCANCODE_ESCAPE:
            std::cout<<"ESCAPE\n";
            _bGameOver = true;
            break;
            
        default:
            break;
    }
    return;
}

Player VectorRace::GetActivePlayer()
{
    Player foo;
    return foo;
}

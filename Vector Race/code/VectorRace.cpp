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

VectorRace::VectorRace()
{
    SDL_Init(SDL_INIT_EVERYTHING);
    _clearColor.r = 255;
    _clearColor.g = 255;
    _clearColor.b = 255;
    _clearColor.a = SDL_ALPHA_OPAQUE;
}

VectorRace::~VectorRace() { return; }

void VectorRace::NewGame()
{
    SDL_Event event;
    SDL_Scancode pressedKey;
    
    Graphics graphics;
    
    //TODO: Update to a vector of players.
    Player player1, player2;
    
    SetPlayersColors(&player1, &player2);
    
    Player *activePlayer;
    
    //To control the time between frames. To limit the fps
    int LAST_UPDATE_TIME = SDL_GetTicks(); // it gets the ticks since the last get
    const int FPS = 30;
    
    std::string CircuitFilePath = "resources/TestMap.png";
    //graphics.LoadMap(CircuitFilePath);
        
    //Load the circuit and set the players
    PrepareRace(&player1, &player2);
    
    //main game loop
    while ( !isGameOver() )
    {
        if( SDL_PollEvent(&event) ) //true = pending events, false = no events.
        {
            if (event.type == SDL_KEYDOWN) //Only interested in events when the key is down
            {
                //activePlayer = GetActivePlayer();
                activePlayer = &player1;
            
                pressedKey = event.key.keysym.scancode;
                processKey(pressedKey, activePlayer);
                
                graphics.SetRenderColor(activePlayer->GetVector()->GetColor());
                
                graphics.DrawVector( activePlayer->GetVector() );
                
                //Render
                graphics.Render();
            }
        }
        
        graphics.SetRenderColor(_clearColor);
        graphics.Clear();
        
        //Control the fps
        const int CURRENT_TIME_MS = SDL_GetTicks();
        int ELAPSED_TIME_MS = CURRENT_TIME_MS - LAST_UPDATE_TIME;
        if(ELAPSED_TIME_MS < 1000/FPS)
        {
            //wait until we have the fps that we want
        }
        //std::cout << "frame(ms)" << ELAPSED_TIME_MS << std::endl;
    }
    //Present results?
    std::cout<<"out of game loop\n";
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

void VectorRace::processKey(SDL_Scancode pressedKey, Player *activePlayer)
{
    switch (pressedKey) {
        case SDL_SCANCODE_UP:
            activePlayer->Up();
            break;
            
        case SDL_SCANCODE_DOWN:
            activePlayer->Down();
            break;
            
        case SDL_SCANCODE_LEFT:
            activePlayer->Left();
            break;
            
        case SDL_SCANCODE_RIGHT:
            activePlayer->Right();
            break;
            
        case SDL_SCANCODE_RETURN:
            activePlayer->Enter();
            //TODO: NextPlayer();
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

void VectorRace::SetPlayersColors(Player* p1, Player* p2)
{
    p1->GetVector()->SetColor(255, 0, 0, SDL_ALPHA_OPAQUE);
    p2->GetVector()->SetColor(0, 255, 0, SDL_ALPHA_OPAQUE);
}

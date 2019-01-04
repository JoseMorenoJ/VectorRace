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
#include <memory>

#include "VectorRace.h"
#include "Map.h"

VectorRace::VectorRace()
{
    SDL_Init(SDL_INIT_EVERYTHING);
}

VectorRace::~VectorRace() { return; }

void VectorRace::NewGame()
{
    SDL_Event event;
    
    Graphics graphics;
    
    //TODO: Update to a vector of players.
    Player* players [2];
    players[0] = new Player;
    players[1] = new Player;
    
    SetPlayersColors(players);
    
    //active player is player 1 by default
    Player* activePlayer;
    players[0]->SetActive(true);
    activePlayer = players[0];
    
    //To control the time between frames. To limit the fps
    int LAST_UPDATE_TIME = SDL_GetTicks(); // it gets the ticks since the last get
    const int FPS = 30;
    
    //Load the circuit and set the players
    //  load the Map object and fill up the grid
    PrepareRace(players[0], players[1]); //TODO
    
    //main game loop
    while ( !isGameOver() )
    {
        if( SDL_PollEvent(&event) ) //true = pending events, false = no events.
        {
            if (event.type == SDL_KEYDOWN) //Only interested in events when the key is down
            {
                activePlayer = GetActivePlayer(players);
                
                const SDL_Scancode pressedKey = event.key.keysym.scancode;
                processKey(pressedKey, activePlayer);
                
                if (pressedKey == SDL_SCANCODE_RETURN) {
                    
                    activePlayer = GetNextPlayer(players);
                }
            }
        }
        
        //DrawScreen(&graphics, players);
        
        //Render any other information (ex: HUB)
        
        //Render the map
        std::string CircuitFilePath = "resources/TestMap.png";
        graphics.LoadMap(CircuitFilePath);
        
        //Render the traces of the players
        for (int i=0; i<2; ++i) {
            graphics.SetRenderColor( players[i]->GetColor() );
            Coordinate temp = players[i]->GetTrace(); //previous coordinate
            for (auto Coord: *players[i]->GetTraceList()) {
                graphics.DrawLine(&temp, &Coord);
                temp = Coord;
            }
        }
        
        graphics.SetRenderColor( activePlayer->GetColor() );
        graphics.DrawVector( activePlayer->GetVector() );
        
        //Draw the renderer in the screen
        graphics.Flip();
        
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

/*
void DrawScreen(Graphics* graphics, Player* players[])
{
    return;
}
*/
 
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

Player* VectorRace::GetActivePlayer(Player* players[])
{
    for(int i = 0; i < 2; ++i)
    {
        if(players[i]->IsActive())
        {
            return players[i];
        }
    }
    return nullptr;
}

void VectorRace::SetPlayersColors(Player* players[])
{
    players[0]->SetColor(255, 0, 0, SDL_ALPHA_OPAQUE);
    players[1]->SetColor(0, 255, 0, SDL_ALPHA_OPAQUE);
    return;
}

Player* VectorRace::GetNextPlayer(Player* players[])
{
    if(players[0]->IsActive())
    {
        players[0]->SetActive(false);
        players[1]->SetActive(true);
        return players[1];
    }
    else if(players[1]->IsActive())
    {
        players[1]->SetActive(false);
        players[0]->SetActive(true);
        return players[0];
    }
    return nullptr;
}

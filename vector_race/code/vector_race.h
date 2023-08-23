//
//  vector_race.h
//  vector Race
//      vector_race class: Game manager of the vector Race game. Main loop.
//
//  Created by José Moreno on 28/12/18.
//  Copyright (c) 2018 José Moreno. All rights reserved.
//

#ifndef VECTOR_RACE_H
#define VECTOR_RACE_H

#include <stdio.h>

#include <SDL2/SDL.h>

#include "Player.h"
#include "graphics.h"

class VectorRace
{
public:
    VectorRace();
    ~VectorRace();

    void new_game();
    void prepare_race(Player *, Player *);
    // void Draw_Screen(Graphics* graphics, Player* players[]);

    bool is_game_over();

    void process_key(SDL_Scancode, Player *);

private:
    bool _b_game_over; // Control of the game loop

    // Helper Functions:
    Player *get_active_player(Player *players[]);
    void set_players_colors(Player *players[]);
    Player *get_next_player(Player *players[]);
};

#endif // #ifndef VECTOR_RACE_H

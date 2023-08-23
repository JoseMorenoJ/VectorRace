//
//  vector_race.cpp
//  vector Race
//      vector_race class: Game manager of the vector Race game. Main loop.
//
//  Created by José Moreno on 28/12/18.
//  Copyright (c) 2018 José Moreno. All rights reserved.
//

#include <iostream>
#include <memory>

#include "vector_race.h"
#include "circuit.h"

VectorRace::VectorRace()
{
    // Here initialize the game
}

VectorRace::~VectorRace() { return; }

void VectorRace::new_game()
{
    SDL_Event event;

    Graphics graphics;

    // TODO: Update to a vector of players.
    Player *players[2];
    players[0] = new Player;
    players[1] = new Player;

    set_player_colors(players);

    // active player is player 1 by default
    Player *active_player;
    players[0]->set_active(true);
    active_player = players[0];

    // To control the time between frames. To limit the fps
    int last_update_time = sdl_get_ticks(); // it gets the ticks since the last get
    const int FPS = 25;

    // Load the circuit and set the players
    char circuit_file_path[] = "../resources/Test_Circuit.bmp";
    Circuit circuit(circuit_file_path);
    graphics.load_circuit_img(circuit_file_path);

    // main game loop
    while (!is_game_over())
    {
        if (SDL_PollEvent(&event)) // true = pending events, false = no events.
        {
            if (event.type == SDL_KEYDOWN) // Only interested in events when the key is down
            {
                active_player = get_active_player(players);

                const SDL_Scancode pressed_key = event.key.keysym.scancode;
                process_key(pressed_key, active_player);

                if (pressed_key == SDL_SCANCODE_RETURN)
                {

                    if (!circuit.is_inside(active_player->get_vector()->get_origin()))
                    {
                        active_player->on_crash();
                    }

                    active_player = get_next_player(players);
                }
            }
        }

        // draw_screen(&graphics, players); //************************

        // Render any other information (ex: HUB)

        // Render the Circuit
        SDL_Rect src_rect = graphics.make_sdl_rect(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
        SDL_Rect dest_rect = graphics.make_sdl_rect(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);

        // get circuit returns a SDL_texture*
        graphics.draw_texture(graphics.get_circuit_img(), &src_rect, &dest_rect);

        // Render the traces of the players
        for (int i = 0; i < 2; ++i)
        {
            graphics.set_render_color(players[i]->get_color());
            Coordinate temp = players[i]->get_trace(); // previous coordinate
            for (auto coord : *players[i]->get_trace_list())
            {
                graphics.draw_line(&temp, &coord);
                temp = coord;
            }
        }
        //**********************************************************

        graphics.set_render_color(active_player->get_color());
        graphics.draw_vector(active_player->get_vector());

        // Draw the renderer in the screen
        graphics.flip();

        graphics.clear();

        // Control the fps
        const int current_time_ms = sdl_get_ticks();
        int elapsed_time_ms = current_time_ms - last_update_time;

        if (elapsed_time_ms < 1000 / FPS)
        {
            // wait until we have the fps that we want
            SDL_Delay((1000 / FPS) - elapsed_time_ms);
        }
        // else{ std::cout << "frame(ms)" << elapsed_time_ms << std::endl; }
        last_update_time = current_time_ms;
    }

    // Present results?
    std::cout << "out of game loop\n";

    // Cleanup
    delete players[0];
    delete players[1];
}

void VectorRace::prepare_race(Player *p1, Player *p2)
{
    Circuit circuit;

    // circuit.init_grid();

    return;
}

/*
void draw_screen(Graphics* graphics, Player* players[])
{
    return;
}
*/

bool VectorRace::is_game_over()
{
    return _bGameOver;
}

void VectorRace::process_key(SDL_Scancode pressed_key, Player *active_player)
{
    // Process the key strokes
}

Player *VectorRace::get_active_player(Player *players[])
{
    for (int i = 0; i < 2; ++i)
    {
        if (players[i]->is_active())
        {
            return players[i];
        }
    }
    return nullptr;
}

void VectorRace::set_player_colors(Player *players[])
{
    players[0]->set_color(255, 0, 0, SDL_ALPHA_OPAQUE);
    players[1]->set_color(0, 255, 0, SDL_ALPHA_OPAQUE);
    return;
}

Player *VectorRace::get_next_player(Player *players[])
{
    if (players[0]->is_active())
    {
        players[0]->set_active(false);
        players[1]->set_active(true);
        return players[1];
    }
    else if (players[1]->is_active())
    {
        players[1]->set_active(false);
        players[0]->set_active(true);
        return players[0];
    }
    return nullptr;
}

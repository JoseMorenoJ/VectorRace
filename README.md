# VectorRace
A race of vectors.

## To do
### State Machine
Add a State Machine where each state will be either the menu, the game, the pause menu from the game.
- Main menu: player/game selection and options menu
- Game: the race itself
- Pause menu: menu opened from a game.
States: 
```
MainMenu  --NewGame--> Game  -----ESC----> PauseMenu
                       Game <--Continue--  PauseMenu
MainMenu <------------------Exit---------- PauseMenu
```

Similarly, we will need to define a Context for those states (which will be the components of the class, basicaly).

### Check local files in the laptop, there should be a "ToDo" file somewhere

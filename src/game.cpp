#include "../headers/game.hpp"
#include "../raylib/include/raylib.h"


Game::Game() : current_screen(MENU_SCREEN)
{}
void Game::Manage_Screens()
{
    switch(current_screen)
    {
        case MENU_SCREEN:
            Menu_Screen();
            break;

        case CHARACTER_SELECT_SCREEN:
           // Character_Select_Screen();
            break;

        case GAME_SCREEN:
          //  Game_Screen();
            break;

        case GAME_OVER_SCREEN:
            //Game_Over_Screen();
            break;
    }
}

void Game::Menu_Screen()
{
    
    BeginDrawing();
    ClearBackground(BLACK);
    EndDrawing();    

}
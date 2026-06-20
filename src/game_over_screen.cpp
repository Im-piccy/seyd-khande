#include "../headers/game.hpp"
#include "../raylib/include/raylib.h"

void Game::Game_Over_Screen()
{
    BeginDrawing();
    ClearBackground(BLACK);
    DrawText("WON!", 450, 300,30 , WHITE);
    EndDrawing();
    if(WindowShouldClose)
    {
        current_screen = WINDOWSHOULDCLOSE;
    }
}
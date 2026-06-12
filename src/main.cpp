#include "../raylib/include/raylib.h"
#include "../headers/game.hpp"
const int SCREEN_WIDTH = 1000;
const int SCREEN_HEIGHT = 600;

int main()
{
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "SEYD KHANDE");
    SetTargetFPS(30);
    InitAudioDevice();
    Game game_manager;
    while(!WindowShouldClose())
    {
        if(game_manager.Manage_Screens())
        {}
        else
        {
            break;
        }
    }
    CloseWindow();
    CloseAudioDevice();
    return 0;
}


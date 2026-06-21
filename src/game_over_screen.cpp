#include "../headers/game.hpp"
#include "../raylib/include/raylib.h"

void string_to_char_array(const std::string& st, char out[]);

void Game::Game_Over_Screen()
{
    char username[26];
    string_to_char_array(control.Return_Name_Of_Winner(), username);
    BeginDrawing();
    ClearBackground(BLACK);
    DrawText(username, 200, 300,30 , WHITE);
    DrawText("WON!", 500, 300,30 , WHITE);
    EndDrawing();
    if(WindowShouldClose())
    {
        current_screen = WINDOWSHOULDCLOSE;
    }
}
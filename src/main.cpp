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

void string_to_char_array(const std::string& st, char out[])
{
    
    if(st.empty())
    {
        out[0] = '\0';
        return;
    }
    int i;
    for(i = 0 ; i < st.length()  && i < 25; i++)
    {
        out[i] = st[i];
    }
    out[i] = '\0';
    
}
#include "../headers/game.hpp"
#include "../raylib/include/raylib.h"
#include <iostream>


Game::Game() : current_screen(MENU_SCREEN)
{}
bool Game::Manage_Screens()
{
    switch(current_screen)
    {
        case MENU_SCREEN:
            Menu_Screen();
            return true;

        case CHARACTER_SELECT_SCREEN:
           // Character_Select_Screen();
            break;

        case GAME_SCREEN:
          //  Game_Screen();
            break;

        case GAME_OVER_SCREEN:
            //Game_Over_Screen();
            break;

        case WINDOWSHOULDCLOSE:
            return false;
    }
}

void Game::Menu_Screen()
{
    static Music Starting_Menu_Music = LoadMusicStream("game_assets/starting_menu_assets/startmenu.mp3");
    static Texture2D background = LoadTexture("game_assets/starting_menu_assets/starting_menu_background.jpg");
    static Texture2D Button = LoadTexture("game_assets/starting_menu_assets/button.jpg");
    static Texture2D Sign = LoadTexture("game_assets/starting_menu_assets/sign.png");
    static Sound swordsfx = LoadSound("game_assets/starting_menu_assets/swordsfx.mp3");
    static Sound Transition_sound = LoadSound("game_assets/starting_menu_assets/transition_sound.mp3");
    
    static bool Is_Cursor_Inside_botton = false;
    static float fade = 0;
    static bool Begin_Fading = false;
    bool Should_Exit = false;
    bool Should_Start_Game = false;
    char start_txt[] = "Start";
    char Exit_txt[] = "Exit";
    
    int font_size = 50;
    int Start_txt_width = MeasureText(start_txt,font_size);
    int Exit_txt_width = MeasureText(Exit_txt,font_size);
    static bool music_is_playing = false;
    if(!music_is_playing)
    {
        PlayMusicStream(Starting_Menu_Music);
        music_is_playing = true;
    }
    BeginDrawing();
    ClearBackground(BLACK);
    DrawTexture(background,0,0,WHITE);
    DrawTexture(Button,40,280,GRAY);
    DrawTexture(Button,40,430,GRAY);
    DrawTexture(Sign,15,0,WHITE);
    DrawText(start_txt,136 - (Start_txt_width/2),320, font_size, GRAY);//printing start txt on screen
    DrawText(Exit_txt,136 - (Exit_txt_width/2),470, font_size, GRAY);//printing exit txt on screen
    
    //cheking to see if mouse cursor is on the  buttons
    if(GetMouseX() <= 233 && GetMouseX() >= 40 && !Begin_Fading)
    {
        if(GetMouseY() >= 280 && GetMouseY() <= 410 )
        {
            //mouse is on the start button
            DrawText(start_txt,136 - (Start_txt_width/2),320, font_size, WHITE);//printing start txt on screen
            if(!Is_Cursor_Inside_botton)
            {
                Is_Cursor_Inside_botton = true;
                PlaySound(swordsfx);
            }
            //checking to see if the button has been pressed
            if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
            {
                Should_Start_Game = true;
                Begin_Fading = true;
                PauseMusicStream(Starting_Menu_Music);
                PlaySound(Transition_sound);
            }
        }
        else if(GetMouseY() >= 430 && GetMouseY() <= 560 )
        {
            //mouse is on the exit button
            DrawText(Exit_txt,136 - (Exit_txt_width/2),470, font_size, WHITE);//printing exit txt on screen
            if(!Is_Cursor_Inside_botton)
            {
                Is_Cursor_Inside_botton = true;
                PlaySound(swordsfx);
            }
            //checking to see if the button has been pressed
            if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
            {
                Should_Exit = true;
            }
        }
    }
    else if (!Begin_Fading)
    {
        Is_Cursor_Inside_botton = false;
    }
    else
    {
        //this is to transition from start menu to character select screen
        DrawRectangle(0,0,GetScreenWidth(),GetScreenHeight(),Fade(BLACK,fade/255));
        fade += 8;
        if(fade >= 255)
        {
            fade = 255;
        }
    }
    EndDrawing();    
    UpdateMusicStream(Starting_Menu_Music);
    if(Should_Start_Game || Should_Exit)
    {
        
        //logical part of the program
        if(Should_Exit)
        {
            current_screen = WINDOWSHOULDCLOSE;
        }
        else if(Should_Start_Game && fade == 255)
        {
            current_screen = CHARACTER_SELECT_SCREEN;
        }
        //to empty RAM resources
        UnloadMusicStream(Starting_Menu_Music);
        UnloadTexture(background);
        UnloadTexture(Button);
        UnloadTexture(Sign);
        UnloadSound(swordsfx);
        UnloadSound(Transition_sound);
    }


}
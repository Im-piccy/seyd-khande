#include "../headers/game.hpp"
#include "../raylib/include/raylib.h"


void Game::Menu_Screen()
{
    //sound and music assets
    static Music Starting_Menu_Music = LoadMusicStream("game_assets/starting_menu_assets/startmenu.mp3");
    static Sound transition_sound = LoadSound("game_assets/starting_menu_assets/transition_sound.mp3");
    static Sound swordsfx = LoadSound("game_assets/starting_menu_assets/swordsfx.mp3");
    
    //img asstes
    static Texture2D background = LoadTexture("game_assets/starting_menu_assets/starting_menu_background.jpg");
    static Texture2D Button = LoadTexture("game_assets/starting_menu_assets/button.jpg");
    static Texture2D Sign = LoadTexture("game_assets/starting_menu_assets/sign.png");
    
    //variables for program's logic
    static bool Is_Cursor_Inside_botton = false;
    static float fade = 0;
    static bool Begin_Fading = false;
    static bool Should_Exit = false;
    static bool Should_Start_Game = false;
    static bool Is_transitin_sound_started = false;
    static bool Is_transition_sound_finished = false;
    static bool music_is_playing = false;
    
    //variables for drawing on the screeen 
    char start_txt[] = "Start";
    char Exit_txt[] = "Exit";
    int font_size = 50;
    int Start_txt_width = MeasureText(start_txt,font_size);
    int Exit_txt_width = MeasureText(Exit_txt,font_size);


    if(!music_is_playing)
    {
        PlayMusicStream(Starting_Menu_Music);
        music_is_playing = true;
    }

    //drawing the background and buttons
    BeginDrawing();
    DrawTexture(background,0,0,WHITE);
    DrawTexture(Button,40,280,GRAY);
    DrawTexture(Button,40,420,GRAY);
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
                PlaySound(transition_sound);
                Is_transitin_sound_started = true;
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
        else
        {
            Is_Cursor_Inside_botton = false;
        }
    }

    //this else if is used for reseting cursor and button relation status
    //with out this the sound effect won't play correctly
    else if (!Begin_Fading)
    {
        Is_Cursor_Inside_botton = false;
    }
    //this is the transition part between the screens
    else
    {
        //this is to transition from start menu to character select screen
        DrawRectangle(0,0,GetScreenWidth(),GetScreenHeight(),Fade(BLACK,fade/255));
        fade += 4;
        if(fade >= 255)
        {
            fade = 255;
        }
        if(Is_transitin_sound_started)
        {
            if(!IsSoundPlaying(transition_sound))
            {
                Is_transition_sound_finished = true;
            }
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
        else if(Should_Start_Game && fade >= 255 && Is_transition_sound_finished)
        {
            current_screen = CHARACTER_SELECT_SCREEN;
        }
        //to empty RAM resources
        if(current_screen != MENU_SCREEN)
        {   
            UnloadMusicStream(Starting_Menu_Music);
            UnloadTexture(background);
            UnloadTexture(Button);
            UnloadTexture(Sign);
            UnloadSound(swordsfx);
        }
    }


}

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
            Character_Select_Screen();
            return true;

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
    static Sound transition_sound = LoadSound("game_assets/starting_menu_assets/transition_sound.mp3");
    static Texture2D background = LoadTexture("game_assets/starting_menu_assets/starting_menu_background.jpg");
    static Texture2D Button = LoadTexture("game_assets/starting_menu_assets/button.jpg");
    static Texture2D Sign = LoadTexture("game_assets/starting_menu_assets/sign.png");
    static Sound swordsfx = LoadSound("game_assets/starting_menu_assets/swordsfx.mp3");
    
    static bool Is_Cursor_Inside_botton = false;
    static float fade = 0;
    static bool Begin_Fading = false;
    static bool Should_Exit = false;
    static bool Should_Start_Game = false;
    static bool Is_transitin_sound_started = false;
    static bool Is_transition_sound_finished = false;
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
    // ClearBackground(BLACK);
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

void Game::Character_Select_Screen()
{
    //init assets
    //music and background pic
    struct Texture_with_bound 
    {
        Texture2D texture;
        Rectangle bound;
        
    };
    
    static Music background_music = LoadMusicStream("game_assets/character_select_screen_asset/ch-select-music.mp3");
    static Texture2D background_img = LoadTexture("game_assets/character_select_screen_asset/character-select-background.png");
    //hero card assets
    static Texture_with_bound T_Little_card = {.texture = LoadTexture("game_assets/character_select_screen_asset/Tkochaiccart.jpg"), .bound{100,430,100,149}};
    static Texture_with_bound T_Big_card = {.texture = LoadTexture("game_assets/character_select_screen_asset/Tbozorgcard.jpg"), .bound{214,430,100,149}};
    static Texture_with_bound Dani_card = {.texture = LoadTexture("game_assets/character_select_screen_asset/danicard.jpg"), .bound{328,430,100,149}};
    static Texture_with_bound White_Doctor_card = {.texture = LoadTexture("game_assets/character_select_screen_asset/whitecard.jpg"), .bound{442,430,100,149}};
    static Texture_with_bound Shahriar_card = {.texture = LoadTexture("game_assets/character_select_screen_asset/shahriarcard.jpg"), .bound{556,430,100,149}};
    static Texture_with_bound Amin_card = {.texture = LoadTexture("game_assets/character_select_screen_asset/amincard.jpg"), .bound{670,430,100,149}};
    static Texture_with_bound Pouya_card = {.texture = LoadTexture("game_assets/character_select_screen_asset/pouyacard.jpg"), .bound{784,430,100,149}};
    
    
    //music control variables
    static bool Is_music_playing = false;
    //fade transition variables
    static bool Is_fading_in = true;
    static float fade = 255;
    

   

    //playing music
    if(!Is_music_playing)
    {
        PlayMusicStream(background_music);
        Is_music_playing = true;
    }
    UpdateMusicStream(background_music);

    //i will use this struct to check if mouse i hovering over any card or button 
    Vector2 Mouse_position = GetMousePosition();
    //the drawing part
    BeginDrawing();
    DrawTexture(background_img,0,0,WHITE);
    DrawTexture(Dani_card.texture,Dani_card.bound.x,Dani_card.bound.y,GRAY);
    DrawTexture(T_Big_card.texture,T_Big_card.bound.x,T_Big_card.bound.y,GRAY);
    DrawTexture(T_Little_card.texture,T_Little_card.bound.x,T_Little_card.bound.y,GRAY);
    DrawTexture(Amin_card.texture,Amin_card.bound.x,Amin_card.bound.y,GRAY);
    DrawTexture(White_Doctor_card.texture,White_Doctor_card.bound.x,White_Doctor_card.bound.y,GRAY);
    DrawTexture(Pouya_card.texture,Pouya_card.bound.x,Pouya_card.bound.y,GRAY);
    DrawTexture(Shahriar_card.texture,Shahriar_card.bound.x,Shahriar_card.bound.y,GRAY);

    //---------------this part is for mouse hovering over cards----------------------------
    //checking mouse hover over dani
    if(CheckCollisionPointRec(Mouse_position, Dani_card.bound))
    {
        //highlight the card
        DrawTexture(Dani_card.texture,Dani_card.bound.x,Dani_card.bound.y,WHITE);

    }

    //checking mouse hover over T big
    if(CheckCollisionPointRec(Mouse_position,T_Big_card.bound))
    {
        //highlight the card
        DrawTexture(T_Big_card.texture,T_Big_card.bound.x,T_Big_card.bound.y,WHITE);
    }

    //checking mouse hover over T little
    if(CheckCollisionPointRec(Mouse_position,T_Little_card.bound))
    {
        //highlight the card
        DrawTexture(T_Little_card.texture,T_Little_card.bound.x,T_Little_card.bound.y,WHITE);
    }

    //checking mouse hover over white doc
    if(CheckCollisionPointRec(Mouse_position,White_Doctor_card.bound))
    {
        //highlight the card
        DrawTexture(White_Doctor_card.texture,White_Doctor_card.bound.x,White_Doctor_card.bound.y,WHITE);
    }

    //checking mouse hover over shahriar
    if(CheckCollisionPointRec(Mouse_position,Shahriar_card.bound))
    {
        //highlight the card
        DrawTexture(Shahriar_card.texture,Shahriar_card.bound.x,Shahriar_card.bound.y,WHITE);
    }

    //checking mouse hover over pouya
    if(CheckCollisionPointRec(Mouse_position,Pouya_card.bound))
    {
        //highlight the card
        DrawTexture(Pouya_card.texture,Pouya_card.bound.x,Pouya_card.bound.y,WHITE);
    }

    //checking mouse hover over amin
    if(CheckCollisionPointRec(Mouse_position,Amin_card.bound))
    {
        //highlight the card
        DrawTexture(Amin_card.texture,Amin_card.bound.x,Amin_card.bound.y,WHITE);
    }
    // -----------------------------------------------------------------------------------
    
    if(Is_fading_in)
    {
        DrawRectangle(0,0,GetScreenWidth(),GetScreenHeight(),Fade(BLACK,fade/255));
        fade -= 3;
        //test to be deleted
        std::cout << "fading in and fade amount is " << fade << std::endl;
        if(fade <= 0)
        {
            fade = 0;
            Is_fading_in = false;
        }
    }


    EndDrawing();

    
}
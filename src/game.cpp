#include "../headers/game.hpp"
#include "../raylib/include/raylib.h"
#include "../headers/hero_abstract_base_class.hpp"
#include "../headers/hero_sub_class_to_instatniate_objects.hpp"
#include "../headers/user.hpp"
#include "../headers/controller.hpp"
#include <iostream>
#include <array>



void string_to_char_array(std::string st, char out[])//string should not have more than 25 characters
{
    if(st.empty())
    {
        out[0] = '\0';
    }
    int i;
    for(i = 0 ; st[i] != '\0'  && i < 25; i++)
    {
        out[i] = st[i];
    }
    out[i] = '\0';
}

void Get_keyboard_Input_And_Add_To_The_String_Passed_By_Refrence(std::string & st)
{
    int key = GetKeyPressed();
    //this switch has 28 case 26 for alphabetic characters, one for backspace, and one for space
    //reads key from kEyboard input and adds it to the string
    //only upercase
    switch (key)
    {
    case KEY_A:
        st += "A";
        break;
    case KEY_B:
        st += "B";
        break;
    case KEY_C:
        st += "C";
        break;
    case KEY_D:
        st += "D";
        break;
    case KEY_E:
        st += "E";
        break;
    case KEY_F:
        st += "F";
        break;
    case KEY_G:
        st += "G";
        break;
    case KEY_H:
        st += "H";
        break;
    case KEY_I:
        st += "I";
        break;
    case KEY_J:
        st += "J";
        break;
    case KEY_K:
        st += "K";
        break;
    case KEY_L:
        st += "L";
        break;
    case KEY_M:
        st += "M";
        break;
    case KEY_N:
        st += "N";
        break;
    case KEY_O:
        st += "O";
        break;
    case KEY_P:
        st += "P";
        break;
    case KEY_Q:
        st += "Q";
        break;
    case KEY_R:
        st += "R";
        break;
    case KEY_S:
        st += "S";
        break;
    case KEY_T:
        st += "T";
        break;
    case KEY_U:
        st += "U";
        break;
    case KEY_V:
        st += "V";
        break;
    case KEY_W:
        st += "W";
        break;
    case KEY_X:
        st += "X";
        break;
    case KEY_Y:
        st += "Y";
        break;
    case KEY_Z:
        st += "Z";
        break;
    case KEY_BACKSPACE:
        if(!st.empty())
            st.pop_back();
        break;
    case KEY_SPACE:
        st += " ";
        break;
    }
}
struct Texture_with_bound 
{
    Texture2D texture;
    Rectangle bound;
    
};

bool Is_name_string_more_then_25_characters(const std::string st)
{
    if(st.length() >= 25)
    {
        return true;
    }
    return false;
}

void show_name_character_limit_error_message_on_screen(Font out_font)
{
    Vector2 Text_size = MeasureTextEx(out_font, "Name can't be more than 25 characters long!", 18, 0);
    DrawTextEx(out_font,"Name can't be more than 25 characters long!",{(500 - (Text_size.x / 2)), 360}, 18, 0,RED);
}

int Change_temperory_hero_selected(int hero , int current)
{
    if(IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
    {
        return hero;
    }
    return current;

}

bool Based_On_The_Chosen_Cards_Should_This_Card_Be_Highlighted(const std::array<bool,8>& user1_hero_tracker_array,const std::array <bool,8>& user2_hero_tracker_array , int user_turn, int hero_card_which_is_to_be_selected)
{
    if(hero_card_which_is_to_be_selected == NONSELECT)
        return true;


    switch (user_turn)
    {
    case USER1:
        return !user1_hero_tracker_array[hero_card_which_is_to_be_selected ];
        break;
    
    case USER2:
        return !user2_hero_tracker_array[hero_card_which_is_to_be_selected ];
        break;
    }
}

Game::Game() : current_screen(CHARACTER_SELECT_SCREEN)
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

void Game::Character_Select_Screen()
{
    enum stage{DELAY_BEFORE_GETTING_INPUT, GET_USER_INPUT_NAME, GET_USER_INPUT_CHARACTERS , TRANSITION_TO_THE_GAME};
    //init assets
    //music and background pic
    static Music background_music = LoadMusicStream("game_assets/character_select_screen_asset/ch-select-music.mp3");
    static Texture2D background_img = LoadTexture("game_assets/character_select_screen_asset/character-select-background.png");

    //adding font
    static Font font = LoadFont("game_assets/character_select_screen_asset/bahnschrift.ttf"); 


    //hero card assets
    static Texture_with_bound T_Little_card = {.texture = LoadTexture("game_assets/character_select_screen_asset/Tkochaiccart.jpg"), .bound{50,430,100,149}};
    static Texture_with_bound T_Big_card = {.texture = LoadTexture("game_assets/character_select_screen_asset/Tbozorgcard.jpg"), .bound{164,430,100,149}};
    static Texture_with_bound Dani_card = {.texture = LoadTexture("game_assets/character_select_screen_asset/danicard.jpg"), .bound{278,430,100,149}};
    static Texture_with_bound White_Doctor_card = {.texture = LoadTexture("game_assets/character_select_screen_asset/whitecard.jpg"), .bound{392,430,100,149}};
    static Texture_with_bound Shahriar_card = {.texture = LoadTexture("game_assets/character_select_screen_asset/shahriarcard.jpg"), .bound{506,430,100,149}};
    static Texture_with_bound Amin_card = {.texture = LoadTexture("game_assets/character_select_screen_asset/amincard.jpg"), .bound{620,430,100,149}};
    static Texture_with_bound Pouya_card = {.texture = LoadTexture("game_assets/character_select_screen_asset/pouyacard.jpg"), .bound{734,430,100,149}};
    
    //hero deck selection buttons
    static Texture_with_bound Choose_button = {.texture{LoadTexture("game_assets/character_select_screen_asset/choose-button.jpg")}, .bound{855,410,83,85}};
    static Texture_with_bound Reset_Deck_button = {.texture{LoadTexture("game_assets/character_select_screen_asset/reset-button.jpg")}, .bound{855,500,85,85}};
    static Texture_with_bound Confirm_button = {.texture{LoadTexture("game_assets/character_select_screen_asset/confirm-button.jpg")}, .bound{855,430,82,85}};

    //user input form assets
    static Texture2D User1_form_inactive = LoadTexture("game_assets/character_select_screen_asset/user1inputbox-notselected.jpg");
    static Texture2D User1_form_active = LoadTexture("game_assets/character_select_screen_asset/user1inputbox-selected.jpg");
    static Texture2D User2_form_inactive = LoadTexture("game_assets/character_select_screen_asset/user2inputbox-notselected.jpg");
    static Texture2D User2_form_active = LoadTexture("game_assets/character_select_screen_asset/user2inputbox-selected.jpg");
    
    //music control variables
    static bool Is_music_playing = false;
    //fade transition variables
    static bool Is_fading_in = true;
    static float fade = 255;
    
    //screen management variables
    static bool User_Can_Use_Controlls = false;
    static bool User_Hover_Should_Highlight_Ui_Elemets = false;
    static int screen_stage = DELAY_BEFORE_GETTING_INPUT;
    static Rectangle name_inputbox_boarder = {350,276,365,74};
    static Rectangle name_input_form_confirm_button_boarder = {382, 427, 240, 98};
    
    //few variables to help with the logic
    static float timer = 0;
    static bool timer_should_Be_active = true;
    static bool Is_Name_Input_box_Active = false;
    static int User_Turn = USER1; // to know whos turn it is
    static int temp_hero_being_selected = NONSELECT; // this is to know which hero the hero wants to select
    static bool fading_out = false;
    static std::array <bool,8> user1_chosen_heros = {};
    static std::array <bool,8> user2_chosen_heros = {};
    
    //playing music
    if(!Is_music_playing)
    {
        PlayMusicStream(background_music);
        Is_music_playing = true;
    }
    UpdateMusicStream(background_music);

    //i will use this struct to check if mouse i hovering over any card or button 
    Vector2 Mouse_position = GetMousePosition();
    

    //drawwing the background and cards and buttons
    BeginDrawing();
    DrawTexture(background_img,0,0,WHITE);
    DrawTexture(Dani_card.texture,Dani_card.bound.x,Dani_card.bound.y,GRAY);
    DrawTexture(T_Big_card.texture,T_Big_card.bound.x,T_Big_card.bound.y,GRAY);
    DrawTexture(T_Little_card.texture,T_Little_card.bound.x,T_Little_card.bound.y,GRAY);
    DrawTexture(Amin_card.texture,Amin_card.bound.x,Amin_card.bound.y,GRAY);
    DrawTexture(White_Doctor_card.texture,White_Doctor_card.bound.x,White_Doctor_card.bound.y,GRAY);
    DrawTexture(Pouya_card.texture,Pouya_card.bound.x,Pouya_card.bound.y,GRAY);
    DrawTexture(Shahriar_card.texture,Shahriar_card.bound.x,Shahriar_card.bound.y,GRAY);
    DrawTexture(Choose_button.texture,Choose_button.bound.x,Choose_button.bound.y,GRAY);
    DrawTexture(Reset_Deck_button.texture, Reset_Deck_button.bound.x, Reset_Deck_button.bound.y, GRAY);

    //---------------this part is for mouse hovering over cards and selecting heros ----------------------------
    //checking mouse hover over dani
    if(CheckCollisionPointRec(Mouse_position, Dani_card.bound))
    {
        //highlight the card
        if(User_Hover_Should_Highlight_Ui_Elemets && Based_On_The_Chosen_Cards_Should_This_Card_Be_Highlighted(user1_chosen_heros, user2_chosen_heros,User_Turn,DANI_GOLANG))
        {
            DrawTexture(Dani_card.texture,Dani_card.bound.x,Dani_card.bound.y,WHITE);
            //if user click on the hero we will store the hero in the temp hero variable
            temp_hero_being_selected = Change_temperory_hero_selected(DANI_GOLANG , temp_hero_being_selected);
        }

    }

    //checking mouse hover over T big
    if(CheckCollisionPointRec(Mouse_position,T_Big_card.bound))
    {
        //highlight the card
        if(User_Hover_Should_Highlight_Ui_Elemets && Based_On_The_Chosen_Cards_Should_This_Card_Be_Highlighted(user1_chosen_heros, user2_chosen_heros,User_Turn,TAHA_BOZORGE))
        {
            DrawTexture(T_Big_card.texture,T_Big_card.bound.x,T_Big_card.bound.y,WHITE);
            temp_hero_being_selected = Change_temperory_hero_selected(TAHA_BOZORGE, temp_hero_being_selected);
        }
    }

    //checking mouse hover over T little
    if(CheckCollisionPointRec(Mouse_position,T_Little_card.bound))
    {
        //highlight the card
        if(User_Hover_Should_Highlight_Ui_Elemets && Based_On_The_Chosen_Cards_Should_This_Card_Be_Highlighted(user1_chosen_heros, user2_chosen_heros,User_Turn,TAHA_KOCHIKE))
        {
            DrawTexture(T_Little_card.texture,T_Little_card.bound.x,T_Little_card.bound.y,WHITE);
            temp_hero_being_selected = Change_temperory_hero_selected(TAHA_KOCHIKE, temp_hero_being_selected);
        }

    }

    //checking mouse hover over white doc
    if(CheckCollisionPointRec(Mouse_position,White_Doctor_card.bound))
    {
        //highlight the card
        if(User_Hover_Should_Highlight_Ui_Elemets && Based_On_The_Chosen_Cards_Should_This_Card_Be_Highlighted(user1_chosen_heros, user2_chosen_heros,User_Turn,WHITEDOCTOR))
        {
            DrawTexture(White_Doctor_card.texture,White_Doctor_card.bound.x,White_Doctor_card.bound.y,WHITE);
            temp_hero_being_selected = Change_temperory_hero_selected(WHITEDOCTOR, temp_hero_being_selected);
        }
    }

    //checking mouse hover over shahriar
    if(CheckCollisionPointRec(Mouse_position,Shahriar_card.bound))
    {
        //highlight the card
        if(User_Hover_Should_Highlight_Ui_Elemets && Based_On_The_Chosen_Cards_Should_This_Card_Be_Highlighted(user1_chosen_heros, user2_chosen_heros,User_Turn,AGHA_SHAHRIAR))
        {
            DrawTexture(Shahriar_card.texture,Shahriar_card.bound.x,Shahriar_card.bound.y,WHITE);
            temp_hero_being_selected = Change_temperory_hero_selected(AGHA_SHAHRIAR, temp_hero_being_selected);
        }
    }

    //checking mouse hover over pouya
    if(CheckCollisionPointRec(Mouse_position,Pouya_card.bound))
    {
        //highlight the card
        if(User_Hover_Should_Highlight_Ui_Elemets && Based_On_The_Chosen_Cards_Should_This_Card_Be_Highlighted(user1_chosen_heros, user2_chosen_heros,User_Turn,POUYA_KAJDOM))
        {
            DrawTexture(Pouya_card.texture,Pouya_card.bound.x,Pouya_card.bound.y,WHITE);
            temp_hero_being_selected = Change_temperory_hero_selected(POUYA_KAJDOM, temp_hero_being_selected);
        }
    }

    //checking mouse hover over amin
    if(CheckCollisionPointRec(Mouse_position,Amin_card.bound))
    {
        //highlight the card
        if(User_Hover_Should_Highlight_Ui_Elemets && Based_On_The_Chosen_Cards_Should_This_Card_Be_Highlighted(user1_chosen_heros, user2_chosen_heros,User_Turn,AMIN_EMENI))
        {
            DrawTexture(Amin_card.texture,Amin_card.bound.x,Amin_card.bound.y,WHITE);
            temp_hero_being_selected = Change_temperory_hero_selected(AMIN_EMENI, temp_hero_being_selected);
        }
    }
    // -----------------------------------------------------------------------------------
    //------------------mouse hovering over buttons reset and choose buttons management ---------
    //choose button 
    if(CheckCollisionPointRec(Mouse_position, Choose_button.bound))
    {
        //highlight button
        if(User_Hover_Should_Highlight_Ui_Elemets && temp_hero_being_selected != NONSELECT)
        {
            DrawTexture(Choose_button.texture,Choose_button.bound.x,Choose_button.bound.y,WHITE); 
            //if user clicked on the button it will update user array   
            if(IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
            {
                switch (User_Turn)
                {
                    case USER1:
                        //just add the selected hero to the user object array and user hero tracker array
                        user1.add_hero_to_hero_array(temp_hero_being_selected);
                        user1_chosen_heros[temp_hero_being_selected] = true;
                        temp_hero_being_selected = NONSELECT;
                        break;
                    
                    case USER2:
                        user2.add_hero_to_hero_array(temp_hero_being_selected);
                        user2_chosen_heros[temp_hero_being_selected] = true;
                        temp_hero_being_selected = NONSELECT;
                        break;
                }
            }
        }
        
    }

    //reset button
    if(CheckCollisionPointRec(Mouse_position,Reset_Deck_button.bound))
    {
        //highlight text
        if(User_Hover_Should_Highlight_Ui_Elemets)
            DrawTexture(Reset_Deck_button.texture, Reset_Deck_button.bound.x, Reset_Deck_button.bound.y, WHITE);
        
        //this resets the users array so the characters wont be shown on the screen
        if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
        {
            temp_hero_being_selected = NONSELECT;
            switch (User_Turn)
            {
            case USER1 :
                user1_chosen_heros.fill(0);
                control.Empty_User_Array(user1);
                break;
            
            case USER2:
                user2_chosen_heros.fill(0);
                control.Empty_User_Array(user2);
                break;
            }
        }
    }

    //-------------------------------------------------------------------------------------------------------------
    //this is for the transition when we change screen
    //from menu to character select and only is used once
    if(Is_fading_in)
    {
        DrawRectangle(0,0,GetScreenWidth(),GetScreenHeight(),Fade(BLACK,fade/255));
        fade -= 3;
        if(fade <= 0)
        {
            fade = 0;
            Is_fading_in = false;
        }
    }

    //we use this to put delay between input boxes poping up
    //once used for user1 and once for user2



    if(timer < 2)
    {
        //this timer roughly takes 3 seconds to reach value 2
        // it should take longer for user one
        if(User_Turn == USER1)
        {
            timer += (2.0/90.0);
        }
        else
        {
            timer += (2.0/45.0);
        }     
    }
    else if (timer_should_Be_active)
    {
        if(User_Turn == 3)
        {
            fade = 0;
            fading_out = true;
            screen_stage = TRANSITION_TO_THE_GAME;
            timer_should_Be_active = false;
        }
        else
        {
            screen_stage = GET_USER_INPUT_NAME;
            User_Hover_Should_Highlight_Ui_Elemets = false;
            timer_should_Be_active = false;
        }
    }
    
    //this switch is to help tidy up the code and to avoid rewriting code
    //this is related to the input box poping up and then
    //asking the user to choose characters
    switch (screen_stage)
    {
        case GET_USER_INPUT_NAME:
            //we fade the background using this draw function
            DrawRectangle(0,0,GetScreenWidth(), GetScreenHeight(), Fade(BLACK,0.7));
            
            
            //to know if user has clicked on the input box
            if(CheckCollisionPointRec(Mouse_position,name_inputbox_boarder))
            {
                if(IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
                {
                    Is_Name_Input_box_Active = true;
                }
            }

            if(!Is_Name_Input_box_Active)
            {
                if(User_Turn == USER1)
                    {DrawTexture(User1_form_inactive,300,0,WHITE);}
                else if(User_Turn == USER2)
                    {DrawTexture(User2_form_inactive,300,0,WHITE);}
                DrawRectangleRounded(name_input_form_confirm_button_boarder,0.5,10,Fade(BLACK,0.5));
                
            }
            //we have to read input from keyboard
            else
            {

                //to know which user is inputing
                if(User_Turn == USER1)
                {
                    DrawTexture(User1_form_active,300,0,WHITE);
                }
                else if(User_Turn == USER2)
                {
                    DrawTexture(User2_form_active,300,0,WHITE);
                }

                //to darken confirm button so we can lighten it again
                //when user hovers the mouse on it
                if(!CheckCollisionPointRec(Mouse_position,name_input_form_confirm_button_boarder))
                {
                    DrawRectangleRounded(name_input_form_confirm_button_boarder,0.5,10,Fade(BLACK,0.5));
                }   

                //this string gets the user input
                static std::string User_Input_Name = "";

                //making sure user enters no more than 25 characters
                if(Is_name_string_more_then_25_characters(User_Input_Name))
                {
                    show_name_character_limit_error_message_on_screen(font);
                    if(IsKeyPressed(KEY_BACKSPACE))
                    {
                        User_Input_Name.pop_back();
                    }
                }
                else
                {
                    Get_keyboard_Input_And_Add_To_The_String_Passed_By_Refrence(User_Input_Name);
                }

                // we store the string value inside this char array
                static char name[26];
                string_to_char_array(User_Input_Name, name);

                //this vector2 helps with center aligning the txt
                Vector2 name_text_size = MeasureTextEx(font, name, 18, 0);
                DrawTextEx(font,name,{(500 - (name_text_size.x / 2)), 300}, 18, 0, WHITE);

                //we check to see if the user wants to confirm the input name

                if(CheckCollisionPointRec(Mouse_position,name_input_form_confirm_button_boarder) || IsKeyPressed(KEY_ENTER))
                {
                    //this means user is hovering over the button
                    //now we check to see if user has clicked
                    if((IsMouseButtonPressed(MOUSE_LEFT_BUTTON) || IsKeyPressed(KEY_ENTER)) && !User_Input_Name.empty())
                    {
                        //user has confirmed the input so 
                        // we close the pop up input box
                        screen_stage = GET_USER_INPUT_CHARACTERS;
                        User_Hover_Should_Highlight_Ui_Elemets = true;

                        //save the name into the corresponding user object
                        if(User_Turn == USER1)
                        {
                            // we set the name inside the object that is the game class
                            // attribute
                            user1.Set_Name(User_Input_Name);
                        }
                        else if(User_Turn == USER2)
                        {
                            user2.Set_Name(User_Input_Name);
                        }

                        
                        // we reset the variables so that the next user can use them
                        User_Input_Name.erase();
                        Is_Name_Input_box_Active = false;
                    }
                }
            }
            break;
        
        case GET_USER_INPUT_CHARACTERS:
            

            break;

        case TRANSITION_TO_THE_GAME:
            DrawRectangle(0,0,GetScreenWidth(), GetScreenHeight(),Fade(BLACK,fade/255));
            fade += 4;
            if(fade >= 255)
            {
                fade = 255;
                
            }
            break;

    }
    
    
    
    //if this condition is true it means the user has clicked on a card
    //and we have to highligh the card
    if(!temp_hero_being_selected == NONSELECT)
    {
        switch (temp_hero_being_selected)
        {
            case DANI_GOLANG:
                DrawTexture(Dani_card.texture,Dani_card.bound.x,Dani_card.bound.y,WHITE);
                break;
            
            case AMIN_EMENI:
                DrawTexture(Amin_card.texture,Amin_card.bound.x,Amin_card.bound.y,WHITE);
                break;
            
            case AGHA_SHAHRIAR:
                DrawTexture(Shahriar_card.texture,Shahriar_card.bound.x,Shahriar_card.bound.y,WHITE);
                break;
            
            case POUYA_KAJDOM:
                DrawTexture(Pouya_card.texture,Pouya_card.bound.x,Pouya_card.bound.y,WHITE);
                break;
            
            case TAHA_KOCHIKE:
                DrawTexture(T_Little_card.texture,T_Little_card.bound.x,T_Little_card.bound.y,WHITE);
                break;
            
            case TAHA_BOZORGE:
                DrawTexture(T_Big_card.texture,T_Big_card.bound.x,T_Big_card.bound.y,WHITE);
                break;
            
            case WHITEDOCTOR:
                DrawTexture(White_Doctor_card.texture,White_Doctor_card.bound.x,White_Doctor_card.bound.y,WHITE);
                break;
            
        }
    }
    
    // std::cout << "user one hero tracker array: \n";
    // for(int i = 0 ; i < 7 ; i++)
    // {
    //     std::cout << user1_chosen_heros[i] << "  ";
    // }

    EndDrawing();

    //this part checks to see if hero arrays for user objects are full or not
    //and if they are full it will manage the logic
    switch (User_Turn)
    {
    case USER1:
        if(control.Is_Hero_Array_Full(user1))
        {
            //user has chosen all tree cards and now we reset the variable
            //to get the other user hero cards as well
            User_Turn = USER2;
            timer = 0;
            timer_should_Be_active = true;
            screen_stage = DELAY_BEFORE_GETTING_INPUT;
            temp_hero_being_selected = NONSELECT;
            User_Hover_Should_Highlight_Ui_Elemets = false;
        }
        break;
    
    case USER2:
        if(control.Is_Hero_Array_Full(user2))
        {
            //disable all user controll
            User_Hover_Should_Highlight_Ui_Elemets = false;
            User_Turn = 3; // to avoid coming into this switch
            timer = 0;
            timer_should_Be_active = true;
            fade = 0;

        }
        break;
    }
    std::cout << "screen stage : " << screen_stage << std::endl;
}
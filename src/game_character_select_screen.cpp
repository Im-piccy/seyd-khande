#include "../headers/game.hpp"
#include "../raylib/include/raylib.h"
#include "../headers/include_in_character_select_screen_file.hpp"
#include "../headers/enums.hpp"

void Game::Character_Select_Screen()
{
    enum stage{DELAY_BEFORE_GETTING_INPUT, GET_USER_INPUT_NAME, GET_USER_INPUT_CHARACTERS , TRANSITION_TO_THE_GAME};
    //init assets
    //music and background pic
    static Music background_music = LoadMusicStream("game_assets/character_select_screen_asset/ch-select-music.mp3");
    static Texture2D background_img = LoadTexture("game_assets/character_select_screen_asset/character-select-background.png");
    static Sound Card_sfx = LoadSound("game_assets/character_select_screen_asset/confirm_button_sfx.mp3");
    static Sound Confirm_sfx = LoadSound("game_assets/character_select_screen_asset/deck_selection_complete_sfx.mp3");
    static Sound Deck_Complete_sfx = LoadSound("game_assets/character_select_screen_asset/hover_over_cards_sfx.mp3");
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
    static int index_for_hero_array = 0;
    
    //keeping track of user inputs
    static std::array <bool,8> user1_chosen_heros = {};
    static std::array <bool,8> user2_chosen_heros = {};
    static char user1_name[26];
    static char user2_name[26];
    static char name[26]; 
    static std::array <int ,3> user1_hero_array;
    static std::array <int ,3> user2_hero_array;
    
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
    else if(CheckCollisionPointRec(Mouse_position,T_Big_card.bound))
    {
        //highlight the card
        if(User_Hover_Should_Highlight_Ui_Elemets && Based_On_The_Chosen_Cards_Should_This_Card_Be_Highlighted(user1_chosen_heros, user2_chosen_heros,User_Turn,TAHA_BOZORGE))
        {
            
            DrawTexture(T_Big_card.texture,T_Big_card.bound.x,T_Big_card.bound.y,WHITE);
            temp_hero_being_selected = Change_temperory_hero_selected(TAHA_BOZORGE, temp_hero_being_selected);
        }
    }

    //checking mouse hover over T little
    else if(CheckCollisionPointRec(Mouse_position,T_Little_card.bound))
    {
        //highlight the card
        if(User_Hover_Should_Highlight_Ui_Elemets && Based_On_The_Chosen_Cards_Should_This_Card_Be_Highlighted(user1_chosen_heros, user2_chosen_heros,User_Turn,TAHA_KOCHIKE))
        {
            
            DrawTexture(T_Little_card.texture,T_Little_card.bound.x,T_Little_card.bound.y,WHITE);
            temp_hero_being_selected = Change_temperory_hero_selected(TAHA_KOCHIKE, temp_hero_being_selected);
        }

    }

    //checking mouse hover over white doc
    else if(CheckCollisionPointRec(Mouse_position,White_Doctor_card.bound))
    {
        //highlight the card
        if(User_Hover_Should_Highlight_Ui_Elemets && Based_On_The_Chosen_Cards_Should_This_Card_Be_Highlighted(user1_chosen_heros, user2_chosen_heros,User_Turn,WHITEDOCTOR))
        {
            
            DrawTexture(White_Doctor_card.texture,White_Doctor_card.bound.x,White_Doctor_card.bound.y,WHITE);
            temp_hero_being_selected = Change_temperory_hero_selected(WHITEDOCTOR, temp_hero_being_selected);
        }
    }

    //checking mouse hover over shahriar
    else if(CheckCollisionPointRec(Mouse_position,Shahriar_card.bound))
    {
        //highlight the card
        if(User_Hover_Should_Highlight_Ui_Elemets && Based_On_The_Chosen_Cards_Should_This_Card_Be_Highlighted(user1_chosen_heros, user2_chosen_heros,User_Turn,AGHA_SHAHRIAR))
        {
            
            DrawTexture(Shahriar_card.texture,Shahriar_card.bound.x,Shahriar_card.bound.y,WHITE);
            temp_hero_being_selected = Change_temperory_hero_selected(AGHA_SHAHRIAR, temp_hero_being_selected);
        }
    }

    //checking mouse hover over pouya
    else if(CheckCollisionPointRec(Mouse_position,Pouya_card.bound))
    {
        //highlight the card
        if(User_Hover_Should_Highlight_Ui_Elemets && Based_On_The_Chosen_Cards_Should_This_Card_Be_Highlighted(user1_chosen_heros, user2_chosen_heros,User_Turn,POUYA_KAJDOM))
        {
            
            DrawTexture(Pouya_card.texture,Pouya_card.bound.x,Pouya_card.bound.y,WHITE);
            temp_hero_being_selected = Change_temperory_hero_selected(POUYA_KAJDOM, temp_hero_being_selected);
        }
    }

    //checking mouse hover over amin
    else if(CheckCollisionPointRec(Mouse_position,Amin_card.bound))
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
                PlaySound(Confirm_sfx);
                switch (User_Turn)
                {
                    case USER1:
                        //just add the selected hero to the user object array and user hero tracker array
                        control.Fill_Hero_object_Array(USER1,index_for_hero_array,temp_hero_being_selected);
                        index_for_hero_array++;
                        user1.add_hero_to_hero_array(temp_hero_being_selected);
                        user1_chosen_heros[temp_hero_being_selected] = true;
                        temp_hero_being_selected = NONSELECT;
                        if(index_for_hero_array == 3)
                        {
                            index_for_hero_array = 0;
                        }
                        break;
                    
                    case USER2:
                        control.Fill_Hero_object_Array(USER2, index_for_hero_array, temp_hero_being_selected);
                        index_for_hero_array++;
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
            PlaySound(Confirm_sfx);
            temp_hero_being_selected = NONSELECT;
            switch (User_Turn)
            {
            case USER1 :
                control.Empty_Array_Which_Stores_Hero_Base_Class_Pointers(USER1, index_for_hero_array);
                user1_chosen_heros.fill(0);
                control.Empty_User_Array(user1);
                break;
            
            case USER2:
                control.Empty_Array_Which_Stores_Hero_Base_Class_Pointers(USER2, index_for_hero_array);
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
    

    

    
    //if this condition is true it means the user has clicked on a card
    //and we have to highligh the card
    if(temp_hero_being_selected != NONSELECT)
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
    
   


    // printing heros and name on the screen
    
    Vector2 user1_name_size = MeasureTextEx(font, user1_name, 20, 0);
    Vector2 user2_name_size = MeasureTextEx(font, user2_name, 20, 0);
    
    //printing names 
    if(User_Turn == USER1)
    {
        DrawTextEx(font,user1_name,{120 - (user1_name_size.x / 2),20},20,0,WHITE);      
        DrawTextEx(font,user2_name,{880 - (user2_name_size.x / 2) , 20}, 20, 0, GRAY);
    }
    else if(User_Turn == USER2)
    {
        DrawTextEx(font,user1_name,{120 - (user1_name_size.x / 2),20},20,0,GRAY);      
        DrawTextEx(font,user2_name,{880 - (user2_name_size.x / 2) , 20}, 20, 0, WHITE);
    }
    else
    {
        DrawTextEx(font,user1_name,{120 - (user1_name_size.x / 2),20},20,0,GRAY);      
        DrawTextEx(font,user2_name,{880 - (user2_name_size.x / 2) , 20}, 20, 0, GRAY);
    }


    user1_hero_array = user1.Get_Hero_Array();
    user2_hero_array = user2.Get_Hero_Array();

    //print user 1 cards on screen
    for(int i = 0 ; i < 3 ; i++)
    {
        switch (i)
        {
            
        case 0:
        {
            if(user1_hero_array[i] == NONSELECT)
            {
                //this means we should break out of the loop and display nothin
                i = 4;
                break;
            }
            Texture2D to_be_displayed = Return_The_Corresponding_Texture_Based_On_User_Array(user1_hero_array, user2_hero_array,USER1,i);
            if(User_Turn == USER1)
            {
                DrawTexture(to_be_displayed,0,35,WHITE);
                
            }
            else
            {
                DrawTexture(to_be_displayed,0,35,GRAY);
            }
            
            break;
        }    
        case 1:
        {
            if(user1_hero_array[i] == NONSELECT)
            {
                //this means we should break out of the loop and display nothin
                i = 4;
                break;
            }
            Texture2D to_be_displayed = Return_The_Corresponding_Texture_Based_On_User_Array(user1_hero_array, user2_hero_array,USER1,i);
            if(User_Turn == USER1)
            {
                DrawTexture(to_be_displayed,0,135,WHITE);
                
            }
            else
            {
                DrawTexture(to_be_displayed,0,135,GRAY);
            }
            break;
        }    
        case 2:
        {
            if(user1_hero_array[i] == NONSELECT)
            {
                //this means we should break out of the loop and display nothin
                i = 4;
                break;
            }
            Texture2D to_be_displayed = Return_The_Corresponding_Texture_Based_On_User_Array(user1_hero_array, user2_hero_array,USER1,i);
            if(User_Turn == USER1)
            {
                DrawTexture(to_be_displayed,0,235,WHITE);
                
            }
            else
            {
                DrawTexture(to_be_displayed,0,235,GRAY);
            }
            break;
        }
        }
    }
    
    //print user 2 cards on screen
    for(int i = 0 ; i < 3 ; i++)
    {
        switch (i)
        {
        case 0:
        {
            if(user2_hero_array[i] == NONSELECT)
            {
                //this means we should break out of the loop and display nothin
                i = 4;
                break;
            }
            Texture2D to_be_displayed = Return_The_Corresponding_Texture_Based_On_User_Array(user1_hero_array, user2_hero_array,USER2,i);
            if(User_Turn == USER2)
            {
                
                DrawTexture(to_be_displayed,860,40,WHITE);
                
            }
            else
            {
                DrawTexture(to_be_displayed,860,40,GRAY);
            }
            
            break;
        }
        case 1:
        {
            if(user2_hero_array[i] == NONSELECT)
            {
                //this means we should break out of the loop and display nothin
                i = 4;
                break;
            }
            Texture2D to_be_displayed = Return_The_Corresponding_Texture_Based_On_User_Array(user1_hero_array, user2_hero_array,USER2,i);
            if(User_Turn == USER2)
            {
                DrawTexture(to_be_displayed,860,140,WHITE);
                
            }
            else
            {
                DrawTexture(to_be_displayed,860,140,GRAY);
            }
            break;
        }  
        case 2:
        {
            if(user2_hero_array[i] == NONSELECT)
            {
                //this means we should break out of the loop and display nothin
                i = 4;
                break;
            }
            Texture2D to_be_displayed = Return_The_Corresponding_Texture_Based_On_User_Array(user1_hero_array, user2_hero_array,USER2,i);
            if(User_Turn == USER1)
            {
                DrawTexture(to_be_displayed,860,250,WHITE);
                
            }
            else
            {
                DrawTexture(to_be_displayed,860,250,GRAY);
            }
            break;
        }
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
                
                string_to_char_array(User_Input_Name, name);

                //this vector2 helps with center aligning the txt
                Vector2 name_text_size = MeasureTextEx(font, name, 18, 0);
                DrawTextEx(font,name,{(500 - (name_text_size.x / 2)), 300}, 18, 0, WHITE);

                //we check to see if the user wants to confirm the input name

                if(CheckCollisionPointRec(Mouse_position,name_input_form_confirm_button_boarder) || IsKeyPressed(KEY_ENTER))
                {
                    //this means user is hovering over the button
                    //now we check to see if user has clicked
                    if(!IsSoundPlaying(Card_sfx))
                        PlaySound(Card_sfx);
                    if((IsMouseButtonPressed(MOUSE_LEFT_BUTTON) || IsKeyPressed(KEY_ENTER)) && !User_Input_Name.empty())
                    {
                        PlaySound(Confirm_sfx);
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
                            string_to_char_array(User_Input_Name, user1_name);
                        }
                        else if(User_Turn == USER2)
                        { 
                            user2.Set_Name(User_Input_Name);
                            string_to_char_array(User_Input_Name, user2_name);
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
                //stop eveything
                StopMusicStream(background_music);
                //unloading textures
                {
                    UnloadTexture(T_Little_card.texture);
                    UnloadTexture(T_Big_card.texture);
                    UnloadTexture(Dani_card.texture);
                    UnloadTexture(White_Doctor_card.texture);
                    UnloadTexture(Shahriar_card.texture);
                    UnloadTexture(Amin_card.texture);
                    UnloadTexture(Pouya_card.texture);
                    UnloadTexture(Choose_button.texture);
                    UnloadTexture(Reset_Deck_button.texture);
                    UnloadTexture(User1_form_active);
                    UnloadTexture(User1_form_inactive);
                    UnloadTexture(User2_form_active);
                    UnloadTexture(User2_form_inactive);
                    UnloadTexture(background_img);
                }
                //unloading; music and sound and font
                {
                    UnloadFont(font);
                    UnloadSound(Card_sfx);
                    UnloadSound(Confirm_sfx);
                    UnloadSound(Deck_Complete_sfx);
                    UnloadMusicStream(background_music);
                }
                current_screen = GAME_SCREEN;
                fade = 255;
                
            }
            SetMusicVolume(background_music, 1.0 - fade/255.0);
            break;
    }

    EndDrawing();

    //this part checks to see if hero arrays for user objects are full or not
    //and if they are full it will manage the logic
    switch (User_Turn)
    {
    case USER1:
        if(control.Is_Hero_Array_Full(user1))
        {
            PlaySound(Deck_Complete_sfx);
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
            PlaySound(Deck_Complete_sfx);
            //disable all user controll
            User_Hover_Should_Highlight_Ui_Elemets = false;
            User_Turn = 3; // to avoid coming into this switch
            timer = 0;
            timer_should_Be_active = true;
            fade = 0;

        }
        break;
    }
    
}

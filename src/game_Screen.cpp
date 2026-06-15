#include "../headers/game.hpp"
#include "../raylib/include/raylib.h"
#include "../headers/hero_abstract_base_class.hpp"
#include "../headers/hero_sub_class_to_instatniate_objects.hpp"
#include "../headers/user.hpp"
#include "../headers/controller.hpp"
#include "../headers/enums.hpp"
#include "../headers/include_in_game_screen_file.hpp"
#include <iostream>
#include <cmath>
#include <array>

void Game::Game_Screen()
{


    //music and sound and font
    static Music Background_music = LoadMusicStream("game_assets/game_screen_assets/game_background_music.mp3");
    static Font font = LoadFont("game_assets/character_select_screen_asset/bahnschrift.ttf"); 

    //background related textures
    static Texture2D Background_img = LoadTexture("game_assets/game_screen_assets/game_background.jpg");
    static Texture2D Control_panel = LoadTexture("game_assets/game_screen_assets/control-panel-hero-not-selected.png");
    static Texture2D Control_panle_hero_selected = LoadTexture("game_assets/game_screen_assets/control-panel-hero-selected.png");

    //button related textures
    static Texture2D attack_button_textrue = LoadTexture("game_assets/game_screen_assets/Attack.png");
    static Texture2D end_turn_texture = LoadTexture("game_assets/game_screen_assets/end-turn.png");

    
    //transition fade and music control variables
    static float fade = 255.0f;
    static bool is_fading_in = true;
    static bool is_music_playing = false;
    
    //abilities bounds
    static Rectangle Skill_1_bound = {315, 420, 75, 100};
    static Rectangle Skill_2_bound = {600, 420, 75, 100};
    static Rectangle superpower_bound = {450, 402, 135, 90};

    //abilities logic related variables
    static ABILITIES ability_to_be_highlighted = NON;
    static ABILITIES ability_to_stay_highlighted = NON;
    static bool should_ability_be_highlighted = false;
    static bool should_ability_stay_highlighted = false;
    static bool is_mouse_hovering_over_abilities = false;


    // these variables are going to be used for fliping the 
    //animation sprite for users
    static float doc_frame_width = 164;
    static float dani_frame_width = 136;
    static float amin_frame_width = 169;
    static float shahriar_frame_width = 160;
    static float pouya_frame_width = 134;
    static float tbig_frame_width = 135;
    static float tlittle_frame_width = 178;
    
    
    
    //animation and screen control
    static bool are_textures_loaded = false;
    static bool should_hero_be_animated = false;
    static bool Hero_should_be_highlighted = false;
    static int user1_hero_to_be_highlighted_index = 4;
    static int user2_hero_to_be_highlighted_index = 4;
    static int hero_to_be_animated_index = 4;
    static int enemy_to_be_highlighted = 4;
    static int enemy_to_stay_highlighted = 4;
    
    //end turn and attack button bounds
    Rectangle End_turn_button_bound = {900, 497, 82, 92};
    Rectangle Attack_button_bound = {818, 497, 82,92};
    
    
    //animation struct declarations
    //initialization goes like this -> {first frame, last frame, current frame, frame-width, frame-height, first-frame-x, first-frame-y, animation-speed, duration-left, initial-duration, {rectangle frame x, rectangle frame y, width , height}}
    static Animation Doc_anim_struct = {0, 4, 0, -doc_frame_width,  characters_sprite_sheets_frame_height, 0, 0, Animation_Speed,  Animation_Duration,  Animation_Duration,  {0, 0, doc_frame_width,  characters_sprite_sheets_frame_height}};
    static Animation Dani_anim_struct = {0, 4, 0, -dani_frame_width,  characters_sprite_sheets_frame_height, 0, 0, Animation_Speed,  Animation_Duration,  Animation_Duration,  {0, 0, dani_frame_width,  characters_sprite_sheets_frame_height}};
    static Animation Amin_anim_struct = {0, 4, 0, -amin_frame_width,  characters_sprite_sheets_frame_height, 0, 0, Animation_Speed,  Animation_Duration,  Animation_Duration,  {0, 0, amin_frame_width,  characters_sprite_sheets_frame_height}};
    static Animation Shahriar_anim_struct = {0, 4, 0, -shahriar_frame_width,  characters_sprite_sheets_frame_height, 0, 0, Animation_Speed,  Animation_Duration,  Animation_Duration,  {0, 0, shahriar_frame_width,  characters_sprite_sheets_frame_height}};
    static Animation Pouya_anim_struct = {0, 4, 0, -pouya_frame_width,  characters_sprite_sheets_frame_height, 0, 0, Animation_Speed,  Animation_Duration,  Animation_Duration,  {0, 0, pouya_frame_width,  characters_sprite_sheets_frame_height}};
    static Animation Tbig_anim_struct = {0, 4, 0, -tbig_frame_width,  characters_sprite_sheets_frame_height, 0, 0, Animation_Speed,  Animation_Duration,  Animation_Duration,  {0, 0, tbig_frame_width,  characters_sprite_sheets_frame_height}};
    static Animation Tlittle_anim_struct = {0, 4, 0, -tlittle_frame_width,  characters_sprite_sheets_frame_height, 0, 0, Animation_Speed,  Animation_Duration,  Animation_Duration,  {0, 0, tlittle_frame_width,  characters_sprite_sheets_frame_height}};
    std::array <Animation, 7> animation_structs_in_array {Doc_anim_struct, Tlittle_anim_struct,Dani_anim_struct,Amin_anim_struct,Tbig_anim_struct,Pouya_anim_struct,Shahriar_anim_struct};
    
    
    
    
    //variables for logic of the program
    static int User_Turn = USER1;
    static bool copied_user1_info = false;
    static bool copied_user2_info = false;
    static Vector2 Mouse_Positon;
    static Rectangle user1_hero1_bound = {202,104,120,102};
    static Rectangle user1_hero2_bound = {82,146,120,250};
    static Rectangle user1_hero3_bound = {202,206, 120, 250};
    static Rectangle user2_hero1_bound = {660,104,120,102};
    static Rectangle user2_hero2_bound = {773,136,120,250};
    static Rectangle user2_hero3_bound = {660,206,120,250};
    static bool is_mouse_hovering_over_enemy = false;
    static bool should_execute_ability = false;
    static bool should_end_turn = false;
    static bool should_enemy_be_highlighted = false;
    static bool should_enemy_stay_highlighted = false;
    static bool is_mouse_hovring_over_attack_or_endTurn_button = false;
    
    
    //user info
    static char user1_name[26];
    static char user2_name[26];
    static std::array <int, 3> user1_hero_arr;
    static std::array <int, 3> user2_hero_arr;
    static Vector2 User1_name_size;
    static Vector2 User2_name_size;
    static char user1_energy[5] = {};
    static char user2_energy[5] = {};
    static char current_round[5] = {};
    static std::array <Texture2D,3> user1_ability_texture_array;
    static std::array <Texture2D,3> user2_ability_texture_array;
    
    //loading game screen textures
    if(!are_textures_loaded)
    {
        load_game_screen_abilities_textures();
        load_game_screen_animation_sprite_sheets();
        are_textures_loaded = true;
    }
    
    
    //music control 
    if(!is_music_playing)
    {
        PlayMusicStream(Background_music);
        is_music_playing = true;
    }
    UpdateMusicStream(Background_music);
    
    
    //storing users info in this local scope
    //we use boolian variables to run this part just once
    if(!copied_user1_info)
    {
        copied_user1_info = true;
        string_to_char_array(user1.Get_Name_String(), user1_name);
        std::cout << "i think get name memeber function isnt working so this is what it returns : " << user1.Get_Name_String() << std::endl;
        std::cout << "if you see this i am coping user1 name into the variable \n this is the valuse in it : " << user1_name << std::endl;
        user1_hero_arr = user1.Get_Hero_Array();
        User1_name_size = MeasureTextEx(font, user1_name, 20, 0);
    }

    if(!copied_user2_info)
    {
        copied_user2_info = true;
        string_to_char_array(user2.Get_Name_String(), user2_name);
        user2_hero_arr = user2.Get_Hero_Array();
        User2_name_size = MeasureTextEx(font, user2_name, 20, 0);
    }

    string_to_char_array(std::to_string(user1.Get_Energy()), user1_energy);
    string_to_char_array(std::to_string(user2.Get_Energy()), user2_energy);
    string_to_char_array(std::to_string(control.return_round_number()), current_round);
    



    Mouse_Positon = GetMousePosition();
    
    //check to see if we are hovering over buttons or not
    if(CheckCollisionPointRec(Mouse_Positon, Attack_button_bound) && CheckCollisionPointRec(Mouse_Positon, End_turn_button_bound) && should_ability_stay_highlighted)
    {
        is_mouse_hovring_over_attack_or_endTurn_button = true;
    }
    else
    {
        is_mouse_hovring_over_attack_or_endTurn_button = false;
    }
    
    //check to see if mouse on the abilities position

    if(CheckCollisionPointRec(Mouse_Positon,Skill_1_bound) || CheckCollisionPointRec(Mouse_Positon,Skill_2_bound) || CheckCollisionPointRec(Mouse_Positon,superpower_bound))
    {
        is_mouse_hovering_over_abilities = true;
    }
    else
    {
        is_mouse_hovering_over_abilities = false;
    }

    //checking to see if mouse is hovering over enemy
    if(User_Turn == USER1)
    {
        if(CheckCollisionPointRec(Mouse_Positon, user2_hero1_bound) || CheckCollisionPointRec(Mouse_Positon, user2_hero2_bound) || CheckCollisionPointRec(Mouse_Positon, user2_hero3_bound))
        {
            is_mouse_hovering_over_enemy = true;
        }
        else
        {
            is_mouse_hovering_over_enemy = false;
        }
    }
    else if(User_Turn == USER2)
    {
        if(CheckCollisionPointRec(Mouse_Positon, user1_hero1_bound) || CheckCollisionPointRec(Mouse_Positon, user1_hero2_bound) || CheckCollisionPointRec(Mouse_Positon, user1_hero3_bound))
        {
            is_mouse_hovering_over_enemy = true;
        }
        else
        {
            is_mouse_hovering_over_enemy = false;
        }
    }



    //checking to see user is hovering over heros
    if(CheckCollisionPointRec(Mouse_Positon,user1_hero1_bound))
    {
        user1_hero_to_be_highlighted_index = 0;

        //checking to see if enemy should be highlighted
        if(User_Turn == USER2)
        {
            if(should_ability_stay_highlighted)
            {
                enemy_to_be_highlighted = 0;
            }
            //checking to see if the enemy should stay highlighted
            if(should_ability_stay_highlighted && IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
            {
                should_enemy_stay_highlighted = true;
                enemy_to_stay_highlighted = 0;
            }
        }


        if(User_Turn == USER1 && IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
        {
            hero_to_be_animated_index = 0;
        }
    }
    else if(CheckCollisionPointRec(Mouse_Positon, user1_hero2_bound))
    {

        
        //checking to see if enemy should be highlighted
        if(User_Turn == USER2)
        {
            if(should_ability_stay_highlighted)
            {
                enemy_to_be_highlighted = 1;
            }
            //checking to see if the enemy should stay highlighted
            if(should_ability_stay_highlighted && IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
            {
                should_enemy_stay_highlighted = true;
                enemy_to_stay_highlighted = 1;
            }
        }

        user1_hero_to_be_highlighted_index = 1;
        if(User_Turn == USER1 && IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
        {
            hero_to_be_animated_index = 1;
        }

    }
    else if(CheckCollisionPointRec(Mouse_Positon, user1_hero3_bound))
    {
        user1_hero_to_be_highlighted_index = 2;
        
        
        //checking to see if enemy should be highlighted
        if(User_Turn == USER2)
        {
            if(should_ability_stay_highlighted)
            {
                enemy_to_be_highlighted = 2;
            }
            //checking to see if the enemy should stay highlighted
            if(should_ability_stay_highlighted && IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
            {
                should_enemy_stay_highlighted = true;
                enemy_to_stay_highlighted = 2;
            }
        }


        if(User_Turn == USER1 && IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
        {
            hero_to_be_animated_index = 2;
        }

    }
    else if(CheckCollisionPointRec(Mouse_Positon, user2_hero1_bound))
    {
        user2_hero_to_be_highlighted_index = 0;
        
        
        //checking to see if enemy should be highlighted
        if(User_Turn == USER1)
        {
            //checking to see if enemy should be highlighted
            if(User_Turn == USER1)
            {
                if(should_ability_stay_highlighted)
                {
                    enemy_to_be_highlighted = 0;
                }
                //checking to see if the enemy should stay highlighted
                if(should_ability_stay_highlighted && IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
                {
                    should_enemy_stay_highlighted = true;
                    enemy_to_stay_highlighted = 0;
                }
            }
        }
     
        if(User_Turn == USER2 && IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
        {
            hero_to_be_animated_index = 0;
        }

    }
    else if(CheckCollisionPointRec(Mouse_Positon, user2_hero2_bound))
    {
        user2_hero_to_be_highlighted_index = 1;
        
        //checking to see if enemy should be highlighted
        if(User_Turn == USER1)
        {
            if(should_ability_stay_highlighted)
            {
                enemy_to_be_highlighted = 1;
            }
            //checking to see if the enemy should stay highlighted
            if(should_ability_stay_highlighted && IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
            {
                should_enemy_stay_highlighted = true;
                enemy_to_stay_highlighted = 1;
            }
        }
        
        if(User_Turn == USER2 && IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
        {
            hero_to_be_animated_index = 1;
        }

    }
    else if(CheckCollisionPointRec(Mouse_Positon, user2_hero3_bound))
    {
        user2_hero_to_be_highlighted_index = 2;
        
        //checking to see if enemy should be highlighted
        if(User_Turn == USER1)
        {
            if(should_ability_stay_highlighted)
            {
                enemy_to_be_highlighted = 2;
            }
            //checking to see if the enemy should stay highlighted
            if(should_ability_stay_highlighted && IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
            {
                should_enemy_stay_highlighted = true;
                enemy_to_stay_highlighted = 2;
            }
        }
        
        if(User_Turn == USER2 && IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
        {
            hero_to_be_animated_index = 2;
        }

    }
    else
    {
        Hero_should_be_highlighted = false;
        if(should_ability_stay_highlighted)
        {
            if((!is_mouse_hovering_over_enemy && !is_mouse_hovring_over_attack_or_endTurn_button) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
            {
                should_hero_be_animated = false;
                hero_to_be_animated_index = 4;

            }
        }
        else if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && !is_mouse_hovering_over_abilities )
        {

            should_hero_be_animated = false;
            hero_to_be_animated_index = 4;
        }
    }


    //turning off the highlighted ability if necessary
    if(!is_mouse_hovering_over_abilities && !is_mouse_hovering_over_enemy && !is_mouse_hovring_over_attack_or_endTurn_button)
    {
        if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
        {
            should_ability_stay_highlighted = false;
            ability_to_stay_highlighted = NON;
        }
    }

    if(should_hero_be_animated && should_ability_stay_highlighted)
    {
        should_enemy_be_highlighted = true;
    }

    //to see if the character should highlight or not
    //and see if the character should be animated or not
    if(CheckCollisionPointRec(Mouse_Positon,user1_hero1_bound) || CheckCollisionPointRec(Mouse_Positon,user1_hero2_bound) || CheckCollisionPointRec(Mouse_Positon,user1_hero3_bound))
    {
        if(IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && User_Turn == USER1)
        {
            should_hero_be_animated = true;
        }
        if(User_Turn == USER1)
        {
            Hero_should_be_highlighted = true;

        }

    }
    else if(CheckCollisionPointRec(Mouse_Positon,user2_hero1_bound) || CheckCollisionPointRec(Mouse_Positon,user2_hero2_bound) || CheckCollisionPointRec(Mouse_Positon,user2_hero3_bound))
    {
        if(User_Turn == USER2)
        {
            Hero_should_be_highlighted = true;
        }
        if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && User_Turn == USER2)
        {
            should_hero_be_animated = true;
        }
    }

//checking to see if user is hovering over abilities
    if(should_hero_be_animated)
    {
        if(CheckCollisionPointRec(Mouse_Positon, Skill_1_bound))
        {

            if(control.can_ability_be_used_based_on_energy_points(hero_to_be_animated_index,SKILL1,User_Turn,user1.Get_Energy(), user2.Get_Energy()))
            {
                ability_to_be_highlighted = SKILL1;
                should_ability_be_highlighted = true;
            }
            if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && ability_to_be_highlighted == SKILL1)
            {
                ability_to_stay_highlighted = SKILL1;
                should_ability_stay_highlighted = true;
            }
        }
        else if(CheckCollisionPointRec(Mouse_Positon, Skill_2_bound))
        {
            if(control.can_ability_be_used_based_on_energy_points(hero_to_be_animated_index,SKILL2,User_Turn,user1.Get_Energy(), user2.Get_Energy()))
            {
                should_ability_be_highlighted = true;
                ability_to_be_highlighted = SKILL2;
            }
            if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && ability_to_be_highlighted == SKILL2)
            {
                ability_to_stay_highlighted = SKILL2;
                should_ability_stay_highlighted = true;
            }
        }
        else if(CheckCollisionPointRec(Mouse_Positon, superpower_bound))
        {
            if(control.can_ability_be_used_based_on_energy_points(hero_to_be_animated_index,SUPERPOWER,User_Turn,user1.Get_Energy(), user2.Get_Energy()))
            {
                ability_to_be_highlighted = SUPERPOWER;
                should_ability_be_highlighted = true;
            }
            if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && ability_to_be_highlighted == SUPERPOWER)
            {
                ability_to_stay_highlighted = SUPERPOWER;
                should_ability_stay_highlighted = true;
            }
        }
        else
        {
            //this means no ability should be highlighted
            if(should_ability_stay_highlighted)
            {   
                if(!is_mouse_hovering_over_enemy && !is_mouse_hovring_over_attack_or_endTurn_button && IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
                {
                    ability_to_be_highlighted = NON;
                    should_ability_be_highlighted = false;
                    is_mouse_hovering_over_abilities = false; 
                }
            }
            else
            {
                ability_to_be_highlighted = NON;
                should_ability_be_highlighted = false;
                is_mouse_hovering_over_abilities = false; 

            }
        }
    }

    //here i check to see if i should still highlight the enemy or not
    if(User_Turn == USER1)
    {
        if(!(CheckCollisionPointRec(Mouse_Positon, user2_hero1_bound) || CheckCollisionPointRec(Mouse_Positon, user2_hero2_bound) || CheckCollisionPointRec(Mouse_Positon, user2_hero3_bound)))
        {
            enemy_to_be_highlighted = 4;
            should_enemy_be_highlighted = false;
            if(IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
            {
                enemy_to_stay_highlighted = 4;
                should_enemy_stay_highlighted = false;
            }
        }
    }
    else if(User_Turn == USER2)
    {
        if(!(CheckCollisionPointRec(Mouse_Positon, user1_hero1_bound) || CheckCollisionPointRec(Mouse_Positon, user1_hero2_bound) || CheckCollisionPointRec(Mouse_Positon, user1_hero3_bound)))
        {
            enemy_to_be_highlighted = 4;
            should_enemy_be_highlighted = false;
            if(IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
            {
                enemy_to_stay_highlighted = 4;
                should_enemy_stay_highlighted = false;
            }
        }
    }





    //drawing part
    BeginDrawing();
    //drawing the background
    DrawTexture(Background_img, 0, -100, WHITE);
   
    //game info panel
    DrawTexture(Control_panel, 0, 600 - Control_panel.height, WHITE);
   
    
    //drawing heros animated or non animated
        //this loop and if statement is placed here
        //to make the heros be drawn in the backgrond
        //or in front of the animated hero
        //with out this the animations wont look correct
    if(hero_to_be_animated_index == 2)
    {
        //drawing heros 
        for(int i = 0 ; i < 3 ; i++)
        {
            
            print_heros_on_screen_idle_and_highlight_hero_which_is_hoverd(user1_hero_arr, user2_hero_arr, i, User_Turn,Hero_should_be_highlighted, user1_hero_to_be_highlighted_index, user2_hero_to_be_highlighted_index, hero_to_be_animated_index);
        }
    }

   

    
    //animating heros
   if(should_hero_be_animated)
   {

       if(User_Turn == USER1)
       {

           switch (user1_hero_arr[hero_to_be_animated_index])
           {
               case DANI_GOLANG:
               //this is to flip horizontaly so that the animation is facing the correct direction
               if(Dani_anim_struct.frame_width > 0)
               {
                   Dani_anim_struct.frame_width = -dani_frame_width;
                }
                DrawTextureRec(Dani_anim_texture,Dani_anim_struct.frame,{180.0f - (100 * (hero_to_be_animated_index % 2)), 80.0f + (hero_to_be_animated_index * 50)} , WHITE);
                update_animation_loop(Dani_anim_struct);
                break;

            case AMIN_EMENI:
            if(Amin_anim_struct.frame_width > 0)
                {
                    Amin_anim_struct.frame_width = -amin_frame_width;
                }
                DrawTextureRec(Amin_anim_texture,Amin_anim_struct.frame,{180.0f - (100 * (hero_to_be_animated_index % 2)), 80.0f + (hero_to_be_animated_index * 50)} , WHITE);
                update_animation_loop(Amin_anim_struct);
                break;
                
                case TAHA_BOZORGE:
                if(Tbig_anim_struct.frame_width > 0)
                {
                    Tbig_anim_struct.frame_width = -tbig_frame_width;
                }
                DrawTextureRec(Tbig_anim_texture,Tbig_anim_struct.frame,{180.0f - (100 * (hero_to_be_animated_index % 2)), 80.0f + (hero_to_be_animated_index * 50)} , WHITE);
                update_animation_loop(Tbig_anim_struct);
                break;
                case TAHA_KOCHIKE:
                if(Tlittle_anim_struct.frame_width > 0)
                {
                    Tlittle_anim_struct.frame_width = -tlittle_frame_width;
                }
                DrawTextureRec(Tlittle_anim_texture,Tlittle_anim_struct.frame, {180.0f - (100 * (hero_to_be_animated_index % 2)), 80.0f + (hero_to_be_animated_index * 50)} , WHITE);
                update_animation_loop(Tlittle_anim_struct);
                break;
                case AGHA_SHAHRIAR:
                if(Shahriar_anim_struct.frame_width > 0)
                {
                    Shahriar_anim_struct.frame_width = -shahriar_frame_width;
                }
                DrawTextureRec(Shahriar_anim_texture, Shahriar_anim_struct.frame, {180.0f - (100 * (hero_to_be_animated_index % 2)), 80.0f + (hero_to_be_animated_index * 50)} , WHITE);
                update_animation_loop(Shahriar_anim_struct);
                break;
            case WHITEDOCTOR:
                if(Doc_anim_struct.frame_width > 0)
                {
                    Doc_anim_struct.frame_width = - doc_frame_width;
                }
                DrawTextureRec(Doc_anim_texture,Doc_anim_struct.frame,{180.0f - (100 * (hero_to_be_animated_index % 2)), 80.0f + (hero_to_be_animated_index * 50)} , WHITE);
                update_animation_loop(Doc_anim_struct);
                break;
            case POUYA_KAJDOM:
                if(Pouya_anim_struct.frame_width > 0)
                {
                    Pouya_anim_struct.frame_width = -pouya_frame_width;
                }
                DrawTextureRec(Pouya_anim_texture,Pouya_anim_struct.frame,{180.0f - (100 * (hero_to_be_animated_index % 2)), 80.0f + (hero_to_be_animated_index * 50)} , WHITE);
                update_animation_loop(Pouya_anim_struct);
                break;
                
            }
        }
        else if(User_Turn == USER2)
        {
            switch (user2_hero_arr[hero_to_be_animated_index])
            {
                case DANI_GOLANG:
                //this is to flip horizontaly so that the animation is facing the correct direction
                if(Dani_anim_struct.frame_width < 0)
                {
                    Dani_anim_struct.frame_width = dani_frame_width;
                }
                DrawTextureRec(Dani_anim_texture,Dani_anim_struct.frame,{1000.0f -(350.0f - (100 * (hero_to_be_animated_index % 2))), 80.0f + (hero_to_be_animated_index * 50)} , WHITE);
                update_animation_loop(Dani_anim_struct);
                break;
                
                case AMIN_EMENI:
                if(Amin_anim_struct.frame_width < 0)
                {
                    Amin_anim_struct.frame_width = amin_frame_width;
                }
                DrawTextureRec(Amin_anim_texture,Amin_anim_struct.frame,{1000.0f -(350.0f - (100 * (hero_to_be_animated_index % 2))), 80.0f + (hero_to_be_animated_index * 50)} , WHITE);
                update_animation_loop(Amin_anim_struct);
                break;

                case TAHA_BOZORGE:
                if(Tbig_anim_struct.frame_width < 0)
                {
                    Tbig_anim_struct.frame_width = tbig_frame_width;
                }
                DrawTextureRec(Tbig_anim_texture,Tbig_anim_struct.frame,{1000.0f -(350.0f - (100 * (hero_to_be_animated_index % 2))), 80.0f + (hero_to_be_animated_index * 50)} , WHITE);
                update_animation_loop(Tbig_anim_struct);
                break;
            case TAHA_KOCHIKE:
                if(Tlittle_anim_struct.frame_width < 0)
                {
                    Tlittle_anim_struct.frame_width = tlittle_frame_width;
                }
                DrawTextureRec(Tlittle_anim_texture,Tlittle_anim_struct.frame, {1000.0f -(350.0f - (100 * (hero_to_be_animated_index % 2))), 80.0f + (hero_to_be_animated_index * 50)} , WHITE);
                update_animation_loop(Tlittle_anim_struct);
                break;
                case AGHA_SHAHRIAR:
                if(Shahriar_anim_struct.frame_width < 0)
                {
                    Shahriar_anim_struct.frame_width = shahriar_frame_width;
                }
                DrawTextureRec(Shahriar_anim_texture, Shahriar_anim_struct.frame, {1000.0f -(350.0f - (100 * (hero_to_be_animated_index % 2))), 80.0f + (hero_to_be_animated_index * 50)} , WHITE);
                update_animation_loop(Shahriar_anim_struct);
                break;
            case WHITEDOCTOR:
                if(Doc_anim_struct.frame_width < 0)
                {
                    Doc_anim_struct.frame_width =  doc_frame_width;
                }
                DrawTextureRec(Doc_anim_texture,Doc_anim_struct.frame,{1000.0f -(350.0f - (100 * (hero_to_be_animated_index % 2))), 80.0f + (hero_to_be_animated_index * 50)} , WHITE);
                update_animation_loop(Doc_anim_struct);
                break;
            case POUYA_KAJDOM:
                if(Pouya_anim_struct.frame_width < 0)
                {
                    Pouya_anim_struct.frame_width = pouya_frame_width;
                }
                DrawTextureRec(Pouya_anim_texture,Pouya_anim_struct.frame,{1000.0f -(350.0f - (100 * (hero_to_be_animated_index % 2))), 80.0f + (hero_to_be_animated_index * 50)} , WHITE);
                update_animation_loop(Pouya_anim_struct);
                break;
                
            }
        }
        //changing the panel to show info and powers
        DrawTexture(Control_panle_hero_selected,0,600 - Control_panle_hero_selected.height, WHITE);
    }
    
    if(hero_to_be_animated_index != 2)
    {
        //drawing heros 
        for(int i = 0 ; i < 3 ; i++)
        {
            
            print_heros_on_screen_idle_and_highlight_hero_which_is_hoverd(user1_hero_arr, user2_hero_arr, i, User_Turn,Hero_should_be_highlighted, user1_hero_to_be_highlighted_index, user2_hero_to_be_highlighted_index, hero_to_be_animated_index);
        }
    }

    if(enemy_to_be_highlighted == 0 && should_enemy_be_highlighted)
    {
        //if i dont draw the second line the hero will be display
        //on top of the 3rd enemy and make it look wierd
        highlight_enemy(user1_hero_arr, user2_hero_arr, User_Turn, enemy_to_be_highlighted);
        highlight_enemy(user1_hero_arr, user2_hero_arr, User_Turn, 2, GRAY);
    }
    else if(should_enemy_be_highlighted)
    {
        highlight_enemy(user1_hero_arr, user2_hero_arr, User_Turn, enemy_to_be_highlighted);
    }
    
    
    if(enemy_to_stay_highlighted == 0 && should_enemy_stay_highlighted)
    {
        highlight_enemy(user1_hero_arr, user2_hero_arr, User_Turn, enemy_to_stay_highlighted);
        if(enemy_to_be_highlighted != 2)
        {
            highlight_enemy(user1_hero_arr, user2_hero_arr, User_Turn, 2, GRAY);
        }
        else
        {
            highlight_enemy(user1_hero_arr, user2_hero_arr, User_Turn, enemy_to_be_highlighted);
        }
    }
    else if(should_enemy_stay_highlighted)
    {
        highlight_enemy(user1_hero_arr, user2_hero_arr, User_Turn, enemy_to_stay_highlighted);
    }

    




    //drawing name and energy level and round number on the ui panel
    // draw info grayed out and highlight it according to user turn
    if(!should_hero_be_animated)
    {
        //user1 info
        DrawTextEx(font, user1_name,{96 - (User2_name_size.x / 2), 524 - (User2_name_size.y / 2)}, 20, 0, GRAY);
        DrawText(user1_energy, 90, 565, 20, GRAY);
        //user2 info
        DrawTextEx(font, user2_name,{912 - (User2_name_size.x / 2), 524 - (User2_name_size.y / 2)}, 20, 0, GRAY);
        DrawText(user2_energy, 910, 565, 20, GRAY);

        //round number
        DrawText(current_round, 480, 540, 30, WHITE);

        //now for highlighting  text for whom ever turn it is
        if(User_Turn == USER1)
        {
            DrawTextEx(font, user1_name,{96 - (User2_name_size.x / 2), 524 - (User2_name_size.y / 2)}, 20, 0, WHITE);
            DrawText(user1_energy, 90, 565, 20, WHITE);
        }
        else if(User_Turn == USER2)
        {
            DrawTextEx(font, user2_name,{912 - (User2_name_size.x / 2), 524 - (User2_name_size.y / 2)}, 20, 0, WHITE);
            DrawText(user2_energy, 910, 565, 20, WHITE);
        }
    }

    


    if(should_hero_be_animated)
    {
        if(User_Turn == USER1)
        {
            //just khoshgelasion
            if(!should_ability_stay_highlighted && should_ability_be_highlighted)
            {
                display_ability_defenition_and_detail(user1_hero_arr, User_Turn, hero_to_be_animated_index, ability_to_be_highlighted, font, GRAY);
            }

            return_skill_texture_based_on_arguments_passed_onto_the_texture_array_passed_to_the_funtion(user1_hero_arr, user1_ability_texture_array, User_Turn,hero_to_be_animated_index);
            game_screen_draw_abilities_grayed_out(user1_ability_texture_array,Skill_1_bound,Skill_2_bound,superpower_bound);
            highlight_ability(user1_ability_texture_array, Skill_1_bound, Skill_2_bound, superpower_bound, ability_to_be_highlighted);
            if(should_ability_stay_highlighted)
            {
                highlight_ability(user1_ability_texture_array, Skill_1_bound, Skill_2_bound, superpower_bound, ability_to_stay_highlighted);
                //print ability info on screen
                display_ability_defenition_and_detail(user1_hero_arr, User_Turn, hero_to_be_animated_index, ability_to_stay_highlighted, font, LIGHTGRAY);
                DrawTexture(attack_button_textrue, Attack_button_bound.x, Attack_button_bound.y, LIGHTGRAY);                
                DrawTexture(end_turn_texture, End_turn_button_bound.x, End_turn_button_bound.y, LIGHTGRAY);                
                //checking to see if attack button is pressed
                if(CheckCollisionPointRec(Mouse_Positon, Attack_button_bound))
                {
                    DrawTexture(attack_button_textrue, Attack_button_bound.x, Attack_button_bound.y, WHITE);
                    std::cout << "user1 hoverd over attack button \n";
                    if(IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
                    {
                        std::cout << "user1 clicked on attack button \n";
                        should_execute_ability = true;
                    }
                }
                //checking to see end turn button has been pressed or not
                else if(CheckCollisionPointRec(Mouse_Positon, End_turn_button_bound))
                {
                    DrawTexture(end_turn_texture, End_turn_button_bound.x, End_turn_button_bound.y, WHITE);  
                    std::cout << "user 1 hoverd over end turn button \n";
                    if(IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
                    {
                        std::cout <<"user1 clicked on end turn button \n";
                        should_end_turn = true;
                    }
                }
            }
        }
        else if(User_Turn == USER2)
        {
            //merely khoshgelasion has no logical benefit
            if(!should_ability_stay_highlighted && should_ability_be_highlighted)
            {
                display_ability_defenition_and_detail(user2_hero_arr, User_Turn, hero_to_be_animated_index, ability_to_be_highlighted, font, GRAY);
            }


            return_skill_texture_based_on_arguments_passed_onto_the_texture_array_passed_to_the_funtion(user2_hero_arr, user2_ability_texture_array, User_Turn,hero_to_be_animated_index);
            game_screen_draw_abilities_grayed_out(user2_ability_texture_array,Skill_1_bound,Skill_2_bound,superpower_bound);
            highlight_ability(user2_ability_texture_array, Skill_1_bound, Skill_2_bound, superpower_bound, ability_to_be_highlighted);
            if(should_ability_stay_highlighted)
            {
                highlight_ability(user2_ability_texture_array, Skill_1_bound, Skill_2_bound, superpower_bound, ability_to_stay_highlighted);
                //print ability info on screen
                display_ability_defenition_and_detail(user2_hero_arr, User_Turn, hero_to_be_animated_index, ability_to_stay_highlighted, font, LIGHTGRAY);
                DrawTexture(attack_button_textrue, Attack_button_bound.x, Attack_button_bound.y, LIGHTGRAY);                
                DrawTexture(end_turn_texture, End_turn_button_bound.x, End_turn_button_bound.y, LIGHTGRAY);   
                

                if(CheckCollisionPointRec(Mouse_Positon, Attack_button_bound))
                {
                    DrawTextureEx(attack_button_textrue, {Attack_button_bound.x, Attack_button_bound.y}, 0, 0, WHITE);
                    std::cout << "user2 hover over attack button \n";
                    if(IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
                    {
                        std::cout << "user 2 clicked attack button \n";
                        should_execute_ability = true;
                    }
                }
                else if(CheckCollisionPointRec(Mouse_Positon, End_turn_button_bound))
                {
                    DrawTextureEx(end_turn_texture, {End_turn_button_bound.x, End_turn_button_bound.y}, 0, 0, WHITE);
                    std::cout << "user2 hoverd over end turn button \n";
                    if(IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
                    {
                        std::cout <<"user 2 clicked on end turn button \n";
                        should_end_turn = true;
                    }
                }
            }
        }
    }

    if(is_fading_in)
    {
        DrawRectangle(0, 0, GetScreenWidth(), GetScreenHeight(), Fade(BLACK, fade/255.0));
        fade -= 4.0;
        if(fade <= 0)
        {
            is_fading_in = false;
            fade = 0;
        }
    }
    



    EndDrawing();



    if(should_execute_ability)
    {
        
    }



    if(should_end_turn || control.should_change_turn(User_Turn, user1.Get_Energy(), user2.Get_Energy()))
    {
        //reseting variables for the next player
        should_ability_be_highlighted = false;
        should_ability_stay_highlighted = false;
        is_mouse_hovering_over_abilities = false;
        is_mouse_hovering_over_enemy = false;
        is_mouse_hovring_over_attack_or_endTurn_button = false;
        should_hero_be_animated = false;
        Hero_should_be_highlighted = false;
        user1_hero_to_be_highlighted_index = 4;
        user2_hero_to_be_highlighted_index = 4;
        hero_to_be_animated_index = 4;
        enemy_to_be_highlighted = 4;
        enemy_to_stay_highlighted = 4;
        should_execute_ability = false;
        should_end_turn = false;
        should_enemy_be_highlighted = false;
        should_enemy_stay_highlighted = false;

        //changing turn or ending round
        if(change_turn_or_finish_round(User_Turn, control.return_user_whom_started_the_game_as_an_int()))
        {
            control.Finish_Round();
        }



    }

    if(IsKeyPressed(KEY_K))
    {
        if(User_Turn == USER1)
        {
            User_Turn = USER2;
        }
        else
        {
            User_Turn = USER1;
        }
    }
    
    
}


#include "../headers/game.hpp"
#include "../raylib/include/raylib.h"
#include "../headers/hero_abstract_base_class.hpp"
#include "../headers/hero_sub_class_to_instatniate_objects.hpp"
#include "../headers/user.hpp"
#include "../headers/controller.hpp"
#include <iostream>
#include <cmath>
#include <array>

const float Animation_Duration = 2.0f;
const float Animation_Speed = 25.0f;
const int characters_sprite_sheets_frame_height = 250;

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


struct Animation
{
    int First_frame;
    int Last_frame;
    int current_frame;

    float frame_width;
    float frame_height;
    float first_frame_x;
    float first_frame_y;


    float animation_speed;
    float duration_left;
    float initial_duration;
    Rectangle frame;
};

void update_animation_loop(Animation& anim)
{
    anim.duration_left -= GetFrameTime() * anim.animation_speed;
    if(anim.duration_left <= 0)
    {
        anim.current_frame++;
        anim.duration_left = anim.initial_duration;
    }
    if(anim.current_frame > anim.Last_frame)
    {
        anim.current_frame = anim.First_frame;
    }
    anim.frame = {anim.first_frame_x + (anim.frame_width * anim.current_frame), anim.first_frame_y, anim.frame_width, anim.frame_height};
}

void update_animation_once(Animation& anim)
{
    if(anim.current_frame == anim.First_frame)
    {
        return;
    }

    anim.duration_left -= GetFrameTime() * Animation_Speed;
    if(anim.duration_left <= 0)
    {
        anim.duration_left = anim.initial_duration;
        anim.current_frame++;
    }
    if(anim.current_frame > anim.Last_frame)
    {
        anim.current_frame = anim.Last_frame;
    }
    anim.frame = {anim.first_frame_x + (anim.frame_width * anim.current_frame), anim.first_frame_y, anim.frame_width, anim.frame_height};
    
}
Texture2D Return_The_Corresponding_Texture_Based_On_User_Array(const std::array <int,3> & user1_hero_array, const std::array <int,3> & user2_hero_array, int current_user, int array_index)
{
    //amin 
    static Texture2D Amin_Right = LoadTexture("game_assets/character_select_screen_asset/Amin_User2.png");
    static Texture2D Amin_Left = LoadTexture("game_assets/character_select_screen_asset/Amin_User1.png");
    // dani
    static Texture2D Dani_Right = LoadTexture("game_assets/character_select_screen_asset/Dani_User2.png");
    static Texture2D Dani_Left = LoadTexture("game_assets/character_select_screen_asset/Dani_User1.png");
    //pouya
    static Texture2D Pouya_Right =LoadTexture("game_assets/character_select_screen_asset/Pouya_User2.png");
    static Texture2D Pouya_Left =LoadTexture("game_assets/character_select_screen_asset/Pouya_User1.png");
    // Taha kockike
    static Texture2D TLITTLE_Right =LoadTexture("game_assets/character_select_screen_asset/TLITTLE_User2.png");
    static Texture2D TLITTLE_Left =LoadTexture("game_assets/character_select_screen_asset/TLITTLE_User1.png");
    // Taha bozorge
    static Texture2D TBIG_Right =LoadTexture("game_assets/character_select_screen_asset/TBIG_User2.png");
    static Texture2D TBIG_Left =LoadTexture("game_assets/character_select_screen_asset/TBIG_User1.png");
    // white doc
    static Texture2D DOC_Right =LoadTexture("game_assets/character_select_screen_asset/DOC_User2.png");
    static Texture2D DOC_Left =LoadTexture("game_assets/character_select_screen_asset/DOC_User1.png");
    //SHAHRIAR
    static Texture2D SHAHRIAR_Right =LoadTexture("game_assets/character_select_screen_asset/shahriar_User2.png");
    static Texture2D SHAHRIAR_Left =LoadTexture("game_assets/character_select_screen_asset/shahriar_User1.png");


    if(current_user == USER1)
    {
        switch (user1_hero_array[array_index])
        {
        case DANI_GOLANG:
            return Dani_Left;
        case AMIN_EMENI:
            return Amin_Left;
        case AGHA_SHAHRIAR:
            return SHAHRIAR_Left;
        case POUYA_KAJDOM:
            return Pouya_Left;
        case TAHA_KOCHIKE:
            return  TLITTLE_Left;
        case TAHA_BOZORGE:
            return TBIG_Left;
        case WHITEDOCTOR:
            return DOC_Left;

        }
    }
    else if(current_user == USER2)
    {
        switch (user2_hero_array[array_index])
        {
        case DANI_GOLANG:
            return Dani_Right;
        case AMIN_EMENI:
            return Amin_Right;
        case AGHA_SHAHRIAR:
            return SHAHRIAR_Right;
        case POUYA_KAJDOM:
            return Pouya_Right;
        case TAHA_KOCHIKE:
            return  TLITTLE_Right;
        case TAHA_BOZORGE:
            return TBIG_Right;
        case WHITEDOCTOR:
            return DOC_Right;

        }

    }
} 




void set_frame_width_with_respect_to_the_player(Animation& anim, int width , int user)
{
    if(user == USER2)
    {
        anim.frame_width = width;
    }
    else
    {
        anim.frame_width = -width;
    }
}
Game::Game() : current_screen(CHARACTER_SELECT_SCREEN){}
 
void Game::load_game_screen_animation_sprite_sheets()
{
    Doc_anim_texture = LoadTexture("game_assets/game_screen_assets/doc-sprite-sheet.png");
    Dani_anim_texture = LoadTexture("game_assets/game_screen_assets/dani-sprite.png");
    Amin_anim_texture = LoadTexture("game_assets/game_screen_assets/amin-sprite.png");
    Tlittle_anim_texture = LoadTexture("game_assets/game_screen_assets/t-little-sprite.png");
    Tbig_anim_texture = LoadTexture("game_assets/game_screen_assets/tbig-sprite.png");
    Pouya_anim_texture = LoadTexture("game_assets/game_screen_assets/pouya-sprite.png");
    Shahriar_anim_texture = LoadTexture("game_assets/game_screen_assets/shahriar-sprite.png");
}

void Game::unload_game_screen_animation_sprite_sheets()
{
    UnloadTexture(Doc_anim_texture);
    UnloadTexture(Dani_anim_texture);
    UnloadTexture(Amin_anim_texture);
    UnloadTexture(Tlittle_anim_texture);
    UnloadTexture(Tbig_anim_texture);
    UnloadTexture(Pouya_anim_texture);
    UnloadTexture(Shahriar_anim_texture);
}

void Game::load_game_screen_abilities_textures()
{
        Dani_fil_kosh = LoadTexture("game_assets/game_screen_assets/powers/normalpowers/fil-kosh.png");
        Dani_lock = LoadTexture("game_assets/game_screen_assets/powers/normalpowers/the-lock.png");
        Dani_super_power_3rounds_left = LoadTexture("game_assets/game_screen_assets/powers/superpowers/dani/trenches-3rounds-left.png");
        Dani_super_power_2rounds_left = LoadTexture("game_assets/game_screen_assets/powers/superpowers/dani/trenches-2rounds-left.png");
        Dani_super_power_1rounds_left = LoadTexture("game_assets/game_screen_assets/powers/superpowers/dani/trenches-1round-left.png");
        Dani_super_power_ready = LoadTexture("game_assets/game_screen_assets/powers/superpowers/dani/trenches-ready.png");
        Dani_super_power_not_ready = LoadTexture("game_assets/game_screen_assets/powers/superpowers/dani/trenches-not-ready.png");
        
        amin_friendly_fire = LoadTexture("game_assets/game_screen_assets/powers/normalpowers/friendly-fire.png");
        amin_last_bullet = LoadTexture("game_assets/game_screen_assets/powers/normalpowers/last-bullet.png");
        amin_super_power_2rounds_left = LoadTexture("game_assets/game_screen_assets/powers/superpowers/amin/the-shout-2rounds-left.png");
        amin_super_power_1rounds_left = LoadTexture("game_assets/game_screen_assets/powers/superpowers/amin/the-shout-1round-left.png");
        amin_super_power_ready = LoadTexture("game_assets/game_screen_assets/powers/superpowers/amin/the-shout-ready.png");
        amin_super_power_not_ready = LoadTexture("game_assets/game_screen_assets/powers/superpowers/amin/the-shout-not-ready.png");

        doc_asprin = LoadTexture("game_assets/game_screen_assets/powers/normalpowers/asprin.png");
        doc_doping = LoadTexture("game_assets/game_screen_assets/powers/normalpowers/doping.png");
        doc_super_power_3rounds_left = LoadTexture("game_assets/game_screen_assets/powers/superpowers/doc/revival-3rounds-left.png");
        doc_super_power_2rounds_left = LoadTexture("game_assets/game_screen_assets/powers/superpowers/doc/revival-2rounds-left.png");
        doc_super_power_1rounds_left = LoadTexture("game_assets/game_screen_assets/powers/superpowers/doc/revival-1round-left.png");
        doc_super_power_ready = LoadTexture("game_assets/game_screen_assets/powers/superpowers/doc/revival-ready.png");
        doc_super_power_not_ready = LoadTexture("game_assets/game_screen_assets/powers/superpowers/doc/revival-not-ready.png");
        
        tlittle_razor_sharp = LoadTexture("game_assets/game_screen_assets/powers/normalpowers/razor-sharp.png");
        tlittle_blood_bag = LoadTexture("game_assets/game_screen_assets/powers/normalpowers/blood-bag.png");
        tlittle_super_power_2rounds_left = LoadTexture("game_assets/game_screen_assets/powers/superpowers/tlittle/quarantine-2rounds-left.png");
        tlittle_super_power_1rounds_left = LoadTexture("game_assets/game_screen_assets/powers/superpowers/tlittle/quarantine-1round-left.png");
        tlittle_super_power_ready = LoadTexture("game_assets/game_screen_assets/powers/superpowers/tlittle/quarantine-ready.png");
        tlittle_super_power_not_ready = LoadTexture("game_assets/game_screen_assets/powers/superpowers/tlittle/quarantine-not-ready.png");
        
        tbig_machine_gun = LoadTexture("game_assets/game_screen_assets/powers/normalpowers/machine-gun.png");
        tbig_xray = LoadTexture("game_assets/game_screen_assets/powers/normalpowers/xray.png");
        tbig_super_power_3rounds_left = LoadTexture("game_assets/game_screen_assets/powers/superpowers/tbig/revenge-3rounds-left.png");
        tbig_super_power_2rounds_left = LoadTexture("game_assets/game_screen_assets/powers/superpowers/tbig/revenge-2rounds-left.png");
        tbig_super_power_1rounds_left = LoadTexture("game_assets/game_screen_assets/powers/superpowers/tbig/revenge-1round-left.png");
        tbig_super_power_ready = LoadTexture("game_assets/game_screen_assets/powers/superpowers/tbig/revenge-ready.png");
        tbig_super_power_not_ready = LoadTexture("game_assets/game_screen_assets/powers/superpowers/tbig/revenge-not-ready.png");
        
        pouya_dagger = LoadTexture("game_assets/game_screen_assets/powers/normalpowers/dagger-kajdom.png");
        pouya_scorpion = LoadTexture("game_assets/game_screen_assets/powers/normalpowers/scorpion-kajdom.png");
        pouya_super_power_3rounds_left = LoadTexture("game_assets/game_screen_assets/powers/superpowers/pouya/venomous-bite-kajdom-3rounds-left.png");
        pouya_super_power_2rounds_left = LoadTexture("game_assets/game_screen_assets/powers/superpowers/pouya/venomous-bite-kajdom-2rounds-left.png");
        pouya_super_power_1rounds_left = LoadTexture("game_assets/game_screen_assets/powers/superpowers/pouya/venomous-bite-kajdom-1round-left.png");
        pouya_super_power_ready = LoadTexture("game_assets/game_screen_assets/powers/superpowers/pouya/venomous-bite-kajdom-ready.png");
        pouya_super_power_not_ready = LoadTexture("game_assets/game_screen_assets/powers/superpowers/pouya/venomous-bite-kajdom-not-ready.png");
        
        shahriar_dummy = LoadTexture("game_assets/game_screen_assets/powers/normalpowers/shahriar-dummy.png");
        shahriar_stubborn = LoadTexture("game_assets/game_screen_assets/powers/normalpowers/shahriar-stubborn.png");
        shahriar_super_power_3rounds_left = LoadTexture("game_assets/game_screen_assets/powers/superpowers/shahriar/shahriar/shahriar-super-power-3rounds-left.png");
        shahriar_super_power_2rounds_left = LoadTexture("game_assets/game_screen_assets/powers/superpowers/shahriar/shahriar-super-power-2rounds-left.png");
        shahriar_super_power_1rounds_left = LoadTexture("game_assets/game_screen_assets/powers/superpowers/shahriar/shahriar-super-power-1round-left.png");
        shahriar_super_power_ready = LoadTexture("game_assets/game_screen_assets/powers/superpowers/shahriar/shahriar-super-power-ready.png");
        shahriar_super_power_not_ready = LoadTexture("game_assets/game_screen_assets/powers/superpowers/shahriar/shahriar-super-power-not-ready.png");
}

void Game::unload_game_screen_abilities_textures()
{
        UnloadTexture( Dani_fil_kosh);
        UnloadTexture( Dani_lock);
        UnloadTexture( Dani_super_power_3rounds_left);
        UnloadTexture( Dani_super_power_2rounds_left);
        UnloadTexture( Dani_super_power_1rounds_left);
        UnloadTexture( Dani_super_power_ready);
        
        UnloadTexture( amin_friendly_fire);
        UnloadTexture( amin_last_bullet);
        UnloadTexture( amin_super_power_2rounds_left);
        UnloadTexture( amin_super_power_1rounds_left);
        UnloadTexture( amin_super_power_ready);

        UnloadTexture( doc_asprin);
        UnloadTexture( doc_doping);
        UnloadTexture( doc_super_power_3rounds_left);
        UnloadTexture( doc_super_power_2rounds_left);
        UnloadTexture( doc_super_power_1rounds_left);
        UnloadTexture( doc_super_power_ready);
        
        UnloadTexture( tlittle_razor_sharp);
        UnloadTexture( tlittle_blood_bag);
        UnloadTexture( tlittle_super_power_2rounds_left);
        UnloadTexture( tlittle_super_power_1rounds_left);
        UnloadTexture( tlittle_super_power_ready);
        
        UnloadTexture( tbig_machine_gun);
        UnloadTexture( tbig_xray);
        UnloadTexture( tbig_super_power_3rounds_left);
        UnloadTexture( tbig_super_power_2rounds_left);
        UnloadTexture( tbig_super_power_1rounds_left);
        UnloadTexture( tbig_super_power_ready);
        
        UnloadTexture( pouya_dagger);
        UnloadTexture( pouya_scorpion);
        UnloadTexture( pouya_super_power_3rounds_left);
        UnloadTexture( pouya_super_power_2rounds_left);
        UnloadTexture( pouya_super_power_1rounds_left);
        UnloadTexture( pouya_super_power_ready);
        
        UnloadTexture( shahriar_dummy);
        UnloadTexture( shahriar_stubborn);
        UnloadTexture( pouya_super_power_3rounds_left);
        UnloadTexture( pouya_super_power_2rounds_left);
        UnloadTexture( pouya_super_power_1rounds_left);
        UnloadTexture( pouya_super_power_ready);
}
void Game::print_heros_on_screen_idle_and_highlight_hero_which_is_hoverd(const std::array <int,3>& user1_heros, const std::array <int,3>&  user2_heros, int index, int user_turn,bool should_highlight,int user1_hero_being_hoverd, int user2_hero_being_hoverd, int hero_to_be_animated_index)
{

    //for player one
    switch (user1_heros[index])
    {
    case WHITEDOCTOR:
        if(user_turn == USER1 && should_highlight && index == user1_hero_being_hoverd && hero_to_be_animated_index != index)
        {
            DrawTextureRec(Doc_anim_texture,{0,0, -164,characters_sprite_sheets_frame_height}, {180.0f - (100 * (index % 2)), 80.0f + (index * 50)},WHITE);
        }
        else if(user_turn == USER1 && hero_to_be_animated_index == index)
        {
            break;
        }
        else
            DrawTextureRec(Doc_anim_texture,{0,0, -164,characters_sprite_sheets_frame_height}, {180.0f - (100 * (index % 2)), 80.0f + (index * 50)},GRAY);
        break;
    
    case DANI_GOLANG:
        if(user_turn == USER1 && should_highlight && index == user1_hero_being_hoverd && hero_to_be_animated_index != index)
        {
            DrawTextureRec(Dani_anim_texture,{0,0, -136,characters_sprite_sheets_frame_height}, {180.0f - (100 * (index % 2)), 80.0f + (index * 50)},WHITE);
        }
        else if(user_turn == USER1 && hero_to_be_animated_index == index)
        {
            break;
        }
        else
            DrawTextureRec(Dani_anim_texture,{0,0, -136,characters_sprite_sheets_frame_height}, {180.0f - (100 * (index % 2)), 80.0f + (index * 50)},GRAY);
        break;
    
    case AMIN_EMENI:
        if(user_turn == USER1 && should_highlight && index == user1_hero_being_hoverd && hero_to_be_animated_index != index)
        {
            DrawTextureRec(Amin_anim_texture,{0,0, -145,characters_sprite_sheets_frame_height}, {180.0f - (100 * (index % 2)), 80.0f + (index * 50)},WHITE);
        }
        else if(user_turn == USER1 && hero_to_be_animated_index == index)
        {
            break;
        }
        else
            DrawTextureRec(Amin_anim_texture,{0,0, -145,characters_sprite_sheets_frame_height}, {180.0f - (100 * (index % 2)), 80.0f + (index * 50)},GRAY);
        
        break;
    
    case POUYA_KAJDOM:
        if(user_turn == USER1 && should_highlight && index == user1_hero_being_hoverd && hero_to_be_animated_index != index)
        {
            DrawTextureRec(Pouya_anim_texture,{0,0, -120,characters_sprite_sheets_frame_height}, {180.0f - (100 * (index % 2)), 80.0f + (index * 50)},WHITE);
        }
        else if(user_turn == USER1 && hero_to_be_animated_index == index)
        {
            break;
        }
        else
            DrawTextureRec(Pouya_anim_texture,{0,0, -120,characters_sprite_sheets_frame_height}, {180.0f - (100 * (index % 2)), 80.0f + (index * 50)},GRAY);
        
        break;
    
    case AGHA_SHAHRIAR:
        if(user_turn == USER1 && should_highlight && index == user1_hero_being_hoverd && hero_to_be_animated_index != index)
        {
           DrawTextureRec(Shahriar_anim_texture,{0,0, -160,characters_sprite_sheets_frame_height}, {180.0f - (100 * (index % 2)), 80.0f + (index * 50)},WHITE);
        }   
        else if(user_turn == USER1 && hero_to_be_animated_index == index)
        {
            break;
        }  
        else
            DrawTextureRec(Shahriar_anim_texture,{0,0, -160,characters_sprite_sheets_frame_height}, {180.0f - (100 * (index % 2)), 80.0f + (index * 50)},GRAY); 
        
        break;
    
    case TAHA_KOCHIKE:
        if(user_turn == USER1 && should_highlight && index == user1_hero_being_hoverd && hero_to_be_animated_index != index)
        {
            DrawTextureRec(Tlittle_anim_texture,{0,0, -185,characters_sprite_sheets_frame_height}, {180.0f - (100 * (index % 2)), 80.0f + (index * 50)},WHITE);
        }     
        else if(user_turn == USER1 && hero_to_be_animated_index == index)
        {
            break;
        }
        else
            DrawTextureRec(Tlittle_anim_texture,{0,0, -185,characters_sprite_sheets_frame_height}, {180.0f - (100 * (index % 2)), 80.0f + (index * 50)},GRAY);
        
        break;
    
    case TAHA_BOZORGE:
        if(user_turn == USER1 && should_highlight && index == user1_hero_being_hoverd && hero_to_be_animated_index != index)
        {
            DrawTextureRec(Tbig_anim_texture,{0,0, -135,characters_sprite_sheets_frame_height}, {180.0f - (100 * (index % 2)), 80.0f + (index * 50)},WHITE);
        }   
        else if(user_turn == USER1 && hero_to_be_animated_index == index)
        {
            break;
        }  
        else
            DrawTextureRec(Tbig_anim_texture,{0,0, -135,characters_sprite_sheets_frame_height}, {180.0f - (100 * (index % 2)), 80.0f + (index * 50)},GRAY);
        
        break;
    
    }
    //for player two

    switch (user2_heros[index])
    {
    case WHITEDOCTOR:
        if(user_turn == USER2 && should_highlight && index == user2_hero_being_hoverd && hero_to_be_animated_index != index)
        {
            DrawTextureRec(Doc_anim_texture,{0,0, 164,characters_sprite_sheets_frame_height}, {1000.0f - (350 - (100 * (index % 2))), 80.0f + (index * 50)},WHITE);
        }    
        else if(user_turn == USER2 && hero_to_be_animated_index == index)
        {
            break;
        } 
        else
            DrawTextureRec(Doc_anim_texture,{0,0, 164,characters_sprite_sheets_frame_height}, {1000.0f - (350 - (100 * (index % 2))), 80.0f + (index * 50)},GRAY);
        
        break;
    
    case DANI_GOLANG:
        if(user_turn == USER2 && should_highlight && index == user2_hero_being_hoverd && hero_to_be_animated_index != index)
        {
            DrawTextureRec(Dani_anim_texture,{0,0, 136,characters_sprite_sheets_frame_height}, {1000.0f - (350 - (100 * (index % 2))), 80.0f + (index * 50)},WHITE);
        }     
        else if(user_turn == USER2 && hero_to_be_animated_index == index)
        {
            break;
        } 
        else
            DrawTextureRec(Dani_anim_texture,{0,0, 136,characters_sprite_sheets_frame_height}, {1000.0f - (350 - (100 * (index % 2))), 80.0f + (index * 50)},GRAY);
        
        break;
    
    case AMIN_EMENI:
        if(user_turn == USER2 && should_highlight && index == user2_hero_being_hoverd && hero_to_be_animated_index != index)
        {
            DrawTextureRec(Amin_anim_texture,{0,0, 145,characters_sprite_sheets_frame_height}, {1000.0f - (350 - (100 * (index % 2))), 80.0f + (index * 50)},WHITE);
        }     
        else if(user_turn == USER2 && hero_to_be_animated_index == index)
        {
            break;
        } 
        else
            DrawTextureRec(Amin_anim_texture,{0,0, 145,characters_sprite_sheets_frame_height}, {1000.0f - (350 - (100 * (index % 2))), 80.0f + (index * 50)},GRAY);
        
        break;
    
    case POUYA_KAJDOM:
        if(user_turn == USER2 && should_highlight && index == user2_hero_being_hoverd && hero_to_be_animated_index != index)
        {
            DrawTextureRec(Pouya_anim_texture,{0,0, 120,characters_sprite_sheets_frame_height}, {1000.0f - (350 - (100 * (index % 2))), 80.0f + (index * 50)},WHITE);
        }     
        else if(user_turn == USER2 && hero_to_be_animated_index == index)
        {
            break;
        } 
        else
            DrawTextureRec(Pouya_anim_texture,{0,0, 120,characters_sprite_sheets_frame_height}, {1000.0f - (350 - (100 * (index % 2))), 80.0f + (index * 50)},GRAY);
        
        break;
    
    case AGHA_SHAHRIAR:
        if(user_turn == USER2 && should_highlight && index == user2_hero_being_hoverd && hero_to_be_animated_index != index)
        {
            DrawTextureRec(Shahriar_anim_texture,{0,0, 160,characters_sprite_sheets_frame_height}, {1000.0f - (350 - (100 * (index % 2))), 80.0f + (index * 50)},WHITE);
        }     
        else if(user_turn == USER2 && hero_to_be_animated_index == index)
        {
            break;
        } 
        else
            DrawTextureRec(Shahriar_anim_texture,{0,0, 160,characters_sprite_sheets_frame_height}, {1000.0f - (350 - (100 * (index % 2))), 80.0f + (index * 50)},GRAY);
        
        break;
    
    case TAHA_KOCHIKE:
        if(user_turn == USER2 && should_highlight && index == user2_hero_being_hoverd && hero_to_be_animated_index != index)
        {
            DrawTextureRec(Tlittle_anim_texture,{0,0, 178,characters_sprite_sheets_frame_height}, {1000.0f - (350 - (100 * (index % 2))), 80.0f + (index * 50)},WHITE);
        }   
        else if(user_turn == USER2 && hero_to_be_animated_index == index)
        {
            break;
        }   
        else
            DrawTextureRec(Tlittle_anim_texture,{0,0, 178,characters_sprite_sheets_frame_height}, {1000.0f - (350 - (100 * (index % 2))), 80.0f + (index * 50)},GRAY);
        
        break;
    
    case TAHA_BOZORGE:
        if(user_turn == USER2 && should_highlight && index == user2_hero_being_hoverd && hero_to_be_animated_index != index)
        {
            DrawTextureRec(Tbig_anim_texture,{0,0, 135,characters_sprite_sheets_frame_height}, {1000.0f - (350 - (100 * (index % 2))), 80.0f + (index * 50)},WHITE);
        }
        else if(user_turn == USER2 && hero_to_be_animated_index == index)
        {
            break;
        }      
        else
            DrawTextureRec(Tbig_anim_texture,{0,0, 135,characters_sprite_sheets_frame_height}, {1000.0f - (350 - (100 * (index % 2))), 80.0f + (index * 50)},GRAY);
        
        break;
    
    }
}


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
            Game_Screen();
            return true;

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
                    if(!IsSoundPlaying(Card_sfx));
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

Texture2D Game::return_animation_texture_based_on_arguments_passed(const std::array <int,3>& user1_hero_arr, const std::array <int,3>& user2_hero_arr,int user_turn, int hero_index_in_array)
{
    if(user_turn == USER1)
    {
        switch (user1_hero_arr[hero_index_in_array])
        {
        case DANI_GOLANG:
            return Dani_anim_texture;
        case AMIN_EMENI:
            return Amin_anim_texture;
        case TAHA_BOZORGE:
            return Tbig_anim_texture;
        case TAHA_KOCHIKE:
            return Tlittle_anim_texture;
        case POUYA_KAJDOM:
            return Pouya_anim_texture;
        case WHITEDOCTOR:
            return Doc_anim_texture;
        case AGHA_SHAHRIAR:
            return Shahriar_anim_texture;
        
        }
    }
    else if(user_turn == USER2)
    {
        switch (user2_hero_arr[hero_index_in_array])
        {
        case DANI_GOLANG:
            return Dani_anim_texture;
        case AMIN_EMENI:
            return Amin_anim_texture;
        case TAHA_BOZORGE:
            return Tbig_anim_texture;
        case TAHA_KOCHIKE:
            return Tlittle_anim_texture;
        case POUYA_KAJDOM:
            return Pouya_anim_texture;
        case WHITEDOCTOR:
            return Doc_anim_texture;
        case AGHA_SHAHRIAR:
            return Shahriar_anim_texture;
        
        }
    }
}

void Game::return_skill_texture_based_on_arguments_passed_onto_the_texture_array_passed_to_the_funtion(const std::array<int,3>& user_hero_array,  std::array <Texture2D, 3>& user_texture_array, int user_turn, int hero_index_in_array)
{
    switch (user_hero_array[hero_index_in_array])
    {
        case DANI_GOLANG:
        {
            //SO WE HAVE TO FILL THE PASSED ARRAY WITH DANI ABILITIES
            //FIRST ABILITY
            user_texture_array[SKILL1] = Dani_fil_kosh;
            user_texture_array[SKILL2] = Dani_lock;
            //HOW MANY ROUNDS IS LEFT TILL THE SUPER POWER IS READY
            //TO RETURN THE CORRECT TEXTURE

            //I KNOW I SHOULDN'T WRITE NESTED IFS AND ELSES 
            //LORD FORGIVE ME I HAD TO I HAD NO OTHER CHOICE
            //HOLD YOUR BRAETH I AM GOING TO COMMIT A CODE CRIME!
            
            if(control.return_rounds_left_till_hero_ability_is_ready(hero_index_in_array, user_turn) == 0)
            {
               user_texture_array[SUPERPOWER] = Dani_super_power_ready;
            }
            else if(control.return_rounds_left_till_hero_ability_is_ready(hero_index_in_array, user_turn) == 1)
            {
                user_texture_array[SUPERPOWER] = Dani_super_power_1rounds_left;
            }
            else if(control.return_rounds_left_till_hero_ability_is_ready(hero_index_in_array, user_turn) == 2)
            {
                user_texture_array[SUPERPOWER] = Dani_super_power_2rounds_left;
            }
            else if(control.return_rounds_left_till_hero_ability_is_ready(hero_index_in_array, user_turn) == 3)
            {
                user_texture_array[SUPERPOWER] = Dani_super_power_3rounds_left;
            }
            else if(control.return_rounds_left_till_hero_ability_is_ready(hero_index_in_array, user_turn) == 4)
            {
                user_texture_array[SUPERPOWER] = Dani_super_power_not_ready;
            }
            
            break;
        }
        case AMIN_EMENI:
            user_texture_array[SKILL1] = amin_friendly_fire;
            user_texture_array[SKILL2] = amin_last_bullet;
            //super powers
            if(control.return_rounds_left_till_hero_ability_is_ready(hero_index_in_array, user_turn) == 0)
            {
               user_texture_array[SUPERPOWER] = amin_super_power_ready;
            }
            else if(control.return_rounds_left_till_hero_ability_is_ready(hero_index_in_array, user_turn) == 1)
            {
                user_texture_array[SUPERPOWER] = amin_super_power_1rounds_left;
            }
            else if(control.return_rounds_left_till_hero_ability_is_ready(hero_index_in_array, user_turn) == 2)
            {
                user_texture_array[SUPERPOWER] = amin_super_power_2rounds_left;
            }
            else if(control.return_rounds_left_till_hero_ability_is_ready(hero_index_in_array, user_turn) == 3)
            {
                user_texture_array[SUPERPOWER] = amin_super_power_not_ready;
            }
            
            break;
            
        case AGHA_SHAHRIAR:
            user_texture_array[SKILL1] = shahriar_dummy;
            user_texture_array[SKILL2] = shahriar_stubborn;
            //super powers
            if(control.return_rounds_left_till_hero_ability_is_ready(hero_index_in_array, user_turn) == 0)
            {
               user_texture_array[SUPERPOWER] = shahriar_super_power_ready;
            }
            else if(control.return_rounds_left_till_hero_ability_is_ready(hero_index_in_array, user_turn) == 1)
            {
                user_texture_array[SUPERPOWER] = shahriar_super_power_1rounds_left;
            }
            else if(control.return_rounds_left_till_hero_ability_is_ready(hero_index_in_array, user_turn) == 2)
            {
                user_texture_array[SUPERPOWER] = shahriar_super_power_2rounds_left;
            }
            else if(control.return_rounds_left_till_hero_ability_is_ready(hero_index_in_array, user_turn) == 3)
            {
                user_texture_array[SUPERPOWER] = shahriar_super_power_3rounds_left;
            }
            else if(control.return_rounds_left_till_hero_ability_is_ready(hero_index_in_array, user_turn) == 4)
            {
                user_texture_array[SUPERPOWER] = shahriar_super_power_not_ready;
            }
            
            break;
        
        case WHITEDOCTOR:
            user_texture_array[SKILL1] = doc_asprin;
            user_texture_array[SKILL2] = doc_doping;
            //super powers
            if(control.return_rounds_left_till_hero_ability_is_ready(hero_index_in_array, user_turn) == 0)
            {
               user_texture_array[SUPERPOWER] = doc_super_power_ready;
            }
            else if(control.return_rounds_left_till_hero_ability_is_ready(hero_index_in_array, user_turn) == 1)
            {
                user_texture_array[SUPERPOWER] = doc_super_power_1rounds_left;
            }
            else if(control.return_rounds_left_till_hero_ability_is_ready(hero_index_in_array, user_turn) == 2)
            {
                user_texture_array[SUPERPOWER] = doc_super_power_2rounds_left;
            }
            else if(control.return_rounds_left_till_hero_ability_is_ready(hero_index_in_array, user_turn) == 3)
            {
                user_texture_array[SUPERPOWER] = doc_super_power_3rounds_left;
            }
            else if(control.return_rounds_left_till_hero_ability_is_ready(hero_index_in_array, user_turn) == 4)
            {
                user_texture_array[SUPERPOWER] = doc_super_power_not_ready;
            }
            
            break;
        
        case TAHA_BOZORGE:
            user_texture_array[SKILL1] = tbig_machine_gun;
            user_texture_array[SKILL2] = tbig_xray;
            //super powers
            if(control.return_rounds_left_till_hero_ability_is_ready(hero_index_in_array, user_turn) == 0)
            {
               user_texture_array[SUPERPOWER] = tbig_super_power_ready;
            }
            else if(control.return_rounds_left_till_hero_ability_is_ready(hero_index_in_array, user_turn) == 1)
            {
                user_texture_array[SUPERPOWER] = tbig_super_power_1rounds_left;
            }
            else if(control.return_rounds_left_till_hero_ability_is_ready(hero_index_in_array, user_turn) == 2)
            {
                user_texture_array[SUPERPOWER] = tbig_super_power_2rounds_left;
            }
            else if(control.return_rounds_left_till_hero_ability_is_ready(hero_index_in_array, user_turn) == 3)
            {
                user_texture_array[SUPERPOWER] = tbig_super_power_3rounds_left;
            }
            else if(control.return_rounds_left_till_hero_ability_is_ready(hero_index_in_array, user_turn) == 4)
            {
                user_texture_array[SUPERPOWER] = tbig_super_power_not_ready;
            }
            break;
        
        case TAHA_KOCHIKE:
            user_texture_array[SKILL1] = tlittle_blood_bag;
            user_texture_array[SKILL2] = tlittle_razor_sharp;
            //super powers
            if(control.return_rounds_left_till_hero_ability_is_ready(hero_index_in_array, user_turn) == 0)
            {
               user_texture_array[SUPERPOWER] = tlittle_super_power_ready;
            }
            else if(control.return_rounds_left_till_hero_ability_is_ready(hero_index_in_array, user_turn) == 1)
            {
                user_texture_array[SUPERPOWER] = tlittle_super_power_1rounds_left;
            }
            else if(control.return_rounds_left_till_hero_ability_is_ready(hero_index_in_array, user_turn) == 2)
            {
                user_texture_array[SUPERPOWER] = tlittle_super_power_2rounds_left;
            }
            else if(control.return_rounds_left_till_hero_ability_is_ready(hero_index_in_array, user_turn) == 3)
            {
                user_texture_array[SUPERPOWER] = tlittle_super_power_not_ready;
            }
            
            break;
        
        case POUYA_KAJDOM:
            user_texture_array[SKILL1] = pouya_dagger;
            user_texture_array[SKILL2] = pouya_scorpion;
            //super powers
            if(control.return_rounds_left_till_hero_ability_is_ready(hero_index_in_array, user_turn) == 0)
            {
               user_texture_array[SUPERPOWER] = pouya_super_power_ready;
            }
            else if(control.return_rounds_left_till_hero_ability_is_ready(hero_index_in_array, user_turn) == 1)
            {
                user_texture_array[SUPERPOWER] = pouya_super_power_1rounds_left;
            }
            else if(control.return_rounds_left_till_hero_ability_is_ready(hero_index_in_array, user_turn) == 2)
            {
                user_texture_array[SUPERPOWER] = pouya_super_power_2rounds_left;
            }
            else if(control.return_rounds_left_till_hero_ability_is_ready(hero_index_in_array, user_turn) == 3)
            {
                user_texture_array[SUPERPOWER] = pouya_super_power_3rounds_left;
            }
            else if(control.return_rounds_left_till_hero_ability_is_ready(hero_index_in_array, user_turn) == 4)
            {
                user_texture_array[SUPERPOWER] = pouya_super_power_not_ready;
            }
            break;
    }    
}

void game_screen_draw_abilities_grayed_out(const std::array<Texture2D,3>& textures, const Rectangle & skill1_bound, const Rectangle& skill2_bound, const Rectangle& superpower_bound)
{
    DrawTexture(textures[SKILL1],skill1_bound.x,skill1_bound.y,GRAY);
    DrawTexture(textures[SKILL2],skill2_bound.x,skill2_bound.y,GRAY);
    DrawTexture(textures[SUPERPOWER],superpower_bound.x, superpower_bound.y,GRAY);
            
}

void highlight_ability(const std::array<Texture2D, 3>& textures, const Rectangle & skill1_bound, const Rectangle& skill2_bound, const Rectangle& superpower_bound,ABILITIES skill_to_be_highlighted)
{
    switch (skill_to_be_highlighted)
    {
    case SKILL1:
        DrawTexture(textures[SKILL1],skill1_bound.x,skill1_bound.y,WHITE);
        break;
    
    case SKILL2:
        DrawTexture(textures[SKILL2],skill2_bound.x,skill2_bound.y,WHITE);
        break;
    
    case SUPERPOWER:
        DrawTexture(textures[SUPERPOWER],superpower_bound.x, superpower_bound.y,WHITE);
        break;
    
    default:
        break;
    }
}

void display_ability_defenition_and_detail(const std::array<int,3>& user_hero_array, int user_turn, int hero_index_in_array, ABILITIES which_ability, Font font, Color color)
{
    DrawTextEx(font, "ENERGY REQUIRED", {127.0f - (MeasureTextEx(font,"ENERGY REQUIRED",20.0f,0).x/2),540.0f}, 20.0f, 0.0f,  color);

    switch (user_hero_array[hero_index_in_array])
    {
    case DANI_GOLANG:
        if(which_ability == SKILL1)
        {
            DrawTextEx(font, "FIL KOSH ", {260, 520}, 35,0, color);
            DrawTextEx(font, "DEALS 50 POINTS OF DAMAGE TO THE CHOSEN ENEMY AND THE ENEMY WITH THE HIGHEST HP", {260, 555},15,0, color);
            //extra detail
            DrawTextEx(font, "4 POINTS", {127.0f - (MeasureTextEx(font,"4 POINTS", 20, 0).x /2), 560}, 20, 0,  color);
        }
        else if(which_ability == SKILL2)
        {
            DrawTextEx(font, "THE LOCK: ", {260, 520}, 35,0, color);
            DrawTextEx(font, "DEALS 20 POINTS OF DAMAGE TO THE CHOSEN ENEMY CONSECUTIVE ATTACK TO THE SAME ENEMY INCREASES DAMAGE BY 60%", {260, 555},15,0, color);
            //extra detail
            DrawTextEx(font, "2 POINTS", {127.0f - (MeasureTextEx(font,"2 POINTS", 20, 0).x /2), 560}, 20, 0,  color);
        }
        if(which_ability == SUPERPOWER)
        {
            DrawTextEx(font, "TRENCHES: ", {260, 520}, 35,0, color);
            DrawTextEx(font, "GIVES 250 SHIELD POINTS TO THE LOWEST HP TEAMMATE AND THE EFFECT LASTS FOR 2 ROUNDS", {260, 555},15,0, color);
            //extra detail
            DrawTextEx(font, "4 POINTS", {127.0f - (MeasureTextEx(font,"4 POINTS", 20, 0).x /2), 560}, 20, 0,  color);
        }
        break;
    
    case AMIN_EMENI:
        if(which_ability == SKILL1)
        {
            DrawTextEx(font, "FRIENDLY FIRE:", {260, 520}, 35,0, color);
            DrawTextEx(font, "DEALS 25 POINTS OF DAMAGE TO A RANDOM TEAMMATES AND HEALS HIMSELF BY 75 HP", {260, 555},15,0, color);
            //extra detail
            DrawTextEx(font, "3 POINTS", {127.0f - (MeasureTextEx(font,"3 POINTS", 20, 0).x /2), 560}, 20, 0,  color);
        }
        else if(which_ability == SKILL2)
        {
            DrawTextEx(font, "LAST BULLET: ", {260, 520}, 35,0, color);
            DrawTextEx(font, "DEALS 55 POINTS OF DAMAGE TO THE CHOSEN ENEMY. KILLING THE ENEMY DOUBLES AMIN'S DAMAGE", {260, 555},15,0, color);
            //extra detail
            DrawTextEx(font, "3 POINTS", {127.0f - (MeasureTextEx(font,"3 POINTS", 20, 0).x /2), 560}, 20, 0,  color);
        }
        if(which_ability == SUPERPOWER)
        {
            DrawTextEx(font, "THE SHOUT: ", {260, 520}, 35,0, color);
            DrawTextEx(font, "DEALS 250 POINTS OF DAMAGE TO A RANDOM ENEMY BUT ALSO DAMAGES BOTH TEAMMATES BY 30 POINTS", {260, 555},15,0, color);
            //extra detail
            DrawTextEx(font, "4 POINTS", {127.0f - (MeasureTextEx(font,"4 POINTS", 20, 0).x /2), 560}, 20, 0,  color);
        }
        break;
    
    case AGHA_SHAHRIAR:
        if(which_ability == SKILL1)
        {
            DrawTextEx(font, "THE DUMMY:", {260, 520}, 35,0, color);
            DrawTextEx(font, "DEALS 60 POINTS OF DAMAGE TO A CHOSEN ENEMY WITH A 20\% CHANCE OF MISSING THE SHOT", {260, 555},15,0, color);
            //extra detail
            DrawTextEx(font, "2 POINTS", {127.0f - (MeasureTextEx(font,"2 POINTS", 20, 0).x /2), 560}, 20, 0,  color);
        }
        else if(which_ability == SKILL2)
        {
            DrawTextEx(font, "THE STUBBORN: ", {260, 520}, 35,0, color);
            DrawTextEx(font, "DEALS 100 POINTS OF DAMAGE TO A RANDOM ENEMY ANYONE BUT THE CHOSEN ENEMY", {260, 555},15,0, color);
            //extra detail
            DrawTextEx(font, "4 POINTS", {127.0f - (MeasureTextEx(font,"4 POINTS", 20, 0).x /2), 560}, 20, 0,  color);
        }
        if(which_ability == SUPERPOWER)
        {
            DrawTextEx(font, "THE REVERSION: ", {260, 520}, 35,0, color);
            DrawTextEx(font, "HEALING ABILITIES DAMAGE TEAMMATES AND ATTACKING ABILITIES HEAL ENEMIES FOR 2ROUNDS", {260, 555},15,0, color);
            //extra detail
            DrawTextEx(font, "8 POINTS", {127.0f - (MeasureTextEx(font,"8 POINTS", 20, 0).x /2), 560}, 20, 0,  color);
        }
        break;
    
    case POUYA_KAJDOM:
        if(which_ability == SKILL1)
        {
            DrawTextEx(font, "THE DAGGER:", {260, 520}, 35,0, color);
            DrawTextEx(font, "DEALS 20 POINTS OF DAMAGE TO THE CHOSEN ENEMY AND BUFFS THE SCORPION DAMAGE BY 40 POINTS ON THAT ENEMY", {260, 555},15,0, color);
            //extra detail
            DrawTextEx(font, "2 POINTS", {127.0f - (MeasureTextEx(font,"2 POINTS", 20, 0).x /2), 560}, 20, 0,  color);
        }
        else if(which_ability == SKILL2)
        {
            DrawTextEx(font, "THE SCORPION: ", {260, 520}, 35,0, color);
            DrawTextEx(font, "PUTS A SCORPION ON THE CHOSEN ENEMY WHICH DEALS 20 POINTS OF DAMAGE PER ROUND ", {260, 555},15,0, color);
            //extra detail
            DrawTextEx(font, "4 POINTS", {127.0f - (MeasureTextEx(font,"4 POINTS", 20, 0).x /2), 560}, 20, 0,  color);
        }
        if(which_ability == SUPERPOWER)
        {
            DrawTextEx(font, "THE VENOMOUS BITE: ", {260, 520}, 35,0, color);
            DrawTextEx(font, "HIDES FOR 3 ROUNDS (CAN'T BE DIRECTLY TARGETED BY ENEMIES) AND DEALS 450 POINTS OF DAMAGE TO A RANDOM ENEMY WHEN THE 3 ROUNDS ARE OVER", {260, 555},15,0, color);
            //extra detail
            DrawTextEx(font, "5 POINTS", {127.0f - (MeasureTextEx(font,"5 POINTS", 20, 0).x /2), 560}, 20, 0,  color);
        }
        break;
    
    case TAHA_BOZORGE:
        if(which_ability == SKILL1)
        {
            DrawTextEx(font, "THE MACHINE GUN:", {260, 520}, 35,0, color);
            DrawTextEx(font, "DEALS 30 POINTS OF DAMAGE TO EVERY ENEMY", {260, 555},15,0, color);
            //extra detail
            DrawTextEx(font, "3 POINTS", {127.0f - (MeasureTextEx(font,"3 POINTS", 20, 0).x /2), 560}, 20, 0,  color);
        }
        else if(which_ability == SKILL2)
        {
            DrawTextEx(font, "XRAY: ", {260, 520}, 35,0, color);
            DrawTextEx(font, "DEALS 90 POINTS OF DAMAGE TO THE CHOSEN ENEMY AND HIDES FOR ONE ROUND (CAN'T BE TARGETED DIRECTLY)", {260, 555},15,0, color);
            //extra detail
            DrawTextEx(font, "4 POINTS", {127.0f - (MeasureTextEx(font,"4 POINTS", 20, 0).x /2), 560}, 20, 0,  color);
        }
        if(which_ability == SUPERPOWER)
        {
            DrawTextEx(font, "REVENGE: ", {260, 520}, 35,0, color);
            DrawTextEx(font, "MARKS A RANDOM ENEMY TO DEAL 360 POINTS OF DAMAGE TO IN THE NEXT ROUND. IF THE MARKED ENEMY'S HP IS OVER 360 THE DAMAGE WILL BE REDUCED TO 200 POINTS", {260, 555},15,0, color);
            //extra detail
            DrawTextEx(font, "3 POINTS", {127.0f - (MeasureTextEx(font,"3 POINTS", 20, 0).x /2), 560}, 20, 0,  color);
        }
        break;
    
    case TAHA_KOCHIKE:
        if(which_ability == SKILL1)
        {
            DrawTextEx(font, "THE MACHINE GUN:", {260, 520}, 35,0, color);
            DrawTextEx(font, "DEALS 30 POINTS OF DAMAGE TO EVERY ENEMY", {260, 555},15,0, color);
            //extra detail
            DrawTextEx(font, "3 POINTS", {127.0f - (MeasureTextEx(font,"3 POINTS", 20, 0).x /2), 560}, 20, 0,  color);
        }
        else if(which_ability == SKILL2)
        {
            DrawTextEx(font, "XRAY: ", {260, 520}, 35,0, color);
            DrawTextEx(font, "DEALS 90 POINTS OF DAMAGE TO THE CHOSEN ENEMY AND HIDES FOR ONE ROUND (CAN'T BE TARGETED DIRECTLY)", {260, 555},15,0, color);
            //extra detail
            DrawTextEx(font, "4 POINTS", {127.0f - (MeasureTextEx(font,"4 POINTS", 20, 0).x /2), 560}, 20, 0,  color);
        }
        if(which_ability == SUPERPOWER)
        {
            DrawTextEx(font, "REVENGE: ", {260, 520}, 35,0, color);
            DrawTextEx(font, "MARKS A RANDOM ENEMY TO DEAL 360 POINTS OF DAMAGE TO IN THE NEXT ROUND. IF THE MARKED ENEMY'S HP IS OVER 360 THE DAMAGE WILL BE REDUCED TO 200 POINTS", {260, 555},15,0, color);
            //extra detail
            DrawTextEx(font, "3 POINTS", {127.0f - (MeasureTextEx(font,"3 POINTS", 20, 0).x /2), 560}, 20, 0,  color);
        }
        break;
    
    case WHITEDOCTOR:
        if(which_ability == SKILL1)
        {
            DrawTextEx(font, "ASPRIN:", {260, 520}, 35,0, color);
            DrawTextEx(font, "DEALS 40 POINTS OF DAMAGE TO THE CHOSEN ENEMY AND HEALS A RANDOM TEAMMATE BY 40 POINTS", {260, 555},15,0, color);
            //extra detail
            DrawTextEx(font, "3 POINTS", {127.0f - (MeasureTextEx(font,"3 POINTS", 20, 0).x /2), 560}, 20, 0,  color);
        }
        else if(which_ability == SKILL2)
        {
            DrawTextEx(font, "DOPING: ", {260, 520}, 35,0, color);
            DrawTextEx(font, "BUFFS ONE TEAMMATE ATTACKING DAMAGE BY 20 POINTS FOR 2ROUNDS ", {260, 555},15,0, color);
            //extra detail
            DrawTextEx(font, "4 POINTS", {127.0f - (MeasureTextEx(font,"4 POINTS", 20, 0).x /2), 560}, 20, 0,  color);
        }
        if(which_ability == SUPERPOWER)
        {
            DrawTextEx(font, "REVIVAL: ", {260, 520}, 35,0, color);
            DrawTextEx(font, "MARKS A RANDOM ENEMY TO DEAL 360 POINTS OF DAMAGE TO IN THE NEXT ROUND. IF THE MARKED ENEMY'S HP IS OVER 360 THE DAMAGE WILL BE REDUCED TO 200 POINTS", {260, 555},15,0, color);
            //extra detail
            DrawTextEx(font, "4 POINTS", {127.0f - (MeasureTextEx(font,"3 POINTS", 20, 0).x /2), 560}, 20, 0,  color);
        }
        break;
    
    }
}

void Game::highlight_enemy(const std::array <int, 3>& user1_hero_arr, const std::array <int, 3>& user2_hero_arr, int user_turn, int enemy_to_be_highlighted, Color color)
{   
    if(user_turn == USER1)
    { 
        switch (user2_hero_arr[enemy_to_be_highlighted])
        {
            case WHITEDOCTOR:
                DrawTextureRec(Doc_anim_texture,{0,0, 164,characters_sprite_sheets_frame_height}, {1000.0f - (350 - (100 * (enemy_to_be_highlighted % 2))), 80.0f + (enemy_to_be_highlighted * 50)},  color);
                break;
            
            case DANI_GOLANG:
                DrawTextureRec(Dani_anim_texture,{0,0, 136,characters_sprite_sheets_frame_height}, {1000.0f - (350 - (100 * (enemy_to_be_highlighted % 2))), 80.0f + (enemy_to_be_highlighted * 50)},  color);
                break;
            
            case AMIN_EMENI:
                DrawTextureRec(Amin_anim_texture,{0,0, 145,characters_sprite_sheets_frame_height}, {1000.0f - (350 - (100 * (enemy_to_be_highlighted % 2))), 80.0f + (enemy_to_be_highlighted * 50)},  color);
                break;
            
            case POUYA_KAJDOM:
                DrawTextureRec(Pouya_anim_texture,{0,0, 120,characters_sprite_sheets_frame_height}, {1000.0f - (350 - (100 * (enemy_to_be_highlighted % 2))), 80.0f + (enemy_to_be_highlighted * 50)},  color);
                break;
            
            case AGHA_SHAHRIAR:
                DrawTextureRec(Shahriar_anim_texture,{0,0, 160,characters_sprite_sheets_frame_height}, {1000.0f - (350 - (100 * (enemy_to_be_highlighted % 2))), 80.0f + (enemy_to_be_highlighted * 50)},  color);
                    break;
            
            case TAHA_KOCHIKE:
                DrawTextureRec(Tlittle_anim_texture,{0,0, 185,characters_sprite_sheets_frame_height}, {1000.0f - (350 - (100 * (enemy_to_be_highlighted % 2))), 80.0f + (enemy_to_be_highlighted * 50)},  color);
                break;
            
            case TAHA_BOZORGE:
                DrawTextureRec(Tbig_anim_texture,{0,0, 135,characters_sprite_sheets_frame_height}, {1000.0f - (350 - (100 * (enemy_to_be_highlighted % 2))), 80.0f + (enemy_to_be_highlighted * 50)},  color);
                break;
            
        }
    }  
    
    
    else if(user_turn == USER2)
    { 
        switch (user1_hero_arr[enemy_to_be_highlighted])
        {
            case WHITEDOCTOR:
                DrawTextureRec(Doc_anim_texture,{0,0, -164,characters_sprite_sheets_frame_height}, {180.0f - (100 * (enemy_to_be_highlighted % 2)), 80.0f + (enemy_to_be_highlighted * 50)}, color);
                break;
            
            case DANI_GOLANG:
                DrawTextureRec(Dani_anim_texture,{0,0, -136,characters_sprite_sheets_frame_height}, {180.0f - (100 * (enemy_to_be_highlighted % 2)), 80.0f + (enemy_to_be_highlighted * 50)}, color);
                break;
            
            case AMIN_EMENI:
                DrawTextureRec(Amin_anim_texture,{0,0, -145,characters_sprite_sheets_frame_height}, {180.0f - (100 * (enemy_to_be_highlighted % 2)), 80.0f + (enemy_to_be_highlighted * 50)}, color);
                break;
            
            case POUYA_KAJDOM:
                DrawTextureRec(Pouya_anim_texture,{0,0, -120,characters_sprite_sheets_frame_height}, {180.0f - (100 * (enemy_to_be_highlighted % 2)), 80.0f + (enemy_to_be_highlighted * 50)}, color);
                break;
            
            case AGHA_SHAHRIAR:
                DrawTextureRec(Shahriar_anim_texture,{0,0, -160,characters_sprite_sheets_frame_height}, {180.0f - (100 * (enemy_to_be_highlighted % 2)), 80.0f + (enemy_to_be_highlighted * 50)}, color);
                    break;
            
            case TAHA_KOCHIKE:
                DrawTextureRec(Tlittle_anim_texture,{0,0, -185,characters_sprite_sheets_frame_height}, {180.0f - (100 * (enemy_to_be_highlighted % 2)), 80.0f + (enemy_to_be_highlighted * 50)}, color);
                break;
            
            case TAHA_BOZORGE:
                DrawTextureRec(Tbig_anim_texture,{0,0, -135,characters_sprite_sheets_frame_height}, {180.0f - (100 * (enemy_to_be_highlighted % 2)), 80.0f + (enemy_to_be_highlighted * 50)}, color);
                break;
            
        }
    }  
}
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
    
    
    //user info
    static char user1_name[26];
    static char user2_name[26];
    static std::array <int, 3> user1_hero_arr;
    static std::array <int, 3> user2_hero_arr;
    static Vector2 User1_name_size;
    static Vector2 User2_name_size;
    static char user1_energy[10] = {};
    static char user2_energy[10] = {};
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
    



    Mouse_Positon = GetMousePosition();
    
    
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
        if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && !is_mouse_hovering_over_abilities)
        {

            should_hero_be_animated = false;
            hero_to_be_animated_index = 4;
        }
    }


    //turning off the highlighted ability if necessary
    if(!is_mouse_hovering_over_abilities && !is_mouse_hovering_over_enemy)
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
            ability_to_be_highlighted = NON;
            should_ability_be_highlighted = false; 
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
                    if(IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
                    {
                        should_execute_ability = true;
                    }
                }
                //checking to see end turn button has been pressed or not
                else if(CheckCollisionPointRec(Mouse_Positon, End_turn_button_bound))
                {
                    DrawTexture(end_turn_texture, End_turn_button_bound.x, End_turn_button_bound.y, WHITE);  
                    if(IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
                    {
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
                    if(IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
                    {
                        should_execute_ability = true;
                    }
                }
                else if(CheckCollisionPointRec(Mouse_Positon, End_turn_button_bound))
                {
                    DrawTextureEx(end_turn_texture, {End_turn_button_bound.x, End_turn_button_bound.y}, 0, 0, WHITE);
                    if(IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
                    {
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

    if(should_end_turn || control.should_change_turn(User_Turn, user1.Get_Energy(), user2.Get_Energy()))
    {
        if(User_Turn == USER1)
        {
            //changing every logic variable to the default for the next player
            User_Turn = USER2;
            should_end_turn = false;
            hero_to_be_animated_index = 4;
            should_ability_be_highlighted = false;
            should_hero_be_animated = false;
            user1_hero_to_be_highlighted_index = 4;
            ability_to_stay_highlighted = NON;
        }
        else if(User_Turn == USER2)
        {
            User_Turn = USER1;
            should_end_turn = false;
            hero_to_be_animated_index = 4;
            should_ability_be_highlighted = false;
            should_hero_be_animated = false;
            user2_hero_to_be_highlighted_index = 4;
            ability_to_stay_highlighted = NON;
            //new round
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


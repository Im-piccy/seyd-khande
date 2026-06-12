#ifndef INCLUDE_IN_CHARACTER_SELECT_SCREEN_FILE_HPP
#define INCLUDE_IN_CHARACTER_SELECT_SCREEN_FILE_HPP
#include "enums.hpp"
#include <array>
#include <string>
#include "../raylib/include/raylib.h"


struct Texture_with_bound 
{
    Texture2D texture;
    Rectangle bound;
    
};



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



int Change_temperory_hero_selected(int hero , int current)
{
    if(IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
    {
        return hero;
    }
    return current;

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




bool Is_name_string_more_then_25_characters(const std::string st)
{
    if(st.length() >= 25)
    {
        return true;
    }
    return false;
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


void string_to_char_array(const std::string& st, char out[])//string should not have more than 25 characters
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



void show_name_character_limit_error_message_on_screen(Font out_font)
{
    Vector2 Text_size = MeasureTextEx(out_font, "Name can't be more than 25 characters long!", 18, 0);
    DrawTextEx(out_font,"Name can't be more than 25 characters long!",{(500 - (Text_size.x / 2)), 360}, 18, 0,RED);
}


#endif
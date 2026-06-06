#ifndef GAME_HPP
#define GAME_HPP
#include "controller.hpp"
#include "user.hpp"
#include <raylib.h>
enum SCREENS{MENU_SCREEN, CHARACTER_SELECT_SCREEN, GAME_SCREEN, GAME_OVER_SCREEN, WINDOWSHOULDCLOSE};
enum TURN{USER1, USER2};

//this class actually runs the game and ties everything together

class Game
{
    
    public:    
        Game();
        void print_characters_gaurd_pose_on_screen_according_to_user_array();
        bool Manage_Screens();
        void Menu_Screen();
        void Character_Select_Screen();
        void Game_Screen();
        void load_animation_sprite_sheets();
        void unload_animation_sprite_sheets();
        void print_heros_on_screen_idle_and_highlight_hero_which_is_hoverd(const std::array <int,3>& user1_heros, const std::array <int,3>&  user2_heros, int index, int user_turn,bool should_highlight,int hero_being_hoverd);  
        Texture2D return_texture_based_on_arguments_passed(const std::array <int,3>& user1_hero_arr, const std::array <int,3>& user2_hero_arr,int user_turn, int hero_index_in_array);
        //bool Game_Over_Screen();
    private:
        int current_screen;
        User user1;
        User user2;
        Controller control;

        Texture2D Doc_anim_texture;
        Texture2D Dani_anim_texture;
        Texture2D Amin_anim_texture; 
        Texture2D Tlittle_anim_texture;
        Texture2D Tbig_anim_texture;
        Texture2D Pouya_anim_texture;
        Texture2D Shahriar_anim_texture;
};

#endif
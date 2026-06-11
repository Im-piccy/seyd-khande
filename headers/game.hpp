#ifndef GAME_HPP
#define GAME_HPP
#include "controller.hpp"
#include "user.hpp"
#include <raylib.h>


//this class actually runs the game and ties everything together

class Game
{
    
    public:    
        Game();
        bool Manage_Screens();
        void Menu_Screen();
        void Character_Select_Screen();
        void Game_Screen();
        void load_game_screen_animation_sprite_sheets();
        void unload_game_screen_animation_sprite_sheets();
        void print_heros_on_screen_idle_and_highlight_hero_which_is_hoverd(const std::array <int,3>& user1_heros, const std::array <int,3>&  user2_heros, int index, int user_turn,bool should_highlight,int user1_hero_being_hovered, int user2_hero_being_hoverd, int hero_to_be_animated_index); 
        void load_game_screen_abilities_textures();
        void unload_game_screen_abilities_textures();
        Texture2D return_animation_texture_based_on_arguments_passed(const std::array <int,3>& user1_hero_arr, const std::array <int,3>& user2_hero_arr,int user_turn, int hero_index_in_array);
        void return_skill_texture_based_on_arguments_passed_onto_the_texture_array_passed_to_the_funtion(const std::array<int,3>& user_hero_array,  std::array <Texture2D, 3>& user_texture_array, int user_turn, int hero_index_in_array);// pass a texture 2d array to this function by refrence and it will fill it for you
        void highlight_enemy(const std::array <int, 3>& user1_hero_array, const std::array <int, 3>& user2_hero_array, int user_turn, int enemy_to_be_highlighted, Color color = WHITE);
        //bool Game_Over_Screen();
    private:
        int current_screen;
        User user1;
        User user2;
        Controller control;

        //game screen animation textures
        Texture2D Doc_anim_texture;
        Texture2D Dani_anim_texture;
        Texture2D Amin_anim_texture; 
        Texture2D Tlittle_anim_texture;
        Texture2D Tbig_anim_texture;
        Texture2D Pouya_anim_texture;
        Texture2D Shahriar_anim_texture;

        //game screen abilities textures
        Texture2D Dani_fil_kosh;
        Texture2D Dani_lock;
        Texture2D Dani_super_power_3rounds_left;
        Texture2D Dani_super_power_2rounds_left;
        Texture2D Dani_super_power_1rounds_left;
        Texture2D Dani_super_power_ready;
        Texture2D Dani_super_power_not_ready;
        
        Texture2D amin_friendly_fire;
        Texture2D amin_last_bullet;
        Texture2D amin_super_power_2rounds_left;
        Texture2D amin_super_power_1rounds_left;
        Texture2D amin_super_power_ready;
        Texture2D amin_super_power_not_ready;

        Texture2D doc_asprin;
        Texture2D doc_doping;
        Texture2D doc_super_power_3rounds_left;
        Texture2D doc_super_power_2rounds_left;
        Texture2D doc_super_power_1rounds_left;
        Texture2D doc_super_power_ready;
        Texture2D doc_super_power_not_ready;
        
        Texture2D tlittle_razor_sharp;
        Texture2D tlittle_blood_bag;
        Texture2D tlittle_super_power_2rounds_left;
        Texture2D tlittle_super_power_1rounds_left;
        Texture2D tlittle_super_power_ready;
        Texture2D tlittle_super_power_not_ready;
        
        Texture2D tbig_machine_gun;
        Texture2D tbig_xray;
        Texture2D tbig_super_power_3rounds_left;
        Texture2D tbig_super_power_2rounds_left;
        Texture2D tbig_super_power_1rounds_left;
        Texture2D tbig_super_power_ready;
        Texture2D tbig_super_power_not_ready;
        
        Texture2D pouya_dagger;
        Texture2D pouya_scorpion;
        Texture2D pouya_super_power_3rounds_left;
        Texture2D pouya_super_power_2rounds_left;
        Texture2D pouya_super_power_1rounds_left;
        Texture2D pouya_super_power_ready;
        Texture2D pouya_super_power_not_ready;
        
        Texture2D shahriar_dummy;
        Texture2D shahriar_stubborn;
        Texture2D shahriar_super_power_3rounds_left;
        Texture2D shahriar_super_power_2rounds_left;
        Texture2D shahriar_super_power_1rounds_left;
        Texture2D shahriar_super_power_ready;
        Texture2D shahriar_super_power_not_ready;
        

    };

#endif
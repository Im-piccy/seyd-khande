#ifndef GAME_HPP
#define GAME_HPP
#include "controller.hpp"
#include "user.hpp"
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
       // bool Game_Screen();
        //bool Game_Over_Screen();
    private:
        int current_screen;
        User user1;
        User user2;
        Controller control;
};

#endif
#ifndef GAME_HPP
#define GAME_HPP
enum SCREENS{MENU_SCREEN, CHARACTER_SELECT_SCREEN, GAME_SCREEN, GAME_OVER_SCREEN};

//this class actually runs the game and ties everything together

class Game
{
    public:    
        Game();
        bool Manage_Screens();
        void Menu_Screen();
        //bool Character_Select_Screen();
       // bool Game_Screen();
        //bool Game_Over_Screen();
    private:
        int current_screen;
};

#endif
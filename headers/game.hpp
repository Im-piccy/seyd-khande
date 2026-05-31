#ifndef GAME_HPP
#define GAME_HPP
enum SCREENS{MENU_SCREEN, CHARACTER_SELECT_SCREEN, GAME_SCREEN, GAME_OVER_SCREEN};

//this class actually runs the game and ties everything together

class Game
{
    public:    
        Game();
        void Manage_Screens();
        void Menu_Screen();
        void Character_Select_Screen();
        void Game_Screen();
        void Game_Over_Screen();
    private:
        int current_screen;
};

#endif
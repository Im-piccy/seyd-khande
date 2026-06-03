#ifndef CONTROLLER_HPP
#define CONTROLLER_HPP
#include <array>

//declare to avoid compile time error
class User;
class Hero_Abstaction;


enum HERO_TYPE{NONSELECT, WHITEDOCTOR, TAHA_KOCHIKE, DANI_GOLANG, AMIN_EMENI, TAHA_BOZORGE, POUYA_KAJDOM, AGHA_SHAHRIAR};


class Controller
{
    public:
        bool Is_game_over(); // checks to see if game raound is 15 or one players heros are all dead
        void execute_user_ask_to_use_hero_ability_if_possible(); //it gets user request to atteck and does the logic (considering energy cost)
        void Refill_Players_Energy(); // after each round ends it refill energies accordingly
        void Finish_Round(); // this function increments the private round_number variable by one
        void manage_chosing_character_screen_logic();//this function instantiates objects and let users pick their heros
        void Empty_User_Array(User &user);
        bool Is_Hero_Array_Full(User &user);
        void Fill_Hero_object_Array(int user_number, int index, HERO_TYPE hero_type);
        void Fill_Hero_object_Array(std::array<Hero_Abstaction*,3>, int index, HERO_TYPE hero_type);
        void Set_User_Hero_Array_Index(int index);
        //~Controller();
        
    private:
        int round_number; // to keep track of the current game round
        int which_user_started_the_game; // to remember which user started first
        std::array<Hero_Abstaction*,3> Hero_Arr_User1;
        std::array<Hero_Abstaction*,3> Hero_Arr_User2;
};  
#endif

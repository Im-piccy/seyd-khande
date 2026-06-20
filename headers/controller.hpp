#ifndef CONTROLLER_HPP
#define CONTROLLER_HPP
#include <array>
#include <typeinfo>
#include <iostream>
#include "enums.hpp"
//declare to avoid compile time error
class User;
class Hero_Abstaction;


class Controller
{
    public:
        Controller();
        bool Is_game_over(User &user1, User &user); // checks to see if game raound is 15 or one players heros are all dead
        std::string Return_Name_Of_Winner() const;
        void execute_user_ask_to_use_hero_ability_if_possible(int selected_enemy_index, Argument_Skills_Functions &parameters, int hero_index_in_array, ABILITIES which_ability, int user_turn, User &user1, User &user2, std::array<int,3> hero_arr_user1, std::array<int,3> hero_arr_user2); //it gets user request to atteck and does the logic (considering energy cost)
        void Refill_Players_Energy(User &user, User &usr); // after each round ends it refill energies accordingly
        void Finish_Round(); // this function increments the private round_number variable by one
        void Empty_User_Array(User &user);
        bool Is_Hero_Array_Full(User &user);
        void Fill_Struct_For_Virtual_Functions(int user_turn, int selected_enemy_index, Argument_Skills_Functions& parameters, User &user1, User &user2);
        void Fill_Hero_object_Array(TURN user, int index, int hero_type);
        void Fill_Hero_object_Array(std::array<Hero_Abstaction*,3>&, int index, int hero_type);
        int return_round_number();
        int return_rounds_left_till_hero_ability_is_ready(int array_index, int user);
        void Empty_Array_Which_Stores_Hero_Base_Class_Pointers(TURN user_turn, int filled_to_which_index);
        bool can_ability_be_used_based_on_energy_points(int hero_index_in_array, ABILITIES which_ability, int user_turn , int user1_current_energy, int user2_current_energy);
        bool should_change_turn(int user_turn, int user1_current_energy, int user2_current_energy);
        int return_user_whom_started_the_game_as_an_int() const;
        int return_hero_hp(int user_turn, int hero_index);

        //for the superpower of agha_shahriar
        void Activate_Reverse_World();
        void Update_Reverse_World();
        void Apply_Healed(Hero_Abstaction* ally, int healing_points);
        void Apply_Damaged(Hero_Abstaction* enemy, int damaging_point);

        //for the doping power of whitedoctor
        void Updated_Doping_Status();
        //for the serom_khon power of taha_kochike
        void Updated_Serom_Khon_Status();
        //for the family stronghold super power of dani_golang
        void Updated_Family_StrongHold_Status();
        //for the ghofli power of dani_golang
        void Updated_Ghofli_Status();
        //for the brother revenge super power of taha_bozorge
        void Updated_Brother_Revenge_Status();
        //for the dom kajdom super power of pouya_kajdom
        void Updated_Dom_Kajdom_Status();
        bool Check_pouya_kajdom_between_selected_heroes(int usre_turn, int hero_index_in_array, std::array<int,3> hero_arr_user1, std::array<int,3> hero_arr_user2);
        
        ~Controller();
        
    private:
        int round_number; // to keep track of the current game round
        int which_user_started_the_game; // to remember which user started first
        std::string Winner_Name;
        std::array<Hero_Abstaction*,3> Hero_Arr_User1;
        std::array<Hero_Abstaction*,3> Hero_Arr_User2;

        //for the suoerpower of agha_shahriar
        bool Reverse_World_Active;
        int Reverse_World_Rounds_Left;
    };  
    
#endif

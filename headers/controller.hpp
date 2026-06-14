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
        bool Is_game_over(int user_turn); // checks to see if game raound is 15 or one players heros are all dead
        void execute_user_ask_to_use_hero_ability_if_possible(int selected_enemy_index, int selected_ally_index, Argument_Skills_Functions &parameters, int hero_index_in_array, ABILITIES which_ability, int user_turn, User &user1, User &user2); //it gets user request to atteck and does the logic (considering energy cost)
        void Refill_Players_Energy(); // after each round ends it refill energies accordingly
        void Finish_Round(); // this function increments the private round_number variable by one
        void Empty_User_Array(User &user);
        bool Is_Hero_Array_Full(User &user);
        void Fill_Struct_For_Virtual_Functions(int user_turn, int selected_enemy_index, int selected_ally_index, Argument_Skills_Functions& parameters, User &user1, User &user2);
        void Fill_Hero_object_Array(TURN user, int index, int hero_type);
        void Fill_Hero_object_Array(std::array<Hero_Abstaction*,3>&, int index, int hero_type);
        int return_round_number();
        int return_rounds_left_till_hero_ability_is_ready(int array_index, int user);
        void Empty_Array_Which_Stores_Hero_Base_Class_Pointers(TURN user_turn, int filled_to_which_index);
        bool can_ability_be_used_based_on_energy_points(int hero_index_in_array, ABILITIES which_ability, int user_turn , int user1_current_energy, int user2_current_energy);
        bool should_change_turn(int user_turn, int user1_current_energy, int user2_current_energy);
        int return_user_whom_started_the_game_as_an_int() const;

        //for the superpower of agha_shahriar
        bool Is_Reverse_World_Active();
        void Activate_Reverse_World();
        void Update_Reverse_World();
        void Apply_Healed(Hero_Abstaction* ally, int healing_points);
        void Apply_Damaged(Hero_Abstaction* enemy, int damaging_point);
        
        ~Controller();
        
    private:
        int round_number; // to keep track of the current game round
        int which_user_started_the_game; // to remember which user started first
        std::array<Hero_Abstaction*,3> Hero_Arr_User1;
        std::array<Hero_Abstaction*,3> Hero_Arr_User2;

        //for the suoerpower of agha_shahriar
        bool Reverse_World_Active;
        int Reverse_World_Rounds_Left;
    };  
    
#endif

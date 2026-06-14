#include "../headers/controller.hpp"
#include "../headers/hero_sub_class_to_instatniate_objects.hpp"
#include "../headers/game.hpp"
#include "../headers/user.hpp"
#include <ctime>
#include <random>
#include <iostream>


Controller::Controller()
{
    this->round_number = 1;
    srand(time(0));
    this->which_user_started_the_game = rand() % 2;

    for(int i = 0 ; i < 3 ; i++)
    {
        Hero_Arr_User1[i] = nullptr;
        Hero_Arr_User2[i] = nullptr;
    }
    //for agha_shahriar
    this->Reverse_World_Active = false;
    this->Reverse_World_Rounds_Left = 0;
}


void Controller::Empty_User_Array(User &user)
{
    user.Hero_Arr.fill(0);
}

bool Controller::Is_Hero_Array_Full(User &user)
{
    
    for(int i = 0; i < 3; i++)
    {
        if(user.Hero_Arr[i] == 0)
            return false;
    }
    return true;
} 


void Controller::Fill_Hero_object_Array(std::array<Hero_Abstaction*,3>& hero_arr, int index, int hero_type)
{
    switch (hero_type)
    {
        case WHITEDOCTOR:
            hero_arr[index] = new WhiteDoctor;  
            break;
        case TAHA_KOCHIKE:
            hero_arr[index] = new Taha_Kochike; 
            break;
        case DANI_GOLANG:
            hero_arr[index] = new Dani_Golang; 
            break;
        case AMIN_EMENI:
            hero_arr[index] = new Amin_Emeni; 
            break;
        case TAHA_BOZORGE:
            hero_arr[index] = new Taha_Bozorge; 
            break;
        case POUYA_KAJDOM:
            hero_arr[index] = new Pouya_Kajdom; 
            break;
        case AGHA_SHAHRIAR:
            hero_arr[index] = new Agha_Shahriar; 
            break;
    }
}

//the following function is called three times for three indexes array 

void Controller::Fill_Hero_object_Array(TURN  user_number, int index, int hero_type)
{
    if(index < 0 || index >= 3)
        return;
    if(user_number == 0)
        Fill_Hero_object_Array(this->Hero_Arr_User1, index, hero_type);
    else if(user_number == 1)
        Fill_Hero_object_Array(this->Hero_Arr_User2, index, hero_type);   
}

Controller::~Controller()
{
    for( int i = 0; i < 3; i++)
    {
        delete Hero_Arr_User1[i];
        Hero_Arr_User1[i] = nullptr;
        
        delete Hero_Arr_User2[i];
        Hero_Arr_User2[i] = nullptr;
    }
}

int Controller::return_round_number()
{
    return round_number;
}

int Controller::return_rounds_left_till_hero_ability_is_ready(int array_index, int user)
{
    if(user == USER1)
    {
        return Hero_Arr_User1[array_index] ->return_rounds_left_till_superpower_is_ready();
    }
    else if(user == USER2)
    {
        return Hero_Arr_User2[array_index]->return_rounds_left_till_superpower_is_ready();
    }
}

void Controller::Empty_Array_Which_Stores_Hero_Base_Class_Pointers(TURN user_turn, int filled_to_which_index)
{
    switch (user_turn)
    {
    case USER1:
        for(int i = 0 ; i <= filled_to_which_index ; i++)
        {
            delete Hero_Arr_User1[i];
            Hero_Arr_User1[i] = nullptr;   
        }
        break;
    
    case USER2:
        for(int i = 0 ; i < filled_to_which_index ; i++)
        {
            delete Hero_Arr_User2[i];
            Hero_Arr_User2[i] = nullptr;   
        }
        break;
    
    }
}

bool Controller::can_ability_be_used_based_on_energy_points(int hero_index_in_array, ABILITIES which_ability, int user_turn , int user1_current_energy, int user2_current_energy)
{
    if(user_turn == USER1)
    {
        switch (which_ability)
        {
        case SKILL1:
            if(Hero_Arr_User1[hero_index_in_array]->Return_Skill1_Energy_Cost() <= user1_current_energy)
            {
                return true;
            }
            return false;
        
        case SKILL2:
            if(Hero_Arr_User1[hero_index_in_array]->Return_Skill2_Energy_Cost() <= user1_current_energy)
            {
                return true;
            }
            return false;
        
        case SUPERPOWER:
            if(Hero_Arr_User1[hero_index_in_array]->return_rounds_left_till_superpower_is_ready() != 0)
            {
                return false;
            }
            if(Hero_Arr_User1[hero_index_in_array]->Return_SuperPower_Energy_Cost() <= user1_current_energy)
            {
                return true;
            }
            return false;    
        
        
        }
    }
    else if(user_turn == USER2)
    {
        switch (which_ability)
        {
            case SKILL1:
                if(Hero_Arr_User2[hero_index_in_array]->Return_Skill2_Energy_Cost() <= user2_current_energy)
                {
                    return true;
                }
                return false;
            
            case SKILL2:
                if(Hero_Arr_User2[hero_index_in_array]->Return_Skill2_Energy_Cost() <= user2_current_energy)
                {
                    return true;
                }
                return false;
            
            case SUPERPOWER:
                if(Hero_Arr_User2[hero_index_in_array]->return_rounds_left_till_superpower_is_ready() != 0)
                {
                    return false;
                }
                if(Hero_Arr_User2[hero_index_in_array]->Return_SuperPower_Energy_Cost() <= user2_current_energy)
                {
                    return true;
                }
                return false;    
        }
    }
}

bool Controller::should_change_turn(int user_turn, int user1_current_energy, int user2_current_energy)
{
    if(user_turn == USER1)
    {
        for(int i = 0 ; i < 3 ; i++)
        {
            if(Hero_Arr_User1[i]->Return_Skill1_Energy_Cost() <= user1_current_energy)
            {
                return false;
            }
            if(Hero_Arr_User1[i]->Return_Skill2_Energy_Cost() <= user1_current_energy)
            {
                return false;
            }
            if(Hero_Arr_User1[i]->Return_SuperPower_Energy_Cost() <= user1_current_energy)
            {
                return false;
            }
        }
        return true;
    }
    else if (user_turn == USER2)
    {
        for(int i = 0 ; i < 3 ; i++)
        {
            if(Hero_Arr_User2[i]->Return_Skill1_Energy_Cost() <= user2_current_energy)
            {
                return false;
            }
            if(Hero_Arr_User2[i]->Return_Skill2_Energy_Cost() <= user2_current_energy)
            {
                return false;
            }
            if(Hero_Arr_User2[i]->Return_SuperPower_Energy_Cost() <= user2_current_energy)
            {
                return false;
            }
        }
        return true;
    }
}


bool Controller::Is_Reverse_World_Active()
{
    return this->Reverse_World_Active;
}

void Controller::Activate_Reverse_World()
{
    Reverse_World_Active = true;
    Reverse_World_Rounds_Left = 2;
}

void Controller::Update_Reverse_World()
{
    if(!Reverse_World_Active)
        return;

    Reverse_World_Rounds_Left--;

    if(Reverse_World_Rounds_Left <= 0)
    {
        Reverse_World_Active = false;
        Reverse_World_Rounds_Left = 0;
    }
}

void Controller::Apply_Healed(Hero_Abstaction* ally, int healing_points)
{
    if(ally == nullptr)
        return;
    if(Reverse_World_Active)
        ally->Get_Healed(healing_points);
    else
        ally->Get_Damaged(healing_points);
}

void Controller::Apply_Damaged(Hero_Abstaction* enemy, int damaging_point)
{

    if(enemy == nullptr)
        return;
    if(Reverse_World_Active)
        enemy->Get_Damaged(damaging_point);
    else
        enemy->Get_Healed(damaging_point);
}

void Controller::Finish_Round()
{
    if(round_number >= 15)
        return;
    round_number++;
}

bool Controller::Is_game_over(int user_turn)
{
    int count  = 0;
    if(user_turn == USER1)
    {
        for(int i = 0; i < 3; i++)
        {
            if(Hero_Arr_User1[i]->Is_Dead())
                count++;
        }
        if(round_number == 15 || count == 3)
            return true;
    }
    else
    {
        for(int i = 0; i < 3; i++)
        {
            if(Hero_Arr_User2[i]->Is_Dead())
                count++;
        }
        if(round_number == 15 || count == 3)
            return true;
    }
    return false;
}

void Controller::Fill_Struct_For_Virtual_Functions(int user_turn, int selected_enemy_index, int selected_ally_index, Argument_Skills_Functions& parameters, User &user1, User &user2)
{
    parameters.controller = this;
    if(user_turn == USER1)
    {
        for(int i = 0; i < 3; i++)
        {
            parameters.allies[i] = Hero_Arr_User1[i];
            parameters.enemies[i]= Hero_Arr_User2[i];
        }
        parameters.selected_ally_index = selected_ally_index;
        parameters.selected_enemy_index = selected_enemy_index;
        parameters.user =  &user1;
    }
    else 
    {
        for(int i = 0; i < 3; i++)
        {
            parameters.allies[i] = Hero_Arr_User2[i];
            parameters.enemies[i]= Hero_Arr_User1[i];
        }
        parameters.selected_ally_index = selected_ally_index;
        parameters.selected_enemy_index = selected_enemy_index;
        parameters.user =  &user2;
    }
}

void Controller::execute_user_ask_to_use_hero_ability_if_possible(int selected_enemy_index, int selected_ally_index, Argument_Skills_Functions &parameters, int hero_index_in_array, ABILITIES which_ability, int user_turn, User &user1, User &user2)
{
    Fill_Struct_For_Virtual_Functions(user_turn, selected_enemy_index, selected_ally_index, parameters, user1, user2);
    if(user_turn == USER1)
    {
        if(which_ability == SKILL1)
        {
            if(!Hero_Arr_User1[hero_index_in_array]->Is_Dead())
            {
                if(Hero_Arr_User1[hero_index_in_array]->Return_Skill1_Energy_Cost() > user1.Get_Energy())
                    Finish_Round();// i think you ment change turn
                else  
                    Hero_Arr_User1[hero_index_in_array]->Execute_Skill1(parameters);
            }
        }
        else if(which_ability == SKILL2)
        {
            if(!Hero_Arr_User1[hero_index_in_array]->Is_Dead())
            {
                if(Hero_Arr_User1[hero_index_in_array]->Return_Skill2_Energy_Cost() > user1.Get_Energy())
                    Finish_Round();
                else  
                    Hero_Arr_User1[hero_index_in_array]->Execute_Skill2(parameters);
            }
        }
        else if(which_ability == SUPERPOWER)
        {
            if(!Hero_Arr_User1[hero_index_in_array]->Is_Dead())
            {
                if(Hero_Arr_User1[hero_index_in_array]->Return_SuperPower_Energy_Cost() > user1.Get_Energy())
                    Finish_Round();
                else 
                    Hero_Arr_User1[hero_index_in_array]->Execute_SuperSkill(parameters);
            }
        }
    }
    else
    {
        if(which_ability == SKILL1)
        {
            if(!Hero_Arr_User2[hero_index_in_array]->Is_Dead())
            {
                if(Hero_Arr_User2[hero_index_in_array]->Return_Skill1_Energy_Cost() > user2.Get_Energy())
                    Finish_Round();
                else  
                    Hero_Arr_User2[hero_index_in_array]->Execute_Skill1(parameters);
            }
        }
        else if(which_ability == SKILL2)
        {
            if(!Hero_Arr_User2[hero_index_in_array]->Is_Dead())
            {
                if(Hero_Arr_User2[hero_index_in_array]->Return_Skill2_Energy_Cost() > user2.Get_Energy())
                    Finish_Round();
                else  
                    Hero_Arr_User2[hero_index_in_array]->Execute_Skill2(parameters);
            }
        }
        else if(which_ability == SUPERPOWER)
        {
            if(!Hero_Arr_User2[hero_index_in_array]->Is_Dead())
            {
                if(Hero_Arr_User2[hero_index_in_array]->Return_SuperPower_Energy_Cost() > user2.Get_Energy())
                    Finish_Round();
                else 
                    Hero_Arr_User2[hero_index_in_array]->Execute_SuperSkill(parameters);
            }
        }
    }
}


int Controller::return_user_whom_started_the_game_as_an_int() const
{
    return which_user_started_the_game;
}

void Controller::Refill_Players_Energy()
{

}


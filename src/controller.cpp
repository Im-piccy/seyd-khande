#include "../headers/controller.hpp"
#include "../headers/hero_sub_class_to_instatniate_objects.hpp"
#include "../headers/game.hpp"
#include "../headers/user.hpp"
#include <iostream>

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

void Controller::Set_User_Hero_Array_Index(int index)
{
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
    if(user_number == 1)
        Fill_Hero_object_Array(this->Hero_Arr_User1, index, hero_type);
    else
        Fill_Hero_object_Array(this->Hero_Arr_User2, index, hero_type);   
}

// Controller::~Controller()
// {
//     for( int i = 0; i < 3; i++)
//     {
//         delete Hero_Arr_User1[i];
//         Hero_Arr_User1[i] = nullptr;
        
//         delete Hero_Arr_User2[i];
//         Hero_Arr_User2[i] = nullptr;
//     }
// }

int Controller::return_round_number()
{
    return round_number;
}

int Controller::return_rounds_left_till_hero_ability_is_ready(int array_index, TURN user)
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
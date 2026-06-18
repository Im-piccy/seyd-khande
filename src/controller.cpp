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

void Controller::Activate_Reverse_World()// for superpower of joker
{
    Reverse_World_Active = true;
    Reverse_World_Rounds_Left = 2;
}

void Controller::Update_Reverse_World()// for superpower of joker
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

void Controller::Apply_Healed(Hero_Abstaction* ally, int healing_points)// for superpower of joker
{
    if(ally == nullptr)
        return;
    if(Reverse_World_Active)
        ally->Get_Damaged(healing_points);
    else
        ally->Get_Healed(healing_points);
}

void Controller::Apply_Damaged(Hero_Abstaction* enemy, int damaging_point)// for superpower of joker
{

    if(enemy == nullptr)
        return;
    if(Reverse_World_Active)
        enemy->Get_Healed(damaging_point);
    else
        enemy->Get_Damaged(damaging_point);
}

void Controller::Finish_Round()
{
    if(round_number >= 15)
        return;

    //this loop is to update hero superpower variable
    //that indicates how many rounds is left to make it avaible
    for(int i = 0 ; i < 3 ; i++)
    {
        Hero_Arr_User1[i]->update_superpower_rounds_left_at_the_end_of_round();
        Hero_Arr_User2[i]->update_superpower_rounds_left_at_the_end_of_round();
    }
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

void Controller::Fill_Struct_For_Virtual_Functions(int user_turn, int selected_enemy_index, Argument_Skills_Functions& parameters, User &user1, User &user2)
{
    parameters.controller = this;
    if(user_turn == USER1)
    {
        for(int i = 0; i < 3; i++)
        {
            parameters.allies[i] = Hero_Arr_User1[i];
            parameters.enemies[i]= Hero_Arr_User2[i];
        }
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
        parameters.selected_enemy_index = selected_enemy_index;
        parameters.user =  &user2;
    }
}



void Controller::execute_user_ask_to_use_hero_ability_if_possible(int selected_enemy_index, Argument_Skills_Functions &parameters, int hero_index_in_array, ABILITIES which_ability, int user_turn, User &user1, User &user2, std::array<int,3> hero_arr_user1, std::array<int,3> hero_arr_user2)
{
    Fill_Struct_For_Virtual_Functions(user_turn, selected_enemy_index, parameters, user1, user2);
    if(user_turn == USER1)
    {
        if(which_ability == SKILL1)
        {
            if(!Hero_Arr_User1[hero_index_in_array]->Is_Dead())
            {
                if(Check_pouya_kajdom_between_selected_heroes(user_turn, hero_index_in_array, hero_arr_user1, hero_arr_user2) && Hero_Arr_User1[hero_index_in_array]->Return_Is_Dom_KajDom_Ongoing()){}
                else
                    Hero_Arr_User1[hero_index_in_array]->Execute_Skill1(parameters);
            }
        }
        else if(which_ability == SKILL2)
        {
            if(!Hero_Arr_User1[hero_index_in_array]->Is_Dead())
            {
                if(Check_pouya_kajdom_between_selected_heroes(user_turn, hero_index_in_array, hero_arr_user1, hero_arr_user2) && Hero_Arr_User1[hero_index_in_array]->Return_Is_Dom_KajDom_Ongoing()){}
                else
                    Hero_Arr_User1[hero_index_in_array]->Execute_Skill2(parameters);
            }
        }
        else if(which_ability == SUPERPOWER)
        {
            if(!Hero_Arr_User1[hero_index_in_array]->Is_Dead())
            {
                if(Check_pouya_kajdom_between_selected_heroes(user_turn, hero_index_in_array, hero_arr_user1, hero_arr_user2) && Hero_Arr_User1[hero_index_in_array]->Return_Is_Dom_KajDom_Ongoing()){}
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
                if(Check_pouya_kajdom_between_selected_heroes(user_turn, hero_index_in_array, hero_arr_user1, hero_arr_user2) && Hero_Arr_User1[hero_index_in_array]->Return_Is_Dom_KajDom_Ongoing()){}
                else
                    Hero_Arr_User2[hero_index_in_array]->Execute_Skill1(parameters);
            }
        }
        else if(which_ability == SKILL2)
        {
            if(!Hero_Arr_User2[hero_index_in_array]->Is_Dead())
            {
                if(Check_pouya_kajdom_between_selected_heroes(user_turn, hero_index_in_array, hero_arr_user1, hero_arr_user2) && Hero_Arr_User1[hero_index_in_array]->Return_Is_Dom_KajDom_Ongoing()){}
                else
                Hero_Arr_User2[hero_index_in_array]->Execute_Skill2(parameters);
            }
        }
        else if(which_ability == SUPERPOWER)
        {
            if(!Hero_Arr_User2[hero_index_in_array]->Is_Dead())
            {
                if(Check_pouya_kajdom_between_selected_heroes(user_turn, hero_index_in_array, hero_arr_user1, hero_arr_user2) && Hero_Arr_User1[hero_index_in_array]->Return_Is_Dom_KajDom_Ongoing()){}
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

void Controller::Refill_Players_Energy(User &user1, User &user2)
{
    switch (round_number)
    {
    case 1:
        if(which_user_started_the_game == USER1)
        {
            user1.Set_Energy(5);
            user2.Set_Energy(8);
        }
        else
        {
            user2.Set_Energy(5);
            user1.Set_Energy(8);
        }
        break;
    case 2:
        if(which_user_started_the_game == USER1)
        {
            user1.Set_Energy(8);
            user2.Set_Energy(9);
        }
        else
        {
            user2.Set_Energy(8);
            user1.Set_Energy(9);
        }
        break;
    case 3:
        if(which_user_started_the_game == USER1)
        {
            user1.Set_Energy(9);
            user2.Set_Energy(10);
        }
        else
        {
            user2.Set_Energy(9);
            user1.Set_Energy(10);
        }
        break;
    default:
        user1.Set_Energy(10);
        user2.Set_Energy(10);
        break;
    }
}

void Controller::Updated_Doping_Status()
{
    for(int i = 0; i < 3; i++)
    {
        if(Hero_Arr_User1[i] == nullptr)
            continue;
        if(Hero_Arr_User1[i]->Return_Is_Doped())
        {
            Hero_Arr_User1[i]->Reduce_Round_Doping();
            if(Hero_Arr_User1[i]->Return_Rounds_Since_Doping() <= 0)
                Hero_Arr_User1[i]->Set_Is_Doped();
        }
    }

    for(int i = 0; i < 3; i++)
    {
        if(Hero_Arr_User2[i] == nullptr)
            continue;
        if(Hero_Arr_User2[i]->Return_Is_Doped())
        {
            Hero_Arr_User2[i]->Reduce_Round_Doping();
            if(Hero_Arr_User2[i]->Return_Rounds_Since_Doping() <= 0)
                Hero_Arr_User2[i]->Set_Is_Doped();
        }
    }
}

void Controller::Updated_Serom_Khon_Status()
{
    for(int i = 0; i < 3; i++)
    {
        if(Hero_Arr_User1[i] == nullptr)
            continue;
        if(Hero_Arr_User1[i]->Return_Is_serom_Khon_ongoing())
        {
            Apply_Healed(Hero_Arr_User1[i], 40);
            Hero_Arr_User1[i]->Reduce_Round_Serom_Khon();
            if(Hero_Arr_User1[i]->Return_Round_since_Serom_khon() <= 0)
                Hero_Arr_User1[i]->Set_Is_serom_Khon_ongoing();
        }
    }

    for(int i = 0; i < 3; i++)
    {
        if(Hero_Arr_User2[i] == nullptr)
            continue;
        if(Hero_Arr_User2[i]->Return_Is_serom_Khon_ongoing())
        {
            Apply_Healed(Hero_Arr_User2[i], 40);
            Hero_Arr_User2[i]->Reduce_Round_Serom_Khon();
            if(Hero_Arr_User2[i]->Return_Round_since_Serom_khon() <= 0)
                Hero_Arr_User2[i]->Set_Is_serom_Khon_ongoing();
        }
    }
}

void Controller::Updated_Family_StrongHold_Status()
{
    for(int i = 0; i < 3; i++)
    {
        if(Hero_Arr_User1[i] == nullptr)
            continue;
        if(Hero_Arr_User1[i]->Return_Is_Family_StrongHold_ongoing())
        {
            Hero_Arr_User1[i]->Reduce_Round_Famly_StrongHold();
            if(Hero_Arr_User1[i]->Return_Round_Since_Family_StrongHold() <= 0)
                Hero_Arr_User1[i]->Set_Is_Family_StrongHold_ongoing();
        }
    }

    for(int i = 0; i < 3; i++)
    {
        if(Hero_Arr_User2[i] == nullptr)
            continue;
        if(Hero_Arr_User2[i]->Return_Is_Family_StrongHold_ongoing())
        {
            Hero_Arr_User2[i]->Reduce_Round_Famly_StrongHold();
            if(Hero_Arr_User2[i]->Return_Round_Since_Family_StrongHold() <= 0)
                Hero_Arr_User2[i]->Set_Is_Family_StrongHold_ongoing();
        }
    }
}

void Controller::Updated_Ghofli_Status()
{
    for(int i = 0; i < 3; i++)
    {
        if(Hero_Arr_User2[i] == nullptr)
            continue;
        if(Hero_Arr_User2[i]->Return_Is_Ghofli_ongoing())
        {
            Hero_Arr_User2[i]->ReSet_amount_damage_when_family_stronghold_is_active();
        }
    }

    for(int i = 0; i < 3; i++)
    {
        if(Hero_Arr_User1[i] == nullptr)
            continue;
        if(Hero_Arr_User1[i]->Return_Is_Ghofli_ongoing())
        {
            Hero_Arr_User1[i]->ReSet_amount_damage_when_family_stronghold_is_active();
        }
    }
}

void Controller::Updated_Brother_Revenge_Status()
{
    for(int i = 0; i < 3; i++)
    {
        if(Hero_Arr_User2[i] == nullptr)
            continue;
        if(Hero_Arr_User2[i]->Return_Is_Brother_Revenge_Ongoing())
        {
            Hero_Arr_User2[i]->Reduce_Round_Brother_Revenge();
            if(Hero_Arr_User2[i]->Return_Round_Brother_Revenge_Left() <= 0)
            {
                if(Hero_Arr_User2[i]->Get_Current_Hp() <= 360)
                    if(!Hero_Arr_User2[i]->Return_Is_Hidden())
                        Apply_Damaged(Hero_Arr_User2[i], Hero_Arr_User2[i]->Get_Current_Hp());
                else 
                    if(!Hero_Arr_User2[i]->Return_Is_Hidden())
                        Apply_Damaged(Hero_Arr_User2[i], 200);
                Hero_Arr_User2[i]->Set_Is_Brother_Revenge_Ongoing();
            }
        }
    }

    for(int i = 0; i < 3; i++)
    {
        if(Hero_Arr_User1[i] == nullptr)
            continue;
        if(Hero_Arr_User1[i]->Return_Is_Brother_Revenge_Ongoing())
        {
            Hero_Arr_User1[i]->Reduce_Round_Brother_Revenge();
            if(Hero_Arr_User1[i]->Return_Round_Brother_Revenge_Left() <= 0)
            {
                if(Hero_Arr_User1[i]->Get_Current_Hp() <= 360)
                    if(!Hero_Arr_User1[i]->Return_Is_Hidden())
                        Apply_Damaged(Hero_Arr_User1[i], Hero_Arr_User1[i]->Get_Current_Hp());
                else 
                    if(!Hero_Arr_User1[i]->Return_Is_Hidden())
                        Apply_Damaged(Hero_Arr_User1[i], 200);
                Hero_Arr_User1[i]->Set_Is_Brother_Revenge_Ongoing();
            }
        }
    }
}

void Controller::Updated_Dom_Kajdom_Status()
{
    for(int i = 0; i < 3; i++)
    {
        if(Hero_Arr_User2[i] == nullptr)
            continue;
        if(Hero_Arr_User2[i]->Return_Is_Dom_KajDom_Ongoing())
        {
            Hero_Arr_User2[i]->Reduce_Round_Dom_KajDom();
            if(Hero_Arr_User2[i]->Return_Round_Dom_KajDom_Left() <= 0)
            {
                Hero_Arr_User2[i]->Set_Is_Dom_KajDom_Ongoing();
                if(!Hero_Arr_User2[i]->Return_Is_Hidden())
                    Apply_Damaged(Hero_Arr_User2[i], 450);
            }
        }
    }

    for(int i = 0; i < 3; i++)
    {
        if(Hero_Arr_User1[i] == nullptr)
            continue;
        if(Hero_Arr_User1[i]->Return_Is_Dom_KajDom_Ongoing())
        {
            Hero_Arr_User1[i]->Reduce_Round_Dom_KajDom();
            if(Hero_Arr_User1[i]->Return_Round_Dom_KajDom_Left() <= 0)
            {
                Hero_Arr_User1[i]->Set_Is_Dom_KajDom_Ongoing();
                if(!Hero_Arr_User1[i]->Return_Is_Hidden())
                    Apply_Damaged(Hero_Arr_User1[i], 450);
            }
        }
    }
}

bool Controller::Check_pouya_kajdom_between_selected_heroes(int user_turn, int hero_index_in_array, std::array<int,3> hero_arr_user1, std::array<int,3> hero_arr_user2)
{
    if(user_turn == USER1)
    {
        for(int i = 0; i < 3; i++)
        {
            if(hero_arr_user1[i] == POUYA_KAJDOM)
                return true;
        }
        return false;
    }
    else 
    {
        for(int i = 0; i < 3; i++)
        {
            if(hero_arr_user2[i] == POUYA_KAJDOM)
                return true;
        }
        return false;
    }
}
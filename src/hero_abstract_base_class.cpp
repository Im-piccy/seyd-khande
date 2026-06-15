#include "../headers/hero_abstract_base_class.hpp"

void Hero_Abstaction::Get_Damaged(int damaging_points)
{
    if(Is_Doped)
        damaging_points = damaging_points * 1.2; 
    if(Is_Family_StrongHold_ongoing)
    {
        amount_damage_when_family_stronghold_is_active += damaging_points;
        if(amount_damage_when_family_stronghold_is_active >= 250)
        {
            amount_damage_when_family_stronghold_is_active = 0;
            Is_Family_StrongHold_ongoing = false;
        }
    }
    else
    {
        if(damaging_points >= Current_Hp)
        {
            Current_Hp = 0;
            Is_Hero_Dead = true;
        }
        else
        {
            Current_Hp -= damaging_points;
        }
    }
}

void Hero_Abstaction::Get_Healed(int healing_points)
{
    if(Current_Hp + healing_points >= Initial_Hp)
    {
        Current_Hp = Initial_Hp;
    }
    else
    {
        Current_Hp += healing_points;
    }
}

int Hero_Abstaction::Get_Current_Hp() const
{
    return Current_Hp;
}

bool Hero_Abstaction::Is_Dead() const
{
    return Is_Hero_Dead;
}

void Hero_Abstaction::Set_Is_Hero_Dead()
{
    if(Current_Hp <= 0)
        Is_Hero_Dead = true;
}

std::array<int, 4> Hero_Abstaction::Valid_Index_Hero(Hero_Abstaction* heros[3], int choose) const
{
    std::array<int,4> valid_indexes = {};
    int valid_count = 0;
    std::array<int, 3> valid_argument;
    if(choose != 0)
    {
        for(int i = 0; i < 3; i++)
        {
            if(heros[i] != nullptr && !heros[i]->Is_Dead() && heros[i] != this)
            {
                valid_indexes[valid_count] = i;
                valid_count++;
            }
        }
    }
    else
    {
        for(int i = 0; i < 3; i++)
        {
            if(heros[i] != nullptr && !heros[i]->Is_Dead())
            {
                valid_indexes[valid_count] = i;
                valid_count++;
            }
        }
    }
    //check check bug
    valid_indexes[3] = valid_count;
    return valid_indexes;
}

void Hero_Abstaction::Seeded()
{
    if(!seeded)
    {
        std::srand(static_cast<unsigned int>(std::time(0)));
        seeded = true;
    }
}

Hero_Abstaction * Hero_Abstaction::Find_Highest_Or_Lowest_Hp(Hero_Abstaction* heros[3], const std::string& choose ) const
{
    if(choose == "min")
    {
        Hero_Abstaction* Lowest_Hp_Hero = nullptr;
        for(int i = 0; i < 3; i++)
        {
            if(heros[i] == nullptr || heros[i]->Is_Dead())
                continue;
            if(Lowest_Hp_Hero == nullptr || heros[i]->Get_Current_Hp() < Lowest_Hp_Hero->Get_Current_Hp())
                Lowest_Hp_Hero = heros[i];
        }
        return Lowest_Hp_Hero;
    }
    else
    {
        Hero_Abstaction* Highest_Hp_Hero = nullptr;
        for(int i = 0; i < 3; i++)
        {
            if(heros[i] == nullptr || heros[i]->Is_Dead())
                continue;
            if(Highest_Hp_Hero == nullptr || heros[i]->Get_Current_Hp() > Highest_Hp_Hero->Get_Current_Hp())
               Highest_Hp_Hero = heros[i];
        }
        return Highest_Hp_Hero;
    }
}

int Hero_Abstaction::return_rounds_left_till_superpower_is_ready()
{
    return rounds_left_till_superpower_is_ready;
}

int Hero_Abstaction::Return_Skill1_Energy_Cost()
{
    return Skill1_Energy_Cost;
}
int Hero_Abstaction::Return_Skill2_Energy_Cost()
{
    return Skill2_Energy_Cost;
}
int Hero_Abstaction::Return_SuperPower_Energy_Cost()
{
    return SuperPower_Energy_Cost;
}


//-----------------------------------------Doping(whitedoctor)-----------------------------------------
void Hero_Abstaction::Activate_Doping()
{
    Is_Doped = true;
    Rounds_Since_Doping = 2;
}

bool Hero_Abstaction::Return_Is_Doped() const
{
    return Is_Doped;
}

int Hero_Abstaction::Return_Rounds_Since_Doping() const
{
    return Rounds_Since_Doping;
}

void Hero_Abstaction::Reduce_Round_Doping()
{
    Rounds_Since_Doping--;
}

void Hero_Abstaction::Set_Is_Doped()
{
    Is_Doped = false;
}
//-------------------------------------------------------------------------------------------------
//-------------------------------------serom_khon(taha-kochike)------------------------------------

void Hero_Abstaction::Activate_Serom_Khon()
{
    Is_serom_Khon_ongoing = true;
    Round_since_Serom_khon = 2;
}

bool Hero_Abstaction::Return_Is_serom_Khon_ongoing() const
{
    return Is_serom_Khon_ongoing;
}

int Hero_Abstaction::Return_Round_since_Serom_khon() const
{
    return Round_since_Serom_khon;
}

void Hero_Abstaction::Reduce_Round_Serom_Khon()
{
    Round_since_Serom_khon--;
}

void Hero_Abstaction::Set_Is_serom_Khon_ongoing()
{
    Is_serom_Khon_ongoing = false;
}
//----------------------------------------------------------------------------------------------------
//----------------------------------familiy_stronghold(dani_golang)-----------------------------------
void Hero_Abstaction::Activate_Family_StrongHold()
{
    Is_Family_StrongHold_ongoing = true;
    Round_Since_Family_StrongHold = 2;
}

void Hero_Abstaction::Updated_Family_StrongHold_Status()
{
    if(Is_Family_StrongHold_ongoing)
    {
        Round_Since_Family_StrongHold--;
        if(Round_Since_Family_StrongHold <= 0)
            Is_Family_StrongHold_ongoing = false;
    }
}

bool Hero_Abstaction::Return_Is_Hidden() const
{
    return this->Is_Hidden;
}

void Hero_Abstaction::Updated_Round_Hidden()
{
    if(Is_Hidden)
    {
        Hidden_Round_Left--;
        if(Hidden_Round_Left <= 0)
        {
            Is_Hidden = false;
        }
    }
}

void Hero_Abstaction::Activate_Brother_revenge()
{
    Is_Brother_Revenge_Ongoing = true;
    Round_Brother_Revenge_Left = 1;
}

void Hero_Abstaction::Updated_Brother_Revenge_Status(Controller &controller)// initailize when put in controller (whit object from Hero_Abstaction class)
{
    if(Is_Brother_Revenge_Ongoing)
    {
        Round_Brother_Revenge_Left--;
        if(Round_Brother_Revenge_Left <= 0)
        {
            if(Get_Current_Hp() <= 360)
                if(!this->Return_Is_Hidden())
                    controller.Apply_Damaged(this, Get_Current_Hp());
            else 
                if(!this->Return_Is_Hidden())
                    controller.Apply_Damaged(this, 200);
            Is_Brother_Revenge_Ongoing = false;
        }
    }
}

void Hero_Abstaction::Activate_Dom_Kajdom(Argument_Skills_Functions parameters)// initailize when put in controller (whit object from Hero_Abstaction class)
{
    if(Is_Hidden)
    {
        Hidden_Round_Left--;
        if(Hidden_Round_Left <= 0)
        {
            Is_Hidden = false;
            Seeded();
            std::array<int,4> valid_indexes = Valid_Index_Hero(parameters.enemies);
            if(valid_indexes[3] == 0)
                return;
            int random_position = std::rand() % valid_indexes[3];
            int selected_index = valid_indexes[random_position];
            if(!parameters.enemies[selected_index]->Return_Is_Hidden())
                (*parameters.controller).Apply_Damaged(parameters.enemies[selected_index], 450);
        }
    }
}

void Hero_Abstaction::update_superpower_rounds_left_at_the_end_of_round()
{
    this->rounds_left_till_superpower_is_ready--;
    if(this->rounds_left_till_superpower_is_ready < 0)
    {
        this->rounds_left_till_superpower_is_ready = 0;
    }
}
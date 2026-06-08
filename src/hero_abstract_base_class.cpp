#include "../headers/hero_abstract_base_class.hpp"

void Hero_Abstaction::Get_Damaged(int damaging_points)
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

std::array<int, 4> Hero_Abstaction::Valid_Index_Hero(Hero_Abstaction* heros[3], int choose = 0) const
{
   std::array<int,4> valid_indexes;
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
    valid_argument[3] = valid_count;
    return valid_indexes;
}

void Hero_Abstaction::Seeded()
{
    seeded = false;
    if(!seeded)
    {
        std::srand(static_cast<unsigned int>(std::time(0)));
        seeded = true;
    }
}

Hero_Abstaction * Hero_Abstaction::Find_Highest_Or_Lowest_Hp(Hero_Abstaction* heros[3], int turn) const
{
    if(turn == 0)
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
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

std::array<int, 4> Hero_Abstaction::Valid_Index_Hero(Hero_Abstaction* allies[3], int choose = 0) const
{
   std::array<int,4> valid_indexes;
    int valid_count = 0;
    std::array<int, 3> valid_argument;
    if(choose != 0)
    {
        for(int i = 0; i < 3; i++)
        {
            if(allies[i] != nullptr && !allies[i]->Is_Dead() && allies[i] != this)
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
            if(allies[i] != nullptr && !allies[i]->Is_Dead())
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
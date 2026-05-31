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



#include "../headers/user.hpp"

User::User()
{
    Hero_Arr = {0, 0 ,0};
}

int User::Get_Energy() const
{
    return this->energy;
}

void User::Set_Energy(int cost)
{
    if(cost > energy)
        energy = 0;
    else
        energy -= cost;
}

bool User::Set_Name(std::string username)
{
    if(username.size() > 25)
        return false;
    int i;    
    for(i = 0; i < 25; i++)
    {
        this->username[i] = username[i];
    }
    this->username[i] = '\0';
    return true;
}

std::string User::Get_Name() const
{
    std::string username;
    for(int i = 0; i < 25; i++)
        username[i] = this->username[i];
    return username;
}

void User::add_hero_to_hero_array(int hero)
{
    for(int i = 0 ; i < 3 ; i++)
    {
        if(this->Hero_Arr[i] == 0)
        {
            this->Hero_Arr[i] = hero;
            return;
        }
    }
}

std::array<int,3> User::Get_Hero_Array() const
{
    return Hero_Arr;
}
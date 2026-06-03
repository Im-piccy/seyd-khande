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

std::array<char,26> User::Get_Name() const
{
    return this->username;
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
#include "../headers/user.hpp"

User::User()
{
    this->Hero_Arr = {0, 0 ,0};
    this->username = {};

    //testing to be deleted
    this->energy = 10;
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

void User::Set_Name(const std::string& username)
{

    int i;
    for(i = 0; i < 25; i++)
    {
        this->username[i] = username[i];
    }
    this->username[i] = '\0';
}

std::string User::Get_Name_String() const
{
    std::string username;
    int i;
    for(i = 0; i < 25; i++)
    {
        username[i] = this->username[i];
    }
    username[i] = '\0';
    return username;
}

std::array<char,26> User::Get_Name_Char_Array() const
{
    this->username;
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



std::array<int,2> User::call_hero_abillity(int hero_type, int abillity_type)
{
    std::array<int,2> Hero_And_HisAbillity = {hero_type, abillity_type};
    return Hero_And_HisAbillity;
}
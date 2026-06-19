#include "../headers/user.hpp"

User::User()
{
    this->Hero_Arr = {0, 0 ,0};
    this->username = {};

    //testing to be deleted
    this->energy = 0;
}

int User::Get_Energy() const
{
    return this->energy;
}

void User::Subtract_Energy(int cost)
{
    if(cost > energy)
        energy = 0;
    else
        energy -= cost;
}

void User::Set_Name(const std::string& username)
{

    std::fill(this->username.begin(), this->username.end(), '\0');
    for(int i = 0; i < 25 && i < username.length(); i++)
    {
        this->username[i] = username[i];
    }
}

std::string User::Get_Name_String() const
{
    return std::string (this->username.data());
}

std::array<char,26> User::Get_Name_Char_Array() const
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

std::array<int,3> User::Get_Hero_Array() const
{
    return Hero_Arr;
}

void User::Add_Energy(int energy)
{
    this->energy = energy;
}
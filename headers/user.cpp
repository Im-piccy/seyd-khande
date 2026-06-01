#include "../headers/user.hpp"

int User::Get_Energy() const
{
    return energy;
}

void User::Set_Energy(int cost)
{
    if(cost > energy)
        energy = 0;
    else
        energy -= cost;
}
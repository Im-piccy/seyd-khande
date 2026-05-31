#ifndef HERO_SUB_CLASS_TO_INSTATIATE_OBJECTS_HPP
#define HERO_SUB_CLASS_TO_INSTATIATE_OBJECTS_HPP
#include "hero_abstract_base_class.hpp"

class WhiteDoctor : public Hero_Abstaction
{
    public:
        WhiteDoctor();//this constructor should initilize heros info like hp, superpower cost ...
        bool Execute_Asprin_Ability(int current_energy);//return type is bool that means if there is not enaugh energy for the attack it will return false
        bool Execute_Doping_Ability(int current_energy);
    private:
        int Asprin_Ability_Energy_Cost;
        int Doping_Ability_Energy_Cost;
        bool Is_Doping_Ongoing;//to know if any of team heros are being doped
        int Rounds_Since_Doping;//keeping track of Doping duration
        int Hero_Being_Doped;//keeping track of who is being doped
};

class Taha_Kochike : public Hero_Abstaction
{
    public:
        Taha_Kochike(); // constructor to initilize the hero information
        bool Execute_Tigh_Tiz_Ability(int current_energy); 
        bool Execute_Serom_Khon_Ability(int current_energy); 
    private:
        int Tigh_Tiz_Ability_Energy_Cost;
        int Serom_Khon_Ability_Energy_Cost;
};

class Dani_Golang : public Hero_Abstaction
{
    public:
        Dani_Golang(); // conctructior to initiate info
        bool Execute_Ghofli_Ability(int current_energy); 
        bool Execute_Fil_kosh_Ability(int current_energy); 

    private:
        int Last_Attacked_Enemy;
        int Ghofli_Ability_Energy_Cost;
        int Fil_kosh_Ability_Energy_Cost;

};




#endif
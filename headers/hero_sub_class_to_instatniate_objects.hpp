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
        
};

class Taha_Kochike
{
    public:
        Taha_Kochike(); // constructor to initilize the hero information
        bool Execute_Tigh_Tiz_Ability(int current_energy); 
        bool Execute_Serom_Khon_Ability(int current_energy); 
    private:
        int Tigh_Tiz_Ability_Energy_Cost;
        int Serom_Khon_Ability_Energy_Cost;
};




#endif
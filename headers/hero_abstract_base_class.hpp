#ifndef HERO_ABSTRACT_BASE_CLASS_HPP
#define HERO_ABSTRACT_BASE_CLASS_HPP
#include <array>
#include <string>
#include <cstdlib>
#include <ctime>

class Hero_Abstaction //abstract class
{
    public:
        int Get_Current_Hp() const;//returns hero current health
        bool Is_Dead() const;// indicates hero living status 
        void Get_Healed(int healing_points);
        void Get_Damaged(int damaging_point);//if damage is more than hp it will edit the boolian value
        void Seeded();

        int Return_Skill1_Energy_Cost();
        int Return_Skill2_Energy_Cost();
        int Return_SuperPower_Energy_Cost();

        virtual int return_rounds_left_till_superpower_is_ready() = 0;
        std::array<int, 4> Valid_Index_Hero(Hero_Abstaction* allies[3], int chosee = 0) const;
        Hero_Abstaction * Find_Highest_Or_Lowest_Hp(Hero_Abstaction* heros[3], std::string choose = "min") const;//to find the hero with the highest or lowest Hp
    protected:
        int Current_Hp; // this shows how much health the hero has got left
        int Initial_Hp; // this is how much hp a hero has with out any damage
        bool seeded = false;// for rand function (in Seeded function)
        int rounds_left_till_superpower_is_ready;// this shows the number of round it takes to use 
        // super power  if 0 means superpower is ready
        bool Is_Hero_Dead;
        int hero_type; // is the hero a Healer? Attacker? Defender? or a joker?
        int SuperPower_Energy_Cost;
        int Skill1_Energy_Cost;
        int Skill2_Energy_Cost;
};




#endif
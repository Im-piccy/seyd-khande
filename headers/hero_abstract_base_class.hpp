#ifndef HERO_ABSTRACT_BASE_CLASS_HPP
#define HERO_ABSTRACT_BASE_CLASS_HPP
#include <array>
#include <string>
#include <cstdlib>
#include <ctime>
#include "enums.hpp"
class User;
class Controller;

class Hero_Abstaction //abstract class
{
    public:
        
        Hero_Abstaction();
        int Get_Current_Hp() const;//returns hero current health
        bool Is_Dead() const;// indicates hero living status 
        void Set_Is_Hero_Dead();
        void Get_Healed(int healing_points);
        void Get_Damaged(int damaging_point);//if damage is more than hp it will edit the boolian value
        void Seeded();
        void update_superpower_rounds_left_at_the_end_of_round();

        virtual bool Execute_Skill1(Argument_Skills_Functions &parameters) = 0;
        virtual bool Execute_Skill2(Argument_Skills_Functions &parameters) = 0;
        virtual bool Execute_SuperSkill(Argument_Skills_Functions &parameters) = 0;

        int Return_Skill1_Energy_Cost();
        int Return_Skill2_Energy_Cost();
        int Return_SuperPower_Energy_Cost();

        virtual int return_rounds_left_till_superpower_is_ready() = 0;
        std::array<int, 4> Valid_Index_Hero(Hero_Abstaction* allies[3], int chosee = 0) const;
        Hero_Abstaction * Find_Highest_Or_Lowest_Hp(Hero_Abstaction* heros[3], const std::string& choose = "min") const;//to find the hero with the highest or lowest Hp
        
        //for doping power (whitedoctor)
        void Activate_Doping();
        bool Return_Is_Doped() const;
        int Return_Rounds_Since_Doping() const;
        void Reduce_Round_Doping();
        void Set_Is_Doped();

        //for serom_khon power (taha_kochike)
        void Activate_Serom_Khon();
        bool Return_Is_serom_Khon_ongoing() const;
        int Return_Round_since_Serom_khon() const;
        void Reduce_Round_Serom_Khon();
        void Set_Is_serom_Khon_ongoing();

        //for family stronghold (superpower of dani_golang)
        void Activate_Family_StrongHold();
        bool Return_Is_Family_StrongHold_ongoing() const;
        int Return_Round_Since_Family_StrongHold () const;
        void Reduce_Round_Famly_StrongHold();
        void Set_Is_Family_StrongHold_ongoing();

        //for ghofli power (dani_golang)
        void Activate_Ghofli();
        bool Return_Is_Ghofli_ongoing() const;
        void ReSet_amount_damage_when_family_stronghold_is_active();

        //for XRay power (taha_bozorge) & super power of pouya_kajdom
        bool Return_Is_Hidden() const;
        void Updated_Round_Hidden();

        //for brother revenge power(superpower of taha_ozorge)
        void Activate_Brother_revenge();
        bool Return_Is_Brother_Revenge_Ongoing() const;
        int Return_Round_Brother_Revenge_Left() const;
        void Reduce_Round_Brother_Revenge();
        void Set_Is_Brother_Revenge_Ongoing();

        //for superpower of pouya_kajdom
        void Activate_Dom_Kajdom();
        bool Return_Is_Dom_KajDom_Ongoing() const;
        int Return_Round_Dom_KajDom_Left() const;
        void Reduce_Round_Dom_KajDom();
        void Set_Is_Dom_KajDom_Ongoing();
        
    protected:
        int Current_Hp; // this shows how much health the hero has got left
        int Initial_Hp; // this is how much hp a hero has with out any damage
        bool seeded = false;// for rand function (in Seeded function)
        int rounds_left_till_superpower_is_ready;// this shows the number of round it takes to use 
        bool Is_Hero_Dead;
        int hero_type; // is the hero a Healer? Attacker? Defender? or a joker?
        int SuperPower_Energy_Cost;
        int Skill1_Energy_Cost;
        int Skill2_Energy_Cost;

        //for doping power (whitedoctor)
        bool Is_Doped;
        int Rounds_Since_Doping;//keeping track of Doping duration

        //for serom_khon power (taha_kochike)
        bool Is_serom_Khon_ongoing;
        int Round_since_Serom_khon;

        //for family stronghold (superpower of dani_golang)
        bool Is_Family_StrongHold_ongoing;
        int Round_Since_Family_StrongHold;
        int amount_damage_when_family_stronghold_is_active;

        //for ghofli power (dani_golang)
        bool Is_Ghofli_ongoing;
        int amount_of_the_last_damage_done;

        //for XRay power (taha_bozorge)
        bool Is_Hidden;
        int Hidden_Round_Left;

        //for brother revenge power(superpower of taha_ozorge)
        bool Is_Brother_Revenge_Ongoing;
        int Round_Brother_Revenge_Left;

        //for dom kajdom power(superpower of pouya_kajdom)
        bool Is_Dom_KajDom_Ongoing;
        int Round_Dom_KajDom_Left;

};

#endif
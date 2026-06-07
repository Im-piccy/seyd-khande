#ifndef HERO_SUB_CLASS_TO_INSTATIATE_OBJECTS_HPP
#define HERO_SUB_CLASS_TO_INSTATIATE_OBJECTS_HPP
#include "hero_abstract_base_class.hpp"
#include "User.hpp"
#include <cstdlib>
#include <ctime>
#include <array>


enum POUYA_KAJDOM_SCORPIENS{NONE, SCORPIEN, BUFFED_SCORPIEN};
class WhiteDoctor : public Hero_Abstaction//healer
{
    public:
        WhiteDoctor();//this constructor should initilize heros info like hp, superpower cost ...
        bool Execute_Asprin_Ability_Healed(Hero_Abstaction* allies[3], User &user);//return type is bool that means if there is not enaugh energy for the attack it will return false
        bool Execute_Asprin_Ability_Damaged(Hero_Abstaction* enemies[3], int target_index, User &user);
        bool Execute_Doping_Ability(Hero_Abstaction* allies[3], User &user);  
        bool Execute_SuperPower(Hero_Abstaction* allies[3], User &user);
    private:
        int Asprin_Ability_Energy_Cost;
        int Doping_Ability_Energy_Cost;
        bool Is_Doping_Ongoing;//to know if any of team heros are being doped
        int Rounds_Since_Doping;//keeping track of Doping duration
        int Hero_Being_Doped;//keeping track of who is being doped
};

class Taha_Kochike : public Hero_Abstaction//healer
{
    public:
        Taha_Kochike(); // constructor to initilize the hero information
        bool Execute_Tigh_Tiz_Ability_Healed(Hero_Abstaction* allies[3], User &user);
        bool Execute_Tigh_Tiz_Ability_Damage(Hero_Abstaction* allies[3], int target_index, User&user); 
        bool Execute_Serom_Khon_Ability(Hero_Abstaction* allies[3], User &user); 
        bool Execute_SuperPower(Hero_Abstaction* allies[3], User &user);
    private:
        int Tigh_Tiz_Ability_Energy_Cost;
        int Serom_Khon_Ability_Energy_Cost;
        bool Is_serom_Khon_ongoing;
        int Round_since_Serom;
        int Hero_under_Serom;
};

class Dani_Golang : public Hero_Abstaction //defender
{
    public:
        Dani_Golang(); // conctructor to initiate info
        bool Execute_Ghofli_Ability(int current_energy); 
        bool Execute_Fil_kosh_Ability(int current_energy); 
        bool Execute_SuperPower(int current_energy);

    private:
        int Last_Attacked_Enemy;
        int Ghofli_Ability_Energy_Cost;
        int Fil_kosh_Ability_Energy_Cost;

};


class Amin_Emeni : public Hero_Abstaction //attacker
{
    public:
        Amin_Emeni();//constructor to initiate info
        bool Execute_Akharin_Feshang_Ability(int current_energy); 
        bool Execute_Zarbe_Be_Khody_Ability(int current_energy); 
        bool Execute_SuperPower(int current_energy);
    private:
        int Akharin_Feshang_Ability_Energy_Cost;
        int Zarbe_Be_Khodi_Ability_Energy_Cost;
};


class Taha_Bozorge : public Hero_Abstaction // attacker
{
    public:
        Taha_Bozorge();//constructor to initiate info
        bool Execute_Ragbar_Ability(int current_energy); 
        bool Execute_Xray_Ability(int current_energy); 
        bool Execute_SuperPower(int current_energy);
    private:
        int Ragbar_Ability_Energy_Cost;
        int Xray_Ability_Energy_Cost;
        bool Is_Xray_Ongoing;
        int Rounds_Since_Xray;
};

class Pouya_Kajdom : public Hero_Abstaction // attacker
{
    public:
        Pouya_Kajdom();//constructor to initiate info
        bool Execute_Khanjar_Ability(int current_energy); 
        bool Execute_Aghrab_Ability(int current_energy); 
        bool Execute_SuperPower(int current_energy);
    private:
        int Khanjar_Ability_Energy_Cost;
        int Aghrab_Ability_Energy_Cost;
        int Enemy_Array_With_Respect_To_Active_Scorpiens[3];
        bool Is_SuperPower_Active;
};

class Agha_Shahriar : public Hero_Abstaction // attacker
{
    public:
        Agha_Shahriar();//constructor to initiate info
        bool Execute_Maskhare_Ability(int current_energy); 
        bool Execute_Lajbaz_Ability(int current_energy); 
        bool Execute_SuperPower(int current_energy);
    private:
        int Maskhare_Ability_Energy_Cost;
        int Lajbaz_Ability_Energy_Cost;
        bool Is_SuperPower_Active;
        int Rounds_Since_SuperPower;
};
#endif
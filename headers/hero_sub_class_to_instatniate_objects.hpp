#ifndef HERO_SUB_CLASS_TO_INSTATIATE_OBJECTS_HPP
#define HERO_SUB_CLASS_TO_INSTATIATE_OBJECTS_HPP
#include "User.hpp"
#include "hero_abstract_base_class.hpp"
#include <cstdlib>
#include <ctime>
#include <array>

enum POUYA_KAJDOM_SCORPIENS{NONE, SCORPIEN, BUFFED_SCORPIEN};
class WhiteDoctor : public Hero_Abstaction//healer
{
    public:
        WhiteDoctor();//this constructor should initilize heros info like hp, superpower cost ...
        bool Execute_Asprin_Ability_Healed(Hero_Abstaction* allies[3], User &user);//return type is bool that means if there is not enaugh energy for the attack it will return false
        bool Execute_Asprin_Ability_Damaged(Hero_Abstaction* enemies[3], int selected_enemy_index, User &user);
        bool Execute_Doping_Ability(User &user);  
        bool Execute_SuperPower(Hero_Abstaction* allies[3], User &user);

        virtual bool Execute_Skill1(Hero_Abstaction* allies[3], Hero_Abstaction* enemies[3], int selected_enemy_index, int selected_ally_index, User &user) override;
        virtual bool Execute_Skill2(Hero_Abstaction* allies[3], Hero_Abstaction* enemies[3], int selected_enemy_index, User &user) override;
        virtual bool Execute_SkillPower(Hero_Abstaction* allies[3], Hero_Abstaction* enemies[3], User &user) override;
        virtual int return_rounds_left_till_superpower_is_ready() override;    
    private:
        bool Is_Doping_Ongoing;//to know if any of team heros are being doped
        int Rounds_Since_Doping;//keeping track of Doping duration
        int Hero_Being_Doped;//keeping track of who is being doped
};

class Taha_Kochike : public Hero_Abstaction//healer
{
    public:
        Taha_Kochike(); // constructor to initilize the hero information
        bool Execute_Tigh_Tiz_Ability_Healed(Hero_Abstaction* allies[3], User &user);
        bool Execute_Tigh_Tiz_Ability_Damage(Hero_Abstaction* enemies[3], int selected_enemy_index, User &user); 
        bool Execute_Serom_Khon_Ability(Hero_Abstaction* allies[3] , int selected_ally_index, User &user); 
        bool Execute_SuperPower(Hero_Abstaction* allies[3], User &user);

        virtual bool Execute_Skill1(Hero_Abstaction* allies[3], Hero_Abstaction* enemies[3], int selected_enemy_index, int selected_ally_index, User &user) override;
        virtual bool Execute_Skill2(Hero_Abstaction* allies[3], Hero_Abstaction* enemies[3], int selected_enemy_index, User &user) override;
        virtual bool Execute_SkillPower(Hero_Abstaction* allies[3], Hero_Abstaction* enemies[3], User &user) override;
        virtual int return_rounds_left_till_superpower_is_ready() override;    
    private:
        bool Is_serom_Khon_ongoing;
        int Round_since_Serom;
        int Hero_under_Serom;
};

class Dani_Golang : public Hero_Abstaction //defender
{
    public:
        Dani_Golang(); // conctructor to initiate info
        bool Execute_Ghofli_Ability(Hero_Abstaction* enemies[3], int selected_enemy_index, User &user); 
        bool Execute_Fil_kosh_Ability(Hero_Abstaction* enemies[3], int selected_enemy_index, User &user); 
        bool Execute_SuperPower(Hero_Abstaction* allies[3], User &user);

        virtual bool Execute_Skill1(Hero_Abstaction* allies[3], Hero_Abstaction* enemies[3], int selected_enemy_index, int selected_ally_index, User &user) override;
        virtual bool Execute_Skill2(Hero_Abstaction* allies[3], Hero_Abstaction* enemies[3], int selected_enemy_index, User &user) override;
        virtual bool Execute_SkillPower(Hero_Abstaction* allies[3], Hero_Abstaction* enemies[3], User &user) override;
        virtual int return_rounds_left_till_superpower_is_ready() override;    
    private:
        int Last_Attacked_Enemy;
        int Round_Use_Ghofli_Ability;
        bool Repete_Ghofli_Ability;
        bool Start_SuperPower;
        int Round_Use_SuperPower;

};


class Amin_Emeni : public Hero_Abstaction //attacker
{
    public:
        Amin_Emeni();//constructor to initiate info
        bool Execute_Akharin_Feshang_Ability(Hero_Abstaction* enemies[3], int selected_enemy_index,  User &user); 
        bool Execute_Zarbe_Be_Khody_Ability(Hero_Abstaction* allies[3], User &usser); 
        bool Execute_SuperPower(Hero_Abstaction* allies[3], Hero_Abstaction* enemies[3], User &user);

        virtual bool Execute_Skill1(Hero_Abstaction* allies[3], Hero_Abstaction* enemies[3], int selected_enemy_index, int selected_ally_index, User &user) override;
        virtual bool Execute_Skill2(Hero_Abstaction* allies[3], Hero_Abstaction* enemies[3], int selected_enemy_index, User &user) override;
        virtual bool Execute_SkillPower(Hero_Abstaction* allies[3], Hero_Abstaction* enemies[3], User &user) override;
        virtual int return_rounds_left_till_superpower_is_ready() override;    
    private:
};


class Taha_Bozorge : public Hero_Abstaction // attacker
{
    public:
        Taha_Bozorge();//constructor to initiate info
        bool Execute_Ragbar_Ability(Hero_Abstaction* enemies[3], User &user);
        bool Execute_Xray_Ability(Hero_Abstaction* enemies[3], int selected_enemy_index, User &user); 
        bool Execute_SuperPower(Hero_Abstaction* enemies[3], User &user);

        virtual bool Execute_Skill1(Hero_Abstaction* allies[3], Hero_Abstaction* enemies[3], int selected_enemy_index, int selected_ally_index, User &user) override;
        virtual bool Execute_Skill2(Hero_Abstaction* allies[3], Hero_Abstaction* enemies[3], int selected_enemy_index, User &user) override;
        virtual bool Execute_SkillPower(Hero_Abstaction* allies[3], Hero_Abstaction* enemies[3], User &user) override;
        virtual int return_rounds_left_till_superpower_is_ready() override;    
    private:
        bool Is_Xray_Ongoing;
        int Rounds_Since_Xray;
        int Rounds_Since_SuperPower;
        int Save_Selected_Enemy_Index;
};

class Pouya_Kajdom : public Hero_Abstaction // attacker
{
    public:
        Pouya_Kajdom();//constructor to initiate info
        bool Activate_scorpien(Hero_Abstaction* enemies[3]);
        bool Execute_Khanjar_Ability(Hero_Abstaction* enemies[3], int selected_enemy_index, User &user); 
        bool Execute_Aghrab_Ability(Hero_Abstaction* enemies[3], int selected_enemy_index, User &user); 
        bool Execute_SuperPower(Hero_Abstaction* enemies[3], User &user);

        virtual bool Execute_Skill1(Hero_Abstaction* allies[3], Hero_Abstaction* enemies[3], int selected_enemy_index, int selected_ally_index, User &user) override;
        virtual bool Execute_Skill2(Hero_Abstaction* allies[3], Hero_Abstaction* enemies[3], int selected_enemy_index, User &user) override;
        virtual bool Execute_SkillPower(Hero_Abstaction* allies[3], Hero_Abstaction* enemies[3], User &user) override;
        virtual int return_rounds_left_till_superpower_is_ready() override;    
    private:
        int Enemy_Array_With_Respect_To_Active_Scorpiens[3];
        bool Is_SuperPower_Active;
        int Rounds_Since_SuperPower;
};

class Agha_Shahriar : public Hero_Abstaction // attacker
{
    public:
        Agha_Shahriar();//constructor to initiate info
        bool Execute_Maskhare_Ability(Hero_Abstaction* enemies[3], int selected_enemy_index, User &user); 
        bool Execute_Lajbaz_Ability(Hero_Abstaction* enemies[3], int selected_enemy_index, User &user); 
        bool Execute_SuperPower(User &user);

        virtual bool Execute_Skill1(Hero_Abstaction* allies[3], Hero_Abstaction* enemies[3], int selected_enemy_index, int selected_ally_index, User &user) override;
        virtual bool Execute_Skill2(Hero_Abstaction* allies[3], Hero_Abstaction* enemies[3], int selected_enemy_index, User &user) override;
        virtual bool Execute_SkillPower(Hero_Abstaction* allies[3], Hero_Abstaction* enemies[3], User &user) override;
        virtual int return_rounds_left_till_superpower_is_ready() override;    
    private:
        bool Is_SuperPower_Active;
        int Rounds_Since_SuperPower;
};

#endif
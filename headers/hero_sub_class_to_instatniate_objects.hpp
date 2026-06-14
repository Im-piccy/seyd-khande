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
        bool Execute_Asprin_Ability_Healed(Hero_Abstaction* allies[3], User &user, Controller &controller);//return type is bool that means if there is not enaugh energy for the attack it will return false
        bool Execute_Asprin_Ability_Damaged(Hero_Abstaction* enemies[3], int selected_enemy_index, User &user, Controller &controller);
        bool Execute_Asprin_Ability(Hero_Abstaction* allies[3], Hero_Abstaction* enemies[3], int selected_enemy_index, User &user, Controller &controller);
        bool Execute_Doping_Ability(Hero_Abstaction* allies[3], User &user);  
        bool Execute_SuperPower(Hero_Abstaction* allies[3], User &user, Controller &controller);

        virtual bool Execute_Skill1(Argument_Skills_Functions parameters) override;
        virtual bool Execute_Skill2(Argument_Skills_Functions parameters) override;
        virtual bool Execute_SuperSkill(Argument_Skills_Functions parameters) override;
        virtual int return_rounds_left_till_superpower_is_ready() override;    
    private:
};

class Taha_Kochike : public Hero_Abstaction//healer
{
    public:
        Taha_Kochike(); // constructor to initilize the hero information
        bool Execute_Tigh_Tiz_Ability_Healed(Hero_Abstaction* allies[3], User &user, Controller &controller);
        bool Execute_Tigh_Tiz_Ability_Damage(Hero_Abstaction* enemies[3], int selected_enemy_index, User &user, Controller &controller);
        bool Execute_Tigh_Tiz_Abillity(Hero_Abstaction* allies[3], Hero_Abstaction* enemies[3], int selected_enemy_index, User &user, Controller &controller);
        bool Execute_Serom_Khon_Ability(Hero_Abstaction* allies[3] , User &user, Controller &controller); 
        bool Execute_SuperPower(Hero_Abstaction* allies[3], User &user, Controller &controller);

        virtual bool Execute_Skill1(Argument_Skills_Functions parameters) override;
        virtual bool Execute_Skill2(Argument_Skills_Functions parameters) override;
        virtual bool Execute_SuperSkill(Argument_Skills_Functions parameters) override;
        virtual int return_rounds_left_till_superpower_is_ready() override;    
    private:
};

class Dani_Golang : public Hero_Abstaction //defender
{
    public:
        Dani_Golang(); // conctructor to initiate info
        bool Execute_Ghofli_Ability(Hero_Abstaction* enemies[3], int selected_enemy_index, User &user, Controller &controller); 
        bool Execute_Fil_kosh_Ability(Hero_Abstaction* enemies[3], int selected_enemy_index, User &user, Controller &controller); 
        bool Execute_SuperPower(Hero_Abstaction* allies[3], User &user, Controller &controller);

        virtual bool Execute_Skill1(Argument_Skills_Functions parameters) override;
        virtual bool Execute_Skill2(Argument_Skills_Functions parameters) override;
        virtual bool Execute_SuperSkill(Argument_Skills_Functions parameters) override;
        virtual int return_rounds_left_till_superpower_is_ready() override;    
    private:
        int Last_Attacked_Enemy;
};


class Amin_Emeni : public Hero_Abstaction //attacker
{
    public:
        Amin_Emeni();//constructor to initiate info
        bool Execute_Akharin_Feshang_Ability(Hero_Abstaction* enemies[3], int selected_enemy_index, User &user, Controller &controller); 
        bool Execute_Zarbe_Be_Khody_Ability(Hero_Abstaction* allies[3], User &usser, Controller &controller); 
        bool Execute_SuperPower(Hero_Abstaction* allies[3], Hero_Abstaction* enemies[3], User &user, Controller &controller);

        virtual bool Execute_Skill1(Argument_Skills_Functions parameters) override;
        virtual bool Execute_Skill2(Argument_Skills_Functions parameters) override;
        virtual bool Execute_SuperSkill(Argument_Skills_Functions parameters) override;
        virtual int return_rounds_left_till_superpower_is_ready() override;    
    private:
};


class Taha_Bozorge : public Hero_Abstaction // attacker
{
    public:
        Taha_Bozorge();//constructor to initiate info
        bool Execute_Ragbar_Ability(Hero_Abstaction* enemies[3], User &user, Controller &controller);
        bool Execute_Xray_Ability(Hero_Abstaction* enemies[3], int selected_enemy_index, User &user, Controller &controller); 
        bool Execute_SuperPower(Hero_Abstaction* enemies[3], User &user, Controller &controller);

        virtual bool Execute_Skill1(Argument_Skills_Functions parameters) override;
        virtual bool Execute_Skill2(Argument_Skills_Functions parameters) override;
        virtual bool Execute_SuperSkill(Argument_Skills_Functions parameters) override;
        virtual int return_rounds_left_till_superpower_is_ready() override;    
    private:
        int Save_Selected_Enemy_Index;
};

class Pouya_Kajdom : public Hero_Abstaction // attacker
{
    public:
        Pouya_Kajdom();//constructor to initiate info
        bool Activate_scorpien(Hero_Abstaction* enemies[3], Controller &controller);
        bool Execute_Khanjar_Ability(Hero_Abstaction* enemies[3], int selected_enemy_index, User &user, Controller &controller); 
        bool Execute_Aghrab_Ability(Hero_Abstaction* enemies[3], int selected_enemy_index, User &user, Controller &controller); 
        bool Execute_SuperPower(Hero_Abstaction* enemies[3], User &user, Controller &controller);

        virtual bool Execute_Skill1(Argument_Skills_Functions parameters) override;
        virtual bool Execute_Skill2(Argument_Skills_Functions parameters) override;
        virtual bool Execute_SuperSkill(Argument_Skills_Functions parameters) override;
        virtual int return_rounds_left_till_superpower_is_ready() override;    
    private:
        int Enemy_Array_With_Respect_To_Active_Scorpiens[3];
};

class Agha_Shahriar : public Hero_Abstaction // attacker
{
    public:
        Agha_Shahriar();//constructor to initiate info
        bool Execute_Maskhare_Ability(Hero_Abstaction* enemies[3], int selected_enemy_index, User &user, Controller &controller); 
        bool Execute_Lajbaz_Ability(Hero_Abstaction* enemies[3], int selected_enemy_index, User &user, Controller &controller); 
        bool Execute_SuperPower(User &user, Controller &controller);

        virtual bool Execute_Skill1(Argument_Skills_Functions parameters) override;
        virtual bool Execute_Skill2(Argument_Skills_Functions parameters) override;
        virtual bool Execute_SuperSkill(Argument_Skills_Functions parameters) override;
        virtual int return_rounds_left_till_superpower_is_ready() override;    
    private:
};

#endif
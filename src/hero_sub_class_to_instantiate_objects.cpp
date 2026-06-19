#include "../headers/hero_abstract_base_class.hpp"
#include "../headers/hero_sub_class_to_instatniate_objects.hpp"

// -----------------------------white doctor----------------------------------
//skill1 --> asprin
//skill2 --> doping

WhiteDoctor::WhiteDoctor()
{
    this->Current_Hp = 550;
    this->Initial_Hp = 550;
    this->hero_type = HELAER;
    this->Skill1_Energy_Cost = 3;
    this->Skill2_Energy_Cost = 4;
    this->SuperPower_Energy_Cost = 4;
    this->Is_Hero_Dead = false;
    this->rounds_left_till_superpower_is_ready = 4;

    this->Rounds_Since_Doping = 0;
    this->Is_Doped = false;

    this->Is_serom_Khon_ongoing = false;
    this->Round_since_Serom_khon =  0;
    this->Is_Family_StrongHold_ongoing = false;
    this->Round_Since_Family_StrongHold = 0;
    this->amount_damage_when_family_stronghold_is_active = 0;
    this->Is_Brother_Revenge_Ongoing = false;
    this->Round_Brother_Revenge_Left = 0;
    this->Is_Dom_KajDom_Ongoing = false;
    this->Round_Dom_KajDom_Left = 0;
    this->Is_Ghofli_ongoing = false;
    this->amount_of_the_last_damage_done = 0;
}

bool WhiteDoctor::Execute_Asprin_Ability_Healed(Hero_Abstaction* allies[3], User &user, Controller &controller)
{
    Seeded();
    std::array<int,4> valid_indexes = Valid_Index_Hero(allies);
    if(valid_indexes[3] == 0)
        return false;
    int random_position = std::rand() % valid_indexes[3];
    int selected_index = valid_indexes[random_position];
    controller.Apply_Healed(allies[selected_index], 40);
    user.Subtract_Energy(Skill1_Energy_Cost);
    return true;
}

bool WhiteDoctor::Execute_Asprin_Ability_Damaged(Hero_Abstaction* enemies[3], int selected_enemy_index, User &user, Controller &controller)
{
    if(selected_enemy_index < 0 || selected_enemy_index >= 3)
        return false;
    if(enemies[selected_enemy_index] == nullptr || enemies[selected_enemy_index]->Is_Dead())
        return false;
    if(!enemies[selected_enemy_index]->Return_Is_Hidden())
        controller.Apply_Damaged(enemies[selected_enemy_index], 40);
    return true;
}

bool WhiteDoctor::Execute_Asprin_Ability(Hero_Abstaction* allies[3], Hero_Abstaction* enemies[3], int selected_enemy_index, User &user, Controller &controller)
{
    if(Execute_Asprin_Ability_Healed(allies, user, controller) && Execute_Asprin_Ability_Damaged(enemies, selected_enemy_index, user, controller))
        return true;
    return false;
}

bool WhiteDoctor::Execute_Doping_Ability(Hero_Abstaction* allies[3], User &user)
{
    Seeded();
    std::array<int,4> valid_indexes = Valid_Index_Hero(allies);
    if(valid_indexes[3] == 0)
        return false;
    int random_position = std::rand() % valid_indexes[3];
    int selected_index = valid_indexes[random_position];
    allies[selected_index]->Activate_Doping();
    user.Subtract_Energy(Skill2_Energy_Cost);
    return true;
}

bool WhiteDoctor::Execute_SuperPower(Hero_Abstaction* allies[3], User &user, Controller &controller)
{
    if(rounds_left_till_superpower_is_ready != 4)
        return false;
    Seeded();
    // finding  live allies and not  being null and not this
    std::array<int,4> valid_indexes = Valid_Index_Hero(allies, 1);
    if(valid_indexes[3] == 0)
        return false;
    int random_position = std::rand() % valid_indexes[3];
    int selected_index = valid_indexes[random_position];
    controller.Apply_Healed(allies[selected_index], 200);
    user.Subtract_Energy(SuperPower_Energy_Cost);
    return true; 
}

bool WhiteDoctor::Execute_Skill1(Argument_Skills_Functions &parameters)
{
    return Execute_Asprin_Ability(parameters.allies, parameters.enemies, parameters.selected_enemy_index, *parameters.user, *parameters.controller);
}

bool WhiteDoctor::Execute_Skill2(Argument_Skills_Functions &parameters)
{
    return Execute_Doping_Ability(parameters.allies, *parameters.user);
}

bool WhiteDoctor::Execute_SuperSkill(Argument_Skills_Functions &parameters)
{
    return Execute_SuperPower(parameters.allies, *parameters.user, *parameters.controller);
}

int WhiteDoctor::return_rounds_left_till_superpower_is_ready()
{
    return this->rounds_left_till_superpower_is_ready;
}
//----------------------------------------------------------------------------

//-----------------------------------taha kochike-----------------------------

//skill1 --> blood bag
//skill2 --> razor sharp

Taha_Kochike::Taha_Kochike()
{
    this->Current_Hp = 500;
    this->Initial_Hp = 500;
    this->hero_type = HELAER;
    this->Skill2_Energy_Cost = 2;
    this->Skill1_Energy_Cost = 4;
    this->SuperPower_Energy_Cost = 4;
    this->Is_Hero_Dead = false;
    this->rounds_left_till_superpower_is_ready = 3;

    this->Is_serom_Khon_ongoing = false;
    this->Round_since_Serom_khon  = 0;

    this->Rounds_Since_Doping = 0;
    this->Is_Doped = false;
    this->Is_Family_StrongHold_ongoing = false;
    this->Round_Since_Family_StrongHold = 0;
    this->amount_damage_when_family_stronghold_is_active = 0;
    this->Is_Brother_Revenge_Ongoing = false;
    this->Round_Brother_Revenge_Left = 0;
    this->Is_Dom_KajDom_Ongoing = false;
    this->Round_Dom_KajDom_Left = 0; 
    this->Is_Ghofli_ongoing = false;
    this->amount_of_the_last_damage_done = 0;
}

bool Taha_Kochike::Execute_Tigh_Tiz_Ability_Healed(Hero_Abstaction* allies[3], User &user, Controller &controller)
{
    //find the ally with the lowest Hp
    Hero_Abstaction* Lowest_Hp_Ally = Find_Highest_Or_Lowest_Hp(allies);
    if(Lowest_Hp_Ally == nullptr)
        return false;
    controller.Apply_Healed(Lowest_Hp_Ally, 20);
    user.Subtract_Energy(Skill2_Energy_Cost);
    
    return true; 
}

bool Taha_Kochike::Execute_Tigh_Tiz_Ability_Damage(Hero_Abstaction* enemies[3], int selected_enemy_index, User &user, Controller &controller)
{
    if(selected_enemy_index < 0 || selected_enemy_index >= 3)
        return false;
    if(enemies[selected_enemy_index] == nullptr || enemies[selected_enemy_index]->Is_Dead())
        return false;
    if(!enemies[selected_enemy_index]->Return_Is_Hidden())
        controller.Apply_Damaged(enemies[selected_enemy_index], 30);
    
    return true;
}

bool Taha_Kochike::Execute_Tigh_Tiz_Abillity(Hero_Abstaction* allies[3], Hero_Abstaction* enemies[3], int selected_enemy_index, User &user, Controller &controller)
{
    if(Execute_Tigh_Tiz_Ability_Healed(allies, user, controller) && Execute_Tigh_Tiz_Ability_Damage(enemies, selected_enemy_index, user, controller))
        return true;
    return false;
}

bool Taha_Kochike::Execute_Serom_Khon_Ability(Hero_Abstaction* allies[3], User &user)
{
    Seeded();
    std::array<int,4> valid_indexes = Valid_Index_Hero(allies);
    if(valid_indexes[3] == 0)
        return false;
    int random_position = std::rand() % valid_indexes[3];
    int selected_index = valid_indexes[random_position];
    allies[selected_index]->Activate_Serom_Khon();
    user.Subtract_Energy(Skill1_Energy_Cost);
    
    return true;
}

bool Taha_Kochike::Execute_SuperPower(Hero_Abstaction* allies[3], User &user, Controller &controller)
{
    if(rounds_left_till_superpower_is_ready != 3)
        return false;
    Hero_Abstaction* Lowest_Hp_Ally = Find_Highest_Or_Lowest_Hp(allies);
    if(Lowest_Hp_Ally == nullptr)
        return false;
    controller.Apply_Healed( Lowest_Hp_Ally, 200);
    user.Subtract_Energy(SuperPower_Energy_Cost);
    return true;   
}

bool Taha_Kochike::Execute_Skill1(Argument_Skills_Functions &parameters)
{
    return Execute_Serom_Khon_Ability(parameters.allies, *parameters.user);
}

bool Taha_Kochike::Execute_Skill2(Argument_Skills_Functions &parameters)
{
    return Execute_Tigh_Tiz_Abillity(parameters.allies, parameters.enemies, parameters.selected_enemy_index, *parameters.user, *parameters.controller);
}

bool Taha_Kochike::Execute_SuperSkill(Argument_Skills_Functions &parameters)
{
    return Execute_SuperPower(parameters.allies, *parameters.user, *parameters.controller);
}

int Taha_Kochike::return_rounds_left_till_superpower_is_ready()
{
    return this->rounds_left_till_superpower_is_ready;
}

//----------------------------------------------------------------------------

//-----------------------------------dani golang------------------------------
//skill1 --> fil kosh
//skill2 --> the lock

Dani_Golang::Dani_Golang()
{
    this->Current_Hp = 600;
    this->Initial_Hp = 600;
    this->hero_type = DEFENDER;
    this->Last_Attacked_Enemy = 3; // any number except from [0,3)
    this->Skill2_Energy_Cost = 2;
    this->Skill1_Energy_Cost = 4;
    this->SuperPower_Energy_Cost = 4;
    this->Is_Hero_Dead = false;
    this->rounds_left_till_superpower_is_ready = 4;

    this->Is_Family_StrongHold_ongoing = false;
    this->Round_Since_Family_StrongHold = 0;
    this->amount_damage_when_family_stronghold_is_active = 0;
    this->Is_Ghofli_ongoing = false;
    this->amount_of_the_last_damage_done = 0;
    
    this->Rounds_Since_Doping = 0;
    this->Is_Doped = false;
    this->Is_serom_Khon_ongoing = false;
    this->Round_since_Serom_khon =  0;
    this->Is_Brother_Revenge_Ongoing = false;
    this->Round_Brother_Revenge_Left = 0;
    this->Is_Dom_KajDom_Ongoing = false;
    this->Round_Dom_KajDom_Left = 0;
}

bool Dani_Golang::Execute_Ghofli_Ability(Hero_Abstaction* enemies[3], int selected_enemy_index, User &user, Controller &controller)
{
    if(selected_enemy_index < 0 || selected_enemy_index >= 3)
        return false;
    if(Last_Attacked_Enemy != selected_enemy_index)
    {
        Last_Attacked_Enemy = selected_enemy_index;
        if(!enemies[selected_enemy_index]->Return_Is_Hidden())
            controller.Apply_Damaged(enemies[selected_enemy_index], 20);
        enemies[selected_enemy_index]->Activate_Ghofli();
    }
    else 
    {
        if(!enemies[Last_Attacked_Enemy]->Return_Is_Hidden())
            controller.Apply_Damaged(enemies[Last_Attacked_Enemy], amount_of_the_last_damage_done);
    }
    user.Subtract_Energy(Skill2_Energy_Cost);
    
    return true;
}

bool Dani_Golang::Execute_Fil_kosh_Ability(Hero_Abstaction* enemies[3], int selected_enemy_index, User &user, Controller &controller)
{
    if(selected_enemy_index < 0 || selected_enemy_index >= 3)
        return false;
    Hero_Abstaction* Highest_Hp_Enemy = Find_Highest_Or_Lowest_Hp(enemies, "max");
    if(Highest_Hp_Enemy == nullptr)
        return false;
    if(!enemies[selected_enemy_index]->Return_Is_Hidden())
        controller.Apply_Damaged(Highest_Hp_Enemy, 50);
    if(selected_enemy_index < 0 || selected_enemy_index >= 3 || enemies[selected_enemy_index] == nullptr)
        return false;
    if(!enemies[selected_enemy_index]->Return_Is_Hidden())
        controller.Apply_Damaged(enemies[selected_enemy_index], 50);
    user.Subtract_Energy(Skill1_Energy_Cost);
    
    return true;
}

bool Dani_Golang::Execute_SuperPower(Hero_Abstaction* allies[3], User &user)
{
    if(rounds_left_till_superpower_is_ready != 4)
        return false;
    Hero_Abstaction* Lowest_Hp_Ally = Find_Highest_Or_Lowest_Hp(allies);
    if(Lowest_Hp_Ally == nullptr)
        return false;
    Lowest_Hp_Ally->Activate_Family_StrongHold();
    user.Subtract_Energy(SuperPower_Energy_Cost);
    return true;
}

bool Dani_Golang::Execute_Skill1(Argument_Skills_Functions &parameters)
{
    return Execute_Fil_kosh_Ability(parameters.enemies, parameters.selected_enemy_index, *parameters.user, *parameters.controller);
}

bool Dani_Golang::Execute_Skill2(Argument_Skills_Functions &parameters)
{
    return Execute_Ghofli_Ability(parameters.enemies, parameters.selected_enemy_index, *parameters.user, *parameters.controller);
}

bool Dani_Golang::Execute_SuperSkill(Argument_Skills_Functions &parameters)
{
    return Execute_SuperPower(parameters.allies, *parameters.user);
}

int Dani_Golang::return_rounds_left_till_superpower_is_ready()
{
    return this->rounds_left_till_superpower_is_ready;
}
//----------------------------------------------------------------------------

//-----------------------------------amin emeni-------------------------------
//skill1 --> friendly fire
//skill2 --> last bullet

Amin_Emeni::Amin_Emeni()
{
    this->Current_Hp = 500;
    this->Initial_Hp = 500;
    this->hero_type = ATTACKER;
    this->Skill1_Energy_Cost = 3;
    this->Skill2_Energy_Cost = 3;
    this->SuperPower_Energy_Cost = 4;
    this->Is_Hero_Dead = false;
    this->rounds_left_till_superpower_is_ready = 3;

    this->Rounds_Since_Doping = 0;
    this->Is_Doped = false;
    this->Is_serom_Khon_ongoing = false;
    this->Round_since_Serom_khon =  0;
    this->Is_Family_StrongHold_ongoing = false;
    this->Round_Since_Family_StrongHold = 0;
    this->amount_damage_when_family_stronghold_is_active = 0;
    this->Is_Brother_Revenge_Ongoing = false;
    this->Round_Brother_Revenge_Left = 0;
    this->Is_Dom_KajDom_Ongoing = false;
    this->Round_Dom_KajDom_Left = 0;
    this->Is_Ghofli_ongoing = false;
    this->amount_of_the_last_damage_done = 0;
}

bool Amin_Emeni::Execute_Akharin_Feshang_Ability(Hero_Abstaction* enemies[3], int selected_enemy_index, User &user, Controller &controller)
{
    if(selected_enemy_index < 0 || selected_enemy_index >= 3)
        return false;
    if(enemies[selected_enemy_index]->Get_Current_Hp() <= 110)
    {
        if(!enemies[selected_enemy_index]->Return_Is_Hidden())
            controller.Apply_Damaged(enemies[selected_enemy_index], 110);
    }
    else
    {
        if(!enemies[selected_enemy_index]->Return_Is_Hidden())
            controller.Apply_Damaged(enemies[selected_enemy_index], 55);
    }
    user.Subtract_Energy(Skill2_Energy_Cost);
    
    return true;
}

bool Amin_Emeni::Execute_Zarbe_Be_Khody_Ability(Hero_Abstaction* allies[3], User &user, Controller &controller)
{
    Seeded();
    std::array<int,4> valid_indexes = Valid_Index_Hero(allies);
    if(valid_indexes[3] == 0)
        return false;
    int random_position = std::rand() % valid_indexes[3];
    int selected_index = valid_indexes[random_position];

    if(!allies[selected_index]->Return_Is_Hidden())
        controller.Apply_Damaged(allies[selected_index], 25);
    controller.Apply_Healed(this, 75);
    user.Subtract_Energy(Skill1_Energy_Cost);
    
    return true;
}

bool Amin_Emeni::Execute_SuperPower(Hero_Abstaction* allies[3], Hero_Abstaction* enemies[3], User &user, Controller &controller)
{
    if(rounds_left_till_superpower_is_ready != 3)
        return false;
    Seeded();
    std::array<int,4> valid_indexes = Valid_Index_Hero(enemies);
    if(valid_indexes[3] == 0)
        return false;
    int random_position = std::rand() % valid_indexes[3];
    int selected_index = valid_indexes[random_position];
    if(!enemies[selected_index]->Return_Is_Hidden())
        controller.Apply_Damaged(enemies[selected_index], 250);
    for(int i = 0; i < 3; i++)
    {
        if(allies[i] != nullptr && !allies[i]->Is_Dead() && allies[i] != this)
            if(!allies[i]->Return_Is_Hidden())
                controller.Apply_Damaged(allies[i], 30);
    }
    user.Subtract_Energy(SuperPower_Energy_Cost);
    return true;
}

bool Amin_Emeni::Execute_Skill1(Argument_Skills_Functions &parameters)
{
    return Execute_Zarbe_Be_Khody_Ability(parameters.allies, *parameters.user, *parameters.controller);
}

bool Amin_Emeni::Execute_Skill2(Argument_Skills_Functions &parameters)
{
    return Execute_Akharin_Feshang_Ability(parameters.enemies, parameters.selected_enemy_index, *parameters.user, *parameters.controller);
}

bool Amin_Emeni::Execute_SuperSkill(Argument_Skills_Functions &parameters)
{
    return Execute_SuperPower(parameters.allies, parameters.enemies, *parameters.user, *parameters.controller);
}

int Amin_Emeni::return_rounds_left_till_superpower_is_ready()
{
    return this->rounds_left_till_superpower_is_ready;
}
//----------------------------------------------------------------------------

//-----------------------------------taha bozorge-----------------------------
//skill1 --> machine gun
//skill2 --> xray

Taha_Bozorge::Taha_Bozorge()
{
    this->Current_Hp = 500;
    this->Initial_Hp = 500;
    this->hero_type = ATTACKER;
    this->Skill2_Energy_Cost = 4;
    this->Skill1_Energy_Cost = 3;
    this->SuperPower_Energy_Cost = 4;
    this->Is_Hero_Dead = false;
    this->rounds_left_till_superpower_is_ready = 4;

    this->Rounds_Since_Doping = 0;
    this->Is_Doped = false;
    this->Is_serom_Khon_ongoing = false;
    this->Round_since_Serom_khon =  0;
    this->Is_Family_StrongHold_ongoing = false;
    this->Round_Since_Family_StrongHold = 0;
    this->amount_damage_when_family_stronghold_is_active = 0;

    this->Is_Hidden = false;
    this->Hidden_Round_Left = 0; 
    this->Is_Brother_Revenge_Ongoing = false;
    this->Round_Brother_Revenge_Left = 0;
    this->Is_Dom_KajDom_Ongoing = false;
    this->Round_Dom_KajDom_Left = 0;
    this->Is_Ghofli_ongoing = false;
    this->amount_of_the_last_damage_done = 0;
}

bool Taha_Bozorge::Execute_Ragbar_Ability(Hero_Abstaction* enemies[3], User &user, Controller &controller)
{
    for(int i = 0; i < 3; i++)
    {
        if(enemies[i] != nullptr && !enemies[i]->Is_Dead())
            controller.Apply_Damaged(enemies[i], 30);
    }
    user.Subtract_Energy(Skill1_Energy_Cost);
    
    return true;
}

bool Taha_Bozorge::Execute_Xray_Ability(Hero_Abstaction* enemies[3], int selected_enemy_index , User &user, Controller &controller)
{
    if(selected_enemy_index < 0 || selected_enemy_index >= 3)
        return false;
    Is_Hidden = true;
    Hidden_Round_Left = 1;
    if(!enemies[selected_enemy_index]->Return_Is_Hidden())
        controller.Apply_Damaged(enemies[selected_enemy_index], 90);
    user.Subtract_Energy(Skill2_Energy_Cost);
    
    return true;
}

bool Taha_Bozorge::Execute_SuperPower(Hero_Abstaction* enemies[3], User &user)
{
    if(rounds_left_till_superpower_is_ready != 4)
        return false;
    Seeded();
    std::array<int,4> valid_indexes = Valid_Index_Hero(enemies);
    if(valid_indexes[3] == 0)
        return false;
    int random_position = std::rand() % valid_indexes[3];
    int selected_index = valid_indexes[random_position];
    enemies[selected_index]->Activate_Brother_revenge();
    return true;
}

bool Taha_Bozorge::Execute_Skill1(Argument_Skills_Functions &parameters)
{
    return Execute_Ragbar_Ability(parameters.enemies, *parameters.user, *parameters.controller);
}

bool Taha_Bozorge::Execute_Skill2(Argument_Skills_Functions &parameters)
{
    return Execute_Xray_Ability(parameters.enemies, parameters.selected_enemy_index, *parameters.user, *parameters.controller);
}

bool Taha_Bozorge::Execute_SuperSkill(Argument_Skills_Functions &parameters)
{
    return Execute_SuperPower(parameters.enemies, *parameters.user);
}

int Taha_Bozorge::return_rounds_left_till_superpower_is_ready()
{
    return this->rounds_left_till_superpower_is_ready;
}
//----------------------------------------------------------------------------

//-----------------------------------pouya kajdom-----------------------------
//skill1 --> dagger
//skill2 --> scorpion

Pouya_Kajdom::Pouya_Kajdom()
{
    this->Current_Hp = 550;
    this->Initial_Hp = 550;
    this->hero_type = ATTACKER;
    this->Skill1_Energy_Cost = 2;
    this->Skill2_Energy_Cost = 4;
    this->SuperPower_Energy_Cost = 5;
    this->Is_Hero_Dead = false;
    this->rounds_left_till_superpower_is_ready = 4;
    for(int i = 0 ; i < 3 ; i++)
    {
        this->Enemy_Array_With_Respect_To_Active_Scorpiens[i] = NONE;
    }
    this->Is_Dom_KajDom_Ongoing = false;
    this->Round_Dom_KajDom_Left = 0;

    this->Is_Hidden = false;
    this->Hidden_Round_Left = 0; 

    this->Rounds_Since_Doping = 0;
    this->Is_Doped = false;
    this->Is_serom_Khon_ongoing = false;
    this->Round_since_Serom_khon =  0;
    this->Is_Family_StrongHold_ongoing = false;
    this->Round_Since_Family_StrongHold = 0;
    this->amount_damage_when_family_stronghold_is_active = 0;
    this->Is_Brother_Revenge_Ongoing = false;
    this->Round_Brother_Revenge_Left = 0;
    this->Is_Ghofli_ongoing = false;
    this->amount_of_the_last_damage_done = 0;
}

bool Pouya_Kajdom::Activate_scorpien(Hero_Abstaction* enemies[3], Controller &controller)
{
    for(int i = 0; i < 3; i++)
    {
        switch (Enemy_Array_With_Respect_To_Active_Scorpiens[i])
        {
            case SCORPIEN:
                if(!enemies[i]->Return_Is_Hidden())
                    controller.Apply_Damaged(enemies[i], 20);
                break;
            case BUFFED_SCORPIEN:
                if(!enemies[i]->Return_Is_Hidden())
                    controller.Apply_Damaged(enemies[i], 60);
                break;
        }
    }
    return true;
}

bool Pouya_Kajdom::Execute_Khanjar_Ability(Hero_Abstaction* enemies[3], int selected_enemy_index, User &user, Controller &controller)
{
    if(selected_enemy_index < 0 || selected_enemy_index >= 3)
        return false;
    if(Enemy_Array_With_Respect_To_Active_Scorpiens[selected_enemy_index] == BUFFED_SCORPIEN)
        return false;
    Enemy_Array_With_Respect_To_Active_Scorpiens[selected_enemy_index] = BUFFED_SCORPIEN;
    Activate_scorpien(enemies, controller);
    user.Subtract_Energy(Skill1_Energy_Cost);
    
    return true;
}

bool Pouya_Kajdom::Execute_Aghrab_Ability(Hero_Abstaction* enemies[3], int selected_enemy_index, User &user, Controller &controller)
{
    if(selected_enemy_index < 0 || selected_enemy_index >= 3)
        return false;
    if(Enemy_Array_With_Respect_To_Active_Scorpiens[selected_enemy_index] == SCORPIEN)
        return false;
    Enemy_Array_With_Respect_To_Active_Scorpiens[selected_enemy_index] =  SCORPIEN;
    Activate_scorpien(enemies, controller);
    user.Subtract_Energy(Skill2_Energy_Cost);
    
    return true;
}

bool Pouya_Kajdom::Execute_SuperPower(Hero_Abstaction* enemies[3], User &user)
{
    if(rounds_left_till_superpower_is_ready != 4)
        return false;
    Is_Hidden = true;
    Hidden_Round_Left = 3;
    Seeded();
    std::array<int,4> valid_indexes = Valid_Index_Hero(enemies);
    if(valid_indexes[3] == 0)
        return false;
    int random_position = std::rand() % valid_indexes[3];
    int selected_index = valid_indexes[random_position];
    enemies[selected_index]->Activate_Dom_Kajdom();
    user.Subtract_Energy(SuperPower_Energy_Cost);
    return true;
}

bool Pouya_Kajdom::Execute_Skill1(Argument_Skills_Functions &parameters)
{
    return Execute_Khanjar_Ability(parameters.enemies, parameters.selected_enemy_index, *parameters.user, *parameters.controller);
}

bool Pouya_Kajdom::Execute_Skill2(Argument_Skills_Functions &parameters)
{
    return Execute_Aghrab_Ability(parameters.enemies, parameters.selected_enemy_index, *parameters.user, *parameters.controller);
}

bool Pouya_Kajdom::Execute_SuperSkill(Argument_Skills_Functions &parameters)
{
    return Execute_SuperPower(parameters.enemies, *parameters.user);
}

int Pouya_Kajdom::return_rounds_left_till_superpower_is_ready()
{
    return this->rounds_left_till_superpower_is_ready;
}
//----------------------------------------------------------------------------

//-----------------------------------agha shahriar----------------------------
//skill1 --> dummy
//skill2 --> stubborn

Agha_Shahriar::Agha_Shahriar()
{
    this->Current_Hp = 500;
    this->Initial_Hp = 500;
    this->hero_type = JOKER;
    this->Skill2_Energy_Cost = 4;
    this->Skill1_Energy_Cost = 2;
    this->SuperPower_Energy_Cost = 8;
    this->Is_Hero_Dead = false;
    this->rounds_left_till_superpower_is_ready = 4;

    this->Rounds_Since_Doping = 0;
    this->Is_Doped = false;
    this->Is_serom_Khon_ongoing = false;
    this->Round_since_Serom_khon =  0;
    this->Is_Family_StrongHold_ongoing = false;
    this->Round_Since_Family_StrongHold = 0;
    this->amount_damage_when_family_stronghold_is_active = 0;
    this->Is_Brother_Revenge_Ongoing = false;
    this->Round_Brother_Revenge_Left = 0;
    this->Is_Dom_KajDom_Ongoing = false;
    this->Round_Dom_KajDom_Left = 0;
    this->Is_Ghofli_ongoing = false;
    this->amount_of_the_last_damage_done = 0;
}

bool Agha_Shahriar::Execute_Maskhare_Ability(Hero_Abstaction* enemies[3], int selected_enemy_index, User &user, Controller &controller)
{
    if(selected_enemy_index < 0 || selected_enemy_index >= 3)
        return false;
    Seeded();
    int chance = rand() % 100 + 1;
    if(chance > 80)
        if(!enemies[selected_enemy_index]->Return_Is_Hidden())
            controller.Apply_Damaged(enemies[selected_enemy_index], 60);
    user.Subtract_Energy(Skill1_Energy_Cost);
    
        return true;
}

bool Agha_Shahriar::Execute_Lajbaz_Ability(Hero_Abstaction* enemies[3], int selected_enemy_index, User &user, Controller &controller)
{
    if(selected_enemy_index < 0 || selected_enemy_index >= 3)
        return false;
    if(enemies[selected_enemy_index] == nullptr || enemies[selected_enemy_index]->Is_Dead())
        return false;
    if(!enemies[selected_enemy_index]->Return_Is_Hidden())
        controller.Apply_Damaged(enemies[selected_enemy_index], 100);
    Seeded();
    while (true)
    {
        std::array<int,4> valid_indexes = Valid_Index_Hero(enemies);
        if(valid_indexes[3] == 0)
            return false;
        int random_position = std::rand() % valid_indexes[3];
        int selected_index = valid_indexes[random_position];
        if(enemies[selected_index] != enemies[selected_enemy_index])
        {
            if(!enemies[selected_index]->Return_Is_Hidden())
            {
                controller.Apply_Damaged(enemies[selected_index], 100);
                break;
            }
        }
    }
    user.Subtract_Energy(Skill2_Energy_Cost);
    
    return true;
}

bool Agha_Shahriar::Execute_SuperPower(User &user, Controller &controller)
{
    if(rounds_left_till_superpower_is_ready != 4)
        return false;
    controller.Activate_Reverse_World();
    user.Subtract_Energy(SuperPower_Energy_Cost);
    return true;
}

bool Agha_Shahriar::Execute_Skill1(Argument_Skills_Functions &parameters)
{
    return Execute_Maskhare_Ability(parameters.enemies, parameters.selected_enemy_index, *parameters.user, *parameters.controller);
}

bool Agha_Shahriar::Execute_Skill2(Argument_Skills_Functions &parameters)
{
    return Execute_Lajbaz_Ability(parameters.enemies, parameters.selected_enemy_index, *parameters.user, *parameters.controller);
}

bool Agha_Shahriar::Execute_SuperSkill(Argument_Skills_Functions &parameters)
{
    return Execute_SuperPower(*parameters.user, *parameters.controller);
}

int Agha_Shahriar::return_rounds_left_till_superpower_is_ready()
{
    return this->rounds_left_till_superpower_is_ready;
}
//----------------------------------------------------------------------------
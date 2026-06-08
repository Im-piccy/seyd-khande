#include "../headers/hero_abstract_base_class.hpp"
#include "../headers/hero_sub_class_to_instatniate_objects.hpp"

// -----------------------------white doctor----------------------------------
WhiteDoctor::WhiteDoctor()
{
    this->Current_Hp = 550;
    this->Initial_Hp = 550;
    this->hero_type = HELAER;
    this->Asprin_Ability_Energy_Cost = 3;
    this->Doping_Ability_Energy_Cost = 4;
    this->SuperPower_Energy_Cost = 4;
    this->Is_Hero_Dead = false;
    this->rounds_left_till_superpower_is_ready = 4;
    this->Rounds_Since_Doping = 0;
    this->Is_Doping_Ongoing = false;
}

bool WhiteDoctor::Execute_Asprin_Ability_Healed(Hero_Abstaction* allies[3], User &user)
{
    if(user.Get_Energy() < Asprin_Ability_Energy_Cost)
        return false;
    Seeded();
    std::array<int,4> valid_indexes = Valid_Index_Hero(allies);
    if(valid_indexes[3] == 0)
        return false;
    int random_position = std::rand() % valid_indexes[3];
    int selected_index = valid_indexes[random_position];

    allies[selected_index]->Get_Healed(40);
    user.Set_Energy(Asprin_Ability_Energy_Cost);
    return true;
}

bool WhiteDoctor::Execute_Asprin_Ability_Damaged(Hero_Abstaction* enemy, User &user)
{
    if(user.Get_Energy() < Asprin_Ability_Energy_Cost)
        return false;
    if(enemy == nullptr)
        return false;
    if(enemy->Is_Dead())
        return false;
    enemy->Get_Damaged(40);
    user.Set_Energy(Asprin_Ability_Energy_Cost);
    return true;
}

bool WhiteDoctor::Execute_Doping_Ability(Hero_Abstaction* enemy, float damage_amount, User &user)
{
    if(user.Get_Energy() < Doping_Ability_Energy_Cost)
        return false;
    Is_Doping_Ongoing = true;
    if(Rounds_Since_Doping >= 2)
    {
        Rounds_Since_Doping = 0;
        user.Set_Energy(Doping_Ability_Energy_Cost);
        return false;
    }
    damage_amount += damage_amount * 0.2;
    enemy->Get_Damaged(damage_amount);
    Rounds_Since_Doping++;
    return true;
}

bool WhiteDoctor::Execute_SuperPower(Hero_Abstaction* allies[3], User &user)
{
    if(user.Get_Energy() < SuperPower_Energy_Cost)
        return false;
    if(rounds_left_till_superpower_is_ready != 4)
        return false;
    Seeded();
    // finding  live allies and not  being null and not this
    std::array<int,4> valid_indexes = Valid_Index_Hero(allies, 1);
    if(valid_indexes[3] == 0)
        return false;
    int random_position = std::rand() % valid_indexes[3];
    int selected_index = valid_indexes[random_position];
    allies[selected_index]->Get_Healed(200);
    user.Set_Energy(SuperPower_Energy_Cost);
    rounds_left_till_superpower_is_ready = 0;
    return true; 
}

//----------------------------------------------------------------------------

//-----------------------------------taha kochike-----------------------------

Taha_Kochike::Taha_Kochike()
{
    this->Current_Hp = 500;
    this->Initial_Hp = 500;
    this->hero_type = HELAER;
    this->Tigh_Tiz_Ability_Energy_Cost = 2;
    this->Serom_Khon_Ability_Energy_Cost = 4;
    this->SuperPower_Energy_Cost = 4;
    this->Is_Hero_Dead = false;
    this->rounds_left_till_superpower_is_ready = 3;
    this->Is_serom_Khon_ongoing = false;
    this->Round_since_Serom = 0;
    
}

bool Taha_Kochike::Execute_Tigh_Tiz_Ability_Healed(Hero_Abstaction* allies[3], User &user)
{
    if(user.Get_Energy() < Tigh_Tiz_Ability_Energy_Cost)
        return false;
    //find the ally with the lowest Hp
    Hero_Abstaction* Lowest_Hp_Ally = Find_Highest_Or_Lowest_Hp(allies);
    if(Lowest_Hp_Ally == nullptr)
        return false;
    Lowest_Hp_Ally->Get_Healed(20);
    user.Set_Energy(Tigh_Tiz_Ability_Energy_Cost);
    return true; 
}

bool Taha_Kochike::Execute_Tigh_Tiz_Ability_Damage(Hero_Abstaction* enemy, User &user)
{
    if(user.Get_Energy() < Tigh_Tiz_Ability_Energy_Cost)
        return false;
    if(enemy == nullptr)
        return false;
    if(enemy->Is_Dead())
        return false;
    enemy->Get_Damaged(30);
    user.Set_Energy(Tigh_Tiz_Ability_Energy_Cost);
    return true;
}

bool Taha_Kochike::Execute_Serom_Khon_Ability(Hero_Abstaction* ally, User &user)
{
    if(user.Get_Energy() < Serom_Khon_Ability_Energy_Cost)
        return false;
    Is_serom_Khon_ongoing = true;
    if(Round_since_Serom >= 2)
    {
        user.Set_Energy(Serom_Khon_Ability_Energy_Cost);
        Round_since_Serom = 0;
    }
    ally->Get_Healed(40);
    Round_since_Serom++;
    return true;
}

bool Taha_Kochike::Execute_SuperPower(Hero_Abstaction* allies[3], User &user)
{
    if(user.Get_Energy() < SuperPower_Energy_Cost)
        return false;
    if(rounds_left_till_superpower_is_ready != 3)
        return false;
    Hero_Abstaction* Lowest_Hp_Ally = Find_Highest_Or_Lowest_Hp(allies);
    if(Lowest_Hp_Ally == nullptr)
        return false;
    Lowest_Hp_Ally->Get_Healed(200);
    user.Set_Energy(SuperPower_Energy_Cost);
    rounds_left_till_superpower_is_ready = 0;
    return true;   
}

//----------------------------------------------------------------------------

//-----------------------------------dani golang------------------------------
Dani_Golang::Dani_Golang()
{
    this->Current_Hp = 600;
    this->Initial_Hp = 600;
    this->hero_type = DEFENDER;
    this->Ghofli_Ability_Energy_Cost = 2;
    this->Repete_Ghofli_Ability = false;
    this->Round_Use_Ghofli_Ability = 0;
    this->Fil_kosh_Ability_Energy_Cost = 4;
    this->SuperPower_Energy_Cost = 4;
    this->Start_SuperPower =  false;
    this->Is_Hero_Dead = false;
    this->Round_Use_SuperPower = 0;
    this->rounds_left_till_superpower_is_ready = 4;    
}

bool Dani_Golang::Execute_Ghofli_Ability(Hero_Abstaction* enemy, User &user)
{
    if(user.Get_Energy() < Ghofli_Ability_Energy_Cost)
        return false;
    if(Repete_Ghofli_Ability && Round_Use_Ghofli_Ability == 1)
    {
        enemy->Get_Damaged(38);
        Repete_Ghofli_Ability = false;
        Round_Use_Ghofli_Ability = 0;
    }
    enemy->Get_Damaged(20);
    Round_Use_Ghofli_Ability++;
    Repete_Ghofli_Ability = true;
    user.Set_Energy(Ghofli_Ability_Energy_Cost);
    return true;
}

bool Dani_Golang::Execute_Fil_kosh_Ability(Hero_Abstaction* enemies[3], int selected_enemy_index, User &user)
{
    if(user.Get_Energy() < Fil_kosh_Ability_Energy_Cost)
        return false;
    Hero_Abstaction* Highest_Hp_Enemy = Find_Highest_Or_Lowest_Hp(enemies, 1);
    if(Highest_Hp_Enemy == nullptr)
        return false;
    Highest_Hp_Enemy->Get_Damaged(50);
    if(selected_enemy_index < 0 || selected_enemy_index >= 3 || enemies[selected_enemy_index] == nullptr)
        return false;
    enemies[selected_enemy_index]->Get_Damaged(50);
    user.Set_Energy(Fil_kosh_Ability_Energy_Cost);
    return true;
}

bool Dani_Golang::Execute_SuperPower(Hero_Abstaction* allies[3], User &user)
{
    if(user.Get_Energy() < SuperPower_Energy_Cost)
        return false;
    if(rounds_left_till_superpower_is_ready != 4)
        return false;
    Hero_Abstaction* Lowest_Hp_Ally = Find_Highest_Or_Lowest_Hp(allies);
    if(Lowest_Hp_Ally == nullptr)
        return false;

    int Amount_Hp_Befor_Healed =  Get_Current_Hp();
    Start_SuperPower = true;
    Round_Use_SuperPower++;
    int Amount_Hp_After_Healed = Get_Current_Hp();

    if(Start_SuperPower && Round_Use_SuperPower == 2)
        Lowest_Hp_Ally->Get_Damaged(250);
    else if(Amount_Hp_Befor_Healed - Amount_Hp_After_Healed < 250)
        Lowest_Hp_Ally->Get_Damaged(250);  
    
    rounds_left_till_superpower_is_ready = 0;
    user.Set_Energy(SuperPower_Energy_Cost);
    Lowest_Hp_Ally->Get_Healed(250);
    return true;
}
//----------------------------------------------------------------------------

//-----------------------------------amin emeni-------------------------------
Amin_Emeni::Amin_Emeni()
{
    this->Current_Hp = 500;
    this->Initial_Hp = 500;
    this->hero_type = ATTACKER;
    this->Zarbe_Be_Khodi_Ability_Energy_Cost = 3;
    this->Akharin_Feshang_Ability_Energy_Cost = 3;
    this->SuperPower_Energy_Cost = 4;
    this->Is_Hero_Dead = false;
    this->rounds_left_till_superpower_is_ready = 3;
}
//----------------------------------------------------------------------------

//-----------------------------------taha bozorge-----------------------------
Taha_Bozorge::Taha_Bozorge()
{
    this->Current_Hp = 500;
    this->Initial_Hp = 500;
    this->hero_type = ATTACKER;
    this->Xray_Ability_Energy_Cost = 4;
    this->Ragbar_Ability_Energy_Cost = 3;
    this->SuperPower_Energy_Cost = 4;
    this->Is_Hero_Dead = false;
    this->rounds_left_till_superpower_is_ready = 4;
    this->Is_Xray_Ongoing = false;
    this->Rounds_Since_Xray = 0;
}
//----------------------------------------------------------------------------

//-----------------------------------pouya kajdom-----------------------------
Pouya_Kajdom::Pouya_Kajdom()
{
    this->Current_Hp = 550;
    this->Initial_Hp = 550;
    this->hero_type = ATTACKER;
    this->Khanjar_Ability_Energy_Cost = 2;
    this->Aghrab_Ability_Energy_Cost = 4;
    this->SuperPower_Energy_Cost = 5;
    this->Is_Hero_Dead = false;
    this->rounds_left_till_superpower_is_ready = 3;
    for(int i = 0 ; i < 3 ; i++)
    {
        this->Enemy_Array_With_Respect_To_Active_Scorpiens[i] = NONE;
    }
    Is_SuperPower_Active = false;
}
//----------------------------------------------------------------------------

//-----------------------------------agha shahriar----------------------------
Agha_Shahriar::Agha_Shahriar()
{
    this->Current_Hp = 500;
    this->Initial_Hp = 500;
    this->hero_type = JOKER;
    this->Lajbaz_Ability_Energy_Cost = 4;
    this->Maskhare_Ability_Energy_Cost = 2;
    this->SuperPower_Energy_Cost = 8;
    this->Is_Hero_Dead = false;
    this->rounds_left_till_superpower_is_ready = 4;
    this->Is_SuperPower_Active = false;
    this->Rounds_Since_SuperPower = 0;
    
}
//----------------------------------------------------------------------------
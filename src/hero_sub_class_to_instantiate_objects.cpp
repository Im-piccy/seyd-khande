#include "headers/hero_abstract_base_class.hpp"
#include "headers/hero_sub_class_to_instatniate_objects.hpp"

// ----------------------------------white doctor-----------------------------
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


//----------------------------------------------------------------------------

//-----------------------------------dani golang------------------------------
Dani_Golang::Dani_Golang()
{
    this->Current_Hp = 600;
    this->Initial_Hp = 600;
    this->hero_type = DEFENDER;
    this->Ghofli_Ability_Energy_Cost = 2;
    this->Fil_kosh_Ability_Energy_Cost = 4;
    this->SuperPower_Energy_Cost = 4;
    this->Is_Hero_Dead = false;
    this->rounds_left_till_superpower_is_ready = 4;
     
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
#include "headers/hero_abstract_base_class.hpp"
#include "headers/hero_sub_class_to_instatniate_objects.hpp"

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

//--------------------------------------------------------------------------

//-------------------------------- taha kochike ----------------------------

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

//---------------------------------dani golang--------------------------------
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
#ifndef HERO_ABSTRACT_BASE_CLASS_HPP
#define HERO_ABSTRACT_BASE_CLASS_HPP

enum Hero_Type{HELAER, ATTACKER, DEFENDER, JOKER};

class Hero_Abstaction //abstract class
{
    protected:
        int hp; // this shows how much health the hero has got left

        int rounds_left_till_superpower_is_ready;// this shows the number of round it takes to use 
        // super power  if 0 means superpower is ready
        
        bool Is_Hero_Dead;
        int hero_type; // is the hero a Healer? Attacker? Defender? or a joker?
};




#endif
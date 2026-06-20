#ifndef USER_HPP
#define USER_HPP
#include <array>
#include <string>
#include "../headers/controller.hpp"
class User
{
    friend void Controller::Empty_User_Array(User &user);
    friend bool Controller::Is_Hero_Array_Full(User &user);
    public:
        User();
        int Get_Energy() const;
        void Subtract_Energy(int cost);
        void Add_Energy(int energy);
        void Set_Name(const std::string& usrname);// booleaan returned false beacause it was more than 25 char
        std::string Get_Name_String() const;
        std::array<char,26> Get_Name_Char_Array() const;
        void add_hero_to_hero_array(int hero);//when player chooses a hero it will be stored using this function
        std::array<int,3> Get_Hero_Array() const;
    private:
        std::array<int,3> Hero_Arr;// this shows which heros the user possess
        int energy;
        std::array<char,26> username;
};

#endif
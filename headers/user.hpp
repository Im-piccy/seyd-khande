#ifndef USER_HPP
#define USER_HPP
class Hero_Abstaction;
class User
{
    public:
        void call_hero_abillity(); //user decides which hero's ability to use and it tells the controller object
        void terminate_user_turn_manually(); //this means that user is skiping turn or ending attacks before energy is 0
        int return_currnet_energy();
        int Get_Energy() const;
        void Set_Energy(int cost);
    private:
        Hero_Abstaction* Hero_Arr[3];// this shows which heros the user possess
        int energy;
};

#endif
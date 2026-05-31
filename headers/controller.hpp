#ifndef CONTROLLER_HPP
#define CONTROLLER_HPP

class Controller
{
    public:
        bool Is_game_over(); // checks to see if game raound is 15 or one players heros are all dead
        void execute_user_ask_to_use_hero_ability_if_possible(); //it gets user request to atteck and does the logic (considering energy cost)
        void Refill_Players_Energy(); // after each round ends it refill energies accordingly
        void Finish_Round(); // this function increments the private round_number variable by one
    private:
        int round_number; // to keep track of the current game round
        int which_user_started_the_game; // to remember which user started first
};

#endif
#ifndef ENUMS_HPP
#define ENUMS_HPP
enum HERO_TYPE{NONSELECT, WHITEDOCTOR, TAHA_KOCHIKE, DANI_GOLANG, AMIN_EMENI, TAHA_BOZORGE, POUYA_KAJDOM, AGHA_SHAHRIAR};
enum SCREENS{MENU_SCREEN, CHARACTER_SELECT_SCREEN, GAME_SCREEN, GAME_OVER_SCREEN, WINDOWSHOULDCLOSE};
enum ABILITIES{SKILL1, SKILL2, SUPERPOWER, NON};
enum TURN{USER1, USER2};
enum Hero_Type{HELAER, ATTACKER, DEFENDER, JOKER};

class Hero_Abstaction;
class User;
struct Argument_Skills_Functions{
    Hero_Abstaction* allies[3];
    Hero_Abstaction* enemies[3];
    int selected_enemy_index;
    int selected_ally_index;
    User &user;
};

#endif
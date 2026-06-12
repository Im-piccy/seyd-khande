#ifndef INCLUDE_IN_GAME_SCREEN_FILE_HPP
#define INCLUDE_IN_GAME_SCREEN_FILE_HPP

#include "../raylib/include/raylib.h"
#include "enums.hpp"

#include <string>
#include <array>


const float Animation_Duration = 2.0f;
const float Animation_Speed = 25.0f;
const int characters_sprite_sheets_frame_height = 250;


void string_to_char_array(const std::string& st, char out[]);//string should not have more than 25 characters


struct Animation
{
    int First_frame;
    int Last_frame;
    int current_frame;

    float frame_width;
    float frame_height;
    float first_frame_x;
    float first_frame_y;


    float animation_speed;
    float duration_left;
    float initial_duration;
    Rectangle frame;
};

void update_animation_loop(Animation& anim)
{
    anim.duration_left -= GetFrameTime() * anim.animation_speed;
    if(anim.duration_left <= 0)
    {
        anim.current_frame++;
        anim.duration_left = anim.initial_duration;
    }
    if(anim.current_frame > anim.Last_frame)
    {
        anim.current_frame = anim.First_frame;
    }
    anim.frame = {anim.first_frame_x + (anim.frame_width * anim.current_frame), anim.first_frame_y, anim.frame_width, anim.frame_height};
}

void update_animation_once(Animation& anim)
{
    if(anim.current_frame == anim.First_frame)
    {
        return;
    }

    anim.duration_left -= GetFrameTime() * Animation_Speed;
    if(anim.duration_left <= 0)
    {
        anim.duration_left = anim.initial_duration;
        anim.current_frame++;
    }
    if(anim.current_frame > anim.Last_frame)
    {
        anim.current_frame = anim.Last_frame;
    }
    anim.frame = {anim.first_frame_x + (anim.frame_width * anim.current_frame), anim.first_frame_y, anim.frame_width, anim.frame_height};
    
}




void set_frame_width_with_respect_to_the_player(Animation& anim, int width , int user)
{
    if(user == USER2)
    {
        anim.frame_width = width;
    }
    else
    {
        anim.frame_width = -width;
    }
}

void game_screen_draw_abilities_grayed_out(const std::array<Texture2D,3>& textures, const Rectangle & skill1_bound, const Rectangle& skill2_bound, const Rectangle& superpower_bound)
{
    DrawTexture(textures[SKILL1],skill1_bound.x,skill1_bound.y,GRAY);
    DrawTexture(textures[SKILL2],skill2_bound.x,skill2_bound.y,GRAY);
    DrawTexture(textures[SUPERPOWER],superpower_bound.x, superpower_bound.y,GRAY);
            
}

void highlight_ability(const std::array<Texture2D, 3>& textures, const Rectangle & skill1_bound, const Rectangle& skill2_bound, const Rectangle& superpower_bound,ABILITIES skill_to_be_highlighted)
{
    switch (skill_to_be_highlighted)
    {
    case SKILL1:
        DrawTexture(textures[SKILL1],skill1_bound.x,skill1_bound.y,WHITE);
        break;
    
    case SKILL2:
        DrawTexture(textures[SKILL2],skill2_bound.x,skill2_bound.y,WHITE);
        break;
    
    case SUPERPOWER:
        DrawTexture(textures[SUPERPOWER],superpower_bound.x, superpower_bound.y,WHITE);
        break;
    
    default:
        break;
    }
}

void display_ability_defenition_and_detail(const std::array<int,3>& user_hero_array, int user_turn, int hero_index_in_array, ABILITIES which_ability, Font font, Color color)
{
    DrawTextEx(font, "ENERGY REQUIRED", {127.0f - (MeasureTextEx(font,"ENERGY REQUIRED",20.0f,0).x/2),540.0f}, 20.0f, 0.0f,  color);

    switch (user_hero_array[hero_index_in_array])
    {
    case DANI_GOLANG:
        if(which_ability == SKILL1)
        {
            DrawTextEx(font, "FIL KOSH ", {260, 520}, 35,0, color);
            DrawTextEx(font, "DEALS 50 POINTS OF DAMAGE TO THE CHOSEN ENEMY AND THE ENEMY WITH THE HIGHEST HP", {260, 555},15,0, color);
            //extra detail
            DrawTextEx(font, "4 POINTS", {127.0f - (MeasureTextEx(font,"4 POINTS", 20, 0).x /2), 560}, 20, 0,  color);
        }
        else if(which_ability == SKILL2)
        {
            DrawTextEx(font, "THE LOCK: ", {260, 520}, 35,0, color);
            DrawTextEx(font, "DEALS 20 POINTS OF DAMAGE TO THE CHOSEN ENEMY CONSECUTIVE ATTACK TO THE SAME ENEMY INCREASES DAMAGE BY 60%", {260, 555},15,0, color);
            //extra detail
            DrawTextEx(font, "2 POINTS", {127.0f - (MeasureTextEx(font,"2 POINTS", 20, 0).x /2), 560}, 20, 0,  color);
        }
        if(which_ability == SUPERPOWER)
        {
            DrawTextEx(font, "TRENCHES: ", {260, 520}, 35,0, color);
            DrawTextEx(font, "GIVES 250 SHIELD POINTS TO THE LOWEST HP TEAMMATE AND THE EFFECT LASTS FOR 2 ROUNDS", {260, 555},15,0, color);
            //extra detail
            DrawTextEx(font, "4 POINTS", {127.0f - (MeasureTextEx(font,"4 POINTS", 20, 0).x /2), 560}, 20, 0,  color);
        }
        break;
    
    case AMIN_EMENI:
        if(which_ability == SKILL1)
        {
            DrawTextEx(font, "FRIENDLY FIRE:", {260, 520}, 35,0, color);
            DrawTextEx(font, "DEALS 25 POINTS OF DAMAGE TO A RANDOM TEAMMATES AND HEALS HIMSELF BY 75 HP", {260, 555},15,0, color);
            //extra detail
            DrawTextEx(font, "3 POINTS", {127.0f - (MeasureTextEx(font,"3 POINTS", 20, 0).x /2), 560}, 20, 0,  color);
        }
        else if(which_ability == SKILL2)
        {
            DrawTextEx(font, "LAST BULLET: ", {260, 520}, 35,0, color);
            DrawTextEx(font, "DEALS 55 POINTS OF DAMAGE TO THE CHOSEN ENEMY. KILLING THE ENEMY DOUBLES AMIN'S DAMAGE", {260, 555},15,0, color);
            //extra detail
            DrawTextEx(font, "3 POINTS", {127.0f - (MeasureTextEx(font,"3 POINTS", 20, 0).x /2), 560}, 20, 0,  color);
        }
        if(which_ability == SUPERPOWER)
        {
            DrawTextEx(font, "THE SHOUT: ", {260, 520}, 35,0, color);
            DrawTextEx(font, "DEALS 250 POINTS OF DAMAGE TO A RANDOM ENEMY BUT ALSO DAMAGES BOTH TEAMMATES BY 30 POINTS", {260, 555},15,0, color);
            //extra detail
            DrawTextEx(font, "4 POINTS", {127.0f - (MeasureTextEx(font,"4 POINTS", 20, 0).x /2), 560}, 20, 0,  color);
        }
        break;
    
    case AGHA_SHAHRIAR:
        if(which_ability == SKILL1)
        {
            DrawTextEx(font, "THE DUMMY:", {260, 520}, 35,0, color);
            DrawTextEx(font, "DEALS 60 POINTS OF DAMAGE TO A CHOSEN ENEMY WITH A 20\% CHANCE OF MISSING THE SHOT", {260, 555},15,0, color);
            //extra detail
            DrawTextEx(font, "2 POINTS", {127.0f - (MeasureTextEx(font,"2 POINTS", 20, 0).x /2), 560}, 20, 0,  color);
        }
        else if(which_ability == SKILL2)
        {
            DrawTextEx(font, "THE STUBBORN: ", {260, 520}, 35,0, color);
            DrawTextEx(font, "DEALS 100 POINTS OF DAMAGE TO A RANDOM ENEMY ANYONE BUT THE CHOSEN ENEMY", {260, 555},15,0, color);
            //extra detail
            DrawTextEx(font, "4 POINTS", {127.0f - (MeasureTextEx(font,"4 POINTS", 20, 0).x /2), 560}, 20, 0,  color);
        }
        if(which_ability == SUPERPOWER)
        {
            DrawTextEx(font, "THE REVERSION: ", {260, 520}, 35,0, color);
            DrawTextEx(font, "HEALING ABILITIES DAMAGE TEAMMATES AND ATTACKING ABILITIES HEAL ENEMIES FOR 2ROUNDS", {260, 555},15,0, color);
            //extra detail
            DrawTextEx(font, "8 POINTS", {127.0f - (MeasureTextEx(font,"8 POINTS", 20, 0).x /2), 560}, 20, 0,  color);
        }
        break;
    
    case POUYA_KAJDOM:
        if(which_ability == SKILL1)
        {
            DrawTextEx(font, "THE DAGGER:", {260, 520}, 35,0, color);
            DrawTextEx(font, "DEALS 20 POINTS OF DAMAGE TO THE CHOSEN ENEMY AND BUFFS THE SCORPION DAMAGE BY 40 POINTS ON THAT ENEMY", {260, 555},15,0, color);
            //extra detail
            DrawTextEx(font, "2 POINTS", {127.0f - (MeasureTextEx(font,"2 POINTS", 20, 0).x /2), 560}, 20, 0,  color);
        }
        else if(which_ability == SKILL2)
        {
            DrawTextEx(font, "THE SCORPION: ", {260, 520}, 35,0, color);
            DrawTextEx(font, "PUTS A SCORPION ON THE CHOSEN ENEMY WHICH DEALS 20 POINTS OF DAMAGE PER ROUND ", {260, 555},15,0, color);
            //extra detail
            DrawTextEx(font, "4 POINTS", {127.0f - (MeasureTextEx(font,"4 POINTS", 20, 0).x /2), 560}, 20, 0,  color);
        }
        if(which_ability == SUPERPOWER)
        {
            DrawTextEx(font, "THE VENOMOUS BITE: ", {260, 520}, 35,0, color);
            DrawTextEx(font, "HIDES FOR 3 ROUNDS (CAN'T BE DIRECTLY TARGETED BY ENEMIES) AND DEALS 450 POINTS OF DAMAGE TO A RANDOM ENEMY WHEN THE 3 ROUNDS ARE OVER", {260, 555},15,0, color);
            //extra detail
            DrawTextEx(font, "5 POINTS", {127.0f - (MeasureTextEx(font,"5 POINTS", 20, 0).x /2), 560}, 20, 0,  color);
        }
        break;
    
    case TAHA_BOZORGE:
        if(which_ability == SKILL1)
        {
            DrawTextEx(font, "THE MACHINE GUN:", {260, 520}, 35,0, color);
            DrawTextEx(font, "DEALS 30 POINTS OF DAMAGE TO EVERY ENEMY", {260, 555},15,0, color);
            //extra detail
            DrawTextEx(font, "3 POINTS", {127.0f - (MeasureTextEx(font,"3 POINTS", 20, 0).x /2), 560}, 20, 0,  color);
        }
        else if(which_ability == SKILL2)
        {
            DrawTextEx(font, "XRAY: ", {260, 520}, 35,0, color);
            DrawTextEx(font, "DEALS 90 POINTS OF DAMAGE TO THE CHOSEN ENEMY AND HIDES FOR ONE ROUND (CAN'T BE TARGETED DIRECTLY)", {260, 555},15,0, color);
            //extra detail
            DrawTextEx(font, "4 POINTS", {127.0f - (MeasureTextEx(font,"4 POINTS", 20, 0).x /2), 560}, 20, 0,  color);
        }
        if(which_ability == SUPERPOWER)
        {
            DrawTextEx(font, "REVENGE: ", {260, 520}, 35,0, color);
            DrawTextEx(font, "MARKS A RANDOM ENEMY TO DEAL 360 POINTS OF DAMAGE TO IN THE NEXT ROUND. IF THE MARKED ENEMY'S HP IS OVER 360 THE DAMAGE WILL BE REDUCED TO 200 POINTS", {260, 555},15,0, color);
            //extra detail
            DrawTextEx(font, "3 POINTS", {127.0f - (MeasureTextEx(font,"3 POINTS", 20, 0).x /2), 560}, 20, 0,  color);
        }
        break;
    
    case TAHA_KOCHIKE:
        if(which_ability == SKILL1)
        {
            DrawTextEx(font, "THE MACHINE GUN:", {260, 520}, 35,0, color);
            DrawTextEx(font, "DEALS 30 POINTS OF DAMAGE TO EVERY ENEMY", {260, 555},15,0, color);
            //extra detail
            DrawTextEx(font, "3 POINTS", {127.0f - (MeasureTextEx(font,"3 POINTS", 20, 0).x /2), 560}, 20, 0,  color);
        }
        else if(which_ability == SKILL2)
        {
            DrawTextEx(font, "XRAY: ", {260, 520}, 35,0, color);
            DrawTextEx(font, "DEALS 90 POINTS OF DAMAGE TO THE CHOSEN ENEMY AND HIDES FOR ONE ROUND (CAN'T BE TARGETED DIRECTLY)", {260, 555},15,0, color);
            //extra detail
            DrawTextEx(font, "4 POINTS", {127.0f - (MeasureTextEx(font,"4 POINTS", 20, 0).x /2), 560}, 20, 0,  color);
        }
        if(which_ability == SUPERPOWER)
        {
            DrawTextEx(font, "REVENGE: ", {260, 520}, 35,0, color);
            DrawTextEx(font, "MARKS A RANDOM ENEMY TO DEAL 360 POINTS OF DAMAGE TO IN THE NEXT ROUND. IF THE MARKED ENEMY'S HP IS OVER 360 THE DAMAGE WILL BE REDUCED TO 200 POINTS", {260, 555},15,0, color);
            //extra detail
            DrawTextEx(font, "3 POINTS", {127.0f - (MeasureTextEx(font,"3 POINTS", 20, 0).x /2), 560}, 20, 0,  color);
        }
        break;
    
    case WHITEDOCTOR:
        if(which_ability == SKILL1)
        {
            DrawTextEx(font, "ASPRIN:", {260, 520}, 35,0, color);
            DrawTextEx(font, "DEALS 40 POINTS OF DAMAGE TO THE CHOSEN ENEMY AND HEALS A RANDOM TEAMMATE BY 40 POINTS", {260, 555},15,0, color);
            //extra detail
            DrawTextEx(font, "3 POINTS", {127.0f - (MeasureTextEx(font,"3 POINTS", 20, 0).x /2), 560}, 20, 0,  color);
        }
        else if(which_ability == SKILL2)
        {
            DrawTextEx(font, "DOPING: ", {260, 520}, 35,0, color);
            DrawTextEx(font, "BUFFS ONE TEAMMATE ATTACKING DAMAGE BY 20 POINTS FOR 2ROUNDS ", {260, 555},15,0, color);
            //extra detail
            DrawTextEx(font, "4 POINTS", {127.0f - (MeasureTextEx(font,"4 POINTS", 20, 0).x /2), 560}, 20, 0,  color);
        }
        if(which_ability == SUPERPOWER)
        {
            DrawTextEx(font, "REVIVAL: ", {260, 520}, 35,0, color);
            DrawTextEx(font, "MARKS A RANDOM ENEMY TO DEAL 360 POINTS OF DAMAGE TO IN THE NEXT ROUND. IF THE MARKED ENEMY'S HP IS OVER 360 THE DAMAGE WILL BE REDUCED TO 200 POINTS", {260, 555},15,0, color);
            //extra detail
            DrawTextEx(font, "4 POINTS", {127.0f - (MeasureTextEx(font,"3 POINTS", 20, 0).x /2), 560}, 20, 0,  color);
        }
        break;
    
    }
}


#endif
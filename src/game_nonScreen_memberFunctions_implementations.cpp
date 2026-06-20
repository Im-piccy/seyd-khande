#include "../headers/game.hpp"


const float Animation_Duration = 2.0f;
const float Animation_Speed = 25.0f;
const int characters_sprite_sheets_frame_height = 250;



Game::Game() : current_screen(CHARACTER_SELECT_SCREEN){}

void Game::return_skill_texture_based_on_arguments_passed_onto_the_texture_array_passed_to_the_funtion(const std::array<int,3>& user_hero_array,  std::array <Texture2D, 3>& user_texture_array, int user_turn, int hero_index_in_array)
{
    switch (user_hero_array[hero_index_in_array])
    {
        case DANI_GOLANG:
        {
            //SO WE HAVE TO FILL THE PASSED ARRAY WITH DANI ABILITIES
            //FIRST ABILITY
            user_texture_array[SKILL1] = Dani_fil_kosh;
            user_texture_array[SKILL2] = Dani_lock;
            //HOW MANY ROUNDS IS LEFT TILL THE SUPER POWER IS READY
            //TO RETURN THE CORRECT TEXTURE

            //I KNOW I SHOULDN'T WRITE NESTED IFS AND ELSES 
            //LORD FORGIVE ME I HAD TO I HAD NO OTHER CHOICE
            //HOLD YOUR BRAETH I AM GOING TO COMMIT A CODE CRIME!
            
            if(control.return_rounds_left_till_hero_ability_is_ready(hero_index_in_array, user_turn) == 0)
            {
               user_texture_array[SUPERPOWER] = Dani_super_power_ready;
            }
            else if(control.return_rounds_left_till_hero_ability_is_ready(hero_index_in_array, user_turn) == 1)
            {
                user_texture_array[SUPERPOWER] = Dani_super_power_1rounds_left;
            }
            else if(control.return_rounds_left_till_hero_ability_is_ready(hero_index_in_array, user_turn) == 2)
            {
                user_texture_array[SUPERPOWER] = Dani_super_power_2rounds_left;
            }
            else if(control.return_rounds_left_till_hero_ability_is_ready(hero_index_in_array, user_turn) == 3)
            {
                user_texture_array[SUPERPOWER] = Dani_super_power_3rounds_left;
            }
            else if(control.return_rounds_left_till_hero_ability_is_ready(hero_index_in_array, user_turn) == 4)
            {
                user_texture_array[SUPERPOWER] = Dani_super_power_not_ready;
            }
            
            break;
        }
        case AMIN_EMENI:
            user_texture_array[SKILL1] = amin_friendly_fire;
            user_texture_array[SKILL2] = amin_last_bullet;
            //super powers
            if(control.return_rounds_left_till_hero_ability_is_ready(hero_index_in_array, user_turn) == 0)
            {
               user_texture_array[SUPERPOWER] = amin_super_power_ready;
            }
            else if(control.return_rounds_left_till_hero_ability_is_ready(hero_index_in_array, user_turn) == 1)
            {
                user_texture_array[SUPERPOWER] = amin_super_power_1rounds_left;
            }
            else if(control.return_rounds_left_till_hero_ability_is_ready(hero_index_in_array, user_turn) == 2)
            {
                user_texture_array[SUPERPOWER] = amin_super_power_2rounds_left;
            }
            else if(control.return_rounds_left_till_hero_ability_is_ready(hero_index_in_array, user_turn) == 3)
            {
                user_texture_array[SUPERPOWER] = amin_super_power_not_ready;
            }
            
            break;
            
        case AGHA_SHAHRIAR:
            user_texture_array[SKILL1] = shahriar_dummy;
            user_texture_array[SKILL2] = shahriar_stubborn;
            //super powers
            if(control.return_rounds_left_till_hero_ability_is_ready(hero_index_in_array, user_turn) == 0)
            {
               user_texture_array[SUPERPOWER] = shahriar_super_power_ready;
            }
            else if(control.return_rounds_left_till_hero_ability_is_ready(hero_index_in_array, user_turn) == 1)
            {
                user_texture_array[SUPERPOWER] = shahriar_super_power_1rounds_left;
            }
            else if(control.return_rounds_left_till_hero_ability_is_ready(hero_index_in_array, user_turn) == 2)
            {
                user_texture_array[SUPERPOWER] = shahriar_super_power_2rounds_left;
            }
            else if(control.return_rounds_left_till_hero_ability_is_ready(hero_index_in_array, user_turn) == 3)
            {
                user_texture_array[SUPERPOWER] = shahriar_super_power_3rounds_left;
            }
            else if(control.return_rounds_left_till_hero_ability_is_ready(hero_index_in_array, user_turn) == 4)
            {
                user_texture_array[SUPERPOWER] = shahriar_super_power_not_ready;
            }
            
            break;
        
        case WHITEDOCTOR:
            user_texture_array[SKILL1] = doc_asprin;
            user_texture_array[SKILL2] = doc_doping;
            //super powers
            if(control.return_rounds_left_till_hero_ability_is_ready(hero_index_in_array, user_turn) == 0)
            {
               user_texture_array[SUPERPOWER] = doc_super_power_ready;
            }
            else if(control.return_rounds_left_till_hero_ability_is_ready(hero_index_in_array, user_turn) == 1)
            {
                user_texture_array[SUPERPOWER] = doc_super_power_1rounds_left;
            }
            else if(control.return_rounds_left_till_hero_ability_is_ready(hero_index_in_array, user_turn) == 2)
            {
                user_texture_array[SUPERPOWER] = doc_super_power_2rounds_left;
            }
            else if(control.return_rounds_left_till_hero_ability_is_ready(hero_index_in_array, user_turn) == 3)
            {
                user_texture_array[SUPERPOWER] = doc_super_power_3rounds_left;
            }
            else if(control.return_rounds_left_till_hero_ability_is_ready(hero_index_in_array, user_turn) == 4)
            {
                user_texture_array[SUPERPOWER] = doc_super_power_not_ready;
            }
            
            break;
        
        case TAHA_BOZORGE:
            user_texture_array[SKILL1] = tbig_machine_gun;
            user_texture_array[SKILL2] = tbig_xray;
            //super powers
            if(control.return_rounds_left_till_hero_ability_is_ready(hero_index_in_array, user_turn) == 0)
            {
               user_texture_array[SUPERPOWER] = tbig_super_power_ready;
            }
            else if(control.return_rounds_left_till_hero_ability_is_ready(hero_index_in_array, user_turn) == 1)
            {
                user_texture_array[SUPERPOWER] = tbig_super_power_1rounds_left;
            }
            else if(control.return_rounds_left_till_hero_ability_is_ready(hero_index_in_array, user_turn) == 2)
            {
                user_texture_array[SUPERPOWER] = tbig_super_power_2rounds_left;
            }
            else if(control.return_rounds_left_till_hero_ability_is_ready(hero_index_in_array, user_turn) == 3)
            {
                user_texture_array[SUPERPOWER] = tbig_super_power_3rounds_left;
            }
            else if(control.return_rounds_left_till_hero_ability_is_ready(hero_index_in_array, user_turn) == 4)
            {
                user_texture_array[SUPERPOWER] = tbig_super_power_not_ready;
            }
            break;
        
        case TAHA_KOCHIKE:
            user_texture_array[SKILL1] = tlittle_blood_bag;
            user_texture_array[SKILL2] = tlittle_razor_sharp;
            //super powers
            if(control.return_rounds_left_till_hero_ability_is_ready(hero_index_in_array, user_turn) == 0)
            {
               user_texture_array[SUPERPOWER] = tlittle_super_power_ready;
            }
            else if(control.return_rounds_left_till_hero_ability_is_ready(hero_index_in_array, user_turn) == 1)
            {
                user_texture_array[SUPERPOWER] = tlittle_super_power_1rounds_left;
            }
            else if(control.return_rounds_left_till_hero_ability_is_ready(hero_index_in_array, user_turn) == 2)
            {
                user_texture_array[SUPERPOWER] = tlittle_super_power_2rounds_left;
            }
            else if(control.return_rounds_left_till_hero_ability_is_ready(hero_index_in_array, user_turn) == 3)
            {
                user_texture_array[SUPERPOWER] = tlittle_super_power_not_ready;
            }
            
            break;
        
        case POUYA_KAJDOM:
            user_texture_array[SKILL1] = pouya_dagger;
            user_texture_array[SKILL2] = pouya_scorpion;
            //super powers
            if(control.return_rounds_left_till_hero_ability_is_ready(hero_index_in_array, user_turn) == 0)
            {
               user_texture_array[SUPERPOWER] = pouya_super_power_ready;
            }
            else if(control.return_rounds_left_till_hero_ability_is_ready(hero_index_in_array, user_turn) == 1)
            {
                user_texture_array[SUPERPOWER] = pouya_super_power_1rounds_left;
            }
            else if(control.return_rounds_left_till_hero_ability_is_ready(hero_index_in_array, user_turn) == 2)
            {
                user_texture_array[SUPERPOWER] = pouya_super_power_2rounds_left;
            }
            else if(control.return_rounds_left_till_hero_ability_is_ready(hero_index_in_array, user_turn) == 3)
            {
                user_texture_array[SUPERPOWER] = pouya_super_power_3rounds_left;
            }
            else if(control.return_rounds_left_till_hero_ability_is_ready(hero_index_in_array, user_turn) == 4)
            {
                user_texture_array[SUPERPOWER] = pouya_super_power_not_ready;
            }
            break;
    }    
}



void Game::load_game_screen_animation_sprite_sheets()
{
    Doc_anim_texture = LoadTexture("game_assets/game_screen_assets/doc-sprite-sheet.png");
    Dani_anim_texture = LoadTexture("game_assets/game_screen_assets/dani-sprite.png");
    Amin_anim_texture = LoadTexture("game_assets/game_screen_assets/amin-sprite.png");
    Tlittle_anim_texture = LoadTexture("game_assets/game_screen_assets/t-little-sprite.png");
    Tbig_anim_texture = LoadTexture("game_assets/game_screen_assets/tbig-sprite.png");
    Pouya_anim_texture = LoadTexture("game_assets/game_screen_assets/pouya-sprite.png");
    Shahriar_anim_texture = LoadTexture("game_assets/game_screen_assets/shahriar-sprite.png");
}

void Game::unload_game_screen_animation_sprite_sheets()
{
    UnloadTexture(Doc_anim_texture);
    UnloadTexture(Dani_anim_texture);
    UnloadTexture(Amin_anim_texture);
    UnloadTexture(Tlittle_anim_texture);
    UnloadTexture(Tbig_anim_texture);
    UnloadTexture(Pouya_anim_texture);
    UnloadTexture(Shahriar_anim_texture);
}

void Game::load_game_screen_abilities_textures()
{
        Dani_fil_kosh = LoadTexture("game_assets/game_screen_assets/powers/normalpowers/fil-kosh.png");
        Dani_lock = LoadTexture("game_assets/game_screen_assets/powers/normalpowers/the-lock.png");
        Dani_super_power_3rounds_left = LoadTexture("game_assets/game_screen_assets/powers/superpowers/dani/trenches-3rounds-left.png");
        Dani_super_power_2rounds_left = LoadTexture("game_assets/game_screen_assets/powers/superpowers/dani/trenches-2rounds-left.png");
        Dani_super_power_1rounds_left = LoadTexture("game_assets/game_screen_assets/powers/superpowers/dani/trenches-1round-left.png");
        Dani_super_power_ready = LoadTexture("game_assets/game_screen_assets/powers/superpowers/dani/trenches-ready.png");
        Dani_super_power_not_ready = LoadTexture("game_assets/game_screen_assets/powers/superpowers/dani/trenches-not-ready.png");
        
        amin_friendly_fire = LoadTexture("game_assets/game_screen_assets/powers/normalpowers/friendly-fire.png");
        amin_last_bullet = LoadTexture("game_assets/game_screen_assets/powers/normalpowers/last-bullet.png");
        amin_super_power_2rounds_left = LoadTexture("game_assets/game_screen_assets/powers/superpowers/amin/the-shout-2rounds-left.png");
        amin_super_power_1rounds_left = LoadTexture("game_assets/game_screen_assets/powers/superpowers/amin/the-shout-1round-left.png");
        amin_super_power_ready = LoadTexture("game_assets/game_screen_assets/powers/superpowers/amin/the-shout-ready.png");
        amin_super_power_not_ready = LoadTexture("game_assets/game_screen_assets/powers/superpowers/amin/the-shout-not-ready.png");

        doc_asprin = LoadTexture("game_assets/game_screen_assets/powers/normalpowers/asprin.png");
        doc_doping = LoadTexture("game_assets/game_screen_assets/powers/normalpowers/doping.png");
        doc_super_power_3rounds_left = LoadTexture("game_assets/game_screen_assets/powers/superpowers/doc/revival-3rounds-left.png");
        doc_super_power_2rounds_left = LoadTexture("game_assets/game_screen_assets/powers/superpowers/doc/revival-2rounds-left.png");
        doc_super_power_1rounds_left = LoadTexture("game_assets/game_screen_assets/powers/superpowers/doc/revival-1round-left.png");
        doc_super_power_ready = LoadTexture("game_assets/game_screen_assets/powers/superpowers/doc/revival-ready.png");
        doc_super_power_not_ready = LoadTexture("game_assets/game_screen_assets/powers/superpowers/doc/revival-not-ready.png");
        
        tlittle_razor_sharp = LoadTexture("game_assets/game_screen_assets/powers/normalpowers/razor-sharp.png");
        tlittle_blood_bag = LoadTexture("game_assets/game_screen_assets/powers/normalpowers/blood-bag.png");
        tlittle_super_power_2rounds_left = LoadTexture("game_assets/game_screen_assets/powers/superpowers/tlittle/quarantine-2rounds-left.png");
        tlittle_super_power_1rounds_left = LoadTexture("game_assets/game_screen_assets/powers/superpowers/tlittle/quarantine-1round-left.png");
        tlittle_super_power_ready = LoadTexture("game_assets/game_screen_assets/powers/superpowers/tlittle/quarantine-ready.png");
        tlittle_super_power_not_ready = LoadTexture("game_assets/game_screen_assets/powers/superpowers/tlittle/quarantine-not-ready.png");
        
        tbig_machine_gun = LoadTexture("game_assets/game_screen_assets/powers/normalpowers/machine-gun.png");
        tbig_xray = LoadTexture("game_assets/game_screen_assets/powers/normalpowers/xray.png");
        tbig_super_power_3rounds_left = LoadTexture("game_assets/game_screen_assets/powers/superpowers/tbig/revenge-3rounds-left.png");
        tbig_super_power_2rounds_left = LoadTexture("game_assets/game_screen_assets/powers/superpowers/tbig/revenge-2rounds-left.png");
        tbig_super_power_1rounds_left = LoadTexture("game_assets/game_screen_assets/powers/superpowers/tbig/revenge-1round-left.png");
        tbig_super_power_ready = LoadTexture("game_assets/game_screen_assets/powers/superpowers/tbig/revenge-ready.png");
        tbig_super_power_not_ready = LoadTexture("game_assets/game_screen_assets/powers/superpowers/tbig/revenge-not-ready.png");
        
        pouya_dagger = LoadTexture("game_assets/game_screen_assets/powers/normalpowers/dagger-kajdom.png");
        pouya_scorpion = LoadTexture("game_assets/game_screen_assets/powers/normalpowers/scorpion-kajdom.png");
        pouya_super_power_3rounds_left = LoadTexture("game_assets/game_screen_assets/powers/superpowers/pouya/venomous-bite-kajdom-3rounds-left.png");
        pouya_super_power_2rounds_left = LoadTexture("game_assets/game_screen_assets/powers/superpowers/pouya/venomous-bite-kajdom-2rounds-left.png");
        pouya_super_power_1rounds_left = LoadTexture("game_assets/game_screen_assets/powers/superpowers/pouya/venomous-bite-kajdom-1round-left.png");
        pouya_super_power_ready = LoadTexture("game_assets/game_screen_assets/powers/superpowers/pouya/venomous-bite-kajdom-ready.png");
        pouya_super_power_not_ready = LoadTexture("game_assets/game_screen_assets/powers/superpowers/pouya/venomous-bite-kajdom-not-ready.png");
        
        shahriar_dummy = LoadTexture("game_assets/game_screen_assets/powers/normalpowers/shahriar-dummy.png");
        shahriar_stubborn = LoadTexture("game_assets/game_screen_assets/powers/normalpowers/shahriar-stubborn.png");
        shahriar_super_power_3rounds_left = LoadTexture("game_assets/game_screen_assets/powers/superpowers/shahriar/shahriar-super-power-3rounds-left.png");
        shahriar_super_power_2rounds_left = LoadTexture("game_assets/game_screen_assets/powers/superpowers/shahriar/shahriar-super-power-2rounds-left.png");
        shahriar_super_power_1rounds_left = LoadTexture("game_assets/game_screen_assets/powers/superpowers/shahriar/shahriar-super-power-1round-left.png");
        shahriar_super_power_ready = LoadTexture("game_assets/game_screen_assets/powers/superpowers/shahriar/shahriar-super-power-ready.png");
        shahriar_super_power_not_ready = LoadTexture("game_assets/game_screen_assets/powers/superpowers/shahriar/shahriar-super-power-not-ready.png");
}

void Game::unload_game_screen_abilities_textures()
{
        UnloadTexture( Dani_fil_kosh);
        UnloadTexture( Dani_lock);
        UnloadTexture( Dani_super_power_3rounds_left);
        UnloadTexture( Dani_super_power_2rounds_left);
        UnloadTexture( Dani_super_power_1rounds_left);
        UnloadTexture( Dani_super_power_ready);
        
        UnloadTexture( amin_friendly_fire);
        UnloadTexture( amin_last_bullet);
        UnloadTexture( amin_super_power_2rounds_left);
        UnloadTexture( amin_super_power_1rounds_left);
        UnloadTexture( amin_super_power_ready);

        UnloadTexture( doc_asprin);
        UnloadTexture( doc_doping);
        UnloadTexture( doc_super_power_3rounds_left);
        UnloadTexture( doc_super_power_2rounds_left);
        UnloadTexture( doc_super_power_1rounds_left);
        UnloadTexture( doc_super_power_ready);
        
        UnloadTexture( tlittle_razor_sharp);
        UnloadTexture( tlittle_blood_bag);
        UnloadTexture( tlittle_super_power_2rounds_left);
        UnloadTexture( tlittle_super_power_1rounds_left);
        UnloadTexture( tlittle_super_power_ready);
        
        UnloadTexture( tbig_machine_gun);
        UnloadTexture( tbig_xray);
        UnloadTexture( tbig_super_power_3rounds_left);
        UnloadTexture( tbig_super_power_2rounds_left);
        UnloadTexture( tbig_super_power_1rounds_left);
        UnloadTexture( tbig_super_power_ready);
        
        UnloadTexture( pouya_dagger);
        UnloadTexture( pouya_scorpion);
        UnloadTexture( pouya_super_power_3rounds_left);
        UnloadTexture( pouya_super_power_2rounds_left);
        UnloadTexture( pouya_super_power_1rounds_left);
        UnloadTexture( pouya_super_power_ready);
        
        UnloadTexture( shahriar_dummy);
        UnloadTexture( shahriar_stubborn);
        UnloadTexture( pouya_super_power_3rounds_left);
        UnloadTexture( pouya_super_power_2rounds_left);
        UnloadTexture( pouya_super_power_1rounds_left);
        UnloadTexture( pouya_super_power_ready);
}

void Game::print_heros_on_screen_idle_and_highlight_hero_which_is_hoverd(const std::array <int,3>& user1_heros, const std::array <int,3>&  user2_heros, int index, int user_turn,bool should_highlight,int user1_hero_being_hoverd, int user2_hero_being_hoverd, int hero_to_be_animated_index)
{

    //for player one
    switch (user1_heros[index])
    {
    case WHITEDOCTOR:
        if(user_turn == USER1 && should_highlight && index == user1_hero_being_hoverd && hero_to_be_animated_index != index)
        {
            DrawTextureRec(Doc_anim_texture,{0,0, -164,characters_sprite_sheets_frame_height}, {180.0f - (100 * (index % 2)), 80.0f + (index * 50)},WHITE);
        }
        else if(user_turn == USER1 && hero_to_be_animated_index == index)
        {
            break;
        }
        else
            DrawTextureRec(Doc_anim_texture,{0,0, -164,characters_sprite_sheets_frame_height}, {180.0f - (100 * (index % 2)), 80.0f + (index * 50)},GRAY);
        break;
    
    case DANI_GOLANG:
        if(user_turn == USER1 && should_highlight && index == user1_hero_being_hoverd && hero_to_be_animated_index != index)
        {
            DrawTextureRec(Dani_anim_texture,{0,0, -136,characters_sprite_sheets_frame_height}, {180.0f - (100 * (index % 2)), 80.0f + (index * 50)},WHITE);
        }
        else if(user_turn == USER1 && hero_to_be_animated_index == index)
        {
            break;
        }
        else
            DrawTextureRec(Dani_anim_texture,{0,0, -136,characters_sprite_sheets_frame_height}, {180.0f - (100 * (index % 2)), 80.0f + (index * 50)},GRAY);
        break;
    
    case AMIN_EMENI:
        if(user_turn == USER1 && should_highlight && index == user1_hero_being_hoverd && hero_to_be_animated_index != index)
        {
            DrawTextureRec(Amin_anim_texture,{0,0, -145,characters_sprite_sheets_frame_height}, {180.0f - (100 * (index % 2)), 80.0f + (index * 50)},WHITE);
        }
        else if(user_turn == USER1 && hero_to_be_animated_index == index)
        {
            break;
        }
        else
            DrawTextureRec(Amin_anim_texture,{0,0, -145,characters_sprite_sheets_frame_height}, {180.0f - (100 * (index % 2)), 80.0f + (index * 50)},GRAY);
        
        break;
    
    case POUYA_KAJDOM:
        if(user_turn == USER1 && should_highlight && index == user1_hero_being_hoverd && hero_to_be_animated_index != index)
        {
            DrawTextureRec(Pouya_anim_texture,{0,0, -120,characters_sprite_sheets_frame_height}, {180.0f - (100 * (index % 2)), 80.0f + (index * 50)},WHITE);
        }
        else if(user_turn == USER1 && hero_to_be_animated_index == index)
        {
            break;
        }
        else
            DrawTextureRec(Pouya_anim_texture,{0,0, -120,characters_sprite_sheets_frame_height}, {180.0f - (100 * (index % 2)), 80.0f + (index * 50)},GRAY);
        
        break;
    
    case AGHA_SHAHRIAR:
        if(user_turn == USER1 && should_highlight && index == user1_hero_being_hoverd && hero_to_be_animated_index != index)
        {
           DrawTextureRec(Shahriar_anim_texture,{0,0, -160,characters_sprite_sheets_frame_height}, {180.0f - (100 * (index % 2)), 80.0f + (index * 50)},WHITE);
        }   
        else if(user_turn == USER1 && hero_to_be_animated_index == index)
        {
            break;
        }  
        else
            DrawTextureRec(Shahriar_anim_texture,{0,0, -160,characters_sprite_sheets_frame_height}, {180.0f - (100 * (index % 2)), 80.0f + (index * 50)},GRAY); 
        
        break;
    
    case TAHA_KOCHIKE:
        if(user_turn == USER1 && should_highlight && index == user1_hero_being_hoverd && hero_to_be_animated_index != index)
        {
            DrawTextureRec(Tlittle_anim_texture,{0,0, -185,characters_sprite_sheets_frame_height}, {180.0f - (100 * (index % 2)), 80.0f + (index * 50)},WHITE);
        }     
        else if(user_turn == USER1 && hero_to_be_animated_index == index)
        {
            break;
        }
        else
            DrawTextureRec(Tlittle_anim_texture,{0,0, -185,characters_sprite_sheets_frame_height}, {180.0f - (100 * (index % 2)), 80.0f + (index * 50)},GRAY);
        
        break;
    
    case TAHA_BOZORGE:
        if(user_turn == USER1 && should_highlight && index == user1_hero_being_hoverd && hero_to_be_animated_index != index)
        {
            DrawTextureRec(Tbig_anim_texture,{0,0, -135,characters_sprite_sheets_frame_height}, {180.0f - (100 * (index % 2)), 80.0f + (index * 50)},WHITE);
        }   
        else if(user_turn == USER1 && hero_to_be_animated_index == index)
        {
            break;
        }  
        else
            DrawTextureRec(Tbig_anim_texture,{0,0, -135,characters_sprite_sheets_frame_height}, {180.0f - (100 * (index % 2)), 80.0f + (index * 50)},GRAY);
        
        break;
    
    }
    //for player two

    switch (user2_heros[index])
    {
    case WHITEDOCTOR:
        if(user_turn == USER2 && should_highlight && index == user2_hero_being_hoverd && hero_to_be_animated_index != index)
        {
            DrawTextureRec(Doc_anim_texture,{0,0, 164,characters_sprite_sheets_frame_height}, {1000.0f - (350 - (100 * (index % 2))), 80.0f + (index * 50)},WHITE);
        }    
        else if(user_turn == USER2 && hero_to_be_animated_index == index)
        {
            break;
        } 
        else
            DrawTextureRec(Doc_anim_texture,{0,0, 164,characters_sprite_sheets_frame_height}, {1000.0f - (350 - (100 * (index % 2))), 80.0f + (index * 50)},GRAY);
        
        break;
    
    case DANI_GOLANG:
        if(user_turn == USER2 && should_highlight && index == user2_hero_being_hoverd && hero_to_be_animated_index != index)
        {
            DrawTextureRec(Dani_anim_texture,{0,0, 136,characters_sprite_sheets_frame_height}, {1000.0f - (350 - (100 * (index % 2))), 80.0f + (index * 50)},WHITE);
        }     
        else if(user_turn == USER2 && hero_to_be_animated_index == index)
        {
            break;
        } 
        else
            DrawTextureRec(Dani_anim_texture,{0,0, 136,characters_sprite_sheets_frame_height}, {1000.0f - (350 - (100 * (index % 2))), 80.0f + (index * 50)},GRAY);
        
        break;
    
    case AMIN_EMENI:
        if(user_turn == USER2 && should_highlight && index == user2_hero_being_hoverd && hero_to_be_animated_index != index)
        {
            DrawTextureRec(Amin_anim_texture,{0,0, 145,characters_sprite_sheets_frame_height}, {1000.0f - (350 - (100 * (index % 2))), 80.0f + (index * 50)},WHITE);
        }     
        else if(user_turn == USER2 && hero_to_be_animated_index == index)
        {
            break;
        } 
        else
            DrawTextureRec(Amin_anim_texture,{0,0, 145,characters_sprite_sheets_frame_height}, {1000.0f - (350 - (100 * (index % 2))), 80.0f + (index * 50)},GRAY);
        
        break;
    
    case POUYA_KAJDOM:
        if(user_turn == USER2 && should_highlight && index == user2_hero_being_hoverd && hero_to_be_animated_index != index)
        {
            DrawTextureRec(Pouya_anim_texture,{0,0, 120,characters_sprite_sheets_frame_height}, {1000.0f - (350 - (100 * (index % 2))), 80.0f + (index * 50)},WHITE);
        }     
        else if(user_turn == USER2 && hero_to_be_animated_index == index)
        {
            break;
        } 
        else
            DrawTextureRec(Pouya_anim_texture,{0,0, 120,characters_sprite_sheets_frame_height}, {1000.0f - (350 - (100 * (index % 2))), 80.0f + (index * 50)},GRAY);
        
        break;
    
    case AGHA_SHAHRIAR:
        if(user_turn == USER2 && should_highlight && index == user2_hero_being_hoverd && hero_to_be_animated_index != index)
        {
            DrawTextureRec(Shahriar_anim_texture,{0,0, 160,characters_sprite_sheets_frame_height}, {1000.0f - (350 - (100 * (index % 2))), 80.0f + (index * 50)},WHITE);
        }     
        else if(user_turn == USER2 && hero_to_be_animated_index == index)
        {
            break;
        } 
        else
            DrawTextureRec(Shahriar_anim_texture,{0,0, 160,characters_sprite_sheets_frame_height}, {1000.0f - (350 - (100 * (index % 2))), 80.0f + (index * 50)},GRAY);
        
        break;
    
    case TAHA_KOCHIKE:
        if(user_turn == USER2 && should_highlight && index == user2_hero_being_hoverd && hero_to_be_animated_index != index)
        {
            DrawTextureRec(Tlittle_anim_texture,{0,0, 178,characters_sprite_sheets_frame_height}, {1000.0f - (350 - (100 * (index % 2))), 80.0f + (index * 50)},WHITE);
        }   
        else if(user_turn == USER2 && hero_to_be_animated_index == index)
        {
            break;
        }   
        else
            DrawTextureRec(Tlittle_anim_texture,{0,0, 178,characters_sprite_sheets_frame_height}, {1000.0f - (350 - (100 * (index % 2))), 80.0f + (index * 50)},GRAY);
        
        break;
    
    case TAHA_BOZORGE:
        if(user_turn == USER2 && should_highlight && index == user2_hero_being_hoverd && hero_to_be_animated_index != index)
        {
            DrawTextureRec(Tbig_anim_texture,{0,0, 135,characters_sprite_sheets_frame_height}, {1000.0f - (350 - (100 * (index % 2))), 80.0f + (index * 50)},WHITE);
        }
        else if(user_turn == USER2 && hero_to_be_animated_index == index)
        {
            break;
        }      
        else
            DrawTextureRec(Tbig_anim_texture,{0,0, 135,characters_sprite_sheets_frame_height}, {1000.0f - (350 - (100 * (index % 2))), 80.0f + (index * 50)},GRAY);
        
        break;
    
    }
}


bool Game::Manage_Screens()
{
    switch(current_screen)
    {
        case MENU_SCREEN:
            Menu_Screen();
            return true;

        case CHARACTER_SELECT_SCREEN:
            Character_Select_Screen();
            return true;

        case GAME_SCREEN:
            Game_Screen();
            return true;

        case GAME_OVER_SCREEN:
            Game_Over_Screen();
            return true;

        case WINDOWSHOULDCLOSE:
            return false;
    }
}



void Game::highlight_enemy(const std::array <int, 3>& user1_hero_arr, const std::array <int, 3>& user2_hero_arr, int user_turn, int enemy_to_be_highlighted, Color color)
{   
    if(user_turn == USER1)
    { 
        switch (user2_hero_arr[enemy_to_be_highlighted])
        {
            case WHITEDOCTOR:
                DrawTextureRec(Doc_anim_texture,{0,0, 164,characters_sprite_sheets_frame_height}, {1000.0f - (350 - (100 * (enemy_to_be_highlighted % 2))), 80.0f + (enemy_to_be_highlighted * 50)},  color);
                break;
            
            case DANI_GOLANG:
                DrawTextureRec(Dani_anim_texture,{0,0, 136,characters_sprite_sheets_frame_height}, {1000.0f - (350 - (100 * (enemy_to_be_highlighted % 2))), 80.0f + (enemy_to_be_highlighted * 50)},  color);
                break;
            
            case AMIN_EMENI:
                DrawTextureRec(Amin_anim_texture,{0,0, 145,characters_sprite_sheets_frame_height}, {1000.0f - (350 - (100 * (enemy_to_be_highlighted % 2))), 80.0f + (enemy_to_be_highlighted * 50)},  color);
                break;
            
            case POUYA_KAJDOM:
                DrawTextureRec(Pouya_anim_texture,{0,0, 120,characters_sprite_sheets_frame_height}, {1000.0f - (350 - (100 * (enemy_to_be_highlighted % 2))), 80.0f + (enemy_to_be_highlighted * 50)},  color);
                break;
            
            case AGHA_SHAHRIAR:
                DrawTextureRec(Shahriar_anim_texture,{0,0, 160,characters_sprite_sheets_frame_height}, {1000.0f - (350 - (100 * (enemy_to_be_highlighted % 2))), 80.0f + (enemy_to_be_highlighted * 50)},  color);
                    break;
            
            case TAHA_KOCHIKE:
                DrawTextureRec(Tlittle_anim_texture,{0,0, 185,characters_sprite_sheets_frame_height}, {1000.0f - (350 - (100 * (enemy_to_be_highlighted % 2))), 80.0f + (enemy_to_be_highlighted * 50)},  color);
                break;
            
            case TAHA_BOZORGE:
                DrawTextureRec(Tbig_anim_texture,{0,0, 135,characters_sprite_sheets_frame_height}, {1000.0f - (350 - (100 * (enemy_to_be_highlighted % 2))), 80.0f + (enemy_to_be_highlighted * 50)},  color);
                break;
            
        }
    }  
    
    
    else if(user_turn == USER2)
    { 
        switch (user1_hero_arr[enemy_to_be_highlighted])
        {
            case WHITEDOCTOR:
                DrawTextureRec(Doc_anim_texture,{0,0, -164,characters_sprite_sheets_frame_height}, {180.0f - (100 * (enemy_to_be_highlighted % 2)), 80.0f + (enemy_to_be_highlighted * 50)}, color);
                break;
            
            case DANI_GOLANG:
                DrawTextureRec(Dani_anim_texture,{0,0, -136,characters_sprite_sheets_frame_height}, {180.0f - (100 * (enemy_to_be_highlighted % 2)), 80.0f + (enemy_to_be_highlighted * 50)}, color);
                break;
            
            case AMIN_EMENI:
                DrawTextureRec(Amin_anim_texture,{0,0, -145,characters_sprite_sheets_frame_height}, {180.0f - (100 * (enemy_to_be_highlighted % 2)), 80.0f + (enemy_to_be_highlighted * 50)}, color);
                break;
            
            case POUYA_KAJDOM:
                DrawTextureRec(Pouya_anim_texture,{0,0, -120,characters_sprite_sheets_frame_height}, {180.0f - (100 * (enemy_to_be_highlighted % 2)), 80.0f + (enemy_to_be_highlighted * 50)}, color);
                break;
            
            case AGHA_SHAHRIAR:
                DrawTextureRec(Shahriar_anim_texture,{0,0, -160,characters_sprite_sheets_frame_height}, {180.0f - (100 * (enemy_to_be_highlighted % 2)), 80.0f + (enemy_to_be_highlighted * 50)}, color);
                    break;
            
            case TAHA_KOCHIKE:
                DrawTextureRec(Tlittle_anim_texture,{0,0, -185,characters_sprite_sheets_frame_height}, {180.0f - (100 * (enemy_to_be_highlighted % 2)), 80.0f + (enemy_to_be_highlighted * 50)}, color);
                break;
            
            case TAHA_BOZORGE:
                DrawTextureRec(Tbig_anim_texture,{0,0, -135,characters_sprite_sheets_frame_height}, {180.0f - (100 * (enemy_to_be_highlighted % 2)), 80.0f + (enemy_to_be_highlighted * 50)}, color);
                break;
            
        }
    }  
}


 
Texture2D Game::return_animation_texture_based_on_arguments_passed(const std::array <int,3>& user1_hero_arr, const std::array <int,3>& user2_hero_arr,int user_turn, int hero_index_in_array)
{
    if(user_turn == USER1)
    {
        switch (user1_hero_arr[hero_index_in_array])
        {
        case DANI_GOLANG:
            return Dani_anim_texture;
        case AMIN_EMENI:
            return Amin_anim_texture;
        case TAHA_BOZORGE:
            return Tbig_anim_texture;
        case TAHA_KOCHIKE:
            return Tlittle_anim_texture;
        case POUYA_KAJDOM:
            return Pouya_anim_texture;
        case WHITEDOCTOR:
            return Doc_anim_texture;
        case AGHA_SHAHRIAR:
            return Shahriar_anim_texture;
        
        }
    }
    else if(user_turn == USER2)
    {
        switch (user2_hero_arr[hero_index_in_array])
        {
        case DANI_GOLANG:
            return Dani_anim_texture;
        case AMIN_EMENI:
            return Amin_anim_texture;
        case TAHA_BOZORGE:
            return Tbig_anim_texture;
        case TAHA_KOCHIKE:
            return Tlittle_anim_texture;
        case POUYA_KAJDOM:
            return Pouya_anim_texture;
        case WHITEDOCTOR:
            return Doc_anim_texture;
        case AGHA_SHAHRIAR:
            return Shahriar_anim_texture;
        
        }
    }
}


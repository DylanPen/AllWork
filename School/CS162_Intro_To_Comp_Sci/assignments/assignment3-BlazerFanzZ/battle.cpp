// TODO Implement member functions of the battle class
#include <iostream>
#include <cmath>

#include "battle.hpp"

battle::battle(){

}

battle::battle(pokemon p1, pokemon p2){
    //setting initial varaibles
    string p1_name = p1.get_name();
    int p1_current_health = p1.get_health();
    int p1_max_health = p1.get_max_health();
    string p2_name = p2.get_name();
    int p2_current_health = p2.get_health();
    int p2_max_health = p2.get_max_health();
    int heal_1 = 1;
    int heal_2 = 1;
    int user_choice;
    do{
        set_turn(1);
        turn = get_turn();
        p1.set_health(p1_current_health);
        p2.set_health(p2_current_health);
        user_choice = turn_display(p1_current_health, p1_max_health, p2_current_health, p2_max_health, turn, p1_name, p2_name, heal_1, heal_2); //displays pokemon health and what the user wants to do, move or heal
        if(user_choice == 1){
            p2_current_health = battle_choice1(turn, p1, p2); //does damage to opposing pokemon 
        }
        else{
            p1_current_health = battle_choice2(turn, p1, p2, heal_1, heal_2); //heals user pokemon
        }
        cout << "P2 CURRENT HEALTH: " << p2_current_health << endl;
        cout << endl;
        if(p2_current_health <= 0){
            break;
        }
        set_turn(2);
        turn = get_turn();
        p1.set_health(p1_current_health);
        p2.set_health(p2_current_health);
        user_choice = turn_display(p1_current_health, p1_max_health, p2_current_health, p2_max_health, turn, p1_name, p2_name, heal_1, heal_2);
        if(user_choice == 1){
            p1_current_health = battle_choice1(turn, p1, p2); //does damage to opposing pokemon
        }
        else{
            p2_current_health = battle_choice2(turn, p1, p2, heal_1, heal_2); //heals user pokemon
        }
        cout << "P1 CURRENT HEALTH: " << p1_current_health << endl;
        cout << endl;
    }
    while(p1_current_health > 0 && p2_current_health > 0);

    if(p1_current_health <= 0){
        cout << "PLAYER 2 WINS!" << endl;
    }
    else{
        cout << "PLAYER 1 WINS!" << endl;
    }

}

int battle::turn_display(int p1_current_health, int p1_max_health, int p2_current_health, int p2_max_health, int turn, string p1_name, string p2_name, int& h_1, int& h_2){
    cout << "it's Trainer " << turn << "'s turn." << endl;
    cout << p1_name << " has " << p1_current_health << '/' << p1_max_health << " HP remaining." << endl;
    cout << p2_name << " has " << p2_current_health << '/' << p2_max_health << " HP remaining." << endl;
    cout << endl;
    int user_choice;
    do{
        do{
            cout << "Would you like to [1. Use a move] or [2. heal]?: ";
            cin >> user_choice;
            cout << endl;
        }
        while((h_1 == 0 && user_choice == 2) && (h_2 == 0 && user_choice == 2));
    } 
    while (user_choice != 1 && user_choice != 2);
    return user_choice;
}

int battle::battle_choice1(int turn, pokemon p1, pokemon p2){
    if(turn == 1){
        int move_num = move_selection(p1);
        int total_damage = damage_calc(move_num, turn, p1, p2);
        return p2.do_damage(total_damage); //returns damage calculation for p1
    }
    else{
        int move_num = move_selection(p2);
        int total_damage = damage_calc(move_num, turn, p1, p2);
        return p1.do_damage(total_damage); //returns damage calculation for p2
    }
}

int battle::battle_choice2(int turn, pokemon p1, pokemon p2, int& h_1, int& h_2){
    if(turn == 1){
        h_1 -= 1;
        int h = p1.health_potion();
        int mh = p1.get_max_health();
        if(h > mh){
            h = mh;
        }
        return h;
    }
    else{
        h_2 -= 1;
        int h = p2.health_potion();
        int mh = p2.get_max_health();
        if(h > mh){
            h = mh;
        }
        return h;
    }
}

void battle::set_turn(int turn){
    this->turn = turn;
}

int battle::get_turn(){
    return this->turn;
}

int battle::move_selection(pokemon pokemon){
    int user_choice;
    string m1_name = pokemon.get_moves_name(0);
    string m2_name = pokemon.get_moves_name(1);
    int m1_pp = pokemon.get_moves_pp(0);
    int m2_pp = pokemon.get_moves_pp(1);
    cout << "Which move would you like to use? " << endl;
    cout << "1. " << m1_name << " (" << m1_pp << " uses remaining)" << endl;
    cout << "2. " << m2_name << " (" << m2_pp << " uses remaining)" << endl;
    cout << endl;
    do{
        cout << "Which move would you like to use: ";
        cin >> user_choice;
        cout << endl;
    } 
    while (user_choice != 1 && user_choice != 2);
    if(user_choice == 1){
        m1_pp = pokemon.use_moves_pp(0);
        pokemon.set_moves_pp(m1_pp, 0);
        cout << "MOVE 1 PP: " << m1_pp << endl;
        cout << endl;
        return 0;
    }
    else{
        m2_pp = pokemon.use_moves_pp(1);
        pokemon.set_moves_pp(m2_pp, 1);
        cout << "MOVE 2 PP: " << m2_pp << endl;
        cout << endl;
        return 1;
    }
}

int battle::damage_calc(int move_num, int turn, pokemon att_pokemon, pokemon def_pokemon){
    int damage;
    int attack = att_pokemon.get_attack();
    int defence = def_pokemon.get_defence();
    double type_interaction = type_calc(move_num, turn, att_pokemon, def_pokemon);
    int base_damage = att_pokemon.get_moves_base_damage(move_num);
    double random_multiplier = random_mult();
    int crit = crit_calc();
    cout << "Performing damage calculation..." << endl;
    cout << "Value of type interaction: " << type_interaction << endl;
    cout << "Value of random multiplier: " << random_multiplier << endl;
    cout << "Value of random critical: " << crit << endl;
    damage = ceil((attack / defence) * type_interaction * base_damage * random_multiplier * crit); //damage calculation
    cout << "Value of damage: " << damage << endl;
    cout << endl;
    return damage;
}

int battle::crit_calc(){
    int rand_value = rand();
    int r = rand_value % 10 + 1;
    if(r != 10){
        return 1;
    }
    else{
        return 3;
    }
}

double battle::random_mult(){
    double rand_value = rand(); 
    double zero_to_one = rand_value / RAND_MAX;
    double r = 0.8 + zero_to_one * 0.4; //sets value between .8 and 1.2
    return r;
}

double battle::type_calc(int move_num, int turn, pokemon p1, pokemon p2){
    string move, type;
    if(turn == 1){
        move = p1.get_moves_type(move_num);
        type = p2.get_type();
        return type_effectives(move, type);
    }
    else{
        move = p2.get_moves_type(move_num);
        type = p1.get_type();
        return type_effectives(move, type);
    }
}

double battle::type_effectives(string move, string type){
    // checks move type of attacker and type of defender and reutrns value based on effectiveness
    if(move == "fire" && type == "grass"){
        return 2.0;
    }
    else if(move == "fire" && (type == "fire" || type == "water")){
        return 0.5;
    }
    else if(move == "water" && type == "fire"){
        return 2.0;
    }
    else if(move == "water" && (type == "water" || type == "grass")){
        return 0.5;
    }
    else if(move == "grass" && type == "water"){
        return 2.0;
    }
    else if(move == "grass" && (type == "grass" || type == "fire")){
        return 0.5;
    }
    else{
        return 1;
    }
}

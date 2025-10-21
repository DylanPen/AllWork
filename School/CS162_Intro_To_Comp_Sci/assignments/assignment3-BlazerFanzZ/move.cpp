// TODO Implement member functions of the move class
#include <iostream>

#include "move.hpp"

move::move(){

}

move::move(string name, string type, int base_damage, int pp){

    this->name = name;
    this->type = type;
    this->base_damage = base_damage;
    this->pp = pp;
        
}

void move::set_move_name(const string name){
    this->name = name;
}

string move::get_move_name() const {
    return this->name;
}

void move::set_move_type(const string type){
    this->type = type;
}

string move::get_move_type() const {
    return this->type;
}

void move::set_move_base_damage(const int base_damage){
    this->base_damage = base_damage;
}

int move::get_move_base_damage() const {
    return this->base_damage;
}

void move::set_move_pp(int pp){
    this->pp = pp;
}

int move::get_move_pp() const {
    return this->pp;
}

int move::use_move_pp(){
    pp -= 1;
    return pp;
}

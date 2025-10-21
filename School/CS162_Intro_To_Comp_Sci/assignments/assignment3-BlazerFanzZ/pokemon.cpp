// TODO Implement member functions of the pokemon class
#include <iostream>
#include "pokemon.hpp"

pokemon::pokemon(){

}

pokemon::pokemon(int pokemon, int size){
    this->num_moves = size;
	this->move_arr = new move [size];
    this->move_arr[0] = move("Scratch", "normal", 3, 10000);
    if(pokemon == 1){
        this->name = "Charmander";
        this->type = "fire";
        this->attack = 6;
        this->defence = 4;
        this->health = 18;
        this->max_health = 18;
        this->move_arr[1] = move("Ember", "fire", 5, 3);
    }
    else if(pokemon == 2){
        this->name = "Squirtle";
        this->type = "water";
        this->attack = 4;
        this->defence = 6;
        this->health = 22;
        this->max_health = 22;
        this->move_arr[1] = move("Water Gun", "water", 5, 3);
    }
    else{
        this->name = "Bulbasaur";
        this->type = "grass";
        this->attack = 5;
        this->defence = 5;
        this->health = 20;
        this->max_health = 20;
        this->move_arr[1] = move("Vine Whip", "grass", 5, 3);
    }
}

void pokemon::set_name(const string name){
    this->name = name;
}

string pokemon::get_name() const {
    return this->name;
}

void pokemon::set_type(const string type){
    this->type = type;
}

string pokemon::get_type() const {
    return this->type;
}

void pokemon::set_attack(const int attack){
    this->attack = attack;
}

int pokemon::get_attack() const {
    return this->attack;
}

void pokemon::set_defence(const int defence){
    this->defence = defence;
}

int pokemon::get_defence() const {
    return this->defence;
}

void pokemon::set_health(int health){
    this->health = health;
}

int pokemon::get_health(){
    return this->health;
}

void pokemon::set_max_health(const int max_health){
    this->max_health = max_health;
}

int pokemon::get_max_health() const {
    return this->max_health;
}

void pokemon::set_moves(move* move_arr){
    this->move_arr = move_arr;
}

move* pokemon::get_moves() const {
    return this->move_arr;
}

string pokemon::get_moves_name(int move_num) const {
    return this->move_arr[move_num].get_move_name();
}

string pokemon::get_moves_type(int move_num) const {
    return this->move_arr[move_num].get_move_type();
}

int pokemon::get_moves_base_damage(int move_num) const {
    return this->move_arr[move_num].get_move_base_damage();
}

int pokemon::get_moves_pp(int move_num) const {
    return this->move_arr[move_num].get_move_pp();
}

void pokemon::set_moves_pp(int pp, int move_num){
    this->move_arr[move_num].set_move_pp(pp);
}

int pokemon::use_moves_pp(int move_num){
    return this->move_arr[move_num].use_move_pp();
}

int pokemon::do_damage(int total_damage){
    health -= total_damage;
    return health;
}

int pokemon::health_potion(){
    health += 10;
    return health;
}

void pokemon::print() const {
    cout << this->name << endl;
    cout << this->type << endl;
    cout << this->attack << endl;
    cout << this->defence << endl;
    cout << this->health << endl;
    cout << this->max_health << endl;
}

pokemon::~pokemon(){
    delete [] move_arr;
    move_arr = nullptr;
}

pokemon& pokemon::operator=(const pokemon &other){
    if(this == &other){
        return *this;
    }

    if(this->move_arr != nullptr){
        delete [] this->move_arr;
    }
    this->num_moves = other.num_moves;
    this->move_arr = new move [this->num_moves];
    this->name = other.name;
    this->type = other.type;
    this->health = other.health;
    this->max_health = other.max_health;
    this->attack = other.attack;
    this->defence = other.defence;

    return *this;
}

pokemon::pokemon(const pokemon &other){
    this->num_moves = other.num_moves;
    this->move_arr = new move [this->num_moves];
    this->name = other.name;
    this->type = other.type;
    this->health = other.health;
    this->max_health = other.max_health;
    this->attack = other.attack;
    this->defence = other.defence;
    for(int i = 0; i < num_moves; i++){
        this->move_arr[i] = other.move_arr[i];
    }
}
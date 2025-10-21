#include <iostream>

#include "startup.hpp"
#include "battle.hpp"

using std::cout;
using std::endl;
using std::string;

int main() {
	srand(time(nullptr));

	int trainer_1_pokemon_choice = prompt_first_pokemon();
	int trainer_2_pokemon_choice = prompt_second_pokemon(trainer_1_pokemon_choice);

	pokemon p1(trainer_1_pokemon_choice, 2);
	pokemon p2(trainer_2_pokemon_choice, 2);

	battle(p1, p2);
	
	//p1 = p2;

	//pokemon p3 = p1;

	// move scratch("scratch", "normal", 3, 10000);

	// cout << scratch.name << endl;
	// cout << scratch.type << endl;
	// cout << scratch.base_damage << endl;
	// cout << scratch.pp << endl;

	// TODO Use if statements to determine which pokemon was chosen by
	// each player and create respective pokemon objects with the
	// appropriate types, stats, and moves

	// TODO Create a battle object containing the two pokemon objects
	// created above, and then start the battle
}

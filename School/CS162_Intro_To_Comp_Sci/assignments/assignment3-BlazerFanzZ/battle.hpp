#ifndef BATTLE_HPP
#define BATTLE_HPP
#include <cstdlib>

#include "pokemon.hpp"

using std::string;
using std::cout;
using std::cin;
using std::endl;

class battle {
private:
	int turn;
public:

/*********************************************************************
** Program Filename: battle
** Author: Dylan Peniuk
** Date: 11/13/24
** Description: default constructor
*********************************************************************/

	battle();

/*********************************************************************
** Program Filename: battle
** Author: Dylan Peniuk
** Date: 11/13/24
** Description: non-default constructor
*********************************************************************/

	battle(pokemon p1, pokemon p2);

/*********************************************************************
** Program Filename: damage_calc
** Author: Dylan Peniuk
** Date: 11/13/24
** Description: calculated the damage for an attack when called
*********************************************************************/

	int damage_calc(int move_num, int turn, pokemon att_pokemon, pokemon def_pokemon);

/*********************************************************************
** Program Filename: type_calc
** Author: Dylan Peniuk
** Date: 11/13/24
** Description: gets types of attack and pokemon and calls function to calculate effectiveness multiplier and returns the value
*********************************************************************/

	double type_calc(int move_num, int turn, pokemon p1, pokemon p2);

/*********************************************************************
** Program Filename: type_effectives
** Author: Dylan Peniuk
** Date: 11/13/24
** Description: calculates the multiplier for each type combo for damage calculation
*********************************************************************/

	double type_effectives(string move, string type);
	
/*********************************************************************
** Program Filename: random_mult
** Author: Dylan Peniuk
** Date: 11/13/24
** Description: calculates a random number from .8 to 1.2 for damage calculation
*********************************************************************/

	double random_mult();

/*********************************************************************
** Program Filename: crit_calc
** Author: Dylan Peniuk
** Date: 11/13/24
** Description: picks a random number from 1-10 and if 10, returns 3, else returns 1
*********************************************************************/

	int crit_calc();

/*********************************************************************
** Program Filename: move_selection
** Author: Dylan Peniuk
** Date: 11/13/24
** Description: shows avaliable moves to pick from and takes the input of the move wanting to be used
*********************************************************************/

	int move_selection(pokemon pokemon);

/*********************************************************************
** Program Filename: set_turn
** Author: Dylan Peniuk
** Date: 11/13/24
** Description: sets the value of turn
*********************************************************************/

	void set_turn(int turn);

/*********************************************************************
** Program Filename: get_turn
** Author: Dylan Peniuk
** Date: 11/13/24
** Description: gets the value of turn
*********************************************************************/

	int get_turn();

/*********************************************************************
** Program Filename: turn_display
** Author: Dylan Peniuk
** Date: 11/13/24
** Description: displays the turn, pokemon health, and if they would like to use a move or heal
*********************************************************************/

	int turn_display(int p1_current_health, int p1_max_health, int p2_current_health, int p2_max_health, int turn, string p1_name, string p2_name, int& h_1, int& h_2);

/*********************************************************************
** Program Filename: battle_choice1
** Author: Dylan Peniuk
** Date: 11/13/24
** Description: does damage calculation
*********************************************************************/

	int battle_choice1(int turn, pokemon p1, pokemon p2);

/*********************************************************************
** Program Filename: battle_choice2
** Author: Dylan Peniuk
** Date: 11/13/24
** Description: does healing calculation
*********************************************************************/

	int battle_choice2(int turn, pokemon p1, pokemon p2, int& h_1, int& h_2);

};

#endif

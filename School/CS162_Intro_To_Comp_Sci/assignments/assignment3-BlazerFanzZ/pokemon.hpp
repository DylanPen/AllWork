#ifndef POKEMON_HPP
#define POKEMON_HPP

#include "move.hpp"

using std::string;
using std::cout;
using std::endl;

class pokemon {
	// TODO
private:
	string name;
	int num_moves;
	move* move_arr;
	string type;
	int health;
	int max_health;
	int attack;
	int defence;
public:

/*********************************************************************
** Program Filename: pokemon
** Author: Dylan Peniuk
** Date: 11/13/24
** Description: default constructor
*********************************************************************/
	pokemon();

/*********************************************************************
** Program Filename: pokemon
** Author: Dylan Peniuk
** Date: 11/13/24
** Description: non-default constructor, makes the pokemon and sets stats
*********************************************************************/

	pokemon (int pokemon, int size);

/*********************************************************************
** Program Filename: ~pokemon
** Author: Dylan Peniuk
** Date: 11/13/24
** Description: destructor
*********************************************************************/

	~pokemon();

/*********************************************************************
** Program Filename:pokemon& operator
** Author: Dylan Peniuk
** Date: 11/13/24
** Description: AAO
*********************************************************************/

	pokemon& operator=(const pokemon &other);

/*********************************************************************
** Program Filename: pokemon
** Author: Dylan Peniuk
** Date: 11/13/24
** Description: copy constructor
*********************************************************************/

	pokemon(const pokemon &other); 

/*********************************************************************
** Program Filename: get_name
** Author: Dylan Peniuk
** Date: 11/13/24
** Description: getter for name
*********************************************************************/

	string get_name() const;

/*********************************************************************
** Program Filename: set_name
** Author: Dylan Peniuk
** Date: 11/13/24
** Description: setter for name
*********************************************************************/

	void set_name(const string name);

/*********************************************************************
** Program Filename: set_type
** Author: Dylan Peniuk
** Date: 11/13/24
** Description: setter for type
*********************************************************************/

	void set_type(const string type);

/*********************************************************************
** Program Filename: get_type
** Author: Dylan Peniuk
** Date: 11/13/24
** Description: getter for type
*********************************************************************/

	string get_type() const;

/*********************************************************************
** Program Filename: set_attack
** Author: Dylan Peniuk
** Date: 11/13/24
** Description: setter for type
*********************************************************************/

	void set_attack(const int attack);

/*********************************************************************
** Program Filename: get_attack
** Author: Dylan Peniuk
** Date: 11/13/24
** Description: getter for attack
*********************************************************************/

	int get_attack() const;

/*********************************************************************
** Program Filename: set_defence
** Author: Dylan Peniuk
** Date: 11/13/24
** Description: setter for defence
*********************************************************************/

	void set_defence(const int defence);

/*********************************************************************
** Program Filename: get_defence
** Author: Dylan Peniuk
** Date: 11/13/24
** Description: getter for defence
*********************************************************************/

	int get_defence() const;

/*********************************************************************
** Program Filename: set_health
** Author: Dylan Peniuk
** Date: 11/13/24
** Description: setter for health
*********************************************************************/

	void set_health(int health);

/*********************************************************************
** Program Filename: get_health
** Author: Dylan Peniuk
** Date: 11/13/24
** Description: getter for health
*********************************************************************/

	int get_health();

/*********************************************************************
** Program Filename: set_max_health
** Author: Dylan Peniuk
** Date: 11/13/24
** Description: setter for max_health
*********************************************************************/

	void set_max_health(const int max_health);

/*********************************************************************
** Program Filename: get_max_health
** Author: Dylan Peniuk
** Date: 11/13/24
** Description: getter for max_health
*********************************************************************/

	int get_max_health() const;

/*********************************************************************
** Program Filename: set_moves
** Author: Dylan Peniuk
** Date: 11/13/24
** Description: sets the moves so they can be accessed through pokemon
*********************************************************************/

	void set_moves(move* move_arr);

/*********************************************************************
** Program Filename: get_moves
** Author: Dylan Peniuk
** Date: 11/13/24
** Description: gets moves so they can be accessed through pokemon
*********************************************************************/

	move* get_moves() const;

/*********************************************************************
** Program Filename: get_moves_name
** Author: Dylan Peniuk
** Date: 11/13/24
** Description: gets the moves name
*********************************************************************/

	string get_moves_name(int move_num) const;

/*********************************************************************
** Program Filename: get_moves_type
** Author: Dylan Peniuk
** Date: 11/13/24
** Description: gets the moves type
*********************************************************************/

	string get_moves_type(int move_num) const;

/*********************************************************************
** Program Filename: get_moves_base_damage
** Author: Dylan Peniuk
** Date: 11/13/24
** Description: gets the moves base_damage
*********************************************************************/

	int get_moves_base_damage(int move_num) const;

/*********************************************************************
** Program Filename: set_moves_pp
** Author: Dylan Peniuk
** Date: 11/13/24
** Description: sets the moves pp
*********************************************************************/

	void set_moves_pp(int pp, int move_num);

/*********************************************************************
** Program Filename: get_moves_pp
** Author: Dylan Peniuk
** Date: 11/13/24
** Description: gets the moves pp
*********************************************************************/

	int get_moves_pp(int move_num) const;

/*********************************************************************
** Program Filename: use_moves_pp
** Author: Dylan Peniuk
** Date: 11/13/24
** Description: subtracts 1 from the pp value
*********************************************************************/

	int use_moves_pp(int move_num);

/*********************************************************************
** Program Filename: print
** Author: Dylan Peniuk
** Date: 11/13/24
** Description: prints out pokemon values
*********************************************************************/

	void print() const;

/*********************************************************************
** Program Filename: do_damage
** Author: Dylan Peniuk
** Date: 11/13/24
** Description: does damage and subracts it from health
*********************************************************************/

	int do_damage(int total_damage);

/*********************************************************************
** Program Filename: health_potion
** Author: Dylan Peniuk
** Date: 11/13/24
** Description: adds 10 health to health
*********************************************************************/

	int health_potion();

};

#endif

#ifndef MOVE_HPP
#define MOVE_HPP

using std::string;
using std::cout;
using std::endl;

class move {
	// TODO
private:
	string name;
	string type;
	int base_damage;
	int pp;
public:

/*********************************************************************
** Program Filename: move
** Author: Dylan Peniuk
** Date: 11/13/24
** Description: default constructor
*********************************************************************/

	move();

/*********************************************************************
** Program Filename: move
** Author: Dylan Peniuk
** Date: 11/13/24
** Description: non-default constructor
*********************************************************************/	

	move(string name, string type, int base_damage, int pp);

/*********************************************************************
** Program Filename: set_move_name
** Author: Dylan Peniuk
** Date: 11/13/24
** Description: sets move_name
*********************************************************************/

	void set_move_name(const string name);

/*********************************************************************
** Program Filename: get_move_name
** Author: Dylan Peniuk
** Date: 11/13/24
** Description: gets move_name
*********************************************************************/

	string get_move_name() const;

/*********************************************************************
** Program Filename: set_move_type
** Author: Dylan Peniuk
** Date: 11/13/24
** Description: sets move_type
*********************************************************************/

	void set_move_type(const string type);

/*********************************************************************
** Program Filename: get_move_type
** Author: Dylan Peniuk
** Date: 11/13/24
** Description: gets move_type
*********************************************************************/

	string get_move_type() const;

/*********************************************************************
** Program Filename: set_move_base_damage
** Author: Dylan Peniuk
** Date: 11/13/24
** Description: sets move_base_damage
*********************************************************************/

	void set_move_base_damage(const int base_damage);

/*********************************************************************
** Program Filename: get_move_base_damage
** Author: Dylan Peniuk
** Date: 11/13/24
** Description: gets move_base_damage
*********************************************************************/

 	int get_move_base_damage() const;

/*********************************************************************
** Program Filename: set_move_pp
** Author: Dylan Peniuk
** Date: 11/13/24
** Description: sets move_pp
*********************************************************************/

	void set_move_pp(int pp);

/*********************************************************************
** Program Filename: get_move_pp
** Author: Dylan Peniuk
** Date: 11/13/24
** Description: gets move_pp
*********************************************************************/

	int get_move_pp() const;

/*********************************************************************
** Program Filename: use_move_pp
** Author: Dylan Peniuk
** Date: 11/13/24
** Description: subtracts 1 from the pp of the given move
*********************************************************************/

	int use_move_pp();

};

#endif

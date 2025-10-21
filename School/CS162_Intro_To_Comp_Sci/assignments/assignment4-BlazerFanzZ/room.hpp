#ifndef ROOM_HPP
#define ROOM_HPP

#include "event.hpp"

// Room interface
class Room {
private: 
// TODO private members

public:
// TODO public members
	event* room_event;

	/******************************************************
	** Author: Dylan Peniuk
	** Date: 11/26/2024
	** Description: default constructor for room
	******************************************************/

	Room();

	/******************************************************
	** Author: Dylan Peniuk
	** Date: 11/26/2024
	** Description: destructor for room
	******************************************************/

	~Room();

	/******************************************************
	** Author: Dylan Peniuk
	** Date: 11/26/2024
	** Description: AOO for room
	******************************************************/

	Room& operator=(const Room &other);

	/******************************************************
	** Author: Dylan Peniuk
	** Date: 11/26/2024
	** Description: CC for room
	******************************************************/

	Room(const Room &other);

};

#endif

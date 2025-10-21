#ifndef WUMPUS_HPP
#define WUMPUS_HPP

#include "event.cpp"

// TODO Wumpus interface (define the wumpus class and declare its member
// functions below)

class wumpus : public event {
public:

	/******************************************************
	** Author: Dylan Peniuk
	** Date: 11/26/2024
	** Description: Overridden percept function 
	******************************************************/

    void percept() override;

	/******************************************************
	** Author: Dylan Peniuk
	** Date: 11/26/2024
	** Description: Overridden encounter function 
	******************************************************/

    int encounter() override;

	/******************************************************
	** Author: Dylan Peniuk
	** Date: 11/26/2024
	** Description: Overridden event_debug function 
	******************************************************/

    void event_debug() override;

private:
};


#endif

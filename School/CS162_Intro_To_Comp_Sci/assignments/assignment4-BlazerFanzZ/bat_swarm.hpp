#ifndef BAT_SWARM_HPP
#define BAT_SWARM_HPP

#include "event.cpp"

// TODO Bat Swarm interface (define the bat_swarm class and declare its member
// functions below)

class bat_swarm : public event {
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

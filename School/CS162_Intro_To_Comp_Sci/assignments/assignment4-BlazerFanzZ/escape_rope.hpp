#ifndef ESCAPE_ROPE_HPP
#define ESCAPE_ROPE_HPP

#include "event.cpp"

// TODO Escape rope interface (define the escape_rope class and declare its
// member functions below)

class escape_rope : public event {
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

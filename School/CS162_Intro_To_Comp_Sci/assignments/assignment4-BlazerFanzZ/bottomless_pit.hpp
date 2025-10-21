#ifndef BOTTOMLESS_PIT_HPP
#define BOTTOMLESS_PIT_HPP

#include "event.cpp"

// TODO Bottomless Pit interface (define the bottomless_pit class and declare
// its member functions below)

class bottomless_pit : public event {
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

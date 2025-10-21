#ifndef EVENT_HPP
#define EVENT_HPP

// Event interface
class event {
private:
	// TODO private members, if relevant
protected:
	// TODO protected members, if relevant
	//virtual char = debug_symbol() = 0;
public:
	// TODO public members

	/******************************************************
	** Author: Dylan Peniuk
	** Date: 11/26/2024
	** Description: pure virtual percept function
	******************************************************/

	virtual void percept() = 0;

	/******************************************************
	** Author: Dylan Peniuk
	** Date: 11/26/2024
	** Description: pure virtual encounter function
	******************************************************/

	virtual int encounter() = 0;

	/******************************************************
	** Author: Dylan Peniuk
	** Date: 11/26/2024
	** Description: pure virtual event_debug function
	******************************************************/

	virtual void event_debug() = 0;

	/******************************************************
	** Author: Dylan Peniuk
	** Date: 11/26/2024
	** Description: event destructor
	******************************************************/

	virtual ~event() = default;
};

#endif

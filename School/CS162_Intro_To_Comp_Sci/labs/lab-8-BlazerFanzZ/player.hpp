#ifndef PLAYER_HPP
#define PLAYER_HPP

class player {
private:
	int hp = 5; // Player's remaining hitpoints
	int location = 0; // Player's location on the 1D game board
	bool confused = false; // Records whether or not the player is confused
public:
	void take_damage(int amount); // Hurt the player by a given amount
	bool is_dead() const; // Returns true if the player is dead
	void heal(int amount); // Heal the player by a given amount
	void print_hp() const; // Prints the player's healthbar to the terminal
	void confuse(); // Confuse the player for a turn

	// Updates the player object (executed once per "turn" after moving the
	// player). In this small program, that simply means setting confused
	// back to false in case it's currently true (confusion from tornadoes
	// should only last one turn).
	void tick();
	
	int get_location() const;
	bool is_confused() const; // Getter for `confused`
	void move_right(); // Move player right by one space (i.e., location++)
	void move_left(); // Move player left by one space (i.e., location--)
};

#endif

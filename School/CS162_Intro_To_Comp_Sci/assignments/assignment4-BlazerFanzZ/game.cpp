#include <iostream>

#include "game.hpp"
#include "gold.hpp"
#include "bat_swarm.hpp"
#include "bottomless_pit.hpp"
#include "wumpus.hpp"
#include "escape_rope.hpp"
#include "arrow.hpp"

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;

// game implementation

game::game(int width, int height, bool debug) :
	width(width),
	height(height),
	debug(debug) {
// TODO Create the game board: 2D vector of room objects
	for (int i = 0; i < height; i++){
		vector<Room> width_vec;
		for (int j = 0; j < width; j++){
			Room room;
			width_vec.push_back(room);
		}
		gameboard_vec.push_back(width_vec);
	}

// TODO Randomly insert events (2 bat_swarms, 2 bottomless_pits,
// 1 wumpus, 1 gold, 2 arrows, 1 escape rope) into the board

	do{
		int random_h = rand() % height;
		int random_w = rand() % width;
		if(gameboard_vec[random_h][random_w].room_event == nullptr){
			room_num++;
			switch(room_num){ //creates events and puts them in rooms
				case 1:
					gameboard_vec[random_h][random_w].room_event = new bottomless_pit();
					break;
				case 2:
					gameboard_vec[random_h][random_w].room_event = new bottomless_pit();
					break;
				case 3:
					gameboard_vec[random_h][random_w].room_event = new bat_swarm();
					break;
				case 4:
					gameboard_vec[random_h][random_w].room_event = new bat_swarm();
					break;
				case 5:
					gameboard_vec[random_h][random_w].room_event = new escape_rope();
					break;
				case 6:
					gameboard_vec[random_h][random_w].room_event = new gold();
					break;
				case 7:
					gameboard_vec[random_h][random_w].room_event = new arrow();
					break;
				case 8:
					gameboard_vec[random_h][random_w].room_event = new arrow();
					break;
			}
		}
	}
	while(room_num < 8);
	hunt_wumpus();

	
}

void game::hunt_wumpus(){ //puts wumpus in room
	do{
		wumpus_h = rand() % height;
		wumpus_w = rand() % width;
		if(gameboard_vec[wumpus_h][wumpus_w].room_event == nullptr){
			room_num++;
			gameboard_vec[wumpus_h][wumpus_w].room_event = new wumpus();
		}
	}
	while(room_num < 9);
}

void game::display_game() const{
	cout << endl << endl;
	cout << "Arrows remaining: " << this->num_arrows << endl;

	string row_border = "--";
	for (int i = 0; i < this->width; ++i) {
		row_border += "-----";
	}

	cout << row_border << endl;
	for (int i = 0; i < this->height; ++i) {
		cout << "||";
		for (int j = 0; j < this->width; ++j) {
			// The first char indicates whether there is a player in the room
			// at row index i, column index j. TODO If the room contains the
			// player, print an asterisk ("*")
			if(i == position_h && j == position_w){
				cout << '*';
			}
			else if(this->debug && this->gameboard_vec[i][j].room_event != nullptr ){
				this->gameboard_vec[i][j].room_event->event_debug();
			}

			// TODO else, print a space (" ")
			else{
				cout << " ";
			}
			// The next char indicates the event in the room.
			
			// TODO If debug mode is disabled OR the room at location <i, j>
			// does not have an event, print a space (" ")
			// For example:
			// if (!this->debug || <i, j> ROOM DOES NOT HAVE EVENT) {
			// 	cout << " ";
			// }
			//
			// TODO else, print the room's debug symbol. There are a few ways to
			// do this. You can use polymorphism, or an event could have a
			// char debug_symbol member variable and some sort of
			// get_debug_symbol() member function that you could call here
			// to get the character and print it.

			cout << " ||";
		}
		cout << endl;
		cout << row_border << endl;
	}

	//example output (when finished): 
	// ----------------------
	// || P || G || P ||   ||
	// ----------------------
	// ||   || W ||   || S ||
	// ----------------------   
	// ||   ||   ||   || S ||
	// ----------------------   
	// ||*  ||   ||   ||   ||
	// ----------------------
}

bool game::check_win() const{
	// TODO Delete the below placeholder code. Return true if the player
	// has won the game. Return false otherwise.

	return win;
}

bool game::check_lose() const{
	// TODO Delete the below placeholder code. Return true if the player
	// has lost the game. Return false otherwise.

	return lose;
}

bool game::is_direction(char c) {
	return c == 'w' ||
		c == 'a' ||
		c == 's' ||
		c == 'd';
}

char game::to_lower(char direction) {
	if (direction >= 'A' && direction <= 'Z') {
		return direction + ('a' - 'A');
	}
	return direction;
}

bool game::can_move_in_direction(char direction) {
	// TODO Delete the below placeholder code. Return true if the player can
	// move in the given direction ('w' for up, 'a' for left, 's' for down,
	// 'd' for right). Return false otherwise. The player can move in the
	// given direction so long as it wouldn't cause them to move off the
	// grid.
	
	if(direction == 'w' && position_h == 0){
		return false;
	}
	else if(direction == 's' && position_h == this->height - 1){
		return false;
	}
	else if(direction == 'a' && position_w == 0){
		return false;
	}
	else if(direction == 'd' && position_w == this->width - 1){
		return false;
	}
	else{
		return true;
	}
}

bool game::is_valid_action(char action) {
	if (this->is_direction(action)) {
		char direction = action;
		return this->can_move_in_direction(direction);
	} else if (action == 'f') {
		return this->num_arrows > 0;
	}
	return false;
}

void game::print_action_error(char action) {
	if (this->is_direction(action)) {
		cout << "You can't move in that direction!" << endl <<
			endl;
	} else if (action == 'f') {
		cout << "You're out of arrows!" << endl << endl;
	} else {
		cout << endl << "That's an invalid input!" << endl
			<< endl;
	}
}

char game::get_player_action() {
	char action;
	bool first = true;
	do {
		if (!first) {
			char previous_action = action;
			this->print_action_error(previous_action);
		}
		first = false;

		cout << endl << endl << "What would you like to do?" <<
			endl << endl;
		cout << "w: move up" << endl;
		cout << "a: move left" << endl;
		cout << "s: move down" << endl;
		cout << "d: move right" << endl;
		cout << "f: fire an arrow" << endl;

		cin >> action;
		action = this->to_lower(action);
	} while (!this->is_valid_action(action));

	return action;
}

char game::get_arrow_fire_direction() {
	char direction;
	bool first = true;
	do {
		if (!first) {
			cout << endl << "That's an invalid input!" <<
				endl << endl;
		}
		first = false;

		cout << endl << endl <<
			"What direction would you like to fire the arrow?" << endl <<
			endl;
		cout << "w: up" << endl;
		cout << "a: left" << endl;
		cout << "s: down" << endl;
		cout << "d: right" << endl;

		cin >> direction;
		direction = this->to_lower(direction);
	} while (!this->is_direction(direction));

	return direction;
}

void game::move_up() {
	// TODO Delete the below placeholder code. Move the player up one
	// space in the grid, however you choose to do that.

	position_h -= 1;
}

void game::move_down() {
	// TODO Delete the below placeholder code. Move the player down one
	// space in the grid, however you choose to do that.

	position_h += 1;
}

void game::move_left() {
	// TODO Delete the below placeholder code. Move the player left one
	// space in the grid, however you choose to do that.

	position_w -= 1;
}

void game::move_right() {
	// TODO Delete the below placeholder code. Move the player right one
	// space in the grid, however you choose to do that.

	position_w += 1;
}

void game::move(char direction) {
	if(user_confusion == false){
		if (direction == 'w') {
			this->move_up();
		} 
		else if (direction == 'a') {
			this->move_left();
		} 
		else if (direction == 'd') {
			this->move_right();
		} 
		else {
			this->move_down();
		}
	}
	else{
		int rand_move = rand() % 4 + 1;
		if (rand_move == 1) {
			direction = 'w';
			this->move_up();
		} 
		else if (rand_move == 2) {
			direction = 'a';
			this->move_left();
		} 
		else if (rand_move == 3) {
			direction = 'd';
			this->move_right();
		} 
		else {
			direction = 's';
			this->move_down();
		}
	}
	user_confusion = false;
}

void game::fire_arrow_up() {
	// TODO Delete the below placeholder code. Fire the arrow upward, killing
	// the wumpus if it hits it or making the wumpus "wake up" and move
	// randomly if it misses

	for(int i = 1; i < 4; i++){
		arrow_loc = position_h - i;
		if(position_w == wumpus_w && arrow_loc == wumpus_h){
			win = true;
			cout << "You hear a loud screaching from the direction of your arrow... the wumpus has been kiled" << endl;
			break;
		}
	}
	delete this->gameboard_vec[wumpus_h][wumpus_w].room_event;
	this->gameboard_vec[wumpus_h][wumpus_w].room_event = nullptr;
	hunt_wumpus();
}

void game::fire_arrow_down() {
	// TODO Delete the below placeholder code. Fire the arrow downward, killing
	// the wumpus if it hits it or making the wumpus "wake up" and move
	// randomly if it misses

	for(int i = 1; i < 4; i++){
		arrow_loc = position_h + i;
		if(position_w == wumpus_w && arrow_loc == wumpus_h){
			win = true;
			cout << "You hear a loud screaching from the direction of your arrow... the wumpus has been kiled" << endl;
			break;
		}
	}
	delete this->gameboard_vec[wumpus_h][wumpus_w].room_event;
	this->gameboard_vec[wumpus_h][wumpus_w].room_event = nullptr;
	hunt_wumpus();
}

void game::fire_arrow_left() {
	// TODO Delete the below placeholder code. Fire the arrow leftward, killing
	// the wumpus if it hits it or making the wumpus "wake up" and move
	// randomly if it misses
	
	for(int i = 1; i < 4; i++){
		arrow_loc = position_w - i;
		if(position_h == wumpus_h && arrow_loc == wumpus_w){
			win = true;
			cout << "You hear a loud screaching from the direction of your arrow... the wumpus has been kiled" << endl;
			break;
		}
	}
	delete this->gameboard_vec[wumpus_h][wumpus_w].room_event;
	this->gameboard_vec[wumpus_h][wumpus_w].room_event = nullptr;
	hunt_wumpus();
}

void game::fire_arrow_right() {
	// TODO Delete the below placeholder code. Fire the arrow rightward, killing
	// the wumpus if it hits it or making the wumpus "wake up" and move
	// randomly if it misses

	for(int i = 1; i < 4; i++){
		arrow_loc = position_w + i;
		if(position_h == wumpus_h && arrow_loc == wumpus_w){
			win = true;
			cout << "You hear a loud screaching from the direction of your arrow... the wumpus has been kiled" << endl;
			break;
		}
	}
	delete this->gameboard_vec[wumpus_h][wumpus_w].room_event;
	this->gameboard_vec[wumpus_h][wumpus_w].room_event = nullptr;
	hunt_wumpus();
}

void game::fire_arrow(char direction) {
	if (direction == 'w') {
		this->fire_arrow_up();
	} else if (direction == 'a') {
		this->fire_arrow_left();
	} else if (direction == 'd') {
		this->fire_arrow_right();
	} else {
		this->fire_arrow_down();
	}

	this->num_arrows--;
}

void game::play_game(){
	while (!this->check_win() && !this->check_lose()) {
		// Print game board
		this->display_game();

		// TODO Display precepts around player's location
		//checking up position for percept
		if(position_h - 1 != -1 && this->gameboard_vec[position_h - 1][position_w].room_event != nullptr){
			this->gameboard_vec[position_h - 1][position_w].room_event->percept();
		}
		//checking down position for percept
		if(position_h + 1 != height && this->gameboard_vec[position_h + 1][position_w].room_event != nullptr){
			this->gameboard_vec[position_h + 1][position_w].room_event->percept();
		}
		//checking left position for percept
		if(position_w - 1 != -1 && this->gameboard_vec[position_h][position_w - 1].room_event != nullptr){
			this->gameboard_vec[position_h][position_w - 1].room_event->percept();
		}
		//checking right position for percept
		if(position_w + 1 != width && this->gameboard_vec[position_h][position_w + 1].room_event != nullptr){
			this->gameboard_vec[position_h][position_w + 1].room_event->percept();
		}
		// Ask player for their action
		char action = this->get_player_action();

		// Process action
		if (this->is_direction(action)) {
			// W/A/S/D = move player
			char direction = action;
			this->move(direction);
		} else {
			// F = prompt for arrow fire direction and fire arrow
			char direction = this->get_arrow_fire_direction();
			this->fire_arrow(direction);
		}

		// TODO If the user is on a space with an event, trigger its encounter
		if(this->gameboard_vec[position_h][position_w].room_event != nullptr){
			int event_encounter = this->gameboard_vec[position_h][position_w].room_event->encounter();
			switch(event_encounter){
				case 1:
					lose = true;
					break;
				case 2:
					break;
				case 3:
					user_confusion = true;
					delete this->gameboard_vec[position_h][position_w].room_event;
					this->gameboard_vec[position_h][position_w].room_event = nullptr;
					break;
				case 4:
					num_arrows++;
					delete this->gameboard_vec[position_h][position_w].room_event;
					this->gameboard_vec[position_h][position_w].room_event = nullptr;
					break;
				case 5:
					if(gold_coin == 1){
						win = true;
					}
					break;
				case 6:
					delete this->gameboard_vec[position_h][position_w].room_event;
					this->gameboard_vec[position_h][position_w].room_event = nullptr;
					gold_coin++;
			}
		}

	}
}

#include <fstream>
#include <iostream>

#include "baseball_player.hpp"

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::ifstream;
using std::ofstream;


int main() {
	// TODO Make sure you understand the below code
	string file_name = prompt_for_file_name();
	ifstream file;
	file.open(file_name);
	if (!file.is_open()) {
		cout << file_name << " could not be opened" << endl;
		return -1;
	}

	int size;
	file >> size;
	
	// TODO Read the number of players from the top of the file and
	// store it in `size`

	// Allocate array
	baseball_player* players = create_players(size);
	
	// Populate array data
	for (int i = 0; i < size; i++) {
		players[i] = read_player_data(file);
	}

	// Print array data
	for (int i = 0; i < size; i++) {
		print_player(players[i]);
	}

	// Delete array data
	delete_player_info(players);
}

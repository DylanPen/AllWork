#include <iostream>

#include "baseball_player.hpp"

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::ifstream;
using std::ofstream;


baseball_player* create_players(int size) {
	return new baseball_player[size];
}

void print_player(const baseball_player& player) {
	cout << player.first_name << " " <<
		player.last_name << " has a batting average of " <<
		player.batting_average << endl;
}

string prompt_for_file_name() {
	cout << "Enter the name of the data file: ";
	string file_name;
	cin >> file_name;
	return file_name;
}

baseball_player read_player_data(ifstream& file) {
	baseball_player result;
	file >> result.first_name;
	file >> result.last_name;
	file >> result.batting_average;

	// TODO Read the next player's data (first name, last name, and
	// batting average) from the file and store it in the member variables
	// of the baseball player called `result`

	return result;
}

void delete_player_info(baseball_player* players) {
	delete [] players;
}

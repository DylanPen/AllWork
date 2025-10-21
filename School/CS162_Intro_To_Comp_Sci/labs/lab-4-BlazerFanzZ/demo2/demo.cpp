#include <iostream>
#include <fstream>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::ifstream;
using std::ofstream;

// Read input file name from user and return it.
string get_filename() {
	cout << "Enter file name: ";
	string filename;
	cin >> filename;
	return filename;
}

// Read n_names from top of input file. ifstreams MUST be passed by reference.
int get_n_names(ifstream& file) {
	int n_names;
	file >> n_names;
	return n_names;
}

// Write the given name to output.txt
void output_name_to_file(string name) {
	ofstream output_file;
	output_file.open("output.txt");
	output_file << name << endl;
}

int main() {
	string filename = get_filename();

	ifstream file;
	file.open(filename);
	if (!file.is_open()) {
		// Failed to open file. Print error and end program.
		cout << "Error! Failed to open file." << endl;
	} else {
		// File exists and opened successfully. Continue with program.
		int n_names = get_n_names(file);

		// Create array of names and populate
		string* names = new string[n_names];
		for (int i = 0; i < n_names; i++) {
			file >> names[i];
		}

		// Write second name to output file
		output_name_to_file(names[1]);

		// Delete array of names
		delete [] names;
		names = nullptr;
	}
}

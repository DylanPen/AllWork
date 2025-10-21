#include <iostream>

#include "recursion.hpp"

using std::endl;
using std::cout;

void print_test_case(int n, int correct) {
	int prediction = no_zero_strings(n);
	cout << "Correct output for no_zero_strings(" <<
		n << "):         " << correct << endl;
	cout << "Your function's output for no_zero_strings(" <<
		n << "): " << prediction;
	
	if (correct != prediction) {
		cout << " (ERROR! INCORRECT ANSWER)";
	}
	cout << endl << endl;
}

int main() {
	print_test_case(1, 2);
	print_test_case(2, 3);
	print_test_case(3, 5);
	print_test_case(4, 8);
	print_test_case(10, 144);
}

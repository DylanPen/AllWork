#include <cstdlib>
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

void populate_multiplication_table(int table[12][12]){
	for(int i = 0; i < 12; i++){
		for(int j = 0; j < 12; j++){
			table[i][j] = (i + 1) * (j + 1);
		}
		
	}
}

int main()
{
	int table[12][12];
	populate_multiplication_table(table);
	for(int i = 0; i < 12; i++){
		for(int j = 0; j < 12; j++){
			cout << table[i][j] << "\t";
		}
		cout << endl;
		
	}


	return 0;
}

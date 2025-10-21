//This is for Lab 2 Part 3: Array exercise

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;


//function to populate the array elements
void populate_array(int array[], int size){

	for(int i = 0; i < size; i++){
		array[i] = rand() % 100 + 1;
	}
	for(int j = 0; j < size; j++){
		cout << array[j] << endl;
	}
	return;
}


//hint: create another function to print the statistics
void array_stats(int array[], int size){
	int sum;
	for(int i = 0; i < size; i++){
		sum += array[i];
	}
	cout << "Sum: " << sum << endl;
	int max = 0;
	for(int i = 0; i < size; i++){
		if(array[i] > max){
			max = array[i];
		}
	}
	cout << "Max: " << max << endl;
	int average = sum / size;
	cout << "Average: " << average << endl;

}

int main()
{
	srand(time(nullptr));
	int user_input;
	int arr[50];
	bool play_again = true;
	while(play_again == true){
		do{
		cout << "enter anumber from 5 to 50: ";
		cin >> user_input;
		}
		while(user_input < 5 || user_input > 50);
		populate_array(arr, user_input);
		array_stats(arr, user_input);
		char yes_no;
		do{
			cout << "Would you like to play again? (y/n) " << endl;
			cin >> yes_no;
		}
		while(yes_no != 'y' && yes_no != 'n');
		if(yes_no == 'y'){
			play_again = true;
		}
		else if(yes_no == 'n'){
			play_again = false;
		}
	}
	return 0;
}
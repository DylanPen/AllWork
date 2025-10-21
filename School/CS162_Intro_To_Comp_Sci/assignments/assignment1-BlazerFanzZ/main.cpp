// In some assignments, you will be provided with a bit of "skeleton code"
// to get you started. However, this assignment is largely geared toward
// getting you up to speed on the basics of C++ programming, so there's very
// minimal starter code here for you.

// All of your programming assignments' driver files (i.e., the .cpp file
// containing the main() function) should have a program header at the
// top. Fill in the program header below:

/*
 * Author: <INSERT YOUR NAME HERE>
 * Program description: <VERY BRIEF DESCRIPTION OF PROGRAM HERE>
 */

// Recall: this is the syntax for importing / including system-installed
// header files in C++. The <iostream> header file gives you access to
// input / output (I/O) tools, like std::cout, std::cin, and std::endl, so
// that your program can interface with the terminal
#include <iostream>

// You'll also need <cstdlib> and <ctime> to use srand() and rand() for
// pseudorandom number generation (PRNG)
#include <cstdlib>
#include <ctime>

// TODO: Create many other functions here (you'll want several of them to
// satisfy the course's style guidelines: 
// https://web.engr.oregonstate.edu/~songyip/Teaching/CS16X/cpp_style_guideline.pdf)

// Recall: This is the main() function. It's the entrypoint to your program
// (i.e., it is where your program will both start and end).

//This runs the core of the game calculating random values, storing them to arrays, and referencing th=ose arrays and comparing values to determing if shots are made or missed


char charFinder(int arr[], int mball, int stat, int j, int i){
	if(i != mball){
		if(arr[j] <= stat && arr[j] != arr[5]){
			return 'X';
		}
		else if(arr[j] <= stat){
			return 'M';
		}
		else{
			return '_';
		}
	}
	else{
		if(arr[j] <= stat){
			return 'M';
		}
		else{
			return '_';
		}
	}
}

char starryCheck(int arr[], int stat, int i, int rand){
	if(i == 2 || i == 3){
		std::cout << std::endl << "Starry: ";
		if(rand <= stat){
			return 'S';
		}
		else{
			return '_';
		}
	}
	return ' ';
}

int play(int mball, int stat){
	int arr[5], score = 0, tempscore = 0;
	srand(time(nullptr));

	for(int i = 1; i <= 5; i++){
		for(int j = 1; j <= 5; j++){
			int rand = std::rand() % 100;
			arr[j] = rand;
			char make_or_miss = charFinder(arr, mball, stat, j, i);
			std::cout << make_or_miss << " ";
			if(make_or_miss == 'X'){
				tempscore += 1;
			}
			else if(make_or_miss == 'M'){
				tempscore += 2;
			}
		}
		std::cout << " | " << tempscore << " pts";
		int rand = std::rand() % 100;
		char starry = starryCheck(arr, stat, i, rand); 
		std::cout << starry;
		if(starry == 'S'){
			std::cout << "  | " << "3 pts";
			tempscore += 3;
		}
		else if(starry == '_'){
			std::cout << "  | " << "0 pts";
		}
		score += tempscore;
		tempscore = 0;
		std::cout << std::endl;
	}
	return score;
}

void getPlayers(){
	int mball[2], stat[2], mballp1, mballp2, statp1, statp2;
	for (int i = 0; i < 2; i++){
		std::cout << "Player" << i+1 << ":" << std::endl;
		do{
			std::cout << "Where do you want your money ball rack (1-5): ";
			std::cin >> mball[i];
		}
		while(mball[i] < 1 || mball[i] > 5);
		do
		{
			std::cout << "What is your shooting stat (1-99): ";
			std::cin >> stat[i];
		} while (stat[i] < 1 || stat[i] > 99);
	}
	mballp1 = mball[0];
	mballp2 = mball[1];
	statp1 = stat[0];
	statp2 = stat[1];
	std::cout << "Player 1:" << std::endl;
	int score1 = play(mballp1, statp1);
	std::cout << "Player 2:" << std::endl;
	int score2 = play(mballp2, statp2);
	std::cout << "Player 1 Score: " << score1 << std::endl;
	std::cout << "Player 2 Score: " << score2 << std::endl;
	if(score1 > score2){
		std::cout << "Player 1 wins" << std::endl;
	}
	else if(score2 > score1){
		std::cout << "Player 2 wins" << std::endl;
	}
	else{
		std::cout << "It's a tie!" << std::endl;
	}
}
int playAgainCheck(int playAgain){
	do{
		std::cout << "Do you want to play again? (1 for yes, 0 for no) ";
		std::cin >> playAgain;	
	}
	while(playAgain > 1 || playAgain < 0);
	return playAgain;

}

int main() {
	// This line seeds your PRNG. You don't need to call srand() anywhere else.
	// After it's been called, you can then proceed to use the rand() function
	// to generate pseudorandom numbers at any point in your program.
	int playAgain = 0;
	do{
		getPlayers();
		playAgain = playAgainCheck(playAgain);
	}
	while(playAgain == 1);

	// TODO: complete the main function, having it call other functions (and
	// perhaps having those functions call other functions, and so on) to
	// complete the program as described in the assignment description document
	// on Canvas.
}

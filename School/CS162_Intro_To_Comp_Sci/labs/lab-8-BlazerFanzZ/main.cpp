#include <vector>

#include "game.hpp"
#include "event.hpp"
#include "apple_pie.hpp"
#include "zombie.hpp"
#include "tornado.hpp"

int main() {
	// TODO Create vector of event pointers. Initialize those pointers like so:
	// index 0: nullptr (no event here)
	// index 1: pointer to a zombie on the heap
	// index 2: pointer to a zombie on the heap
	// index 3: pointer to an apple pie on the heap
	// index 4: pointer to a tornado on the heap
	// index 5: nullptr (no event here)
	// index 6: pointer to a zombie on the heap
	// index 7: pointer to an apple pie on the heap
	// index 8: nullptr (no event here)
	// index 9: pointer to a zombie on the heap

	std::vector <event*> events(10);

	events[0] = nullptr;
	events[1] = new zombie();
	events[2] = new zombie();
	events[3] = new apple_pie();
	events[4] = new tornado();
	events[5] = nullptr;
	events[6] = new zombie();
	events[7] = new apple_pie();
	events[8] = nullptr;
	events[9] = new zombie();

	// You can initialize the pointers in the vector however you'd like. You
	// can just write out ten separate lines of code if you'd like, or you can
	// even due braced initialization (we didn't cover this, but it looks like:
	// std::vector<event*> game_board {nullptr, new zombie, new zombie ...};)

	// Create the player object, p
	player p;

	// TODO Pass your vector of event pointers and p to the global play() function,
	// provided by game.hpp
	play(events, p);
	
	// TODO Delete all remaining events in the game board from the heap
	// and set them to nullptr
	for(int i = 0; i < 10; i++){
		if(events[i] != nullptr){
			delete events[i];
			events[i] = nullptr;
		}
	}
}

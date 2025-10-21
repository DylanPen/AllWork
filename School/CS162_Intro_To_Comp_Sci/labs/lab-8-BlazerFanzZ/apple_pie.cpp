#include <iostream>

#include "apple_pie.hpp"

// TODO Implement the apple pie's encounter() function override to heal the
// player by 2 HP and return true to indicate that it should be removed from
// the board.


bool apple_pie::encounter(player &p){
    p.heal(2);
    return true;
}

// TODO Implement the apple pie's print() function override to print "A"
// to the terminal (do NOT print std::endl after the "A")
void apple_pie::print() const{
    std::cout << 'A';
}

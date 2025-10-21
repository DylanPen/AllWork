#include <iostream>

#include "escape_rope.hpp"

// TODO Escape rope implementation (define escape_rope member functions below)

void escape_rope::percept(){
    std::cout << std::endl;
    std::cout << "You see a rope hanging from the cieling" << std::endl;
    std::cout << std::endl;
}

int escape_rope::encounter(){
    std::cout << "You found the escape rope!" << std::endl;
    return 5;
}

void escape_rope::event_debug(){
    std::cout << 'R';
}
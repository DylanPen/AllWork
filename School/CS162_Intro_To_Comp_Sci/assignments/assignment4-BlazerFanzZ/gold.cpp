#include <iostream>

#include "gold.hpp"

// TODO Gold implementation (define gold member functions below)

void gold::percept(){
    std::cout << std::endl;
    std::cout << "You see shimmering in the distance" << std::endl;
    std::cout << std::endl;
}

int gold::encounter(){
    std::cout << "You found the gold!" << std::endl;
    return 6;
}

void gold::event_debug(){
    std::cout << 'G';
}
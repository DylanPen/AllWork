#include <iostream>

#include "wumpus.hpp"

// TODO Wumpus implementation (define wumpus member functions below)

void wumpus::percept(){
    std::cout << std::endl;
    std::cout << "Fear fills your body" << std::endl;
    std::cout << std::endl;
}

int wumpus::encounter(){
    std::cout << "A huge beats devowers you" << std::endl;
    return 1;

}

void wumpus::event_debug(){
    std::cout << 'W';
}
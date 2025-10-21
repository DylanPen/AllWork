#include <iostream>

#include "bat_swarm.hpp"

// TODO Bat Swarm implementation (define bat_swarm member functions below)

void bat_swarm::percept(){
    std::cout << std::endl;
    std::cout << "You can hear bats nearby" << std::endl;
    std::cout << std::endl;
}

int bat_swarm::encounter(){
    std::cout << "The bats fly around you can you cant see where you're going" << std::endl;
    return 3;
}

void bat_swarm::event_debug(){
    std::cout << 'B';
}

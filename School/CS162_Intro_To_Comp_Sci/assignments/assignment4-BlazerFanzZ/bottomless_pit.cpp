#include <iostream>

#include "bottomless_pit.hpp"

// TODO Bottomless Pit implementation (define bottomless_pit member functions
// below)

void bottomless_pit::percept(){
    std::cout << std::endl;
    std::cout << "Bottomless Pit Nearby" << std::endl;
    std::cout << std::endl;
}

int bottomless_pit::encounter(){
    int randomNum = rand() % 2;
    if(randomNum == 1){
        std::cout << "You fell in the hole" << std::endl;
        return 1;
    }
    else{
        std::cout << "You were able to stop befor you fell in the hole" << std::endl;
        return 2;
    }
}

void bottomless_pit::event_debug(){
    std::cout << 'P';
}

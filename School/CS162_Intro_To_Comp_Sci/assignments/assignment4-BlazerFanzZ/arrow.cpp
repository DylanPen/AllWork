#include <iostream>

#include "arrow.hpp"

// TODO Arrow implementation (define arrow member functions below)

void arrow::percept(){
    std::cout << std::endl;
    std::cout << "Something sharp pokes your foot" << std::endl;
    std::cout << std::endl;
}

int arrow::encounter(){
    std::cout << "You found an arrow" << std::endl;
    return 4;   
}

void arrow::event_debug(){
    std::cout << 'A';
}
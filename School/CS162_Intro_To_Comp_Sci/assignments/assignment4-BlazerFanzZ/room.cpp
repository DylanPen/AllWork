#include "room.hpp"

// TODO Room implementation (define room member functions below)

Room::Room(){
    this->room_event = nullptr;
}

Room::~Room(){
    delete room_event;
    room_event = nullptr;
}

Room& Room::operator=(const Room &other){
    if(this == &other){
        return *this;
    }

    if(this->room_event != nullptr){
        delete this->room_event;
    }
    this->room_event = other.room_event;

    return *this;
}

Room::Room(const Room &other){
    this->room_event = other.room_event;
}



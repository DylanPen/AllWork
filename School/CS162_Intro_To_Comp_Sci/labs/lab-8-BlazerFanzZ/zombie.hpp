#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include "event.hpp"
#include "player.hpp"

// TODO Define the zombie class and prototype its encounter() and print()
// functions

class zombie: public event{
    private:

    public:
        bool encounter(player &p);
        void print() const;
};

#endif

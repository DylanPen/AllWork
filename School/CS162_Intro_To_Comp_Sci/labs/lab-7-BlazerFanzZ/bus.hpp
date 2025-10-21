#ifndef BUS_HPP
#define BUS_HPP

#include "vehicle.hpp"

class Bus : public Vehicle {
private:
    int seat_capacity;
public:
    Bus();
    Bus(const string brand, int year, double range, int seat_capacity);
    double fuel_price();
    void print_info();

};
#endif
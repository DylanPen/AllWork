#ifndef CAR_HPP
#define CAR_HPP

#include "vehicle.hpp"

class Car : public Vehicle {
private:
int num_door;
bool electric; // true if powered by electricity, false otherwise
public:
    Car();
    Car(const string brand, int year, double range, int num_door, bool electric);
    double fuel_price();
    void print_info();
};


#endif
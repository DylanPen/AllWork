#include <iostream>
#include "bus.hpp"

using std::cout;
using std::endl;

Bus::Bus(){

}

Bus::Bus(const string brand, int year, double range, int seat_capacity): Vehicle(brand, year, range) { 
    this->seat_capacity = seat_capacity;
}

double Bus::fuel_price(){
    return 20 / range;
}

void Bus::print_info(){
    Vehicle::print_info();
    double fc = fuel_price();
    cout << "Fuel price: " << fc << endl;
    cout << "Seat Capacity: " << seat_capacity << endl;

}
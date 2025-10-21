#include <iostream>
#include "vehicle.hpp"

using std::cout;
using std::endl;

Vehicle::Vehicle(){
    
}

Vehicle::Vehicle(const string brand, int year, double range):
    brand(brand),
    year(year),
    range(range){}

double Vehicle::fuel_price() const {
    return 0;
}

void Vehicle::print_info() const{
    cout << "Brand: " << this->brand << endl;
    cout << "Year: " << this->year << endl;
    cout << "Range: " << this->range << endl;
}

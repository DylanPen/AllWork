#include <iostream>
#include "vehicle.hpp"
#include "car.hpp"
#include "bus.hpp"

using std::cout;
using std::endl;

int main(){
    cout << "VEHICLE: " << endl;
    Vehicle v1("bmw", 2020, 200.0);
    v1.print_info();
    cout << "CAR: " << endl;
    Car c1("Mercedes", 2023, 10, 4, true);
    c1.print_info();
    cout << "BUS: " << endl;
    Bus b1("Mercedes", 2023, 10, 60);
    b1.print_info();
    return 0;
}
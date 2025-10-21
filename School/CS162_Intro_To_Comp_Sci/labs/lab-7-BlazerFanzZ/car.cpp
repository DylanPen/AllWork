#include <iostream>
#include "car.hpp"

using std::cout;
using std::endl;

Car::Car(){

}

Car::Car(const string brand, int year, double range, int num_door, bool electric): Vehicle(brand, year, range) { 
    this->num_door = num_door;
    this->electric = electric; 
}

double Car::fuel_price(){
    if(electric){
        return 1.5 / range;
    }
    else{
        return 2 / range;
    }
}

void Car::print_info(){
    Vehicle::print_info();
    double fc = fuel_price();
    cout << "Fuel price: " << fc << endl;
    cout << "Number of doors: " << num_door << endl;
    cout << "Electric: " << electric << endl;

}
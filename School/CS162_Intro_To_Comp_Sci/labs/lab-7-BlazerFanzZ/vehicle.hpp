#ifndef VEHICLE_HPP
#define VEHICLE_HPP

using std::string;

class Vehicle {
private:
    const string brand; //note the keyword ‘const’
    int year;
protected:
    double range;
public:
    Vehicle();
    Vehicle(const string brand, int year, double range);
    double fuel_price() const;
    void print_info() const;
    // Other member functions, constructors, getters / setters…
};

#endif
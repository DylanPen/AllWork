#include <cmath>
#include "sigmoid.h"

double sigmoid(double val){
    return 1/(1+exp(-val));
}

double delta_sigmoid(double val){
    double temp=sigmoid(val);
    return temp*(1-temp);
}
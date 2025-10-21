#include <iostream>
#include <cmath>
#include <random>
#include "node.h"
#include "sigmoid.h"

using namespace std;


void Node::calculateValue(){
    this->value=0;
    this->w_sum=0;
    for(int i=0;i<this->prev_layer_size;i++){
        this->w_sum+=(*(this->prev_value_addrs[i])*this->weights[i]);
    }
    this->w_sum+=this->bias;
    this->value=sigmoid(this->w_sum);
}

Node::Node(){
    this->prev_layer_size=0;
    this->weights=nullptr;
    this->prev_value_addrs=nullptr;
}

Node::Node(int prev_layer_size){
    this->prev_layer_size=prev_layer_size;
    this->weights=new double[prev_layer_size];
    for(int i=0;i<prev_layer_size;i++){
        //this->weights[i]=2*((double)rand()/RAND_MAX)-1; //Random weight between -1 and 1
        this->weights[i]=0;
    }
    this->prev_value_addrs=new double*[prev_layer_size];
    this->value=0;
    //this->bias=2*((double)rand()/RAND_MAX)-1;
    this->bias=0;
}

Node::Node(const Node& n){
    this->value=n.value;
    this->prev_layer_size=n.prev_layer_size;
    this->weights=new double[this->prev_layer_size];
    this->prev_value_addrs=new double*[prev_layer_size];
    for(int i=0;i<this->prev_layer_size;i++){
        this->weights[i]=n.weights[i];
        this->prev_value_addrs[i]=n.prev_value_addrs[i];
    }
}

Node::~Node(){
    if(this->weights!=nullptr){
        delete [] this->weights;
    }

    if(this->prev_value_addrs!=nullptr){
        delete [] this->prev_value_addrs;
    }
}
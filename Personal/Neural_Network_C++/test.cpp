//A file to be run and contain predefined tests to ensure accuracy of algorithms
#include <iostream>
#include <cmath>
#include "nn.h"

using namespace std;

int main(){
    //Initialize test network
    int size=3;
    int layers[size]={2,2,2};
    NeuralNet net(size,layers);
    
    net.layers[1][0].weights[0]=1;
    net.layers[1][0].weights[1]=2;
    net.layers[1][0].bias=1;

    net.layers[1][1].weights[0]=3;
    net.layers[1][1].weights[1]=4;
    net.layers[1][1].bias=2;

    net.layers[2][0].weights[0]=1;
    net.layers[2][0].weights[1]=2;
    net.layers[2][0].bias=0;

    net.layers[2][1].weights[0]=2;
    net.layers[2][1].weights[1]=1;
    net.layers[2][1].bias=1;

    //Train the network once on predetermined inputs and outputs
    int input_size=2;
    double inputs[input_size]={0.7,0.5};
    int output_size=2;
    double outputs[output_size]={0.2,0.8};
    net.trainIter(input_size,inputs,output_size,outputs);

    //Check that all the changes to the weights and biases are correct
    double expected[2][6]={{0.00509327,0.00356529,0.00254663,0.00033738,0.00023617,0.00016869},
                           {0.07196142,0.06742976,0.07180038,0.00717694,0.00672499,0.00716088}};

    bool failed=false;
    for(int i=0;i<2;i++){
        for(int j=0;j<6;j++){
            cout << "TEST " << j+(i*6) << ". Indices: " << i << "," << j << endl;
            if(abs(expected[i][j]-net.delta_wbs[i][j])>0.00001){
                cout << "FAILED with error: " << expected[i][j]-net.delta_wbs[i][j] << "\n" << endl;
                failed=true;
            }else{ 
                cout << "PASSED\n" << endl;
            }
        }
    }

    if(!failed){
        cout << "Passed all tests" << endl;
    }else{
        cout << "Failed some tests" << endl;
    }
}
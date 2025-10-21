#ifndef NN_H
#define NN_H

#include <vector>
#include <unordered_map>
#include "node.h"

class NeuralNet{
    public:
        int num_layers;
        int *layer_params;
        std::vector<std::vector<Node>> layers;
        int *delta_params;
        double **delta_wbs;
        int training_iters;
        

        void printValues();
        void printTestNetwork();
        void printDeltaWbs();
        void forwardProp(int,double*);
        void backwardProp(int,double*);
        void trainIter(int,double*,int,double*);
        double stepForwardM(int,char,int,int,int,double*,std::unordered_map<std::string,int> *hash_map,int debug=0);
        double stepForward(int,char,int,int,int,double*,int debug=0);
        void zeroDeltaWbs();

        NeuralNet(int,int*);
        ~NeuralNet();

    private:

};

#endif

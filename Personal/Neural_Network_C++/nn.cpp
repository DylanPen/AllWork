#include <iostream>
#include <vector>
#include <cmath>
#include <unordered_map>
#include <string>
#include "nn.h"
#include "sigmoid.h"

using namespace std;


void NeuralNet::printValues(){
    for(int i=0;i<this->layer_params[this->num_layers-1];i++){
        cout << this->layers[this->num_layers-1][i].value << endl;
    }
}

void NeuralNet::printTestNetwork(){
    //Print the first line
    printf("                          b=%.2f                b=%.2f \n",this->layers[1][0].bias,this->layers[2][0].bias);

    //2nd
    cout << "   ______                ______                ______  " << endl;

    //3rd
    printf("  /      \\           %.1f/      \\           %.1f/      \\ \n",this->layers[1][0].weights[0],this->layers[2][0].weights[0]);

    //4th
    printf(" |        |            |z=%.4f|            |z=%.4f|\n",this->layers[1][0].w_sum,this->layers[2][0].w_sum);

    //5th
    printf(" |a=%.4f| ---------- |a=%.4f| ---------- |a=%.4f|\n",this->layers[0][0].value,this->layers[1][0].value,this->layers[2][0].value);

    //6th
    printf("  \\______/           %.1f\\______/           %.1f\\______/ \n",this->layers[1][0].weights[1],this->layers[2][0].weights[1]);

    //7th
    printf("              \\     /               \\     /            \n");

    //8th
    printf("                \\ /                   \\ /              \n");

    //9th
    printf("                / \\  %.2f b=%.2f      / \\  %.2f b=%.2f \n",
        this->layers[1][1].weights[0],
        this->layers[1][1].bias,
        this->layers[2][1].weights[0],
        this->layers[2][1].bias
    );

    //10th
    printf("   ______     /     \\    ______     /     \\    ______  \n");

    //11th
    printf("  /      \\              /      \\              /      \\ \n");

    //12th
    printf(" |        |         %.1f|z=%.4f|         %.1f|z=%.4f|\n",
        this->layers[1][1].weights[1],
        this->layers[1][1].w_sum,
        this->layers[2][1].weights[1],
        this->layers[2][1].w_sum
    );

    //13th
    printf(" |a=%.4f| ---------- |a=%.4f| ---------- |a=%.4f|\n",
        this->layers[0][1].value,
        this->layers[1][1].value,
        this->layers[2][1].value
    );

    //14th
    printf("  \\______/              \\______/              \\______/ \n\n");
}

void NeuralNet::printDeltaWbs(){
    int node_index=0;
    for(int i=0;i<this->num_layers-1;i++){
        node_index=0;
        int mod_num=this->layer_params[i]+1;
        for(int j=0;j<delta_params[i];j++){
            if(j%mod_num==0){
                printf("b(%d)%d = %.8f\n",i+1,node_index,this->delta_wbs[i][j]);
            }else{
                printf("w(%d)%d%d = %.8f\n",i+1,node_index,(j%mod_num)-1,this->delta_wbs[i][j]);
            }

            if(j%mod_num==this->layer_params[i]){
                node_index++;
            }
        }
        printf("\n");
    }
}

void NeuralNet::zeroDeltaWbs(){
    for(int i=0;i<this->num_layers-2;i++){
        for(int j=0;j<this->delta_params[i];j++){
            this->delta_wbs[i][j]=0;
        }
    }
}

void NeuralNet::trainIter(int i_length, double *inputs, int o_length, double *outputs){
    forwardProp(i_length, inputs);

    backwardProp(o_length, outputs);
    this->training_iters++;
}

void NeuralNet::backwardProp(int length, double *outputs){
    unordered_map<string,int> hash_map;
    int node_index=0;
    for(int i=0;i<this->num_layers-1;i++){
        node_index=0;
        int mod_num=this->layer_params[i]+1; //3 for the 2x3 exmaple
        for(int j=0;j<this->delta_params[i];j++){
            if(j%mod_num!=0){ //Calculate a weight
                this->delta_wbs[i][j]=stepForward(i+1,'w',node_index,(j%mod_num)-1,length,outputs);
            }else{
                this->delta_wbs[i][j]=stepForward(i+1,'b',node_index,0,length,outputs);
            }

            if(j%mod_num==mod_num-1){ //When we are on our last weight for a node, increment the node
                //cout << "incrementing node to " << node_index+1 << endl;
                node_index++;
            }
        }
    }
    // cout << "Weight 00 (L) is " << this->delta_wbs[this->num_layers-2][1] << endl;
    // cout << "Weight 10 (L-1) is " << this->delta_wbs[this->num_layers-3][1] << endl;
    hash_map.clear();
}

double NeuralNet::stepForwardM(int layer,char type,int node,int weight_index,int length,double *outputs,unordered_map<string,int> *hash_map,int debug){
    int value;
    string hash;
    //Base Case
    //If we are on an output node, calculate dCost/dA and return
    if(layer == this->num_layers-1 && type == 'a'){
        double y=outputs[node];
        if(debug==1){
            cout << "dC(" << layer << ")" << node << "/dA(" << layer << ")" << node << " = " << 2*(this->layers[layer][node].value-y) << endl;
        }
        string hash="c"+to_string(node)+"/a"+to_string(layer)+to_string(node);
        if(hash_map->contains(hash)){
            value=hash_map->at(hash);
        }else{
            value=2*(this->layers[layer][node].value-y);
        }
        return value;
    }

    switch(type){
        case 'w': //Weights always feed into z when calculating derivatives
            if(debug==1){
                cout << "dZ(" << layer << ")" << node << "/dW" << node << weight_index << " = " << *(this->layers[layer][node].prev_value_addrs[weight_index]) << endl;
            }
            // string hash="z"+to_string(layer)+to_string(node)+"/w"+to_string(layer)+to_string(weight_index);
            // if(hash_map->contains(hash)){
            //     value=hash_map[hash];
            // }else{
            //     value=*(this->layers[layer][node].prev_value_addrs[weight_index]);
            // }
            // return value*stepForward(layer, 'z', node, weight_index, length, outputs,debug);
            return *(this->layers[layer][node].prev_value_addrs[weight_index])*stepForward(layer, 'z', node, weight_index, length, outputs,debug);
        case 'b': //Biases always feed into z when calculating derivatives
            return stepForward(layer, 'z', node, 0, length, outputs);
        case 'z': //Weighted sums always feed into a when calculating derivatives
            if(debug==1){
                cout << "dA(" << layer << ")" << node << "/dZ(" << layer << ")" << node << " = " << delta_sigmoid(this->layers[layer][node].w_sum) << endl;
            }
            hash="a"+to_string(layer)+to_string(node)+"/z"+to_string(layer)+to_string(node);
            if(hash_map->contains(hash)){
                value=hash_map->at(hash);
            }else{
                value=delta_sigmoid(this->layers[layer][node].w_sum);
            }
            return value*stepForward(layer, 'a', node, weight_index, length, outputs,debug);
            //return delta_sigmoid(this->layers[layer][node].w_sum)*stepForward(layer, 'a', node, weight_index, length, outputs,debug);
        case 'a': //Node values feed into the weighted sums of the next
            double accum = 0;
            for(int i = 0; i < this->layer_params[layer+1];i++){
                if(debug==1){
                    cout << "dZ(" << layer+1 << ")" << i << "/dA(" << layer << ")" << node << " = " << this->layers[layer+1][i].weights[weight_index] << endl;
                }
                hash="a"+to_string(layer+1)+to_string(i)+"/z"+to_string(layer)+to_string(node);
                if(hash_map->contains(hash)){
                    value=hash_map->at(hash);
                }else{
                    value=this->layers[layer+1][i].weights[weight_index];
                }
                accum += value * stepForward(layer+1, 'z', i, node, length, outputs,debug);
            }
            return accum;
    }
    return 0; //Just to stop complier warnings
}

double NeuralNet::stepForward(int layer,char type,int node,int weight_index,int length,double *outputs,int debug){
    //Base Case
    //If we are on an output node, calculate dCost/dA and return
    if(layer == this->num_layers-1 && type == 'a'){
        double y=outputs[node];
        if(debug==1){
            cout << "dC(" << layer << ")" << node << "/dA(" << layer << ")" << node << " = " << 2*(this->layers[layer][node].value-y) << endl;
        }
        return 2*(this->layers[layer][node].value-y);
    }

    switch(type){
        case 'w': //Weights always feed into z when calculating derivatives
            if(debug==1){
                cout << "dZ(" << layer << ")" << node << "/dW" << node << weight_index << " = " << *(this->layers[layer][node].prev_value_addrs[weight_index]) << endl;
            }
            return *(this->layers[layer][node].prev_value_addrs[weight_index])*stepForward(layer, 'z', node, weight_index, length, outputs,debug);
        case 'b': //Biases always feed into z when calculating derivatives
            return stepForward(layer, 'z', node, 0, length, outputs);
        case 'z': //Weighted sums always feed into a when calculating derivatives
            if(debug==1){
                cout << "dA(" << layer << ")" << node << "/dZ(" << layer << ")" << node << " = " << delta_sigmoid(this->layers[layer][node].w_sum) << endl;
            }
            return delta_sigmoid(this->layers[layer][node].w_sum)*stepForward(layer, 'a', node, weight_index, length, outputs,debug);
        case 'a': //Node values feed into the weighted sums of the next
            double accum = 0;
            for(int i = 0; i < this->layer_params[layer+1];i++){
                if(debug==1){
                    cout << "dZ(" << layer+1 << ")" << i << "/dA(" << layer << ")" << node << " = " << this->layers[layer+1][i].weights[node] << endl;
                }
                accum += this->layers[layer+1][i].weights[node] * stepForward(layer+1, 'z', i, node, length, outputs,debug);
            }
            return accum;
    }
    return 0; //Just to stop complier warnings
}

void NeuralNet::forwardProp(int length, double *inputs){
    if(this->layer_params[0]!=length){
        return;
    }

    //Set values of input nodes
    for(int i=0;i<this->layer_params[0];i++){
        this->layers[0][i].value=inputs[i];
    }

    for(int i=1;i<this->num_layers;i++){
        for(int j=0;j<this->layer_params[i];j++){
            this->layers[i][j].calculateValue();
        }
    }
}

NeuralNet::NeuralNet(int num_layers, int *layer_params){
    this->num_layers=num_layers;
    this->layer_params=new int[num_layers];

    //Initialize layers
    for(int i=0;i<num_layers;i++){
        this->layer_params[i]=layer_params[i];
        vector<Node> row;
        for(int j=0;j<layer_params[i];j++){
            if(i==0){
                row.push_back(Node());
            }else{
                row.push_back(Node(layer_params[i-1]));
            }
        }
        this->layers.push_back(row);
    }

    //Create connections between nodes
    for(int i=0;i<num_layers-1;i++){
        vector<double*> addrs;

        //Get all of the addresses of the values in the previous layer
        for(int j=0;j<layer_params[i];j++){
            addrs.push_back(&(this->layers[i][j].value));
        }

        //Put them into all the nodes in the next layer
        for(int j=0;j<this->layer_params[i+1];j++){
            for(int k=0;k<this->layers[i+1][j].prev_layer_size;k++){
                this->layers[i+1][j].prev_value_addrs[k]=addrs[k];
                
            }
        }
    }

    //Initialize the array that holds the changes to weights and biases
    training_iters=0;
    delta_wbs=new double*[this->num_layers-1];
    delta_params=new int[this->num_layers-1];
    for(int i=0;i<this->num_layers-1;i++){
        delta_params[i]=(this->layer_params[i]*this->layer_params[i+1])+this->layer_params[i+1]; //(number of weights) + number of biases
        delta_wbs[i]=new double[delta_params[i]];

        //Initialize to zero
        for(int j=0;j<delta_params[i];j++){
            delta_wbs[i][j]=0;
        }
    }
}

NeuralNet::~NeuralNet(){
    delete [] this->layer_params;
    for(int i=0;i<this->num_layers-1;i++){
        delete [] this->delta_wbs[i];
    }
    delete [] delta_wbs;
    delete [] delta_params;
}
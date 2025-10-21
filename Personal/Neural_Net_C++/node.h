#ifndef NODE_H
#define NODE_H

class Node{
    public:
        double value;
        double w_sum;
        double bias;
        int prev_layer_size;
        double *weights;
        double **prev_value_addrs;

        void calculateValue();
        // double sigmoid(double);
        // double delta_sigmoid(double);

        Node();
        Node(int);
        Node(const Node&);
        ~Node();

    private:


};

#endif

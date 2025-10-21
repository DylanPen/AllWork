#include <iostream>
#include <random>
#include <time.h>
#include <fstream>
#include "nn.h"
#include <chrono>

using namespace std;
using namespace std::chrono;

struct imageList{
    unsigned char*** images;
    unsigned char* labels;
    int n_images;
    int n_rows;
    int n_cols;
};

void freeImages(struct imageList *il){
    for(int i=il->n_images-1;i>=0;i--){
        for(int j=il->n_rows-1;j>=0;j--){
            delete [] il->images[i][j];
        }
        delete [] il->images[i];
    }
    delete [] il->images;
}

int reverseInt (int i){
    unsigned char c1, c2, c3, c4;

    c1 = i & 255;
    c2 = (i >> 8) & 255;
    c3 = (i >> 16) & 255;
    c4 = (i >> 24) & 255;

    return ((int)c1 << 24) + ((int)c2 << 16) + ((int)c3 << 8) + c4;
}

int readMnist(string data_path,string label_path,struct imageList *il){
    ifstream image_file(data_path,ios::binary);
    ifstream label_file(label_path);
    if(image_file.is_open() && label_file.is_open()){
        int label_compare=0;
        int magic_number=0;
        int number_of_images=0;
        int n_rows=0;
        int n_cols=0;
        image_file.read((char*)&magic_number,sizeof(magic_number)); 
        magic_number=reverseInt(magic_number);
        label_file.read((char*)&label_compare,sizeof(label_compare));

        image_file.read((char*)&number_of_images,sizeof(number_of_images));
        number_of_images=reverseInt(number_of_images);
        label_file.read((char*)&label_compare,sizeof(label_compare));
        label_compare=reverseInt(label_compare);
        if(number_of_images!=label_compare){
            cout << "Dataset read failed: Different number of images and labels" << endl;
            cout << "Images: " << number_of_images << "\nLabels: " << label_compare << endl;
        }

        image_file.read((char*)&n_rows,sizeof(n_rows));
        n_rows=reverseInt(n_rows);
        image_file.read((char*)&n_cols,sizeof(n_cols));
        n_cols=reverseInt(n_cols);

        //Make the big fucker
        il->n_images=number_of_images;
        il->n_rows=n_rows;
        il->n_cols=n_cols;
        
        //Allocate space for all the images and labels
        unsigned char*** images=new unsigned char**[number_of_images];
        unsigned char* labels=new unsigned char[number_of_images];
        for(int i=0;i<number_of_images;i++){
            images[i]=new unsigned char*[n_rows];
            for(int j=0;j<n_rows;j++){
                images[i][j]=new unsigned char[n_cols];
            }
        }

        for(int i=0;i<number_of_images;i++){
            //TODO: Make the label data structure and read it
            unsigned char label=0;
            label_file.read((char*)&label,sizeof(label));
            labels[i]=reverseInt(label);

            for(int j=0;j<n_rows;j++){
                for(int k=0;k<n_cols;k++){
                    //Read the pixel
                    unsigned char pixel=0;
                    image_file.read((char*)&pixel,sizeof(pixel));
                    images[i][j][k]=reverseInt(pixel);
                    if(i==0 && j==0 && k==0){
                        cout << "Pixel: " << pixel << endl;
                    }
                }
            }
        }

        il->images=images;
        il->labels=labels;

        image_file.close();
        label_file.close();
    }else{
        cout << "Dataset read failed: Could not open one of the files" << endl;
        return 0;
    }
    return 1;
}

int main(){
    srand(time(NULL)); //Initialize seed for random number generation
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

    int input_size=2;
    double inputs[input_size]={0.7,0.5};
    int output_size=2;
    double outputs[output_size]={0.2,0.8};
    
    auto start = high_resolution_clock::now();

    net.trainIter(input_size,inputs,output_size,outputs);

    
    
    //net.forwardProp(input_size,inputs);
    //net.printValues();

    struct imageList il;

    if(!readMnist("dataset/emnist-mnist-train-images-idx3-ubyte","dataset/emnist-mnist-train-labels-idx1-ubyte",&il)){
        return 0;
    }
    auto stop = high_resolution_clock::now();

    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Time taken by function: " << duration.count() << " microseconds" << endl;

    cout << "First pixel: " << il.images[0][0][5] << endl;
    cout << "First label: " << il.labels[0] << endl;

    freeImages(&il);

    // net.printTestNetwork();
    // net.printDeltaWbs();
}
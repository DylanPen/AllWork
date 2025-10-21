#include <iostream>
#include <cstdlib>
using namespace std;

void populateArray(int** arr, int rows, int cols){
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            arr[i][j] = rand() % 2;

        }
    }
}

void printArray(int** arr, int rows, int cols){
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            if(arr[i][j] == 0){
                cout << "tails ";
            }
            else{
                cout << "heads ";
            }

        }
        cout << endl;
    }
}

int main(){
    int rows, columns;
    cout << "how many rows: ";
    cin >> rows;
    cout << "how many columns: ";
    cin >> columns;
    cout << endl;

    int** tDarr = new int*[rows];
    for(int i = 0; i < rows; i++){
        tDarr[i] = new int[columns];
    }

    populateArray(tDarr, rows, columns);
    printArray(tDarr, rows, columns);

    for (int j = 0; j < rows; j++){
        delete [] tDarr[j];
    }
    delete [] tDarr;

    return 0;
}
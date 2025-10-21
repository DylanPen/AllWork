#include <iostream>
#include <string>

#include "multdiv.hpp"
using std::cin;
using std::cout;
using std::endl;


multdiv_entry** create_table(int row, int col){
    multdiv_entry** arr = new multdiv_entry*[row];

    for (int i = 0; i < row; ++i) {
        arr[i] = new multdiv_entry[col];
        for (int j = 0; j < col; j++){
            arr[i][j].mult = (i + 1) * (j + 1);
            arr[i][j].div = ((double)i + 1.0) / ((double)j + 1.0);
        }
    }
    return arr;
}

void print_table(multdiv_entry** tables, int row, int col){
    cout << "Mult table: " << endl;
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            cout << tables[i][j].mult << "\t";
        }
        cout << endl;
    }
    cout << "Div table: " << endl;
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            cout << tables[i][j].div << "\t";
        }
        cout << endl;
    }

}


void delete_table(multdiv_entry** tables, int row){
    for(int i = 0; i < row; i++){
        delete [] tables[i];
    }
    delete [] tables;
    tables = nullptr;
}
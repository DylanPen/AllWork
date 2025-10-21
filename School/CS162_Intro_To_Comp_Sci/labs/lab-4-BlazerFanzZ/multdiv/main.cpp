#include <iostream>

#include "multdiv.hpp"
using std::cin;
using std::cout;
using std::endl;

int main(){
    int rows, cols;
    cout << "How many rows: ";
    cin >> rows;
    cout << "How many columns: ";
    cin >> cols;
    create_table(rows, cols);
    multdiv_entry ** mdarray = create_table(rows, cols);
    print_table(mdarray, rows, cols);
    delete_table(mdarray, rows);
    return 0;
}
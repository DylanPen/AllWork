#include <iostream>

using namespace std; 
//this will order the array from lowest to highest
void function (int x[], int n) {
    int i, temp, j = n;
    bool swapped = true;

    while (swapped == true) {
        swapped = false;
        
        for (i = 1; i < j; i++) {
            if (x[i] < x[i-1]) {
                
                //hint: what does the next three lines of code do?
                temp = x[i];
                x[i] = x[i-1];
                x[i-1] = temp;
                
                swapped = true;
            }
        }
        j--;
    }
}
 
int main () {
    int x[] = {15, 56, 12, -21, 1, 659, 3, 83, 51, 3, 135, 0};
    int size = sizeof(x) / sizeof(x[0]); //figure out the size of the array
    
    //what is the purpose of the following for loop?
    for (int i = 0; i < size; i++)
        cout << x[i] << " ";
    cout << endl;
    
    function(x, size);
    
    for (int i = 0; i < size; i++)
        cout << x[i] << " ";
    cout << endl;
    
    return 0;
}
#include <stdio.h>
/*
// Function to find the intersection of two arrays
// It returns the result array containing the common elements
*/
void intersection(int a[], int m, int b[], int n, int res[], int *res_size) {
    int i, j;
    for (i = 0; i < m; i++) {
/*
        // Note that duplicates must be 
        // consecutive in a sorted array
*/
        if (i > 0 && a[i - 1] == a[i])
            continue;
/*
        // Since we are only searching distinct
        // elements of a[] in b[] and we break as 
        // soon we find a match, we get only
        // distinct elements in result
*/
        for (j = 0; j < n; j++) {
            if (a[i] == b[j]) {
                res[(*res_size)++] = a[i];
                break;
            }
        }
    }
}

int main() {
    int a[] = {3, 5, 10, 10, 10, 15, 15, 20};
    int b[] = {5, 10, 10, 15, 30};
    int res[10];
    int res_size = 0; 

    intersection(a, 8, b, 5, res, &res_size);
    int i;
    for (i = 0; i < res_size; i++) {
        printf("%d ", res[i]);
    }

    return 0;
}


#include <stdio.h>
#include <stdlib.h>

int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int* findUnion(int a[], int n, int b[], int m, int* size) {
    int* res = (int*)malloc((m + n) * sizeof(int));
    int index = 0;
    int i;


    for (i = 0; i < n; i++) {
      

        int j;
        for (j = 0; j < index; j++) {
            if (res[j] == a[i]) 
                break;
        }
        if (j == index)
            res[index++] = a[i];
    }


    for (i = 0; i < m; i++) {
      

        int j;
        for (j = 0; j < index; j++) {
            if (res[j] == b[i]) 
                break;
        }
        if (j == index)
            res[index++] = b[i];
    }

    qsort(res, index, sizeof(int), compare);

    *size = index; 
    return res; 
}

int main() {
    int a[] = {1, 1, 2, 2, 2, 4};
    int b[] = {2, 2, 4, 4, 3};
    int n = sizeof(a) / sizeof(a[0]);
    int m = sizeof(b) / sizeof(b[0]);
    int size;

    int* result = findUnion(a, n, b, m, &size);
    int i;
    for (i = 0; i < size; i++) 
        printf("%d ", result[i]);
    
    free(result); 
    return 0;
}
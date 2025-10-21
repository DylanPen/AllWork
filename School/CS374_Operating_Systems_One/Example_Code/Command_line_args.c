#include <stdio.h>
#include <stdlib.h>

int main (int argc, char* argv[]){
    printf("%d\n", argc);
    // ./a.out hello Dylan 25 3.14
    for(int i = 0; i < argc; ++i){
        printf("%s\n", argv[i]);
    }
        printf("%ld\n", strtol(argv[3], NULL, 10) + 1);

}
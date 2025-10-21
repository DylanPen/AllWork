#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <stdio.h>
#include <string.h>

int main(){
    struct stat result = {0};
    stat("statFunctions.c", &result);
    printf("INODE Number: %ld", result.st_ino);
    printf("SNODE Size: %ld", result.st_size);
}
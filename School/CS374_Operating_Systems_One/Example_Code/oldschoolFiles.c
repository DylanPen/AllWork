#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

int main(){
    int fd = open("file.csv", O_RDONLY, 0777); //flag = O_RDONLY or 0_WRONLY

    //in practice, you use the read function in a while loop until one or more \n are read

    //Goal: read characters from the file until we see \n
    char buffer[1024] = {0};
    size_t total_bytes_read = 0;
    while(strchr(buffer, '\n') == NULL){
        ssize_t n_bytes_read = read(fd, buffer + total_bytes_read, 1023 - total_bytes_read);
        total_bytes_read += n_bytes_read;

        if(n_bytes_read == 0){
            break;
        }

    }
    //buffer[strlen()]

    //char first_line[20];
    //ssize_t n_bytes_read = read(fd, first_line, 1);
    //first_line[n_bytes_read - 1] = '\0';

    //printf("%s\n", first_line);

    close(fd);
}
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

int main(){
    int fd = open("file.csv", O_WRONLY | O_CREAT, 0764); //flag = O_RDONLY or 0_WRONLY

    const char* sentence = "Holy guacamole\n";
    size_t length_of_sentance = strlen(sentence);
    size_t total_bytes_written = 0;
    while(total_bytes_written < length_of_sentance){
        ssize_t n_bytes_written = write(fd, sentence + total_bytes_written, length_of_sentance - total_bytes_written);
        total_bytes_written += n_bytes_written;
    }
    close(fd);
}
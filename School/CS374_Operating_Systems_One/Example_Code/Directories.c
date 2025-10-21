#include <dirent.h>
#include <stdio.h>
#include <sys/stat.h>

int main(){
    //opendir
    DIR* dir = opendir("."); // . is the working directory

    struct dirent* current_entry = readdir(dir);
    while(current_entry != NULL){
        //TODO Print some info about the entry

        struct stat info = {0};
        stat(current_entry->d_name, &info);

        printf("Name: %s\n", current_entry->d_name);
        printf("Size: %ld\n", current_entry->d_ino);

        //Read the next entry
        current_entry = readdir(dir);
    }

    closedir(dir); // Must close dir when done with it
}
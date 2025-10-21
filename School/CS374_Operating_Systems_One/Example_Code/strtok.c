#include <stdio.h>
#include <string.h>

int main(){
    char my_c_string[] = "Hello,World-Dylan,25";
    char* token = strtok(my_c_string, ",-");
    printf("%s\n", token);
    token = strtok(NULL, ",-");
    printf("%s\n", token);
    token = strtok(NULL, ",-");
    printf("%s\n", token);
    token = strtok(NULL, ",-");
    printf("%s\n", token);
    token = strtok(NULL, ",-");
    if(token != NULL){
        printf("%s\n", token);
    }
    //can make a while loop of this

}
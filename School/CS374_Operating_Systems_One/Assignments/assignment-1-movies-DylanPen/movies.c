// Complete this file to write a C program that adheres to the assignment
// specification. Refer to the assignment document in Canvas for the
// requirements. Refer to the example-directory/ contents for some example
// code to get you started.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Movie{
    char* movieTitle;
    int releaseYear;
    char languages[5][20];
    double rating;
};

struct Link{
    struct Movie movie; /*value of element*/
    struct Link* next; /*pointer to next link*/
};

struct List{
    struct Link* sentinel;
};

void initList(struct List *list);
void addMovies(struct List *list, char* fileName);
int menuChoice(int* userChoice);
void moviesInYear(struct List* list, int year);
void moviesOfLanguage(struct List* list, char* language);
void highestRateByYear(struct List *list);
void mergeSort(struct Link** headRef);
struct Link* sortedMerge(struct Link* a, struct Link* b);
void split(struct Link* source, struct Link** front, struct Link** back);

int main(int argc, char* argv[]){
    struct List list;
    initList(&list);
    addMovies(&list, argv[1]);
    int userChoice;
    int trigger = 1;
    int* trigPoint = &trigger;
    while(trigger != 0){
        userChoice = menuChoice(&userChoice);
        switch (userChoice) {
            case 1:
                printf("%s", "Enter the year of the movies you want to see: ");
                char userInput[6];
                fgets(userInput, 6, stdin);
                int year = strtol(userInput, NULL, 10);
                moviesInYear(&list, year);
                break;
            case 2:
                highestRateByYear(&list);
                break;
            case 3:
                printf("%s", "Enter the language of the movies you want to see: ");
                char lang[21];
                fgets(lang, 21, stdin);
                for(int i = 0; i < 21; i++){
                    if(lang[i] == '\n'){
                        lang[i] = '\0';
                    }
                }
                moviesOfLanguage(&list, lang);
                break;
            case 4:
                struct Link* next = list.sentinel->next;
                while(next != NULL){
                    free(next->movie.movieTitle);
                    struct Link* temp = next;
                    next = next->next;
                    free(temp);
                }
                free(list.sentinel);
                *trigPoint = 0;
                break;
            default:
                printf("%s\n", "\nPlease select a valid entry\n");
                break;
        }
    }
    
    printf("%s\n", "See you again soon!");
    return 0;
}

void initList(struct List* list){
    struct Link *senitnel = (struct Link *)malloc(sizeof(struct Link));
    senitnel->next = NULL;
    list->sentinel = senitnel;
}

void addMovies(struct List *list, char* fileName){
    FILE* file = fopen(fileName, "r");
    const char* check = "Title";
    int movies_num = 0;
    while(1){
        char* line = NULL;
        size_t n = 0;
        size_t string_length = getline(&line, &n, file); 
        if(feof(file)){
            free(line);
            break;
        }
        struct Link* newLink = (struct Link*) malloc(sizeof(struct Link));

        //Tokenize using strtok
        char* token;

        token = strtok(line, ",");
        if(strcmp(token, check) == 0){
            free(line);
            free(newLink);
            continue;
        }
        newLink->movie.movieTitle = (char*)malloc(strlen(token) + 1);
        strcpy(newLink->movie.movieTitle, token);
        token = strtok(NULL, ",");
        char year[6];
        strcpy(year, token);
        token = strtok(NULL, ",");
        char languages[150];
        strcpy(languages, token);
        token = strtok(NULL, ",");
        char rating[6];
        strcpy(rating, token);



        //Create copies of the tokens of the heap, use strcpy
        //Done

        //store pointers in movie struct attributes
        newLink->movie.releaseYear = strtol(year, NULL, 10);
        //Figure out the array
        token = strtok(languages, "[;]");
        int tokenCount = 0;
        while(token != NULL && tokenCount < 10){
            strcpy(newLink->movie.languages[tokenCount++], token);
            token = strtok(NULL, "[;]");
        }
        newLink->movie.rating = strtod(rating, NULL);

        //add to linked list
        struct Link* current = list->sentinel;
        while(current->next != NULL){
            current = current->next;
        }
        current->next = newLink;
        newLink->next = NULL;
        movies_num++;

        free(line);
    }
    printf("%s%s%s%d%s\n", "\nProcessed file ", fileName, " and parsed data for ", movies_num, " movies");
    fclose(file);
}

int menuChoice(int* userChoice){
    printf("%s\n", "\n1. Show movies released in the specified year");
    printf("%s\n", "2. Show highest rated movie for each year");
    printf("%s\n", "3. Show the title and year of release of all movies in a specific language");
    printf("%s\n", "4. Exit from the program\n");
    printf("%s", "Enter a choice from 1 to 4: ");

    char userInput[3];
    fgets(userInput, 3, stdin);
    *userChoice = strtol(userInput, NULL, 10);
    return *userChoice;
}

void moviesInYear(struct List* list, int year){
    if(year > 1900 && year <= 2021){
        struct Link* current = list->sentinel;
        int count = 0;
        printf("\n");
        while(current->next != NULL){
            current = current->next;
            if (current->movie.releaseYear == year){
                printf("%s\n", current->movie.movieTitle);
                count++;
            }
        }
        if(count == 0){
            printf("%s%d%s\n", "\nNo movies in the year ", year, "\n");
            return;
        } 
        return;   
    }
    printf("\nMust choose a year from 1900 - 2021\n");
}

void moviesOfLanguage(struct List* list, char* language){
    struct Link* current = list->sentinel;
    int count = 0;
    printf("\n");
    while(current->next != NULL){
        current = current->next;
        for(int i = 0; i < 10; i++){
            if(strcmp(current->movie.languages[i], language) == 0){
                printf("%s%s%d%s%s\n", current->movie.languages[i], " - ", current->movie.releaseYear, " - ", current->movie.movieTitle);
                count++;
            }
        }
    }
    if(count == 0){
        printf("%s%s\n", "\nNo movies in the language ", language);
    }
}

void highestRateByYear(struct List *list){
    //First, need to sort the linked list by year to allow for efficient comparison of rating
    printf("\n");
    mergeSort(&list->sentinel->next);
    struct Link* current = list->sentinel;
    struct Link* bestMovie = NULL;
    int movieRatingHolder = 0;
    while(current->next != NULL){
        current = current->next;
        if(movieRatingHolder < current->movie.rating){
            movieRatingHolder = current->movie.rating;
            bestMovie = current;
        }
        if(current->next == NULL || current->next->movie.releaseYear != current->movie.releaseYear){
            printf("%d%s%s%s%.1f\n", bestMovie->movie.releaseYear, " - ", bestMovie->movie.movieTitle, " - ", bestMovie->movie.rating);
            movieRatingHolder = 0;
        }
    }
}
// I got help to remember how to use merge sort from this site: https://www.geeksforgeeks.org/c/c-program-for-merge-sort
// I used this because I wanted to learn how to use a sorting method for better O complexity rather than 
// a nested for loop.
void mergeSort(struct Link** headRef){
    struct Link* head = *headRef;
    struct Link* a;
    struct Link* b;

    if(head == NULL || head->next == NULL){
        return;
    }

    split(head, &a, &b);

    mergeSort(&a);
    mergeSort(&b);

    *headRef = sortedMerge(a, b);
}

struct Link* sortedMerge(struct Link* a, struct Link* b){
    struct Link* result = NULL;

    if(a == NULL){
        return b;
    }
    else if(b == NULL){
        return a;
    }

    if(a->movie.releaseYear <= b->movie.releaseYear){
        result = a;
        result->next = sortedMerge(a->next, b);
    }
    else{
        result = b;
        result->next = sortedMerge(a, b->next);
    }

    return result;
}

void split(struct Link* source, struct Link** frontRef, struct Link** backRef){
    struct Link* fast;
    struct Link* slow;
    slow = source;
    fast = source->next;

    while(fast != NULL){
        fast = fast->next;
        if(fast != NULL){
            slow = slow->next;
            fast = fast->next;
        }
    }
    *frontRef = source;
    *backRef = slow->next;
    slow->next = NULL;
}   
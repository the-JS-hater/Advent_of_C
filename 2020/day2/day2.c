#include <stdio.h>

#define MAX_LENGTH 50

int partOne();
int countOccurances(char, char*);


int main(){
    partOne();
    //printf("%d", partOne());
    printf("\n");
    return 0;
}


int partOne(){
    FILE *file_ptr;
    file_ptr = fopen("day1_input.txt", "r");
    char line[MAX_LENGTH];

    int validPasswords = 0;
    while (fgets(line, MAX_LENGTH, file_ptr))
    {
        int lowerBound = 0;
        int upperBound = 0;

        char c = line[0];
        int i = 1;
        while (c != "-"){
            lowerBound *= 10;
            lowerBound += atoi(c);
            c = line[i];
            i++;
        }
        i++;
        while (c != " "){
            upperBound *= 10;
            upperBound += atoi(c);
            c = line[i];
            i++;
        }

        i++;
        c = line[i];
        i += 2;

        char* charsLeft[sizeof(line) - i];
        for (i; i < sizeof(line); i++){
            charsLeft[i] = line[i];
        } 

        printf("%d \n", lowerBound);
        printf("%d \n", upperBound);
        printf(c);

        int occurances = countOccurances(c, charsLeft);

        if(occurances >= lowerBound && occurances <= upperBound){
            validPasswords++;
        }
    }
    return validPasswords;
}


int countOccurances(char c, char* arr){
    int sum = 0;
    for (int i = 0; i < sizeof(arr); i++){
        if(arr[i] == c){
            sum++;
        }
    }
    return sum;
}

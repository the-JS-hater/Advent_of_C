#include <stdio.h>

#define MAX_LENGTH 50

int partOne();

int main(){
    printf("%d", partOne());
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
        continue;   
    }

    return validPasswords;
}
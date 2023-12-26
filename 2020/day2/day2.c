#include <stdio.h>

#define MAX_LENGTH 50

int partOne();
int countOccurrences(char c, char *arr);
int partTwo();

int main(){
    printf("%d", partOne());
    printf("\n");
    printf("%d", partTwo());
    return 0;
}


int partOne(){
    FILE *file_ptr;
    file_ptr = fopen("day2_input.txt", "r");
    char line[MAX_LENGTH];

    int validPasswords = 0;
    while (fgets(line, MAX_LENGTH, file_ptr))
    {
        int lowerBound = 0;
        int upperBound = 0;
        char c;
        int i = 0;


        while (line[i] != '-') {
            lowerBound *= 10;
            lowerBound += line[i] - '0'; //ASCII value of '0' ... '9' start at 47, ex '5' - '0' is equivolent to 52 - 47
            i++;
        }
        i++; // Move past '-'

        // Read upperBound
        while (line[i] != ' ') {
            upperBound *= 10;
            upperBound += line[i] - '0';
            i++;
        }
        i += 1; // Move past ' '

        c = line[i]; // Get the character to count
        i += 3; // Move past the character and ':'

        int occurrences = countOccurrences(c, &line[i]);

        if (occurrences >= lowerBound && occurrences <= upperBound) {
            validPasswords++;
        }
    }
    return validPasswords;
}


int countOccurrences(char c, char *arr) {
    int sum = 0;
    for (int i = 0; arr[i] != '\0'; i++) {
        if (arr[i] == c) {
            sum++;
        }
    }
    return sum;
}


int partTwo(){
    FILE *file_ptr;
    file_ptr = fopen("day2_input.txt", "r");
    char line[MAX_LENGTH];

    int validPasswords = 0;
    while (fgets(line, MAX_LENGTH, file_ptr))
    {
        int firstIndex = 0;
        int secondIndex = 0;
        char c;
        int i = 0;


        while (line[i] != '-') {
            firstIndex *= 10;
            firstIndex += line[i] - '0';
            i++;
        }
        i++; // Move past '-'

        while (line[i] != ' ') {
            secondIndex *= 10;
            secondIndex += line[i] - '0';
            i++;
        }
        i += 1; // Move past ' '

        c = line[i]; // Get the character to compare
        i += 2; // Move past the character and ':'

        //XOR operator ^
        if (line[i + firstIndex] == c ^ line[i + secondIndex] == c) {
            validPasswords++;
        }
    }
    return validPasswords;
}
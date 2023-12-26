#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 100

//correct answer partOne() is 226

int partOne();

int main(){
    printf("part one: %d", partOne());
    printf("\n");
    printf("part two: %d", 1);
    return 0;
}


int partOne(){
     FILE *file_ptr;
    file_ptr = fopen("day4_input.txt", "r");
    char line[MAX_LENGTH];

    int fieldsFound = 0;
    int validPassports = 0;
    int cidFound = 0;

    while (fgets(line, MAX_LENGTH, file_ptr)){
        if (line[0] == '\n' || line[0] == '\r' || feof(file_ptr)){
            if (fieldsFound == 8 || (fieldsFound == 7 && cidFound == 0)) {
                validPassports++;
            }
            fieldsFound = 0;
            cidFound = 0;
        }
        char *ptr = strstr(line, "cid");
        if (ptr != NULL) {
            fieldsFound++;
            cidFound = 1;
        }
        ptr = strstr(line, "byr");
        if (ptr != NULL){
            fieldsFound++;
        }
        ptr = strstr(line, "iyr");
        if (ptr != NULL){
            fieldsFound++;
        }
        ptr = strstr(line, "eyr");
        if (ptr != NULL){
            fieldsFound++;
        }
        ptr = strstr(line, "hgt");
        if (ptr != NULL){
            fieldsFound++;
        }
        ptr = strstr(line, "hcl");
        if (ptr != NULL){
            fieldsFound++;
        }
        ptr = strstr(line, "ecl");
        if (ptr != NULL){
            fieldsFound++;
        }
        ptr = strstr(line, "pid");
        if (ptr != NULL){
            fieldsFound++;
        }
    }
    if (fieldsFound == 8 || (fieldsFound == 7 && cidFound == 0)) {
        validPassports++;
    }
    return validPassports;
}












/* int partOne() {
    FILE *file_ptr;
    file_ptr = fopen("day4_input.txt", "r");
    char line[MAX_LENGTH];

    int fieldsFound = 0;
    int validPassports = 0;
    int cidFound = 0;

    while (fgets(line, MAX_LENGTH, file_ptr)) {
        if(fieldsFound == 8){
            validPassports++;
        }
        if(fieldsFound == 7 && cidFound == 0){
            validPassports++;
        }
        if (line[0] == '\n' || line[0] == '\r') {
            fieldsFound = 0;
            cidFound = 0;
            continue;
        }
        char *ptr = strstr(line, "cid");
        if (ptr != NULL) {

            cidFound = 1;
        }
        for (int i = 0; i < strlen(line); i++){
            if(line[i] == ':'){
                fieldsFound++;
            }
        }
    }
    if(fieldsFound == 8){
        validPassports++;
    }
    if(fieldsFound == 7 && cidFound == 0){
        validPassports++;
    }
    return validPassports;
} */
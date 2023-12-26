#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 50
#define ROW_LENGTH 31

int countTrees();
int partTwo();


int main(){
    printf("part one: %d", countTrees(3, 1));
    printf("\n");
    printf("%d", partTwo());
    return 0;
}


int countTrees(int right, int down){
    FILE *file_ptr;
    file_ptr = fopen("day3_input.txt", "r");
    char line[MAX_LENGTH];

    int skip_lines = down;
    int i = 0;

    int trees = 0;

    while (fgets(line, MAX_LENGTH, file_ptr)){
        if(skip_lines > 1){
            skip_lines--;
            continue;
        }

        if(line[i % (strlen(line) - 1)] == '#'){
            trees++;
        }

        skip_lines = down;
        i += right;

        if(i >= ROW_LENGTH){
            i -= ROW_LENGTH;
        }
    }

    fclose(file_ptr);
    return trees;
}


int partTwo(){
    return 1;
}
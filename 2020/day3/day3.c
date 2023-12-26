#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 50

int countTrees();
int partTwo();


int main(){
    printf("part one: %d", countTrees(3, 1));
    printf("\n");
    printf("part two: %d", partTwo());
    return 0;
}

int countTrees(int right, int down) {
    FILE *file_ptr;
    file_ptr = fopen("day3_input.txt", "r");
    char line[MAX_LENGTH];

    int i = 0;
    int trees = 0;
    int line_count = 0;

    while (fgets(line, MAX_LENGTH, file_ptr)) {
        size_t line_length = strlen(line);

        // Handle the case when the last line doesn't end with a newline
        if (line[line_length - 1] == '\n') {
            line_length--;
        }

        if (line_count % down == 0) {
            if (line[i % line_length] == '#') {
                trees++;
            }

            i += right;
        }

        line_count++;
    }

    fclose(file_ptr);
    return trees;
}


int partTwo(){
    int product = 1;

    printf("1,1 %d\n", countTrees(1, 1));
    printf("3,1 %d\n", countTrees(3, 1));
    printf("5,1 %d\n", countTrees(5, 1));
    printf("7,1 %d\n", countTrees(7, 1));
    printf("1,2 %d\n", countTrees(1, 2));
    product *= countTrees(1, 1);
    product *= countTrees(3, 1);
    product *= countTrees(5, 1);
    product *= countTrees(7, 1);
    product *= countTrees(1, 2);


    return product;
}
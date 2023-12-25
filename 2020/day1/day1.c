#include <stdio.h>
#include "C:\Users\morga\Advent_of_C\2020\myVec.h"

int partOne();
int partTwo();

int main()
{
    printf("%d", partOne());
    printf("\n");
    printf("%d", partTwo());

    return 0;
}


int partOne(){
    FILE *file_ptr;

    file_ptr = fopen("day1_input.txt", "r");

    char line[MAX_LENGTH];

    Vector* lowerHalf = newVector();
    Vector* upperHalf = newVector();
    while (fgets(line, MAX_LENGTH, file_ptr))
    {
        int current_num = atoi(line);
        if (current_num <= 1010){
            pushBack(lowerHalf, current_num);
        } else {
            pushBack(upperHalf, current_num);
        }
    }

    fclose(file_ptr);

    int stopLower = lowerHalf->size;
    int stopUpper = upperHalf->size;

    for (int i = 0; i < stopLower; i++) {
        for (int j = 0; j < stopUpper; j++) {
            int a = lowerHalf->data[i];
            int b = upperHalf->data[j];
            if (a + b == 2020) {
                freeVector(lowerHalf);
                freeVector(upperHalf);
                return("%d\n", a * b);
            }
        }
    }
}

int getThreewaySum(Vector* vec);

int partTwo(){
    FILE *file_ptr;

    file_ptr = fopen("day1_input.txt", "r");

    char line[MAX_LENGTH];

    Vector* nums = newVector();

    while (fgets(line, MAX_LENGTH, file_ptr))
    {
        int current_num = atoi(line);
        pushBack(nums, current_num);
    }

    quickSort(nums->data, 0, nums->size - 1);
    return getThreewaySum(nums);

}

int getThreewaySum(Vector* vec){
    for (int i = 0; i < vec->size - 2; ++i) {
        int target = 2020 - vec->data[i]; 
        int leftIndex = i + 1;
        int rightIndex = vec->size - 1;

        while (leftIndex < rightIndex) {
            int currentSum = vec->data[leftIndex] + vec->data[rightIndex];

            if (currentSum == target) {
                return vec->data[i] * vec->data[leftIndex] * vec->data[rightIndex];
            } else if (currentSum < target) {
                leftIndex++;
            } else {
                rightIndex--;
            }
        }
    }
}
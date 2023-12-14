#include <stdio.h>
#include <stdlib.h>

#define INITIAL_VECTOR_CAPACITY 10
#define MAX_LENGTH 10

typedef struct 
{
    int *data;
    size_t size;
    size_t capacity;
} Vector;


Vector* newVector(){
    Vector* nVector = malloc(sizeof(Vector));
    nVector -> data = (int*)malloc(sizeof(int) * INITIAL_VECTOR_CAPACITY);
    nVector -> size = 0;    
    nVector -> capacity = INITIAL_VECTOR_CAPACITY;
    return nVector;
}  


void pushBack(Vector* vec, int value){
    if (vec -> size >= vec -> capacity){
        vec -> capacity *= 2;
        vec -> data = (int*)realloc(vec->data, sizeof(int) * vec -> capacity);
    }

    vec->data[vec->size++] = value;
}


void freeVector(Vector* vec){
    free(vec -> data);
    free(vec);
}

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


void swap(int* a, int* b);
int partition(int arr[], int low, int high);
void quickSort(int arr[], int low, int high);
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


void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
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
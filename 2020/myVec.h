#include <stdlib.h>

#define INITIAL_VECTOR_CAPACITY 10

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
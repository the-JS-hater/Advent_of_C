#include <stdlib.h>

//TODO - work in progress

typedef struct {
    char* string;
    String_node* next;
} String_node;

typedef struct {
    String_node* head;
    String_node* tail = head->next;
} String_list;

void insert(String_node){
    
};
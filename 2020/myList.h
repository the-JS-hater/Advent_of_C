#include <stdlib.h>

typedef struct {
    char* string;
    String_node* next;
} String_node;

typedef struct {
    String_node* head;
    String_node* tail = head->next;
} String_list;


// Compile this assignment with: clang -g -Wall main.c -o main.out
// Use this file to implement testing for your
// doubly linked list implementation

#include <stdio.h>  // For IO operations
#include <stdlib.h> // for malloc/free

#include "my_dll.h"

// ====================================================
// ================== Program Entry ===================
// ====================================================
int main()
{
    dll_t *dll = create_dll();

    int empty = dll_empty(dll);
    printf("Is DLL empty? %s\n", empty ? "Yes" : "No");

    dll_push_front(dll, 50);
    dll_push_front(dll, 150);
    dll_push_front(dll, 200);

    int size = dll_size(dll);
    printf("DLL size: %d\n", size);

    int element = dll_get(dll, 1);
    printf("Element at position 1: %d\n", element);

    dll_insert(dll, 1, 88);

    int remove = dll_remove(dll, 2);
    printf("Removed item: %d\n", remove);

    int front = dll_pop_front(dll);
    printf("Popped item from the front: %d\n", front);

    int back = dll_pop_back(dll);
    printf("Popped item from the back: %d\n", back);

    empty = dll_empty(dll);
    printf("Is DLL empty? %s\n", empty ? "Yes" : "No");

    free_dll(dll);

    return 0;
}
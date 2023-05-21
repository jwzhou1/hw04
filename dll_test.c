// Note: This is not an exhaustive test suite, but gives you the idea
//       of some tests you might want to create.
//       Adding more tests and slowly making them more and more complicated
//       as you develop your library is recommended.
//
// Compile this assignment with: clang -g -Wall dll_test.c -o dll_test.out
//
// Run with: ./dll_test.out
#include <stdio.h>  // For IO operations
#include <stdlib.h> // for malloc/free
#include "my_dll.h"

// A sample collection of tests for your program
// We will be adding our own to test your program.

// Tests creation and deletion of list
// Ideally does not cause any segfaults, and this
// is considered passing.
// Dll should also be empty.
int unitTest1(int status)
{
    int passed = 0;
    dll_t *test = create_dll();
    if (dll_empty(test))
    {
        passed = 1;
    }
    free_dll(test);

    return passed;
}

// Tests push_front and size functions
int unitTest2(int status)
{
    int passed = 0;
    dll_t *test = create_dll();
    dll_push_front(test, 789);
    if (1 == dll_size(test))
    {
        passed = 1;
    }
    else
    {
        passed = 0;
    }
    free_dll(test);

    return passed;
}

// Tests push_back and size functions
int unitTest3(int status)
{
    int passed = 0;
    dll_t *test = create_dll();
    dll_push_back(test, 142);
    if (1 == dll_size(test))
    {
        passed = 1;
    }
    else
    {
        passed = 0;
    }
    free_dll(test);

    return passed;
}

// Tests push_front and dll_pop_back functions
int unitTest4(int status)
{
    int passed = 0;
    dll_t *test = create_dll();
    dll_push_back(test, 142);
    dll_pop_back(test);
    if (0 == dll_size(test))
    {
        passed = 1;
    }
    else
    {
        passed = 0;
    }
    free_dll(test);

    return passed;
}

// Tests push_back twice, then pops once
// then should compute the correct size.
int unitTest5(int status)
{
    int passed = 0;
    dll_t *test = create_dll();
    dll_push_back(test, 142);
    dll_push_front(test, 142);
    dll_pop_back(test);
    if (1 == dll_size(test))
    {
        passed = 1;
    }
    else
    {
        passed = 0;
    }
    free_dll(test);

    return passed;
}

// One test for 'create_dll' fucntion.
// Here we create one doubly linked list to test 'create_dll' fucntion.
int unitTest6(int status)
{
    int passed = 0;
    dll_t *dll = create_dll();
    if (dll != NULL && dll->count == 0 && dll->head == NULL && dll->tail == NULL)
    {
        passed = 1;
    }
    free(dll);
    return passed;
}

// Another test for 'create_dll' fucntion.
// Here we create five doubly linked lists to test 'create_dll' fucntion.
int unitTest7(int status)
{
    int passed = 0;
    dll_t *dll1 = create_dll();
    dll_t *dll2 = create_dll();
    dll_t *dll3 = create_dll();
    dll_t *dll4 = create_dll();
    dll_t *dll5 = create_dll();
    if (dll1 != NULL && dll1->count == 0 && dll1->head == NULL && dll1->tail == NULL &&
        dll2 != NULL && dll2->count == 0 && dll2->head == NULL && dll2->tail == NULL &&
        dll3 != NULL && dll3->count == 0 && dll3->head == NULL && dll3->tail == NULL &&
        dll4 != NULL && dll4->count == 0 && dll4->head == NULL && dll4->tail == NULL &&
        dll5 != NULL && dll5->count == 0 && dll5->head == NULL && dll5->tail == NULL)
    {
        passed = 1;
    }
    free(dll1);
    free(dll2);
    free(dll3);
    free(dll4);
    free(dll5);
    return passed;
}

// One test for 'dll_empty' fucntion.
// Here we create an empty DDL to test 'dll_empty' fucntion.
int unitTest8(int status)
{
    int passed = 0;
    dll_t *dll = create_dll();
    if (dll_empty(dll) == 1)
    {
        passed = 1;
    }
    free(dll);
    return passed;
}

// Another test for 'dll_empty' fucntion.
// Here we create an non-empty DDL with one element to test 'dll_empty' fucntion.
int unitTest9(int status)
{
    int passed = 0;
    dll_t *dll = create_dll();
    node_t *node = (node_t *)malloc(sizeof(node_t));
    node->data = 5;
    node->next = NULL;
    node->previous = NULL;
    dll->head = node;
    dll->tail = node;
    dll->count = 1;
    if (dll_empty(dll) == 0)
    {
        passed = 1;
    }
    free(dll->head);
    free(dll);
    return passed;
}

// An array of function pointers to all of the tests
// that main() can use iterate over them.
// UNCOMMENT Tests as you are ready to use them
// Add your own tests!
int (*unitTests[])(int) = {
    unitTest1,
    unitTest2,
    unitTest3,
    unitTest4,
    unitTest5,
    unitTest6,
    unitTest7,
    unitTest8,
    unitTest9};

// ====================================================
// ================== Program Entry ===================
// ====================================================
int main()
{
    unsigned int testsPassed = 0;
    // List of Unit Tests to test your data structure
    int counter = 0;
    while (unitTests[counter] != NULL)
    {
        printf("========unitTest %d========\n", counter);
        if (1 == unitTests[counter](1))
        {
            printf("passed test\n");
            testsPassed++;
        }
        else
        {
            printf("failed test, missing functionality, or incorrect test\n");
        }
        counter++;
    }

    printf("%d of %d tests passed\n", testsPassed, counter);

    return 0;
}
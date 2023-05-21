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
// Here we create a non-empty DDL with one element to test 'dll_empty' fucntion.
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

// One test for 'dll_push_front' fucntion.
// Here we create an empty DDL to test 'dll_push_front' fucntion.
int unitTest10(int status)
{
    int passed = 0;
    dll_t *dll = create_dll();
    int item = 5;
    int test = dll_push_front(dll, item);
    if (test == 1 && dll->count == 1 && dll->head != NULL && dll->head->data == item &&
        dll->head->previous == NULL && dll->head->next == NULL && dll->tail == dll->head)
    {
        passed = 1;
    }
    free(dll->head);
    free(dll);
    return passed;
}

// Another test for 'dll_push_front' fucntion.
// Here we create a non-empty DDL to test 'dll_push_front' fucntion.
int unitTest11(int status)
{
    int passed = 0;
    dll_t *dll = create_dll();
    node_t *testNode = (node_t *)malloc(sizeof(node_t));
    testNode->data = 5;
    testNode->next = NULL;
    testNode->previous = NULL;
    dll->head = testNode;
    dll->tail = testNode;
    dll->count = 1;
    int item = 10;
    int test = dll_push_front(dll, item);
    if (test == 1 && dll->count == 2 && dll->head != NULL && dll->head->data == item &&
        dll->head->previous == NULL && dll->head->next == testNode && testNode->previous == dll->head)
    {
        passed = 1;
    }
    free(dll->head);
    free(testNode);
    free(dll);
    return passed;
}

// One test for 'dll_push_back' fucntion.
// Here we create an empty DDL to test 'dll_push_back' fucntion.
int unitTest12(int status)
{
    int passed = 0;
    dll_t *dll = create_dll();
    int item = 5;
    int test = dll_push_back(dll, item);
    if (test == 1 && dll->count == 1 && dll->tail != NULL && dll->tail->data == item &&
        dll->tail->previous == NULL && dll->tail->next == NULL && dll->head == dll->tail)
    {
        passed = 1;
    }
    free(dll->tail);
    free(dll);
    return passed;
}

// Another test for 'dll_push_back' fucntion.
// Here we create a non-empty DDL to test 'dll_push_back' fucntion.
int unitTest13(int status)
{
    int passed = 0;
    dll_t *dll = create_dll();
    node_t *testNode = (node_t *)malloc(sizeof(node_t));
    testNode->data = 5;
    testNode->next = NULL;
    testNode->previous = NULL;
    dll->head = testNode;
    dll->tail = testNode;
    dll->count = 1;
    int item = 10;
    int test = dll_push_back(dll, item);
    if (test == 1 && dll->count == 2 && dll->tail != NULL && dll->tail->data == item &&
        dll->tail->previous == testNode && dll->tail->next == NULL && testNode->next == dll->tail)
    {
        passed = 1;
    }
    free(dll->tail);
    free(testNode);
    free(dll);
    return passed;
}

// One test for 'dll_pop_front' fucntion.
// Here we create a DDL with one element to test 'dll_pop_front' fucntion.
int unitTest14(int status)
{
    int passed = 0;
    dll_t *dll = create_dll();
    dll_push_front(dll, 5);
    int test = dll_pop_front(dll);
    if (test == 5 && dll->count == 0 && dll->head == NULL && dll->tail == NULL)
    {
        passed = 1;
    }
    free(dll);
    return passed;
}

// Another test for 'dll_pop_front' fucntion.
// Here we create a DDL with five elements to test 'dll_pop_front' fucntion.
int unitTest15(int status)
{
    int passed = 0;
    dll_t *dll = create_dll();
    dll_push_front(dll, 5);
    dll_push_front(dll, 10);
    dll_push_front(dll, 15);
    dll_push_front(dll, 20);
    dll_push_front(dll, 25);
    int test = dll_pop_front(dll);
    if (test == 25 && dll->count == 4 && dll->head->data == 20 && dll->head->next->data == 15 &&
        dll->head->next->next->data == 10 && dll->head->next->next->next->data == 5 &&
        dll->tail->data == 5 && dll->tail->next == NULL && dll->tail->previous->data == 10 &&
        dll->tail->previous->previous->data == 15 && dll->tail->previous->previous->previous->data == 20)
    {
        passed = 1;
    }
    free(dll->tail);
    free(dll->head);
    free(dll);
    return passed;
}

// One test for 'dll_pop_back' fucntion.
// Here we create an empty DDL to test 'dll_pop_back' fucntion.
int unitTest16(int status)
{
    int passed = 0;
    dll_t *dll = create_dll();
    int test = dll_pop_back(dll);
    if (test == 0)
    {
        passed = 1;
    }
    free(dll);
    return passed;
}

// Another test for 'dll_pop_back' fucntion.
// Here we create a non-empty DDL to test 'dll_pop_back' fucntion.
int unitTest17(int status)
{
    int passed = 0;
    dll_t *dll = create_dll();
    dll_push_front(dll, 5);
    dll_push_front(dll, 10);
    dll_push_front(dll, 15);
    dll_push_front(dll, 20);
    dll_push_front(dll, 25);
    int test = dll_pop_back(dll);
    if (test == 5 && dll->count == 4 && dll->head->data == 25 && dll->tail->data == 10)
    {
        passed = 1;
    }
    free(dll);
    return passed;
}

// One test for 'dll_insert' fucntion.
// Here we insert a new node at a valid position to test 'dll_insert' fucntion.
int unitTest18(int status)
{
    int passed = 0;
    dll_t *dll = create_dll();
    dll_push_back(dll, 5);
    dll_push_back(dll, 15);
    dll_push_back(dll, 20);
    int test = dll_insert(dll, 1, 10);
    if (test == 1 && dll->count == 4)
    {
        node_t *curr = dll->head;
        int expected[] = {5, 10, 15, 20};
        for (int i = 0; i < dll->count; i++)
        {
            if (curr->data != expected[i])
            {
                break;
            }
            curr = curr->next;
        }
        if (curr == NULL)
        {
            passed = 1;
        }
    }
    return passed;
}

// Another test for 'dll_insert' fucntion.
// Here we insert a new node at an invalid position to test 'dll_insert' fucntion.
int unitTest19(int status)
{
    int passed = 0;
    dll_t *dll = create_dll();
    dll_push_back(dll, 5);
    dll_push_back(dll, 10);
    int test = dll_insert(dll, 10, 30);
    if (test == 0 && dll->count == 2)
    {
        passed = 1;
    }
    return passed;
}

// One test for 'dll_get' fucntion.
// Here we get the item at a valid position to test 'dll_get' fucntion.
int unitTest20(int status)
{
    int passed = 0;
    dll_t *dll = create_dll();
    dll_push_back(dll, 5);
    dll_push_back(dll, 10);
    dll_push_back(dll, 15);
    int test = dll_get(dll, 1);
    if (test == 10)
    {
        passed = 1;
    }
    return passed;
}

// Another test for 'dll_get' fucntion.
// Here we fail to get the item at an invalid position to test 'dll_get' fucntion.
int unitTest21(int status)
{
    int passed = 0;
    dll_t *dll = create_dll();
    dll_push_back(dll, 5);
    dll_push_back(dll, 10);
    int test = dll_get(dll, 3);
    if (test == 0)
    {
        passed = 1;
    }
    return passed;
}

// One test for 'dll_remove' fucntion.
// Here we remove the item at a valid position to test 'dll_remove' fucntion.
int unitTest22(int status)
{
    int passed = 0;
    dll_t *dll = create_dll();
    dll_push_back(dll, 5);
    dll_push_back(dll, 10);
    dll_push_back(dll, 15);
    int test = dll_remove(dll, 1);
    if (test == 10 && dll->count == 2 && dll_get(dll, 0) == 5 && dll_get(dll, 1) == 15)
    {
        passed = 1;
    }
    return passed;
}

// Another test for 'dll_remove' fucntion.
// Here we fail to remove the item at an invalid position to test 'dll_remove' fucntion.
int unitTest23(int status)
{
    int passed = 0;
    dll_t *dll = create_dll();
    dll_push_back(dll, 5);
    dll_push_back(dll, 10);
    int test = dll_remove(dll, 3);
    if (test == 0 && dll->count == 2)
    {
        passed = 1;
    }
    return passed;
}

// One test for 'dll_size' fucntion.
// Here we create an empty DDL to test 'dll_size' fucntion.
int unitTest24(int status)
{
    int passed = 0;
    dll_t *dll = create_dll();
    int test = dll_size(dll);
    if (test == 0)
    {
        passed = 1;
    }
    return passed;
}

// Another test for 'dll_size' fucntion.
// Here we create a non-empty DDL to test 'dll_size' fucntion.
int unitTest25(int status)
{
    int passed = 0;
    dll_t *dll = create_dll();
    dll_push_back(dll, 5);
    dll_push_back(dll, 10);
    dll_push_back(dll, 15);
    dll_push_back(dll, 20);
    dll_push_back(dll, 25);
    int result = dll_size(dll);
    if (result == 5)
    {
        passed = 1;
    }
    return passed;
}

// One test for 'free_dll' fucntion.
// Here we create an empty DDL to test 'free_dll' fucntion.
int unitTest26(int status)
{
    int passed = 0;
    dll_t *dll = create_dll();
    free_dll(dll);
    if (dll != 0)
    {
        passed = 1;
    }
    return passed;
}

// Another test for 'free_dll' fucntion.
// Here we create a non-empty DDL to test 'free_dll' fucntion.
int unitTest27(int status)
{
    int passed = 0;
    dll_t *dll = create_dll();
    dll_push_back(dll, 5);
    dll_push_back(dll, 10);
    dll_push_back(dll, 15);
    dll_push_back(dll, 20);
    dll_push_back(dll, 25);
    free_dll(dll);
    if (dll != 5)
    {
        passed = 1;
    }
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
    unitTest9,
    unitTest10,
    unitTest11,
    unitTest12,
    unitTest13,
    unitTest14,
    unitTest15,
    unitTest16,
    unitTest17,
    unitTest18,
    unitTest19,
    unitTest20,
    unitTest21,
    unitTest22,
    unitTest23,
    unitTest24,
    unitTest25,
    unitTest26,
    unitTest27};

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
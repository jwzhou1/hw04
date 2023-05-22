# HW README

Name: Jiawei Zhou

Github Account name: jwzhou1

Link to Assignment on Github: (copy and paste the link to your assignment repo here)  
https://github.com/jwzhou1/hw04.git

How many hours did it take you to complete this assignment (estimate)?  
    20 hours

Did you collaborate with any other students/TAs/Professors? If so, tell us who and in what capacity.  
- one per row, add more if needed   
    No.

Did you use any external resources (you do not have to cite in class material)? (Cite them below)  
- one row per resource  
    For writing my_dll.h file, I used the following external resources:  
    https://www.tutorialspoint.com/data_structures_algorithms/doubly_linked_list_program_in_c.htm  
    https://prepinsta.com/data-structures/doubly-linked-list-in-c/  
    https://www.geeksforgeeks.org/introduction-and-insertion-in-a-doubly-linked-list/  
    https://www.scaler.com/topics/doubly-linked-list-in-c/  
    https://www.simplilearn.com/tutorials/c-tutorial/doubly-linked-list-in-c#:~:text=Doubly%20Linked%20Lists%20in%20C,both%20forward%20and%20backward%20directions.  
    For question 1:  
    https://www.geeksforgeeks.org/time-complexities-of-different-data-structures/#

(Optional) What was your favorite part of the assignment?  
    I learned to use C langauge to implement doubly linked list.

(Optional) How would you improve the assignment?  
    Maybe give more interesting tests for doubly linked list.

## Understanding Time Complexity

1. Using a markdown table and markdown/latex math, show the BigO for Arrays, Singly Linked Lists, Doubly Linked Lists (so total of 3). For the columns, you will look at the Worst Case Time Complexity for Access, Search/Find, Insertion, and Deletion.  
    | Data Structure       | Access              | Search/Find        | Insertion          | Deletion           |
    | -------------------- | ------------------- | ------------------ | ------------------ | ------------------ |
    | Arrays               | $O(1)$              | $O(n)$             | $O(n)$             | $O(n)$             |
    | Singly Linked Lists  | $O(n)$              | $O(n)$             | $O(n)$             | $O(n)$             |
    | Doubly Linked Lists  | $O(n)$              | $O(n)$             | $O(1)$             | $O(1)$             |

Here is the explanation for the above table:

* Access: Arrays take $O(1)$ time complexity since elements can be accessed by the specific index. Singly linked lists and doubly linked lists take $O(n)$ time complexity since both of them require traversing the list from the head to the specific element we want.
* Search/Find: Arrays take $O(n)$ time complexity since we have the worst case when we need to scan all elements in the array. Singly linked lists and doubly linked lists take $O(n)$ time complexity since both of them require traversing the list from the head until we find the specific element we want.
* Insertion: Arrays take $O(n)$ time complexity since we need to shift elements and change the size of the array. Singly linked lists also take $O(n)$ time complexity for insertion at any position since we need to traverse the list to find the specific location. Doubly linked lists take $O(1)$ time complexity for insertion since we do not need to traverse the list.
* Deletion: Arrays take $O(1)$ time complexity since we need to fill the gap caused by the deleted element by shifting elements. Singly linked lists take $O(n)$ time complexity for deletion at any position since we need to traverse the list to find the element to delete. Doubly linked lists take $O(1)$ time complexity for deletion since we do not need to traverse the list.


2. Usually for singly and doubly linked lists, we reference both the head and tail for speed considerations. What would be the cost if you only had your head referenced, and you wanted to push to the tail of either?  $O(?)$  

    If we only have head referenced in a singly or doubly linked list and we want to push an element to the tail, the time complexity is $O(n)$ where n is the number of elements in the list.  

    For singly linked lists, if we want to push an element to the tail when we only have the head referenced, we need to traverse the entire list to reach the tail and it will take $O(n)$ time complexity.  

    For doubly linked lists, if we only have the head referenced and want to push to the tail, we would need to traverse the entire list from the head to the tail which will take $O(n)$ time complexity.  

    Thus, the time complexity is $O(n)$ in both cases.

3. Name an example where an array is better than a linked list, and an example where a linked list is better than an array. Make sure to reference the big O as part of your reasoning.  
  
    An example where an array is better than a linked list:  
    When we want to perform random access on elements frequently, an array is better than a linked list. Arrays take $O(1)$  random access to elements by directly accessing index in the array. However, linked lists need to traverse the list from the head to reach the desired element which will take $O(n)$ time complexity for random access. Thus, an array is better than a linked list when we want to perform random access on elements frequently.

    An example where a linked list is better than an array:  
    When we want to frequently insert or delete elements in the middle of the collection, a linked list is better than an array. Insertion or deletion in the middle of an array need to change the position of the inserted/deleted elements and change the size of the array which will take $O(n)$ time complexity. However, we can perform insertion or deletion by updating pointers/references in a linked list which will take $O(1)$ time complexity. Linked list is dynamic in size where it is better for frequently inserting or deleting in the middle of the collection.


Note: Make sure look at your finished markdown in the browser hosted on github or via a markdown preview extension. To confirm the notation is showing up properly. Double check the resources section in the instructions if you need help with markdown tables. 
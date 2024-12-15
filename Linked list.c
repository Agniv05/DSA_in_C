/* #    Linked Lists addresses few of the limitations of the arrays. Example:

#    1. insertion or deletion in case of an array is expEnsive(complex position-based)
#    2. as arrays are static structures, they cannot be easily extended or reduced
#    3. fixed size
#    4. one block allocation

#    Linked list---> A LINEAR DYNAMIC DATA STRUCTURE.
#    consists of nodes
#    the nodes consist of the data and the reference(POINTERS) to the next node
#    th last node(THE FINAL ELEMENT) has a reference to null
#    the head(entry point into a linked list) is not a node but a REFERENCE TO THE FIRST NODE
#    if the list is empty, the head is a null reference
#    the size of the list can change during program execution
#    it can be made as long as necessary, until memory is depleted
#    it avoids wastage of memory space but additional memory is required for pointers
#    
#    NOTE:A null reference, also known as a null pointer, is a reference or pointer that does not point to a valid object or memory location. In other words, it is a reference that has no value or points to nothing.
#    LINKED LIST IS AN ABSTRACT DATA TYPE
#    ARRAYS--->simple and easy to use and takes constant time for accessing elements based on indices as it is random access O(1)(takes one multiplication and addition, both of which take a constant time)
#    DYNAMIC ARRAYS--->random access, variable-size list data structure that allows elements to be added or removed.
#    LINKED LIST--->takes O(n) to access the elements
#    ----COMPARATIVE STUDY----
#    Contiguous memory allocation: Dynamic arrays store elements in contiguous blocks of memory, which means that each element is stored next to the previous one in memory.
#    Fixed-size elements: Dynamic arrays typically store elements of a fixed size, which makes it easy to calculate the memory address of each element.
#    Random access: Dynamic arrays allow for random access to elements, meaning that you can access any element directly using its index.
#    Cache-friendly: Dynamic arrays are cache-friendly, meaning that the CPU can efficiently access elements in the array because they are stored in contiguous memory locations.
#    Resizing: Dynamic arrays can be resized by allocating a new block of memory and copying the elements from the old block to the new block.*/
#include <stdio.h>
#include <stdlib.h>

// Define the structure for a singly linked list node
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert at the beginning
struct Node* insertAtBeginning(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = head;
    return newNode;
}

// Function to insert at the end
struct Node* insertAtEnd(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    if (!head) return newNode;
    struct Node* current = head;
    while (current->next) current = current->next;
    current->next = newNode;
    return head;
}

// Function to delete the first node
struct Node* deleteFirstNode(struct Node* head) {
    if (!head) return NULL;
    struct Node* temp = head;
    head = head->next;
    free(temp);
    return head;
}

// Function to delete the last node
struct Node* deleteLastNode(struct Node* head) {
    if (!head || !head->next) return NULL;
    struct Node* current = head;
    while (current->next->next) current = current->next;
    free(current->next);
    current->next = NULL;
    return head;
}

// Function to print the linked list
void printList(struct Node* head) {
    struct Node* current = head;
    while (current) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

// Example usage
int main() {
    struct Node* head = NULL;
    head = insertAtBeginning(head, 10);
    head = insertAtEnd(head, 20);
    head = insertAtEnd(head, 30);
    printf("List after insertions: ");
    printList(head);

    head = deleteFirstNode(head);
    printf("List after deleting the first node: ");
    printList(head);

    head = deleteLastNode(head);
    printf("List after deleting the last node: ");
    printList(head);

    return 0;
}

#include <stdio.h>
#include <stdlib.h>

// Define the structure for a doubly linked list node
struct DNode {
    int data;
    struct DNode* prev;
    struct DNode* next;
};

// Function to create a new node
struct DNode* createDNode(int data) {
    struct DNode* newNode = (struct DNode*)malloc(sizeof(struct DNode));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Function to insert at the beginning
struct DNode* insertAtBeginning(struct DNode* head, int data) {
    struct DNode* newNode = createDNode(data);
    if (head) head->prev = newNode;
    newNode->next = head;
    return newNode;
}

// Function to insert at the end
struct DNode* insertAtEnd(struct DNode* head, int data) {
    struct DNode* newNode = createDNode(data);
    if (!head) return newNode;
    struct DNode* current = head;
    while (current->next) current = current->next;
    current->next = newNode;
    newNode->prev = current;
    return head;
}

// Function to delete the first node
struct DNode* deleteFirstNode(struct DNode* head) {
    if (!head) return NULL;
    struct DNode* temp = head;
    head = head->next;
    if (head) head->prev = NULL;
    free(temp);
    return head;
}

// Function to delete the last node
struct DNode* deleteLastNode(struct DNode* head) {
    if (!head || !head->next) return NULL;
    struct DNode* current = head;
    while (current->next) current = current->next;
    current->prev->next = NULL;
    free(current);
    return head;
}

// Function to print the doubly linked list
void printDList(struct DNode* head) {
    struct DNode* current = head;
    while (current) {
        printf("%d <-> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

// Example usage
int main() {
    struct DNode* head = NULL;
    head = insertAtBeginning(head, 10);
    head = insertAtEnd(head, 20);
    head = insertAtEnd(head, 30);
    printf("List after insertions: ");
    printDList(head);

    head = deleteFirstNode(head);
    printf("List after deleting the first node: ");
    printDList(head);

    head = deleteLastNode(head);
    printf("List after deleting the last node: ");
    printDList(head);

    return 0;
}


#include <stdio.h>
#include <stdlib.h>

// Define the structure for a circular doubly linked list node
struct CDNode {
    int data;
    struct CDNode* next;
    struct CDNode* prev;
};

// Function to create a new node
struct CDNode* createCDNode(int data) {
    struct CDNode* newNode = (struct CDNode*)malloc(sizeof(struct CDNode));
    newNode->data = data;
    newNode->next = newNode;
    newNode->prev = newNode;
    return newNode;
}

// Function to insert at the beginning
struct CDNode* insertAtBeginning(struct CDNode* head, int data) {
    struct CDNode* newNode = createCDNode(data);
    if (!head) return newNode;
    struct CDNode* tail = head->prev;
    newNode->next = head;
    newNode->prev = tail;
    head->prev = newNode;
    tail->next = newNode;
    return newNode;
}

// Function to print the circular doubly linked list
void printCDList(struct CDNode* head) {
    if (!head) {
        printf("List is empty\n");
        return;
    }
    struct CDNode* current = head;
    do {
        printf("%d <-> ", current->data);
        current = current->next;
    } while (current != head);
    printf("(back to head)\n");
}

// Example usage
int main() {
    struct CDNode* head = NULL;
    head = insertAtBeginning(head, 10);
    head = insertAtBeginning(head, 20);
    printf("Circular Doubly Linked List: ");
    printCDList(head);

    return 0;
}


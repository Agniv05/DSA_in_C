/* a hash function to map a data element (key) to an index in a hash table (array), where the corresponding value is stored.

Hashing and Hash Function
A hash function takes an input (key) and produces a fixed-size string of bytes. The output is called the hash value or hash code, which is used as an index in the hash table.

A hash table is an array of fixed size, where each index is called a bucket. Ideally, there is only one element at each bucket, but due to collisions (when two keys produce the same index), multiple elements might be stored in a bucket.

Collision Resolution Techniques
Chaining: Store multiple elements in the same bucket using a linked list.
Open Addressing: When a collision occurs, find another open bucket within the table. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 10

// Node structure for linked list in case of chaining
struct Node {
    int key;
    struct Node* next;
};

// Hash table (array of linked list heads)
struct Node* hashTable[TABLE_SIZE];

// Hash function to calculate index
int hashFunction(int key) {
    return key % TABLE_SIZE;
}

// Insert a key into the hash table
void insert(int key) {
    int index = hashFunction(key);
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->key = key;
    newNode->next = hashTable[index];
    hashTable[index] = newNode;
}

// Search for a key in the hash table
int search(int key) {
    int index = hashFunction(key);
    struct Node* temp = hashTable[index];
    while (temp != NULL) {
        if (temp->key == key)
            return index;  // Return the index if key is found
        temp = temp->next;
    }
    return -1;  // Key not found
}

// Delete a key from the hash table
void delete(int key) {
    int index = hashFunction(key);
    struct Node* temp = hashTable[index];
    struct Node* prev = NULL;
    
    // Traverse the linked list to find the key
    while (temp != NULL) {
        if (temp->key == key) {
            if (prev == NULL) {
                // Remove the first node in the list
                hashTable[index] = temp->next;
            } else {
                // Remove the node from the middle or end of the list
                prev->next = temp->next;
            }
            free(temp);
            return;
        }
        prev = temp;
        temp = temp->next;
    }
}

// Display the hash table
void display() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        struct Node* temp = hashTable[i];
        printf("Bucket %d: ", i);
        while (temp != NULL) {
            printf("%d -> ", temp->key);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

int main() {
    // Initialize hash table
    for (int i = 0; i < TABLE_SIZE; i++) {
        hashTable[i] = NULL;
    }
    
    // Insert some keys
    insert(12);
    insert(22);
    insert(32);
    insert(42);
    
    // Display the hash table
    display();
    
    // Search for a key
    int key = 22;
    int result = search(key);
    if (result != -1)
        printf("Key %d found at index %d\n", key, result);
    else
        printf("Key %d not found\n", key);
    
    // Delete a key
    delete(22);
    printf("After deletion:\n");
    display();
    
    return 0;
}

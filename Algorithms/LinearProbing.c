#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 10

int hashTable[TABLE_SIZE];

// Hash function to calculate index
int hashFunction(int key) {
    return key % TABLE_SIZE;
}

// Linear probing to insert a key
void insert(int key) {
    int index = hashFunction(key);
    
    // If collision occurs, find the next available index
    while (hashTable[index] != -1) {
        index = (index + 1) % TABLE_SIZE;
    }
    
    hashTable[index] = key;
}

// Search for a key
int search(int key) {
    int index = hashFunction(key);
    
    while (hashTable[index] != -1) {
        if (hashTable[index] == key) {
            return index;  // Key found
        }
        index = (index + 1) % TABLE_SIZE;
    }
    
    return -1;  // Key not found
}

// Display the hash table
void display() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (hashTable[i] != -1)
            printf("Index %d: %d\n", i, hashTable[i]);
    }
}

int main() {
    // Initialize hash table with -1 to indicate empty slots
    for (int i = 0; i < TABLE_SIZE; i++) {
        hashTable[i] = -1;
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
    
    return 0;
}

/* In open addressing, if a collision occurs, the algorithm checks the next available slot in the hash table. Linear probing is one such technique where the probe sequence is linear.  */

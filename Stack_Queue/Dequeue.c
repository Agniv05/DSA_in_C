#include <stdio.h>
#include <stdlib.h>

#define MAX 5

struct Deque {
    int arr[MAX];
    int front, rear;
};

// Function to initialize the deque
void initDeque(struct Deque* deque) {
    deque->front = -1;
    deque->rear = -1;
}

// Function to check if the deque is full
int isFull(struct Deque* deque) {
    return (deque->front == 0 && deque->rear == MAX - 1) || (deque->front == deque->rear + 1);
}

// Function to check if the deque is empty
int isEmpty(struct Deque* deque) {
    return deque->front == -1;
}

// Function to insert at front
void insertFront(struct Deque* deque, int value) {
    if (isFull(deque)) {
        printf("Deque Overflow\n");
    } else {
        if (deque->front == -1) {
            deque->front = deque->rear = 0;
        } else if (deque->front == 0) {
            deque->front = MAX - 1;
        } else {
            deque->front--;
        }
        deque->arr[deque->front] = value;
    }
}

// Function to insert at rear
void insertRear(struct Deque* deque, int value) {
    if (isFull(deque)) {
        printf("Deque Overflow\n");
    } else {
        if (deque->rear == -1) {
            deque->front = deque->rear = 0;
        } else if (deque->rear == MAX - 1) {
            deque->rear = 0;
        } else {
            deque->rear++;
        }
        deque->arr[deque->rear] = value;
    }
}

int main() {
    struct Deque deque;
    initDeque(&deque);

    insertFront(&deque, 10);
    insertRear(&deque, 20);
    insertFront(&deque, 30);
    insertRear(&deque, 40);

    return 0;
}

/* We maintain both the front and rear pointers.
Elements can be added or removed from either end, making it a double-ended queue (Deque). */

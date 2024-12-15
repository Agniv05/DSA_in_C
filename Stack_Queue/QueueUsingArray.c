#include <stdio.h>
#include <stdlib.h>

#define MAX 5

struct Queue {
    int arr[MAX];
    int front, rear;
};

// Function to initialize the queue
void initQueue(struct Queue* queue) {
    queue->front = -1;
    queue->rear = -1;
}

// Function to check if the queue is full
int isFull(struct Queue* queue) {
    return queue->rear == MAX - 1;
}

// Function to check if the queue is empty
int isEmpty(struct Queue* queue) {
    return queue->front == -1 || queue->front > queue->rear;
}

// Function to enqueue an element
void enqueue(struct Queue* queue, int value) {
    if (isFull(queue)) {
        printf("Queue Overflow\n");
    } else {
        if (queue->front == -1) {
            queue->front = 0;  // If the queue is empty, set front to 0
        }
        queue->arr[++queue->rear] = value;
        printf("%d enqueued\n", value);
    }
}

// Function to dequeue an element
int dequeue(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue Underflow\n");
        return -1;  // Error condition
    } else {
        return queue->arr[queue->front++];  // Return the front element and increment front
    }
}

int main() {
    struct Queue queue;
    initQueue(&queue);

    enqueue(&queue, 10);
    enqueue(&queue, 20);
    enqueue(&queue, 30);

    printf("%d dequeued\n", dequeue(&queue));
    printf("%d dequeued\n", dequeue(&queue));

    return 0;
}
/*front points to the first element in the queue.
rear points to the last element in the queue.
Enqueue operation inserts elements at the rear and increments the rear pointer.
Dequeue operation removes the element at the front and increments the front pointer.*/

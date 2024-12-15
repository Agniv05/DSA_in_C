#include <stdio.h>
#include <stdlib.h>

#define MAX 5

struct Queue {
    int arr[MAX];
    int front, rear;
};

// Function to initialize the circular queue
void initQueue(struct Queue* queue) {
    queue->front = -1;
    queue->rear = -1;
}

// Function to check if the queue is full
int isFull(struct Queue* queue) {
    return (queue->rear + 1) % MAX == queue->front;
}

// Function to check if the queue is empty
int isEmpty(struct Queue* queue) {
    return queue->front == -1;
}

// Function to enqueue an element in the circular queue
void enqueue(struct Queue* queue, int value) {
    if (isFull(queue)) {
        printf("Queue Overflow\n");
    } else {
        if (queue->front == -1) {
            queue->front = 0;  // First element to enqueue
        }
        queue->rear = (queue->rear + 1) % MAX;  // Circular increment
        queue->arr[queue->rear] = value;
        printf("%d enqueued\n", value);
    }
}

// Function to dequeue an element from the circular queue
int dequeue(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue Underflow\n");
        return -1;
    } else {
        int value = queue->arr[queue->front];
        if (queue->front == queue->rear) {
            queue->front = queue->rear = -1;  // Queue becomes empty
        } else {
            queue->front = (queue->front + 1) % MAX;  // Circular increment
        }
        return value;
    }
}

int main() {
    struct Queue queue;
    initQueue(&queue);

    enqueue(&queue, 10);
    enqueue(&queue, 20);
    enqueue(&queue, 30);
    enqueue(&queue, 40);

    printf("%d dequeued\n", dequeue(&queue));
    printf("%d dequeued\n", dequeue(&queue));

    enqueue(&queue, 50);
    enqueue(&queue, 60);

    return 0;
}
/* In circular queues, the front and rear pointers wrap around when they reach the end of the array.
Enqueue and Dequeue operations are modified to use modulo arithmetic (% MAX) to handle the wrapping. */

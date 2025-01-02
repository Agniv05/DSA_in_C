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
    queue->rear = -1;   //initializes both at -1
}

// Function to check if the queue is full
int isFull(struct Queue* queue) {
    if (queue->front==queue->size-1){
        return 1;
    }
    else{
        return 0;
    }
}

// Function to check if the queue is empty
int isEmpty(struct Queue* queue) {
    if (queue->rear==queue->rear){
        return 1;
    }
    else{
        return 0;
    }
}

// Function to enqueue an element
void enqueue(struct Queue* queue, int value) {
    if (isFull(queue)) {
        printf("Queue Overflow\n");
    } else {
        if (queue->front == -1) {
            queue->front = 0;  // If the queue is empty, set front to 0
        }
        queue->rear++;  //updates rear pointer 
        queue->arr[queue->rear]=value;  //inserts value
        printf("%d enqueued\n", value);
    }
}

// Function to dequeue an element
int dequeue(struct Queue* queue) {
    int a=-1;
    if isFull(queue){
        printf ("Queue is empty");
    }
    else{
        queue->front++;
        a= queue->arr[queue->front];
    }
    return a;
}

int main() {
    struct Queue queue;
    queue.arr=(int*)malloc(queue.size*sizeof(int));
    queue.size=100;
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

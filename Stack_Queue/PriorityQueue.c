#include <stdio.h>
#include <stdlib.h>

struct PriorityQueue {
    int arr[5];
    int size;
};

// Function to initialize the priority queue
void initPriorityQueue(struct PriorityQueue* pq) {
    pq->size = 0;
}

// Function to insert an element with priority
void insert(struct PriorityQueue* pq, int value) {
    if (pq->size == 5) {
        printf("Queue Overflow\n");
    } else {
        int i = pq->size++;
        while (i > 0 && pq->arr[i - 1] < value) {
            pq->arr[i] = pq->arr[i - 1];
            i--;
        }
        pq->arr[i] = value;
    }
}

// Function to remove the element with highest priority
int removeHighestPriority(struct PriorityQueue* pq) {
    if (pq->size == 0) {
        printf("Queue Underflow\n");
        return -1;
    }
    return pq->arr[--pq->size];
}

int main() {
    struct PriorityQueue pq;
    initPriorityQueue(&pq);

    insert(&pq, 30);
    insert(&pq, 20);
    insert(&pq, 40);
    insert(&pq, 10);

    printf("Removed element with highest priority: %d\n", removeHighestPriority(&pq));
    printf("Removed element with highest priority: %d\n", removeHighestPriority(&pq));

    return 0;
}

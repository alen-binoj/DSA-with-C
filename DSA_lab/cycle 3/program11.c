#include <stdio.h>
#define MAX 100

int arr[MAX];
int front = 0, rear = -1;

// Check if queue is empty
int isEmpty() {
    return front > rear;
}

// Check if queue is full
int isFull() {
    return rear == MAX - 1;
}

// Enqueue
void enqueue(int val) {
    if (isFull()) {
        printf("Queue Overflow\n");
        return;
    }
    arr[++rear] = val;
}

// Dequeue
int dequeue() {
    if (isEmpty()) {
        printf("Queue Underflow\n");
        return -1;
    }
    return arr[front++];
}

// Find maximum element
int findMax() {
    if (isEmpty()) {
        printf("Queue is empty\n");
        return -1;
    }
    int max = arr[front];
    for (int i = front; i <= rear; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

int main() {
    enqueue(10);
    enqueue(25);
    enqueue(5);
    enqueue(40);
    enqueue(30);

    printf("Maximum element in queue = %d\n", findMax());

    return 0;
}

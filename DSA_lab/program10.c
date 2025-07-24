#include <stdio.h>

#define SIZE 100

int queue[SIZE];
int front = -1, rear = -1;
int stack[SIZE];
int top = -1;


void enqueue(int value) {
    if (rear == SIZE - 1) {
        printf("Queue overflow\n");
        return;
    }
    if (front == -1)
        front = 0;
    queue[++rear] = value;
}


int dequeue() {
    if (front == -1 || front > rear) {
        printf("Queue underflow\n");
        return -1;
    }
    return queue[front++];
}


void push(int value) {
    if (top == SIZE - 1) {
        printf("Stack overflow\n");
        return;
    }
    stack[++top] = value;
}


int pop() {
    if (top == -1) {
        printf("Stack underflow\n");
        return -1;
    }
    return stack[top--];
}


void displayQueue() {
    if (front == -1 || front > rear) {
        printf("Queue is empty\n");
        return;
    }
    for (int i = front; i <= rear; i++)
        printf("%d ", queue[i]);
    printf("\n");
}


void reverseQueue() {
    
    while (front != -1 && front <= rear) {
        push(dequeue());
    }

   
    front = 0;
    rear = -1;

    
    while (top != -1) {
        enqueue(pop());
    }
}


int main() {
    
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);

    printf("Original Queue: ");
    displayQueue();

    reverseQueue();

    printf("Reversed Queue: ");
    displayQueue();

    return 0;
}

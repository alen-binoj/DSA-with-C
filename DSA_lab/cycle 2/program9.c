#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Stack structure
typedef struct {
    int arr[MAX];
    int top;
} Stack;

// Initialize stack
void init(Stack *s) {
    s->top = -1;
}

// Check if stack is empty
int isEmpty(Stack *s) {
    return s->top == -1;
}

// Check if stack is full
int isFull(Stack *s) {
    return s->top == MAX - 1;
}

// Push element to stack
void push(Stack *s, int val) {
    if (isFull(s)) {
        printf("Stack Overflow\n");
        return;
    }
    s->arr[++s->top] = val;
}

// Pop element from stack
int pop(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack Underflow\n");
        return -1;
    }
    return s->arr[s->top--];
}

// Peek top element
int peek(Stack *s) {
    if (isEmpty(s)) return -1;
    return s->arr[s->top];
}

// Function to sort a stack using another stack
void sortStack(Stack *s) {
    Stack temp;
    init(&temp);

    while (!isEmpty(s)) {
        int curr = pop(s);

        // Move elements from temp back to s if they are greater than curr
        while (!isEmpty(&temp) && peek(&temp) > curr) {
            push(s, pop(&temp));
        }

        push(&temp, curr);
    }

    // Copy sorted elements back to original stack
    while (!isEmpty(&temp)) {
        push(s, pop(&temp));
    }
}

// Display stack elements
void display(Stack *s) {
    for (int i = s->top; i >= 0; i--) {
        printf("%d ", s->arr[i]);
    }
    printf("\n");
}

int main() {
    Stack s;
    init(&s);

    int n, val;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        push(&s, val);
    }

    printf("Original Stack: ");
    display(&s);

    sortStack(&s);

    printf("Sorted Stack (top to bottom): ");
    display(&s);

    return 0;
}

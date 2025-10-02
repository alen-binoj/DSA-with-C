#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct node *head = NULL;

void insertEnd(int e) {
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = e;
    if (head == NULL) {
        head = newnode;
        newnode->next = head;
    } else {
        struct node *temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = newnode;
        newnode->next = head;
    }
}

void insertBeg(int e) {
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = e;
    if (head == NULL) {
        head = newnode;
        newnode->next = head;
    } else {
        struct node *temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        newnode->next = head;
        head = newnode;
        temp->next = head;
    }
}

void deleteNode(int value) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct node *temp = head, *prev = NULL;
    if (head->data == value) {
        if (head->next == head) {
            free(head);
            head = NULL;
        } else {
            while (temp->next != head)
                temp = temp->next;
            struct node *del = head;
            temp->next = head->next;
            head = head->next;
            free(del);
        }
        return;
    }
    prev = head;
    temp = head->next;
    while (temp != head && temp->data != value) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == head) {
        printf("Value not found\n");
        return;
    }
    prev->next = temp->next;
    free(temp);
}

void display() {
    if (head == NULL) {
        printf("Linked list empty\n");
        return;
    }

    struct node *temp = head;
    printf("head-->");

    do {
        printf("%d-->", temp->data);
        temp = temp->next;
    } while (temp != head);

    printf("head\n");
}


int main() {
    int choice, value;
    while (1) {
        printf("\n--- Circular Linked List Menu ---\n");
        printf("1. Insert at end\n");
        printf("2. Insert at beginning\n");
        printf("3. Delete node\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                insertEnd(value);
                break;
            case 2:
                printf("Enter value: ");
                scanf("%d", &value);
                insertBeg(value);
                break;
            case 3:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                deleteNode(value);
                break;
            case 4:
                display();
                break;
            case 5:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}


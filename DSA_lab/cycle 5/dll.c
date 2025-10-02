#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
    struct node *prev;
};

struct node *head = NULL;

void insertbeg(int e) {
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = e;
    newnode->next = head;
    newnode->prev = NULL;
    if (head != NULL)
        head->prev = newnode;
    head = newnode;
}

void insertend(int e) {
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = e;
    newnode->next = NULL;
    newnode->prev = NULL;
    if (head == NULL) {
        head = newnode;
    } else {
        struct node *temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newnode;
        newnode->prev = temp;
    }
}

void insertpos(int e, int pos) {
    if (pos == 1) {
        insertbeg(e);
        return;
    }
    struct node *temp = head;
    for (int i = 1; i < pos - 1; i++) {
        if (temp == NULL) {
            printf("Invalid position\n");
            return;
        }
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Invalid position\n");
        return;
    }
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = e;
    struct node *nextNode = temp->next;
    newnode->next = nextNode;
    newnode->prev = temp;
    temp->next = newnode;
    if (nextNode != NULL)
        nextNode->prev = newnode;
}

void deleteAtBeginning() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct node *temp = head;
    head = head->next;
    if (head != NULL)
        head->prev = NULL;
    printf("Deleted %d from beginning\n", temp->data);
    free(temp);
}

void deleteAtEnd() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct node *temp = head;
    if (temp->next == NULL) {
        printf("Deleted %d from end\n", temp->data);
        free(temp);
        head = NULL;
        return;
    }
    while (temp->next != NULL)
        temp = temp->next;
    temp->prev->next = NULL;
    printf("Deleted %d from end\n", temp->data);
    free(temp);
}

void deleteAtPosition(int position) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    if (position == 1) {
        deleteAtBeginning();
        return;
    }
    struct node *temp = head;
    for (int i = 1; i < position && temp != NULL; i++) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Position out of bounds\n");
        return;
    }
    if (temp->next != NULL)
        temp->next->prev = temp->prev;
    if (temp->prev != NULL)
        temp->prev->next = temp->next;
    printf("Deleted %d from position %d\n", temp->data, position);
    free(temp);
}


void traverseForward() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct node *temp = head;
    printf("head-->");
    while (temp != NULL) {
        printf("%d-->", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}




    void traverseBackward() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct node *temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    printf("NULL<--");
    while (temp != NULL) {
        printf("%d<--", temp->data);
        temp = temp->prev;
    }
    printf("head\n");
}



int main() {
    int choice, value, position;
    while (1) {
        printf("\n--- Doubly Linked List Operations ---\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert at Position\n");
        printf("4. Delete at Beginning\n");
        printf("5. Delete at End\n");
        printf("6. Delete at Position\n");
        printf("7. Traverse Forward\n");
        printf("8. Traverse Backward\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insertbeg(value);
                break;
            case 2:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insertend(value);
                break;
            case 3:
                printf("Enter value and position to insert: ");
                scanf("%d%d", &value, &position);
                insertpos(value, position);
                break;
            case 4:
                deleteAtBeginning();
                break;
            case 5:
                deleteAtEnd();
                break;
            case 6:
                printf("Enter position to delete: ");
                scanf("%d", &position);
                deleteAtPosition(position);
                break;
            case 7:
                traverseForward();
                break;
            case 8:
                traverseBackward();
                break;
            case 9:
                printf("Exiting program\n");
                exit(0);
            default:
                printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}


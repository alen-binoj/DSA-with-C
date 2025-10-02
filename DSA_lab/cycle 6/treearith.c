#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

// =================== Char Stack for Infix to Postfix ===================
char charStack[MAX];
int charTop = -1;

void pushChar(char c) {
    charStack[++charTop] = c;
}

char popChar() {
    if (charTop == -1) return '\0';
    return charStack[charTop--];
}

char peekChar() {
    if (charTop == -1) return '\0';
    return charStack[charTop];
}

int precedence(char c) {
    if (c == '^') return 3;
    else if (c == '*' || c == '/') return 2;
    else if (c == '+' || c == '-') return 1;
    else return 0;
}

void infixToPostfix(char* infix, char* postfix) {
    int i, j = 0;
    char c;

    for (i = 0; infix[i] != '\0'; i++) {
        c = infix[i];
        if (isspace(c)) continue;

        if (isalnum(c)) {
            postfix[j++] = c;
        } else if (c == '(') {
            pushChar(c);
        } else if (c == ')') {
            while (charTop != -1 && peekChar() != '(') {
                postfix[j++] = popChar();
            }
            popChar(); 
        } else {
            while (charTop != -1 && precedence(peekChar()) >= precedence(c)) {
                postfix[j++] = popChar();
            }
            pushChar(c);
        }
    }

    while (charTop != -1) {
        postfix[j++] = popChar();
    }

    postfix[j] = '\0';
}

//Expression Tree 
typedef struct Node {
    char data;
    struct Node* left;
    struct Node* right;
} Node;

// Linked list stack node for Node*
typedef struct StackNode {
    Node* treeNode;
    struct StackNode* next;
} StackNode;

StackNode* top = NULL;

// Push Node* onto the stack
void pushNode(Node* node) {
    StackNode* temp = (StackNode*)malloc(sizeof(StackNode));
    temp->treeNode = node;
    temp->next = top;
    top = temp;
}

// Pop Node* from the stack
Node* popNode() {
    if (top == NULL) return NULL;
    StackNode* temp = top;
    Node* result = top->treeNode;
    top = top->next;
    free(temp);
    return result;
}

Node* createNode(char val) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = val;
    node->left = node->right = NULL;
    return node;
}

Node* buildExpressionTree(char* postfix) {
    int i = 0;
    char c;

    while ((c = postfix[i++]) != '\0') {
        if (isalnum(c)) {
            Node* operand = createNode(c);
            pushNode(operand);
        } else {
            Node* operator = createNode(c);
            operator->right = popNode();
            operator->left = popNode();
            pushNode(operator);
        }
    }

    return popNode(); // Final root node
}

// =================== Tree Traversals ===================
void printPrefix(Node* root) {
    if (root) {
        printf("%c", root->data);
        printPrefix(root->left);
        printPrefix(root->right);
    }
}

void printPostfix(Node* root) {
    if (root) {
        printPostfix(root->left);
        printPostfix(root->right);
        printf("%c", root->data);
    }
}

// =================== Main ===================
int main() {
    char infix[MAX], postfix[MAX];

    printf("Enter infix expression: ");
    fgets(infix, MAX, stdin);
    infix[strcspn(infix, "\n")] = '\0'; // remove newline

    infixToPostfix(infix, postfix);
    printf("Postfix Expression: %s\n", postfix);

    Node* root = buildExpressionTree(postfix);

    printf("Prefix Expression: ");
    printPrefix(root);
    printf("\n");

    printf("Postfix from Tree: ");
    printPostfix(root);
    printf("\n");

    return 0;
}


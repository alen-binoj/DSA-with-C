#include <stdio.h>
#include <ctype.h>  
#include <stdlib.h> 

#define MAX 100

int stack[MAX];
int top = -1;


void push(int value) {
    stack[++top] = value;
}


int pop() {
    return stack[top--];
}


int evaluatePostfix(char postfix[]) {
    int i;
    char ch;
    int val;
    
    for (i = 0; postfix[i] != '\0'; i++) {
        ch = postfix[i];
        
        if (isdigit(ch)) {
            
            push(ch - '0');  
        }
        else if (ch == ' ') {
            
            continue;
        }
        else {
            
            int val2 = pop();
            int val1 = pop();
            
            switch (ch) {
                case '+':
                    push(val1 + val2);
                    break;
                case '-':
                    push(val1 - val2);
                    break;
                case '*':
                    push(val1 * val2);
                    break;
                case '/':
                    push(val1 / val2);
                    break;
                case '^':
                    {
                        int result = 1;
                        for (int i = 0; i < val2; i++)
                            result *= val1;
                        push(result);
                        break;
                    }
            }
        }
    }
    
    return pop();
}

int main() {
    char postfix[MAX];
    
    printf("Enter a Postfix Expression : ");
    scanf("%s", postfix);
    
    int result = evaluatePostfix(postfix);
    
    printf("Result of Postfix Evaluation: %d\n", result);
    
    return 0;
}

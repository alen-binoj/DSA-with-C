#include <stdio.h>
#define MAX 10
int top=-1;
void push(char arr[],char e){
	if (top==MAX-1){
		printf("stack overflow\n");
	}
	else{
		arr[++top]=e;
	}
}
char pop(char arr[]){
	if (top == -1){
		printf("stack underflow\n");
	}
	else{	char item;
		item=arr[top--];
		return item;
	}

}

int main(){
	printf("Enter the string:");
	char str[20];int len=0;
	fgets(str,MAX,stdin);
	for(int i=0;str[i]!='\0';i++){
		len++;
		
	}
	int flag=1;
	char arr[MAX];
	while (flag==1){
	printf("\n1.Push\n2.Pop\n3.Exit\n");
	int ch;
	printf("Enter choice:");
	scanf("%d",&ch);
	switch(ch){
	case 1: for(int i=0;i<len;i++){
		push(arr,str[i]);
		}break;
		
		
		
		
	case 2: for(int i=0;i<len;i++){
		printf("%c",pop(arr));
		}
		break;
	case 3: flag=0;	
		break;
	default: printf("Invalid choice");
		 break;

		}	
}}





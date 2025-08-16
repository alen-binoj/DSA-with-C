#include <stdio.h>
#define MAX 10
int top=-1;
int isfull(int arr[]){
	if (top == MAX-1){
		return 1;
	}else{
		return 0;
	}
}
int isempty(int arr[]){
	if (top==-1){
		return 1;
	
	}else{
		return 0;
	}
}
void push(int arr[],int e){
	if (isfull(arr)){
		printf("Stack is overflow\n");
	}
	else{
		arr[++top]=e;
		
	}
}
int pop(int arr[]){
	if (isempty(arr)){
		printf("Stack is underflow\n");
	}
	else{
		int item=arr[top--];
		return item;		
	}
}
int main(){
	int flag=1;
	int arr[MAX];
	while (flag==1){
	printf("\n1.Push\n2.Pop\n3.Exit\n");
	int ch;
	printf("Enter choice:");
	scanf("%d",&ch);
	switch(ch){
	case 1: int e;
		printf("Enter element to be entered:");
		scanf("%d",&e);
		push(arr,e);
		break;
		
	case 2: printf("%d",pop(arr));
		break;
	case 3: flag=0;	
		break;
	default: printf("Invalid choice");
		 break;

		}	
}}

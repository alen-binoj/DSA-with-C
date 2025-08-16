#include <stdio.h>
#define MAX 10
int top=-1;
void push(int arr[],int e){
	
	if (top==MAX-1){
		printf("Stack overflow\n");
	}
	else{
		arr[++top]=e;
			
	}

}
void pop(int arr[]){
	
	if (top==-1){
		printf("Stack Underflow\n");
	}
	else{	int item;
		item=arr[top--];
		printf("popped item is = %d",item);
	}
}
void peek(int arr[]){
	if (top==-1){
		printf("Stack underflow\n");
	}
	else{
		printf("The top element is:%d",arr[top]);
	}
}
int main(){
	int flag=1;
	int arr[MAX];
	while (flag==1){
	printf("\n1.Push\n2.Pop\n3.Peek\n4.Exit\n");
	int ch;
	printf("Enter choice:");
	scanf("%d",&ch);
	switch(ch){
	case 1: int e;
		printf("Enter element to be entered:");
		scanf("%d",&e);
		push(arr,e);
		break;
		
	case 2: pop(arr);
		break;
	case 3: peek(arr);
		break;
	case 4: flag=0;	
		break;	
		
		}	
}}

#include <stdio.h>
#include <stdlib.h>
struct node{
	int data;
	struct node *next;

};
struct node *top=NULL;
void push(int e){
	struct node *newnode=(struct node*)malloc(sizeof(struct node));
	newnode->data=e;
	newnode->next=top;
	top=newnode;
}

int pop(){
	if (top==NULL){
		printf("Stack is empty\n");
	}
	else{
		struct node *temp=top;
		int pop=temp->data;
		top=top->next;
		free(temp);
		return pop;
	
	}

}
void display(){
	if (top==NULL)printf("Stack empty\n");
	struct node *temp=top;
	while(temp!=NULL){
		printf("%d\n",temp->data);
		temp=temp->next;
	}
}

int main(){
	while(1){
		printf("Stack Menu:-\n1.Push\n2.Pop\n3.Display\n4.Exit\nEnter choice:");
		int ch;
		scanf("%d",&ch);
		switch(ch)
	  {
	   case 1:
		    printf("Enter the data to push:");
		    int data;
		    scanf("%d",&data);
		    push(data);
		    display();
		    break;
	   case 2:
		    int rv;
		    rv=pop();
		    if(rv!=-1) printf("Popped Value is:%d\n",rv);
		    display();
		    break;
	   case 3:
		    display();
		    break;
	   case 4:
		    exit(0);
	   default:
		    printf("Enter the right number\n");
	  }
  }



}

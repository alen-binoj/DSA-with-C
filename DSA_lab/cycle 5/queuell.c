#include <stdio.h>
#include <stdlib.h>
struct node{
	int data;
	struct node *next;

};
struct node *front=NULL,*rear=NULL;

void enqueue(int e){
	struct node *newnode=(struct node *)malloc(sizeof(struct node));
	newnode->data=e;
	newnode->next=NULL;
	if(front==NULL){
		front=newnode;
		rear=newnode;
	
	}
	else{
		rear->next=newnode;
		rear=newnode;
	}

}

int dequeue(){
	if (front==NULL){
		printf("Queue is empty\n");
		return -1;
	}
	else{
		struct node *temp=front;
		int rv=temp->data;
		front=front->next;
		free(temp);
		return rv;
	}
}

void display(){
	if (front ==NULL){
		printf("Queue empty\n");
		
	}
	else{
		struct node *temp=front;
		while(temp!=NULL){
			printf("%d ",temp->data);
			temp=temp->next;
		}
	
		
		
	
	}
	printf("\n");

}
void main()
{
    int ch;

do
{
printf("\nMenu\n----\n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit");
printf("\nEnter the choice:");
scanf("%d",&ch);
switch(ch)
{
case 1:
	printf("Enter the value to be entered:");
	int v;
	scanf("%d",&v);
    enqueue(v);
    display();
    break;
case 2:
    int data;
    data=dequeue();
    if(data!=-1)
        printf("The dequed data is:%d\n",data);
    display();
    break;
case 3:
    display();
    break;
case 4:
    exit(0);
default:
    printf("Invalid no.\n");
    }
  }
while(1);
}


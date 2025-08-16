#include <stdio.h>

#include <stdbool.h>
int front=-1, rear=-1,dfront=-1,drear=-1, dqueue[MAX], cfront=-1, crear=-1, cqueue[MAX];
#define MAX 10
int queue[MAX];
void enqueue(int queue[],e){
    if (rear=MAX-1){
        printf("Queue overflow\n");

    }
    else{
        if (front=rear=-1){
            front=0;
            queue[++rear]=e;
        }
        else{
            queue[++rear]=e;
        }
    }

}
void dequeue(int queue[]){
    if (front==-1){
        printf("Queue underflow\n");
    }
    else{
        int item;
        item=queue[front];
        if (front==rear){
            front=rear=-1; // Queue is now empty
        }
        else{
            front=front+1;
        }
        
    }

}
void cenqueue(int cqueue[], int e){
if (cfront==-1){
    cfront=0;
    crear=0;
    cqueue[crear]=e;
}
else{
    if ((crear+1)%MAX!=cfront){
        crear=(crear+1)%MAX;
        cqueue[crear]=e;
    }
    else{
        printf("Circular Queue overflow\n");
    }
}
}
void cdequeue(int cqueue[]){
    if (cfront==-1){
        printf("Circular Queue underflow\n");
    }
    else{
        int item=cqueue[cfront];
        if (cfront==crear){
            cfront=crear=-1; // Circular Queue is now empty
        }
        else{
            cfront=(cfront+1)%MAX;
        }
    }
}
void denqueuefront(int dqueue[], int e){
    if ((drear+1)%MAX==dfront){
        printf("Deque overflow at front\n");
    }
    else{
        if (dfront==-1 && drear==-1){
            dfront=0;
            drear=0;
            dqueue[drear]=e;
        }
        else{
            dfront=(dfront-1+MAX)%MAX; // Move front pointer backwards
            dqueue[dfront]=e;
        }
    }
}
void denqueuerear(int dqueue[], int e){
    if ((drear+1)%MAX==dfront){
        printf("Deque overflow at rear\n");
    }
    else{
        if (dfront==-1 && drear==-1){
            dfront=0;
            drear=0;
            dqueue[drear]=e;
        }
        else{
            drear=(drear+1)%MAX; // Move rear pointer forwards
            dqueue[drear]=e;
        }
    }
}
void ddequeuefront(int dqueue[]){
    if (dfront==-1){
        printf("Deque underflow at front\n");
    }
    else{
        int item=dqueue[dfront];
        if (dfront==drear){
            dfront=drear=-1; // Deque is now empty
        }
        else{
            dfront=(dfront+1)%MAX; // Move front pointer forwards
        }
    }
}
void ddequeuerear(int dqueue[]){
    if (drear==-1){
        printf("Deque underflow at rear\n");
    }
    else{
        int item=dqueue[drear];
        if (dfront==drear){
            dfront=drear=-1; // Deque is now empty
        }
        else{
            drear=(drear-1+MAX)%MAX; // Move rear pointer backwards
        }
    }
}
          
int main(){
    int e;
    while (true){
        printf("1.Queue\n2.Deque\n3.Curcular Queue\n4.Exit\n");
        int choice;
        scanf("%d", &choice);
        switch(choice){
            case 1:
                printf("1.Enqueue\n2.Dequeue\n3.Exit\n");
                int ch1;
                scanf("%d", &ch1);
                switch(ch1){
                    case 1:
                        printf("Enter element to enqueue: ");
                        scanf("%d", &e);
                        enqueue(queue,e);
                        break;
                    case 2:
                        dequeue(queue);
                        break;
                    case 3:
                        break;
                    default:
                        printf("Invalid choice\n");
                }
            case 2:
                printf("1.Enqueue at front\n2.Enqueue at rear\n3.Dequeue from front\n4.Dequeue from rear\n5.Exit\n");
                int ch3;
                scanf("%d", &ch3);
                switch(ch3){
                    case 1:
                        printf("Enter element to enqueue at front: ");
                        scanf("%d", &e);
                        denqueuefront(dqueue, e);
                        break;
                    case 2:
                        printf("Enter element to enqueue at rear: ");
                        scanf("%d", &e);
                        denqueuerear(dqueue, e);
                        break;
                    case 3:
                        ddequeuefront(dqueue);
                        break;
                    case 4:
                        ddequeuerear(dqueue);
                        break;
                    case 5:
                        break;
                    default:
                        printf("Invalid choice\n");
                }
                break;
            case 3:
                printf("1.Circular Enqueue\n2.Circular Dequeue\n3.Exit\n");
                int ch2;
                scanf("%d", &ch2);
                switch(ch2){
                    case 1:
                        printf("Enter element to enqueue in circular queue: ");
                        scanf("%d", &e);
                        cenqueue(cqueue, e);
                        break;
                    case 2:
                        cdequeue(cqueue);
                        break;
                    case 3:
                        break;
                    default:
                        printf("Invalid choice\n");
                }
                
        }
}
}
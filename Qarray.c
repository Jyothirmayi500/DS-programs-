#include<stdio.h>
#define SIZE 10
void enQueue(int ele);
void deQueue();
void display();
int Queue[SIZE];
int front=-1,rear=-1;
int main(){
    enQueue(32);
    enQueue(12);
    display();
    deQueue();
    display();
}
void enQueue(int ele){
    if(rear==SIZE-1){
        printf("Queue is overflow");
    }
    else{
        if(rear==-1 && front==-1){
            front=0;
            rear=0;
        }
        else{
            rear++;
        }
        Queue[rear]=ele;
    }
}
void deQueue(){
    if(front==-1 && front>rear){
        printf("Queue is underflow not possible to delete");
    }
    else
    printf("\nthe element to be deleted is %d\n",Queue[front]);
    front++;
}
void display(){
    if(front==-1 && front>rear)
    printf("Queue is underflow not possible to display");
    else
    printf("the elements in the queue are:\n");
    for(int i=front;i<=rear;i++){
        printf("%d\t",Queue[i]);
    }
}

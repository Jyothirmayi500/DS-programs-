#include<stdio.h>
#include<stdlib.h>
void push(int ele);
void pop();
void peek();
void display();
struct node
 {
 int data;
 struct node*next;
 };
 struct node*top= NULL;
int main()
{
int ch,ele;
do{
printf("menu\n1.push\n2.pop\n3.peek\n4.display\n");
printf("enter the choice : ");
 scanf("%d",&ch);
 switch(ch)
 {
 case 1:
 printf("enter the value to be pushed : ");
 scanf("%d",&ele);
 push(ele);
 break;
 case 2:
 pop();
 break;
 case 3:
 peek();
 break;
 case 4:
 display();
 break; 
 default:
 printf("wrong choice");
 }
 }while(ch<=4);
 return 0;
 }
 void push(int ele)
 {
 struct node*newnode = (struct node*)malloc(sizeof(struct node));
 newnode->data=ele;
 newnode->next=NULL;
 if(top == NULL){
 top = newnode;
 }
 else
 {
 newnode->next = top;
 top = newnode;
 }
 }
 void pop()
 {
 if(top == NULL)
 {
 printf(" stack is empty  , not possible for pop");
 }
 else
 {
 struct node*temp = top;
 top = top->next;
 temp->next = NULL;
 printf("The element to be popped is %d ",temp->data);
 free(temp);
 }
 }
void peek()
 {
 if(top == NULL)
 {
 printf(" stack is empty  ");
 }
 else{
printf("The top most element is %d ",top->data);
}
}
void display()
 {
 
 if(top==NULL)
 {
 printf("Stack is empty,not possible to print");
 }
 else{
 struct node*temp = top;
 while(temp!=NULL){
 printf("%d\t",temp->data);
 temp=temp->next;
 }
 }
 }
 
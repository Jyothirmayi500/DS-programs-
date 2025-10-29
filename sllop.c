#include<stdio.h>
#include<stdlib.h>

 struct node*create(int ele);
 void insert_beg(int ele);
 void insert_end(int ele);
 void insert_pos(int ele);
 void delete_beg();
 void delete_end();
 void delete_pos();
 void display();
 struct node
 {
 int data;
 struct node*next;
 };
 struct node*head = NULL;
 int main()
 {
 int ch;
 int ele;
 do
 {
 printf("\nMenu\n1.insert_beg\n2.insert_end\n3.insert_pos\n4.delete_beg\n5.delete_end\n6.delete_pos\n7.display\n");
 printf("enter the choice : ");
 scanf("%d",&ch);
 switch(ch)
 {
 case 1:
 printf("enter the value to be inserted : ");
 scanf("%d",&ele);
 insert_beg(ele);
 break;
 case 2:
 printf("enter the value to be inserted : ");
 scanf("%d",&ele);
 insert_end(ele);
 break;
 case 3:
 printf("enter the value to be inserted : ");
 scanf("%d",&ele);
 insert_pos(ele);
 break;
 case 4:
 delete_beg();
 break; 
 case 5:
 delete_end();
 break; 
 case 6:
 delete_pos();
 break; 
 case 7:
 display();
 break; 
 default:
 printf("wrong choice");
 break; 
 }
 }while(ch<=7);
 return 0;
 }
 struct node*create(int ele)
 {
 struct node*newnode=(struct node*)malloc(sizeof(struct node));
 newnode->data = ele;
 newnode->next=NULL;
 return newnode;
 }
 void insert_beg(int ele)
 {
 struct node*newnode=create(ele);
 if(head==NULL){
 head=newnode;
 }
 else{
 newnode->next=head;
 head=newnode;
 }
 }
 void insert_end(int ele)
 {
 struct node*newnode = create(ele);
 if(head==NULL){
 head=newnode;
 }
 else{
 struct node*temp = head;
 while(temp->next!=NULL){
 temp = temp->next;
 temp->next = newnode;
 }
 }
 }
 void insert_pos(int ele)
 {
 struct node*newnode = create(ele);
 int pos;
 printf("enter the position");
 scanf("%d",&pos);
 int count=0;
 if(pos==0)
 {
 newnode->next=head;
 head=newnode;
 }
 else{
 struct node*temp = head;
 while(count<pos-1 && temp->next!=NULL)
 {
 temp=temp->next;
 count++;
 }
 if(temp->next!=NULL)
 {
 newnode->next= temp->next;
 temp->next = newnode;
 }
 else{
 printf("position node not found");
 }
 }
 }
 void delete_beg()
 {
 struct node*temp = head;
 if(head == NULL)
 {
 printf("SLL is empty, not possible to delete");
 return;
 }
 else if(head->next==NULL)
 {
 head = NULL;
 }
 else{
 head = head->next;
 temp->next=NULL;
 }
 free(temp);
 }
 void delete_end()
 {
 struct node*prev,*temp=head;
 if(head==NULL)
 {
 printf("SLL is empty");
 return;
 }
 else if(head->next==NULL)
 {
 head = NULL;
 }
 else{
 while(temp->next!=NULL)
 {
 prev = temp;
 temp = temp->next;
 }
 prev->next=NULL;
 }
 free(temp);
 }
 void delete_pos()
 {
 struct node*prev,*temp=head;
 int pos;
 printf("enter the position");
 scanf("%d",&pos);
 int count=0;
 if(head==NULL)
 {
 printf("empty");
 return;
 }
 else if(pos=1 && head->next==NULL)
 {
 head =NULL;
 }
 else
 {
 if(pos==1)
 {
 head=temp->next;
 temp->next=NULL;
 }
 else
 {
 int count =1;
 while(count!=pos && temp->next!=NULL)
 {
 prev =temp;
 temp=temp->next;
 count++;
 }
 if(count== pos)
 {
 prev->next=NULL;
 }
 }
 }
 free(temp);
 }
 void display()
 {
 struct node*temp=head;
 if(head==NULL)
 {
 printf("SLL is empty,not possible to print");
 return;
 }
 while(temp!=NULL)
 {
 printf("%d\t",temp->data);
 temp=temp->next;
 }
 }
 
 
 
 

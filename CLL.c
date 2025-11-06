#include<stdio.h>
#include<stdlib.h>

 struct node*create(int ele);
 void insert_beg(int ele);
 void insert_end(int ele);
 //void insert_pos(int ele);
 void delete_beg();
 void delete_end();
 //void delete_pos();
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
 printf("\nMenu\n1.insert_beg\n2.insert_end\n3.delete_beg\n4.delete_end\n5.display\n");
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
 delete_beg();
 break; 
 case 4:
 delete_end();
 break; 
 case 5:
 display();
 break; 
 default:
 printf("wrong choice");
 break; 
 }
 }while(ch<=5);
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
 struct node* newnode=create(ele);
 if(head==NULL){
 head=newnode;
newnode->next=head;
 }
 else{
 struct node* temp = head;
 while(temp->next!=head){
 temp = temp->next;
 }
  temp->next = newnode;
 newnode->next=head;
 head=newnode;
 }
 }
 void insert_end(int ele)
 {
 struct node* newnode = create(ele);
 if(head==NULL){
 head=newnode;
 }
 else{
 struct node* temp = head;
 while(temp->next!=head){
 temp = temp->next;
}
 temp->next = newnode;
 newnode->next=head;
 }

 }
 void delete_beg()
 {
 struct node* temp = head;
  struct node* temp1=head;
 if(head == NULL)
 {
 printf("CLL is empty, not possible to delete");
 return;
 }
 else if(head->next==NULL)
 {
 head = NULL;
 }
 else{
   
while(temp->next!=head)
 {
 temp = temp->next;
 }
 head=head->next;
 temp->next=head;
 temp1->next=NULL;
 }
 free(temp1);
 
 }
 
 void delete_end()
 {
 struct node* prev,*temp=head;
 if(head==NULL)
 {
 printf("CLL is empty");
 return;
 }
 else if(head->next==NULL)
 {
 head = NULL;
 }
 else{
 while(temp->next!=head)
 {
 prev = temp;
 temp = temp->next;
 }
 prev->next=head;
 temp->next=NULL;
 }
 free(temp);
 }
void display()
 {
 struct node* temp=head;
 if(head==NULL)
 {
 printf("CLL is empty,not possible to print");
 return;
 }
 do
 {
 printf("%d\t",temp->data);
 temp=temp->next;
 }while(temp!=head);
 }
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
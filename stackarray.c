#include<stdio.h>
void push( int ele);
int pop();
int peek();
void display();
int stack[10];
int top=1;
int main()
{
    int ch;
    int ele;
    do
    {
    printf("menu\n1. push\n 2.pop\n 3.peek\n 4.diplay\n");
    printf("enter the choice");
    scanf("%d",&ch);
      switch(ch)
      {
        case 1:
        printf("enter the element to be pushed into stack");
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
          default :
          printf("entered wrong choice");
          break;
      } 
    } while (ch<=4);
}

void push(int ele)
{
    if(top==9){
    printf("stack is full");
    return;
    }
    else{
        top++;
        stack[top]=ele;
    }
}
int pop()
{
    if(top==-1){
    printf("stack is Empty");
    return -1;
    }
    else
    {
        int e=stack[top];
        top--;
        return e;
    }
}
int peek()
{
    if(top==-1){
        printf("stack is empty");
        return -1;
    }
     return stack[top];
}
void display()
{
    if(top==-1)
    {
        printf("stack is empty");
    }
    else{
        printf("the element in the stack are");
        for(int i=top;i>0;i--)
        {
            printf("%d\t",stack[i]);
        }
    }
}
    
    
    
    



#include<stdio.h>
void infixtopostfix(char infix[20],char postfix[20]);
int precedence(char ch);
void push(char symbol);
char pop();
char stack[20];
int top=-1;
int main(){
    char infix[20];
    char postfix[20];
    printf("enter the infix expression :");
    scanf("%s",infix);
    infixtopostfix(infix,postfix);
    printf("the postfix expression is %s",postfix);
}
void infixtopostfix(char infix[20],char postfix[20])
{
    char symbol;
    int i=0,j=0;
    while(infix[i]!='\0')
    {
      symbol=infix[i];
        switch(symbol)
        {
            case '(':
              push(symbol);
               break;
            case ')':
                while(stack[top]!='(')
                postfix[j++]=pop();
                top--;
                break;
            case'+':
            case'-':
            case'*':
            case'/':
            case'^':
            while(precedence(symbol)<=precedence(stack[top]) && top!=-1)
            postfix[j++]=pop();
            push(symbol);
            break;
            default:
            postfix[j++]=symbol;
            break;
        }
        i++;
    }
        while(top!=-1)
            postfix[j++]=pop();
            postfix[j]='\0';
}      
int precedence(char ch){
            switch (ch)
            {
            case '+':
            case '-':
               return 1;
            case '*':
            case '/':
                return 2;
            case '^':
                  return 3;
            default :
                 return 0; 
            }
        }
        void push(char symbol){
            stack[++top]=symbol;
        }
        char pop(){
             return stack[top--];
        }



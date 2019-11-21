#include<stdio.h>
#include<stdlib.h>
#define MAX 5
int stack[MAX];
int top=-1;
void push();
void pop();
void display();

void main()
{
    int choice;
    while(1)
    {
        printf("\nPress 1 to push elements to the Stack\n");
        printf("Press 2 to pop elements from the Stack\n");
        printf("Press 3 to display the Stack\n");
        printf("Press 4 to exit\n");
        printf("\nEnter choice : ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: push(); break;
            case 2: pop(); break;
            case 3: display(); break;
            case 4: exit(0); break;
            default: printf("\nWrong Choice. Try Again...\n");
        }
    }
}

void push()
{
    int data;
    if (top==MAX-1)
    {
        printf("\nStack Overflow\n");
        return ;
    }
    printf("\nEnter element to Push : ");
    scanf("%d",&data);
    top++;
    stack[top]=data;
}

void pop()
{
    if (top==-1)
    {
        printf("\nStack Underflow\n");
        return ;
    }
    printf("\nPopped Element : %d",stack[top]);
    top--;
}

void display()
{
    int i;
    if (top==-1)
    {
        printf("Stack is Empty\n");
        return ;
    }
    printf("\nElemets in the stack are : \n");
    for (i=top; i>=0; i--)
        printf("\n\t\t\t\t%d\n",stack[i]);
}

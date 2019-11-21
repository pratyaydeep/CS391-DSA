#include<stdio.h>
#include<stdlib.h>

int stack[100]; int top=-1;

int prdence(char a)
{
    switch(a)
        {
        case '+': return 2;
        case '-': return 1;
        case '*': return 3;
        case '/': return 4;
        case '^': return 5;
        case '(': return 0;
        }
}

void main()
{
    char s[100],p[100];
    int sptr=0;
    int pptr=0;

    printf("\tProgram to convert Infix Expression TO Postfix Expression:\t\n");
    printf("\nEnter the Infix Expression : ");
    gets(s);

    while(s[sptr]!='\0')
    {
        switch(s[sptr])
        {
    case '(': top++; stack[top]='('; break;
        case '+':
        case '-':
        case '*':
        case '/':
        case '^':
            while(prdence(s[sptr])<prdence(stack[top]) && top>=0)
            {
                p[pptr]=stack[top];
                pptr++;
                top--;
            }
            top++;
            stack[top]=s[sptr];
            break;
        case ')':
            while(top!=-1 && stack[top]!='(')
            {
                p[pptr]=stack[top];
                top--;
                pptr++;
            }
            top--;
            break;
        default:
            p[pptr]=s[sptr];
            pptr++;
        }
        sptr++;
    }
    while(top>=0)
    {
        p[pptr]=stack[top];
        top--;
        pptr++;
    }
    p[pptr]='\0';
    puts(p);
}

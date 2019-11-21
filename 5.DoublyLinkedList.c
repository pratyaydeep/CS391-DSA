// Program for Doubly Linked List
#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next, *prev;
}*start;

void create_list(int);
void display();
void add_begin(int);
void add_specific(int,int);
void count();
void search(int);
void del(int);
void rev();

void main()
{
    int i,n,m,pos,choice,d;
    start=NULL;
    while(1)
    {
        printf("\nPress 1 to create a list");
        printf("\nPress 2 to display the list");
        printf("\nPerss 3 to add data to the beginnig of the list");
        printf("\nPress 4 to add data to specific position of the list");
        printf("\nPress 5 to count elements");
        printf("\nPress 6 to search an element");
        printf("\nPress 7 to delete an element");
        printf("\nPress 8 to reverse the list");
        printf("\nPress 9 to exit\n");

        printf("\n\nEnter Choice : ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1: printf("\nEnter initial population : ");
                    scanf("%d",&m);
                    printf("\nEnter Data : ");
                    for (i=0;i<m;i++)
                    {
                        scanf("%d",&d);
                        create_list(d);
                    }
                    break;
            case 2: printf("\nThe List is : ");
                    display();
                    printf("\n");
                    break;
            case 3: printf("\nEnter data to insert at beginning of list : ");
                    scanf("%d",&d);
                    add_begin(d);
                    break;
            case 4: printf("\nEnter position and data to add in the list : ");
                    scanf("%d %d",&pos,&d);
                    add_specific(pos,d);
                    break;
            case 5: count(); break;
            case 6: printf("\nEnter data to search : ");
                    scanf("%d",&d);
                    search (d); break;
            case 7: printf("\nEnter data to delete : ");
                    scanf("%d",&d);
                    del (d); break;
            case 8: rev(); break;
            case 9: exit(0);
            default : printf("\nWrong Choice\n");
        }
    }
}

//Creation of Doubly List
void create_list(int d)
{
    struct node *temp,*q;
    temp=malloc(sizeof(struct node));
    temp->next=NULL;
    temp->data=d;
    if (start==NULL)
    {
        temp->prev=NULL;
        start=temp;
    }
    else
    {
        q=start;
        while(q->next!=NULL)
            q=q->next;
        q->next=temp;
        temp->prev=q;
    }
}

//Display of List
void display()
{
    struct node *q;
    q=start;
    while(q!=NULL)
    {
        printf(" %d",q->data);
        q=q->next;
    }
}

//Adding an element to the beginning of the list
void add_begin(int d)
{
    struct node *temp;
    temp=malloc(sizeof(struct node));
    temp->data=d;
    temp->next=start;
    start->prev=temp;
    temp->prev=NULL;
    start=temp;
}

//Adding an element to a specific position in the list
void add_specific(int pos, int d)
{
    int i;
    struct node *temp,*q;
    temp=malloc(sizeof(struct node));
    temp->data=d;
    q=start;
    for (i=0;i<pos-2;i++)
    {
        q=q->next;
        if (q==NULL)
        {
            printf("\nImproper Position");
            return ;
        }
    }
    temp->next=q->next;
    q->next->prev=temp;
    q->next=temp;
    temp->prev=q;
}

//Counting the number of elements in the list
void count(int d)
{
    struct node *q;
    int c=0;
    q=start;
    while(q!=NULL)
    {
        c++;
        q=q->next;
    }
    printf("\nNumber of elements is %d",c);
}

// Searching for an elemet in the list
void search(int d)
{
    struct node *q;
    int c=0;
    q=start;
    while(q!=NULL)
    {
        c++;
        if (q->data==d)
        {
            printf("\nElement found at node %d",c);
            return ;
        }
        q=q->next;

    }
    printf("\nElement not found");
}

//Function to delete data in the list
void del (int d)
{
    struct node *q, *temp;
    if (start->data==d)
    {
        temp=start;
        start=start->next;
        start->prev=NULL;
        free(temp);
        return ;
    }
    q=start;
    while(q->next->next!=NULL)
    {
        if (q->next->data==d)
        {
            temp=q->next;
            q->next=temp->next;
            temp->next->prev=q;
            free(temp);
            return ;
        }
        q=q->next;
    }
    if (q->next->data==d)
    {
        temp=q->next;
        q->next=NULL;
        free(temp);
        return ;
    }
    printf("\nData not found");
}

//Function to reverse the list
void rev()
{
    struct node *p1, *p2;
    p1=start;
    p2=p1->next;
    p1->next=NULL;
    p1->prev=p2;
    while(p2!=NULL)
    {
        p2->prev=p2->next;
        p2->next=p1;
        p1=p2;
        p2=p2->prev;
    }
    start=p1;
}

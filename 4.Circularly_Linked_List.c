// Program for Circularly Linked List
#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
}*last;

void create_list(int);
void display();
void add_begin(int);
void add_specific(int,int);
void count();
void search(int);
void del(int);

void main()
{
    int i,n,m,pos,choice,d;
    last=NULL;
    while(1)
    {
        printf("\nPress 1 to create a list");
        printf("\nPress 2 to display the list");
        printf("\nPerss 3 to add data to the beginnig of the list");
        printf("\nPress 4 to add data to specific position of the list");
        printf("\nPress 5 to count elements");
        printf("\nPress 6 to search an element");
        printf("\nPress 7 to delete an element");
        printf("\nPress 8 to exit\n");

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
            case 8: exit(0);
            default : printf("\nWrong Choice\n");
        }
    }
}

// Function for creating a Circular List
void create_list(int d)
{
    struct node *temp, *q;
    temp=malloc(sizeof(struct node));
    temp->data=d;
    if (last==NULL)
    {
        last=temp;
        temp->next=last;
    }
    else
    {
        q=last;
        temp->next=q->next;
        q->next=temp;
        last=temp;
    }
}

//Function for displaying the list
void display()
{
    struct node *q;
    q=last->next;
    while(q!=last)
    {
        printf(" %d",q->data);
        q=q->next;
    }
    printf(" %d",last->data);
}

//Function to add data to the beginning of the list
void add_begin(int d)
{
    struct node *temp;
    temp=malloc(sizeof(struct node));
    temp->data=d;
    temp->next=last->next;
    last->next=temp;
}

// Function to insert element at specific position
void add_specific(int pos, int d)
{
    struct node *temp, *q;
    int i;
    temp=malloc(sizeof(struct node));
    temp->data=d;
    q=last->next;
    for (i=0;i<pos-2;i++)
    {
        q=q->next;
        if (q==last->next)
        {
            printf("Erroneous Attempt\n");
            return ;
        }
    }
    temp->next=q->next;
    q->next=temp;
    if (q==last)
        last=temp;
}

//Function to count elements in a list
void count()
{
    int c;
    if (last==NULL)
        c=0;
    else
    {
        struct node *q; c=1;
        q=last->next;
        while(q!=last)
        {
            c++;
            q=q->next;
        }
    }
    printf("The number of elements in the list is %d\n",c);
    return ;
}

// Function to search for an element
void search(int d)
{
    struct node *q; int c=1;
    if (last==NULL)
    {
        printf("Empty List\n");
        return ;
    }
    q=last->next;
    while(q!=last)
    {
        if (q->data==d)
        {
            printf("Element found at position %d\n",c);
            return ;
        }
        c++;
        q=q->next;
    }
    if (q->data==d)
    {
        printf("Element found at position %d\n",c);
        return ;
    }
    printf("Element was not found\n");
}

// Function to delete an element from the list
void del(int d)
{
    struct node *temp, *q;
    if (last->next==last && last->data==d)
    {
        temp=last;
        last=NULL;
        free(temp);
        return ;
    }
    q=last->next;
    if (q->data==d)
    {
        temp=q;
        last->next=temp->next;
        free(temp);
        return ;
    }
    while(q->next!=last)
    {
        if (q->next->data==d)
        {
            temp=q->next;
            q->next=temp->next;
            free(temp);
            return ;
        }
        q=q->next;
    }
    if (q->next->data==d)
    {
        temp=q->next;
        q->next=temp->next;
        last=q;
        free(temp);
        return ;
    }
    printf("%d not found\n",d);
}

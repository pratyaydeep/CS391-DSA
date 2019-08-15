#include<stdio.h>
#include<stdlib.h>
int main()
{
    int arr[100],i,r,n,m;
    printf("Enter the initial population of the Array : ");
    scanf("%d",&n);

    //Input Array
    printf("Enter the values of array : ");
    for (i=0;i<n;i++) scanf("%d",&arr[i]);
    printf("\nEnter the position and element to insert : ");
    scanf("%d %d",&m,&r);
    //here it is assumed that position 1 == index 0
    for(i=n-1;i>=m-1;i--) //replace i>=m-1 with i>m-1 to assume position 0 == index 0
    {
        arr[i+1]=arr[i];
    }
    arr[i+1]=r;

    //Displaying Array
    printf("\nThe final array is : ");
    for (i=0;i<n+1;i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
    return 0;
}

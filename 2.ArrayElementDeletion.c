#include<stdio.h>
#include<stdlib.h>
int main()
{
    int arr[100],i,n,m;
    printf("Enter the initial population of the Array : ");
    scanf("%d",&n);

    //Input Array
    printf("Enter the values of array: ");
    for (i=0;i<n;i++) scanf("%d",&arr[i]);
    printf("\nEnter the position to delete : ");
    scanf("%d",&m);
    //here it is assumed that position 1 == index 0
    for(i=m-1;i<n-1;i++) //replace m-1 with m to assume position 0 == index 0
    {
        arr[i]=arr[i+1];
    }

    //Display Array
    printf("\nThe final array is : ");
    for (i=0;i<n-1;i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
    return 0;
}

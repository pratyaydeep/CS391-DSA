#include<stdio.h>

void Merge(int a[], int i1, int j1, int i2, int j2)
{
    int temp[50]; int i=i1,j=i2,k=0;
    while(i<=j1 && j<=j2)
    {
        if (a[i]<a[j])
            temp[k++]=a[i++];
        else
            temp[k++]=a[j++];
    }
    while(i<=j1) temp[k++]=a[i++];

    while(j<=j2) temp[k++]=a[j++];
    for(i=i1,j=0; i<=j2;i++,j++) a[i]=temp[j];
}
void MergeSort(int a[], int i, int j)
{
    if(i<j)
    {
        int mid=(i+j)/2;
        MergeSort(a,i,mid);
        MergeSort(a,mid+1,j);
        Merge(a,i,mid,mid+1,j);
    }
}
void main()
{
    int n;
    int arr[100];
    printf("Enter the length of the array : ");
    scanf("%d",&n);
    printf("Enter the Unsorted Array : ");
    for(int i=0; i<n; i++) scanf("%d",&arr[i]);
    MergeSort(arr,0,n-1);
    printf("The array after sorting is :\n");
    for (int i=0;i<n;i++) printf(" %d",arr[i]);
}

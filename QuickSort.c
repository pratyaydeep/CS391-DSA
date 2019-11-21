#include<stdio.h>

int partition (int arr[], int low, int high)
{
    int swap;
	int pivot = arr[high]; // pivot
	int i = (low - 1);

	for (int j = low; j <= high- 1; j++)
	{

		if (arr[j] < pivot)
		{
			i++;
			swap=arr[i];
			arr[i]=arr[j];
			arr[j]=swap;
		}
	}
	swap=arr[i+1];
	arr[i+1]=arr[high];
	arr[high]=swap;

	return (i + 1);
}

void quickSort(int arr[], int low, int high)
{
	if (low < high)
	{

		int pi = partition(arr, low, high);

		quickSort(arr, low, pi - 1);
		quickSort(arr, pi + 1, high);
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
    quickSort(arr,0,n-1);
    printf("The array after sorting is :\n");
    for (int i=0;i<n;i++) printf(" %d",arr[i]);
}

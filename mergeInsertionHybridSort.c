#include<stdio.h>

void Insertion_Sort(int *a, int n)
{
	for(int j=1;j<n;j++)
	{
		int key=a[j];
		int i=j-1;
		
		while(i>=0&&a[i]>key)
		{
			a[i+1]=a[i];
			i-=1;
		}
	
		a[i+1]=key;
	}
}

void Merge_Sort(int *arr, int n)
{
	int a[n/2+1];
	int b[n/2+1];
	
	int i;
	
	for(i=0;i<n/2;i++)
	{
		a[i]=arr[i];
		b[i]=arr[i+n/2];
	}
	
	Insertion_Sort(a, n/2);
	Insertion_Sort(b, n/2);
	
	a[i]=10000;	//infinity equivalent/sentinel
	b[i]=10000;	//infinity equivalent/sentinel
	
	i=0;
	int j=0, orig_index=0;
	
	while(a[i]!=10000 || b[j]!=10000)
	{
		if(a[i]<b[j])
			arr[orig_index++]=a[i++];
		if(b[j]<a[i])
			arr[orig_index++]=b[j++];
	}

	if(a[i]==10000)
		while(b[j]!=10000)
			arr[orig_index++]=b[j++];
	
	if(b[j]==10000)
		while(a[i]!=10000)
			arr[orig_index++]=a[i++];
}

int main()
{
	int arr[8];
	int i=0;
	printf("\n Enter your array (8 Values): ");
	
	for(i=0;i<8;i++)
		scanf("%d", &arr[i]);
	
	Merge_Sort(arr, 8);
	
	printf("\n Sorted : ");

	for(int i=0;i<8;i++)
		printf("%d\t", arr[i]);
	printf("\n\n");

	return 0;
}

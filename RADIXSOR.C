#include<stdio.h>

int largest(int arr[],int size)
{
	int large=arr[0],i;
	for(i=1;i<size;i++)
	{
		if(arr[i]>large)
			large=arr[i];
	}
	return large;
}
void RadixSort(int arr[],int size)
{
	int bucket[10][10],bcount[10],i,j,k,no_of_digit=0,divisor=1;
	int r,pass;
	int large=largest(arr,size);
	while(large>0)
	{
		no_of_digit++;
		large=large/10;
	}
	for(pass=0;pass<no_of_digit;pass++)
	{
		for(i=0;i<10;i++)
			bcount[i]=0;
		for(i=0;i<size;j++)
		{
			r=(arr[i]/divisor)%10;
			bucket[r][bcount[r]]=arr[i];
			bcount[r]=bcount[r]+1;
		}
		i=0;
		for(k=0;k<10;k++)
		{
			for(j=0;j<bcount[k];j++)
			{
				arr[i]=bucket[k][j];
				i++;
			}
		}
		divisor=divisor*10;
	}
}
void PrintArray(int arr[],int size)
{
	int i;
	for(i=0;i<size;i++)
		printf("%d \n",arr[i]);
}
void main()
{
	int i,size,arr[20];
	clrscr();
	printf("Number of elements you want to enter\n");
	scanf("%d",&size);
	printf("Enter elements\n");
	for(i=0;i<size;i++)
	{
		scanf("%d",&arr[i]);
	}
	RadixSort(arr,size);
	printf("Sorted Array is\n");
	PrintArray(arr,size);
	getch();
}

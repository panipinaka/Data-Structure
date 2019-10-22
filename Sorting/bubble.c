//bubble sort

#include<stdio.h>
#include<stdint.h>
void bubble_sort(int32_t a[],int32_t size)
{
	int i,j,temp;
	for(i=0;i<size;i++)
	{
	for(j=0;j<size-i;j++)
	{
	if(a[j]>a[j+1])
	{
	temp=a[j+1];
	a[j+1]=a[j];
	a[j]=temp;
	}
	}
	}
for(i=1;i<=size;i++)
{
	printf("%d \t",a[i]);
}
}

int main()
{
	int32_t a[10]={23,1,45,90,7,43};
	bubble_sort(a,6);
	return 0;
}
//insertion sort

#include<stdio.h>
#include<stdint.h>

void insertion(int32_t a[],int32_t size)
{
	int i,j=0,temp=0;
	int key;

	for(i=1;i<size;i++)
	{
		key = a[i];
		j=i-1;
		while(j>=0 && a[j]>key)
		{
			a[j+1]=a[j];
			j--;
		}
		a[j+1]=key;
	}
	for(i=0;i<size;i++)
	{
		printf("%d\t",a[i] );
	}
}

int main()
{
	int32_t a[10]={23,1,45,90,7,43};
	insertion(a,6);
	return 0;
}

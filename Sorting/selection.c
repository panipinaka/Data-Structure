//selection sort

#include<stdio.h>
#include<stdint.h>

void selection_sort(int32_t a[],int32_t size)
{
	int i=0;

	for(i=0;i<size;i++)
	{
		int min = i;
		for (int j=i+1;j<size;j++)
		{
			if(a[j]<a[min])
			{
				min=j;
			}
		}
		int temp;
		temp=a[min];
		a[min]=a[i];
		a[i]=temp;
	}
	for(i=1;i<size;i++)
	{
		printf("%d\t",a[i] );
	}
}

int main()
{
	int32_t a[10]={23,1,45,90,7,43};
	selection_sort(a,6);
	return 0;
}


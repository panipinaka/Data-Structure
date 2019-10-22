//merge sort

#include<stdio.h>
#include<stdint.h>

static void _merger_(int a[],int32_t start, int32_t mid, int32_t end)
{
	int f_index,s_index,t_index,i,temp[10];
	f_index = t_index = start;
	s_index = mid+1;
	while(f_index<=mid && s_index<=end)
	{
		if(a[f_index]<= a[s_index])
		{
			temp[t_index++] = a[f_index++];
		}
		else
		{
			temp[t_index++] = a[s_index++];
		}
	}

	if(f_index>mid)
	{
		for(i=s_index;i<=end;i++)
		{
			temp[t_index++]=a[i];
		}
	}

	//if(s_index>end)
	else
	{
		for(i=f_index;i<=mid;i++)
		{
			temp[t_index++]=a[i];
		}
	}

	for(i=start;i<=end;i++)
	{
		a[i]=temp[i];
	}

}

void merge_sort(int a[],int32_t start,int32_t end)
{
	int32_t mid; 
	if(start<end)
	{
		mid= (start+end)/2;
		merge_sort(a,start,mid);
		merge_sort(a,mid+1,end);
		_merger_(a,start,mid,end);
	}
}

int main()
{
	int32_t a[10]={23,1,45,90,7,43};
	merge_sort(a,0,5);
	for(int32_t i=0;i<6;i++)
	{
		printf("%d\t",a[i] );
	}
	return 0;
}
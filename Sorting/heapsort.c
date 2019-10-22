//heap.c

#include<stdio.h>
#include<assert.h>
#include<stdint.h>
#include "heapsort.h"

static void _heapify_(int32_t data[],int32_t length,int32_t parent)
{
	int32_t child = 2*parent;

	while(child<=length)
	{
		if(child+1<length)
		{
			if(a[child+1]>a[child])
			{
				child++;
			}
		}
		if(a[parent]>=a[child])
		{
			break;
		}
		int32_t temp;
		temp=a[child];
		a[child] = a[parent];
		a[parent] = a[temp];
		parent=child;
		child = 2*parent;
	}
}

Heap heap_new(int32_t data[],int32_t length)
{
	assert(length>0 && length<HEAP_SIZE);
	Heap heap;
	int32_t parent;
	for(parent=length/2;parent>0;parent--)
	{
		_heapify_(data,length,parent)
	}
	heap.size = 
}
#ifndef _HEAPSORT_
#define _HEAPSORT_

#include<stdint.h>
#include HEAP_SIZE 32

typedef struct _heap_ Heap;

struct _heap_
{
	int32_t size;
	int32_t data[HEAP_SIZE];
};

Heap heap_new(int32_t data[]);
void heap_sort(Heap *heap);


#endif
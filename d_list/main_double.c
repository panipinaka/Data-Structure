#include <assert.h>
#include "slist_double.h"


void test_add_tail()
{
    Slist s = slist_new();
	Slist *list = &s;

	list=slist_add_tail(list,10);
	list=slist_add_tail(list,20);
	list=slist_add_tail(list,30);
	list=slist_add_tail(list,40);
	assert(list->tail->data==40);
}



void test_add_head()
{
    Slist s = slist_new();
	Slist *list = &s;

	list=slist_add_head(list,10);
	list=slist_add_head(list,20);
	list=slist_add_head(list,30);
	list=slist_add_head(list,40);
	assert(list->head->data==40);

}


void test_del_tail()
{
    Slist s = slist_new();
	Slist *list = &s;

	list=slist_add_tail(list,10);
	list=slist_add_tail(list,20);
	list=slist_add_tail(list,30);
	list=slist_add_tail(list,40);
	list=slist_delete_tail(list);
	assert(slist_length(list)==3);

}


void test_del_head()
{
    Slist s = slist_new();
	Slist *list = &s;
	list=slist_add_tail(list,10);
	list=slist_add_tail(list,20);
	list=slist_add_tail(list,30);
	slist_delete_head(list);
	assert(slist_lookup(list,10)==0);
	assert(slist_length(list)==2);


}
int main()
{
    test_add_tail();
    test_add_head();
    test_del_tail();
    test_del_head();

	return 0;
}

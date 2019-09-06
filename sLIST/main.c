#include <assert.h>
#include<stdio.h>
#include<stdbool.h>
#include "slist .h"

void test_empty_list()
{
    Slist s = slist_new();
	Slist *list = &s;                                         //test case for empty list
	assert(slist_length(list) == 0);
}

void test_addition_at_head()
{
    Slist s = slist_new();                                     //test case for adding head
	Slist *list = &s;
	list=slist_add_head(list,10);
	list=slist_add_head(list,20);
	assert(list->head->data==20);
	assert(list->length==2);

}

void test_addition_at_tail()
{
    Slist s = slist_new();
    Slist *list = &s;
	list = slist_add_tail(list, 10);
	list = slist_add_tail(list, 20);                                      //test case for adding tail
	assert(list->tail->data==20);
	assert(list->length==2);

}

void test_deletion_at_head()
{
    Slist s = slist_new();
	Slist *list = &s;
	list = delete_head(list);

	list = slist_add_tail(list, 10);                                  //test case for deleting head ele
    list = delete_head(list);
    assert(list->head==NULL);

    list = slist_add_tail(list, 10);
	list = slist_add_tail(list, 20);
	list = delete_head(list);
	assert(list->head->data==20);
	assert(list->length==1);

}
void test_deletion_at_tail()
{
    Slist s = slist_new();
	Slist *list = &s;
	list = delete_tail(list);

	list = slist_add_tail(list, 30);
	list = delete_tail(list);                                                //test case for deleting tail ele
    assert(list->head==NULL);

    list = slist_add_tail(list, 30);
    list = slist_add_tail(list, 20);
    list = slist_add_tail(list, 10);
	list = slist_add_tail(list, 0);
	list = delete_tail(list);
	assert(list->tail->data==10);
	assert(list->length==3);

}
void test_maximum()
{
    Slist s = slist_new();
	Slist *list = &s;
	assert(maximum(list)==false);

    list = slist_add_tail(list, 10);
    list = slist_add_tail(list, 20);                             //test case for maximum
    list = slist_add_tail(list, 30);
	list = slist_add_tail(list, 40);
	assert(maximum(list)==40);

}

void test_minimum()
{
    Slist s = slist_new();
	Slist *list = &s;
	assert(minimum(list)==false);
                                                                  //test case for minimum
	list = slist_add_tail(list, 0);
    list = slist_add_tail(list, 10);
    list = slist_add_tail(list, 20);
	list = slist_add_tail(list, 30);
	assert(minimum(list)==0);

}

void test_after()
{
    Slist s = slist_new();
	Slist *list = &s;
	//list=add_element_after_element(list,50,10);

	list = slist_add_tail(list, 30);                                       //test case for adding ele after ele
    list = slist_add_tail(list, 40);
    list = slist_add_tail(list, 50);
	list = slist_add_tail(list, 60);

	list=add_element_after_element(list,55,50);
	assert(slist_lookup(list,55));
}

void test_delete_ele()
{
    Slist s = slist_new();
	Slist *list = &s;                                                  //test case for deleting ele
	list=delete_element(list,50);

	list = slist_add_tail(list, 30);
    list = slist_add_tail(list, 40);
    list = slist_add_tail(list, 50);
	list = slist_add_tail(list, 60);
	list=delete_element(list,50);
    assert(!(slist_lookup(list,50)));

}

void test_lunion()
{
    Slist s = slist_new();
	Slist *list = &s;
	list = slist_add_tail(list, 30);
    list = slist_add_tail(list, 40);
    list = slist_add_tail(list, 50);
	list = slist_add_tail(list, 60);

	Slist s1 = slist_new();                                          //test case for union of  2 list
	Slist *list2 = &s1;
	list2 = slist_add_tail(list2, 30);
    list2 = slist_add_tail(list2, 40);
    list2 = slist_add_tail(list2, 50);
	list2 = slist_add_tail(list2, 60);

	Slist s3 = slist_new();
	Slist *list3 = &s3;
	list3=union_list(list,list2,list3);

	assert((list->length)+(list2->length)==list3->length);

}

void test_intersection()
{
    Slist s = slist_new();
	Slist *list = &s;                                           //test case for intersection of 2 list
	list = slist_add_tail(list, 30);
	list = slist_add_tail(list, 30);
    list = slist_add_tail(list, 40);
    list = slist_add_tail(list, 50);
	list = slist_add_tail(list, 60);
	list = slist_add_tail(list, 70);
	list = slist_add_tail(list, 70);


	Slist s1 = slist_new();
	Slist *list2 = &s1;
	list2 = slist_add_tail(list2, 30);
    list2 = slist_add_tail(list2, 40);
    list2 = slist_add_tail(list2, 50);
    list2 = slist_add_tail(list2, 50);
	list2 = slist_add_tail(list2, 60);


	Slist s3 = slist_new();
	Slist *list3 = &s3;
	list3=intersection(list,list2,list3);


	assert(list3->length==4);
}

void test_unique()
{
     Slist s = slist_new();
	Slist *list = &s;                                            //adding unique ele to list
	list = slist_add_tail(list, 30);
	list = slist_add_tail(list, 40);
	list = slist_add_unique_tail(list, 40);
	assert(list->length==2);
	list = slist_add_unique_head(list, 40);
	assert(list->length==2);
}

void test_reverse()
{
    Slist s = slist_new();
	Slist *list2 = &s;
    list2 = slist_add_tail(list2, 30);                   //test case for reversing of list
    list2 = slist_add_tail(list2, 40);
    list2 = slist_add_tail(list2, 50);
    list2 = slist_add_tail(list2, 50);
	list2 = slist_add_tail(list2, 60);
    list2=reverse_list(list2);

}


int main()
{
	test_empty_list();
	test_addition_at_head();
	test_addition_at_tail();
	test_after();                                  //calling test cases
	test_deletion_at_head();
	test_deletion_at_tail();
	test_maximum();
	test_minimum();
	test_delete_ele();
	test_lunion();
	test_intersection();
	test_unique();
	test_reverse();

	return 0;
}


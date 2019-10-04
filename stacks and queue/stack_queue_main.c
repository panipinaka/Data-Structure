#include "queue.h"
#include "stack.h"
#include<stdint.h>
#include<assert.h>
#include<stddef.h>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>



void test_empty_stack()
{
    Stack s = stack_new(5);
	Stack *stk = &s;
	assert(stack_full(stk)==0);
    assert(stack_empty(stk));
}

void test_two_empty_stack()
{
    Stack s = stack_new(2);
	Stack *stk = &s;
	Stack_Result res;
	stk=stack_push(stk,10,&res);
	stk=stack_peek(stk,&res);
	assert(res.status==STACK_OK && res.data==10);
	stk=stack_push(stk,20,&res);
	assert(stack_full(stk)==1);
    stk=stack_push(stk,30,&res);
    assert(res.status==STACK_FULL);
    stk=stack_pop(stk,&res);
    stk=stack_pop(stk,&res);
    stk=stack_pop(stk,&res);
    assert(res.status==STACK_EMPTY);
}
void test_queue()
{
   Queue queue = queue_new(5);
   Queue *q = &queue;

   Queue_Result res;

   q = queue_add(q,10,&res);
   assert(q->count == 1);
   assert(q->data[q->head-1] == 10);
   q = queue_add(q,20,&res);
   q = queue_add(q,30,&res);
   assert(q->data[q->head-1]==30);
   assert(q->data[q->tail]==10);

   q = queue_delete(q,&res);
   assert(res.data==10);
   assert(q->data[q->tail]==20);
}



//1.balancing of symbols
void balancing_symbols(char c[10])
{

	Stack s = stack_new(5);
	Stack *stk = &s;

	Stack_Result res;
	for(int i=0;i<strlen(c);i++)
	{
		if(c[i] == '[' || c[i] == '(' || c[i] == '{')
		{
			stk = stack_push(stk,c[i],&res);
			continue;
		}
		else if(c[i] == ']' && stk->data[stk->top]=='[')
		{
			stk = stack_pop(stk,&res);
			continue;
		}
		else if(c[i] == ')' && stk->data[stk->top]=='(')
		{
			stk = stack_pop(stk,&res);
			continue;
		}
		else if(c[i] == '}' && stk->data[stk->top]=='{')
		{
			stk = stack_pop(stk,&res);
			continue;
		}
		else
		{
			assert(stk->top!=-1);
		}

	}
	stk = stack_peek(stk,&res);
	assert(stk->top == -1);


}

//2.postfix evaluation
int postfix(char p[20])
{
    int ele;
	Stack s = stack_new(5);
	Stack *stk = &s;

	Stack_Result res;
	for(int i=0;i<strlen(p);i++)
    {
        if(isdigit(p[i]))
        {

            stk=stack_push(stk,p[i]-'0',&res);
        }
        else
        {
            int a1,a2;
            int c=0;
            a2 = stk->data[stk->top];
            stk = stack_pop(stk,&res);
            a1 = stk->data[stk->top];
            stk = stack_pop(stk,&res);
            if(p[i]=='+')
            {
            c = a1  + a2 ;
            }
            else if(p[i]=='-')
            {
                c = a1 - a2;
            }
            else if(p[i]=='*')
            {
                c = a1 * a2;
            }
            else if(p[i]=='/')
            {
                c = a1/a2;
            }

            stk = stack_push(stk,c,&res);


        }
    }

stk = stack_peek(stk,&res);
assert(res.data==-11);

}



//4.stacks using queue

void queue_stack()
{
    Queue queue = queue_new(5);
    Queue *q = &queue;
    Queue_Result res;

    q = queue_add(q,10,&res);
    q = queue_add(q,20,&res);
    q = queue_add(q,30,&res);
    assert(q->data[q->tail]==10);
    while(q->count > 1) {
        q = queue_delete(q,&res);
        q = queue_add(q,res.data,&res);
        --q->count;
        }
    assert(q->data[q->tail]==30);
    q = queue_delete(q,&res);
}



//5.stack contains element x or not with the help of queue
void element_x()
{
    //let element to find be x
    int x = 10;
    int flag=0;
    int count=0;
    Stack s = stack_new(5);
	Stack *stk = &s;
	Stack_Result sres;

	Queue queue = queue_new(5);
    Queue *q = &queue;
    Queue_Result qres;

    stk=stack_push(stk,10,&sres);
    stk=stack_push(stk,20,&sres);
    stk=stack_push(stk,30,&sres);
    stk=stack_push(stk,40,&sres);
    stk=stack_push(stk,50,&sres);
    while(stk->top>-1){
        stk=stack_pop(stk,&sres);
        q = queue_add(q,sres.data,&qres);
        count=q->count;
        while(count > 1) {
            q = queue_delete(q,&qres);
            q = queue_add(q,qres.data,&qres);
            --count;
        }
        if(sres.data==x)
        {
            flag=1;
            break;
        }
        else
        {
            continue;
        }
    }
    while(q->count>0){
        q = queue_delete(q,&qres);
        stk=stack_push(stk,qres.data,&sres);
    }
    assert(stk->data[stk->top]==50);
    assert(flag==1);

}


int main()
{
//stack
    test_empty_stack();
    test_two_empty_stack();
//queue
    test_queue();
//1.balancing of symbols
	char c[10] = "}((]";
	char c1[20] = "[({})]";
	balancing_symbols(c1);
//2.postfix evaluation
	char p[20]="2563*-+";
	postfix(p);
//3.job scheduling

//4.stacks using queue
    queue_stack();
//5.stack contains element x or not with the help of queue
    element_x();
//6.
    return 0;
}

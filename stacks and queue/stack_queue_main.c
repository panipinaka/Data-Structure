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
int balancing_symbols(char c[10])
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

	return 0;
}

//2.postfix evaluation
int postfix(char p[20])
{
	Stack s = stack_new(5);
	Stack *stk = &s;

	Stack_Result res;
	for(int i=0;i<strlen(p);i++)
    {

        printf("%d",p[i]);
        if(isdigit(p[i]))
        {
            //printf("%d",p[i]);
            stk=stack_push(stk,p[i],&res);
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
//printf("%d",res.data);
assert(res.data=='11');

}


int main()
{
//stacks
    test_empty_stack();
    test_two_empty_stack();

//1.balancing of symbols
	char c[10] = "}((]";
	char c1[20] = "[({})]";
//balancing_symbols(c);
	balancing_symbols(c1);
//2.postfix evaluation
	//char p[20]="235*+6-";
	//postfix(p);
//queue
    test_queue();
//4.stacks using queue

    return 0;


}

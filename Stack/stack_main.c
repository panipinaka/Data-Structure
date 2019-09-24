#include "stack.h"
#include<stdint.h>
#include<assert.h>
#include<stddef.h>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>

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

int postfix(char p[20])
{
	Stack s = stack_new(5);
	Stack *stk = &s;

	Stack_Result res;
	for(int i=0;i<strlen(p);i++)
    {
        if(isdigit(p[i]))
        {
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
assert(res.data=='6');

}
void test_empty_stack()
{
    Stack s = stack_new(5);
	Stack *stk = &s;
	assert(stack_full(stk)==0);
    assert(stack_empty(stk));
}

void test_two_empty_stack()
{


}

int main()
{
    test_empty_stack();
    test_two_empty_stack()
	//char c[10] = "}((]";
	//char c1[20] = "[({})]";
    //balancing_symbols(c);
	//balancing_symbols(c1);
	//char p[20]="423+1*+3-";
	//postfix(p);
	return 0;

}

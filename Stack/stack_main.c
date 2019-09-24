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
	//char c[10] = d;
	for(int i=0;i<strlen(c);i++)
	{
		//printf("%c",c[i]);
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
			assert(stk->top==2 || stk->top == -1);
			return 0;//if first symbol is },)or] then it will come out of function.
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
            //printf("houda");
        }
        else
        {
            //printf("is it here");
            char a,b;
            int c=0;
            a = stk->data[stk->top];
            stk = stack_pop(stk,&res);
            b = stk->data[stk->top];
            stk = stack_pop(stk,&res);
            if(p[i]=='+')
            {
                //printf("comoing here");
            c = a -'0' + b - '0';
            //printf("%d",c);
            }
            else if(p[i]=='-')
            {
                c = (b-'0') - (a-'0');
            }
            else if(p[i]=='*')
            {
                c = (b-'0') * (a-'0');
            }
            else if(p[i]=='/')
            {
                c = (b-'0')/(a-'0');
            }
            //char buffer[2];
            //itoa(c,buffer,10);
            //char pf = c+'0';
           //printf("%c",buffer[1]);

            char pf = c+'0';
            stk = stack_push(stk,pf,&res);


            //assert(res.data == '11');
        }
    }

//printf("coming here");
stk = stack_peek(stk,&res);
assert(res.data=='6');
//printf(stk->data[stk->top]);

}

int main()
{
	char c[10] = "}((]";
	char c1[20] = "[({})]";
	//printf("ajith");
    balancing_symbols(c);
	balancing_symbols(c1);

    //char p[20]="6523+8*+3+*";
	char p[20]="423+1*+3-";
	postfix(p);
	return 0;

}

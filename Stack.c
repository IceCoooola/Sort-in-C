#include"stack.h"
/*
typedef struct Stack
{
	StackDataType* data;
	int top;
	int capacity;
} Stack;
*/
void BuyData(Stack* s)
{
	assert(s);
	StackDataType* temp = realloc(s->data, sizeof(StackDataType) * (s->capacity * 2));
	if (temp)
	{
		s->data = temp;
		s->capacity *= 2;
	}
	else
	{
		printf("realloc failed\n");
		exit(-1);
	}
}

void InitStack(Stack* s)
{
	assert(s);
	s->data = (StackDataType*)malloc(sizeof(StackDataType) * 3);
	s->top = 0;
	s->capacity = 3;
}
void PushStack(Stack* s, StackDataType x)
{
	assert(s);
	if (s->top == s->capacity)
	{
		BuyData(s);
	}
	s->data[s->top] = x;
	s->top++;
}
void PopStack(Stack* s)
{
	assert(s && (s->top != 0));
	s->top--;
}
void DestoryStack(Stack* s)
{
	free(s->data);
	s->data = NULL;
	s->top = 0;
	s->capacity = 0;
}

StackDataType TopStack(Stack* s)
{
	return s->data[s->top - 1];
}
bool IsEmptyStack(Stack* s)
{
	return(s->top == 0);
}
int StackSize(Stack* s)
{
	return s->top;
}

#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdbool.h>
#include<assert.h>
#include<malloc.h>
#define StackDataType int

typedef struct Stack
{
	StackDataType* data;
	int top;
	int capacity;
} Stack;

void InitStack(Stack* s);
void PushStack(Stack* s, StackDataType x);
void PopStack(Stack* s);
void DestoryStack(Stack* s);
StackDataType TopStack(Stack* s);
bool IsEmptyStack(Stack* s);
int StackSize(Stack* s);

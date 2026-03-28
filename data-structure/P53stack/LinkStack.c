#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>

//节点定义
typedef struct StackNode
{
	int data;
	struct StackNode* next;
}StackNode;

//栈定义
typedef struct LinkStack
{
	StackNode* top;
}LinkStack;

//初始化栈
void initStack(LinkStack *s)
{
	s->top = NULL;
}

//判断栈空
int isempty(LinkStack *s )
{
	return s->top = NULL;
}

//入栈
void push (LinkStack *s , int data)
{
	StackNode* newNode = (StackNode*)malloc(sizeof(StackNode));
	newNode->data = data;
	newNode->next = s->top;
	s->top = newNode;
}

//出栈
void popStack(LinkStack* s)
{
	StackNode* p = s->top;
	s->top = s->top->next;
	free(p);
}


//打印栈
void printStack(LinkStack* s)
{
	StackNode* p = s->top;
	while (p != NULL)
	{
		printf("%d ", p->data);
		p = p->next;
	}
}

//查看栈顶元素
void findtopelem(LinkStack* s)
{
	printf("栈顶元素是%d", s->top->data);
}

int main()
{
	LinkStack s;
	initStack(&s);
	int a = isempty(&s);
	push(&s, 10);
	push(&s, 20);
	push(&s, 30);
	push(&s, 40);
	printStack(&s);
	findtopelem(&s);
	printf("\n");
	popStack(&s);
	printStack(&s);
	findtopelem(&s);
}

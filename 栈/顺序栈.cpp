/*
    栈的顺序存储
    //初始化顺序栈
    Status InitStack(SqStack* S)
    //清空顺序栈
    Status ClearStack(SqStack* S)
    //栈是否为空
    Status StackEmpty(SqStack S)
    //栈长度
    int StackLength(SqStack S)
    //栈顶元素
    Status GetTop(SqStack S, SELemType* e)
    //入栈
    Status Push(SqStack* S, SELemType e)
    //出栈
    Status Pop(SqStack* S, SELemType* e)
    //打印顺序栈
    Status StackTraverse(SqStack S)
*/

#include<iostream>
using namespace std;

#define OK 1
#define ERROR 0
#define MAX_SIZE 20

typedef int Status;
typedef int SELemType;

typedef struct {
	SELemType data[MAX_SIZE];
	int top;
}SqStack;

//初始化顺序栈
Status InitStack(SqStack* S) {
	S->top = -1;
	return OK;
}

//清空顺序栈
Status ClearStack(SqStack* S) {
	S->top = -1;
	return OK;
}

//栈是否为空
Status StackEmpty(SqStack S) {
	if (S.top == -1) {
		return true;
	}
	else {
		return false;
	}
}

//栈长度
int StackLength(SqStack S) {
	return S.top + 1;
}

//栈顶元素
Status GetTop(SqStack S, SELemType* e) {
	if (S.top == -1) {
		return ERROR;
	}
	else {
		*e = S.data[S.top];
	}
	return OK;
}

//入栈
Status Push(SqStack* S, SELemType e) {
	if (S->top == MAX_SIZE - 1) {
		return ERROR;
	}
	S->top++;
	S->data[S->top] = e;
	return OK;
}

//出栈
Status Pop(SqStack* S, SELemType* e) {
	if (S->top == -1) {
		return ERROR;
	}
	*e = S->data[S->top];
	S->top--;
	return OK;
}

//打印顺序栈
Status StackTraverse(SqStack S) {
	int i = 0;
	while (i <= S.top) {
		cout << S.data[++i] << ' ';
	}
	return OK;
}

int main()
{
	int j;
	SqStack s;
	int e;
	if (InitStack(&s) == OK)
		for (j = 1; j <= 10; j++)
			Push(&s, j);
	printf("栈中元素依次为：");
	StackTraverse(s);
	Pop(&s, &e);
	printf("弹出的栈顶元素 e=%d\n", e);
	printf("栈空否：%d(1:空 0:否)\n", StackEmpty(s));
	GetTop(s, &e);
	printf("栈顶元素 e=%d 栈的长度为%d\n", e, StackLength(s));
	ClearStack(&s);
	printf("清空栈后，栈空否：%d(1:空 0:否)\n", StackEmpty(s));

	return 0;
}


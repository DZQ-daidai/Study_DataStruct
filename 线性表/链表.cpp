/*
    线性表的链式存储
    //初始化链表
    Status InitList(LinkList* L)
    //判断链表是否为空
    Status ListEmpty(LinkList& L)
    //清空链表
    Status ClearList(LinkList* L)
    //链表长度
    int ListLength(LinkList& L)
    //用e返回L中第i个数据元素的值
    Status GetElem(LinkList& L, int i, ElemType* e)
    //返回第1个为e的数据元素的位置
    int LocateElem(LinkList L, ElemType e)
    //在第i个位置之前插入新的数据元素e
    Status ListInsert(LinkList* L, int i, ElemType e)
    //删除第i个数据元素，并用e返回其值
    Status ListDelete(LinkList* L, int i, ElemType* e)
    //打印链表
    Status ListTraverse(LinkList L)
    //头插法插入随机数据
    void CreateListHead(LinkList* L, int n)
    //尾插法插入随机数据
    void CreateListTail(LinkList* L, int n)
*/

#include<iostream>
using namespace std;

#define OK 1
#define ERROR 0

typedef int Status;

typedef int ElemType;

typedef struct Node {
	ElemType data;
	struct Node* next;
}Node;

typedef struct Node* LinkList;

//初始化链表
Status InitList(LinkList* L) {
	*L = new Node;
	if (!(*L)) {
		return ERROR;
	}
	(*L)->next = NULL;
	return OK;
}

//判断链表是否为空
Status ListEmpty(LinkList& L) {
	if (L->next) {
		return false;
	}
	else {
		return true;
	}
}

//清空链表
Status ClearList(LinkList* L) {
	LinkList p, q;
	p = (*L)->next;
	while (p) {
		q = p->next;
		free(p);
		p = q;
	}
	(*L)->next = NULL;
	return OK;
}

//链表长度
int ListLength(LinkList& L) {
	int i = 0;
	LinkList p = L->next;
	while (p)
	{
		++i;
		p = p->next;
	}
	return i;
}

//用e返回L中第i个数据元素的值
Status GetElem(LinkList& L, int i, ElemType* e) {
	LinkList p;
	p = L->next;
	int j = 1;
	while (p && j<i)
	{
		p = p->next;
		++j;
	}
	if (!p || j > i) {
		return ERROR;
	}
	*e = p->data;
	return OK;
}

//返回第1个为e的数据元素的位置
int LocateElem(LinkList L, ElemType e) {
	int i = 0;
	LinkList p = L->next;
	while (p) {
		++i;
		if (p->data == e) {
			return i;
		}
		p = p->next;
	}
	return 0;
}

//在第i个位置之前插入新的数据元素e
Status ListInsert(LinkList* L, int i, ElemType e) {
	int j = 1;
	LinkList p, s;
	p = *L;
	while (p && j < i) {
		p = p->next;
		++j;
	}
	if (!p || j > i) {
		return ERROR;
	}
	s = new Node;
	s->data = e;
	s->next = p->next;
	p->next = s;
	return OK;
}

//删除第i个数据元素，并用e返回其值
Status ListDelete(LinkList* L, int i, ElemType* e) {
	LinkList p, q;
	p = *L;
	int j = 1;
	while (p->next && j < i) {
		p = p->next;
		++j;
	}
	if (!(p->next) || j > i) {
		return ERROR;
	}
	q = p->next;
	p->next = q->next;
	*e = q->data;
	free(q);
	return OK;
}

//打印链表
Status ListTraverse(LinkList L) {
	LinkList p = L->next;
	while (p) {
		cout << p->data << ' ';
		p = p->next;
	}
	return OK;
}

//头插法插入随机数据
void CreateListHead(LinkList* L, int n) {
	LinkList p;
	int i;
	srand(time_t(0));
	*L = new Node;
	(*L)->next = NULL;
	for (i = 0; i < n; ++i) {
		p = new Node;
		p->data = rand() % 100 + 1;
		p->next = (*L)->next;
		(*L)->next = p;
	}
}

//尾插法插入随机数据
void CreateListTail(LinkList* L, int n) {
	LinkList p, r;
	int i;
	srand(time_t(0));
	*L = new Node;
	r = *L;
	for (i = 0; i < n; ++i) {
		p = new Node;
		p->data = rand() % 100 + 1;
		r->next = p;
		r = p;
	}
	r->next = NULL;
}

int main()
{
	LinkList L;
	ElemType e;
	Status i;
	int j, k;
	i = InitList(&L);
	printf("初始化L后：ListLength(L)=%d\n", ListLength(L));
	for (j = 1; j <= 5; j++)
		i = ListInsert(&L, 1, j);
	printf("在L的表头依次插入1～5后：L.data=");
	ListTraverse(L);

	printf("ListLength(L)=%d \n", ListLength(L));
	i = ListEmpty(L);
	printf("L是否空：i=%d(1:是 0:否)\n", i);

	i = ClearList(&L);
	printf("清空L后：ListLength(L)=%d\n", ListLength(L));
	i = ListEmpty(L);
	printf("L是否空：i=%d(1:是 0:否)\n", i);

	for (j = 1; j <= 10; j++)
		ListInsert(&L, j, j);
	printf("在L的表尾依次插入1～10后：L.data=");
	ListTraverse(L);

	printf("ListLength(L)=%d \n", ListLength(L));

	ListInsert(&L, 1, 0);
	printf("在L的表头插入0后：L.data=");
	ListTraverse(L);
	printf("ListLength(L)=%d \n", ListLength(L));

	GetElem(L, 5, &e);
	printf("第5个元素的值为：%d\n", e);
	for (j = 3; j <= 4; j++)
	{
		k = LocateElem(L, j);
		if (k)
			printf("第%d个元素的值为%d\n", k, j);
		else
			printf("没有值为%d的元素\n", j);
	}


	k = ListLength(L); /* k为表长 */
	for (j = k + 1; j >= k; j--)
	{
		i = ListDelete(&L, j, &e); /* 删除第j个数据 */
		if (i == ERROR)
			printf("删除第%d个数据失败\n", j);
		else
			printf("删除第%d个的元素值为：%d\n", j, e);
	}
	printf("依次输出L的元素：");
	ListTraverse(L);

	j = 5;
	ListDelete(&L, j, &e); /* 删除第5个数据 */
	printf("删除第%d个的元素值为：%d\n", j, e);

	printf("依次输出L的元素：");
	ListTraverse(L);

	i = ClearList(&L);
	printf("\n清空L后：ListLength(L)=%d\n", ListLength(L));
	CreateListHead(&L, 20);
	printf("整体创建L的元素(头插法)：");
	ListTraverse(L);

	i = ClearList(&L);
	printf("\n删除L后：ListLength(L)=%d\n", ListLength(L));
	CreateListTail(&L, 20);
	printf("整体创建L的元素(尾插法)：");
	ListTraverse(L);


	return 0;
}
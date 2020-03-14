/*
    线性表的顺序存储

    初始化顺序表
    Status InitList(SqList* L)
    判断顺序表是否为空
    Status ListEmpty(SqList& L)
    清空顺序表
    Status ClearList(SqList* L)
    查询顺序表中元素个数
    int ListLength(SqList& L)
    用e返回L中第i个数据元素的值
    Status GetElem(SqList& L, int i, ElemType* e)
    返回第1个为e的数据元素的位置
    int LocateElem(SqList& L, ElemType e)
    在第i个位置之前插入新的数据元素e，L的长度+1
    Status ListInsert(SqList* L, int i, ElemType e)
    删除第i个数据元素，并用e返回其值，L的长度减1
    Status ListDelete(SqList* L, int i, ElemType* e)
    打印顺序表
    Status ListTraverse(SqList& L)
*/

#include <iostream>
using namespace std;

#define OK 1
#define ERROR 0

#define MAX_SIZE 20	//存储空间初始分配量

typedef int Status;	//Status是函数的类型，其值是函数结果状态代码
typedef int ElemType;	//顺序表数据类型

typedef struct {
	ElemType data[MAX_SIZE];	//数组存储数据元素
	int length;					//存储当前长度
}SqList;

//初始化顺序表
Status InitList(SqList* L) {
	L->length = 0;
	return OK;
}

//判断顺序表是否为空
Status ListEmpty(SqList& L) {
	if (L.length == 0) {
		return true;
	}
	else {
		return false;
	}
}

//清空顺序表
Status ClearList(SqList* L) {
	L->length = 0;
	return OK;
}

//查询顺序表中元素个数
int ListLength(SqList& L) {
	return L.length;
}

//用e返回L中第i个数据元素的值
Status GetElem(SqList& L, int i, ElemType* e) {
	if (L.length == 0 || i<1 || i>L.length) {
		return ERROR;
	}
	*e = L.data[i - 1];
	return OK;
}

//返回第1个为e的数据元素的位置
int LocateElem(SqList& L, ElemType e) {
	if (L.length == 0) {
		return 0;
	}
	int i;
	for (i = 0; i < L.length; ++i) {
		if (L.data[i] == e) {
			break;
		}
	}
	if (i >= L.length) {
		return 0;
	}
	return i + 1;
}

//在第i个位置之前插入新的数据元素e，L的长度+1
Status ListInsert(SqList* L, int i, ElemType e) {
	if (L->length == MAX_SIZE) {
		return ERROR;
	}
	if (i<1 || i>L->length + 1) {
		return ERROR;
	}
	if (i <= L->length) {
		for (int k = L->length - 1; k > i - 1; --k) {
			L->data[k + 1] = L->data[k];
		}
	}
	L->data[i - 1] = e;
	++L->length;
	return OK;
}

//删除第i个数据元素，并用e返回其值，L的长度减1
Status ListDelete(SqList* L, int i, ElemType* e) {
	if (L->length == 0) {
		return ERROR;
	}
	if (i<1 || i>L->length) {
		return ERROR;
	}
	*e = L->data[i - 1];
	if (i < L->length) {
		for (int k = i; k < L->length; ++k) {
			L->data[k - 1] = L->data[k];
		}
	}
	--L->length;
	return OK;
}

//打印顺序表
Status ListTraverse(SqList& L) {
	if (L.length == 0) {
		return ERROR;
	}
	for (int i = 0; i < L.length; ++i) {
		cout << L.data[i] << ' ';
	}
	return OK;
}


int main()
{
	SqList L;

	ElemType e;
	Status i;
	int j, k;
	i = InitList(&L);
	printf("初始化L后：L.length=%d\n", L.length);
	for (j = 1; j <= 5; j++)
		i = ListInsert(&L, 1, j);
	printf("在L的表头依次插入1～5后：L.data=");
	ListTraverse(L);

	printf("L.length=%d \n", L.length);
	i = ListEmpty(L);
	printf("L是否空：i=%d(1:是 0:否)\n", i);

	i = ClearList(&L);
	printf("清空L后：L.length=%d\n", L.length);
	i = ListEmpty(L);
	printf("L是否空：i=%d(1:是 0:否)\n", i);

	for (j = 1; j <= 10; j++)
		ListInsert(&L, j, j);
	printf("在L的表尾依次插入1～10后：L.data=");
	ListTraverse(L);

	printf("L.length=%d \n", L.length);

	ListInsert(&L, 1, 0);
	printf("在L的表头插入0后：L.data=");
	ListTraverse(L);
	printf("L.length=%d \n", L.length);

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

	return 0;
}

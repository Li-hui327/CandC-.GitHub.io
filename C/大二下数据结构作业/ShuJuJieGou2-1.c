#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100
#define OK 1;
#define False 0;
typedef int ElemType;	//自定义线性表数据类型 
typedef struct	//定义线性表 
{
	ElemType elem[MAXSIZE];
	int last;
}SeqList;
void InitialSList(SeqList *L)	//初始化线性表 
{
	int i=0;
	printf("Please input int Xing numbers,and input -1 means endinput: \n");
	do {
		scanf("%d",&(L->elem[i]));
		i++;
	} while((L->elem[i-1])!=-1);
	L->last=i-1;
}
int SListDelXY(SeqList *L,ElemType x, ElemType y)	//函数实现删除线性表中元素值介于x和y之间的元素 
{
	if(L->last)	//判断单链表是否为空表 
	{
		int i;
		for(i=0;i<(L->last);i++)
		{
			if((L->elem[i])>x && (L->elem[i])<y)
			{
				int j;
				for(j=i;j<(L->last-1);j++)
					L->elem[j]=L->elem[j+1];
				i--;
				(L->last)--;
			}
		}
		return OK;
	}
	else
		return False;
}
void printSList(SeqList L)	//打印线性表 
{
	int i;
	for(i=0;i<(L.last);i++)
	{
		printf("%d ",L.elem[i]);
	}
	putchar('\n');
}
int main()
{
	SeqList a;
	InitialSList(&a);
	printf("Please input two numbers,and the first one < the next: \n");
	int x,y;
	scanf("%d %d",&x,&y);
	if(SListDelXY(&a,x,y))
		printSList(a);
	else
		printf("ERROR! \n");
	system("pause");
	return 0;
}

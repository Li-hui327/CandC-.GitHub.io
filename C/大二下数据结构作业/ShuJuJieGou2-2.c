#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100
#define OK 1;
#define False 0;
//还需有待改进 
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
int AdjustSList(SeqList *L)	//函数实现将线性表中的奇数元素排在前面，偶数元素排在后面 
{
	if(L->last)
	{
		int count=0,i;
		for(i=0;i<(L->last);i++)
		{
			if((L->elem[i])%2)
			{
				ElemType t=L->elem[i];
				L->elem[i]=L->elem[count];
				L->elem[count]=t;
				count++;
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
	if(AdjustSList(&a))
		printSList(a);
	else
		printf("ERRPR! \n");
	system("pause");
	return 0;
}

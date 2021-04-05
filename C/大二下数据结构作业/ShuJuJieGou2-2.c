#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100
#define OK 1;
#define False 0;
//�����д��Ľ� 
typedef int ElemType;	//�Զ������Ա��������� 
typedef struct	//�������Ա� 
{
	ElemType elem[MAXSIZE];
	int last;
}SeqList;
void InitialSList(SeqList *L)	//��ʼ�����Ա� 
{
	int i=0;
	printf("Please input int Xing numbers,and input -1 means endinput: \n");
	do {
		scanf("%d",&(L->elem[i]));
		i++;
	} while((L->elem[i-1])!=-1);
	L->last=i-1;
}
int AdjustSList(SeqList *L)	//����ʵ�ֽ����Ա��е�����Ԫ������ǰ�棬ż��Ԫ�����ں��� 
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
void printSList(SeqList L)	//��ӡ���Ա� 
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

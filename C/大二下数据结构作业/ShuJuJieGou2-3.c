#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100
#define OK 1;
#define False 0;
//还需有待改进 
typedef int ElemType;	//自定义线性表数据类型 
typedef struct Node	//定义线性表为单链表 
{
	ElemType data;
	struct Node * next;
}Node, *LinkList;
void InitList(LinkList *L)	//初始化单链表 
{
	*L=(LinkList)malloc(sizeof(Node));
	(*L)->next=NULL;
}
void CFTail(LinkList L)	//使用尾插法建立单链表 
{
	Node *r,*s;
	int i=1;
	r=L;
	ElemType c;
	printf("Please input int Xing numbers,and input -1 means endinput: \n");
	do {
		scanf("%d",&c);
		if(c!=-1)
		{
			s=(Node *)malloc(sizeof(Node));
			s->data=c;
			r->next=s;
			r=s;
		}
		else
		{
			i=0;
			r->next=NULL;
		}
	} while(i);
}
int ListDelRange(LinkList L, int mink, int maxk)	//函数实现删除表中所有大于mink且小于maxk的元素 
{
	Node *r,*s;
	r=L;
	s=L;
	if(r->next!=NULL)	//判断是否为空表 
	{
		r=r->next;
		for(;r->next!=NULL;r=r->next)
		{
			if((r->data)>mink && (r->data)<maxk)
			{
				s->next=r->next;
				r=s;
			}
			else
				s=r;
		}
		if((r->data)>mink && (r->data)<maxk)
		{
			s->next=r->next;
		}
		return OK;
	}	
	else
		return False;
}
void printLList(LinkList L)	//打印单链表 
{
	Node *r;
	r=L->next;
	while(r->next!=NULL)
	{
		printf("%d ",r->data);
		r=r->next;
	}
	printf("%d ",r->data);
	putchar('\n');
}
int main()
{
	LinkList L;
	InitList(&L);
	CFTail(L);
	printf("Please input two numbers,and the first one < the next: \n");
	int mink,maxk;
	scanf("%d %d",&mink,&maxk);
	if(ListDelRange(L,mink,maxk))
		printLList(L);
	else
		printf("ERROR! \n");
	free(L);
	system("pause");
	return 0;
}

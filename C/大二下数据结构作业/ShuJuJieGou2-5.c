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

void InitCLinkList(LinkList *CL)	//初始化循环单链表 
{
	*CL=(LinkList)malloc(sizeof(Node));
	(*CL)->next=*CL;
}

void CCLinkList(LinkList CL)	//利用尾插法建立循环单链表 
{
	Node *r,*s;
	ElemType c;
	r=CL;
	printf("Please input int Xing numbers,and input -1 means endinput: \n");
	scanf("%d",&c);
	while(c!=-1) 
	{
		s=(Node *)malloc(sizeof(Node));
		s->data=c;
		r->next=s;
		r=s;
		scanf("%d",&c);
	}
	r->next=CL;
}

int DelPrior(Node *s)	//函数实现删除s所指节点的前驱节点 
{
	if(s)	//判断是否为空循环链表 
	{
		Node *r;
		r=s->next;
		for(;(r->next->next)!=s;)
			r=r->next;
		r->next=s;
		return OK;
	}
	else
		return False;
}

Node * FindNum(LinkList CL,ElemType c)	//函数实现寻找循环链表中指定数的指针 
{
	Node *r;
	r=CL;
	for(;(r->next)!=CL;)
	{
		r=r->next;
		if((r->data)!=c)
			continue;
		else
			break;
	}
	return r;
}

void printLList(LinkList CL)	//打印单链表 
{
	Node *r;
	r=CL->next;
	while((r->next)!=CL)
	{
		printf("%d ",r->data);
		r=r->next;
	}
	printf("%d ",r->data);
	putchar('\n');
}

int main()
{
	LinkList CL;
	InitCLinkList(&CL);
	CCLinkList(CL);
	printf("Please input the number's later number you want to delete: \n");
	ElemType c;
	scanf("%d",&c);
	if(DelPrior(FindNum(CL,c)))
		printLList(CL);
	else
		printf("ERROR! \n");
	system("pause");
	return 0;
}

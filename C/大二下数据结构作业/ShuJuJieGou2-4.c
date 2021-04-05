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
LinkList  MergeLinkListR(LinkList LA, LinkList LB)	//使用头插法合并线性表 
{
	Node *r,*s,*t;
	LinkList LC;
	r=LA->next;
	s=LB->next;
	LC=LA;
	LC->next=NULL;
	for(;r!=NULL && s!=NULL;)
	{
		if((r->data)<(s->data))
		{
			t=(Node *)malloc(sizeof(Node));
			t->data=r->data;
			t->next=LC->next;
			LC->next=t;
			r=r->next;
		}
		else
		{
			t=(Node *)malloc(sizeof(Node));
			t->data=s->data;
			t->next=LC->next;
			LC->next=t;
			s=s->next;
		}
	}
	if(r)
	{
		for(;r!=NULL;)
		{
			t=(Node *)malloc(sizeof(Node));
			t->data=r->data;
			t->next=LC->next;
			LC->next=t;
			r=r->next;
		}
	}
	else
	{
		for(;s!=NULL;)
		{
			t=(Node *)malloc(sizeof(Node));
			t->data=s->data;
			t->next=LC->next;
			LC->next=t;
			s=s->next;
		}
	}
	return LC;
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
	LinkList LA,LB;
	InitList(&LA);
	CFTail(LA);
	InitList(&LB);
	CFTail(LB);
	printLList(MergeLinkListR(LA,LB));
	system("pause");
	return 0;
}

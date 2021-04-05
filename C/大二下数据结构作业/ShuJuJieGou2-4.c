#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100
#define OK 1;
#define False 0;
//�����д��Ľ� 
typedef int ElemType;	//�Զ������Ա��������� 
typedef struct Node	//�������Ա�Ϊ������ 
{
	ElemType data;
	struct Node * next;
}Node, *LinkList;
void InitList(LinkList *L)	//��ʼ�������� 
{
	*L=(LinkList)malloc(sizeof(Node));
	(*L)->next=NULL;
}
void CFTail(LinkList L)	//ʹ��β�巨���������� 
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
LinkList  MergeLinkListR(LinkList LA, LinkList LB)	//ʹ��ͷ�巨�ϲ����Ա� 
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
void printLList(LinkList L)	//��ӡ������ 
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

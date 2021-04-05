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

void InitCLinkList(LinkList *CL)	//��ʼ��ѭ�������� 
{
	*CL=(LinkList)malloc(sizeof(Node));
	(*CL)->next=*CL;
}

void CCLinkList(LinkList CL)	//����β�巨����ѭ�������� 
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

int DelPrior(Node *s)	//����ʵ��ɾ��s��ָ�ڵ��ǰ���ڵ� 
{
	if(s)	//�ж��Ƿ�Ϊ��ѭ������ 
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

Node * FindNum(LinkList CL,ElemType c)	//����ʵ��Ѱ��ѭ��������ָ������ָ�� 
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

void printLList(LinkList CL)	//��ӡ������ 
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

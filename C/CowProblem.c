/*
��һͷĸţ����ÿ�������һͷСĸţ��ÿͷСĸţ�ӵ��ĸ���ͷ��ʼ��ÿ�����Ҳ��һͷСĸţ��
����ʵ���ڵ�n���ʱ�򣬹��ж���ͷĸţ��
*/
#include <stdio.h>
#include <stdlib.h>
int num(int x)
{
    int sum=x;
    if(x<=4)
    return x;
    else
    {
        return x+num(x-4);
    }
    
}
int main()
{   int number[10],i=-1;
    do{
        i++;
        scanf("%d",&number[i]);
    }   while(number[i]!=0);
    printf("��Ӧ��ĸţ�����ֱ�Ϊ:\n");
    for(i=0;number[i]!=0;i++)
    printf("%d\n",num(number[i]));
    system("pause");
    return 0;
}
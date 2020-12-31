/*
有一头母牛，它每年年初生一头小母牛。每头小母牛从第四个年头开始，每年年初也生一头小母牛。
请编程实现在第n年的时候，共有多少头母牛？
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
    printf("对应的母牛总数分别为:\n");
    for(i=0;number[i]!=0;i++)
    printf("%d\n",num(number[i]));
    system("pause");
    return 0;
}
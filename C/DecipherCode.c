/*
Ҫ��"China"������룬��������ǣ���ԭ����ĸ����ĵ�4����ĸ����ԭ������ĸ��

���磬��ĸ"A"�����4����ĸ��"E"��"E"����"A"����ˣ�"China"Ӧ��Ϊ"Glmre"��

���һ�����ø���ֵ�ķ���ʹcl��c2��c3��c4��c5���������ֵ�ֱ�Ϊ����C������h������i������n������a����
�������㣬ʹc1��c2��c3��c4��c5�ֱ��Ϊ��G������l������m������r������e�����������  
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{   char str[20];
    gets(str);
    printf("���ܺ��");
    puts(str);
    for(int i=0;i<strlen(str);i++)
    str[i]+=4;
    puts(str);
    system ("pause");
    return 0;
}
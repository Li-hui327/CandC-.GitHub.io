/*
 * 绘制sin函数在0~2pi之间图象
 */
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
 
#define PI 3.14
 
int main ( void )
{
	double r;
	int cols,c,i,x;
    printf("请输入要打印的行数: ");
    scanf("%d",&x);
	for ( r=1; r>0; r-=0.1 )
	{
		
        for(i=0;i<x;i++)
        {   cols = asin ( r ) * 10;
		    for ( c=0; c<(i>0? 2*cols:cols); c++ )
			    printf ( " " );
		    printf ( "*" );
            c=cols;
		    for ( ; c<PI*10-cols-1; c++ )
			    printf ( " " );
		    printf ( "*" );
        }
		printf ( "\n" );
	}
 
 /*
	for ( r=0; r>=-1; r-=0.1 )
	{
		cols = ( PI - asin(r) ) * 10;
 
		for ( c=0; c<cols+2; c++ )
			printf ( " " );
		printf ( "*" );
 
		for ( ; c<10*(2*PI+asin(r))+1; c++ )
			printf ( " " );
		printf ( "*" );
 
		printf ( "\n" );
	}           */
    system ("pause");
	return 0;
}
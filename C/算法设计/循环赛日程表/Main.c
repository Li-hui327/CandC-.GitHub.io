#include <stdio.h>
#include <stdlib.h>
#define N 20

void Merge(int a[][N],int n) {    //合并算法
    int m=n/2;
    for(int i=0;i<m;i++)
        for(int j=0;j<m;j++) {
            a[i][j+m]=a[i][j]+m;    //左上角->右上角
            a[i+m][j]=a[i][j+m];    //右上角->左下角
            a[i+m][j+m]=a[i][j];    //左上角->右下角
        }
}

void DivideConquer(int a[][N],int n) {  //分治算法
    if(n==1) {
        a[0][0]=1;
        return;
    }
    DivideConquer(a,n/2);
    Merge(a,n);
}

int main()
{
    int a[N][N]={0};    //循环赛日程表n行n-1列，第i行第j列填第i个选手在第j天遇到的选手
    printf("——————————循环赛日程表——————————\n");
    printf("请输入运动员的个数：\n");
    int n;
    scanf("%d",&n);
    DivideConquer(a,n);
    printf("   运动员编号 ————每天比赛对手编号————\n");
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            if(j==0)
                printf("\t%d\t",a[i][j]);
            else
                printf("%d ",a[i][j]);
        }
        putchar('\n');
    }

    system("pause");
    return 0;
}
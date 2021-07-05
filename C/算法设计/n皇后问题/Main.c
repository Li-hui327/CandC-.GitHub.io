#include <stdio.h>
#include <stdlib.h>
#define N 4

int count=0;

//判断(x,y)位置安全性算法
int SafetyPlace(int col[],int x,int y) {    //即坐标(x,y)
    for(int i=0;i<x;i++) {
        int j=col[i];
        if(x==i || y==j)
            return 0;
        if(x-y==i-j || x+y==i+j)
            return 0;
    }
    return 1;
}

void Get_Position(int i,char board[][N],int col[]) {  //处于第i行的状态
    if(i==N) {
        for(int j=0;j<N;j++) {
            for(int k=0;k<N;k++) {
                if(board[j][k]=='*')
                    printf("%c ",board[j][k]);
                else {
                    printf("$ ");
                    //printf("%c ",board[j][k]);
                }
            }
            putchar('\n');
        }
        printf("-----------------\n");
        count++;    //记录解决办法的次数
    }
    else {
        for(int j=0;j<N;j++) 
            if(SafetyPlace(col,i,j)==1) {
                col[i]=j;
                board[i][j]='*';
                Get_Position(i+1,board,col);
                col[i]=0;
                board[i][j]=0;
            }
    }
}

int main()
{
    char board[N][N];
    int col[N]; //存储对应第i行的列的值
    printf("*是皇后！\n\n");
    Get_Position(0,board,col);
    printf("一共有%d种方法！\n",count);

    system("pause");
    return 0;
}
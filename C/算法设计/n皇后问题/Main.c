#include <stdio.h>
#include <stdlib.h>
#define N 4

int count=0;

//�ж�(x,y)λ�ð�ȫ���㷨
int SafetyPlace(int col[],int x,int y) {    //������(x,y)
    for(int i=0;i<x;i++) {
        int j=col[i];
        if(x==i || y==j)
            return 0;
        if(x-y==i-j || x+y==i+j)
            return 0;
    }
    return 1;
}

void Get_Position(int i,char board[][N],int col[]) {  //���ڵ�i�е�״̬
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
        count++;    //��¼����취�Ĵ���
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
    int col[N]; //�洢��Ӧ��i�е��е�ֵ
    printf("*�ǻʺ�\n\n");
    Get_Position(0,board,col);
    printf("һ����%d�ַ�����\n",count);

    system("pause");
    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#define N 20

void Merge(int a[][N],int n) {    //�ϲ��㷨
    int m=n/2;
    for(int i=0;i<m;i++)
        for(int j=0;j<m;j++) {
            a[i][j+m]=a[i][j]+m;    //���Ͻ�->���Ͻ�
            a[i+m][j]=a[i][j+m];    //���Ͻ�->���½�
            a[i+m][j+m]=a[i][j];    //���Ͻ�->���½�
        }
}

void DivideConquer(int a[][N],int n) {  //�����㷨
    if(n==1) {
        a[0][0]=1;
        return;
    }
    DivideConquer(a,n/2);
    Merge(a,n);
}

int main()
{
    int a[N][N]={0};    //ѭ�����ճ̱�n��n-1�У���i�е�j�����i��ѡ���ڵ�j��������ѡ��
    printf("��������������������ѭ�����ճ̱�������������������\n");
    printf("�������˶�Ա�ĸ�����\n");
    int n;
    scanf("%d",&n);
    DivideConquer(a,n);
    printf("   �˶�Ա��� ��������ÿ��������ֱ�š�������\n");
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
#include <stdio.h>
#include <stdlib.h>

int n;  //��Ʒ����
double c;//��������������װ����Ʒ������
double p[100];  //��Ʒ��ֵ
double w[100];  //��Ʒ����
double cw=0;   //��ǰ����
double cp=0;  //��ǰ��ֵ
double bestp=0;   //��ǰ�����ܼ�ֵ
double perp[100];   //��λ��Ʒ��ֵ
int order[100]; //����˳��
int put[100];   //��ÿ����Ʒ�����Ƿ�װ��ı�־��0Ϊ��װ��1Ϊװ

//��λ��ֵ�����㷨
void Knapsack() {
    for(int i=1;i<=n;i++) { //��ʼ��
        put[i]=0;
        order[i]=i;
    }
    for(int i=1;i<=n;i++) 
        perp[i]=p[i]/w[i];  //���㵥λ��Ʒ��ֵ
    for(int i=1;i<=n;i++)
        for(int j=n-1;j>=i;j--) 
            if(perp[j]<perp[j+1]) { //����ð�ݷ���prep[],order[],p[],w[]��������
                double temp=perp[j];
                perp[j]=perp[j+1];
                perp[j+1]=temp;

                temp=p[j];
                p[j]=p[j+1];
                p[j+1]=temp;

                temp=w[j];
                w[j]=w[j+1];
                w[j+1]=temp;

                int k=order[j];
                order[j]=order[j+1];
                order[j+1]=k;
            }
}

//����ʣ���Ͻ��㷨
double Bound(int i) {
    double cheft=c-cw;  
    double b=cp;
    int k=i;
    while(i<=n && w[i]<=cheft) {
        cheft-=w[i];
        b+=p[i];
        i++;
    }
    if(i<=n) {
        put[k-1]=1;
        b+=p[i]/w[i]*cheft;
    }     
    return b;
}

//�����㷨
void BackTrack(int i) {
    if(i>n) {   //����Ҷ�ӽ��
        bestp=cp;
        return;
    }
    if(cw+w[i]<=c) {
        cw+=w[i];
        cp+=p[i];
        put[i]=1;
        BackTrack(i+1);
        cw-=w[i];
        cp-=p[i];
    }
    if(Bound(i+1)>bestp) {
        put[i-1]=0;
        BackTrack(i+1);
    }
}

int main()
{
    printf("��������Ʒ�ĸ�����\n");
    scanf("%d",&n);
    printf("�����뱳����������\n");
    scanf("%lf",&c);
    printf("��������Ʒ��������Ȩֵ\n");
    for(int i=1;i<=n;i++) {
        printf("��%d����Ʒ������Ϊ��",i);
        scanf("%lf",&w[i]);
        printf("��ֵ�ǣ�");
        scanf("%lf",&p[i]);
    }
    Knapsack();
    BackTrack(1);
    printf("���ż�ֵΪ��%.2f\n",bestp);
    printf("��Ҫװ�����Ʒ����ǣ�\n");
    for(int i=1;i<=n;i++)
        if(put[i])
            printf("%d ",order[i]);

    putchar('\n');
    system("pause");
    return 0;
}
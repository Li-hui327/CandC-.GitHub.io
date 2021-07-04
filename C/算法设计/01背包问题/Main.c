#include <stdio.h>
#include <stdlib.h>

int n;  //物品数量
double c;//背包容量，即能装下物品的数量
double p[100];  //物品价值
double w[100];  //物品重量
double cw=0;   //当前重量
double cp=0;  //当前价值
double bestp=0;   //当前最优总价值
double perp[100];   //单位物品价值
int order[100]; //排列顺序
int put[100];   //对每个物品设置是否装入的标志，0为不装，1为装

//单位价值排序算法
void Knapsack() {
    for(int i=1;i<=n;i++) { //初始化
        put[i]=0;
        order[i]=i;
    }
    for(int i=1;i<=n;i++) 
        perp[i]=p[i]/w[i];  //计算单位物品价值
    for(int i=1;i<=n;i++)
        for(int j=n-1;j>=i;j--) 
            if(perp[j]<perp[j+1]) { //类似冒泡法对prep[],order[],p[],w[]进行排序
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

//计算剩余上界算法
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

//回溯算法
void BackTrack(int i) {
    if(i>n) {   //到达叶子结点
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
    printf("请输入物品的个数：\n");
    scanf("%d",&n);
    printf("请输入背包的容量：\n");
    scanf("%lf",&c);
    printf("请输入物品的重量与权值\n");
    for(int i=1;i<=n;i++) {
        printf("第%d个物品的重量为：",i);
        scanf("%lf",&w[i]);
        printf("价值是：");
        scanf("%lf",&p[i]);
    }
    Knapsack();
    BackTrack(1);
    printf("最优价值为：%.2f\n",bestp);
    printf("需要装入的物品编号是：\n");
    for(int i=1;i<=n;i++)
        if(put[i])
            printf("%d ",order[i]);

    putchar('\n');
    system("pause");
    return 0;
}
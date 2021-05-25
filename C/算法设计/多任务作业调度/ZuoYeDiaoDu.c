#include <stdio.h>
#include <stdlib.h>

int panDuan(int limit,int n,int m,int *b)
{
	int work[m];
	int i,j,count=0,count2=0;
	for(i=0;i<m;i++)
		work[i]=0;
	
	for(i=0,j=n-1;;)
	{
		if(b[j]>limit)
			return 0;
		if(b[j] && work[i]+b[j]<=limit)
		{
			work[i]+=b[j];
			b[j]=0;
			count++;
			count2=0;
			i++;
			j--;
		}
		if(b[j] && work[i]+b[j]>limit)
		{
			i++;
			count2++;
		}
		if(!b[j])
		{
			j--;
			count2++;
		}	/*
		else
		{
			i++;
			j--;
			count2++;
		}	*/
		if(count==n)
			break;
		if(count2==n)
			return 0;
		if(i>=m)
			i=0;
		if(j<=(-1))
			j=n-1;		
	}
	return 1;
}

int main()
{
	int n,m,i,j,sum=0,min,limit,limit2;
	printf("Please input work's number and machine's number:\n");
	scanf("%d %d",&n,&m);
	int a[n],b[n];
	printf("Please input every work's time:\n");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	
	for(i=0;i<n;i++)
		for(j=n-2;j>=i;j--)
			if(a[j]>a[j+1])
			{
				int t=a[j];
				a[j]=a[j+1];
				a[j+1]=t;
			}

	for(i=0;i<n;i++)
		sum+=a[i];
	
	min=a[n-1]; 
	limit=(sum+min)/2;
	limit2=sum;	
	for(;;)
	{
		for(i=0;i<n;i++)
			b[i]=a[i];
		if(panDuan(limit,n,m,b))
		{
			sum=limit;
			limit2=limit;
			limit=(sum+min)/2;
		}
		else
		{
			min=limit+1;
			limit=(sum+min)/2;
		}
		if(limit>=limit2)
			break;
	}	
	printf("%d\n",limit2);
	
	system("pause");
	return 0;
}

/*
bool backtrack(int* jobs, int jobsSize, int* workloads, int workloadsSize, int idx, int limit) {
    if (idx >= jobsSize) {
        return true;
    }
    int cur = jobs[idx];
    for (int i = 0; i < workloadsSize; i++) {
        if (workloads[i] + cur <= limit) {
            workloads[i] += cur;
            if (backtrack(jobs, jobsSize, workloads, workloadsSize, idx + 1, limit)) {
                return true;
            }
            workloads[i] -= cur;
        }
        // �����ǰ����δ�����乤������ô��һ������Ҳ��Ȼδ�����乤��
        // ���ߵ�ǰ����ǡ��ʹ�ù��˵Ĺ������ﵽ������
        // ������������������賢�Լ������乤��
        if (workloads[i] == 0 || workloads[i] + cur == limit) {
            break;
        }
    }
    return false;
}

bool check(int* jobs, int jobsSize, int k, int limit) {
    int workloads[k];
    memset(workloads, 0, sizeof(workloads));
    return backtrack(jobs, jobsSize, workloads, k, 0, limit);
}

int cmp(int* a, int* b) {
    return *b - *a;
}

int accumulate(int* arr, int* arrSize) {
    int ret = 0;
    for (int i = 0; i < arrSize; i++) {
        ret += arr[i];
    }
    return ret;
}

int minimumTimeRequired(int* jobs, int jobsSize, int k) {
    qsort(jobs, jobsSize, sizeof(int), cmp);	//qsort()��ʲô�� 
    int l = jobs[0], r = accumulate(jobs, jobsSize);
    while (l < r) {
        int mid = (l + r) >> 1;
        if (check(jobs, jobsSize, k, mid)) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    return l;
}

���ߣ�LeetCode-Solution
���ӣ�https://leetcode-cn.com/problems/find-minimum-time-to-finish-all-jobs/solution/wan-cheng-suo-you-gong-zuo-de-zui-duan-s-hrhu/
��Դ�����ۣ�LeetCode��
����Ȩ���������С���ҵת������ϵ���߻����Ȩ������ҵת����ע��������
*/

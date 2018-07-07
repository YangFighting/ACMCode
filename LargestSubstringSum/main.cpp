
//����
//  ����һ��������{a1,a2...,an}���ҳ������ǿ��Ӵ�{ax,ax+1,...,ay}��ʹ�ø������еĺ�������У�1<=x<=y<=n��
//
// ����
//  ��һ����һ������N(N<=10)��ʾ�������ݵ�������
//  ÿ��������ݵĵ�һ����һ������n��ʾ�����й���n������������һ������n������I(-100=<I<=100)����ʾ�����е�����Ԫ�ء�(0<n<=1000000)
//���
//  ����ÿ�����������������������Ӵ��ĺ͡�
//
//��������
//1
//5
//1 2 -1 3 -2
//
//�������
//5


#include <iostream>
#include<stdio.h> 

using namespace std;

int LSS(int arry[], int N)
{
    int sum=0;      //��¼�ۼӺ�
    int lss=-100;    //��¼����Ӵ��� ��ʼ��Ϊ��С����(���������ȫΪ����)
    
    for(int i=0;i<N;i++)
    {
        sum += arry[i];
        if(sum > lss)
            lss = sum;
        else if(sum<0)
            sum =0;
    }
    
    return lss;
}
int main()
{
    int t;
    int N;
    int* arry;
    int* ans;
    scanf("%d",&t); 
    ans = new int[t];
    for(int i=0;i<t;i++)
    {
        scanf("%d",&N);
        arry = new int[N];
        for(int j=0;j<N;j++)
            scanf("%d",arry+j);
        ans[i] = LSS(arry,N);
        delete[] arry;
    }
    
    for( int i=0;i<t;i++)
        printf("%d\n",ans[i]); 
    
    delete[] ans;
    
    return 0;
}

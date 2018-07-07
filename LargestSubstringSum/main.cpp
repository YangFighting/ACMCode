
//描述
//  给定一整型数列{a1,a2...,an}，找出连续非空子串{ax,ax+1,...,ay}，使得该子序列的和最大，其中，1<=x<=y<=n。
//
// 输入
//  第一行是一个整数N(N<=10)表示测试数据的组数）
//  每组测试数据的第一行是一个整数n表示序列中共有n个整数，随后的一行里有n个整数I(-100=<I<=100)，表示数列中的所有元素。(0<n<=1000000)
//输出
//  对于每组测试数据输出和最大的连续子串的和。
//
//样例输入
//1
//5
//1 2 -1 3 -2
//
//样例输出
//5


#include <iostream>
#include<stdio.h> 

using namespace std;

int LSS(int arry[], int N)
{
    int sum=0;      //记录累加和
    int lss=-100;    //记录最大子串和 初始化为最小的数(特殊情况，全为负数)
    
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

/*
描述
咱们就不拐弯抹角了，如题，需要你做的就是写一个程序，得出最长公共子序列。
tip：最长公共子序列也称作最长公共子串(不要求连续)，英文缩写为LCS（Longest Common Subsequence）。其定义是，一个序列 S ，如果分别是两个或多个已知序列的子序列，且是所有符合此条件序列中最长的，则 S 称为已知序列的最长公共子序列。

输入
第一行给出一个整数N(0<N<100)表示待测数据组数
接下来每组数据两行，分别为待测的两组字符串。每个字符串长度不大于1000.

输出
每组测试数据输出一个整数，表示最长公共子序列长度。每组结果占一行。

样例输入
2
asdf
adfsd
123abc
abc123abc
样例输出
3
6
*/


#include <iostream>

using namespace std;

int LCS(string s1,string s2)
{
    int c;  //记录S1与s2的LCS长度
    int m = s1.length();
    int n = s2.length();
    
    //构造二维数组记录子问题是s1[i]和s2[i]的LCS长度
    int** opt = new int* [m+1];
    for(int i=0 ;i<m+1;i++)
        opt[i] = new int[n+1];
    
    for(int i =0;i<=m;++i)
    {
        for(int j =0;j<=n;++j)
        {
            if(i==0||j==0)
                opt[i][j] = 0;
            else
            {
                 if(s1[i-1] == s2[j-1])
                    opt[i][j] = opt[i-1][j-1]+1;
                else
                    opt[i][j]=(opt[i-1][j]>opt[i][j-1])?opt[i-1][j]:opt[i][j-1];
            }
        }    
    }
    
    c = opt[m][n];
    
    for(int i=0;i<=m;++i)
        delete[] opt[i];
    delete[] opt;
    
    return c;
}

int main()
{
    int t;
    string s1,s2;

    cin>>t;
    int* res = new int[t];
    for(int i=0;i<t;i++)
    {
        cin>>s1>>s2;
        res[i] = LCS(s1,s2);
    }
    for(int i=0;i<t;i++)
        cout<<res[i]<<endl;

    return 0;
}

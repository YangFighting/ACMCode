/*
����
���ǾͲ�����Ĩ���ˣ����⣬��Ҫ�����ľ���дһ�����򣬵ó�����������С�
tip�������������Ҳ����������Ӵ�(��Ҫ������)��Ӣ����дΪLCS��Longest Common Subsequence�����䶨���ǣ�һ������ S ������ֱ�������������֪���е������У��������з��ϴ�������������ģ��� S ��Ϊ��֪���е�����������С�

����
��һ�и���һ������N(0<N<100)��ʾ������������
������ÿ���������У��ֱ�Ϊ����������ַ�����ÿ���ַ������Ȳ�����1000.

���
ÿ������������һ����������ʾ����������г��ȡ�ÿ����ռһ�С�

��������
2
asdf
adfsd
123abc
abc123abc
�������
3
6
*/


#include <iostream>

using namespace std;

int LCS(string s1,string s2)
{
    int c;  //��¼S1��s2��LCS����
    int m = s1.length();
    int n = s2.length();
    
    //�����ά�����¼��������s1[i]��s2[i]��LCS����
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

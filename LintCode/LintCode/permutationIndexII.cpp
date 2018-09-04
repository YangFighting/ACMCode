/*
198. �������II
����һ�����ܰ����ظ����ֵ����У�����Щ���ֵ��������а��ֵ������������������еı�š���Ŵ�1��ʼ��

����
��������[1, 4, 2, 2]������Ϊ3��
*/

#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Solution {
public:
	/**
	* @param A: An array of integers
	* @return: A long integer
	*/
	long long permutationIndexII(vector<int> &A) {
		// write your code here
		long long sum = 1;	//��1 ��ʼ �ۼ�
		int len = A.size();
		if (len == 0)
			return 0;
		int dup = 1;	//�ظ������Ľ׳�
		map<int, int> hashRepeat;	//������ϣ�����ڼ����ظ�����
		int fac = 1;	//����չ���еĽ׳�
		
		for (int i = len - 1; i >= 0; i--)	//�Ӻ���ǰ���㣬�����λ�׳ˣ������λ�׳�
		{
			hashRepeat[A[i]]++;
			if (hashRepeat[A[i]] > 1)
				dup *= hashRepeat[A[i]];	//map������ģ�dup�Ľ׳�Ҳ�������λ�������λ

			int count = 0;	//����չ����С��ĳ���ĸ���
			for (int j = i + 1; j < len; j++)
			{
				if (A[j] > A[i])
					count++;
			}
			sum += count * fac/ dup;	//�����ظ������Ľ׳�
			fac *= (len - i);
		}
	}
};

int main()
{
	vector<int> nums({ 1, 4, 2, 2 });
	Solution solution;
	long long ans;
	ans = solution.permutationIndexII(nums);
	cout << ans << endl;
	system("pause");
	return 0;
}
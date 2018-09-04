/*
198. 排列序号II
给出一个可能包含重复数字的排列，求这些数字的所有排列按字典序排序后该排列在其中的编号。编号从1开始。

样例
给出排列[1, 4, 2, 2]，其编号为3。
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
		long long sum = 1;	//从1 开始 累加
		int len = A.size();
		if (len == 0)
			return 0;
		int dup = 1;	//重复次数的阶乘
		map<int, int> hashRepeat;	//建立哈希表，用于计算重复次数
		int fac = 1;	//康托展开中的阶乘
		
		for (int i = len - 1; i >= 0; i--)	//从后往前计算，先算低位阶乘，再算高位阶乘
		{
			hashRepeat[A[i]]++;
			if (hashRepeat[A[i]] > 1)
				dup *= hashRepeat[A[i]];	//map是有序的，dup的阶乘也是先算低位，再算高位

			int count = 0;	//康托展开中小于某数的个数
			for (int j = i + 1; j < len; j++)
			{
				if (A[j] > A[i])
					count++;
			}
			sum += count * fac/ dup;	//除以重复次数的阶乘
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
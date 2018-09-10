/*
给定 n 和 k，求123..n组成的排列中的第 k 个排列。

样例
对于 n = 3, 所有的排列如下：

123
132
213
231
312
321
如果 k = 4, 第4个排列为，231.

挑战
O(n*k) in time complexity is easy, can you do it in O(n^2) or less?

注意事项
1 ≤ n ≤ 9
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;


class Solution {
public:
	/**
	* @param n: n
	* @param k: the k th permutation
	* @return: return the k-th permutation
	*/
	string getPermutation(int n, int k) {
		// write your code here
		const int FAC[] = { 1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880 };// 阶乘缓存表

		int ExpansionValue = k - 1;		//康托展开值
		int a;			//排列组合的数 (余数)
		string ans;			//输出的组合数

		vector<int> vec;
		for (int i = 1; i <= n; i++)
			vec.push_back(i);

		for (int i = n - 1; i >= 1; i--)		//从(n-1)! - 1!
		{
			a = ExpansionValue / FAC[i];
			ExpansionValue = ExpansionValue % FAC[i];

			ans += char(vec[a] + '0' - 0);
			vec.erase(vec.begin() + a);

		}
		ans += char(vec[0] + '0' - 0);	//最后一位直接得到
		return ans;
	}
};

int main()
{
	int n = 3, k = 3;
	Solution solution;
	string ans;
	ans = solution.getPermutation(n, k);
	cout << ans << endl;
	system("pause");
	return 0;
}

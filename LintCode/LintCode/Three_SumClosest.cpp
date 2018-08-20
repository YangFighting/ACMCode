/*
给一个包含 n 个整数的数组 S, 找到和与给定整数 target 最接近的三元组，返回这三个数的和。

样例
例如 S = [-1, 2, 1, -4] and target = 1. 和最接近 1 的三元组是 -1 + 2 + 1 = 2.

挑战
O(n^2) 时间, O(1) 额外空间。

注意事项
只需要返回三元组之和，无需返回三元组本身
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	/**
	* @param numbers: Give an array numbers of n integer
	* @param target: An integer
	* @return: return the sum of the three integers, the sum closest target.
	*/
	int threeSumClosest(vector<int> &numbers, int target) {
		sort(numbers.begin(), numbers.end());
		int len = numbers.size();
		int ans = INT_MAX;
		for (int i = 0; i < len; i++)
		{
			int j = i + 1;
			int k = len - 1;
			int sum;
			while (j < k)
			{
				sum = numbers[i] + numbers[j] + numbers[k];
				ans = (abs(sum - target) < abs(ans - target)) ? sum : ans;
				if (sum > target)	k--;
				else if (sum < target) j++;
				else return sum;
			}
		}
		return ans;
	}
};

int main()
{
	const int NUM_SIZE = 4;
	int numbers[NUM_SIZE] = { -1, 2, 1, -4 };
	vector<int> nums(numbers, numbers + NUM_SIZE);

	int target = 1;
	Solution solution;
	int ans = solution.threeSumClosest(nums, target);

	cout << ans << endl;

	system("pause");
	return 0;
}

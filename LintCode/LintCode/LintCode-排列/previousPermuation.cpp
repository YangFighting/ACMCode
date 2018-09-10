/*
给定一个整数数组来表示排列，找出其上一个排列。

样例
给出排列[1,3,2,3]，其上一个排列是[1,2,3,3]

给出排列[1,2,3,4]，其上一个排列是[4,3,2,1]

注意事项
排列中可能包含重复的整数
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
class Solution {
public:
	/*
	* @param nums: A list of integers
	* @return: A list of integers that's previous permuation
	*/
	vector<int> previousPermuation(vector<int> &nums) {
		if (nums.empty() || nums.size() == 1)
			return nums;
		int len = nums.size();
		int pos = -1;
		int i;
		//从右向左，找到位置pos,使pos+1到len，为递增序列
		for (i = len - 1; i > 0; i--)
		{
			if (nums[i] < nums[i - 1])
			{
				pos = i - 1;
				break;
			}
		}
		//输入序列为递增序列(如1,2,3,4)，逆序输出
		if (pos == -1 && i == 0)
		{
			reverse(nums.begin(), nums.end());
			return nums;
		}

		//在pos+1到len序列中，从右向左搜索，寻找第一个比位置pos小的元素位置
		for (i = len - 1; i > pos; i--)
		{
			if (nums[i] < nums[pos])
			{
				swap(nums[i], nums[pos]);
				reverse(nums.begin() + pos + 1, nums.end());
				return nums;
			}
		}

	}
};
int main()
{
	vector<int> numbers({ 2,1,3 });
	Solution solution;
	vector<int> ans;
	ans = solution.previousPermuation(numbers);
	for (vector<int>::iterator it = numbers.begin(); it != numbers.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;

	system("pause");
	return 0;
}

/*
52. 下一个排列
给定一个整数数组来表示排列，找出其之后的一个排列。

样例
给出排列[1,3,2,3]，其下一个排列是[1,3,3,2]

给出排列[4,3,2,1]，其下一个排列是[1,2,3,4]

注意事项
排列中可能包含重复的整数
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
class Solution {
public:
	/**
	* @param nums: A list of integers
	* @return: A list of integers
	*/
	vector<int> nextPermutation(vector<int> &nums) {
		int Len = nums.size();
		vector<int>::iterator it_i = nums.end() - 1;
		while ((it_i != nums.begin()) && (*it_i <= *(it_i - 1)))
			it_i--;
		if (it_i == nums.begin())
		{
			sort(nums.begin(), nums.end());
			return nums;
		}
		it_i--;

		vector<int>::iterator it_j = nums.end() - 1;
		while (it_j != it_i)
		{
			if (*it_j > *it_i)
			{
				it_j--;
				break;
			}
				
			else
				it_j--;
		}
			
		it_j++;
		swap(*it_j, *it_i);
		sort(it_i + 1, nums.end());
		return nums;
	}
};

int main()
{
	vector<int> numbers({ 1,2,1 });
	Solution solution;
	vector<int> ans;
	ans = solution.nextPermutation(numbers);

	for (vector<int>::iterator it = numbers.begin(); it != numbers.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;

	system("pause");
	return 0;
}
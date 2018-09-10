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
		vector<int>::iterator it_j = nums.end() - 1;
		//1)寻找Pj
		while ((it_j != nums.begin()) && (*it_j <= *(it_j - 1)))
			it_j--;
		if (it_j == nums.begin())
		{
			sort(nums.begin(), nums.end());
			return nums;
		}
		it_j--;		
		//2)寻找Pj
		vector<int>::iterator it_k = nums.end() - 1;
		while (it_k != it_j)
		{
			if (*it_k > *it_j)
			{
				it_k--;
				break;
			}
				
			else
				it_k--;
		}
			
		it_k++;

		//3)交换
		swap(*it_j, *it_k);

		//4)翻转排序
		sort(it_j + 1, nums.end());

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
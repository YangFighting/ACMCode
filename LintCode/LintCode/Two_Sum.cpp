//题目描述：
//给一个整数数组，找到两个数使得他们的和等于一个给定的数 target。
//你需要实现的函数twoSum需要返回这两个数的下标, 并且第一个下标小于第二个下标。注意这里下标的范围是 1 到 n，不是以 0 开头。
//
//注意：你可以假设只有一组解。
//样例：给出 numbers = [2, 7, 11, 15], target = 9, 返回[1, 2]，即数字2, 7
// 扩大了条件 可以有不只一组

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
	/**
	* @param numbers: An array of Integer
	* @param target: target = numbers[index1] + numbers[index2]
	* @return: [index1, index2] (index1 < index2)
	*/
	vector<int> twoSum(vector<int> &numbers, int target)
	{
		vector<int> vec(2, 0);
		for (vector<int>::iterator it = numbers.begin(); it != numbers.end(); it++)
		{

			vector<int>::iterator find_it = find(numbers.begin(), numbers.end(), target - *it);
			if (find_it != numbers.end() && find_it != it)
			{
				int min = (it - numbers.begin()) > (find_it - numbers.begin()) ? find_it - numbers.begin() : it - numbers.begin();
				int max = (it - numbers.begin()) > (find_it - numbers.begin()) ? it - numbers.begin() : find_it - numbers.begin();
				vec[0]= min;
				vec[1]= max;
				return vec;
			}
			
		}
		return vec;
	}
};

int main()
{
	const int NUM_SIZE = 4;
	int numbers[NUM_SIZE] = { 2,7,11,15 };
	vector<int> nums(numbers, numbers + NUM_SIZE);

	int target = 9;

	Solution solution;
	vector<int> v = solution.twoSum(nums, target);

	for (vector<int>::const_iterator p = v.cbegin(); p != v.cend(); ++p)
	{
		cout << *p << " ";
		cout << endl;
	}
		
	system("pause");
	return 0;
}
//题目描述：
//给一个整数数组，找到两个数使得他们的和等于一个给定的数 target。
//你需要实现的函数twoSum需要返回这两个数的下标, 并且第一个下标小于第二个下标。注意这里下标的范围是 1 到 n，不是以 0 开头。
//
//注意：你可以假设只有一组解。
//样例：给出 numbers = [2, 7, 11, 15], target = 9, 返回[1, 2]，即数字2, 7
// 扩大了条件 可以有不只一组

#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>

using namespace std;
set<vector<int>> twosum(vector<int> &nums, int target)
{
	set<vector<int>> result;
	unordered_map<int, int> hash;	//val +id
	
	for (int i = 0; i < nums.size(); i++)
		hash[nums[i]] = i;

	for (int i = 0; i < nums.size(); i++)
	{
		int tmp = target - nums[i];
		if (hash.count(tmp) && hash[tmp] != i)
		{
			int min, max;
			if (i < hash[tmp])
			{
				min = i; max = hash[tmp];
			}
			else
			{
				max = i; min = hash[tmp];
			}

			result.insert({ 1 + min, 1 + max });
		}
	}
	
	return result;
}

#ifdef TwoSum
int main()
{
	const int NUM_SIZE = 4;
	int numbers[NUM_SIZE] = { 2,3,1,4 };
	vector<int> nums(numbers, numbers + NUM_SIZE);

	int target = 5;

	set<vector<int>> v = twosum(nums, target);

	for (set<vector<int>>::const_iterator p = v.cbegin(); p != v.cend(); ++p)
	{
		for (vector<int>::const_iterator q = (*p).cbegin(); q != (*p).cend(); q++)
			cout << *q << " ";
		cout << endl;
	}
		
	system("pause");
	return 0;
}
#endif
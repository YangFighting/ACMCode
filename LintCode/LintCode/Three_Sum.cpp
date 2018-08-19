/*
57. 三数之和
给出一个有n个整数的数组S，在S中找到三个整数a, b, c，找到所有使得a + b + c = 0的三元组。

样例
如S = { -1 0 1 2 - 1 - 4 }, 你需要返回的三元组集合的是：

(-1, 0, 1)

(-1, -1, 2)

注意事项
在三元组(a, b, c)，要求a <= b <= c。

结果不能包含重复的三元组。
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
	/**
	* @param numbers: Give an array numbers of n integer
	* @return: Find all unique triplets in the array which gives the sum of zero.
	*/
	vector<vector<int>> threeSum(vector<int> &numbers)
	{
		vector<vector<int>> res;
		sort(numbers.begin(), numbers.end());
		for (int i = 0; i < numbers.size(); i++)
		{
			if (i > 0 && numbers[i - 1] == numbers[i])		//为了防止包含重复的三元组,只在累加后执行
				continue;
			int j, k;
			j = i + 1;
			k = numbers.size() - 1;

			while (j < k)
			{
				if ((j > i + 1) && (numbers[j] == numbers[j - 1]))	//为了防止包含重复的三元组,只在累加后执行
				{
					j++;
					continue;
				}
					
				if ((k < numbers.size() - 1) && (numbers[k] == numbers[k + 1]))
				{
					k--;
					continue;
				}

				int sum = numbers[i] + numbers[j] + numbers[k];

				if (sum == 0)
				{
					res.push_back({ numbers[i] ,numbers[j] ,numbers[k] });
					j++;
					k--;
				}
					
				else if (sum < 0)
				{
					j++;
		
				}
				else
				{
					k--;
				}
			}
		}

		return res;
	}
};

int main()
{
	const int NUM_SIZE = 6;
	int numbers[NUM_SIZE] = { -1, 0, 1, 2, -1, -4 };
	vector<int> nums(numbers, numbers + NUM_SIZE);


	Solution solution;
	vector<vector<int>> v = solution.threeSum(nums);

	for (vector<vector<int>>::iterator p = v.begin(); p != v.end(); ++p)
	{
		for(vector<int>::iterator q = p->begin();q != p->end(); ++q)
			cout << *q << " ";
		cout << endl;
	}

	system("pause");
	return 0;
}
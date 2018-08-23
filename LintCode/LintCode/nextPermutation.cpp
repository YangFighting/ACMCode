/*
52. ��һ������
����һ��������������ʾ���У��ҳ���֮���һ�����С�

����
��������[1,3,2,3]������һ��������[1,3,3,2]

��������[4,3,2,1]������һ��������[1,2,3,4]

ע������
�����п��ܰ����ظ�������
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
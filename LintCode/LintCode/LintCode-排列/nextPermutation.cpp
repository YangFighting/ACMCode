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
		vector<int>::iterator it_j = nums.end() - 1;
		//1)Ѱ��Pj
		while ((it_j != nums.begin()) && (*it_j <= *(it_j - 1)))
			it_j--;
		if (it_j == nums.begin())
		{
			sort(nums.begin(), nums.end());
			return nums;
		}
		it_j--;		
		//2)Ѱ��Pj
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

		//3)����
		swap(*it_j, *it_k);

		//4)��ת����
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
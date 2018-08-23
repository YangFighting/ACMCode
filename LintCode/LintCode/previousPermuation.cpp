/*
����һ��������������ʾ���У��ҳ�����һ�����С�

����
��������[1,3,2,3]������һ��������[1,2,3,3]

��������[1,2,3,4]������һ��������[4,3,2,1]

ע������
�����п��ܰ����ظ�������
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
		//���������ҵ�λ��pos,ʹpos+1��len��Ϊ��������
		for (i = len - 1; i > 0; i--)
		{
			if (nums[i] < nums[i - 1])
			{
				pos = i - 1;
				break;
			}
		}
		//��������Ϊ��������(��1,2,3,4)���������
		if (pos == -1 && i == 0)
		{
			reverse(nums.begin(), nums.end());
			return nums;
		}

		//��pos+1��len�����У���������������Ѱ�ҵ�һ����λ��posС��Ԫ��λ��
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

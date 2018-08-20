/*
��һ������n��������������S����S���ҵ�����ʹ�ú�Ϊ��������target����Ԫ��(a, b, c, d)��

����
���磬���ڸ�������������S=[1, 0, -1, 0, -2, 2] �� target=0. ����Ҫ�����Ԫ�鼯��Ϊ��

(-1, 0, 0, 1)

(-2, -1, 1, 2)

(-2, 0, 0, 2)

ע������
��Ԫ��(a, b, c, d)�У���Ҫ����a <= b <= c <= d

���в����԰����ظ�����Ԫ�顣
*/

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

class Solution {
public:
	/**
	* @param numbers: Give an array
	* @param target: An integer
	* @return: Find all unique quadruplets in the array which gives the sum of zero
	*/
	vector<vector<int>> fourSum(vector<int> &numbers, int target) {
		vector<vector<int>> ans;
		sort(numbers.begin(), numbers.end());

		int Len = numbers.size();
		for (int i = 0; i < Len - 3; i++)
		{
			if (i > 0 && numbers[i - 1] == numbers[i])
				continue;
			for (int j = i + 1; j < Len - 2; j++)
			{
				if(j > i+1 && numbers[j - 1] == numbers[j])
					continue;
				int k = j + 1;
				int m = Len - 1;
				while (k < m)
				{
					if (k > j + 1 && numbers[k - 1] == numbers[k])
					{
						k++;
						continue;
					}
						
					if (m < Len - 1 && numbers[m + 1] == numbers[m])
					{
						m--; 
						continue;
					}
						
					int sum = numbers[i] + numbers[j] + numbers[k] + numbers[m];
					if (sum > target)
						m--;
					else if (sum < target)
						k++;
					else
					{
						ans.push_back({ numbers[i], numbers[j], numbers[k], numbers[m] });
						k++;
						m--;
					}
				}
			}
		}
		return ans;
	}
};

int main()
{
	const int NUMSIZE = 11;
	int num[NUMSIZE] = { 1,0,-1,-1,-1,-1,0,1,1,1,2 };
	vector<int> numbers(num, num + NUMSIZE);
	int target = 2;
	vector<vector<int>> ans;

	Solution solution;
	ans = solution.fourSum(numbers, target);
	for (vector<vector<int>>::iterator it_vec = ans.begin(); it_vec != ans.end(); it_vec++)
	{
		for (vector<int>::iterator it = (*it_vec).begin(); it != (*it_vec).end(); it++)
		{
			cout << *it << " ";
		}
		cout << endl;
	}
	system("pause");
	return 0;
}

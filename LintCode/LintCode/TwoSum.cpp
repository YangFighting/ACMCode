//��Ŀ������
//��һ���������飬�ҵ�������ʹ�����ǵĺ͵���һ���������� target��
//����Ҫʵ�ֵĺ���twoSum��Ҫ���������������±�, ���ҵ�һ���±�С�ڵڶ����±ꡣע�������±�ķ�Χ�� 1 �� n�������� 0 ��ͷ��
//
//ע�⣺����Լ���ֻ��һ��⡣
//���������� numbers = [2, 7, 11, 15], target = 9, ����[1, 2]��������2, 7
// ���������� �����в�ֻһ��

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
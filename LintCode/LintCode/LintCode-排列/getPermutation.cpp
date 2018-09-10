/*
���� n �� k����123..n��ɵ������еĵ� k �����С�

����
���� n = 3, ���е��������£�

123
132
213
231
312
321
��� k = 4, ��4������Ϊ��231.

��ս
O(n*k) in time complexity is easy, can you do it in O(n^2) or less?

ע������
1 �� n �� 9
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;


class Solution {
public:
	/**
	* @param n: n
	* @param k: the k th permutation
	* @return: return the k-th permutation
	*/
	string getPermutation(int n, int k) {
		// write your code here
		const int FAC[] = { 1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880 };// �׳˻����

		int ExpansionValue = k - 1;		//����չ��ֵ
		int a;			//������ϵ��� (����)
		string ans;			//����������

		vector<int> vec;
		for (int i = 1; i <= n; i++)
			vec.push_back(i);

		for (int i = n - 1; i >= 1; i--)		//��(n-1)! - 1!
		{
			a = ExpansionValue / FAC[i];
			ExpansionValue = ExpansionValue % FAC[i];

			ans += char(vec[a] + '0' - 0);
			vec.erase(vec.begin() + a);

		}
		ans += char(vec[0] + '0' - 0);	//���һλֱ�ӵõ�
		return ans;
	}
};

int main()
{
	int n = 3, k = 3;
	Solution solution;
	string ans;
	ans = solution.getPermutation(n, k);
	cout << ans << endl;
	system("pause");
	return 0;
}

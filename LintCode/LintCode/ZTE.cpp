#include <iostream>
#include <vector>

using namespace std;

vector<int> salaryfrequeny(int num, int *salaries)
{
	vector<int> sal;
	vector<int> feq;
	vector<int> ans;

	sal.push_back(*salaries);
	feq.push_back(1);

	for (int i = 1; i < num; i++)
	{
		int sal_len = sal.size();
		int j;
		for (j = 0; j < sal_len; j++)
		{
			if (*(salaries + i) == sal[j])
			{
				feq[j]++;
				break;
			}
		}

		if (j == sal_len)
		{
			sal.push_back(*(salaries + i));
			feq.push_back(1);
		}

	}

	vector<bool> tra_flag;
	int sal_len = sal.size();

	for (int j = 0; j < sal_len; j++)
	{
		tra_flag.push_back(true);
	}
	
	int feq_len = feq.size();
	for(int jj =0; jj < feq_len; jj++)
	{
		int max_feq = -1;
		int max_flag;

		for (int i = 0; i < feq_len; i++)
		{
			if (tra_flag[i] && max_feq < feq[i])
			{
				max_feq = feq[i];
				max_flag = i;
			}
				
		}
		tra_flag[max_flag] = false;

		for (int j = 0; j < max_feq; j++)
		{
			ans.push_back(sal[max_flag]);
		}
	}
	return ans;
}


int main()
{


	system("pause");
	return 0;
};
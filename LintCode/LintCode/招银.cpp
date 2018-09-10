#include <iostream>
#include<random>
using namespace std;

float Rander(float min, float max)
{
	random_device rd;
	mt19937 eng(rd());
	uniform_real_distribution<float> dist(min, max);
	return dist(eng);
}
int main()
{
	float total, min, max;
	int num;
	/*
	total = 10.56;
	num = 5;
	min = 1.8;
	max = 3;

	*/
	cin >> total >> num >> min >> max;

	int i = 1;
	float money = 1;
	while (total > 0)
	{
		total -= money;
		cout << "第" << i << "个人抢到的红包金额为 " << money << "， 红包剩余金额为 " << total << endl;

		if (total> max)
		{
			money = Rander(min, max);
			cout << "money Rander " << money << endl;
		}
		else
		{
			money = total;
		}
		i++;
	}


	system("pause");
	return 0;
}
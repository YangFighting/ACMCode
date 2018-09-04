/*
给出一个非空的字符串，判断这个字符串是否是由它的一个子串进行多次首尾拼接构成的。
例如，"abcabcabc"满足条件，因为它是由"abc"首尾拼接而成的，而"abcab"则不满足条件。
输入描述:
非空字符串

输出描述:
如果字符串满足上述条件，则输出最长的满足条件的的子串；如果不满足条件，则输出false。

输入例子1:
abcabc

输出例子1:
abc
*/

#include <iostream>
#include <string>
#include <queue>
#include <map>
using namespace std;

bool compareQueue(queue<char> que1, queue<char> que2)
{
	int len1 = que1.size();
	int len2 = que2.size();
	if (len1 != len2)
		return false;
	else
	{
		for (int i = 0; i < len1; i++)
		{
			if (que1.front() != que2.front())
				return false;
			else
			{
				que1.pop();
				que2.pop();
			}
		}
		return true;
	}
}
bool StringDetection(string istring, queue<char>& ans_que)
{
	queue<char> que;
	map<queue<char>, int> ans_map;

	bool popflag = false;
	bool ans_flag = false;

	int len = istring.size();
	for (int i = 0; i < len; i++)
	{
		if (que.empty())
		{
			popflag = false;
			if (!ans_que.empty())
			{
				ans_map[ans_que]++;
				ans_que = queue<char>();
			}
				
			que.push(istring[i]);
		}
		else
		{
			if (que.front() != istring[i])
			{
				if (popflag == false)
				{
					que.push(istring[i]);
				}
				else
				{
					ans_flag = false;
					break;
				}
			}
			else
			{
				ans_que.push(que.front());
				que.pop();
				popflag = true;
				continue;
			}
		}
	}

	if (que.empty())
	{
		if (ans_map.size() > 1)
			ans_flag = false;
		else if (ans_map.size() == 1)
		{
			ans_flag = true;
			ans_que = ans_map.begin()->first;
			if (ans_map[ans_que] % 2 != 0)
			{
	
				queue<char> quetmp = ans_que;
				for (int i = 0; (ans_map[ans_que]+1) / 2; i++)
				{
					while (!quetmp.empty())
					{
						ans_que.push(quetmp.front());
						quetmp.pop();
					}

				}
			}
		}
		else
		{
			ans_flag = true;
		}
	}
	else
	{
		if (compareQueue(que, ans_map.begin()->first))
		{
			ans_que = ans_map.begin()->first;
			ans_flag = true;
		}
		else
			ans_flag = false;
	}

	return ans_flag;
}
int main()
{
	string istring;

	istring = string("aaaaaaaaaa");
	//getline(cin, istring);

	queue<char> ans_que;
	bool ans_flag;
	ans_flag = StringDetection(istring, ans_que);
	if (ans_flag)
	{
		int N = ans_que.size();
		for (int i = 0; i < N; i++)
		{
			cout << ans_que.front();
			ans_que.pop();
		}
	}
	else
		cout << "false";
	cout << endl;
	system("pause");
	return 0;
}
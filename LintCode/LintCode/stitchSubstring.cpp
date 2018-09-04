/*
����һ���ǿյ��ַ������ж�����ַ����Ƿ���������һ���Ӵ����ж����βƴ�ӹ��ɵġ�
���磬"abcabcabc"������������Ϊ������"abc"��βƴ�Ӷ��ɵģ���"abcab"������������
��������:
�ǿ��ַ���

�������:
����ַ����������������������������������ĵ��Ӵ�����������������������false��

��������1:
abcabc

�������1:
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
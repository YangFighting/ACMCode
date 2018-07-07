#include <iostream>
#include <vector>
#include <string>

using namespace std;

string solution(string input)
{
	string res;
	const int CHAR_SIZE = 26;
	int char_num[CHAR_SIZE] = { 0 };		//×Ö·ûÍ³¼Æ
	for (int i = 0; i < input.size(); i++)
	{
		char_num[int(input[i] - 'A')]++;
	}

	while(1)
	{
		if (char_num[int('Z' - 'A')] && char_num[int('E' - 'A')] && char_num[int('R' - 'A')] && char_num[int('O' - 'A')])
		{
			char_num[int('Z' - 'A')]--;
			char_num[int('E' - 'A')]--;
			char_num[int('R' - 'A')]--;
			char_num[int('O' - 'A')]--;
			res += '0';
		}
		else if (char_num[int('O' - 'A')] && char_num[int('N' - 'A')] && char_num[int('E' - 'A')])
		{
			char_num[int('O' - 'A')]--;
			char_num[int('N' - 'A')]--;
			char_num[int('E' - 'A')]--;
			res += '1';
		}
		else if (char_num[int('T' - 'A')] && char_num[int('W' - 'A')] && char_num[int('O' - 'A')])
		{
			char_num[int('T' - 'A')]--;
			char_num[int('W' - 'A')]--;
			char_num[int('O' - 'A')]--;
			res += '2';
		}
		else if (char_num[int('T' - 'A')] && char_num[int('H' - 'A')] && char_num[int('R' - 'A')] && (char_num[int('E' - 'A')] >= 2))
		{
			char_num[int('T' - 'A')]--;
			char_num[int('H' - 'A')]--;
			char_num[int('R' - 'A')]--;
			char_num[int('E' - 'A')]--;
			char_num[int('E' - 'A')]--;
			res += '3';
		}

		else if (char_num[int('F' - 'A')] && char_num[int('O' - 'A')] && char_num[int('U' - 'A')] && (char_num[int('R' - 'A')]))
		{
			char_num[int('F' - 'A')]--;
			char_num[int('O' - 'A')]--;
			char_num[int('R' - 'A')]--;
			char_num[int('U' - 'A')]--;
			res += '4';
		}
		else if (char_num[int('F' - 'A')] && char_num[int('I' - 'A')] && char_num[int('V' - 'A')] && (char_num[int('E' - 'A')]))
		{
			char_num[int('F' - 'A')]--;
			char_num[int('I' - 'A')]--;
			char_num[int('V' - 'A')]--;
			char_num[int('E' - 'A')]--;
			res += '5';
		}
		else if (char_num[int('S' - 'A')] && char_num[int('I' - 'A')] && char_num[int('X' - 'A')])
		{
			char_num[int('S' - 'A')]--;
			char_num[int('I' - 'A')]--;
			char_num[int('X' - 'A')]--;
			res += '6';
		}
		else if (char_num[int('S' - 'A')] && (char_num[int('E' - 'A')] >= 2) && char_num[int('V' - 'A')] && char_num[int('N' - 'A')])
		{
			char_num[int('S' - 'A')]--;
			char_num[int('E' - 'A')]--;
			char_num[int('V' - 'A')]--;
			char_num[int('E' - 'A')]--;
			char_num[int('N' - 'A')]--;
			res += '7';
		}
		else if (char_num[int('E' - 'A')] && (char_num[int('I' - 'A')]) && char_num[int('G' - 'A')] && char_num[int('H' - 'A')] && char_num[int('T' - 'A')])
		{
			char_num[int('E' - 'A')]--;
			char_num[int('I' - 'A')]--;
			char_num[int('G' - 'A')]--;
			char_num[int('H' - 'A')]--;
			char_num[int('T' - 'A')]--;
			res += '8';
		}
		else if ((char_num[int('N' - 'A')] >= 2) && char_num[int('I' - 'A')] && char_num[int('N' - 'A')])
		{
			char_num[int('N' - 'A')]--;
			char_num[int('I' - 'A')]--;
			char_num[int('N' - 'A')]--;
			char_num[int('E' - 'A')]--;
			res += '9';
		}
		else
			break;
	}

	return res;
}

#define TeleNumber 1
#ifdef TeleNumber
int main()
{
	vector<string> res;
	string input("NINEEIGHTSEVENSIXFIVE");
	//£¨"ZERO", "ONE", "TWO", "THREE", "FOUR",
	//	"FIVE", "SIX", "SEVEN", "EIGHT", "NINE"£©£¬
	//int N;
	//cin >> N;

	//while (N--)
	//{
	//	getline(cin, input);
	//	res.push_back(solution(input));
	//}

	res.push_back(solution(input));
	for (vector<string>::const_iterator it = res.cbegin(); it != res.cend(); it++)
	{
		cout << *it << endl;
	}
	system("pause");
	return 0;
}
#endif
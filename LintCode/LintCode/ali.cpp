
/*
输入:
输入数据包含两行，
第一行，实体列表，多种实体之间用分号隔开，实体名和实体值之间用下划线隔开，多个实体值之间用竖线隔开，所有标点都是英文状态下的，格式如下：
实体名称1_实体值1|实体值2|…;实体名称2_实体值1|实体值2|…;…
第二行，用户的自然语言指令
输出:
被标记了关键词的指令。指令中的关键词前后加一个空格被单独分出来，并在后面跟上"/"+实体名称来标记。如果一个实体值属于多个实体，将这些实体都标记出来，并按照实体名称的字符串顺序正序排列，并以逗号分隔。
输入范例:
singer_周杰|周杰伦|刘德华|王力宏;song_冰雨|北京欢迎你|七里香;actor_周杰伦|孙俪
请播放周杰伦的七里香给我听
输出范例:
请播放 周杰伦/actor,singer 的 七里香/song 给我听

*/
#include <iostream>
#include <map>
#include <vector>
#include <string>
using namespace std;
int main()
{
	string str1, str2;
	//getline(cin, str1);
	str1 = "singer_周杰|周杰伦|刘德华|王力宏;song_冰雨|北京欢迎你|七里香;actor_周杰伦";
	//getline(cin, str2);

	map<string, vector<string>> map1;
	vector<string> vec_str;
	int str1_size = str1.size();
	string substr, singerName;
	vector<string> EntityName;
	int substr_start = 0;
	int substr_n = 0;
	int Entity_i = 0;

	//-----第一行分割（已完成）---//
	for (int i = 0; i < str1_size; i++)
	{
		if (str1[i] == '_')
		{
			if (substr_start == 0)
				substr = str1.substr(substr_start, substr_n);
			else
				substr = str1.substr(substr_start, substr_n - 1);
			
			//cout << i << " " << substr << endl;
			EntityName.push_back(substr);
			map1.insert(pair<string, vector<string>>(EntityName[Entity_i], vec_str));

			substr.clear();
			substr_start = i+1;
			substr_n = 0;
		}
		else if (str1[i] == '|')
		{
			substr = str1.substr(substr_start, substr_n-1);
			map1[EntityName[Entity_i]].push_back(substr);

			substr.clear();
			substr_start = i+1;
			substr_n = 0;
		}
		else if (str1[i] == ';')
		{
			substr = str1.substr(substr_start, substr_n-1);
			map1[EntityName[Entity_i]].push_back(substr);

			Entity_i++;
			substr.clear();
			substr_start = i+1;
			substr_n = 0;
		}
		else if (i == str1_size-1)
		{
			substr = str1.substr(substr_start, substr_n);
			map1[EntityName[Entity_i]].push_back(substr);

			Entity_i++;
			substr.clear();
			substr_start = i + 1;
			substr_n = 0;
		}
		else
		{

		}
		substr_n++;
	}
	//-----第一行分割（已完成）---//
/*
*/
for (map<string, vector<string>>::iterator it_map = map1.begin(); it_map != map1.end(); it_map++)
{
cout << it_map->first << ": ";
for (vector<string>::iterator it_vec = it_map->second.begin(); it_vec != it_map->second.end(); it_vec++)
{
cout << *it_vec << ";";
}
cout << endl;
}


	system("pause");
	return 0;
}
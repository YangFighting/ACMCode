
/*
����:
�������ݰ������У�
��һ�У�ʵ���б�����ʵ��֮���÷ֺŸ�����ʵ������ʵ��ֵ֮�����»��߸��������ʵ��ֵ֮�������߸��������б�㶼��Ӣ��״̬�µģ���ʽ���£�
ʵ������1_ʵ��ֵ1|ʵ��ֵ2|��;ʵ������2_ʵ��ֵ1|ʵ��ֵ2|��;��
�ڶ��У��û�����Ȼ����ָ��
���:
������˹ؼ��ʵ�ָ�ָ���еĹؼ���ǰ���һ���ո񱻵����ֳ��������ں������"/"+ʵ����������ǡ����һ��ʵ��ֵ���ڶ��ʵ�壬����Щʵ�嶼��ǳ�����������ʵ�����Ƶ��ַ���˳���������У����Զ��ŷָ���
���뷶��:
singer_�ܽ�|�ܽ���|���»�|������;song_����|������ӭ��|������;actor_�ܽ���|��ٳ
�벥���ܽ��׵������������
�������:
�벥�� �ܽ���/actor,singer �� ������/song ������

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
	str1 = "singer_�ܽ�|�ܽ���|���»�|������;song_����|������ӭ��|������;actor_�ܽ���";
	//getline(cin, str2);

	map<string, vector<string>> map1;
	vector<string> vec_str;
	int str1_size = str1.size();
	string substr, singerName;
	vector<string> EntityName;
	int substr_start = 0;
	int substr_n = 0;
	int Entity_i = 0;

	//-----��һ�зָ����ɣ�---//
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
	//-----��һ�зָ����ɣ�---//
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
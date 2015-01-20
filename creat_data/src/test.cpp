#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include<fstream>
#include "json\json.h"
using namespace std;
/*
	生成[m,n]范围内的随机数
*/

inline int rand_m_n(int m, int n)
{
	static int count = 0;//count做种子
	srand(count++);
	int  Result;
	int low = m;
	int up = n;
	if (m > n)
	{
		int temp = low;
		low = up;
		up = temp;
	}
	Result = low +  rand() %(up-low );

	return Result;
}
/*
	生成一个字符串
*/
inline string creat_str(int &m, int &n)
{
	string s1 = "abcdefghij";
	string s2;
	int str_count = rand_m_n(m, n);
	for (int i = 0; i < str_count; i++)
	{
		s2 = s2 + s1[rand_m_n(0, 9)];
	}
	return s2;
}
/*
	生成指定行数据到Sequence.txt
*/
void creat_data(int &m, int &n, int &num)
{
	Json::Reader reader;
	Json::Value json_object;
	ofstream outfile;
	ifstream fin("data.txt");
	outfile.open("Sequence.txt",ios::trunc);
	int flag = 0;
	string JsonStr;
	while (getline(fin,JsonStr)&&flag<num)
	{
		reader.parse(JsonStr, json_object, false);
		string jsonID = json_object["ID"].toStyledString();
		outfile << jsonID.substr(1,jsonID.size()-3) +"  "+creat_str(m, n) << endl;
		flag++;
	}
	outfile.close();
}
int main()
{
	int m, n,num;
	cout << "请输入一个序列的字母个数范围：" << endl;
	cout << "区间左值：" << endl;
	cin >> m;
	cout << "区间右值：" << endl;
	cin >> n;
	cout <<"请输入需要多少行数据："<< endl;
	cin >> num;
	creat_data(m, n, num);
	cout << "文件生成完毕" << endl;
	int i;
	cin >> i;
	return 0;
}
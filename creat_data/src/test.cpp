#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include<fstream>
#include "json\json.h"
using namespace std;
/*
	����[m,n]��Χ�ڵ������
*/

inline int rand_m_n(int m, int n)
{
	static int count = 0;//count������
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
	����һ���ַ���
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
	����ָ�������ݵ�Sequence.txt
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
	cout << "������һ�����е���ĸ������Χ��" << endl;
	cout << "������ֵ��" << endl;
	cin >> m;
	cout << "������ֵ��" << endl;
	cin >> n;
	cout <<"��������Ҫ���������ݣ�"<< endl;
	cin >> num;
	creat_data(m, n, num);
	cout << "�ļ��������" << endl;
	int i;
	cin >> i;
	return 0;
}
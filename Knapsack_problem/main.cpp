#include <iostream>
#define num 5
#define weight  11
using namespace std;

void init_table(int table[num][weight])
{
	for (size_t i = 0; i < num; i++)
	{
		for (size_t j = 0; j < weight; j++)
		{
			table[i][j] = 0;
		}
	}

}
void show_table(int table[num][weight])
{
	for (size_t i = 0; i < num; i++)
	{
		for (size_t j = 0; j < weight; j++)
		{
			cout <<table[i][j] << "\t";
		}
		cout << "\n";
	}

}
void creat_table(int table[num][weight],int w[],int v[])
{
	//给最后一行赋初值
	for (size_t i = 0; i < weight; i++)
	{
		if (w[num] > i)
			table[num - 1][i] = 0;
		else
		{
			table[num - 1][i] = v[num];
		}
	}
	//在最后一行基础上给每行赋值
	for (int i = num - 1; i > 0; i--)
	{
		for (int j = 0; j < weight; j++)
		{
			if (w[i]>j)
			{
				table[i - 1][j] = table[i][j];
			}
			else if ((v[i] + table[i][j-w[i]])>table[i][j])
			{
				table[i-1][j] = v[i] + table[i ][j - w[i]];
			}
			else
			{
				table[i-1][j] = table[i][j];
			}
		}
	}

}



void opt_way(int flag[],int w[], int table[num][weight])
{
	int n = weight-1;
	for (size_t i = 0; i < num; i++)
	{
		if (table[i][n]==table[i+1][n])
		{
			flag[i] = 0;
		}
		else
		{
			flag[i] = 1;
			n = n - w[i+1];
		}
	}

}
int main()
{
	int w[num+1] = {0,2,2,6,5,4};
	int  v[num+1]= {0,6,3,5,4,6};
	int flag[num] = { 0, 0, 0, 0, 0 };
	int table[num][weight];
	init_table(table);
	creat_table(table,w,v);
	opt_way(flag,w,table);
	//----------------
	show_table(table);
	//------------------------------
	for (size_t i = 0; i < num; i++)
	{
		cout << flag[i];
	}
	getchar();
	return 0;
}
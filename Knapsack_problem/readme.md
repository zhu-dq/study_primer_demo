[TOC]
#动态规划  背包问题
###问题描述
>有n个物体有重量和价值两个属性，一个能承重一定重量的背包。问怎么选择物体能实现背包里的价值最大化。
###问题具体化
>假设有5个物体和一个背包。物体的重量分别是2、2、6、5、4，即w[]={0、2、2、6、5、4}，价值分别是6、3、5、4、6，即v[]={0、6、3、5、4、6}。背包承重为10。问怎么选择，能实现背包所背物体价值的最大化。
### 解决过程
>利用二维表格，通过自左向右、自下向上的计算，来绘制表格，左后再在表格的基础上选择最优解。

- **表格最后一行**
>对最后一行的物体4来说，只有两种情况，要么装入背包，要么不装入。物体5的的重量是4。也就是说在背包承重为0--3的时候物体5是装不进去的，所以背包为0，当背包承重为4--10的时候，物体5可以装进去，又因为物体5的价值为6，所以背包价值为6。

       .|0|1|2|3|4|5|6|7|8|9|10
     ------|--------
     1|
     2|
     3|
     4|
     5|0|0|0|0|6|6|6|6|6|6|6
- **表格倒数第二行**
    >表格倒数第二行的计算思路与倒数第一不一样，因为我们要考虑背包里已经有的物体。因为物体4的重量为5。所以在背包承重为0--4的情况下即使空包也装不进去，所以不能装入，包里原本是多少价值，就还是多少价值。在背包承重为5--8的时候，物体4可以装进去，但是物体5要拿出来才行，这样的话背包的价值就变成4了，小于6。所以能然选择不把物体4放进去。在背包承重为9--10的时候，两个都可以放进去，所以背包的价值变成10了。
   
       .|0|1|2|3|4|5|6|7|8|9|10
     ------|--------
     1|
     2|
     3|
     4|0|0|0|0|6|6|6|6|6|10|10
     5|0|0|0|0|6|6|6|6|6|6|6
- **最终计算出来的表格**
>其他行的计算过程同上，最终结果如下。

       .|0|1|2|3|4|5|6|7|8|9|10
     ------|--------
     1|0|0|6|6|9|9|12|12|15|15|15
     2|0|0|3|3|6|6|9|9|9|10|11
     3|0|0|0|0|6|6|6|6|6|10|11
     4|0|0|0|0|6|6|6|6|6|10|10
     5|0|0|0|0|6|6|6|6|6|6|6
- ***表格计算公式**
>max(  m(i+1,j)   ,   m(i+1,j-wi)+vi  )

- **做出最优选择**
>大体思想：我们从右上角（坐标（1,10））开始，看（1,10）与（2,10）的值是不是一样，一样，则说明物体1没装进去，不一样，则说明物体1装进去了。
>void opt_way(int flag[],int w[], int table[num][weight])
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


-------------------


### 完整代码

```c++
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
```

###程序结果截图
>
![这里写图片描述](http://img.blog.csdn.net/20150315164106387)



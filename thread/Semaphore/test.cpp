// pthread_semaphore.cpp : 定义控制台应用程序的入口点。
//
#include <iostream>
#include <pthread.h>
#include "MySemaphore.h"
#include <unistd.h>
using namespace std;

//创建一个信号量，其计数值当前值为0，最大值为3
CMySemaphore g_MySem(0, 3);

//线程函数
void * StartThread(void *pParam)
{
	//休眠1秒，确保主线程函数main中
	//创建工作线程下一句g_MySem.Set();先执行
	sleep(1);

	g_MySem.Wait(); //信号量计数值减1

	cout<<"Do print StartThread"<<endl;

	return (void *)0;
}

int main(int argc, char* argv[])
{
	pthread_t thread;
	pthread_attr_t attr;

	assert ( !g_MySem.TryWait(10) );

	g_MySem.Set(); //信号量计数值加1

	g_MySem.Wait(); //信号量计数值减1

	try
	{
		g_MySem.Wait(100);
		cout<<"must timeout"<<endl; //此处发生超时
	}
	catch (...)
	{
		cout<<"wrong exception"<<endl;
	}

	g_MySem.Set();
	g_MySem.Set();
	assert ( g_MySem.TryWait(0) );
	g_MySem.Wait();
	assert ( !g_MySem.TryWait(10) );

	//创建工作线程
	pthread_attr_init(&attr);
	pthread_attr_setdetachstate(&attr,PTHREAD_CREATE_JOINABLE);
	if (pthread_create(&thread,&attr, StartThread,NULL) == -1)
	{
		cout<<"StartThread: create failed"<<endl;
	}

	g_MySem.Set();

	//等待线程结束
	void *result;
	pthread_join(thread,&result);

	assert ( !g_MySem.TryWait(10) ); //若将断言中的 ! 去掉，则会发生断言错误

	//关闭线程句柄，释放资源
	pthread_attr_destroy(&attr);

	int iWait;
	cin>>iWait;
	return 0;
}


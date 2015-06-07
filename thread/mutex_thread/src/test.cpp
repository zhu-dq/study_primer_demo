#include <iostream>
#include <unistd.h>
#include "Lock.h"

using namespace std;

//创建一个互斥锁
CMutex g_Lock;


//线程函数
void * StartThread(void *pParam)
{
	char *pMsg = (char *)pParam;
	if (!pMsg)
	{
		return (void *)1;
	}

	//对被保护资源（以下打印语句）自动加锁
	//线程函数结束前，自动解锁
	CMyLock lock(g_Lock);

	for( int i = 0; i < 5; i++ )
	{
		cout << pMsg << endl;
		sleep( 1 );
	}

	return (void *)0;
}

int main(int argc, char* argv[])
{
	pthread_t thread1,thread2;
	pthread_attr_t attr1,attr2;

	char *pMsg1 = "First print thread.";
	char *pMsg2 = "Second print thread.";

	//创建两个工作线程，分别打印不同的消息
	pthread_attr_init(&attr1);
	pthread_attr_setdetachstate(&attr1,PTHREAD_CREATE_JOINABLE);
	if (pthread_create(&thread1,&attr1, StartThread,pMsg1) == -1)
	{
		cout<<"Thread 1: create failed"<<endl;
	}
	pthread_attr_init(&attr2);
	pthread_attr_setdetachstate(&attr2,PTHREAD_CREATE_JOINABLE);
	if (pthread_create(&thread2,&attr2, StartThread,pMsg2) == -1)
	{
		cout<<"Thread 2: create failed"<<endl;
	}

	//等待线程结束
	void *result;
	pthread_join(thread1,&result);
	pthread_join(thread2,&result);

	//关闭线程，释放资源
	pthread_attr_destroy(&attr1);
	pthread_attr_destroy(&attr2);

	int iWait;
	cin>>iWait;

	return 0;
}

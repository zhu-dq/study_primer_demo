#ifndef Semaphore_Header
#define Semaphore_Header

#include <iostream>
#include <pthread.h>
#include <errno.h>
#include <assert.h>

using namespace std;

//------------------------------------------------------------------------

class CSemaphoreImpl
{
protected:
	CSemaphoreImpl(int n, int max);		
	~CSemaphoreImpl();
	void SetImpl();
	void WaitImpl();
	bool WaitImpl(long lMilliseconds);

private:
	volatile int    m_n;
	int             m_max;
	pthread_mutex_t m_mutex;
	pthread_cond_t  m_cond;
};

inline void CSemaphoreImpl::SetImpl()
{
	if (pthread_mutex_lock(&m_mutex))	
		cout<<"cannot signal semaphore (lock)"<<endl;
	if (m_n < m_max)
	{
		++m_n;
	}
	else
	{
		pthread_mutex_unlock(&m_mutex);
		cout<<"cannot signal semaphore: count would exceed maximum"<<" m_n = "<<m_n<<"m_max = "<<m_max<<endl;
	}
	//重新开始等待m_cond的线程，可被调度
	if (pthread_cond_signal(&m_cond))
	{
		pthread_mutex_unlock(&m_mutex);
		cout<<"cannot signal semaphore"<<endl;
	}
	pthread_mutex_unlock(&m_mutex);
}

//------------------------------------------------------------------------

/*

 信号量同步机制
 信号量提供一个计数值，可以进行原子操作。V 将计数值加1，使得
 等待该信号量的线程可以被调用（调用Set()），P 将计数值减1，使
 当前线程被挂起，进行睡眠（调用Wait()）。
 当信号量的计数值被初始化为0时，调用P操作，将挂起当前线程。
 当信号量被激活，即调用V操作后，被挂起的线程就有机会被重新调度了。

*/

class CMySemaphore: private CSemaphoreImpl
{
public:

	/*
	 创建一个信号量，信号量计数值当前值为参数n，最大值为max。
	 如果只有n，则n必须大于0；如果同时有n和max,则n必须不小
	 于0，且不大于max
	*/
	CMySemaphore(int n);
	CMySemaphore(int n, int max);
	
	/*
	 销毁一个信号量
	*/
	~CMySemaphore();

	/*
	 对信号量计数值做加1动作，信号量变为有信号状态，使得
	 另一个等待该信号量的线程可以被调度
	*/
	void Set();

	/*
	 对信号量计数值做减1动作，信号量变为无信号状态。若
	 计数值变得大于0时，信号量才会变为有信号状态。
	*/
	void Wait();

	/*
	 在给定的时间间隔里等待信号量变为有信号状态，若成功，
	 则将计数值减1，否则将发生超时。
	*/
	void Wait(long lMilliseconds);

	/*
	 在给定的时间间隔里等待信号量变为有信号状态，若成功，
	 则将计数值减1，返回true；否则返回false。
	*/
	bool TryWait(long lMilliseconds);

private:
	CMySemaphore();
	CMySemaphore(const CMySemaphore&);
	CMySemaphore& operator = (const CMySemaphore&);
};

inline void CMySemaphore::Set()
{
	SetImpl();
}


inline void CMySemaphore::Wait()
{
	WaitImpl();
}


inline void CMySemaphore::Wait(long lMilliseconds)
{
	if (!WaitImpl(lMilliseconds))
		cout<<"time out"<<endl;
}

inline bool CMySemaphore::TryWait(long lMilliseconds)
{
	return WaitImpl(lMilliseconds);
}

#endif

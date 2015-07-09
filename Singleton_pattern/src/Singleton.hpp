#ifndef _SINGLETON_HPP
#define _SINGLETON_HPP
/*
	 //          方法1

#include <mutex>

template<class T>
class Singleton
{
private:
	Singleton(){}
	~Singleton(){}
	static std::mutex _mutex;
	static T* single;
public:
	static T* instance()
	{
		if (single == nullptr)
		{
			_mutex.lock();
			if (single == nullptr)
				{
					single = new T();
					std::atexit(destroy);//通过new关键字创建类型实例的时候，我们同时通过atexit()函数注册了释放该实例的函数，从而保证了这些实例能够在程序退出前正确地析构。该函数的特性也能保证后被创建的实例首先被析构。
				}
			_mutex.unlock();
		}
		return single;
	}
	//你的考虑是对的。但是在实际生产项目上，是不需要考虑销毁时的线程安全的。由于单例模式，就创建一个实例，在程序退出时，都是集中进行销毁这一个实例的，也就是说，只有一个线程去做销毁的工作，一般的情况下，我们不会说去使用多个线程去销毁资源，这样的话，是给自己找罪受。
	static void destroy()
	{
		delete single;
		single = nullptr;
	}

};
template <class T> std::mutex Singleton<T>::_mutex;
template <class T> T* Singleton<T>::single = nullptr;
*/


			//             方法2  
#include <mutex>
#include <memory>
template <class T>
class Singleton
{
private:
	Singleton(){}
	static void  init()
	{
		single = new T();
		std::atexit(destroy);
	}
	static T* single;
	static std::once_flag single_created;
public:
	static T* instance()
	{
		std::call_once(single_created,init);
		return  single;
	}
	static void destroy()
	{
		delete single;
		single = nullptr;
	}
};
template<class T> T* Singleton<T>::single = nullptr;
template<class T> std::once_flag Singleton<T>::single_created; 
#endif
#ifndef _SINGLETON_HPP
#define _SINGLETON_HPP
/*
	 //          ����1

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
					std::atexit(destroy);//ͨ��new�ؼ��ִ�������ʵ����ʱ������ͬʱͨ��atexit()����ע�����ͷŸ�ʵ���ĺ������Ӷ���֤����Щʵ���ܹ��ڳ����˳�ǰ��ȷ���������ú���������Ҳ�ܱ�֤�󱻴�����ʵ�����ȱ�������
				}
			_mutex.unlock();
		}
		return single;
	}
	//��Ŀ����ǶԵġ�������ʵ��������Ŀ�ϣ��ǲ���Ҫ��������ʱ���̰߳�ȫ�ġ����ڵ���ģʽ���ʹ���һ��ʵ�����ڳ����˳�ʱ�����Ǽ��н���������һ��ʵ���ģ�Ҳ����˵��ֻ��һ���߳�ȥ�����ٵĹ�����һ�������£����ǲ���˵ȥʹ�ö���߳�ȥ������Դ�������Ļ����Ǹ��Լ������ܡ�
	static void destroy()
	{
		delete single;
		single = nullptr;
	}

};
template <class T> std::mutex Singleton<T>::_mutex;
template <class T> T* Singleton<T>::single = nullptr;
*/


			//             ����2  
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
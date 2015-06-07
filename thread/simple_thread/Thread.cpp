/*
 * 这里我们用Thread这个类来实现线程的封装，
 * 用户自己要启用的线程类都要继承这个Thread类，
 * 在Thread类的Start函数里，调用了pthread_create创建了一个线程，
 * 并将ThreadFunc设置为线程函数，把线程的this指针传递给了这个函数，
 * 在这个线程函数里调用了虚函数Run，这个Run函数最终会利用多态调用到用户线程类的Run函数，
 * 这就是下面代码的基本原理
*/
#include <iostream>
#include <pthread.h>
#include <string>
#include <unistd.h>
using namespace std;
class Thread
{
    public:
    Thread(){}    
    virtual ~Thread(){}
    void start()//，调用了pthread_create创建了一个线程，
    {
        pthread_create(&TID,NULL,ThreadFunc,this);
    }
    static void* ThreadFunc(void* pth)// 并将ThreadFunc设置为线程函数，把线程的this指针传递给了这个函数，
    {
        Thread* p = static_cast<Thread*>(pth);
        p->Run();// 在这个线程函数里调用了虚函数Run，这个Run函数最终会利用多态调用到用户线程类的Run函数，
        return 0;
    }
    virtual void Run()=0;
    private:
    pthread_t TID;
};

class Test : public Thread{
    virtual void Run(){
        while(1){
            cout<<"thread run : \n";
        }
    }
};

int main()
{
    Thread* test = new Test();
    test->start();
    usleep(100);
    return 0;

}

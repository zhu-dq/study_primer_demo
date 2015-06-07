#include <iostream>
#include "threadpool.h"
#include <unistd.h>
using namespace std;


#define ITERATIONS 20

class SampleWorkerThread : public WorkerThread
{
public:
    int id;
 unsigned virtual executeThis()
 {
 // Instead of sleep() we could do anytime consuming work here.
 // Using ThreadPools is advantageous only when the work to be done is really time consuming. (atleast 1 or 2 seconds)
  cout<<"This is SampleWorkerThread sleep 2s"<<endl;
  sleep(2);
  return(0);
 }

    SampleWorkerThread(int id) : WorkerThread(id), id(id)
    {
//      cout << "Creating SampleWorkerThread " << id << "\t address=" << this << endl;
    }

    ~SampleWorkerThread()
    {
//      cout << "Deleting SampleWorkerThread " << id << "\t address=" << this << endl;
    }
};


int main(int argc, char **argv)
{
 
 cout<<"Thread pool"<<endl;
 ThreadPool* myPool = new ThreadPool(25);
 //pthread_create()执行，开始等待任务分配
 myPool->initializeThreads();

 //用来计算时间间隔。
    time_t t1=time(NULL);

 //分配具体工作到线程池
 for(unsigned int i=0;i<ITERATIONS;i++){
  SampleWorkerThread* myThreathreadExecuted = new SampleWorkerThread(i);
  myPool->assignWork(myThreathreadExecuted);
 }
 
 //销毁钱等待所有线程结束，等待间隔为2秒。
    myPool->destroyPool(2);

    time_t t2=time(NULL);
    cout << t2-t1 << " seconds elapsed\n" << endl;
 delete myPool;
 
    return 0;
}

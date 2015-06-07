#include <pthread.h>
#include <semaphore.h>
#include <iostream>
#include <vector>

using namespace std;
/*
WorkerThread class
This class needs to be sobclassed by the user.
*/
class WorkerThread{
public:
    int id;
    unsigned virtual executeThis()
 {
  return 0;
 }

    WorkerThread(int id) : id(id) {}
    virtual ~WorkerThread(){}
};

/*
ThreadPool class manages all the ThreadPool related activities. This includes keeping track of idle threads and synchronizations between all threads.
*/
class ThreadPool{
public:
    ThreadPool();
    ThreadPool(int maxThreadsTemp);
    virtual ~ThreadPool();
 
 void destroyPool(int maxPollSecs);

    bool assignWork(WorkerThread *worker);
    bool fetchWork(WorkerThread **worker);

 void initializeThreads();
 
    static void *threadExecute(void *param); // pthread_create()调用的函数必须为静态的 
    static pthread_mutex_t mutexSync;
    static pthread_mutex_t mutexWorkCompletion;//工作完成个数互斥量
 
    
private:
    int maxThreads;
    
    pthread_cond_t  condCrit;
    sem_t availableWork;
    sem_t availableThreads;

    vector<WorkerThread *> workerQueue;

    int topIndex;
    int bottomIndex;
 int incompleteWork;
    int queueSize;
};

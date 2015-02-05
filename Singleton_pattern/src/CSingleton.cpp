#include <iostream>
using namespace std;
class CSingleton
{
    private:
        CSingleton()//单例模式特点1：构造私有化
        {
            cout<<"in the structure"<<endl;
        }
        static CSingleton *p_instance;
        class recover//写这个类专门为了最后释放单例的指针。利用的是c++在程序结束时会自动析构所有全局变量和静态成员变量。
        {
            public:
                ~recover()
                {
                    if(CSingleton::p_instance)
                    {
                        cout<<"end"<<endl;
                    delete CSingleton::p_instance;
                    }
                }
        };
        static  recover r;
    public:
        static CSingleton * GetInstance()//单例模式核心：只new一次
        {
            if(CSingleton::p_instance==NULL)
            {
              p_instance =new CSingleton();
            }             
            return p_instance;
        }
        void speak()
        {
            cout<<"speak"<<endl;
        }
};
CSingleton * CSingleton::p_instance=CSingleton::GetInstance();//静态变量要在类外初始化，它在类内只是声明状态
CSingleton::recover CSingleton::r;//静态变量要在类外初始化，不然会报错
int main()
{
    CSingleton *cs=CSingleton::GetInstance();
   cs->speak();
    CSingleton *cs1 = cs->GetInstance();
    cs1->speak();
    return 0;
}


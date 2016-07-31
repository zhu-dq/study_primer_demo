#include <iostream>
#include <memory>
#include <assert.h>
using namespace std;
/*
 *  智能指针循环引用 
 */
class B;
class A{
    public:
        std::shared_ptr<B> b_ptr_;
};
class B{
    public:
        std::shared_ptr<A> a_ptr_;
};
/*
 * weak_ptr 解决循环引用问题
 */
class BB;
class AA{
    public:
        std::weak_ptr<BB> bb_ptr_;
};
class BB{
    public:
        std::weak_ptr<AA> aa_ptr_;
};

std::weak_ptr<A> test_a_b()
{
  std::shared_ptr<A> a(new A());
  std::shared_ptr<B> b(new B());
  a->b_ptr_ = b;
  b->a_ptr_ = a;
  cout<<"a count "<<a.use_count()<<endl;
  cout<<"b count "<<b.use_count()<<endl;
  return std::weak_ptr<A>(a);
}

std::weak_ptr<AA> test_aa_bb()
{
  std::shared_ptr<AA> aa(new AA());
  std::shared_ptr<BB> bb(new BB());
  aa->bb_ptr_ = bb;
  bb->aa_ptr_ = aa;
  cout<<"aa count "<<aa.use_count()<<endl;
  cout<<"bb count "<<bb.use_count()<<endl;
  return std::weak_ptr<AA>(aa);
}

int main()
{
    std::weak_ptr<A> a = test_a_b();
   // assert(a.lock()==nullptr);//此处报错，说明内存泄漏
    shared_ptr<A> a_err(a.lock());
    cout<<"本该释放的内存里还有"<<a_err.use_count()<<"个引用！(算上a_err)"<<endl;
    std::weak_ptr<AA> aa = test_aa_bb();
    assert(aa.lock()==nullptr);
    return 0;
}

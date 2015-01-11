#include "Qcopy.h"
#include "Scopy.h"
#include "Iptr.h"
#include <iostream>
/*
		测试浅拷贝  缺点:容易产生野指针 造成内存泄露
*/
void testQcopy()
{
	int *i = new int(42);
	Qcopy q1(i,33);
	Qcopy q2 = q1;
	std::cout << "浅拷贝修改前的数据" << std::endl;
	std::cout << q1.get_data() << "," << q1.get_ptr() << "," << q1.get_ptr_data() << std::endl;
	std::cout << q2.get_data() << "," << q2.get_ptr() << "," << q2.get_ptr_data() << std::endl;
	/*
		修改数据
	*/
	q1.set_ptr_data(54);
	std::cout << "浅拷贝修改后的数据(原指针和新指针的数据都被修改了，这可能不是我们想要的情况)" << std::endl;
	std::cout << q1.get_data() << "," << q1.get_ptr() << "," << q1.get_ptr_data() << std::endl;
	std::cout << q2.get_data() << "," << q2.get_ptr() << "," << q2.get_ptr_data() << std::endl;
	/*
		delete指针带来的悲剧---悬垂指针（野指针）
	*/
	delete i;
	std::cout << "浅拷贝delete后的数据（q1和q2开始乱指了）" << std::endl;
	std::cout << q1.get_data() << "," << q1.get_ptr() << "," << q1.get_ptr_data() << std::endl;
	std::cout << q2.get_data() << "," << q2.get_ptr() << "," << q2.get_ptr_data() << std::endl;
}
/*
		测试深拷贝   缺点占用大量内存
*/
void testScopy()
{
	int *i = new int(42);
	Scopy s1(i,33);
	Scopy s2 = s1;
	std::cout << "深拷贝修改前的数据" << std::endl;
	std::cout << s1.get_data() << "," << s1.get_ptr() << "," << s1.get_ptr_data() << std::endl;
	std::cout << s2.get_data() << "," << s2.get_ptr() << "," << s2.get_ptr_data() << std::endl;
	/*
	修改数据
	*/
	s1.set_ptr_data(54);
	std::cout << "深拷贝修改后的数据(互不影响)" << std::endl;
	std::cout << s1.get_data() << "," << s1.get_ptr() << "," << s1.get_ptr_data() << std::endl;
	std::cout << s2.get_data() << "," << s2.get_ptr() << "," << s2.get_ptr_data() << std::endl;
	/*
	delete 指针不会带来影响
	*/
	delete i;
	std::cout << "深拷贝delete后的数据（q1和q2还有自己的地址和值）" << std::endl;
	std::cout << s1.get_data() << "," << s1.get_ptr() << "," << s1.get_ptr_data() << std::endl;
	std::cout << s2.get_data() << "," << s2.get_ptr() << "," << s2.get_ptr_data() << std::endl;
}
/*
		测试智能指针
*/
void testIptr()
{
	//int  *p1 = new int(44);
	Iptr ip1(new int(44), 33);
	Iptr ip2(ip1);
	Iptr ip3 = ip1;
	std::cout << "ip1: \t"<<ip1.get_data() << "\t  ip2: "<<ip2.get_data() << "\t  ip3: " <<ip3.get_data()<< std::endl;
	std::cout << "指针对比：" << std::endl;
	std::cout << ip1.get_ptr() << "\n" << ip2.get_ptr() << "\n" << ip3.get_ptr() << std::endl;
	/*
		修改后
	*/
	std::cout << "---------------------------------------------------------修改后----------------------------------------" << std::endl;
	//int  *p2 = new int(88);
	Iptr  ip4(new int(88), 66);
	//*p1 = 55;
	ip2.set_data(10);
	ip3 = ip4;
	std::cout << "\t  ip1:" << ip1.get_data() << "\t  ip2:"<<ip2.get_data()<<"\t  ip3:" << ip3.get_data() << "\t  ip4:" << ip4.get_data() << std::endl;
	std::cout << "指针对比：" << std::endl;
	std::cout << ip1.get_ptr() << "\n" <<ip2.get_ptr()<<"\n"<< ip3.get_ptr() << "\n" << ip4.get_ptr() << std::endl;
	/*
			删除后
	*/
	std::cout << "-----------------------------------------------------------删除后----------------------------------------" << std::endl;
	//delete p1;
	//delete p2;
	std::cout << "\t   ip1:" << ip1.get_data() << "\t  ip2:" << ip2.get_data() << "\t  ip3:" << ip3.get_data() << "\t  ip4:" << ip4.get_data() << std::endl;
	std::cout << "指针对比：" << std::endl;
	std::cout << ip1.get_ptr() << "\n" << ip2.get_ptr() << "\n" << ip3.get_ptr() << "\n" << ip4.get_ptr() << std::endl;
}
int main()
{
	//testQcopy();   
	//testScopy();
	testIptr();
	getchar();
	return 0;
}
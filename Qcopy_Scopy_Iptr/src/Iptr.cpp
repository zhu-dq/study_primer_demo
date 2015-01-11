#include "Iptr.h"
Iptr::Iptr()
{
}
Iptr::Iptr(int *p, int d) :ptr(new U_Ptr(p)), data(d){ std::cout << "构造：new了个新的。当前计数为" + std::to_string(ptr->count) + "" << std::endl; }
Iptr::Iptr(const Iptr &org) : ptr(org.ptr), data(org.data)
{
	org.ptr->count++;// 与ptr->count++效果一样。因为指的是同一块内存
	std::cout << "拷贝了一次，当前计数为" + std::to_string(ptr->count) + "" << std::endl;
}
Iptr& Iptr::operator = (const Iptr &org)
{
	if (--ptr->count == 0) //左值减
	{
		delete ptr; 
		std::cout << "在赋值操作符里被杀了" << std::endl;
	}
	org.ptr->count++;//右值加
	std::cout << "利用赋值操作符赋值了一次，右值当前计数为" + std::to_string(org.ptr->count) + "" << std::endl;
	ptr = org.ptr;
	data = org.data;
	return *this;
}
int   Iptr::get_data()
{
	return data;
}
int*  Iptr::get_ptr()
{
	return  ptr->ptr;
}
int Iptr::get_ptr_count() const
{
	return  ptr->count;
}
void Iptr::set_data(int d)
{
	data = d;
}
void Iptr::set_ptr(int *p)
{
	ptr->ptr = p;
}
void Iptr::set_ptr_data(int d)
{
	*ptr->ptr = d;
}
int  Iptr::get_ptr_data() const
{
	return *ptr->ptr;
}
Iptr::~Iptr()
{
	std::cout << "当前计数为" + std::to_string(ptr->count) + "" << std::endl;
	std::cout << "调用了析构后" + std::to_string(ptr->count-1) + "" << std::endl;
	if (--ptr->count == 0)
	{
		delete ptr;
		std::cout << "在析构里被杀了" << std::endl;
	}
	}

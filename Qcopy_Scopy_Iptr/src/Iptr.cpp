#include "Iptr.h"
Iptr::Iptr()
{
}
Iptr::Iptr(int *p, int d) :ptr(new U_Ptr(p)), data(d){ std::cout << "���죺new�˸��µġ���ǰ����Ϊ" + std::to_string(ptr->count) + "" << std::endl; }
Iptr::Iptr(const Iptr &org) : ptr(org.ptr), data(org.data)
{
	org.ptr->count++;// ��ptr->count++Ч��һ������Ϊָ����ͬһ���ڴ�
	std::cout << "������һ�Σ���ǰ����Ϊ" + std::to_string(ptr->count) + "" << std::endl;
}
Iptr& Iptr::operator = (const Iptr &org)
{
	if (--ptr->count == 0) //��ֵ��
	{
		delete ptr; 
		std::cout << "�ڸ�ֵ�������ﱻɱ��" << std::endl;
	}
	org.ptr->count++;//��ֵ��
	std::cout << "���ø�ֵ��������ֵ��һ�Σ���ֵ��ǰ����Ϊ" + std::to_string(org.ptr->count) + "" << std::endl;
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
	std::cout << "��ǰ����Ϊ" + std::to_string(ptr->count) + "" << std::endl;
	std::cout << "������������" + std::to_string(ptr->count-1) + "" << std::endl;
	if (--ptr->count == 0)
	{
		delete ptr;
		std::cout << "�������ﱻɱ��" << std::endl;
	}
	}

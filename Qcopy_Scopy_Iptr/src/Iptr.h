#include <iostream>
#include <string>
#ifndef IPTR_H
#define IPTR_H
#pragma once
class Iptr
{
public:
	/*
		����ָ���� 
	*/
	class U_Ptr
	{
		friend class Iptr;
		private:
			int *ptr;
			size_t count ;
			U_Ptr(int *p) :ptr(p), count(1){}
			int& operator * (){ return *ptr; }
			int*  operator -> () { return ptr; }
			~U_Ptr()
			{
				delete ptr;
				std::cout << "U_ptr����������" << std::endl;
			}
	};
	/*
		Ĭ�Ϲ��캯��
	*/
	Iptr();
	/*
		���ι��캯��
	*/
	explicit Iptr(int *p, int d);
	/*
		�������캯��
	*/
	Iptr(const Iptr &org);
	/*
		��ֵ������
	*/
	Iptr &  operator = (const Iptr &org);
	/*
	set����
	*/
	void set_ptr(int *p);
	void set_data(int d);
	/*
	get����
	*/
	int* get_ptr();
	int  get_data();
	/*
	��ָ��ptr��ָ���ݵĲ���
	*/
	int      get_ptr_count() const;
	int     get_ptr_data() const;
	void   set_ptr_data(int d);
	~Iptr();
private:
	U_Ptr *ptr;
	int data;
};

#endif
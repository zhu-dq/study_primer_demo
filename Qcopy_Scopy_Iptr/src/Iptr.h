#include <iostream>
#include <string>
#ifndef IPTR_H
#define IPTR_H
#pragma once
class Iptr
{
public:
	/*
		智能指针类 
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
				std::cout << "U_ptr的析构函数" << std::endl;
			}
	};
	/*
		默认构造函数
	*/
	Iptr();
	/*
		带参构造函数
	*/
	explicit Iptr(int *p, int d);
	/*
		拷贝构造函数
	*/
	Iptr(const Iptr &org);
	/*
		赋值操作符
	*/
	Iptr &  operator = (const Iptr &org);
	/*
	set操作
	*/
	void set_ptr(int *p);
	void set_data(int d);
	/*
	get操作
	*/
	int* get_ptr();
	int  get_data();
	/*
	对指针ptr所指内容的操作
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
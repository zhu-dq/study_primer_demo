#ifndef  SCOPY_H
#define SCOPT_H

#pragma once
class Scopy
{
public:
	/*
		默认构造
	*/
	Scopy();
	/*
		带参构造函数
	*/
	Scopy(int *p , int d);
	/*
		拷贝构造函数
	*/
	Scopy (const Scopy &org);
	/*
		赋值操作符
	*/
	Scopy& operator = (const Scopy& org);
	/*
	set操作
	*/
	void set_ptr(int *p) ;
	void set_data(int d) ;
	/*
	get操作
	*/
	int* get_ptr() const;
	int  get_data() const;
	/*
	对指针ptr所指内容的操作
	*/
	int      get_ptr_data() const;
	void   set_ptr_data(int d) const;
	~Scopy();
private:
	int  data;
	int  *ptr;
};
#endif

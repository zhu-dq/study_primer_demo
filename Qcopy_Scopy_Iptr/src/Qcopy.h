#pragma once
#ifndef QCOPY_H
#define QCOPY_H
class Qcopy
{
public:
	/*
		默认构造
	*/
	Qcopy();
	/*
		带参构造
	*/
	Qcopy(int *ptr, int data);
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
	int      get_ptr_data() const;
	void   set_ptr_data(int d) const;
	~Qcopy();
private:
	int *ptr;
	int data;
};
#endif


#pragma once
#ifndef QCOPY_H
#define QCOPY_H
class Qcopy
{
public:
	/*
		Ĭ�Ϲ���
	*/
	Qcopy();
	/*
		���ι���
	*/
	Qcopy(int *ptr, int data);
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
	int      get_ptr_data() const;
	void   set_ptr_data(int d) const;
	~Qcopy();
private:
	int *ptr;
	int data;
};
#endif


#ifndef  SCOPY_H
#define SCOPT_H

#pragma once
class Scopy
{
public:
	/*
		Ĭ�Ϲ���
	*/
	Scopy();
	/*
		���ι��캯��
	*/
	Scopy(int *p , int d);
	/*
		�������캯��
	*/
	Scopy (const Scopy &org);
	/*
		��ֵ������
	*/
	Scopy& operator = (const Scopy& org);
	/*
	set����
	*/
	void set_ptr(int *p) ;
	void set_data(int d) ;
	/*
	get����
	*/
	int* get_ptr() const;
	int  get_data() const;
	/*
	��ָ��ptr��ָ���ݵĲ���
	*/
	int      get_ptr_data() const;
	void   set_ptr_data(int d) const;
	~Scopy();
private:
	int  data;
	int  *ptr;
};
#endif

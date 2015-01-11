#include "Qcopy.h"
#include<iostream>

Qcopy::Qcopy()
{
}
Qcopy::Qcopy(int *ptr, int data) :ptr(ptr), data(data){}
void Qcopy::set_data(int d)
{
	data = d;
}
void Qcopy::set_ptr(int *p)
{
	ptr = p;
}
int Qcopy::get_data()
{
	return data;
}
int* Qcopy::get_ptr()
{
	return ptr;
}
void Qcopy::set_ptr_data(int d)  const
{
	*ptr = d;
}
int Qcopy::get_ptr_data() const
{
	return *ptr;
}
Qcopy::~Qcopy()
{
}

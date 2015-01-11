#include "Scopy.h"


Scopy::Scopy()
{
}
Scopy::Scopy( int *p, int d) :ptr(new int(*p)), data(d){}
Scopy::Scopy(const Scopy &org) : ptr(new int(*org.ptr)),data(org.data){}
Scopy& Scopy::operator=(const Scopy& org)
{
	ptr = new int(*org.ptr);
	data = org.data;
	return *this;
}
int  Scopy::get_data() const
{
	return data;
}
int *  Scopy::get_ptr() const
{
	return ptr;
}
int Scopy::get_ptr_data() const
{
	return *ptr;
}
void Scopy::set_data(int d) 
{
	data = d;
}
void Scopy::set_ptr(int *p) 
{
	ptr = new int(*p);
}
void Scopy::set_ptr_data(int d) const
{
	*ptr = data;
}
Scopy::~Scopy()
{
	delete ptr;
}

#include "Qcopy.h"
#include "Scopy.h"
#include "Iptr.h"
#include <iostream>
/*
		����ǳ����  ȱ��:���ײ���Ұָ�� ����ڴ�й¶
*/
void testQcopy()
{
	int *i = new int(42);
	Qcopy q1(i,33);
	Qcopy q2 = q1;
	std::cout << "ǳ�����޸�ǰ������" << std::endl;
	std::cout << q1.get_data() << "," << q1.get_ptr() << "," << q1.get_ptr_data() << std::endl;
	std::cout << q2.get_data() << "," << q2.get_ptr() << "," << q2.get_ptr_data() << std::endl;
	/*
		�޸�����
	*/
	q1.set_ptr_data(54);
	std::cout << "ǳ�����޸ĺ������(ԭָ�����ָ������ݶ����޸��ˣ�����ܲ���������Ҫ�����)" << std::endl;
	std::cout << q1.get_data() << "," << q1.get_ptr() << "," << q1.get_ptr_data() << std::endl;
	std::cout << q2.get_data() << "," << q2.get_ptr() << "," << q2.get_ptr_data() << std::endl;
	/*
		deleteָ������ı���---����ָ�루Ұָ�룩
	*/
	delete i;
	std::cout << "ǳ����delete������ݣ�q1��q2��ʼ��ָ�ˣ�" << std::endl;
	std::cout << q1.get_data() << "," << q1.get_ptr() << "," << q1.get_ptr_data() << std::endl;
	std::cout << q2.get_data() << "," << q2.get_ptr() << "," << q2.get_ptr_data() << std::endl;
}
/*
		�������   ȱ��ռ�ô����ڴ�
*/
void testScopy()
{
	int *i = new int(42);
	Scopy s1(i,33);
	Scopy s2 = s1;
	std::cout << "����޸�ǰ������" << std::endl;
	std::cout << s1.get_data() << "," << s1.get_ptr() << "," << s1.get_ptr_data() << std::endl;
	std::cout << s2.get_data() << "," << s2.get_ptr() << "," << s2.get_ptr_data() << std::endl;
	/*
	�޸�����
	*/
	s1.set_ptr_data(54);
	std::cout << "����޸ĺ������(����Ӱ��)" << std::endl;
	std::cout << s1.get_data() << "," << s1.get_ptr() << "," << s1.get_ptr_data() << std::endl;
	std::cout << s2.get_data() << "," << s2.get_ptr() << "," << s2.get_ptr_data() << std::endl;
	/*
	delete ָ�벻�����Ӱ��
	*/
	delete i;
	std::cout << "���delete������ݣ�q1��q2�����Լ��ĵ�ַ��ֵ��" << std::endl;
	std::cout << s1.get_data() << "," << s1.get_ptr() << "," << s1.get_ptr_data() << std::endl;
	std::cout << s2.get_data() << "," << s2.get_ptr() << "," << s2.get_ptr_data() << std::endl;
}
/*
		��������ָ��
*/
void testIptr()
{
	//int  *p1 = new int(44);
	Iptr ip1(new int(44), 33);
	Iptr ip2(ip1);
	Iptr ip3 = ip1;
	std::cout << "ip1: \t"<<ip1.get_data() << "\t  ip2: "<<ip2.get_data() << "\t  ip3: " <<ip3.get_data()<< std::endl;
	std::cout << "ָ��Աȣ�" << std::endl;
	std::cout << ip1.get_ptr() << "\n" << ip2.get_ptr() << "\n" << ip3.get_ptr() << std::endl;
	/*
		�޸ĺ�
	*/
	std::cout << "---------------------------------------------------------�޸ĺ�----------------------------------------" << std::endl;
	//int  *p2 = new int(88);
	Iptr  ip4(new int(88), 66);
	//*p1 = 55;
	ip2.set_data(10);
	ip3 = ip4;
	std::cout << "\t  ip1:" << ip1.get_data() << "\t  ip2:"<<ip2.get_data()<<"\t  ip3:" << ip3.get_data() << "\t  ip4:" << ip4.get_data() << std::endl;
	std::cout << "ָ��Աȣ�" << std::endl;
	std::cout << ip1.get_ptr() << "\n" <<ip2.get_ptr()<<"\n"<< ip3.get_ptr() << "\n" << ip4.get_ptr() << std::endl;
	/*
			ɾ����
	*/
	std::cout << "-----------------------------------------------------------ɾ����----------------------------------------" << std::endl;
	//delete p1;
	//delete p2;
	std::cout << "\t   ip1:" << ip1.get_data() << "\t  ip2:" << ip2.get_data() << "\t  ip3:" << ip3.get_data() << "\t  ip4:" << ip4.get_data() << std::endl;
	std::cout << "ָ��Աȣ�" << std::endl;
	std::cout << ip1.get_ptr() << "\n" << ip2.get_ptr() << "\n" << ip3.get_ptr() << "\n" << ip4.get_ptr() << std::endl;
}
int main()
{
	//testQcopy();   
	//testScopy();
	testIptr();
	getchar();
	return 0;
}
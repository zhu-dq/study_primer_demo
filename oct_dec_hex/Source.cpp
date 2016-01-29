#include <iostream>
#include <sstream>

int main(int argc, char * argv[])
{
	std::cout << "please input integer value" << std::endl;
	int  x = 0;
	std::cin >> x;
	std::cout << std::oct << x << std::endl;//8
	std::cout << std::dec << x << std::endl;//10
	std::cout << std::hex << x << std::endl;//16
	
	int hex_x = 0;
	std::istringstream("15")>>std::hex >> hex_x;
	std::cout << std::dec<<"hex_x :" << hex_x << std::endl;


	std::cout << "please input bool value" << std::endl;
	bool y;
	std::cin >> y;
	std::cout << std::boolalpha <<y<< std::endl;

	system("pause");

	return 0;
}
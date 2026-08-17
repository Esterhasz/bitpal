#include <iostream>
#include "colors.h"

using namespace std;

int main()
{
	std::cout << "\033[2;31m" << "Red" << "\033[0m" << std::endl;
	std::cout << "\033[31m" << "Red" << "\033[0m" << std::endl;
	std::cout << "\033[1;31m" << "Red" << "\033[0m" << std::endl;
	std::cout << "\033[91m" << "Red" << "\033[0m" << std::endl;

	return 0;
}
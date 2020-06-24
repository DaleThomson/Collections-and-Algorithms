#include "EmployeeDash.h"
#include "BinarySearchTree.h"
void EmployeeDash::print()
{
	std::cout << "Welcome to the Employee Dashboard.";
	std::cout << "\n\n1. Continue to the main site.";
}

void EmployeeDash::input(int input, AbstractPage** page)
{
	AbstractPage* p = *page;
	switch (input)
	{
	case 1:
		system("CLS");
		//*page = new BinarySearchTree(employee);
		*page = new mainPage(employee);
		delete p;
		break;
	default:
		system("CLS");
		std::cout << "Please select a valid option \n\n";
		system("Pause");
		system("CLS");
		break;
	}
}
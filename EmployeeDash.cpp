#include "EmployeeDash.h"
#include "BinarySearchTree.h"

//Prints the contents of the webpage
void EmployeeDash::print()
{
	std::cout << "Welcome to the Employee Dashboard.";
	std::cout << "\n\n1. Continue to the main site.";
	std::cout << "\n2. Log out";

	std::cout << "\n\nYour Selection: ";
}

// Handles the users inputs on the site.
void EmployeeDash::input(int input, AbstractPage** page)
{
	AbstractPage* p = *page;
	switch (input)
	{
	case 1:
		system("CLS");
		*page = new mainPage(employee);
		delete p;
		break;
	case 2:
		delete employee;
		system("CLS");
		*page = new Access();
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
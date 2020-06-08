#include "Access.h"

void Access::print()
{
	std::cout << "Please select a valid option: \n\n";
	std::cout << "1. Register Account\n";
	std::cout << "2. Login";
	std::cout << "\n\nYour selection: ";

}

void Access::input(int input, AbstractPage** page)
{
	AbstractPage* p = *page;
	switch (input)
	{
	case 1:
		system("CLS");
		*page = new Register();
		break;
	case 2:
		system("CLS");
		*page = new Login();
		break;
	default:
		system("CLS");
		std::cout << "Please select a valid option \n\n";
		system("Pause");
		system("CLS");
		break;
	}
	delete p;
}
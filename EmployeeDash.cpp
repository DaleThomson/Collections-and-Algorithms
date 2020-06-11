#include "EmployeeDash.h"

void EmployeeDash::print()
{
	std::cout << "Welcome to the Employee Dashboard.";
}

void EmployeeDash::input(int input, AbstractPage** page)
{
	switch (input)
	{
	case 1:
		system("PAUSE");
	default:
		break;
	}
}
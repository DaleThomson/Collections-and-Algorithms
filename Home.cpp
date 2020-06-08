#include "Home.h"

void Home::print()
{
	system("CLS");
	std::cout << "Welcome to the Homepage: \n\n";
	user->wee();
	system("PAUSE");
}

void Home::input(int input, AbstractPage** page)
{
	switch (input)
	{
	case 1:
		break;
	default:break;
	}
}
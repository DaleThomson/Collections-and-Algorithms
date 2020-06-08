#include <iostream>
#include "Access.h"
int main()
{
	AbstractPage* page = new Access();
	page->print();
	int input;
	std::cin >> input;
	std::cin.get();
	while (input != 0)
	{
		page->input(input, &page);
		page->print();
		std::cin >> input;
		std::cin.get();
	}
	return 0;
}
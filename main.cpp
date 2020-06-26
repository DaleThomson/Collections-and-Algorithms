#include <iostream>
#include "Access.h"
int main()
{
	AbstractPage* page = new Access(); // Creates an abstract page pointer and sets it to the Access page.
	page->print(); // Prints the contents of the access page.
	int input; 
	std::cin >> input;
	std::cin.get();
	while (input != 0)
	{
		page->input(input, &page); // Handles the input for the pages in the program.
		page->print(); // Prints the pages within the program as the user accesses them.
		std::cin >> input;
		std::cin.get();
	}
	return 0;
}
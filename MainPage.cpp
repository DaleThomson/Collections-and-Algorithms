#include "MainPage.h"

void mainPage::print()
{
	std::cout << "Welcome to our vast selection of rooms.";
	std::cout << "\n\nHere at Hotel Co we hope you find the room that is right for you";
	std::cout << "\n\n1. Load room selection";
	std::cout << "\n2. View all rooms.";
	std::cout << "\n3. Search for a specific room.";
	std::cout << "\n4. Create a new room. (Employee account required)";
	std::cout << "\n\nPlease make your selection: ";
}

void mainPage::input(int input, AbstractPage** page)
{
	switch (input)
	case 1:
	{
		tree->populateTree(&bst);
		system("CLS");
		std::cout << "Load successful.\n\n";
		system("PAUSE");
		break;
	case 2:
		system("CLS");
		bst.display();
		break;
	case 3:
		system("CLS");
		std::cout << "Please enter the room number you are looking for: E.G. R201\n\n";
		std::cout << "Enter here: ";
		std::cin >> searchParams;
		bst.searchRoom(searchParams);
		break;
	case 4:
		if (employee == NULL)
		{
			system("CLS");
			std::cout << "Sorry you do not have the permissions required to access this feature.\n\n";
			system("PAUSE");
			break;
		}
		else
		{
			bst.createRoom(employee);
			break;
		}
	default:
		system("CLS");
		std::cout << "Please select a valid option.\n\n";
		system("Pause");
		system("CLS");
		break;
	}
}
#include "MainPage.h"

//Prints the contents of the webpage
void mainPage::print()
{
	std::cout << "Welcome to our vast selection of rooms.";
	std::cout << "\n\nHere at Hotel Co we hope you find the room that is right for you";
	std::cout << "\n\n1. Load room selection";
	std::cout << "\n2. Load room selection in reverse order";
	std::cout << "\n3. View all rooms.";
	std::cout << "\n4. Search for a specific room.";
	std::cout << "\n5. Search for reversed room.";
	std::cout << "\n6. Create a new room. (Employee account required)";
	std::cout << "\n7. Check Booking";
	std::cout << "\n8. Previous page";
	std::cout << "\n9. Log out";
	std::cout << "\n\nPlease make your selection: ";
}

// Handles the users inputs on the site.
void mainPage::input(int input, AbstractPage** page)
{
	AbstractPage* p = *page;
	switch (input)
	{
	case 1:
		//Nullifys the root and populates the BST.
		bst.nullRoot();
		tree->populateTree(&bst);
		system("CLS");
		std::cout << "Load successful.\n\n";
		system("PAUSE");
		system("CLS");
		break;
	case 2:
		bst.nullRoot();
		tree->populateReverseTree(&bst);
		system("CLS");
		std::cout << "Load successful\n\n";
		system("PAUSE");
		system("CLS");
		break;
	case 3:
		//Prints the BST
		system("CLS");
		std::cout << "Room Num" << "    " << "Suite" << "         " << "Vacancy" << "       " << "Cost \x9C"
			<< "   " << "Max Occ" << "  " << "Rating\n";
		bst.display();
		system("PAUSE");
		system("CLS");
		break;
	case 4:
		if (user == NULL)
		{
			system("CLS");
			std::cout << "Sorry this feature is for customers only.\n\n";
			system("PAUSE");
			system("CLS");
			break;
		}
		//Allows the user to search rooms.
		system("CLS");
		std::cout << "Please enter the room number you are looking for: E.G. R201\n\n";
		std::cout << "Enter here: ";
		std::cin >> searchParams;
		bst.searchRoom(searchParams);
		break;
	case 5:
		if (user == NULL)
		{
			system("CLS");
			std::cout << "Sorry this feature is for customers only.\n\n";
			system("PAUSE");
			system("CLS");
			break;
		}
		//Allows the user to search rooms.
		system("CLS");
		std::cout << "Please enter the room number you are looking for: E.G. R201\n\n";
		std::cout << "Enter here: ";
		std::cin >> searchParams;
		bst.searchReverseRoom(searchParams);
		break;
	case 6:
		if (employee == NULL)
		{
			system("CLS");
			std::cout << "Sorry you do not have the permissions required to access this feature.\n\n";
			system("PAUSE");
			system("CLS");
			break;
		}
		else
		{
			//Allows the employee to create rooms.
			bst.createRoom(employee);
			break;
		}
	case 7:
		if (user == NULL)
		{
			system("CLS");
			std::cout << "Sorry this feature is for customers only.\n\n";
			system("PAUSE");
			system("CLS");
			break;
		}
		else
		{
			//Allows the user to check the room they have booked.
			bst.checkBooking(user);
			system("CLS");
			break;
		}
	case 8:
		// Allows the user to go back a page.
		system("CLS");
		if (user != NULL)
		{
			*page = new Home(user);
			delete p;
			break;
		}
		if (employee != NULL)
		{
			*page = new EmployeeDash(employee);
			delete p;
			break;
		}
	case 9:
		// Allows the user to log out.
		system("CLS");
		if(user != NULL)
		{
			delete user;
			*page = new Access();
			delete p;
			break;
		}
		if (employee != NULL)
		{
			delete employee;
			*page = new Access();
			delete p;
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
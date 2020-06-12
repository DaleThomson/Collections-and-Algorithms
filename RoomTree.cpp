#include "RoomTree.h"

void RoomTree::print()
{
	std::cout << "Welcome to our vast selection of rooms.";
	std::cout << "\n\nHere at Hotel Co we hope you find the room that is right for you";
	std::cout << "\n\n1. View all rooms";
	std::cout << "\n2. Search for a specific room.";
	std::cout << "\n3. Deposit currency.";
	std::cout << "\n\nPlease make your selection: ";
}

void RoomTree::input(int input, AbstractPage** page)
{
	switch (input)
	{
	case 1:
		break;
	case 2:
		break;
	case 3:
		break;
	default:
		break;
	}
}
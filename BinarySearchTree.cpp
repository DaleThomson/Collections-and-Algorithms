#include "BinarySearchTree.h"

void BinarySearchTree::print()
{
	std::cout << "Welcome to our vast selection of rooms.";
	std::cout << "\n\nHere at Hotel Co we hope you find the room that is right for you";
	std::cout << "\n\n1. View all rooms";
	std::cout << "\n2. Search for a specific room.";
	std::cout << "\n3. Deposit currency.";
	std::cout << "\n\nPlease make your selection: ";
}

void BinarySearchTree::addRoom(Room* room)
{
	tree* node = new tree;
	tree* parent;
	node->room = room;
	parent = NULL;

	if (root == NULL)
	{
		root = node;
	}
	else
	{
		tree* currentNode;
		currentNode = root;

		while (currentNode)
		{
			parent = currentNode;

			if (node->roomTree->roomNum > currentNode->roomTree->roomNum)
			{
				currentNode = currentNode->right;
			}
			else
			{
				currentNode = currentNode->left;
			}
		}

		if (node->roomTree->roomNum < parent->roomTree->roomNum)
		{
			parent->left = node;
		}
		else
		{
			parent->right = node;
		}

	}
}

void BinarySearchTree::createRoom()
{
	system("CLS");
	std::cout << "Please enter the room number for the new listing: ";
	std::cin >> roomNum;
	std::cout << "\nPlease enter the suite type for the new listing: ";
	std::cin >> suite;
	std::cout << "\nPlease enter the vacancy status of the new listing: ";
	std::cin >> vacancy;
	std::cout << "\nPlease enter the cost of the new listing: £";
	std::cin >> cost;
	std::cout << "\nPlease enter the maximum occupancy of the new listing: ";
	std::cin >> max_occupancy;
	std::cout << "\nPlease enter the rating of the new listing: ";
	std::cin >> rating;
	while (rating < 0 || rating > 5)
	{
		std::cout << "Sorry the limits are between 0 and 5 please re-enter.";
		std::cout << "\n\nPlease enter the rating of the new listing: ";
		std::cin >> rating;
	}
	system("CLS");
	std::cout << "Room Number: " << roomNum;
	std::cout << "\nSuite: " << suite;
	std::cout << "\nVacancy: " << vacancy;
	std::cout << "\nCost: £" << cost;
	std::cout << "\nMaximum Occupancy: " << max_occupancy;
	std::cout << "\nRating: " << rating << "/5";
	std::cout << "\n\nAre these details correct? ";
	char confirm;
	std::cin >> confirm;
	switch (confirm)
	{
	case 'Y': case 'y':
		Room* room = new Room(roomNum, suite, vacancy,
			cost, max_occupancy, rating);
		addRoom(room);
		break;
	case 'N': case 'n':
		createRoom();
		break;
	default:
		std::cout << "Please select a valid option.\n\n";
		break;
	}

}

void BinarySearchTree::searchRoom(std::string roomNum)
{
	bool roomFound = false;
	tree* currentNode, *parent;
	currentNode = root;

	if (root == NULL)
	{
		std::cout << "Tree is empty\n\n";
		system("PAUSE");
		return;
	}

	while (currentNode != NULL)
	{
		if (currentNode->room->getRoomNum() == roomNum)
		{
			std::cout << "Room Number: " << currentNode->room->getRoomNum();
			std::cout << "\nSuite: " << currentNode->room->getSuite();
			std::cout << "\nVacancy: " << currentNode->room->getVacancy();
			std::cout << "\nCost: £" << currentNode->room->getPrice();
			std::cout << "\nMaximum Occupancy: " << currentNode->room->getOccupancyLimit();
			std::cout << "\nRating: " << currentNode->room->getRating();
			break;
		}
		else
		{
			parent = currentNode;
			if (roomNum > currentNode->room->getRoomNum())
			{
				currentNode = currentNode->right;
			}
			else
			{
				currentNode = currentNode->left;
			}
		}
	}

}

void BinarySearchTree::input(int input, AbstractPage** page)
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
#include "BinarySearchTree.h"

void BinarySearchTree::addRoom(Room room)
{
	tree* node = new tree;
	tree* parent;
	node->room = room;
	node->left = NULL;
	node->right = NULL;
	parent = NULL;

	if (root == NULL)
		root = node;
	else
	{
		tree* currentNode;
		currentNode = root;

		while (currentNode)
		{
			parent = currentNode;
			if (node->room.getRoomNum() > currentNode->room.getRoomNum()) 
				currentNode = currentNode->right;							
			else							
				currentNode = currentNode->left;
		}
		if (node->room.getRoomNum() < parent->room.getRoomNum())
			parent->left = node;
		else
			parent->right = node;
	}
}

void BinarySearchTree::populateTree(BinarySearchTree* tree)
{
	std::ifstream file;
	std::string roomNum, suite, vacancy;
	int cost, max_occupancy, rating;
	Room room;

	file.open("roomList.txt");
	if (!file)
	{
		std::cout << "Can't find file" << std::endl;
	}

	while (file >> roomNum >> suite >> vacancy >> cost >> max_occupancy >> rating)
	{
		room.setRoomNum(roomNum);
		room.setSuite(suite);
		room.setVacancy(vacancy);
		room.setPrice(cost);
		room.setOccupancyLimit(max_occupancy);
		room.setRating(rating);
		(*tree).addRoom(room);
	}
	file.close();
}

void BinarySearchTree::createRoom(Employee* employee)
{
	std::string roomNum, suite, vacancy;
	int cost = 0, max_occupancy = 0, rating = 0;
	system("CLS");
	std::cout << "Please enter the room number for the new listing: ";
	std::cin >> roomNum;
	std::cout << "\nPlease enter the suite type for the new listing: ";
	std::cin >> suite;
	std::cout << "\nIs the room vacant Y/N? ";
	char confirm;
	std::cin >> confirm;
	while (1)
	{
		switch (confirm)
		{
		case 'Y': case 'y':
			vacancy = "Vacant";
			break;
		case 'N': case 'n':
			vacancy = "Occupied";
			break;
		default:
			std::cout << "Please select a valid option";
			break;
		}
		break;
	}
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
	std::cout << "\nRating: " << rating;
	std::cout << "\n\nAre these details correct? ";
	std::cin >> confirm;
	switch (confirm)
	{
	case 'Y': case 'y':
	{
		Room room;

		outRoomList.open("roomList.txt", std::fstream::out | std::fstream::app);
		outRoomList << roomNum << " " << suite << " " << vacancy << " " << cost << " "
			<< max_occupancy << " " << rating << std::endl;
		addRoom(room);
		outRoomList.close();
		break;
	}
	case 'N': case 'n':
		createRoom(employee);
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
		if (currentNode->room.getRoomNum() == roomNum)
		{
			std::cout << "Room Number: " << currentNode->room.getRoomNum();
			std::cout << "\nSuite: " << currentNode->room.getSuite();
			std::cout << "\nVacancy: " << currentNode->room.getVacancy();
			std::cout << "\nCost: £" << currentNode->room.getPrice();
			std::cout << "\nMaximum Occupancy: " << currentNode->room.getOccupancyLimit();
			std::cout << "\nRating: " << currentNode->room.getRating();
			break;
		}
		else
		{
			parent = currentNode;
			if (roomNum > currentNode->room.getRoomNum())
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

void BinarySearchTree::printTree(tree* roomTree)
{
	if (roomTree != NULL)
	{
		std::cout << roomTree->room.getRoomNum() << "        ";
		std::cout << roomTree->room.getSuite() << "        ";
		std::cout << roomTree->room.getVacancy() << "        ";
		std::cout << roomTree->room.getPrice() << "        ";
		std::cout << roomTree->room.getOccupancyLimit() << "        ";
		std::cout << roomTree->room.getRating() << "/5" << std::endl;
		if (roomTree->left)
		{
			printTree(roomTree->left);
		}
		if (roomTree->right)
		{
			printTree(roomTree->right);
		}
	}
	else
	{
		std::cout << "Tree is empty";
	}
}

void BinarySearchTree::display()
{
	printTree(root);
}
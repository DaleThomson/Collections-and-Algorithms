#include "BinarySearchTree.h"

//This method allows the root to be nulled allowing for the file to be loaded multiple times
//without duplicating the data.
void BinarySearchTree::nullRoot()
{
	root = NULL;
}

//This is used to add individual rooms to the nodes within the BST
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

//This is used to add individual rooms to the nodes within the BST in reverse order
void BinarySearchTree::addReverseRoom(Room room)
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
			if (node->room.getRoomNum() < currentNode->room.getRoomNum())
				currentNode = currentNode->right;
			else
				currentNode = currentNode->left;
		}
		if (node->room.getRoomNum() > parent->room.getRoomNum())
			parent->left = node;
		else
			parent->right = node;
	}
}

// This method is used to read the data from a text file and parse it into the nodes
void BinarySearchTree::populateTree(BinarySearchTree* tree)
{
	std::ifstream file;
	std::string roomNum, suite, vacancy;
	int cost, max_occupancy, rating;
	Room room;

	file.open("roomList.txt");
	if (!file)
	{
		system("CLS");
		std::cout << "Can't find file" << std::endl;
		system("PAUSE");
		system("CLS");
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

// This method is used to read the data from a text file and parse it into the nodes
void BinarySearchTree::populateReverseTree(BinarySearchTree* tree)
{
	std::ifstream file;
	std::string roomNum, suite, vacancy;
	int cost, max_occupancy, rating;
	Room room;

	file.open("roomList.txt");
	if (!file)
	{
		system("CLS");
		std::cout << "Can't find file" << std::endl;
		system("PAUSE");
		system("CLS");
	}

	while (file >> roomNum >> suite >> vacancy >> cost >> max_occupancy >> rating)
	{
		room.setRoomNum(roomNum);
		room.setSuite(suite);
		room.setVacancy(vacancy);
		room.setPrice(cost);
		room.setOccupancyLimit(max_occupancy);
		room.setRating(rating);
		(*tree).addReverseRoom(room);
	}
	file.close();
}

// This method allows for the creation of new rooms which are then added as nodes.
void BinarySearchTree::createRoom(Employee* employee)
{
	std::string roomNum, suite, vacancy;
	int cost = 0, max_occupancy = 0, rating = 0;
	system("CLS");
	std::cout << "Please enter the room number for the new listing: E.G. R201: ";
	std::cin >> roomNum;
	std::cout << "\nPlease enter the suite type for the new listing: E.G. Single: ";
	std::cin >> suite;
	std::cout << "\nIs the room vacant? Y/N: ";
	char confirm;
	std::cin >> confirm;
	int check = 0;
	while (check != 1)
	{
		switch (confirm)
		{
		case 'Y': case 'y':
			vacancy = "Vacant";
			check = 1;
			break;
		case 'N': case 'n':
			vacancy = "Occupied";
			check = 1;
			break;
		default:
			system("CLS");
			std::cout << "Please select a valid option\n\n";
			std::cout << "Please enter your selection: Y/N: ";
			std::cin >> confirm;
			break;
		}
	}
	std::cout << "\nPlease enter the cost of the new listing: E.G. \x9C" << "400 \x9C";
	std::cin >> cost;
	std::cout << "\nPlease enter the maximum occupancy of the new listing: E.G. 2: ";
	std::cin >> max_occupancy;
	std::cout << "\nPlease enter the rating of the new listing: E.G. 1-5: ";
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
	std::cout << "\nCost: \x9C" << cost << "Per night";
	std::cout << "\nMaximum Occupancy: " << max_occupancy;
	std::cout << "\nRating: " << rating;
	std::cout << "\n\nAre these details correct? Y/N: ";
	std::cin >> confirm;
	check = 0;
	while (check != 1)
	{
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
			system("CLS");
			check = 1;
			break;
		}
		case 'N': case 'n':
			system("CLS");
			std::cout << "Do you wish to try again?\n\n";
			std::cout << "Please enter your selection: Y/N: ";
			std::cin >> confirm;
			switch (confirm)
			{
			case 'Y': case 'y':
				createRoom(employee);
				break;
			case 'N': case 'n':
				system("CLS");
				check = 1;
				break;
			}
			break;
		default:
			std::cout << "Please select a valid option.\n\n";
			std::cout << "Please enter your selection: Y/N: ";
			std::cin >> confirm;
			break;
		}
	}

}
// Seaches the rooms and allows the user to book one if they decide to.
void BinarySearchTree::searchRoom(std::string roomNum)
{
	bool roomFound = false;
	tree* currentNode, * parent;
	currentNode = root;

	if (root == NULL)
	{
		system("CLS");
		std::cout << "Tree is empty\n\n";
		system("PAUSE");
		system("CLS");
		return;
	}

	while (currentNode != NULL)
	{
		if (currentNode->room.getRoomNum() == roomNum)
		{
			std::cout << "Room Number: " << currentNode->room.getRoomNum();
			std::cout << "\nSuite: " << currentNode->room.getSuite();
			std::cout << "\nVacancy: " << currentNode->room.getVacancy();
			std::cout << "\nCost: \x9C" << currentNode->room.getPrice() << " Per night";
			std::cout << "\nMaximum Occupancy: " << currentNode->room.getOccupancyLimit();
			std::cout << "\nRating: " << currentNode->room.getRating() << "/5" << "\n\n";
			std::cout << "Would you like to book this room? Y\N: ";
			char confirm;
			std::cin >> confirm;
			int check = 0;
			while (check != 1)
			{
				switch (confirm)
				{
				case 'Y': case 'y':
					booking(currentNode);
					check = 1;
					system("CLS");
					break;
				case 'N': case 'n':
					check = 1;
					system("CLS");
					break;
				default:
					system("CLS");
					std::cout << "Please select a valid option\n\n";
					std::cout << "Please enter your selection: Y/N: ";
					std::cin >> confirm;
					system("CLS");
					break;
				}
			}
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

void BinarySearchTree::searchReverseRoom(std::string roomNum)
{
	bool roomFound = false;
	tree* currentNode, * parent;
	currentNode = root;

	if (root == NULL)
	{
		system("CLS");
		std::cout << "Tree is empty\n\n";
		system("PAUSE");
		system("CLS");
		return;
	}

	while (currentNode != NULL)
	{
		if (currentNode->room.getRoomNum() == roomNum)
		{
			std::cout << "Room Number: " << currentNode->room.getRoomNum();
			std::cout << "\nSuite: " << currentNode->room.getSuite();
			std::cout << "\nVacancy: " << currentNode->room.getVacancy();
			std::cout << "\nCost: \x9C" << currentNode->room.getPrice() << " Per night";
			std::cout << "\nMaximum Occupancy: " << currentNode->room.getOccupancyLimit();
			std::cout << "\nRating: " << currentNode->room.getRating() << "/5" << "\n\n";
			std::cout << "Would you like to book this room? Y\N: ";
			char confirm;
			std::cin >> confirm;
			int check = 0;
			while (check != 1)
			{
				switch (confirm)
				{
				case 'Y': case 'y':
					booking(currentNode);
					check = 1;
					system("CLS");
					break;
				case 'N': case 'n':
					check = 1;
					system("CLS");
					break;
				default:
					system("CLS");
					std::cout << "Please select a valid option\n\n";
					std::cout << "Please enter your selection: Y/N: ";
					std::cin >> confirm;
					system("CLS");
					break;
				}
			}
			break;
		}
		else
		{
			parent = currentNode;
			if (roomNum < currentNode->room.getRoomNum())
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

//This method simply sets the bookedRoom node to the currentNode in the search method.
void BinarySearchTree::booking(tree* room)
{
	bookedRoom = room;
}

//This method displays the contents of the booked room method.
void BinarySearchTree::checkBooking(User* user)
{
	if (bookedRoom == NULL)
	{
		system("CLS");
		std::cout << "Sorry it appears you do not have a booking with us\n\n";
		system("PAUSE");
	}
	else
	{
		system("CLS");
		std::cout << "Room Number: " << bookedRoom->room.getRoomNum();
		std::cout << "\nSuite: " << bookedRoom->room.getSuite();
		std::cout << "\nVacancy: " << bookedRoom->room.getVacancy();
		std::cout << "\nCost: \x9C" << bookedRoom->room.getPrice() << " Per night";
		std::cout << "\nMaximum Occupancy: " << bookedRoom->room.getOccupancyLimit();
		std::cout << "\nRating: " << bookedRoom->room.getRating() << "/5" << std::endl << std::endl;
		system("PAUSE");
		system("CLS");
	}
}
// This method prints the BST inorder.
void BinarySearchTree::printTree(tree* roomTree)
{
	if (roomTree != NULL)
	{
		if (roomTree->left) printTree(roomTree->left);
		std::cout << roomTree->room.getRoomNum() << "        ";
		std::cout << roomTree->room.getSuite() << "        ";
		std::cout << roomTree->room.getVacancy() << "        ";
		std::cout << "\x9C" << roomTree->room.getPrice() << "        ";
		std::cout << roomTree->room.getOccupancyLimit() << "        ";
		std::cout << roomTree->room.getRating() << "/5" << std::endl;
		if (roomTree->right) printTree(roomTree->right);
	}
}

//This method runs the print method.
void BinarySearchTree::display()
{
	printTree(root);
}
#pragma once
#include "User.h"
#include "Employee.h"
#include "Room.h"
class BinarySearchTree
{
private:

	//Struct for declaring a tree
	struct tree
	{
		tree* left; //Left node
		tree* right; // Right Node
		Room room; // Room class
	};
	tree* root; //The root of the tree.
	tree* bookedRoom; //A node used to store the users booked room
	std::ofstream outRoomList;// An ofstrean to write out to the roomList file.
public:
	BinarySearchTree() {} //Constructor

	void addRoom(Room room); // A method for adding nodes to the BST.
	void booking(tree* tree); // A method used to set the bookedRoom node to the current node in the tree.
	void checkBooking(User* user); // A method to display the users booking to them.
	void createRoom(Employee* employee); // A method for an employee to create a new room.
	void searchRoom(std::string room); // A method used to search for specific rooms.
	void printTree(tree*); // A method used to print the tree.
	void display(); // A method used to rum the printTree method.
	void populateTree(BinarySearchTree* tree); // Parses the text files and sets the data for each node to be passed to the add room method.
	void nullRoot(); // A method used to nullify the root so the tree can be updated when the file is loaded.
};
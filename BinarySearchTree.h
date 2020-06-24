#pragma once
#include "User.h"
#include "Employee.h"
#include "Room.h"
class BinarySearchTree
{
private:
	struct tree
	{
		tree* left;
		tree* right;
		Room room;
	};
	tree* root;
	std::ofstream outRoomList;

	User* user;
	Employee* employee;
public:
	BinarySearchTree() {
		root = NULL;
	}

	void addRoom(Room room);
	void createRoom(Employee* employee);
	void searchRoom(std::string room);
	void printTree(tree*);
	void display();
	void populateTree(BinarySearchTree* tree);
};
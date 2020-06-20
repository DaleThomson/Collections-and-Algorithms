#pragma once
#include "AbstractPage.h"
#include "User.h"
#include "Employee.h"
#include "Room.h"
class BinarySearchTree : public AbstractPage
{
private:
	std::string roomNum, suite, vacancy;
	int cost, max_occupancy, rating;
	
	std::ofstream roomList;
	std::fstream authenticate;

	struct tree
	{
		tree* left;
		tree* right;
		BinarySearchTree* roomTree;
		Room* room;
	};
	tree* root;

	User* user;
	Employee* employee;

public:
	BinarySearchTree(User* user) : user(user)
	{
		root = NULL;
	}

	BinarySearchTree(Employee* employee) : employee(employee)
	{
		root = NULL;
	}

	void print();
	void input(int input, AbstractPage** page);
	void addRoom(Room* room);
	void createRoom();
	void searchRoom(std::string room);
	void removeRoom(std::string room);
	void printTree(tree* tree);
	void populateTree(BinarySearchTree* tree);
};
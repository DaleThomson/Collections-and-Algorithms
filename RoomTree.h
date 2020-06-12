#pragma once
#include "AbstractPage.h"
#include "User.h"
#include "Employee.h"
class RoomTree : public AbstractPage
{
private:
	std::string room, suite;
	int cost, max_occupancy;
	bool vacany;

	struct tree
	{
		tree* left;
		tree* right;
	};
	tree* root;

	User* user;
	Employee* employee;
public:
	RoomTree(User* user) : user(user)
	{
		root = NULL;
	}

	RoomTree(Employee* employee) : employee(employee)
	{
		root = NULL;
	}

	void print();
	void input(int input, AbstractPage** page);
	void addRoom(std::string room, std::string suite, int cost,
		int max_occupancy, bool vacancy);
	void searchRoom(std::string room);
	void removeRoom(std::string room);
	void printTree(tree* tree);
	void populateTree(RoomTree* tree);
};
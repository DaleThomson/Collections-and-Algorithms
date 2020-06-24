#pragma once
#include "AbstractPage.h"
#include "BinarySearchTree.h"
#include "EmployeeDash.h"
class mainPage : public AbstractPage
{
private:
	User* user;
	Employee* employee;
	std::string searchParams;
	BinarySearchTree bst, * tree = nullptr;
public:
	mainPage(User* user) : user(user) {}
	mainPage(Employee* employee) : employee(employee) {}

	virtual ~mainPage() {}

	void print();
	void input(int input, AbstractPage** page);
};
#pragma once
#include "AbstractPage.h"
#include "BinarySearchTree.h"
#include "EmployeeDash.h"
class mainPage : public AbstractPage
{
private:
	User* user; // Pointer to the user
	Employee* employee; // Pointer to the employee
	std::string searchParams; // String for searching rooms
	BinarySearchTree bst, *tree = nullptr; //Class and pointer for the BST class.
public:
	mainPage(User* user) : user(user) {} // Constructor to pass the user account in. 
	mainPage(Employee* employee) : employee(employee) {} // Constructor to pass the employee account in.

	virtual ~mainPage() {} // Deconstructor

	void print(); // Prints the contents of the webpage.
	void input(int input, AbstractPage** page); // Handles the inputs of the webpage.
};
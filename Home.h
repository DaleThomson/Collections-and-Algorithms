#pragma once
#include "AbstractPage.h"
#include "User.h"
#include "Access.h"
#include "BinarySearchTree.h"
class Home : public AbstractPage
{
private:
	User* user; // Pointer to the user class
public:
	Home(User* user) :user(user) {} // Constructor

	virtual ~Home() {} // Deconstructor

	void print(); // Prints the contents of the web page
	void input(int input, AbstractPage** page); // Handles the inputs for this webpage
};
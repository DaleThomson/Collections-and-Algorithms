#pragma once
#include "AbstractPage.h"
#include "User.h"
#include "Employee.h"
#include "Home.h"
class Register : public AbstractPage
{
public:

	Register() {} // Constructor

	virtual ~Register() {} // Deconstructor

	void print(); // Prints the contents of the webpage.
	void input(int input, AbstractPage** page);
private:
	User* user; // Pointer to the user
	Employee* employee; // Pointer to the employee
	std::string username, password; // Strings for storing usernames and passwords.
};
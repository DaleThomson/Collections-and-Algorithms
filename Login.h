#pragma once
#include "AbstractPage.h"
#include "User.h"
#include "Employee.h"
#include "Home.h"
#include "EmployeeDash.h"
class Login : public AbstractPage
{
public:
	Login() {} // Constructor

	virtual ~Login() {} // Deconstructor

	void print(); // Prints the contents of this webpage.
	void input(int input, AbstractPage** page); // Handles the inputs for this webpage.
private:
	User* user; // Pointer to the user class.
	Employee* employee; // Pointer to the employee class.
	std::string username, password; // Strings for storing usernames and passwords.
};
#pragma once
#include "AbstractPage.h"
#include "Register.h"
#include "Login.h"
class Access : public AbstractPage
{
public:
	Access() {} // Constructor

	virtual ~Access() {} // Deconstructor

	void print(); //A method to print the contents of the page.
	void input(int input, AbstractPage** page); //Handles the inputs for the page.
};
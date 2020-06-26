#pragma once
#include <string>
#include <iostream>
class AbstractPage
{
public:
	virtual ~AbstractPage(){} // Deconstructor

	virtual void print() = 0; // A virtual void for printing the contents of pages.
	virtual void input(int input, AbstractPage** page) = 0;//A virtual void for handling inputs.
};
#pragma once
#include "AbstractPage.h"
#include "User.h"
class Home : public AbstractPage
{
private:
	User* user;
public:
	Home(User* user) {}

	virtual ~Home() {}

	void print();
	void input(int input, AbstractPage** page);
};
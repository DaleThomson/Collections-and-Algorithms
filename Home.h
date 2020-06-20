#pragma once
#include "AbstractPage.h"
#include "User.h"
#include "Access.h"
#include "BinarySearchTree.h"
class Home : public AbstractPage
{
private:
	User* user;
public:
	Home(User* user) :user(user) {}

	virtual ~Home() {}

	void print();
	void input(int input, AbstractPage** page);
};
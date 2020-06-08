#pragma once
#include "AbstractPage.h"
#include "Register.h"
#include "Login.h"
class Access : public AbstractPage
{
public:
	Access() {}

	virtual ~Access() {}

	void print();
	void input(int input, AbstractPage** page);
};
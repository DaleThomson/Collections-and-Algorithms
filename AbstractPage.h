#pragma once
class AbstractPage
{
public:
	virtual ~AbstractPage(){
	}

	virtual void print() = 0;
	virtual void input(int input, AbstractPage** page) = 0;
};
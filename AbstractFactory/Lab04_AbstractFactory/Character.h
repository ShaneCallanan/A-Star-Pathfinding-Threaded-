#pragma once

#include <iostream>
using namespace std;


class Character
{
public:
	Character();
	~Character();
	virtual void writeToConsole() = 0;
};


#pragma once

#include <iostream>
#include <string>

using namespace std;


class PrinterInterface
{
public:
	PrinterInterface();
	~PrinterInterface();
	virtual void printText(string text) = 0;
};


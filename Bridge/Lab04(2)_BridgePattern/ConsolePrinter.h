#pragma once
#include "PrinterInterface.h"

class ConsolePrinter : public PrinterInterface
{
public:
	ConsolePrinter();
	~ConsolePrinter();
	void printText(string text);
};


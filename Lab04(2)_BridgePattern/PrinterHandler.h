#pragma once

#include "Printer.h"

class PrinterHandler
{
private:
	Printer* printer;

public:
	PrinterHandler();
	~PrinterHandler();
	Printer* operator->();
};


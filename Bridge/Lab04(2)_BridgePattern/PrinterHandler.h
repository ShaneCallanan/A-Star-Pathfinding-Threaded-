#pragma once

#include "PrinterInterface.h"

class PrinterHandler
{
private:
	PrinterInterface* m_printer;

public:
	PrinterHandler(PrinterInterface* printer);
	~PrinterHandler();
	PrinterInterface* operator->();
};


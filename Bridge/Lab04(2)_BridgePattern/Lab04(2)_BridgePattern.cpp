// Lab04(2)_BridgePattern.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "PrinterHandler.h"
#include "ConsolePrinter.h"


int main()
{
	PrinterHandler hPrinter = PrinterHandler(new ConsolePrinter());
	hPrinter->printText("First bit of text");
	hPrinter->printText("Second bit of text");
	hPrinter->printText("Turning off printer...");

    return 0;
}


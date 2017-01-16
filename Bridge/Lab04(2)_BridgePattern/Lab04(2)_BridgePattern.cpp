// Lab04(2)_BridgePattern.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "PrinterHandler.h"


int main()
{
	PrinterHandler hPrinter = PrinterHandler();
	hPrinter->printText("First bit of text");
	hPrinter->printText("Second bit of text");
	hPrinter->printText("Turning off printer...");

    return 0;
}


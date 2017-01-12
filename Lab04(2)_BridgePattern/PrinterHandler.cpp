#include "stdafx.h"
#include "PrinterHandler.h"


PrinterHandler::PrinterHandler() : printer(new Printer())
{
}


PrinterHandler::~PrinterHandler()
{
	delete printer;
}


Printer* PrinterHandler::operator->()
{
	return printer;
}
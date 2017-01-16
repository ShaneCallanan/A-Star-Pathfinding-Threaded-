#include "stdafx.h"
#include "PrinterHandler.h"


PrinterHandler::PrinterHandler(PrinterInterface* printer) : m_printer(printer)
{
}


PrinterHandler::~PrinterHandler()
{
	delete m_printer;
}


PrinterInterface* PrinterHandler::operator->()
{
	return m_printer;
}
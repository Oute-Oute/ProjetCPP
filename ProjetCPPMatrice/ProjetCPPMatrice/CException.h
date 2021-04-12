#ifndef C_EXCEPTION_H
#define C_EXCEPTION_H

#include <fstream>
#include <iostream>
#include <cstring>

class CException
{
private:
	const char* sEXCMessage;

public:
	//constructeur a partir d un message d exception
	CException(const char* sMessage);

	~CException();

	char* getMessage();

	int EXCAddition();

	int EXCSoustraction();

	int EXCMultiplicationSimple();

	int EXCMultiplicationDouble();

	int EXCDivision();

};
#endif

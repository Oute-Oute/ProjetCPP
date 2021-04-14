#ifndef C_EXCEPTION_H
#define C_EXCEPTION_H

#include <fstream>
#include <iostream>
#include <cstring>

class CException
{
private:
	char cEXCOperation;
	char* sEXCMessage;

public:

	CException();
	//constructeur a partir d une operation et un message d exception
	CException(char cOpreation, char* sMessage);

	~CException();

	char* EXCGetMessage();

	void EXCSetMessage(char* smessage);

	char EXCGetOperation();

	void EXCSetOperation(char cOperation);

	int EXCAddition();

	int EXCSoustraction();

	int EXCMultiplicationSimple();

	int EXCMultiplicationDouble();

	int EXCDivision();

};
#endif

#include <fstream>
#include <iostream>
#include "CException.h"
using namespace std;

CException::CException() {
	sEXCMessage = (char*) "Exception innatendue";
	cEXCOperation = '0';
}

CException::CException(char cOpreation, char * sMessage)
{
	sEXCMessage = sMessage;
	cEXCOperation = cOpreation;
}

CException::~CException() {

}

char* CException::EXCGetMessage() {
	return sEXCMessage;
}

void CException::EXCSetMessage(char* sMessage) {
	sEXCMessage = sMessage;
}

char CException::EXCGetOperation() {
	return cEXCOperation;
}

void CException::EXCSetOperation(char cOperation) {
	cEXCOperation = cOperation;
}

//////////////////////////////////////////////////////
int CException::EXCAddition() {
	return 0;
}

int CException::EXCSoustraction() {

	return 0;
}

int CException::EXCMultiplicationSimple() {

	return 0;
}

int CException::EXCMultiplicationDouble() {

	return 0;
}

int CException::EXCDivision() {

	return 0;
}



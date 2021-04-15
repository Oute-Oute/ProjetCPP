///
/// @brief Voir CException.h pour les descriptions des methodes
/// @file CEsxeption.cpp
/// @author NASSIRI Adam
/// @coauthor BLUMSTEIN Thomas
/// @date 2021-04-15
///

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



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
	pEXCmessage = (char*) "Exception innatendue";
	cEXCoperation = '0';
}

CException::CException(char cEXCope, char * pEXCmess)
{
	pEXCmessage = pEXCmess;
	cEXCoperation = cEXCope;
}

CException::~CException() {

}

void CException::EXCGetMessage(char* pEXCmess) {
	strcpy_s(pEXCmess, sizeof pEXCmess, pEXCmessage);
}

void CException::EXCSetMessage(char* pEXCmess) {
	pEXCmessage = pEXCmess;
}

char CException::EXCGetOperation() {
	return cEXCoperation;
}

void CException::EXCSetOperation(char cEXCope) {
	cEXCoperation = cEXCope;
}

void CException::EXCAfficherException() {
	cout << "Opération" << cEXCoperation << ", exception: " << pEXCmessage << endl;
}



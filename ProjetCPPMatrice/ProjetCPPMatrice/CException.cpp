///
/// @brief Voir CException.h pour les descriptions des methodes
/// @file CEsxeption.cpp
/// @author NASSIRI Adam
/// @coauthor BLUMSTEIN Thomas
/// @date 2021-04-17
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

/// @brief retourne le message d exception de la CException
/// @param RIEN
/// @return sEXCMessage le message d exception
void CException::EXCGetMessage(char* pEXCmess) {
	strcpy_s(pEXCmess, sizeof pEXCmess, pEXCmessage);
}

/// @brief definit le message d exception dans la CException
/// @param smessage le nouveau message d exception
/// @return RIEN
void CException::EXCSetMessage(char* pEXCmess) {
	pEXCmessage = pEXCmess;
}

/// @brief retourne l operation concernee par la CException
/// @param RIEN
/// @return cEXCOperation l operateur sous forme de char
char CException::EXCGetOperation() {
	return cEXCoperation;
}

/// @brief definit l operation concernee par la CException
/// @param cOperation l operateur sous forme de char
/// @return RIEN
void CException::EXCSetOperation(char cEXCope) {
	cEXCoperation = cEXCope;
}

/// @brief affiche le message d'exception de la CException courante
/// @param RIEN
/// @return RIEN
void CException::EXCAfficherException() {
	cout << "Opération" << cEXCoperation << ", exception: " << pEXCmessage << endl;
}



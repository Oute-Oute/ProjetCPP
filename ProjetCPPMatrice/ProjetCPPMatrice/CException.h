///
/// @file CException.h
/// @author NASSIRI Adam
/// @coauthor BLUMSTEIN Thomas
/// @date 2021-04-15
///

#ifndef C_EXCEPTION_H
#define C_EXCEPTION_H

#include <fstream>
#include <iostream>
#include <cstring>

/// @brief Un objet de la classe CException est lance en cas d'exception 
/// @details cEXOperation represente l'operation avec un caractère (ex: '+' pour l'addition), sEXCMessage contient un message d'exception.
class CException
{
private:
	char cEXCoperation;
	char* pEXCmessage;

public:
	//constructeur de CException par defaut
	CException();

	//constructeur a partir d une operation et un message d exception
	CException(char cEXCope, char* pEXCmess);

	//destructeur de CException
	~CException();

	/// @brief retourne le message d exception de la CException
	/// @param RIEN
	/// @return sEXCMessage le message d exception
	void EXCGetMessage(char* pEXCmess);

	/// @brief definit le message d exception dans la CException
	/// @param smessage le nouveau message d exception
	/// @return RIEN
	void EXCSetMessage(char* pEXCmess);

	/// @brief retourne l operation concernee par la CException
	/// @param RIEN
	/// @return cEXCOperation l operateur sous forme de char
	char EXCGetOperation();

	/// @brief definit l operation concernee par la CException
	/// @param cOperation l operateur sous forme de char
	/// @return 
	void EXCSetOperation(char cEXCope);

};
#endif

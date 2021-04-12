#include <fstream>
#include <iostream>
#include "CException.h"
using namespace std;

CException::CException(const char* sMessage) {
	sEXCMessage = sMessage;
}

CException::~CException() {

}

int CException::EXCAddition() {
	/*
	catch (CException & EXCexception) {
		cerr << "Exception: " << EXCexception.getMessage() << endl;
	}
	*/
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



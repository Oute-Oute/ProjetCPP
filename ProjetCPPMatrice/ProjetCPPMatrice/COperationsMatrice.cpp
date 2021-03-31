#include <fstream>
#include <iostream>

#include "COperationsMatrice.h"


COperationsMatrice::COperationsMatrice()
{
}

COperationsMatrice::COperationsMatrice(COperationsMatrice &OMAM1)
{
}

COperationsMatrice::COperationsMatrice(int pmOMAMat)
{
}

COperationsMatrice::~COperationsMatrice()
{
}

COperationsMatrice COperationsMatrice::&operator+(COperationsMatrice &OMAM1)
{
	return 0;
}

COperationsMatrice COperationsMatrice::&operator*(COperationsMatrice &OMAM1)
{
	return 0;
}

COperationsMatrice COperationsMatrice::&operator*(COperationsMatrice &OMAM1, int &iElem)
{
	return 0;
}

COperationsMatrice COperationsMatrice::&operator*(int &iElem, COperationsMatrice &OMAM1)
{
	return 0;
}

COperationsMatrice COperationsMatrice::&operator/(int &iElem, COperationsMatrice &OMAM1)
{
	return 0;
}

COperationsMatrice COperationsMatrice::&operator-(COperationsMatrice &OMAM1)
{
	return 0;
}

COperationsMatrice COperationsMatrice::MATCalculTransposee(COperationsMatrice OMAM1)
{
	return 0;
}

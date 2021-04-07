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

COperationsMatrice COperationsMatrice::operator+(COperationsMatrice &OMAM1)
{
	return MATMatriceResultat;
}

COperationsMatrice COperationsMatrice::operator*(COperationsMatrice &OMAM1)
{
	return MATMatriceResultat;
}

COperationsMatrice COperationsMatrice::operator*(COperationsMatrice& OMAM1, int &iElem)
{
	unsigned int uiNbColonnes = OMAM1.pmOMAMatrice.MATGetnbColonne();
	unsigned int uiNbLignes = OMAM1.pmOMAMatrice.MATGetnbLigne();
	CMatrice mMatriceResultat;

	mMatriceResultat.CMatrice(uiNbLignes,uiNbColonnes);

	for (int iLigne = 0 ; iLigne < uiNbLignes; iLigne++) {
		for (int iColonne = 0 ; iColonne < uiNbColonnes ; iColonne ++){

			//FAIRE L'OPERATION SUR L'ELEMENT

		}
	}

	return mMatriceResultat;
}

COperationsMatrice COperationsMatrice::operator*(int &iElem, COperationsMatrice &OMAM1)
{
	return MATMatriceResultat;
}

COperationsMatrice COperationsMatrice::operator/(int &iElem, COperationsMatrice &OMAM1)
{
	return MATMatriceResultat;
}

COperationsMatrice COperationsMatrice::operator-(COperationsMatrice &OMAM1)
{
	return MATMatriceResultat;
}

COperationsMatrice COperationsMatrice::MATCalculTransposee(COperationsMatrice OMAM1)
{
	return 0;
}

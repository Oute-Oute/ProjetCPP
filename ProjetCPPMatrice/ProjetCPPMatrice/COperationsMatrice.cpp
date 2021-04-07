#include <fstream>
#include <iostream>

#include "COperationsMatrice.h"

template<class nomType>
COperationsMatrice<nomType>::COperationsMatrice()
{
}

template<class nomType>
COperationsMatrice<nomType>::COperationsMatrice(COperationsMatrice<nomType> &OMAM1)
{
}

template<class nomType>
COperationsMatrice<nomType>::COperationsMatrice(int pmOMAMat)
{
}

template<class nomType>
COperationsMatrice<nomType>::~COperationsMatrice()
{
}

template<class nomType>
CMatrice<nomType> COperationsMatrice<nomType>::operator+(COperationsMatrice<nomType> &OMAM1)
{
	unsigned int uiNbColonnes = OMAM1.pmOMAMatrice.MATGetnbColonne();
	unsigned int uiNbLignes = OMAM1.pmOMAMatrice.MATGetnbLigne();

	CMatrice<nomType> MATMatriceResultat = new CMatrice(uiNbLignes, uiNbColonnes);

	//TRAITEMENT OPERATION

	return MATMatriceResultat;
}

template<class nomType>
CMatrice<nomType> COperationsMatrice<nomType>::operator*(COperationsMatrice<nomType> &OMAM1)
{
	unsigned int uiNbColonnes = OMAM1.pmOMAMatrice.MATGetnbColonne();
	unsigned int uiNbLignes = OMAM1.pmOMAMatrice.MATGetnbLigne();

	//TRAITEMENT OPERATION

	CMatrice<nomType> MATMatriceResultat = new CMatrice(uiNbLignes, uiNbColonnes);

	return MATMatriceResultat;
}

/*template<class nomType>
CMatrice<nomType> COperationsMatrice<nomType>::operator*(COperationsMatrice<nomType>& OMAM1, int &iElem)
{
	unsigned int uiNbColonnes = OMAM1.pmOMAMatrice.MATGetnbColonne();
	unsigned int uiNbLignes = OMAM1.pmOMAMatrice.MATGetnbLigne();

	CMatrice<nomType> MATMatriceResultat = new CMatrice(uiNbLignes, uiNbColonnes);

	for (int iLigne = 0 ; iLigne < uiNbLignes; iLigne++) {
		for (int iColonne = 0 ; iColonne < uiNbColonnes ; iColonne ++){

			//FAIRE L'OPERATION SUR L'ELEMENT

		}
	}

	return MATMatriceResultat;
}*/

template<class nomType>
CMatrice<nomType> COperationsMatrice<nomType>::operator*(int &iElem)
{
	unsigned int uiNbColonnes = pmOMAMatrice.MATGetnbColonne();
	unsigned int uiNbLignes = pmOMAMatrice.MATGetnbLigne();

	CMatrice<nomType> MATMatriceResultat = new CMatrice(uiNbLignes, uiNbColonnes);

	for (int iLigne = 0; iLigne < uiNbLignes; iLigne++) {
		for (int iColonne = 0; iColonne < uiNbColonnes; iColonne++) {

			pmOMAMatrice.pMATtabValeurs[iLigne][iColonne] = pmOMAMatrice.pMATtabValeurs[iLigne][iColonne] * iElem;

		}
	}

	return MATMatriceResultat;
}

template<class nomType>
CMatrice<nomType> COperationsMatrice<nomType>::operator/(int &iElem)
{
	unsigned int uiNbColonnes = pmOMAMatrice.MATGetnbColonne();
	unsigned int uiNbLignes = pmOMAMatrice.MATGetnbLigne();

	CMatrice<nomType> MATMatriceResultat = new CMatrice(uiNbLignes, uiNbColonnes);

	//TRAITEMENT OPERATION

	return MATMatriceResultat;
}

template<class nomType>
CMatrice<nomType> COperationsMatrice<nomType>::operator-(COperationsMatrice<nomType> &OMAM1)
{
	unsigned int uiNbColonnes = OMAM1.pmOMAMatrice.MATGetnbColonne();
	unsigned int uiNbLignes = OMAM1.pmOMAMatrice.MATGetnbLigne();

	CMatrice<nomType> MATMatriceResultat = new CMatrice(uiNbLignes, uiNbColonnes);

	//TRAITEMENT OPERATION

	return MATMatriceResultat;
}

template<class nomType>
CMatrice<nomType> COperationsMatrice<nomType>::MATCalculTransposee(COperationsMatrice<nomType> OMAM1)
{
	return 0;
}

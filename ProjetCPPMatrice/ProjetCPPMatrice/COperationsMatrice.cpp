#include <fstream>
#include <iostream>

#include "COperationsMatrice.h"

template<class nomType>
COperationsMatrice<nomType>::COperationsMatrice()
{
	pmOMAMatrice = new CMatrice();
}

//constructeur de COperationsMatrice de recopie
template<class nomType>
COperationsMatrice<nomType>::COperationsMatrice(COperationsMatrice<nomType> &OMAM1)
{
	pmOMAMatrice = OMAM1.pmOMAMatrice;
}

//constructeur de COperationsMatrice a partir d une Cmatrice*
template<class nomType>
COperationsMatrice<nomType>::COperationsMatrice(CMatrice<nomType>* pmOMAMat)
{
	pmOMAMatrice = pmOMAMat;
}

//destructeur de COperationsMatrice
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
CMatrice<nomType> COperationsMatrice<nomType>::operator-(COperationsMatrice<nomType> &OMAM1)
{
	unsigned int uiNbColonnes = OMAM1.pmOMAMatrice.MATGetnbColonne();
	unsigned int uiNbLignes = OMAM1.pmOMAMatrice.MATGetnbLigne();

	CMatrice<nomType> MATMatriceResultat = new CMatrice(uiNbLignes, uiNbColonnes);

	//TRAITEMENT OPERATION


	for (int iLigne = 0; iLigne < uiNbLignes; iLigne++) {
		for (int iColonne = 0; iColonne < uiNbColonnes; iColonne++) {

			MATMatriceResultat.pMATtabValeurs[iLigne][iColonne] = pmOMAMatrice.pMATtabValeurs[iLigne][iColonne] - OMAM1.pmOMAMatrice.pMATtabValeurs[iLigne][iColonne];

		}
	}

	return MATMatriceResultat;
}

template<class nomType>
CMatrice<nomType> COperationsMatrice<nomType>::operator*(COperationsMatrice<nomType> &OMAM1)
{
	unsigned int uiNbColonnes = pmOMAMatrice.MATGetnbColonne();
	unsigned int uiNbLignes = OMAM1.pmOMAMatrice.MATGetnbLigne();
	char* sNomType = pmOMAMatrice.MATGetNomType();

	//INITIALISATION DE LA MATRICE RESULTAT EN MATRICE NULLE

				//ADAM: pas assez d'arguments ici, comprends a quoi sert MATtv
	CMatrice<nomType> MATMatriceResultat = new CMatrice(uiNbLignes, uiNbColonnes, sNomType);

	for (int iLigne = 0; iLigne < uiNbLignes; iLigne++) {
		for (int iColonne = 0; iColonne < uiNbColonnes; iColonne++) {
			MATMatriceResultat.pMATtabValeurs[iLigne][iColonne] = 0;
		}

	}

	//EXCEPTIONS

		//types differents
	if (pmOMAMatrice.MATGetnomType != OMAM1.pmOMAMatrice.MATGetnomType) {
		throw "Types incompatibles!";
	}

	MATMatriceResultat.MATSetnomType(pmOMAMatrice.MATGetnomType);

		//dimensions incorrectes
	if (pmOMAMatrice.MATGetnbColonne != OMAM1.pmOMAMatrice.MATGetnbLigne) {
		throw "Dimensiosn incompatibles!";
	}

	//TRAITEMENT

	for (int iLigne = 0; iLigne < uiNbLignes; iLigne++) {
		for (int iColonne = 0; iColonne < uiNbColonnes; iColonne++) {
			for (int iElement = 0; iElement < pmOMAMatrice.MATGetnbColonne; iElement++) {

				MATMatriceResultat.pMATtabValeurs[iLigne][iColonne] += pmOMAMatrice.pMATtabValeurs[iLigne][iColonne] * OMAM1.pmOMAMatrice.pMATtabValeurs[iColonne][iLigne];
			}

		}

	}

	return MATMatriceResultat;
}


/*
template<class nomType>
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
}
*/

template<class nomType>
CMatrice<nomType> COperationsMatrice<nomType>::operator*(int &iElem)
{
	unsigned int uiNbColonnes = pmOMAMatrice.MATGetnbColonne();
	unsigned int uiNbLignes = pmOMAMatrice.MATGetnbLigne();

	CMatrice<nomType> MATMatriceResultat = new CMatrice(uiNbLignes, uiNbColonnes);

	for (int iLigne = 0; iLigne < uiNbLignes; iLigne++) {
		for (int iColonne = 0; iColonne < uiNbColonnes; iColonne++) {

			MATMatriceResultat.pMATtabValeurs[iLigne][iColonne] = pmOMAMatrice.pMATtabValeurs[iLigne][iColonne] * iElem;

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

	for (int iLigne = 0; iLigne < uiNbLignes; iLigne++) {
		for (int iColonne = 0; iColonne < uiNbColonnes; iColonne++) {

			MATMatriceResultat.pMATtabValeurs[iLigne][iColonne] = pmOMAMatrice.pMATtabValeurs[iLigne][iColonne] / iElem;

		}
	}

	return MATMatriceResultat;
}

template<class nomType>
CMatrice<nomType> COperationsMatrice<nomType>::MATCalculTransposee(COperationsMatrice<nomType> OMAM1)
{
	unsigned int uiNbColonnes = pmOMAMatrice.MATGetnbColonne();
	unsigned int uiNbLignes = pmOMAMatrice.MATGetnbLigne();

	CMatrice<nomType> MATMatriceResultat = new CMatrice(uiNbLignes, uiNbColonnes);

	for (int iLigne = 0; iLigne < uiNbLignes; iLigne++) {
		for (int iColonne = 0; iColonne < uiNbColonnes; iColonne++) {

			MATMatriceResultat.pMATtabValeurs[iLigne][iColonne] = OMAM1.pmOMAMatrice.pMATtabValeurs[iColonne][iLigne];

		}
	}

	return MATMatriceResultat;
}

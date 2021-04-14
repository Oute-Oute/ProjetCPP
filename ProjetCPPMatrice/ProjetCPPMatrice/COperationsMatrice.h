#ifndef C_OPERATIONS_MATRICE_H
#define C_OPERATIONS_MATRICE_H

#include "CMatrice.h"
#include "CException.h"

using namespace std;

template <class nomType>
class COperationsMatrice
{
private:
	CMatrice<nomType> pmOMAMatrice;


public:
	//constructeur par defaut
	COperationsMatrice();

	//constructeur de recopie
	COperationsMatrice(COperationsMatrice<nomType> &OMAM1);

	//constructeur a partir d une CMatrice*
	COperationsMatrice(CMatrice<nomType>* pmOMAMat);

	//destructeur
	~COperationsMatrice();

	CMatrice<nomType> operator+(COperationsMatrice<nomType> &OMAM1);

	CMatrice<nomType> operator-(COperationsMatrice<nomType> &OMAM1);

	CMatrice<nomType> operator*(COperationsMatrice<nomType> &OMAM1);

	CMatrice<nomType> operator*(int &iElem);

	//CMatrice<nomType> operator*(int &iElem * COperationsMatrice<nomType> &OMAM1);

	CMatrice<nomType> operator/(int &iElem);

	CMatrice<nomType> MATCalculTransposee(COperationsMatrice<nomType> OMAM1);

};

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

	//initialisation de l'objet exception
	CException EXCexception = new CException();
	EXCexception.EXCSetOperation('+');

	try{
	//EXCEPTIONS
		if (uiNbColonnes != pmOMAMatrice.MATGetnbColonne() || uiNbLignes != pmOMAMatrice.MATGetnbLigne()) {
			EXCexception.EXCSetMessage("Dimensions incompatibles!");
			throw (EXCexception);
		}

	//TRAITEMENT OPERATION
		for (int iLigne = 0; iLigne < uiNbLignes; iLigne++) {
			for (int iColonne = 0; iColonne < uiNbColonnes; iColonne++) {

				MATMatriceResultat.pMATtabValeurs[iLigne][iColonne] = pmOMAMatrice.pMATtabValeurs[iLigne][iColonne] + OMAM1.pmOMAMatrice.pMATtabValeurs[iLigne][iColonne];

			}

		}

	}

	//LEVER LES EXCEPTIONS
	catch (CException EXCexception) {
		cout<< "Opération" <<EXCexception.EXCGetOperation << ", exception: " << EXCexception.EXCGetMessage() << endl;
	}

	return MATMatriceResultat;
}

template<class nomType>
CMatrice<nomType> COperationsMatrice<nomType>::operator-(COperationsMatrice<nomType> &OMAM1)
{
	unsigned int uiNbColonnes = OMAM1.pmOMAMatrice.MATGetnbColonne();
	unsigned int uiNbLignes = OMAM1.pmOMAMatrice.MATGetnbLigne();

	CMatrice<nomType> MATMatriceResultat = new CMatrice(uiNbLignes, uiNbColonnes);

	//initialisation de l'objet exception
	CException EXCexception = new CException();
	EXCexception.EXCSetOperation('-');

	try {
		//EXCEPTIONS
		if (uiNbColonnes != pmOMAMatrice.MATGetnbColonne() || uiNbLignes != pmOMAMatrice.MATGetnbLigne()) {
			EXCexception.EXCSetMessage("Dimensions incompatibles!");
			throw (EXCexception);
		}

		//TRAITEMENT
		for (int iLigne = 0; iLigne < uiNbLignes; iLigne++) {
			for (int iColonne = 0; iColonne < uiNbColonnes; iColonne++) {
				MATMatriceResultat.pMATtabValeurs[iLigne][iColonne] = pmOMAMatrice.pMATtabValeurs[iLigne][iColonne] - OMAM1.pmOMAMatrice.pMATtabValeurs[iLigne][iColonne];
			}

		}

	}


	//LEVER LES EXCEPTIONS
	catch (CException EXCexception) {
		cout << "Opération" << EXCexception.EXCGetOperation << ", exception: " << EXCexception.EXCGetMessage() << endl;
	}

	return MATMatriceResultat;
}

template<class nomType>
CMatrice<nomType> COperationsMatrice<nomType>::operator*(COperationsMatrice<nomType> &OMAM1)
{
	unsigned int uiNbColonnes = pmOMAMatrice.MATGetnbColonne();
	unsigned int uiNbLignes = OMAM1.pmOMAMatrice.MATGetnbLigne();
	char* sNomType = pmOMAMatrice.MATGetNomType();

	//initialisation de l'objet exception
	CException EXCexception = new CException();
	EXCexception.EXCSetOperation('*');

	//INITIALISATION DE LA MATRICE RESULTAT EN MATRICE NULLE
			//ADAM REPARE: pas assez d'arguments ici, comprends a quoi sert MATtv
	int** piTabValeurs;
	for (int iLigne = 0; iLigne < uiNbLignes; iLigne++) {
		for (int iColonne = 0; iColonne < uiNbColonnes; iColonne++) {
			piTabValeurs[iLigne][iColonne] = 0;
		}

	}

	CMatrice<nomType> MATMatriceResultat = new CMatrice(uiNbLignes, uiNbColonnes, sNomType, piTabValeurs);

	try {
	//EXCEPTIONS

		//dimensions incorrectes
		if (pmOMAMatrice.MATGetnbColonne != OMAM1.pmOMAMatrice.MATGetnbLigne) {
			EXCexception.EXCSetMessage("Dimensions incompatibles!");
			throw (EXCexception);
		}

	//TRAITEMENT

		for (int iLigne = 0; iLigne < uiNbLignes; iLigne++) {
			for (int iColonne = 0; iColonne < uiNbColonnes; iColonne++) {
				for (int iElement = 0; iElement < pmOMAMatrice.MATGetnbColonne; iElement++) {
					MATMatriceResultat.pMATtabValeurs[iLigne][iColonne] += pmOMAMatrice.pMATtabValeurs[iLigne][iColonne] * OMAM1.pmOMAMatrice.pMATtabValeurs[iColonne][iLigne];
				}

			}

		}

	}
	
	catch (CException EXCexception) {
		cout << "Opération" << EXCexception.EXCGetOperation << ", exception: " << EXCexception.EXCGetMessage() << endl;
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


	//initialisation de l'objet exception
	CException EXCexception = new CException();
	EXCexception.EXCSetOperation('/');

	try {
	//EXCEPTIONS
		//division par 0
		if (iElem == 0) {
			EXCexception.EXCSetMessage("Division par 0!");
			throw (EXCexception);
		}

	//TRAITEMENT
		for (int iLigne = 0; iLigne < uiNbLignes; iLigne++) {
			for (int iColonne = 0; iColonne < uiNbColonnes; iColonne++) {

				MATMatriceResultat.pMATtabValeurs[iLigne][iColonne] = pmOMAMatrice.pMATtabValeurs[iLigne][iColonne] / iElem;

			}

		}

	}

	catch(CException EXCexception) {
		cout << "Opération" << EXCexception.EXCGetOperation << ", exception: " << EXCexception.EXCGetMessage() << endl;
	}

	return MATMatriceResultat;
}

template<class nomType>
CMatrice<nomType> COperationsMatrice<nomType>::MATCalculTransposee(COperationsMatrice<nomType> OMAM1)
{
	unsigned int uiNbColonnes = pmOMAMatrice.MATGetnbColonne();
	unsigned int uiNbLignes = pmOMAMatrice.MATGetnbLigne();

	CMatrice<nomType> MATMatriceResultat = new CMatrice(uiNbLignes, uiNbColonnes);

	//initialisation de l'objet exception
	CException EXCexception = new CException();
	EXCexception.EXCSetOperation('T');

	try {
	//EXCEPTIONS
		//matrice non carree
		if (uiNbColonnes != uiNbLignes) {
			EXCexception.EXCSetMessage("Taille de matrice invalide (matrice non carrée) !");
			throw (EXCexception);
		}

	//TRAITEMENT
		for (int iLigne = 0; iLigne < uiNbLignes; iLigne++) {
			for (int iColonne = 0; iColonne < uiNbColonnes; iColonne++) {

				MATMatriceResultat.pMATtabValeurs[iLigne][iColonne] = OMAM1.pmOMAMatrice.pMATtabValeurs[iColonne][iLigne];

			}

		}

	}

	catch (CException EXCexception) {
		cout << "Opération" << EXCexception.EXCGetOperation << ", exception: " << EXCexception.EXCGetMessage() << endl;
	}
		

	return MATMatriceResultat;
}

#endif

///
/// @file CMatrice.h
/// @author BLUMSTEIN Thomas
/// @coauthor NASSIRI Adam
/// @date 2021-04-15
///

#ifndef C_MATRICE_H
#define C_MATRICE_H

#include <fstream>
#include <iostream>
#include "CException.h"
using namespace std;

template <class nomType>
class CMatrice
{
private:
	unsigned int uiMATnbLignes;

	unsigned int uiMATnbColonnes;

	char* cMATnomType;

	nomType ** pMATtabValeurs;

public:
	//constructeur de CMatrice par defaut
	CMatrice();

	//constructeur avec indication des donnees
	CMatrice(int MATnbL, int MATnbC, char* MATnT, nomType ** MATtV);

	//constructeur avec indication des dimensions
	CMatrice(int MATnbL, int MATnbC, char*MATnT);

	//constructeur de CMatrice de recopie
	CMatrice(CMatrice &MATM1);

	//destructeur de CMatrice
	~CMatrice();

	/// @brief renvoie le nombre de lignes de la matrice
	/// @param RIEN
	/// @return uiMATnbLignes le nombre de lignes de la matrice
	int MATGetNbLigne();

	/// @brief renvoie le nombre de colonnes de la matrice
	/// @param RIEN
	/// @return uiMATnbColonnes le nombre de colonnes de la matrice
	int MATGetNbColonne();


	/// @brief renvoie le type des elements dde la matrice
	/// @param RIEN
	/// @return cMATnomTypele le type des elements de la matrice
	char* MATGetNomType();

	/// @brief renvoie le tableau d'elements de la matrice
	/// @param RIEN
	/// @return pMATtabValuerse le tableau des elements de la matrices
	void MATGetTabValeurs(nomType** MATtV);

	/// @brief definit le nombre de lignes d'une CMatrice
	/// @param MATnb nombre de lignes qu'on impose
	/// @return RIEN
	void MATSetNbLigne(int MATnbL);

	/// @brief definit le nombre de colonnes d'une CMatrice
	/// @param MATnbC nombre de colonnes qu'on impose
	/// @return RIEN
	void MATSetNbColonne(int MATnbC);

	/// @brief definit le nom du type des elements de la matrice
	/// @param MATnT nom du type impos�
	/// @return RIEN
	void MATSetNomType(char* MATnT);

	/// @brief definit le tableau des elements de la CMatrice
	/// @param MATtV tableau des valeurs a entrer
	/// @return RIEN
	void MATSetTabValeur(nomType **MATtV);

	/// @brief affiche le contenu de la CMatrice: repmlit le tableau avec des entiers croissants en partant de 0
	/// @param RIEN
	/// @return RIEN
	void MATAfficherMatrice();

	CMatrice<nomType> operator+(CMatrice<nomType> &MATm1);

	CMatrice<nomType> operator-(CMatrice<nomType> &MATm1);

	CMatrice<nomType> operator*(CMatrice<nomType> &MATm1);

	CMatrice<nomType> operator*(double &iElem);

	CMatrice<nomType> operator/(double & iElem);

	CMatrice<nomType> MATCalculTransposee(CMatrice<nomType> MATm1);

};

template<class nomType>
CMatrice<nomType>::CMatrice()
{
	uiMATnbColonnes = 0;
	uiMATnbLignes = 0;
	cMATnomType = nullptr;
	pMATtabValeurs = nullptr;
}

template<class nomType>
CMatrice<nomType>::CMatrice(int MATnbL, int MATnbC, char* MATnT, nomType** MATtV)
{
	uiMATnbLignes = MATnbL;
	uiMATnbColonnes = MATnbC;
	cMATnomType = MATnT;
	unsigned int uiboucleTab;
	unsigned int uiBoucleLignes;
	unsigned int uiBoucleColonnes;
	this->pMATtabValeurs = new double*[uiMATnbLignes];
	for (uiboucleTab = 0; uiboucleTab < uiMATnbLignes; uiboucleTab++) {
		this->pMATtabValeurs[uiboucleTab] = new double[uiMATnbColonnes];
	}
	for (uiBoucleLignes = 0; uiBoucleLignes < uiMATnbLignes; uiBoucleLignes++) {
		for (uiBoucleColonnes = 0; uiBoucleColonnes < uiMATnbColonnes; uiBoucleColonnes++) {

			this->pMATtabValeurs[uiBoucleLignes][uiBoucleColonnes] = MATtV[uiBoucleLignes][uiBoucleColonnes];
			//cout << this->pMATtabValeurs[uiBoucleLignes][uiBoucleColonnes];
		}
	}
}

template<class nomType>
CMatrice<nomType>::CMatrice(int MATnbL, int MATnbC, char* MATnT )
{
	uiMATnbLignes = MATnbL;
	uiMATnbColonnes = MATnbC;

	double** pitabVal = new double*[MATnbL];
	unsigned int uiboucle;

	for (uiboucle = 0; uiboucle < MATnbL; uiboucle++) {
		pitabVal[uiboucle] = new double[MATnbC];
	}

	cMATnomType = MATnT;
	this->MATSetTabValeur(pitabVal);

}

template<class nomType>
CMatrice<nomType>::CMatrice(CMatrice &MATM1)
{
	uiMATnbLignes = MATM1.MATGetNbLigne();
	uiMATnbColonnes = MATM1.MATGetNbColonne();
	cMATnomType = MATM1.MATGetNomType();
	MATM1.MATGetTabValeurs(this->pMATtabValeurs);
}

template<class nomType>
CMatrice<nomType>::~CMatrice()
{
	uiMATnbColonnes = 0;
	uiMATnbLignes = 0;
	delete cMATnomType;
}

template<class nomType>
int CMatrice<nomType>::MATGetNbLigne()
{
	return uiMATnbLignes;
}

template<class nomType>
int CMatrice<nomType>::MATGetNbColonne()
{
	return uiMATnbColonnes;
}

template<class nomType>
char * CMatrice<nomType>::MATGetNomType()
{
	return cMATnomType;
}

template<class nomType>
void CMatrice<nomType>::MATGetTabValeurs(nomType** MATtV)
{
	unsigned int uiboucleTab;
	unsigned int uiboucleLignes;
	unsigned int uiboucleColonnes;
	for (uiboucleLignes = 0; uiboucleLignes < uiMATnbLignes; uiboucleLignes++) {
		for (uiboucleColonnes = 0; uiboucleColonnes < uiMATnbColonnes; uiboucleColonnes++) {

			MATtV[uiboucleLignes][uiboucleColonnes] = pMATtabValeurs[uiboucleLignes][uiboucleColonnes];
		}
	}
}

template<class nomType>
void CMatrice<nomType>::MATSetNbLigne(int MATnbL)
{
	uiMATnbLignes = MATnbL;
}

template<class nomType>
void CMatrice<nomType>::MATSetNbColonne(int MATnbC)
{
	uiMATnbColonnes = MATnbC;
}

template<class nomType>
void CMatrice<nomType>::MATSetNomType(char * MATnT)
{
	cMATnomType = MATnT;
}

template<class nomType>
void CMatrice<nomType>::MATSetTabValeur(nomType ** MATtV)
{

	unsigned int uiboucleLignes;
	unsigned int uiboucleColonnes;
	for (uiboucleLignes = 0; uiboucleLignes < uiMATnbLignes; uiboucleLignes++)
	{
		for (uiboucleColonnes = 0; uiboucleColonnes < uiMATnbColonnes; uiboucleColonnes++)
		{
			this->pMATtabValeurs[uiboucleLignes][uiboucleColonnes] = MATtV[uiboucleLignes][uiboucleColonnes];
		}
	}
}


template<class nomType>
inline void CMatrice<nomType>::MATAfficherMatrice()
{
	unsigned int uiboucleLignes;
	unsigned int uiboucleColonnes;
	for (uiboucleLignes = 0; uiboucleLignes < uiMATnbLignes; uiboucleLignes++)
	{
		for (uiboucleColonnes = 0; uiboucleColonnes < uiMATnbColonnes; uiboucleColonnes++)
		{
			cout << pMATtabValeurs[uiboucleLignes][uiboucleColonnes] << "  ";
		}
		cout << endl;
	}
}

template<class nomType>
inline CMatrice<nomType> CMatrice<nomType>::operator+(CMatrice<nomType>& MATm1)
{

	unsigned int uiNbColonnes = MATm1.MATGetNbColonne();
	unsigned int uiNbLignes = MATm1.MATGetNbLigne();

	CMatrice<nomType> MATMatriceResultat = new CMatrice(uiNbLignes, uiNbColonnes);

	//initialisation de l'objet exception
	CException EXCexception = new CException();
	EXCexception.EXCSetOperation('+');

	try {
		//EXCEPTIONS
		if (uiNbColonnes != MATGetNbColonne() || uiNbLignes != MATGetNbLigne()) {
			EXCexception.EXCSetMessage("Dimensions incompatibles!");
			throw (EXCexception);
		}

		//TRAITEMENT OPERATION
		for (int iLigne = 0; iLigne < uiNbLignes; iLigne++) {
			for (int iColonne = 0; iColonne < uiNbColonnes; iColonne++) {

				pMATtabValeurs[iLigne][iColonne] = pMATtabValeurs[iLigne][iColonne] + MATm1.pMATtabValeurs[iLigne][iColonne];

			}

		}

	}

	//LEVER LES EXCEPTIONS
	catch (CException EXCexception) {
		cout << "Op�ration" << EXCexception.EXCGetOperation << ", exception: " << EXCexception.EXCGetMessage() << endl;
	}

	return MATMatriceResultat;
}

template<class nomType>
inline CMatrice<nomType> CMatrice<nomType>::operator-(CMatrice<nomType>& MATm1)
{
	unsigned int uiNbColonnes = MATm1.MATGetNbColonne();
	unsigned int uiNbLignes = MATm1.MATGetNbLigne();

	CMatrice<nomType> MATMatriceResultat = new CMatrice(uiNbLignes, uiNbColonnes);

	//initialisation de l'objet exception
	CException EXCexception = new CException();
	EXCexception.EXCSetOperation('-');

	try {
		//EXCEPTIONS
		if (uiNbColonnes != MATGetNbColonne() || uiNbLignes != MATGetNbLigne()) {
			EXCexception.EXCSetMessage("Dimensions incompatibles!");
			throw (EXCexception);
		}

		//TRAITEMENT
		for (int iLigne = 0; iLigne < uiNbLignes; iLigne++) {
			for (int iColonne = 0; iColonne < uiNbColonnes; iColonne++) {
				pMATtabValeurs[iLigne][iColonne] = pMATtabValeurs[iLigne][iColonne] - MATm1.pMATtabValeurs[iLigne][iColonne];
			}

		}

	}


	//LEVER LES EXCEPTIONS
	catch (CException EXCexception) {
		cout << "Op�ration" << EXCexception.EXCGetOperation << ", exception: " << EXCexception.EXCGetMessage() << endl;
	}

	return MATMatriceResultat;
}

template<class nomType>
inline CMatrice<nomType> CMatrice<nomType>::operator*(CMatrice<nomType>& MATm1)
{
	unsigned int uiNbColonnes = MATGetNbColonne();
	unsigned int uiNbLignes = MATm1.MATGetNbLigne();
	char* sNomType = MATGetNomType();

	//initialisation de l'objet exception
	CException EXCexception = new CException();
	EXCexception.EXCSetOperation('*');

	//INITIALISATION DE LA MATRICE RESULTAT EN MATRICE NULLE
	double** pitabVal = new double*[uiNbLignes];
	unsigned int uiboucle;

	for (uiboucle = 0; uiboucle < uiNbLignes; uiboucle++) {
		pitabVal[uiboucle] = new double[uiNbColonnes];
	}

	CMatrice<nomType> MATMatriceResultat(uiNbLignes, uiNbColonnes, sNomType, pitabVal);

	try {
		//EXCEPTIONS

			//dimensions incorrectes
		if (MATGetNbColonne() != MATm1.MATGetNbLigne()) {
			EXCexception.EXCSetMessage("Dimensions incompatibles!");
			throw (EXCexception);
		}

		//TRAITEMENT

		for (int iLigne = 0; iLigne < uiNbLignes; iLigne++) {
			for (int iColonne = 0; iColonne < uiNbColonnes; iColonne++) {
				for (int iElement = 0; iElement < MATGetNbColonne; iElement++) {
					MATMatriceResultat.pMATtabValeurs[iLigne][iColonne] += pMATtabValeurs[iLigne][iColonne] * MATm1.pMATtabValeurs[iColonne][iLigne];
				}

			}

		}

	}

	catch (CException EXCexception) {
		cout << "Op�ration" << EXCexception.EXCGetOperation << ", exception: " << EXCexception.EXCGetMessage() << endl;
	}

	return MATMatriceResultat;
}

template<class nomType>
inline CMatrice<nomType> CMatrice<nomType>::operator*(double & iElem)
{
	unsigned int uinbColonnes = MATGetNbColonne();
	unsigned int uinbLignes = MATGetNbLigne();

	double** ptabVal = new double*[uinbLignes];
	unsigned int uiboucle;

	for (uiboucle = 0; uiboucle < uinbLignes; uiboucle++) {
		ptabVal[uiboucle] = new double[uinbColonnes];
	}

	CMatrice<nomType> MATMatriceResultat(uinbLignes, uinbColonnes, (char*)"double",ptabVal);

	for (int iLigne = 0; iLigne < uinbLignes; iLigne++) {
		for (int iColonne = 0; iColonne < uinbColonnes; iColonne++) {

			MATMatriceResultat.pMATtabValeurs[iLigne][iColonne] = pMATtabValeurs[iLigne][iColonne] * iElem;

		}

	}

	return MATMatriceResultat;
}

template<class nomType>
inline CMatrice<nomType> CMatrice<nomType>::operator/(double & iElem)
{
	unsigned int uiNbColonnes = MATGetNbColonne();
	unsigned int uiNbLignes = MATGetNbLigne();

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

				MATMatriceResultat.pMATtabValeurs[iLigne][iColonne] = pMATtabValeurs[iLigne][iColonne] / iElem;

			}

		}

	}

	catch (CException EXCexception) {
		cout << "Op�ration" << EXCexception.EXCGetOperation << ", exception: " << EXCexception.EXCGetMessage() << endl;
	}

	return MATMatriceResultat;
}


template<class nomType>
inline CMatrice<nomType> CMatrice<nomType>::MATCalculTransposee(CMatrice<nomType> MATm1)
{
	unsigned int uiNbColonnes = MATGetNbColonne();
	unsigned int uiNbLignes = MATGetNbLigne();

	CMatrice<nomType> MATMatriceResultat = new CMatrice(uiNbLignes, uiNbColonnes);

	//initialisation de l'objet exception
	CException EXCexception = new CException();
	EXCexception.EXCSetOperation('T');

	try {
		//EXCEPTIONS
			//matrice non carree
		if (uiNbColonnes != uiNbLignes) {
			EXCexception.EXCSetMessage("Taille de matrice invalide (matrice non carr�e) !");
			throw (EXCexception);
		}

		//TRAITEMENT
		for (int iLigne = 0; iLigne < uiNbLignes; iLigne++) {
			for (int iColonne = 0; iColonne < uiNbColonnes; iColonne++) {

				MATMatriceResultat.pMATtabValeurs[iLigne][iColonne] = MATm1.pMATtabValeurs[iColonne][iLigne];

			}

		}

	}

	catch (CException EXCexception) {
		cout << "Op�ration" << EXCexception.EXCGetOperation << ", exception: " << EXCexception.EXCGetMessage() << endl;
	}


	return MATMatriceResultat;
}

#endif

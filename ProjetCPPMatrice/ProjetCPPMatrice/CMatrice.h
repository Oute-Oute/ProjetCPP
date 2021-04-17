///
/// @file CMatrice.h
/// @author BLUMSTEIN Thomas
/// @coauthor NASSIRI Adam
/// @date 2021-04-17
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
	CMatrice(unsigned int MATnbL, unsigned int MATnbC, char*MATnT);

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
	/// @param MATnT nom du type imposé
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

	///@brief renvoie le resultat de l'addition de deux matrices
	///@param MATm1 CMatrice membre droit de l'addition
	///@return MATMatriceResultat matrice resultat de l'addition
	CMatrice<nomType> operator+(CMatrice<nomType> &MATm1);

	///@brief renvoie le resultat de la soustraction  de deux matrices
	///@param MATm1 CMatrice membre droit de la soustraction
	///@return MATMatriceResultat matrice resultat de la soustraction 
	CMatrice<nomType> operator-(CMatrice<nomType> &MATm1);

	///@brief renvoie le resultat de la multiplication actuelle par une autre passée en parametre
	///@param MATm1 CMatrice membre droit de la multiplication
	///@return  MATMatriceResultat la matrice resultat
	CMatrice<nomType> operator*(CMatrice<nomType> &MATm1);

	///@brief renvoie le resultat de la multiplication terme a terme de la matrice actuelle par un double
	///@param dElem le multiplicateur 
	///@return  MATMatriceResultat la matrice multipliée
	CMatrice<nomType> operator*(double &dElem);

	///@brief renvoie le resultat de la division terme a terme de la matrice actuelle par un double
	///@param iElem le diviseur 
	///@return  MATMatriceResultat la matrice divisée
	CMatrice<nomType> operator/(double & dElem);

	///@brief renvoie la transposee de la matrice parametre
	///@param MATm1 la matrice 
	///@return MATMatriceResultat la matrice transposee
	void MATCalculTransposee(CMatrice<nomType> MATm1);

};

//constructeur de CMatrice par defaut
template<class nomType>
CMatrice<nomType>::CMatrice()
{
	uiMATnbColonnes = 0;
	uiMATnbLignes = 0;
	cMATnomType = nullptr;
	pMATtabValeurs = nullptr;
}

//constructeur de CMatrice de confort (l'utilisateur renseigne tout les attributs)
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

//constructeur de CMatrice avec dimensions et nom du type
template<class nomType>
CMatrice<nomType>::CMatrice(unsigned int MATnbL, unsigned int MATnbC, char* MATnT)
{
	uiMATnbLignes = MATnbL;
	uiMATnbColonnes = MATnbC;
	cMATnomType = MATnT;

	this->pMATtabValeurs = new double*[MATnbL];
	unsigned int uiboucle;

	for (uiboucle = 0; uiboucle < MATnbL; uiboucle++) {
		pMATtabValeurs[uiboucle] = new double[MATnbC];
	}

}

//constructeur de CMatrice de recopie
template<class nomType>
CMatrice<nomType>::CMatrice(CMatrice &MATM1)
{
	uiMATnbLignes = MATM1.MATGetNbLigne();
	uiMATnbColonnes = MATM1.MATGetNbColonne();
	cMATnomType = MATM1.MATGetNomType();
	this->pMATtabValeurs = new double*[uiMATnbLignes];
	unsigned int uiboucle;

	for (uiboucle = 0; uiboucle < uiMATnbLignes; uiboucle++) {
		pMATtabValeurs[uiboucle] = new double[uiMATnbColonnes];
	}
	memcpy(pMATtabValeurs, MATM1.pMATtabValeurs, uiMATnbLignes * uiMATnbColonnes * sizeof(double));
}

//destructeur de CMatrice
template<class nomType>
CMatrice<nomType>::~CMatrice()
{
	uiMATnbColonnes = 0;
	uiMATnbLignes = 0;
	//delete cMATnomType;
}

///@brief retourne le nombre de lignes que contient la matrice
///@param RIEN
///@return uiMATnbLignes le nombre de colonnes de la matrice
template<class nomType>
int CMatrice<nomType>::MATGetNbLigne()
{
	return uiMATnbLignes;
}

///@brief retourne le nombre de colonnes que contient la matrice
///@param RIEN
///@return uiMATnbColonnes le nombre de colonnes de la matrice
template<class nomType>
int CMatrice<nomType>::MATGetNbColonne()
{
	return uiMATnbColonnes;
}

///@brief retourne le nom du type des elements de la matrice
///@param RIEN
///@return cMATnomType le nom du type des elements de la matrice
template<class nomType>
char * CMatrice<nomType>::MATGetNomType()
{
	return cMATnomType;
}

///@brief copie le tableau des valeurs de la matrice dans le tableau en parametre
///@param MATtV tabluea a remplir avec les elements de la matrice
///@return RIEN
template<class nomType>
void CMatrice<nomType>::MATGetTabValeurs(nomType** MATtV)
{
	unsigned int uiboucleLignes;
	unsigned int uiboucleColonnes;
	for (uiboucleLignes = 0; uiboucleLignes < uiMATnbLignes; uiboucleLignes++) {
		for (uiboucleColonnes = 0; uiboucleColonnes < uiMATnbColonnes; uiboucleColonnes++) {

			MATtV[uiboucleLignes][uiboucleColonnes] = pMATtabValeurs[uiboucleLignes][uiboucleColonnes];
		}

	}

}

///@brief definit le nombre de lignes contenues dans la matrice
///@param MATnbL le nombre de lignes 
///@return RIEN
template<class nomType>
void CMatrice<nomType>::MATSetNbLigne(int MATnbL)
{
	uiMATnbLignes = MATnbL;
}

///@brief definit le nombre de colonnes contenues dans la matrice
///@param MATnbC le nombre de volonnes
///@return RIEN
template<class nomType>
void CMatrice<nomType>::MATSetNbColonne(int MATnbC)
{
	uiMATnbColonnes = MATnbC;
}

///@brief definit le nom du type des elements de la matrice
///@param MATnT char* le nom du type affecte a la matrice
///@return RIEN
template<class nomType>
void CMatrice<nomType>::MATSetNomType(char * MATnT)
{
	cMATnomType = MATnT;
}

///@brief definit le tableau de valeurs de la matrice
///@param MATtV le tableau contenant les valeurs a mettre dans la matrice
///@return RIEN
template<class nomType>
void CMatrice<nomType>::MATSetTabValeur(nomType ** MATtV)
{
	this->pMATtabValeurs = new double*[uiMATnbLignes];
	unsigned int uiboucle;

	for (uiboucle = 0; uiboucle < uiMATnbLignes; uiboucle++) {
		pMATtabValeurs[uiboucle] = new double[uiMATnbColonnes];
	}
	memcpy(pMATtabValeurs, MATtV, uiMATnbLignes * uiMATnbColonnes * sizeof(double));
}

///@brief affiche le contenu du tableau de valeurs de la matrice
///@param RIEN
///@return RIEN
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

///@brief renvoie le resultat de l'addition de deux matrices
///@param MATm1 CMatrice membre droit de l'addition
///@return MATMatriceResultat matrice resultat de l'addition
template<class nomType>
inline CMatrice<nomType> CMatrice<nomType>::operator+(CMatrice<nomType>& MATm1)
{

	unsigned int uiNbColonnes = MATm1.MATGetNbColonne();
	unsigned int uiNbLignes = MATm1.MATGetNbLigne();
	char* snomType = MATGetNomType();

<<<<<<< Updated upstream
	CMatrice<nomType> MATMatriceResultat = new CMatrice(uiNbLignes, uiNbColonnes, snomType);
=======
	CMatrice<nomType> MATMatriceResultat(uiNbLignes, uiNbColonnes, (char*)"double");
>>>>>>> Stashed changes

	//initialisation de l'objet exception
	CException EXCexception = *new CException();
	EXCexception.EXCSetOperation('+');

	try {
		//EXCEPTIONS
		if (uiNbColonnes != MATGetNbColonne() || uiNbLignes != MATGetNbLigne()) {
			EXCexception.EXCSetMessage((char*)"Dimensions incompatibles!");
			throw (EXCexception);
		}

		//TRAITEMENT OPERATION
		unsigned int uiboucleLignes;
		unsigned int uiboucleColonnes;
		for (uiboucleLignes = 0; uiboucleLignes < uiNbLignes; uiboucleLignes++) {
			for (uiboucleColonnes = 0; uiboucleColonnes < uiNbColonnes; uiboucleColonnes++) {

				MATMatriceResultat.pMATtabValeurs[uiboucleLignes][uiboucleColonnes] = pMATtabValeurs[uiboucleLignes][uiboucleColonnes] + MATm1.pMATtabValeurs[uiboucleLignes][uiboucleColonnes];

			}

		}

	}

	//LEVER LES EXCEPTIONS
	catch (CException EXCexception) {
		EXCexception.EXCAfficherException();
	}

	return MATMatriceResultat;
}

///@brief renvoie le resultat de la soustraction  de deux matrices
///@param MATm1 CMatrice membre droit de la soustraction
///@return MATMatriceResultat matrice resultat de la soustraction 
template<class nomType>
inline CMatrice<nomType> CMatrice<nomType>::operator-(CMatrice<nomType>& MATm1)
{
	unsigned int uiNbColonnes = MATm1.MATGetNbColonne();
	unsigned int uiNbLignes = MATm1.MATGetNbLigne();
	char* snomType = MATGetNomType();

<<<<<<< Updated upstream
	CMatrice<nomType> MATMatriceResultat = new CMatrice(uiNbLignes, uiNbColonnes, snomType);
=======
	CMatrice<nomType> MATMatriceResultat(uiNbLignes, uiNbColonnes, (char*)"double");
>>>>>>> Stashed changes

	//initialisation de l'objet exception
	CException EXCexception = *new CException();
	EXCexception.EXCSetOperation('-');

	try {
		//EXCEPTIONS
		if (uiNbColonnes != MATGetNbColonne() || uiNbLignes != MATGetNbLigne()) {
			EXCexception.EXCSetMessage((char*)"Dimensions incompatibles!");
			throw (EXCexception);
		}

		//TRAITEMENT
		unsigned int uiboucleLignes;
		unsigned int uiboucleColonnes;
		for (uiboucleLignes = 0; uiboucleLignes < uiNbLignes; uiboucleLignes++) {
			for (uiboucleColonnes = 0; uiboucleColonnes < uiNbColonnes; uiboucleColonnes++) {
				MATMatriceResultat.pMATtabValeurs[uiboucleLignes][uiboucleColonnes] = pMATtabValeurs[uiboucleLignes][uiboucleColonnes] - MATm1.pMATtabValeurs[uiboucleLignes][uiboucleColonnes];
			}

		}

	}


	//LEVER LES EXCEPTIONS
	catch (CException EXCexception) {
		EXCexception.EXCAfficherException();
	}

	return MATMatriceResultat;
}

///@brief renvoie le resultat de la multiplication actuelle par une autre passée en parametre
///@param MATm1 CMatrice membre droit de la multiplication
///@return  MATMatriceResultat la matrice resultat
template<class nomType>
inline CMatrice<nomType> CMatrice<nomType>::operator*(CMatrice<nomType>& MATm1)
{
	unsigned int uiNbColonnes = MATm1.MATGetNbColonne();
	unsigned int uiNbLignes = MATm1.MATGetNbLigne();
	char* sNomType = MATGetNomType();

	CMatrice<nomType> MATMatriceResultat = new CMatrice(uiNbLignes, uiNbColonnes, sNomType);

	//initialisation de l'objet exception
	CException EXCexception = *new CException();
	EXCexception.EXCSetOperation('*');

	//INITIALISATION DE LA MATRICE RESULTAT EN MATRICE NULLE
<<<<<<< Updated upstream
	CMatrice<nomType> MATMatriceResultat = new CMatrice(uiNbLignes, uiNbColonnes, sNomType);
=======
	double** pitabVal = new double*[uiNbLignes];
	unsigned int uiboucle;

	for (uiboucle = 0; uiboucle < uiNbLignes; uiboucle++) {
		pitabVal[uiboucle] = new double[uiNbColonnes];
	}

	CMatrice<nomType> MATMatriceResultat(uiNbLignes, uiNbColonnes, sNomType);


>>>>>>> Stashed changes

	try {
		//EXCEPTIONS

			//dimensions incorrectes
		if (MATGetNbColonne() != MATm1.MATGetNbLigne()) {
			EXCexception.EXCSetMessage((char*)"Dimensions incompatibles!");
			throw (EXCexception);
		}

		//TRAITEMENT

		unsigned int uiboucleLignes;
		unsigned int uiboucleColonnes;
		unsigned int uiboucleElement;
		//Initilisation de la matrice résultat a 0
		for (uiboucleLignes = 0; uiboucleLignes < uiMATnbLignes; uiboucleLignes++)
		{
			for (uiboucleColonnes = 0; uiboucleColonnes < uiMATnbColonnes; uiboucleColonnes++)
			{
				MATMatriceResultat.pMATtabValeurs[uiboucleLignes][uiboucleColonnes] = 0;
			}
		}
		// Calcul
		for (uiboucleLignes = 0; uiboucleLignes < uiNbLignes; uiboucleLignes++) {
			for (uiboucleColonnes = 0; uiboucleColonnes < uiNbColonnes; uiboucleColonnes++) {
				for (uiboucleElement = 0; uiboucleElement < uiNbColonnes; uiboucleElement++) {
					MATMatriceResultat.pMATtabValeurs[uiboucleLignes][uiboucleColonnes] += pMATtabValeurs[uiboucleLignes][uiboucleElement] * MATm1.pMATtabValeurs[uiboucleElement][uiboucleColonnes];
				}

			}

		}

	}

	catch (CException EXCexception) {
		EXCexception.EXCAfficherException();
	}

	return MATMatriceResultat;
}

///@brief renvoie le resultat de la multiplication terme a terme de la matrice actuelle par un double
///@param iElem le multiplicateur 
///@return  MATMatriceResultat la matrice multipliée
template<class nomType>
inline CMatrice<nomType> CMatrice<nomType>::operator*(double & dElem)
{
<<<<<<< Updated upstream
	unsigned int uiNbColonnes = MATGetNbColonne();
	unsigned int uiNbLignes = MATGetNbLigne();
	char* sNomType = MATGetNomType();

	CMatrice<nomType> MATMatriceResultat = *new CMatrice(uiNbLignes, uiNbColonnes, sNomType);

	for (int iLigne = 0; iLigne < uiNbLignes; iLigne++) {
		for (int iColonne = 0; iColonne < uiNbColonnes; iColonne++) {

			MATMatriceResultat.pMATtabValeurs[iLigne][iColonne] = pMATtabValeurs[iLigne][iColonne] * iElem;
=======
	unsigned int uinbColonnes = MATGetNbColonne();
	unsigned int uinbLignes = MATGetNbLigne();
	unsigned int uiLigne;
	unsigned int uiColonne;
	CMatrice<nomType> MATMatriceResultat(uiMATnbLignes, uinbColonnes, (char*)"double");

	for (uiLigne = 0; uiLigne < uinbLignes; uiLigne++) {
		for (uiColonne = 0; uiColonne < uinbColonnes; uiColonne++) {

			MATMatriceResultat.pMATtabValeurs[uiLigne][uiColonne] = pMATtabValeurs[uiLigne][uiColonne] * dElem;
>>>>>>> Stashed changes

		}

	}

	return MATMatriceResultat;
}

///@brief renvoie le resultat de la division terme a terme de la matrice actuelle par un double
///@param iElem le diviseur 
///@return  MATMatriceResultat la matrice divisée
template<class nomType>
inline CMatrice<nomType> CMatrice<nomType>::operator/(double & dElem)
{
	unsigned int uiNbColonnes = MATGetNbColonne();
	unsigned int uiNbLignes = MATGetNbLigne();

	CMatrice<nomType> MATMatriceResultat(uiNbLignes, uiNbColonnes, (char*)"double");


	//initialisation de l'objet exception
	CException EXCexception = *new CException();
	EXCexception.EXCSetOperation('/');

	try {
		//EXCEPTIONS
			//division par 0
		if (dElem == 0) {
			EXCexception.EXCSetMessage((char*)"Division par 0!");
			throw (EXCexception);
		}

		//TRAITEMENT
		unsigned int uiLigne;
		unsigned int uiColonne;
		for (uiLigne = 0; uiLigne < uiNbLignes; uiLigne++) {
			for (uiColonne = 0; uiColonne < uiNbColonnes; uiColonne++) {

				MATMatriceResultat.pMATtabValeurs[uiLigne][uiColonne] = pMATtabValeurs[uiLigne][uiColonne] / dElem;

			}

		}

	}

	catch (CException EXCexception) {
		EXCexception.EXCAfficherException();
	}

	return MATMatriceResultat;
}

<<<<<<< Updated upstream
///@brief renvoie la transposee de la matrice parametre
///@param MATm1 la matrice 
///@return MATMatriceResultat la matrice transposee
=======


>>>>>>> Stashed changes
template<class nomType>
void CMatrice<nomType>::MATCalculTransposee(CMatrice<nomType> MATm1)
{
	unsigned int uiMATnbColonnes= MATm1.MATGetNbLigne();
	unsigned int uiMATnblignes = MATm1.MATGetNbColonne();

	pMATtabValeurs = new double*[uiMATnblignes];
	unsigned int uiboucle;

	for (uiboucle = 0; uiboucle < uiMATnblignes; uiboucle++) {
		pMATtabValeurs[uiboucle] = new double[uiMATnbColonnes];
	}
	//CMatrice<nomType> MATMatriceResultat(uiNbLignes, uiNbColonnes, (char*)"double");


		//TRAITEMENT
	unsigned int uiboucleLignes;
	unsigned int uiboucleColonnes;
	//Initilisation de la matrice courante a 0
	for (uiboucleLignes = 0; uiboucleLignes < uiMATnbLignes; uiboucleLignes++)
	{
		for (uiboucleColonnes = 0; uiboucleColonnes < uiMATnbColonnes; uiboucleColonnes++)
		{
			pMATtabValeurs[uiboucleLignes][uiboucleColonnes] = 0;
		}
	}

	//calcul transposée
	for (uiboucleLignes = 0; uiboucleLignes < uiMATnblignes; uiboucleLignes++) {
		for (uiboucleColonnes = 0; uiboucleColonnes < uiMATnbColonnes; uiboucleColonnes++) {

			pMATtabValeurs[uiboucleLignes][uiboucleColonnes] = MATm1.pMATtabValeurs[uiboucleColonnes][uiboucleLignes];

		}

	}




	//return MATMatriceResultat;
}

#endif

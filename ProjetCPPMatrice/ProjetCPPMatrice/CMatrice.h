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
#include "CComplexe.h"
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
#include "CMatrice.cpp"

#endif

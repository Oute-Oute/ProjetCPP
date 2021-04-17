///
/// @file CException.h
/// @author BLUMSTEIN Thomas
/// @coauthor NASSIRI Adam
/// @date 2021-04-17
///

#ifndef C_LECTURE_H
#define C_LECTURE_H

#include <string>
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;


class CLecture
{
public:
	const char* pLECnomFichier;

	unsigned int uiLECnbLignes;

	unsigned int uiLECnbColonnes;

	double** pLECtabValeurs;

	char* pLECnomType;

	ifstream fmyFile;

public:
	//constructeur de CLecture par defaut 
	CLecture();

	//constructeur de CLecture de confort avec indication du nom du fichier
	CLecture(char* pnF);

	//constructeur de CLecture de recopie
	CLecture(CLecture &LEClecture);

	//destructeur de CLecture
	~CLecture();

	///@brief renvoie le nombre de lignes qui sera attribue a la matrice
	///@param RIEN
	///@return uiLECnbLignes le nombre de lignes a attribuer a la matrice
	int LECGetNbLignes();

	///@brief renvoie le nombre de colonnes qui sera attribue a la matrice
	///@param RIEN
	///@return uiLECnbLignes le nombre de colonnes a attribuer a la matrice
	int LECGetNbColonnes();

	///@brief copie le nom du type des elements de la matrice dans le char* en parametre
	///@param pLECnT chaine dans laquelle on copie le nom du type
	///@return RIEN
	void LECGetnomType(char* pLECnT);

	///@brief copie le tableau des elements de la matrice dans le tableau en parametre
	///@param pLECtV tableau dans lequel on copie le tableau des valeurs
	///@return RIEN
	void LECGetTabValeurs(double** pLECtV);

	///@brief definit le nombre de lignes attribuees a la matrice 
	///@details aucun argument, ce setter fonctionne en lisant un fichier texte
	///@param RIEN
	///@return RIEN
	void LECSetNbLigne();

	///@brief definit le nombre de colonnes attribuees a la matrice 
	///@details aucun argument, ce setter fonctionne en lisant un fichier texte
	///@param RIEN
	///@return RIEN
	void LECSetNbColonne();

	///@brief definit le nom du type des elements de la matrice 
	///@details aucun argument, ce setter fonctionne en lisant un fichier texte
	///@param RIEN
	///@return RIEN
	void LECSetNomType();

	///@brief definit le tableau de valeurs de la matrice 
	///@details aucun argument, ce setter fonctionne en lisant un fichier texte
	///@param RIEN
	///@return RIEN
	void LECSetTabValeurs();

	///@brief definit le nom du fichier lu
	///@param LECnF nom du fichier
	///@return RIEN
	void LECSetNomFichier(char* LECnF);

};
#endif

///
/// @file CException.h
/// @author BLUMSTEIN Thomas
/// @coauthor NASSIRI Adam
/// @date 2021-04-17
///
#include <string>
#include <iostream>
#include "CLecture.h"
#include "CException.h"
#include <fstream>

using namespace std;

//constructeur de CLecture par defaut 
CLecture::CLecture()
{
	uiLECnbColonnes = 0;
	uiLECnbLignes = 0;
	pLECnomType = nullptr;
	pLECtabValeurs = nullptr;
	pLECnomFichier = nullptr;
}

//constructeur de CLecture de confort avec indication du nom du fichier
CLecture::CLecture(char* pnF)
{
	CException EXCExceptionLecture = *new CException();
	EXCExceptionLecture.EXCSetOperation('L');
	
	try {
		pLECnomFichier = pnF;
		fmyFile.open(pLECnomFichier);

		if (fmyFile) {
			LECSetNomType();
			LECSetNbLigne();
			LECSetNbColonne();
			LECSetTabValeurs();
			fmyFile.close();
		}

		else {
			EXCExceptionLecture.EXCSetMessage((char*)"Erreur lors de l'ouverture du fichier");
			throw(EXCExceptionLecture);
		}

	}

	catch (CException EXCExceptionLecture) {
		EXCExceptionLecture.EXCAfficherException();
	}

}

//constructeur de CLecture de recopie
CLecture::CLecture(CLecture &LEClecture)
{
	uiLECnbColonnes = LEClecture.LECGetNbColonnes();
	uiLECnbLignes = LEClecture.LECGetNbLignes();
	LEClecture.LECGetnomType(pLECnomType);
	LEClecture.LECGetTabValeurs(pLECtabValeurs);
	pLECnomFichier = LEClecture.pLECnomFichier;
}

//destructeur de CLecture
CLecture::~CLecture()
{
	//delete pLECnomType;
	//delete pLECnomFichier;
	delete pLECtabValeurs;
}

///@brief renvoie le nombre de lignes qui sera attribue a la matrice
///@param RIEN
///@return uiLECnbLignes le nombre de lignes a attribuer a la matrice
int CLecture::LECGetNbLignes()
{
	return uiLECnbLignes;
}

///@brief renvoie le nombre de colonnes qui sera attribue a la matrice
///@param RIEN
///@return uiLECnbLignes le nombre de colonnes a attribuer a la matrice
int CLecture::LECGetNbColonnes()
{
	return uiLECnbColonnes;
}

///@brief copie le nom du type des elements de la matrice dans le char* en parametre
///@param pLECnT chaine dans laquelle on copie le nom du type
///@return RIEN
void CLecture::LECGetnomType(char* pLECnT)
{
	strcpy_s(pLECnT,sizeof pLECnT,pLECnomType);
}

///@brief copie le tableau des elements de la matrice dans le tableau en parametre
///@param pLECtV tableau dans lequel on copie le tableau des valeurs
///@return RIEN
void CLecture::LECGetTabValeurs(double** pLECtV)
{
	unsigned int uiboucleTab;
	unsigned int uiboucleLignes;
	unsigned int uiboucleColonnes;
	for (uiboucleTab = 0; uiboucleTab < uiLECnbLignes; uiboucleTab++) {
		pLECtV[uiboucleTab] = new double[uiLECnbColonnes];
	}
	for (uiboucleLignes = 0; uiboucleLignes < uiLECnbLignes; uiboucleLignes++) {
		for (uiboucleColonnes = 0; uiboucleColonnes < uiLECnbColonnes; uiboucleColonnes++) {

			pLECtV[uiboucleLignes][uiboucleColonnes] = pLECtabValeurs[uiboucleLignes][uiboucleColonnes];
		}

	}

}

///@brief definit le nombre de lignes attribuees a la matrice 
///@details aucun argument, ce setter fonctionne en lisant un fichier texte
///@param RIEN
///@return RIEN
void CLecture::LECSetNbLigne()
{
	char cLigne[50];
	char* cParse;
	char* context = NULL;

	CException EXCExceptionLecture = *new CException();
	EXCExceptionLecture.EXCSetOperation('L');

	fmyFile.getline(cLigne, 50);
	cParse = strtok_s(cLigne, "=", &context);
	cParse = strtok_s(NULL, "=", &context);

	if (cParse == 0) {
		EXCExceptionLecture.EXCSetMessage((char*)"Erreur lors de l'ouverture du fichier");
		throw(EXCExceptionLecture);
	}

	else {
		uiLECnbLignes = atoi(cParse);
	}
	
}

///@brief definit le nombre de colonnes attribuees a la matrice 
///@details aucun argument, ce setter fonctionne en lisant un fichier texte
///@param RIEN
///@return RIEN
void CLecture::LECSetNbColonne()
{
	char cLigne[50];
	char* cParse;
	char* context = NULL;
	fmyFile.getline(cLigne, 50);
	cParse = strtok_s(cLigne, "=", &context);
	cParse = strtok_s(NULL, "=", &context);

	if (cParse == 0) {
		EXCExceptionLecture.EXCSetMessage((char*)"Erreur lors de l'ouverture du fichier");
		throw(EXCExceptionLecture);
	}

	else {
		uiLECnbLignes = atoi(cParse);
	}
}

///@brief definit le nom du type des elements de la matrice 
///@details aucun argument, ce setter fonctionne en lisant un fichier texte
///@param RIEN
///@return RIEN
void CLecture::LECSetNomType()
{
	char cLigne[50];
	char* cParse;
	char* context = NULL;
	pLECnomType = new char[10];
	fmyFile.getline(cLigne, 50);
	cParse = strtok_s(cLigne, "=", &context);
	cParse = strtok_s(NULL, "=", &context);
	strcpy_s(pLECnomType, sizeof(pLECnomType), cParse);

}

///@brief definit le tableau de valeurs de la matrice 
///@details aucun argument, ce setter fonctionne en lisant un fichier texte
///@param RIEN
///@return RIEN
void CLecture::LECSetTabValeurs()
{

	char cLigne[50];
	char* cParse = new char[50];
	char* context = NULL;
	unsigned int uiBoucleLignes;
	unsigned int uiBoucleColonnes;
	unsigned int uiboucleTab;
	pLECtabValeurs = new double*[uiLECnbLignes];
	for (uiboucleTab = 0; uiboucleTab < uiLECnbLignes; uiboucleTab++) {
		pLECtabValeurs[uiboucleTab] = new double[uiLECnbColonnes];
	}

	fmyFile.getline(cLigne, 50);
	fmyFile.getline(cLigne, 50);
	for (uiBoucleLignes = 0; uiBoucleLignes < uiLECnbLignes; uiBoucleLignes++) {
		cParse = strtok_s(cLigne, "\t", &context);
		cParse = strtok_s(cParse, " ", &context);
		for (uiBoucleColonnes = 0; uiBoucleColonnes < uiLECnbColonnes; uiBoucleColonnes++) {

			pLECtabValeurs[uiBoucleLignes][uiBoucleColonnes] = atof(cParse);
			cParse = strtok_s(NULL, " ", &context);
		}
		fmyFile.getline(cLigne, 50);
	}

}

///@brief definit le nom du fichier lu
///@param LECnF nom du fichier
///@return RIEN
void CLecture::LECSetNomFichier(char * LECnF)
{
	pLECnomFichier = LECnF;
}

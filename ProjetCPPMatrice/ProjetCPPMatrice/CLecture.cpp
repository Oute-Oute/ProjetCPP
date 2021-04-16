#include <string>
#include <iostream>
#include "CLecture.h"
#include "CException.h"
#include <fstream>

using namespace std;

CLecture::CLecture()
{
	uiLECnbColonnes = 0;
	uiLECnbLignes = 0;
	pLECnomType = nullptr;
	pLECtabValeurs = nullptr;
	pLECnomFichier = nullptr;
}

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
			EXCExceptionLecture.EXCSetMessage("Erreur lors de l'ouverture du fichier")
			throw(EXCExceptionLecture);
		}

	}

	catch (CException EXCExceptionLecture) {
		EXCExceptionLecture.EXCAfficherException();
	}

}

CLecture::CLecture(CLecture &LEClecture)
{
	uiLECnbColonnes = LEClecture.LECGetNbColonnes();
	uiLECnbLignes = LEClecture.LECGetNbLignes();
	LEClecture.LECGetnomType(pLECnomType);
	LEClecture.LECGetTabValeurs(pLECtabValeurs);
	pLECnomFichier = LEClecture.pLECnomFichier;
}

CLecture::~CLecture()
{
	//delete pLECnomType;
	//delete pLECnomFichier;
	delete pLECtabValeurs;
}

int CLecture::LECGetNbLignes()
{
	return uiLECnbLignes;
}

int CLecture::LECGetNbColonnes()
{
	return uiLECnbColonnes;
}

void CLecture::LECGetnomType(char* pLECnT)
{
	strcpy_s(pLECnT,sizeof pLECnT,pLECnomType);
}

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

void CLecture::LECSetNbLigne()
{
	char cLigne[50];
	char* cParse;
	char* context = NULL;


	fmyFile.getline(cLigne, 50);
	cParse = strtok_s(cLigne, "=", &context);
	cParse = strtok_s(NULL, "=", &context);

	if (cParse == 0) {
		EXCExceptionLecture.EXCSetMessage("Erreur lors de l'ouverture du fichier");
		throw(EXCExceptionLecture);
	}

	else {
		uiLECnbLignes = atoi(cParse);
	}
	
}

void CLecture::LECSetNbColonne()
{
	char cLigne[50];
	char* cParse;
	char* context = NULL;
	fmyFile.getline(cLigne, 50);
	cParse = strtok_s(cLigne, "=", &context);
	cParse = strtok_s(NULL, "=", &context);
	uiLECnbColonnes = atoi(cParse);

	//exception
}

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

void CLecture::LECSetNomFichier(char * LECnF)
{
	pLECnomFichier = LECnF;
}

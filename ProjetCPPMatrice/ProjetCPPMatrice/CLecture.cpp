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
	pLECnomFichier = pnF;
	LECSetNbLigne();
	LECSetNbColonne();
	LECSetNomType();
	LECSetTabValeurs();
}

CLecture::CLecture(CLecture &LEClecture)
{
	uiLECnbColonnes = LEClecture.LECGetNbColonnes();
	uiLECnbLignes = LEClecture.LECGetNbLignes();
	pLECnomType = LEClecture.LECGetnomType();
	pLECtabValeurs = LEClecture.LECGetTabValeurs();
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

char* CLecture::LECGetnomType()
{
	return pLECnomType;
}

double** CLecture::LECGetTabValeurs()
{
	return pLECtabValeurs;
}

void CLecture::LECSetNbLigne()
{
	ifstream fmyFile;
	char cLigne[50];
	char* cParse;
	char* context = NULL;
	fmyFile.open(pLECnomFichier);
	if (fmyFile) {
		fmyFile.getline(cLigne,50);
		fmyFile.getline(cLigne, 50);
		cParse = strtok_s(cLigne, "=",&context);
		cParse = strtok_s(NULL, "=",&context);
		uiLECnbLignes = atoi(cParse);

		fmyFile.close();
	}

	//exception
}

void CLecture::LECSetNbColonne()
{
	ifstream fmyFile;
	char cLigne[50];
	char* cParse;
	char* context = NULL;
	fmyFile.open(pLECnomFichier);
	if (fmyFile) {
		fmyFile.getline(cLigne, 50);
		fmyFile.getline(cLigne, 50);
		fmyFile.getline(cLigne, 50);
		cParse = strtok_s(cLigne, "=", &context);
		cParse = strtok_s(NULL, "=", &context);
		uiLECnbColonnes = atoi(cParse);

		fmyFile.close();
	}

}

void CLecture::LECSetNomType()
{
	ifstream fmyFile;
	char cLigne[50];
	char* cParse;
	char* context = NULL;
	fmyFile.open(pLECnomFichier);
	if (fmyFile) {
		fmyFile.getline(cLigne, 50);
		cParse = strtok_s(cLigne, "=", &context);
		cParse = strtok_s(NULL, "=", &context);
		pLECnomType = cParse;
		fmyFile.close();
	}
}

void CLecture::LECSetTabValeurs()
{
	ifstream fmyFile;
	char cLigne[50];
	char* cParse=new char[50];
	char* context = NULL;
	unsigned int uiBoucleLignes;
	unsigned int uiBoucleColonnes;
	unsigned int uiboucleTab;
	double** ptabVal=new double*[uiLECnbLignes];
	for (uiboucleTab = 0; uiboucleTab < uiLECnbLignes; uiboucleTab++) {
		ptabVal[uiboucleTab] = new double[uiLECnbColonnes];
	}
	fmyFile.open(pLECnomFichier);
	if (fmyFile) {
		fmyFile.getline(cLigne, 50);
		fmyFile.getline(cLigne, 50);
		fmyFile.getline(cLigne, 50);
		fmyFile.getline(cLigne, 50);
		fmyFile.getline(cLigne, 50);
		for (uiBoucleLignes = 0; uiBoucleLignes < uiLECnbLignes; uiBoucleLignes++) {
			cParse = strtok_s(cLigne, "\t", &context);
			cParse = strtok_s(cParse, " ", &context);
			for (uiBoucleColonnes = 0; uiBoucleColonnes < uiLECnbColonnes; uiBoucleColonnes++) {
				
				ptabVal[uiBoucleLignes][uiBoucleColonnes] = atof(cParse);
				cParse = strtok_s(NULL, " ", &context);
				cout << ptabVal[uiBoucleLignes][uiBoucleColonnes];
			}
			fmyFile.getline(cLigne, 50);
		}
		
		fmyFile.close();
	}
}

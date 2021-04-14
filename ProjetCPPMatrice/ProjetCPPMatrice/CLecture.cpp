#include <string>
#include <iostream>
#include "CLecture.h"
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
	uiLECnbColonnes = 0;
	uiLECnbLignes = 0;
	pLECnomType = nullptr;
	pLECtabValeurs = nullptr;
	pLECnomFichier = pnF;
}

CLecture::CLecture(CLecture &LEClecture)
{
	uiLECnbColonnes = LEClecture.LECGetnbColonne();
	uiLECnbLignes = LEClecture.LECGetNbLignes();
	pLECnomType = LEClecture.LECGetnomType();
	pLECtabValeurs = LEClecture.LECGetTabValeurs();
	pLECnomFichier = LEClecture.pLECnomFichier;
}

CLecture::~CLecture()
{
	delete pLECnomType;
	//delete pLECnomFichier;
	delete pLECtabValeurs;
}

int CLecture::LECGetNbLignes()
{
	return uiLECnbLignes;
}

int CLecture::LECGetnbColonne()
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
	int inbLignes;
	fmyFile.open(pLECnomFichier);
	if (fmyFile) {
		fmyFile.getline(cLigne,50);
		fmyFile.getline(cLigne, 50);
		cParse = strtok_s(cLigne, "=",&context);
		cParse = strtok_s(NULL, "=",&context);
		inbLignes = atoi(cParse);
		cout << inbLignes;

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
	int inbLignes;
	fmyFile.open(pLECnomFichier);
	if (fmyFile) {
		fmyFile.getline(cLigne, 50);
		fmyFile.getline(cLigne, 50);
		fmyFile.getline(cLigne, 50);
		cParse = strtok_s(cLigne, "=", &context);
		cParse = strtok_s(NULL, "=", &context);
		inbLignes = atoi(cParse);
		cout << inbLignes;

		fmyFile.close();
	}
	//exception
}

void CLecture::LECSetNomType()
{
}

void CLecture::LECSetTabValeurs()
{
}

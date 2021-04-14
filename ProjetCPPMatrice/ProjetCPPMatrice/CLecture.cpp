#include <string>
#include <iostream>
#include "CLecture.h"

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
	delete pLECnomFichier;
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
	FILE* myFile;

	fopen_s(&myFile, pLECnomFichier, "r");
	if (myFile) {

	}
}

void CLecture::LECSetNbColonne()
{
}

void CLecture::LECSetNomType()
{
}

void CLecture::LECSetTabValeurs()
{
}

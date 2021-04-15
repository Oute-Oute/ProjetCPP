#include <string>
#include <iostream>
#include "CLecture.h"
#include <fstream>
#include "CException.h"
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
	//delete pLECnomType;
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
	//initialisation de l'objet exception
	CException EXCexception = *new CException();
	EXCexception.EXCSetOperation('L');

	ifstream fmyFile;
	char cLigne[50];
	char* cParse;
	char* context = NULL;
	fmyFile.open(pLECnomFichier);

	try {
		if (fmyFile) {
			fmyFile.getline(cLigne, 50);
			fmyFile.getline(cLigne, 50);
			cParse = strtok_s(cLigne, "=", &context);
			cParse = strtok_s(NULL, "=", &context);
			uiLECnbLignes = atoi(cParse);

			fmyFile.close();
		}

		//exception
		else {
			EXCexception.EXCSetMessage((char*)"Erreur d'ouverture de fichier!");
			throw(EXCexception);
		}

	}

	catch (CException EXCexception) {
		cout << "Opération" << EXCexception.EXCGetOperation() << ", exception: " << EXCexception.EXCGetMessage() << endl;
	}

}

void CLecture::LECSetNbColonne()
{


	ifstream fmyFile;
	char cLigne[50];
	char* cParse;
	char* context = NULL;
	fmyFile.open(pLECnomFichier);

	//initialisation de l'objet exception
	CException EXCexception = *new CException();
	EXCexception.EXCSetOperation('L');

	//traitement
	try {

		if (fmyFile) {
			fmyFile.getline(cLigne, 50);
			fmyFile.getline(cLigne, 50);
			fmyFile.getline(cLigne, 50);
			cParse = strtok_s(cLigne, "=", &context);
			cParse = strtok_s(NULL, "=", &context);
			uiLECnbColonnes = atoi(cParse);

			fmyFile.close();
		}

		else {
			EXCexception.EXCSetMessage((char*)"Erreur d'ouverture de fichier!");
			throw(EXCexception);
		}

	}

	//lever l exception
	catch (CException EXCexception) {
		cout << "Opération" << EXCexception.EXCGetOperation() << ", exception: " << EXCexception.EXCGetMessage() << endl;
	}
}

void CLecture::LECSetNomType()
{
	ifstream fmyFile;
	char cLigne[50];
	char* cParse;
	char* context = NULL;
	fmyFile.open(pLECnomFichier);

	//initialisation de l'objet exception
	CException EXCexception = *new CException();
	EXCexception.EXCSetOperation('L');

	try {
		if (fmyFile) {
			fmyFile.getline(cLigne, 50);
			cParse = strtok_s(cLigne, "=", &context);
			cParse = strtok_s(NULL, "=", &context);
			pLECnomType = cParse;
			cout << pLECnomType;
			fmyFile.close();
		}

		else {
			EXCexception.EXCSetMessage((char*)"Erreur d'ouverture de fichier!");
			throw(EXCexception);
		}

	}

	//lever l exception
	catch (CException EXCexception) {
		cout << "Opération" << EXCexception.EXCGetOperation() << ", exception: " << EXCexception.EXCGetMessage() << endl;
	}

}

void CLecture::LECSetTabValeurs()
{

}

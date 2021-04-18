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
	CLecture();

	CLecture(char* pnF);

	CLecture(CLecture &LEClecture);

	~CLecture();

	int LECGetNbLignes();

	int LECGetNbColonnes();

	void LECGetnomType(char* pLECnT);

	void LECGetTabValeurs(double** pLECtV);

	void LECSetNbLigne();

	void LECSetNbColonne();

	void LECSetNomType();

	void LECSetTabValeurs();

	void LECSetNomFichier(char* LECnF);

	void LECLireFichier();

};
#endif

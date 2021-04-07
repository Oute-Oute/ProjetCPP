#ifndef C_MATRICE_H
#define C_MATRICE_H

#include <fstream>
#include <iostream>
using namespace std;

template <class nomType>
class CMatrice
{
private:
	unsigned int iMATnbLignes;

	unsigned int iMATnbColonnes;

	char* cMATnomType;

	nomType * pMATtabValeurs;

public:
	CMatrice();

	CMatrice(int MATnbL, int MATnbC,char* MATnT, nomType * MATtV);

	CMatrice(CMatrice &MATM1);

	~CMatrice();

	int MATGetnbLigne();

	int MATGetnbColonne();

	char* MATGetnomType();

	void MATSetnbLigne(int MATnbL);

	void MATSetnbColonne(int MATnbC);
	
	void MATSetnomType(char* MATnT);

	friend ostream& operator<<(ostream& os, CMatrice &MATM1);

};
#endif

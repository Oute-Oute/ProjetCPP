#ifndef C_MATRICE_H
#define C_MATRICE_H

#include <fstream>
#include <iostream>
using namespace std;

class CMatrice
{
private:
	int iMATnbLignes;

	int iMATnbColonnes;


public:
	CMatrice();

	CMatrice(int MATnbL, int MATnbC);

	CMatrice(CMatrice &MATM1);

	~CMatrice();

	int MATGetnbLigne();

	int MATGetnbColonne();

	void MATSetnbLigne();

	void MATSetnbColonne();

	friend ostream& operator<<(ostream& os, CMatrice &MATM1);

};
#endif

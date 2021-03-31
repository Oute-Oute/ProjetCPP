#ifndef C_OPERATIONS_MATRICE_H
#define C_OPERATIONS_MATRICE_H

#include "CMatrice.h"

class COperationsMatrice
{
private:
	CMatrice pmOMAMatrice;


public:
	COperationsMatrice();

	COperationsMatrice(COperationsMatrice &OMAM1);

	COperationsMatrice(int pmOMAMat);

	~COperationsMatrice();

	COperationsMatrice &operator+(COperationsMatrice &OMAM1);

	COperationsMatrice &operator*(COperationsMatrice &OMAM1);

	COperationsMatrice &operator*(COperationsMatrice &OMAM1, int &iElem);

	COperationsMatrice &operator*(int &iElem, COperationsMatrice &OMAM1);

	COperationsMatrice &operator/(int &iElem, COperationsMatrice &OMAM1);

	COperationsMatrice &operator-(COperationsMatrice &OMAM1);

	COperationsMatrice MATCalculTransposee(COperationsMatrice OMAM1);

};
#endif

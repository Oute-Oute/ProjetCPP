#ifndef C_OPERATIONS_MATRICE_H
#define C_OPERATIONS_MATRICE_H

#include "CMatrice.h"

template <class nomType>
class COperationsMatrice
{
private:
	CMatrice<nomType> pmOMAMatrice;


public:
	COperationsMatrice();

	COperationsMatrice(COperationsMatrice<nomType> &OMAM1);

	COperationsMatrice(int pmOMAMat);

	~COperationsMatrice();

	CMatrice<nomType> operator+(COperationsMatrice<nomType> &OMAM1);

	CMatrice<nomType> operator*(COperationsMatrice<nomType> &OMAM1);

	CMatrice<nomType> operator*(int &iElem);

	//CMatrice<nomType> operator*(int &iElem * COperationsMatrice<nomType> &OMAM1);

	CMatrice<nomType> operator/(int &iElem);

	CMatrice<nomType> operator-(COperationsMatrice<nomType> &OMAM1);

	CMatrice<nomType> MATCalculTransposee(COperationsMatrice<nomType> OMAM1);

};
#endif

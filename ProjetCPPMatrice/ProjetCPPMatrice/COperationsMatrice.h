#ifndef C_OPERATIONS_MATRICE_H
#define C_OPERATIONS_MATRICE_H

#include "CMatrice.h"

template <class nomType>
class COperationsMatrice
{
private:
	CMatrice<nomType> pmOMAMatrice;


public:
	//constructeur par defaut
	COperationsMatrice();

	//constructeur de recopie
	COperationsMatrice(COperationsMatrice<nomType> &OMAM1);

	//constructeur a partir d une CMatrice*
	COperationsMatrice(CMatrice<nomType>* pmOMAMat);

	//destructeur
	~COperationsMatrice();

	CMatrice<nomType> operator+(COperationsMatrice<nomType> &OMAM1);

	CMatrice<nomType> operator-(COperationsMatrice<nomType> &OMAM1);

	CMatrice<nomType> operator*(COperationsMatrice<nomType> &OMAM1);

	CMatrice<nomType> operator*(int &iElem);

	//CMatrice<nomType> operator*(int &iElem * COperationsMatrice<nomType> &OMAM1);

	CMatrice<nomType> operator/(int &iElem);

	CMatrice<nomType> MATCalculTransposee(COperationsMatrice<nomType> OMAM1);

};
#endif

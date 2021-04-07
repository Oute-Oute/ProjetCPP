#include <fstream>
#include <iostream>

#include "CMatrice.h"

template<class nomType>
CMatrice<nomType>::CMatrice()
{
	iMATnbColonnes = 0;
	iMATnbLignes = 0;
	cMATnomType = nullptr;
}

template<class nomType>
CMatrice<nomType>::CMatrice(int MATnbL, int MATnbC, char* MATnT, nomType * MATtV)
{
	iMATnbLignes = MATnbL;
	iMATnbColonnes = MATnbC;
	cMATnomType = MATnT;
}

template<class nomType>
CMatrice<nomType>::CMatrice(CMatrice &MATM1)
{
	iMATnbLignes = MATM1.MATGetnbLigne();
	iMATnbColonnes = MATM1.MATGetnbColonne();
	cMATnomType = MATM1.MATGetnomType();
}

template<class nomType>
CMatrice<nomType>::~CMatrice()
{
	iMATnbColonnes = 0;
	iMATnbLignes = 0;
	delete cMATnomType;
}

template<class nomType>
int CMatrice<nomType>::MATGetnbLigne()
{
	return iMATnbLignes;
}

template<class nomType>
int CMatrice<nomType>::MATGetnbColonne()
{
	return iMATnbColonnes;
}

template<class nomType>
char * CMatrice<nomType>::MATGetnomType()
{
	return cMATnomType;
}

template<class nomType>
void CMatrice<nomType>::MATSetnbLigne(int MATnbL)
{
	iMATnbLignes = MATnbL;
}

template<class nomType>
void CMatrice<nomType>::MATSetnbColonne(int MATnbC)
{
	iMATnbColonnes = MATnbC;
}

template<class nomType>
void CMatrice<nomType>::MATSetnomType(char * MATnT)
{
	cMATnomType = MATnT;
}

template<class nomType>
ostream & operator<<(ostream & os, CMatrice<nomType> &MATM1)
{
	for (int iboucleLignes = 0; iboucleLignes < MATM1.iMATnbLignes; iboucleLignes++)
	{
		for (int iboucleColonnes = 0; iboucleColonnes < MATM1.iMATnbColonnes; iboucleColonnes++)
		{
			os << MATM1.pMATtabValeurs[iboucleLignes][iboucleColonnes] << "  ";
		}
		os << endl;
	}
	os << endl << endl;
	return(os);
}

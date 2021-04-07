#include <fstream>
#include <iostream>

#include "CMatrice.h"

template<class nomType>
CMatrice<nomType>::CMatrice()
{
	uiMATnbColonnes = 0;
	uiMATnbLignes = 0;
	cMATnomType = nullptr;
}

template<class nomType>
CMatrice<nomType>::CMatrice(int MATnbL, int MATnbC, char* MATnT, nomType * MATtV)
{
	uiMATnbLignes = MATnbL;
	uiMATnbColonnes = MATnbC;
	cMATnomType = MATnT;
}

template<class nomType>
CMatrice<nomType>::CMatrice(CMatrice &MATM1)
{
	uiMATnbLignes = MATM1.MATGetnbLigne();
	uiMATnbColonnes = MATM1.MATGetnbColonne();
	cMATnomType = MATM1.MATGetnomType();
}

template<class nomType>
CMatrice<nomType>::~CMatrice()
{
	uiMATnbColonnes = 0;
	uiMATnbLignes = 0;
	delete cMATnomType;
}

template<class nomType>
int CMatrice<nomType>::MATGetnbLigne()
{
	return uiMATnbLignes;
}

template<class nomType>
int CMatrice<nomType>::MATGetnbColonne()
{
	return uiMATnbColonnes;
}

template<class nomType>
char * CMatrice<nomType>::MATGetnomType()
{
	return cMATnomType;
}

template<class nomType>
void CMatrice<nomType>::MATSetnbLigne(int MATnbL)
{
	uiMATnbLignes = MATnbL;
}

template<class nomType>
void CMatrice<nomType>::MATSetnbColonne(int MATnbC)
{
	uiMATnbColonnes = MATnbC;
}

template<class nomType>
void CMatrice<nomType>::MATSetnomType(char * MATnT)
{
	cMATnomType = MATnT;
}

template<class nomType>
ostream & operator<<(ostream & os, CMatrice<nomType> &MATM1)
{
	for (int iboucleLignes = 0; iboucleLignes < MATM1.uiMATnbLignes; iboucleLignes++)
	{
		for (int iboucleColonnes = 0; iboucleColonnes < MATM1.uiMATnbColonnes; iboucleColonnes++)
		{
			os << MATM1.pMATtabValeurs[iboucleLignes][iboucleColonnes] << "  ";
		}
		os << endl;
	}
	os << endl << endl;
	return(os);
}

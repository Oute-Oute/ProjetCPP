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
int CMatrice<nomType>::MATGetNbLigne()
{
	return uiMATnbLignes;
}

template<class nomType>
int CMatrice<nomType>::MATGetNbColonne()
{
	return uiMATnbColonnes;
}

template<class nomType>
char * CMatrice<nomType>::MATGetNomType()
{
	return cMATnomType;
}

template<class nomType>
inline nomType CMatrice<nomType>::MATgetTabValeur()
{
	return pMATtabValeurs;
}

template<class nomType>
void CMatrice<nomType>::MATSetNbLigne(int MATnbL)
{
	uiMATnbLignes = MATnbL;
}

template<class nomType>
void CMatrice<nomType>::MATSetNbColonne(int MATnbC)
{
	uiMATnbColonnes = MATnbC;
}

template<class nomType>
void CMatrice<nomType>::MATSetNomType(char * MATnT)
{
	cMATnomType = MATnT;
}

template<class nomType>
void CMatrice<nomType>::MATSetTabValeur(nomType * MATtV)
{
	*pMATtabValeurs = *MATtV;
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

#ifndef C_MATRICE_H
#define C_MATRICE_H

#include <fstream>
#include <iostream>
using namespace std;

template <class nomType>
class CMatrice
{
private:
	unsigned int uiMATnbLignes;

	unsigned int uiMATnbColonnes;

	char* cMATnomType;

	nomType * pMATtabValeurs;

public:
	CMatrice();

	CMatrice(int MATnbL, int MATnbC,char* MATnT, nomType * MATtV);

	CMatrice(CMatrice &MATM1);

	~CMatrice();

	int MATGetNbLigne();

	int MATGetNbColonne();

	char* MATGetNomType();

	nomType MATgetTabValeur();

	void MATSetNbLigne(int MATnbL);

	void MATSetNbColonne(int MATnbC);
	
	void MATSetNomType(char* MATnT);

	void MATSetTabValeur(nomType *MATtV);

	void MATAfficherMatrice();
	
	ostream& operator<<(ostream& os, CMatrice<nomType> const& MATM1);

};

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
inline void CMatrice<nomType>::MATAfficherMatrice()
{
}

template<class nomType>
inline ostream & CMatrice<nomType>::operator<<(ostream & os, CMatrice<nomType> const & MATM1)
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
	// TODO: insérer une instruction return ici
}

#endif

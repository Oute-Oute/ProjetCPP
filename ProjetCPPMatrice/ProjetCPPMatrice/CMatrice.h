///
/// @file CMatrice.h
/// @author BLUMSTEIN Thomas
/// @coauthor NASSIRI Adam
/// @date 2021-04-15
///

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

	nomType ** pMATtabValeurs;

public:
	//constructeur de CMatrice par defaut
	CMatrice();

	//constructeur avec indication des donnees
	CMatrice(int MATnbL, int MATnbC,char* MATnT, nomType ** MATtV);

	//constructeur de CMatrice de recopie
	CMatrice(CMatrice &MATM1);

	//destructeur de CMatrice
	~CMatrice();

	/// @brief renvoie le nombre de lignes de la matrice
	/// @param RIEN
	/// @return uiMATnbLignes le nombre de lignes de la matrice
	int MATGetNbLigne();

	/// @brief renvoie le nombre de colonnes de la matrice
	/// @param RIEN
	/// @return uiMATnbColonnes le nombre de colonnes de la matrice
	int MATGetNbColonne();


	/// @brief renvoie le type des elements dde la matrice
	/// @param RIEN
	/// @return cMATnomTypele le type des elements de la matrice
	char* MATGetNomType();

	/// @brief renvoie le tableau d'elements de la matrice
	/// @param RIEN
	/// @return pMATtabValuerse le tableau des elements de la matrices
	nomType MATgetTabValeur();

	/// @brief definit le nombre de lignes d'une CMatrice
	/// @param MATnb nombre de lignes qu'on impose
	/// @return RIEN
	void MATSetNbLigne(int MATnbL);

	/// @brief definit le nombre de colonnes d'une CMatrice
	/// @param MATnbC nombre de colonnes qu'on impose
	/// @return RIEN
	void MATSetNbColonne(int MATnbC);
	
	/// @brief definit le nom du type des elements de la matrice
	/// @param MATnT nombre de lignes qu'on impose
	/// @return RIEN
	void MATSetNomType(char* MATnT);

	/// @brief definit le tableau des elements de la CMatrice
	/// @param MATtV nombre de lignes qu'on impose
	/// @return RIEN
	void MATSetTabValeur(nomType **MATtV);

	/// @brief definit le tableau des elements de la CMatrice 
	/// @param RIEN
	/// @return RIEN
	void MATSetTabValeur();

	/// @brief affiche le contenu de la CMatrice: repmlit le tableau avec des entiers croissants en partant de 0
	/// @param RIEN
	/// @return RIEN
	void MATAfficherMatrice();
	
	ostream& operator<<(ostream& os);

};

template<class nomType>
CMatrice<nomType>::CMatrice()
{
	uiMATnbColonnes = 0;
	uiMATnbLignes = 0;
	cMATnomType = nullptr;
	pMATtabValeurs = nullptr;
}

template<class nomType>
CMatrice<nomType>::CMatrice(int MATnbL, int MATnbC, char* MATnT, nomType ** MATtV)
{
	uiMATnbLignes = MATnbL;
	uiMATnbColonnes = MATnbC;
	cMATnomType = MATnT;
	pMATtabValeurs = MATtV;
}

template<class nomType>
CMatrice<nomType>::CMatrice(CMatrice &MATM1)
{
	uiMATnbLignes = MATM1.MATGetNbLigne();
	uiMATnbColonnes = MATM1.MATGetNbColonne();
	cMATnomType = MATM1.MATGetNomType();
	pMATtabValeurs = MATM1.MATGetTabValeur;
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
void CMatrice<nomType>::MATSetTabValeur(nomType ** MATtV)
{
	for (int iboucleLignes = 0; iboucleLignes < uiMATnbLignes; iboucleLignes++)
	{
		for (int iboucleColonnes = 0; iboucleColonnes < uiMATnbColonnes; iboucleColonnes++)
		{
			pMATtabValeurs[iboucleLignes][iboucleColonnes] = MATtV[iboucleLignes][iboucleColonnes];
		}
	}
}

template<class nomType>
inline void CMatrice<nomType>::MATSetTabValeur()
{
	int k = 0;
	for (int iboucleLignes = 0; iboucleLignes < uiMATnbLignes; iboucleLignes++)
	{
		for (int iboucleColonnes = 0; iboucleColonnes < uiMATnbColonnes; iboucleColonnes++)
		{
			pMATtabValeurs[iboucleLignes][iboucleColonnes] = k;
			k++;
		}
	}
}

template<class nomType>
inline void CMatrice<nomType>::MATAfficherMatrice()
{
	for (int iboucleLignes = 0; iboucleLignes < uiMATnbLignes; iboucleLignes++)
	{
		for (int iboucleColonnes = 0; iboucleColonnes < uiMATnbColonnes; iboucleColonnes++)
		{
			cout << pMATtabValeurs[iboucleLignes][iboucleColonnes] << "  ";
		}
		cout << endl;
	}
}

template<class nomType>
inline ostream & CMatrice<nomType>::operator<<(ostream & os)
{	
	for (int iboucleLignes = 0; iboucleLignes < uiMATnbLignes; iboucleLignes++)
	{
		for (int iboucleColonnes = 0; iboucleColonnes < uiMATnbColonnes; iboucleColonnes++)
		{
			os << pMATtabValeurs[iboucleLignes][iboucleColonnes] << "  ";
		}
		os << endl;
	}
	os << endl << endl;
	return(os);
	// TODO: insérer une instruction return ici
}

#endif

///
/// @file CImaginaire.h
/// @author NASSIRI Adam
/// @coauthor BLUMSTEIN Thomas
/// @date 2021-02-06
///


#include "CException.h"

class CImaginaire {
private:
	float fIMAvaleur;

public:

	CImaginaire();

	CImaginaire(float ffloat);

	CImaginaire(CImaginaire &IMAimaginaire);

	~CImaginaire();

	float IMAgetValeur();

	void IMAsetValeur(float fValeur);

	void IMAafficher();

	//operations imaginaire-imaginaire
	CImaginaire operator+(CImaginaire &IMAi1);
	CImaginaire operator-(CImaginaire &IMAi1);
	CImaginaire operator*(CImaginaire &IMAi1);
	CImaginaire operator/(CImaginaire &IMAi1);

	//operations imaginaire-reel
	//il faudrait renvoyer un complexe, mais ça pose des problemes d'inclusion [ADAM]
	//CImaginaire operator+(float &IMAr1);
	//CImaginaire operator-(float &IMAr1);
	CImaginaire operator*(float fValeur);
	CImaginaire operator/(float fValeur);
};
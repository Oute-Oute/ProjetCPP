///
/// @file CComplexe.h
/// @author NASSIRI Adam
/// @coauthor BLUMSTEIN Thomas
/// @date 2021-02-06
///
#include "CImaginaire.h"

class CComplexe {

private:
	float fCOMpartieReelle;

	CImaginaire fCOMpartieImaginaire;

public:

	CComplexe();

	CComplexe(float fValeurReelle, CImaginaire IMAvaleurImaginaire);

	CComplexe(float fValeurReelle);

	CComplexe(CImaginaire IMAvaleurImaginaire);

	CComplexe(CComplexe COMComplexe);

	float COMgetPartieReelle();

	void COMsetPartieReelle(float);

	CImaginaire COMgetPartieImaginaire();

	void COMsetPartieImaginaire(CImaginaire IMAimaginaire);


	//operations complexe-complexe
	CComplexe operator+(CComplexe &COMc1);
	CComplexe operator-(CComplexe &COMc1);
	CComplexe operator*(CComplexe &COMc1);
	CComplexe operator/(CComplexe &COMc1);

	//operations complexe-reel
	CComplexe operator+(float fValeur);
	CComplexe operator-(float fValeur);
	CComplexe operator*(float fValeur);
	CComplexe operator/(float fValeur);

	//operations complexe-imaginaire
	CComplexe operator+(CImaginaire &IMAr1);
	CComplexe operator-(CImaginaire &IMAr1);
	CComplexe operator*(CImaginaire &IMAr1);
	CComplexe operator/(CImaginaire &IMAr1);
};
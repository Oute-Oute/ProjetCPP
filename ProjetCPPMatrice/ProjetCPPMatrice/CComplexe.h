///
/// @file CComplexe.h
/// @author NASSIRI Adam
/// @coauthor BLUMSTEIN Thomas
/// @date 2021-02-06
///

#include <iostream>
using namespace std;

class CComplexe {

private:
	double dCOMpartieReelle;

	double dCOMpartieImaginaire;

public:

	CComplexe();

	CComplexe(double dValeurReelle, double dValeurImaginaire);

	CComplexe(double dValeurReelle);

	CComplexe(CComplexe &COMComplexe);

	double COMgetPartieReelle();

	void COMsetPartieReelle(double dPartieReelle);

	double COMgetPartieImaginaire();

	void COMsetPartieImaginaire(double dPartieImaginaire);

	CComplexe COMconjugue();

	//operations complexe-complexe
	CComplexe operator + (CComplexe &COMc1);
	CComplexe operator - (CComplexe &COMc1);
	CComplexe operator * (const CComplexe &COMc1);
	CComplexe operator / (CComplexe &COMc1);
	void operator = (const CComplexe &COMc1);
	bool operator == (CComplexe &COMc1);

	//operations complexe-reel
	CComplexe operator + (double dValeur);
	CComplexe operator - (double dValeur);
	CComplexe operator * (double dValeur);
	CComplexe operator / (double dValeur);
	CComplexe operator = (double dValeur);
	bool operator == (double dValeur);
	void afficher(ostream &flux) const;

};

///
/// @file CComplexe.cpp
/// @author NASSIRI Adam
/// @coauthor BLUMSTEIN Thomas
/// @date 2021-02-06
///

#include "CComplexe.h"
#include <iostream>
using namespace std;

CComplexe::CComplexe() {
	dCOMpartieReelle = 0;
	dCOMpartieImaginaire = 0;
}

CComplexe::CComplexe(double dValeurReelle, double dValeurImaginaire) {
	this->dCOMpartieImaginaire = dValeurImaginaire;
	this->dCOMpartieReelle = dValeurReelle;
}

CComplexe::CComplexe(double dValeurReelle)
{
	this->dCOMpartieReelle = dValeurReelle;
	this->dCOMpartieImaginaire = 0;
}

CComplexe::CComplexe(CComplexe & COMComplexe)
{
	this->dCOMpartieImaginaire = COMComplexe.COMgetPartieImaginaire();
	this->dCOMpartieReelle = COMComplexe.COMgetPartieReelle();
}

double CComplexe::COMgetPartieReelle()
{
	return this->dCOMpartieReelle;
}

void CComplexe::COMsetPartieReelle(double dPartieReelle)
{
	this->dCOMpartieReelle = dPartieReelle;
}

double CComplexe::COMgetPartieImaginaire()
{
	return this->dCOMpartieImaginaire;
}

void CComplexe::COMsetPartieImaginaire(double dPartieImaginaire)
{
	this->dCOMpartieImaginaire = dPartieImaginaire;
}

CComplexe  CComplexe::COMconjugue() {
	CComplexe COMresultat;

	COMresultat.COMsetPartieImaginaire(-(this->COMgetPartieImaginaire()));
	COMresultat.COMsetPartieReelle(this->COMgetPartieReelle());

	return COMresultat;
}

//opérations complexe-complexe
CComplexe CComplexe::operator + (CComplexe & COMc1)
{
	CComplexe COMresultat;

	COMresultat.dCOMpartieImaginaire = this->dCOMpartieImaginaire + COMc1.dCOMpartieImaginaire;
	COMresultat.dCOMpartieReelle = this->dCOMpartieReelle + COMc1.dCOMpartieReelle;

	return COMresultat;
}

CComplexe CComplexe::operator - (CComplexe & COMc1)
{
	CComplexe COMresultat;

	COMresultat.COMsetPartieImaginaire(this->COMgetPartieImaginaire() - COMc1.COMgetPartieImaginaire());
	COMresultat.COMsetPartieReelle(this->COMgetPartieReelle() - COMc1.COMgetPartieReelle());

	return COMresultat;
}

CComplexe CComplexe::operator * (const CComplexe & COMc1)
{
	CComplexe COMresultat;

	COMresultat.COMsetPartieReelle(this->COMgetPartieReelle()*COMc1.dCOMpartieReelle - this->COMgetPartieImaginaire()*COMc1.dCOMpartieImaginaire);
	COMresultat.COMsetPartieImaginaire(this->COMgetPartieReelle()*COMc1.dCOMpartieReelle + this->COMgetPartieImaginaire()*COMc1.dCOMpartieImaginaire);

	return COMresultat;
}

CComplexe CComplexe::operator / (CComplexe & COMc1)
{
	CComplexe COMresultat;
	CComplexe COMnum(*this);
	CComplexe COMdeno(COMc1);
	CComplexe COMconj;
	COMconj = COMdeno.COMconjugue();
	double Ddeno;
	COMnum = COMnum * COMdeno.COMconjugue();
	COMdeno = COMdeno * COMdeno.COMconjugue();

	Ddeno = COMdeno.COMgetPartieReelle();

	COMresultat = COMnum / Ddeno;

	return COMresultat;
}


CComplexe CComplexe::operator = (const CComplexe &COMc1)
{
	CComplexe COMresultat;
	
	COMresultat.dCOMpartieImaginaire = COMc1.dCOMpartieImaginaire;
	COMresultat.dCOMpartieReelle = COMc1.dCOMpartieReelle;

	return COMresultat;
}

bool CComplexe::operator == (CComplexe &COMc1)
{
	return(this->dCOMpartieImaginaire==COMc1.dCOMpartieImaginaire && this->dCOMpartieReelle==COMc1.dCOMpartieReelle);
}

CComplexe CComplexe::operator+(double dValeur)
{
	CComplexe COMresultat(dValeur,0);

	COMresultat.dCOMpartieImaginaire = this->COMgetPartieImaginaire();
	COMresultat.dCOMpartieReelle = COMresultat.dCOMpartieReelle + this->dCOMpartieReelle;

	return COMresultat;
}

CComplexe CComplexe::operator - (double dValeur)
{
	CComplexe COMresultat(dValeur, 0);

	COMresultat.dCOMpartieImaginaire = this->COMgetPartieImaginaire();
	COMresultat.dCOMpartieReelle = COMresultat.dCOMpartieReelle - this->dCOMpartieReelle;

	return COMresultat;
}

CComplexe CComplexe::operator * (double dValeur)
{
	CComplexe COMresultat(this->COMgetPartieReelle()*dValeur,this->COMgetPartieImaginaire()*dValeur);

	return COMresultat;
}

CComplexe CComplexe::operator / (double dValeur)
{
	CComplexe COMresultat(this->COMgetPartieReelle()/dValeur, this->COMgetPartieImaginaire()/dValeur);

	return COMresultat;
}

CComplexe CComplexe::operator = (double dValeur)
{
	CComplexe COMresultat(dValeur,0);
	return COMresultat;
}

bool CComplexe::operator == (double dValeur)
{
	return (this->COMgetPartieImaginaire() == 0 && this->COMgetPartieReelle() == dValeur);
}

void CComplexe::afficher(std::ostream & flux) const
{
	flux << dCOMpartieReelle;
	if (this->dCOMpartieImaginaire>=0) {
		cout << "+";
	}
	cout<<dCOMpartieImaginaire<<"i";
}


///
/// @file CComplexe.cpp
/// @author NASSIRI Adam
/// @coauthor BLUMSTEIN Thomas
/// @date 2021-02-06
///

#include "CComplexe.h"

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
	this->dCOMPartieReelle = dValeurReelle;
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

CComplexe COMconjugue() {
	CComplexe COMresultat();

	COMresultat.COMsetPartieImaginaire(-(this->COMgetPartieImaginaire()));
	COMresultat.COMsetPartieReelle(this->COMgetPartieReelle());

	return COMresultat;
}

//opérations complexe-complexe
CComplexe CComplexe::operator + (CComplexe & COMc1)
{
	CComplexe COMresultat;

	COMresultat.COMsetPartieImaginaire(this->COMgetPartieImaginaire()+COMc1.COMgetPartieImaginaire());
	COMresultat.COMsetPartieReelle(this->COMgetPartieReelle() + COMc1.COMgetPartieIReelle());

	return COMresultat;
}

CComplexe CComplexe::operator - (CComplexe & COMc1)
{
	CComplexe COMresultat;

	COMresultat.COMsetPartieImaginaire(this->COMgetPartieImaginaire() - COMc1.COMgetPartieImaginaire());
	COMresultat.COMsetPartieReelle(this->COMgetPartieReelle() - COMc1.COMgetPartieIReelle());

	return COMresultat;
}

CComplexe CComplexe::operator * (CComplexe & COMc1)
{
	CComplexe COMresultat;

	COMresultat.SOMsetPartieReelle(this->COMgetPartieReelle()*COMc1.COMgetPartieReelle() - this->COMgetPartieImaginaire()*COMc1.COMgetPartieImaginaire());
	COMresultat.SOMsetPartieImaginaire(this->COMgetPartieReelle()*COMc1.COMgetPartieImaginaire() + this->COMgetPartieImaginaire()*COMc1.COMgetPartieReelle());

	return COMresultat;
}

CComplexe CComplexe::operator / (CComplexe & COMc1)
{
	CComplexe COMresultat;
	CComplexe COMnum(this);
	CComplexe COMdeno(COMc1);
	double Ddeno;
	COMnum = COMnum * COMdeno.COMconjugue();
	COMdeno = COMdeno * COMdeno.COMconjugue();

	Ddeno = SOMdeno.COMgetPartieReelle();

	COMresultat = COMnum / Ddeno;

	return COMresultat;
}


CComplexe CComplexe::operator = (CComplexe &COMc1)
{
	CComplexe COMresultat(COMc1.COMgetPartieReelle(), COMc1.COMgetPartieImaginaire());
	
	return *COMresultat;
}

bool CComplexe::operator == (CComplexe &COMc1)
{
	return(this->COMgetPartieImaginaire()==COMc1.COMgetPartieImaginaire() &&this->COMgetPartieReelle()==COMc1.COMgetPartieReelle());
}

CComplexe CComplexe::operator+(double dValeur)
{
	CComplexe COMresultat(dValeur,0);

	COMresultat += this;

	return COMresultat;
}

CComplexe CComplexe::operator - (double dValeur)
{
	CComplexe COMresultat(dValeur, 0);

	COMresultat -= this;

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
	CComplexe COMresultat(COMsetPartieReelle(dValeur),COMsetPartieImaginaire(0));
	return COMresultat;
}

void CComplexe::operator == (double dValeur)
{
	return (this->COMgetPartieImaginaire() == 0 && this->COMgetPartieReelle() == dValeur);
}
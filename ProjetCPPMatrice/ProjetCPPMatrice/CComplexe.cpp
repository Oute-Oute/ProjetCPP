
///
/// @file CComplexe.cpp
/// @author NASSIRI Adam
/// @coauthor BLUMSTEIN Thomas
/// @date 2021-02-06
///

#include "CComplexe.h"
#include <iostream>
using namespace std;

///@brief constructeur de CComplexe par defaut
///@param RIEN
///@return RIEN
CComplexe::CComplexe() {
	dCOMpartieReelle = 0;
	dCOMpartieImaginaire = 0;
}

///@brief constructeur de CComplexe avec indication des parties reelles et imaginaires
///@param double dValeurReelle : valeur de la partie reelle
///@param double dValeurImaginaire : valeur de la partie imaginaire
///@return RIEN
CComplexe::CComplexe(double dValeurReelle, double dValeurImaginaire) {
	this->dCOMpartieImaginaire = dValeurImaginaire;
	this->dCOMpartieReelle = dValeurReelle;
}

///@brief constructeur de CComplexe avec indication de la partie reelle (la partie imaginaire est mise a 0)
///@param double dValeurReelle : valeur de la partie reelle
///@return RIEN
CComplexe::CComplexe(double dValeurReelle)
{
	this->dCOMpartieReelle = dValeurReelle;
	this->dCOMpartieImaginaire = 0;
}

///@brief constructeur de CComplexe de recopie
///@param CComplexe & COMcomplexe : CComplexe a recopier
///@return RIEN
CComplexe::CComplexe(CComplexe & COMComplexe)
{
	this->dCOMpartieImaginaire = COMComplexe.COMgetPartieImaginaire();
	this->dCOMpartieReelle = COMComplexe.COMgetPartieReelle();
}

///@brief getter de l'attribut dCOMpartieReelle
///@param RIEN
///@return dCOMpartieReelle : partie reelle du CComplexe actuel
double CComplexe::COMgetPartieReelle()
{
	return this->dCOMpartieReelle;
}

///@brief setter de l'attribut dPartieReelle
///@param double dPartieReelle : nouvelle valeur de la partie reelle
///@return RIEN
void CComplexe::COMsetPartieReelle(double dPartieReelle)
{
	this->dCOMpartieReelle = dPartieReelle;
}

///@brief getter de l'attribut dCOMpartieImaginaire
///@param RIEN
///@return this->dCOMpartieImaginaire : partie imaginaire du CComplexe actuel
double CComplexe::COMgetPartieImaginaire()
{
	return this->dCOMpartieImaginaire;
}

///@brief setter de l'attribut dCOMpartieImaginaire
///@param double dPartieImaginaire : nouvelle valeur de la partie imaginaire
///@return RIEN
void CComplexe::COMsetPartieImaginaire(double dPartieImaginaire)
{
	this->dCOMpartieImaginaire = dPartieImaginaire;
}

///@brief cette methode renvoie le conjugue du CComplexe actuel
///@param RIEN
///@return CComplexe COMresultat : conjugue du CComplexe actuel
CComplexe  CComplexe::COMconjugue() {
	CComplexe COMresultat;

	COMresultat.COMsetPartieImaginaire(-(this->COMgetPartieImaginaire()));
	COMresultat.COMsetPartieReelle(this->COMgetPartieReelle());

	return COMresultat;
}

//opérations complexe-complexe
<<<<<<< HEAD
CComplexe CComplexe::operator + (const CComplexe & COMc1)
=======
///@brief surcharge de l'operateur +, renvoie le resultat de l'addition entre deux CComplexes
///@param const CComplexe & COMc1 : CComplexe a additionnerau CComplexe actuel
///@return CComplexe COMresultat : resultat de l'addition
CComplexe CComplexe::operator + (CComplexe & COMc1)
>>>>>>> e6e09a12b05681b59c3f8dc5cd26f3a273fe4c86
{
	CComplexe COMresultat;

	COMresultat.dCOMpartieImaginaire = this->dCOMpartieImaginaire + COMc1.dCOMpartieImaginaire;
	COMresultat.dCOMpartieReelle = this->dCOMpartieReelle + COMc1.dCOMpartieReelle;

	return COMresultat;
}

<<<<<<< HEAD
CComplexe CComplexe::operator - (const CComplexe & COMc1)
=======
///@brief surcharge de l'operateur -, renvoie le resultat de la soustraction entre deux CComplexes
///@param const CComplexe & COMc1 : CComplexe a soustraire au CComplexe actuel
///@return CComplexe COMresultat : resultat de la soustraction
CComplexe CComplexe::operator - (CComplexe & COMc1)
>>>>>>> e6e09a12b05681b59c3f8dc5cd26f3a273fe4c86
{
	CComplexe COMresultat;

	COMresultat.COMsetPartieImaginaire(this->COMgetPartieImaginaire() - COMc1.dCOMpartieImaginaire);
	COMresultat.COMsetPartieReelle(this->COMgetPartieReelle() - COMc1.dCOMpartieReelle);

	return COMresultat;
}

///@brief surcharge de l'operateur *, renvoie le resultat de la multiplication entre deux CComplexes
///@param const CComplexe & COMc1
///@return CComplexe COMresultat : resultat de la multiplication
CComplexe CComplexe::operator * (const CComplexe & COMc1)
{
	CComplexe COMresultat;

	COMresultat.COMsetPartieReelle(this->COMgetPartieReelle()*COMc1.dCOMpartieReelle - this->COMgetPartieImaginaire()*COMc1.dCOMpartieImaginaire);
	COMresultat.COMsetPartieImaginaire(this->COMgetPartieReelle()*COMc1.dCOMpartieImaginaire + this->COMgetPartieImaginaire()*COMc1.dCOMpartieReelle);

	return COMresultat;
}

///@brief surcharge de l'operateur /, renvoie le resultat de la divison de deux CComplexes
///@param CComplexe & COMc1 : diviseur du CComplexe actuel
///@return CComplexe COMresultat : resultat de la division
CComplexe CComplexe::operator / (CComplexe & COMc1)
{
	CComplexe COMresultat;
	CComplexe COMnum(*this);
	CComplexe COMdeno(COMc1);
	double Ddeno;
	COMnum = COMnum * COMdeno.COMconjugue();
	COMdeno = COMdeno * COMdeno.COMconjugue();

	Ddeno = COMdeno.COMgetPartieReelle();

	COMresultat = COMnum / Ddeno;

	return COMresultat;
}

///@brief surcharge de l'operateur =
///@param const CComplexe &COMc1 : le CComplexe actuel prendra cette valeur
///@return RIEN
void CComplexe::operator = (const CComplexe &COMc1)
{
	
	this->dCOMpartieImaginaire = COMc1.dCOMpartieImaginaire;
	this->dCOMpartieReelle = COMc1.dCOMpartieReelle;

}

///@brief surcharge de l'operateur
///@param CComplexe &COMc1 : CComplexe avec lequel on compare le CComplexe actuel
///@return bool resultat : 1 si les CComplexes sont egaux, 0 sinon
bool CComplexe::operator == (CComplexe &COMc1)
{
	bool resultat = (this->dCOMpartieImaginaire == COMc1.dCOMpartieImaginaire && this->dCOMpartieReelle == COMc1.dCOMpartieReelle);
	return(resultat);
}

///@brief surcharge de l'operateur +, renvoie le resultat de l'addition d'un CComplexe et d'un double
///@param double dValeur : valeur reelle qu'on ajoute au CComplexe actuel
///@return CComplexe COMresultat : resultat de l'addition
CComplexe CComplexe::operator+(double dValeur)
{
	CComplexe COMresultat(dValeur,0);

	COMresultat.dCOMpartieImaginaire = this->COMgetPartieImaginaire();
	COMresultat.dCOMpartieReelle = COMresultat.dCOMpartieReelle + this->dCOMpartieReelle;

	return COMresultat;
}

///@brief surcharge de l'operateur -, renvoie le resultat de la soustraction entre un CComplexe et un double
///@param double dValeur : valeur reelle a soustraire au CComplexe actuel
///@return CComplexe COMresultat : resultat de la soustraction
CComplexe CComplexe::operator - (double dValeur)
{
	CComplexe COMresultat(0,0);

	COMresultat.dCOMpartieImaginaire = this->COMgetPartieImaginaire();
	COMresultat.dCOMpartieReelle = this->dCOMpartieReelle - dValeur;

	return COMresultat;
}

///@brief surcharge de l'operateur *, renvoie le resultat de la multiplication entre un CComplexe et un double
///@param double dValeur : valeur reelle par laquelle on multiplie le CComplexe actuiel
///@return CComplexe COMresultat : resultat de la multiplication
CComplexe CComplexe::operator * (double dValeur)
{
	CComplexe COMresultat(this->COMgetPartieReelle()*dValeur,this->COMgetPartieImaginaire()*dValeur);

	return COMresultat;
}

///@brief surcharge de l'operateur /, renvoie le resultat de la division d'un CComplexe par un double
///@param double dValeur : valeur reelle par laquelle on divise lle CComplexe
///@return CComplexe COMresultat : resultat de la division
CComplexe CComplexe::operator / (double dValeur)
{
	CComplexe COMresultat(this->COMgetPartieReelle()/dValeur, this->COMgetPartieImaginaire()/dValeur);

	return COMresultat;
}

///@brief surcharge de l'operateur =
///@param double dValeur : valeur reelle qu'on impose au CComplexe actuel (la partie imaginaire est mise a 0)
///@return RIEN
void CComplexe::operator = (double dValeur)
{
	this->dCOMpartieImaginaire = 0;
	this->dCOMpartieReelle = dValeur;
}

///@brief surcharge de l'operateur == 
///@param double dValeur : valeur reelle avec laquelle on compare le CComplexe actuel
///@return bool resultat : 1 si le CComplexe est egal a la valeur reelle, 0 sinon
bool CComplexe::operator == (double dValeur)
{
	bool resultat = (this->COMgetPartieImaginaire() == 0 && this->COMgetPartieReelle() == dValeur);
	return (resultat);
}

///@brief afficheur de CComplexe
///@param std::ostream & flux : flux de sortie correspondant a cout
///@return RIEN
void CComplexe::afficher(std::ostream & flux) const
{
	flux << dCOMpartieReelle;
	if (this->dCOMpartieImaginaire>=0) {
		cout << "+";
	}
	cout<<dCOMpartieImaginaire<<"i";
}

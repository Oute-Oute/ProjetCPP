///
/// @file CComplexe.h
/// @author NASSIRI Adam
/// @coauthor BLUMSTEIN Thomas
/// @date 2021-02-06
///

#include <iostream>
using namespace std;

///@brief la classe CComplexe sert a representer l'ensemble des nombres complexes en ecriture algebrique
class CComplexe {

private:
	//partie reelle du complexe
	double dCOMpartieReelle;

	//partie imaginaire du complexe
	double dCOMpartieImaginaire;

public:

	///@brief constructeur de CComplexe par defaut
	///@param RIEN
	///@return RIEN
	CComplexe();

	///@brief constructeur de CComplexe avec indication des parties reelles et imaginaires
	///@param double dValeurReelle : valeur de la partie reelle
	///@param double dValeurImaginaire : valeur de la partie imaginaire
	///@return RIEN
	CComplexe(double dValeurReelle, double dValeurImaginaire);

	///@brief constructeur de CComplexe avec indication de la partie reelle (la partie imaginaire est mise a 0)
	///@param double dValeurReelle : valeur de la partie reelle
	///@return RIEN
	CComplexe(double dValeurReelle);

	///@brief constructeur de CComplexe de recopie
	///@param CComplexe & COMcomplexe : CComplexe a recopier
	///@return RIEN
	CComplexe(CComplexe &COMComplexe);

	///@brief getter de l'attribut dCOMpartieReelle
	///@param RIEN
	///@return dCOMpartieReelle : partie reelle du CComplexe actuel
	double COMgetPartieReelle();

	///@brief setter de l'attribut dPartieReelle
	///@param double dPartieReelle : nouvelle valeur de la partie reelle
	///@return RIEN
	void COMsetPartieReelle(double dPartieReelle);

	///@brief getter de l'attribut dCOMpartieImaginaire
	///@param RIEN
	///@return this->dCOMpartieImaginaire : partie imaginaire du CComplexe actuel
	double COMgetPartieImaginaire();

	///@brief setter de l'attribut dCOMpartieImaginaire
	///@param double dPartieImaginaire : nouvelle valeur de la partie imaginaire
	///@return RIEN
	void COMsetPartieImaginaire(double dPartieImaginaire);

	///@brief cette methode renvoie le conjugue du CComplexe actuel
	///@param RIEN
	///@return CComplexe COMresultat : conjugue du CComplexe actuel
	CComplexe COMconjugue();

	//operations complexe-complexe
<<<<<<< HEAD
	CComplexe operator + (const CComplexe &COMc1);
	CComplexe operator - (const CComplexe &COMc1);
=======
	///@brief surcharge de l'operateur +, renvoie le resultat de l'addition entre deux CComplexes
	///@param const CComplexe & COMc1 : CComplexe a additionnerau CComplexe actuel
	///@return CComplexe COMresultat : resultat de l'addition
	CComplexe operator + (const CComplexe &COMc1);

	///@brief surcharge de l'operateur -, renvoie le resultat de la soustraction entre deux CComplexes
	///@param const CComplexe & COMc1 : CComplexe a soustraire au CComplexe actuel
	///@return CComplexe COMresultat : resultat de la soustraction
	CComplexe operator - (const CComplexe &COMc1);

	///@brief surcharge de l'operateur *, renvoie le resultat de la multiplication entre deux CComplexes
	///@param const CComplexe & COMc1
	///@return CComplexe COMresultat : resultat de la multiplication
>>>>>>> e6e09a12b05681b59c3f8dc5cd26f3a273fe4c86
	CComplexe operator * (const CComplexe &COMc1);

	///@brief surcharge de l'operateur /, renvoie le resultat de la divison de deux CComplexes
	///@param CComplexe & COMc1 : diviseur du CComplexe actuel
	///@return CComplexe COMresultat : resultat de la division
	CComplexe operator / (CComplexe &COMc1);

	///@brief surcharge de l'operateur =
	///@param const CComplexe &COMc1 : le CComplexe actuel prendra cette valeur
	///@return RIEN
	void operator = (const CComplexe &COMc1);

	///@brief surcharge de l'operateur
	///@param CComplexe &COMc1 : CComplexe avec lequel on compare le CComplexe actuel
	///@return bool resultat : 1 si les CComplexes sont egaux, 0 sinon
	bool operator == (CComplexe &COMc1);

	//operations complexe-reel

	///@brief surcharge de l'operateur +, renvoie le resultat de l'addition d'un CComplexe et d'un double
	///@param double dValeur : valeur reelle qu'on ajoute au CComplexe actuel
	///@return CComplexe COMresultat : resultat de l'addition
	CComplexe operator + (double dValeur);

	///@brief surcharge de l'operateur -, renvoie le resultat de la soustraction entre un CComplexe et un double
	///@param double dValeur : valeur reelle a soustraire au CComplexe actuel
	///@return CComplexe COMresultat : resultat de la soustraction
	CComplexe operator - (double dValeur);

	///@brief surcharge de l'operateur *, renvoie le resultat de la multiplication entre un CComplexe et un double
	///@param double dValeur : valeur reelle par laquelle on multiplie le CComplexe actuiel
	///@return CComplexe COMresultat : resultat de la multiplication
	CComplexe operator * (double dValeur);

	///@brief surcharge de l'operateur /, renvoie le resultat de la division d'un CComplexe par un double
	///@param double dValeur : valeur reelle par laquelle on divise lle CComplexe
	///@return CComplexe COMresultat : resultat de la division
	CComplexe operator / (double dValeur);

	///@brief surcharge de l'operateur =
	///@param double dValeur : valeur reelle qu'on impose au CComplexe actuel (la partie imaginaire est mise a 0)
	///@return RIEN
	void operator = (double dValeur);

	///@brief surcharge de l'operateur == 
	///@param double dValeur : valeur reelle avec laquelle on compare le CComplexe actuel
	///@return bool resultat : 1 si le CComplexe est egal a la valeur reelle, 0 sinon
	bool operator == (double dValeur);

	///@brief afficheur de CComplexe
	///@param std::ostream & flux : flux de sortie correspondant a cout
	///@return RIEN
	void afficher(ostream &flux) const;

};
// ProjetCPPMatrice.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

///
/// @file CComplexe.cpp
/// @author BLUMSTEIN Thomas
/// @coauthor NASSIRI Adam
/// @date 2021-05-06
///

#include "CMatrice.h"
#include "CLecture.h"
#include "CComplexe.h"
using namespace std;

///@brief surcharge de l'operateur <<, affiche un CComplexe dans la console
///@param ostream &flux : flux de sortie correspondant a cout
///@param CComplexe const& COMcomplexe : le CComplexe a afficher
///@return ostream & flux : flux de sortie correspondant a cout
ostream& operator<<(ostream &flux, CComplexe const& COMcomplexe)
{
	COMcomplexe.afficher(flux);
	return flux;
}

int main(int argc, char *argv[])
{
	cout << endl << "//////tests sur un complexe: z1//////" << endl << endl;
	CComplexe z1(1, 1);
	cout << "z1=" << z1 << endl;
	cout << "conjugue de z1=" << z1.COMconjugue() << endl;
	cout << "z1+5=" << z1+5 << endl;
	cout << "z1-5=" << z1-5 << endl;
	cout << "z1*5=" << z1 * 5 << endl;
	cout << "z1/2=" << z1 / 2 << endl;
	cout << "verification de l'operateur == (1 pour vrai 0 pour faux)" << endl;
	cout << "z1==1 donne: " << (z1 == 1) << endl;
	cout << "avant d'executer la suite ona fait z1=1" << endl;
	z1 = 1;
	cout << "z1= " << z1 << endl;
	cout << "z1==1 donne: " << (z1 == 1)  << endl;

	cout <<endl<< "//////tests sur deux complexes: z1 et z2//////" << endl <<endl;
	z1.COMsetPartieImaginaire(1);
	CComplexe z2(2, 2);
	cout << "z1=" << z1 <<endl;
	cout << "z2=" << z2 << endl;
	cout << "addition de z1 et z2" << endl;
	cout << "z1+z2=" << z2+z1 << endl;
	cout << "soustraction entre z1 et z2" << endl;
	cout << "z1-z2=" << z1 - z2 << endl;
	cout << "multiplication de z1 par z2" << endl;
	cout << "z1*z2=" << z1 *z2 << endl;
	cout << "division de z1 par z2" << endl;
	cout << "z1/z2=" << z1 / z2 << endl;
	cout << "verification de l'operateur == (1 pour vrai 0 pour faux)" << endl;
	cout << "z1==z1 donne: " << (z1 == z1) << endl;
	cout << "z1==z2 donne: " << (z1 == z2) << endl;
	cout << "avant d'executer ce qui suit, on a fait z2=z1"<<endl;
	z2 = z1;
	cout << "z1==z2 donne: " << (z1 == z2) << endl;
	cout << "z1=" << z1 << endl;
	cout << "z2=" << z2 << endl;

	/*
	unsigned int uiboucle;
	unsigned int uiboucle2;

	//Etape 1 : creations matrices
	CMatrice<double> *pMATtab = new CMatrice<double>[argc-1];
	for (uiboucle = 0; uiboucle < argc-1; uiboucle++)
	{
		CLecture LEClecture;
		LEClecture.LECSetNomFichier(argv[uiboucle+1]);
		LEClecture.LECLireFichier();
		unsigned int uinbLignes = LEClecture.LECGetNbLignes();

		unsigned int uinbColonnes = LEClecture.LECGetNbColonnes();

		double** pdtableau = new double*[3];

		for (uiboucle2 = 0; uiboucle2 < 3; uiboucle2++) {
			pdtableau[uiboucle2] = new double[3];
		}
		LEClecture.LECGetTabValeurs(pdtableau);

		char cnomType[100];

		LEClecture.LECGetnomType(cnomType);
		pMATtab[uiboucle].MATSetNbLigne(uinbLignes);
		pMATtab[uiboucle].MATSetNbColonne(uinbColonnes);
		pMATtab[uiboucle].MATSetNomType(cnomType);
		pMATtab[uiboucle].MATSetTabValeur(pdtableau);
	}

	//Etape 2 : entrée de l'opérateur
	double coperateur;
	cout << "Entrez une valeur pour c \nc= ";
	cin >> coperateur;
	
	CMatrice <double> CMATmatriceResultats; //matrices des résultats
	for (uiboucle = 0; uiboucle < argc - 1; uiboucle++) {
		//Etape 3 : multiplication des matrices par c
		cout << "Multiplication des matrices par c : \n";
		CMATmatriceResultats = pMATtab[uiboucle] * coperateur;
		CMATmatriceResultats.MATAfficherMatrice();
	}
	for (uiboucle = 0; uiboucle < argc - 1; uiboucle++) {
		//Etape 4 : Division des matrices par c
		cout << "Division des matrices par c : \n";
		CMATmatriceResultats = pMATtab[uiboucle] / coperateur;
		CMATmatriceResultats.MATAfficherMatrice();

	}

	CMATmatriceResultats = pMATtab[0];
	for (uiboucle = 0; uiboucle < argc - 2; uiboucle++) {
		//Etape 5 : addition des matrices entre elles
		cout << " addition des matrices entre elles : \n";
		CMATmatriceResultats = CMATmatriceResultats + pMATtab[uiboucle + 1];
		
	}
	CMATmatriceResultats.MATAfficherMatrice();

	CMATmatriceResultats = pMATtab[0];
	for (uiboucle = 0; uiboucle < argc - 2; uiboucle++) {
		//Etape 6 : résultat de M1-M2+M3-M4+M5-M6+...
		cout << " resultat de M1-M2+M3-M4+M5-M6+... : \n";
		if (uiboucle % 2 == 1) {
			CMATmatriceResultats = CMATmatriceResultats - pMATtab[uiboucle + 1];
		}
		else {
			CMATmatriceResultats = CMATmatriceResultats + pMATtab[uiboucle + 1];
		}
		
	}
	CMATmatriceResultats.MATAfficherMatrice();

	CMATmatriceResultats = pMATtab[0];
	for (uiboucle = 0; uiboucle < argc - 2; uiboucle++) {
		//Etape 7 : multiplication des matrices entres elles
		cout << " multiplication des matrices entres elles : \n";
		CMATmatriceResultats = CMATmatriceResultats * pMATtab[uiboucle + 1];

	}
	CMATmatriceResultats.MATAfficherMatrice();
	*/
	return 0;
}

// Exécuter le programme : Ctrl+F5 ou menu Déboguer > Exécuter sans débogage
// Déboguer le programme : F5 ou menu Déboguer > Démarrer le débogage

// Astuces pour bien démarrer : 
//   1. Utilisez la fenêtre Explorateur de solutions pour ajouter des fichiers et les gérer.
//   2. Utilisez la fenêtre Team Explorer pour vous connecter au contrôle de code source.
//   3. Utilisez la fenêtre Sortie pour voir la sortie de la génération et d'autres messages.
//   4. Utilisez la fenêtre Liste d'erreurs pour voir les erreurs.
//   5. Accédez à Projet > Ajouter un nouvel élément pour créer des fichiers de code, ou à Projet > Ajouter un élément existant pour ajouter des fichiers de code existants au projet.
//   6. Pour rouvrir ce projet plus tard, accédez à Fichier > Ouvrir > Projet et sélectionnez le fichier .sln.

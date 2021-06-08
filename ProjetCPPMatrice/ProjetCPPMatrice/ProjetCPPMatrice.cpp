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

int main()
{
	CComplexe z1(1, 1);
	CComplexe z2(2, 2);
	CComplexe z3(0, 0);
	try {
		cout << endl << "//////tests sur un complexe: z1//////" << endl << endl;

		cout << "z1=" << z1 << endl;
		cout << "conjugue de z1=" << z1.COMconjugue() << endl;
		cout << "z1+5=" << z1 + 5 << endl;
		cout << "z1-5=" << z1 - 5 << endl;
		cout << "z1*5=" << z1 * 5 << endl;
		cout << "z1/2=" << z1 / 5 << endl;
		cout << "verification de l'operateur == (1 pour vrai 0 pour faux)" << endl;
		cout << "z1==1 donne: " << (z1 == 1) << endl;
		cout << "avant d'executer la suite on a fait z1=1" << endl;
		z1 = 1;
		cout << "z1= " << z1 << endl;
		cout << "z1==1 donne: " << (z1 == 1) << endl;
		cout << "division par un reel nul (devrait lever une exception) :" << endl;
		cout << "z1/0=" << z1 / 0 << endl;
	}

	catch (CException *EXCexception) {
		EXCexception->EXCAfficherException();
	}

	try{
		cout << endl << "//////tests sur deux complexes: z1 et z2//////" << endl << endl;
		z1.COMsetPartieImaginaire(1);
		cout << "z1=" << z1 << endl;
		cout << "z2=" << z2 << endl << endl;
		cout << "addition :" << endl;
		cout << "z1+z2=" << z2 + z1 << endl << endl;
		cout << "soustraction :" << endl;
		cout << "z1-z2=" << z1 - z2 << endl;
		cout << "multiplication :" << endl;
		cout << "z1*z2=" << z2 * z1 << endl << endl;
		cout << "division :" << endl;
		cout << "z1/z2=" << z1 / z2 << endl;
		cout << "division par un complexe nul (devrait lever une exception) :" << endl;
		cout << "z1/(0+0i)=" << z1 / z3 << endl;
	}

	catch (CException *EXCexception) {
		EXCexception->EXCAfficherException();
	}

	
	unsigned int uiboucle;
	unsigned int uiboucle2;

	//Etape 1 : creations matrices
	CMatrice<CComplexe> *pMATtab = new CMatrice<CComplexe>[2];
	for (uiboucle = 0; uiboucle < 2; uiboucle++)
	{
		unsigned int uinbLignes = 2;

		unsigned int uinbColonnes = 2;

		CComplexe** pctableau = new CComplexe*[3];

		for (uiboucle2 = 0; uiboucle2 < 3; uiboucle2++) {
			pctableau[uiboucle2] = new CComplexe[3];
		}

		unsigned int uiboucleRemplissageLignes;
		unsigned int uiboucleRemplissageColonnes;

		for (uiboucleRemplissageLignes = 0; uiboucleRemplissageLignes < 2; uiboucleRemplissageLignes++) {
			for (uiboucleRemplissageColonnes = 0; uiboucleRemplissageColonnes < 2; uiboucleRemplissageColonnes++) {
				pctableau[uiboucleRemplissageLignes][uiboucleRemplissageColonnes].COMsetPartieReelle(uiboucleRemplissageLignes+ uiboucle);
				pctableau[uiboucleRemplissageLignes][uiboucleRemplissageColonnes].COMsetPartieImaginaire(uiboucleRemplissageColonnes+ uiboucle);
			}
		}

		char cnomType[100]="CComplexe";
		pMATtab[uiboucle].MATSetNbLigne(uinbLignes);
		pMATtab[uiboucle].MATSetNbColonne(uinbColonnes);
		pMATtab[uiboucle].MATSetNomType(cnomType);
		pMATtab[uiboucle].MATSetTabValeur(pctableau);
	}
	cout << "Matrice numero 1 :" << endl;
	pMATtab[0].MATAfficherMatrice();
	cout << "Matrice numero 2 :" << endl;
	pMATtab[1].MATAfficherMatrice();

	//Etape 2 : entrée de l'opérateur
	double coperateur;
	cout << "Entrez une valeur pour c \nc= ";
	cin >> coperateur;
	
	CMatrice <CComplexe> CMATmatriceResultats; //matrices des résultats
	for (uiboucle = 0; uiboucle < 2; uiboucle++) {
		//Etape 3 : multiplication des matrices par c
		cout << "Multiplication des matrices par c : \n";
		CMATmatriceResultats = pMATtab[uiboucle] * coperateur;
		CMATmatriceResultats.MATAfficherMatrice();
	}
	for (uiboucle = 0; uiboucle < 2; uiboucle++) {
		//Etape 4 : Division des matrices par c
		cout << "Division des matrices par c : \n";
		CMATmatriceResultats = pMATtab[uiboucle] / coperateur;
		CMATmatriceResultats.MATAfficherMatrice();

	}

	//addition entre elles
	CMATmatriceResultats = pMATtab[0];
	cout << " addition des matrices entres elles : \n";
	CMATmatriceResultats = CMATmatriceResultats + pMATtab[1];
	CMATmatriceResultats.MATAfficherMatrice();

	//multiplication entre elles
	CMATmatriceResultats = pMATtab[0];
	cout << " multiplication des matrices entres elles : \n";
	CMATmatriceResultats = CMATmatriceResultats * pMATtab[1];
	CMATmatriceResultats.MATAfficherMatrice();
	
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

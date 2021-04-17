// ProjetCPPMatrice.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include "CMatrice.h"
#include "CLecture.h"
using namespace std;

int main(int argc, char *argv[])
{
	unsigned int uiboucle;
	unsigned int uiboucle2;
	CLecture *pLECtab=new CLecture[argc];
	CMatrice<double> *pMATtab=new CMatrice<double>[argc];
	for (uiboucle = 0; uiboucle < argc; uiboucle++)
	{
		pLECtab[uiboucle].LECSetNomFichier(argv[uiboucle]);
		pLECtab[uiboucle].LECLireFichier();
		unsigned int uinbLignes = pLECtab[uiboucle].LECGetNbLignes();

		unsigned int uinbColonnes = pLECtab[uiboucle].LECGetNbColonnes();

		double** test = new double*[uinbLignes];

		for (uiboucle2 = 0; uiboucle2 < uinbLignes; uiboucle2++) {
			test[uiboucle2] = new double[uinbColonnes];
		}
		pLECtab[uiboucle].LECGetTabValeurs(test);
		char* test2 = new char[100];
		pLECtab[uiboucle].LECGetnomType(test2);
		pMATtab[uiboucle].MATSetNbLigne(uinbLignes);
		pMATtab[uiboucle].MATSetNbColonne(uinbColonnes);
		pMATtab[uiboucle].MATSetNomType(test2);
		pMATtab[uiboucle].MATSetTabValeur(test);
	}

	CMatrice <double> CMAT3;
	double multi = 23.0;
	CMAT3.MATCalculTransposee(pMATtab[0]);
	pMATtab[0].MATAfficherMatrice();
	pMATtab[1].MATAfficherMatrice();
	CMAT3.MATAfficherMatrice();


	//point 1

	//point 2
	/*
	cout << "entrez la valeur de C" << endl;
	cin >> C;
	*/

	//point 3

	//point 4

	//point 5

	//point 6

	//point 7
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

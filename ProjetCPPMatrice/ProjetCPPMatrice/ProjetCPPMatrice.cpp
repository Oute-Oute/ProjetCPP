// ProjetCPPMatrice.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include "COperationsMatrice.h"
#include "CLecture.h"
using namespace std;

int main(int argv, char** argc)
{

	CLecture CLEC((char*)"test.txt");

	unsigned int uinbLignes = CLEC.LECGetNbLignes();

	unsigned int uinbColonnes = CLEC.LECGetNbLignes();

	unsigned int uiboucle;

	double** test = new double*[uinbLignes];

	for (uiboucle = 0; uiboucle < uinbLignes; uiboucle++) {
		test[uiboucle] = new double[uinbColonnes];
	}
	CLEC.LECGetTabValeurs(test);
	char* test2 = new char[100];
	CLEC.LECGetnomType(test2);
	CMatrice <double> CMAT1(uinbLignes, uinbColonnes, test2, test);
	CMAT1.MATAfficherMatrice();


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

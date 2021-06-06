template<class nomType>
CMatrice<nomType>::CMatrice()
{
	uiMATnbColonnes = 0;
	uiMATnbLignes = 0;
	cMATnomType = nullptr;
	pMATtabValeurs = nullptr;
}

template<class nomType>
CMatrice<nomType>::CMatrice(int MATnbL, int MATnbC, char* MATnT, nomType** MATtV)
{
	uiMATnbLignes = MATnbL;
	uiMATnbColonnes = MATnbC;
	cMATnomType = MATnT;
	unsigned int uiboucleTab;
	unsigned int uiBoucleLignes;
	unsigned int uiBoucleColonnes;
	this->pMATtabValeurs = new nomType*[uiMATnbLignes];
	for (uiboucleTab = 0; uiboucleTab < uiMATnbLignes; uiboucleTab++) {
		this->pMATtabValeurs[uiboucleTab] = new nomType[uiMATnbColonnes];
	}
	for (uiBoucleLignes = 0; uiBoucleLignes < uiMATnbLignes; uiBoucleLignes++) {
		for (uiBoucleColonnes = 0; uiBoucleColonnes < uiMATnbColonnes; uiBoucleColonnes++) {

			this->pMATtabValeurs[uiBoucleLignes][uiBoucleColonnes] = MATtV[uiBoucleLignes][uiBoucleColonnes];
			//cout << this->pMATtabValeurs[uiBoucleLignes][uiBoucleColonnes];
		}
	}
}

template<class nomType>
CMatrice<nomType>::CMatrice(unsigned int MATnbL, unsigned int MATnbC, char* MATnT)
{
	uiMATnbLignes = MATnbL;
	uiMATnbColonnes = MATnbC;
	cMATnomType = MATnT;

	this->pMATtabValeurs = new nomType*[MATnbL];
	unsigned int uiboucle;

	for (uiboucle = 0; uiboucle < MATnbL; uiboucle++) {
		pMATtabValeurs[uiboucle] = new nomType[MATnbC];
	}

}

template<class nomType>
CMatrice<nomType>::CMatrice(CMatrice &MATM1)
{
	uiMATnbLignes = MATM1.MATGetNbLigne();
	uiMATnbColonnes = MATM1.MATGetNbColonne();
	cMATnomType = MATM1.MATGetNomType();
	this->pMATtabValeurs = new nomType*[uiMATnbLignes];
	unsigned int uiboucle;
	unsigned int uiboucleColonnes;
	for (uiboucle = 0; uiboucle < uiMATnbLignes; uiboucle++) {
		pMATtabValeurs[uiboucle] = new nomType[uiMATnbColonnes];
		for (uiboucleColonnes = 0; uiboucleColonnes < uiMATnbColonnes; uiboucleColonnes++) {
			pMATtabValeurs[uiboucle][uiboucleColonnes] = nomType(MATM1.pMATtabValeurs[uiboucle][uiboucleColonnes]);
		}
	}
}

template<class nomType>
CMatrice<nomType>::~CMatrice()
{
	uiMATnbColonnes = 0;
	uiMATnbLignes = 0;
}

template<class nomType>
int CMatrice<nomType>::MATGetNbLigne()
{
	return uiMATnbLignes;
}

template<class nomType>
int CMatrice<nomType>::MATGetNbColonne()
{
	return uiMATnbColonnes;
}

template<class nomType>
char * CMatrice<nomType>::MATGetNomType()
{
	return cMATnomType;
}

template<class nomType>
void CMatrice<nomType>::MATGetTabValeurs(nomType** MATtV)
{
	unsigned int uiboucleLignes;
	unsigned int uiboucleColonnes;
	for (uiboucleLignes = 0; uiboucleLignes < uiMATnbLignes; uiboucleLignes++) {
		for (uiboucleColonnes = 0; uiboucleColonnes < uiMATnbColonnes; uiboucleColonnes++) {

			MATtV[uiboucleLignes][uiboucleColonnes] = pMATtabValeurs[uiboucleLignes][uiboucleColonnes];
		}
	}
}

template<class nomType>
void CMatrice<nomType>::MATSetNbLigne(int MATnbL)
{
	uiMATnbLignes = MATnbL;
}

template<class nomType>
void CMatrice<nomType>::MATSetNbColonne(int MATnbC)
{
	uiMATnbColonnes = MATnbC;
}

template<class nomType>
void CMatrice<nomType>::MATSetNomType(char * MATnT)
{
	cMATnomType = MATnT;
}

template<class nomType>
void CMatrice<nomType>::MATSetTabValeur(nomType ** MATtV)
{
	this->pMATtabValeurs = new nomType*[uiMATnbLignes];
	unsigned int uiboucle;
	unsigned int uiboucleColonnes;
	for (uiboucle = 0; uiboucle < uiMATnbLignes; uiboucle++) {
		pMATtabValeurs[uiboucle] = new nomType[uiMATnbColonnes];
		for (uiboucleColonnes = 0; uiboucleColonnes < uiMATnbColonnes; uiboucleColonnes++) {
			pMATtabValeurs[uiboucle][uiboucleColonnes] = nomType(MATtV[uiboucle][uiboucleColonnes]);
		}
	}
	
}


template<class nomType>
inline void CMatrice<nomType>::MATAfficherMatrice()
{
	unsigned int uiboucleLignes;
	unsigned int uiboucleColonnes;
	for (uiboucleLignes = 0; uiboucleLignes < uiMATnbLignes; uiboucleLignes++)
	{
		for (uiboucleColonnes = 0; uiboucleColonnes < uiMATnbColonnes; uiboucleColonnes++)
		{
			cout << pMATtabValeurs[uiboucleLignes][uiboucleColonnes] << "  ";
		}

		cout << endl;
		cout << endl;
	}

}

template<class nomType>
inline CMatrice<nomType> CMatrice<nomType>::operator+(CMatrice<nomType>& MATm1)
{

	unsigned int uiNbColonnes = MATm1.MATGetNbColonne();
	unsigned int uiNbLignes = MATm1.MATGetNbLigne();

	CMatrice<nomType> MATMatriceResultat(uiNbLignes, uiNbColonnes, (char*)"double");

	
	CException *EXCexception = new CException();
	EXCexception->EXCSetOperation('+');

	try {
		//EXCEPTIONS
		if (uiNbColonnes !=this->uiMATnbColonnes || uiNbLignes != this->uiMATnbLignes) {
			EXCexception->EXCSetMessage((char*)"Dimensions incompatibles!");
			throw (EXCexception);
		}

		//TRAITEMENT OPERATION
		unsigned int uiboucleLignes;
		unsigned int uiboucleColonnes;
		for (uiboucleLignes = 0; uiboucleLignes < uiNbLignes; uiboucleLignes++) {
			for (uiboucleColonnes = 0; uiboucleColonnes < uiNbColonnes; uiboucleColonnes++) {

				MATMatriceResultat.pMATtabValeurs[uiboucleLignes][uiboucleColonnes] = pMATtabValeurs[uiboucleLignes][uiboucleColonnes] + MATm1.pMATtabValeurs[uiboucleLignes][uiboucleColonnes];

			}

		}

	}

	//LEVER LES EXCEPTIONS
	catch (CException *EXCexception) {
		EXCexception->EXCAfficherException();
	}

	return MATMatriceResultat;
}

template<class nomType>
inline CMatrice<nomType> CMatrice<nomType>::operator-(CMatrice<nomType>& MATm1)
{
	unsigned int uiNbColonnes = MATm1.MATGetNbColonne();
	unsigned int uiNbLignes = MATm1.MATGetNbLigne();

	CMatrice<nomType> MATMatriceResultat(uiNbLignes, uiNbColonnes, (char*)"double");

	//initialisation de l'objet exception
	CException *EXCexception = new CException();
	EXCexception->EXCSetOperation('-');

	try {
		//EXCEPTIONS
		if (uiNbColonnes != MATGetNbColonne() || uiNbLignes != MATGetNbLigne()) {
			EXCexception->EXCSetMessage((char*)"Dimensions incompatibles!");
			throw (EXCexception);
		}

		//TRAITEMENT
		unsigned int uiboucleLignes;
		unsigned int uiboucleColonnes;
		for (uiboucleLignes = 0; uiboucleLignes < uiNbLignes; uiboucleLignes++) {
			for (uiboucleColonnes = 0; uiboucleColonnes < uiNbColonnes; uiboucleColonnes++) {
				MATMatriceResultat.pMATtabValeurs[uiboucleLignes][uiboucleColonnes] = pMATtabValeurs[uiboucleLignes][uiboucleColonnes] - MATm1.pMATtabValeurs[uiboucleLignes][uiboucleColonnes];
			}

		}

	}


	//LEVER LES EXCEPTIONS
	catch (CException *EXCexception) {
		EXCexception->EXCAfficherException();
	}

	return MATMatriceResultat;
}

template<class nomType>
inline CMatrice<nomType> CMatrice<nomType>::operator*(CMatrice<nomType>& MATm1)
{
	unsigned int uiNbColonnes = MATGetNbColonne();
	unsigned int uiNbLignes = MATm1.MATGetNbLigne();
	char* sNomType = MATGetNomType();

	//initialisation de l'objet exception
	CException *EXCexception = new CException();
	EXCexception->EXCSetOperation('*');

	//INITIALISATION DE LA MATRICE RESULTAT EN MATRICE NULLE
	nomType** pitabVal = new nomType*[uiNbLignes];
	unsigned int uiboucle;

	for (uiboucle = 0; uiboucle < uiNbLignes; uiboucle++) {
		pitabVal[uiboucle] = new nomType[uiNbColonnes];
	}

	CMatrice<nomType> MATMatriceResultat(uiNbLignes, uiNbColonnes, sNomType);



	try {
		//EXCEPTIONS

			//dimensions incorrectes
		if (MATGetNbColonne() != MATm1.MATGetNbLigne()) {
			EXCexception->EXCSetMessage((char*)"Dimensions incompatibles!");
			throw (EXCexception);
		}

		//TRAITEMENT

		unsigned int uiboucleLignes;
		unsigned int uiboucleColonnes;
		unsigned int uiboucleElement;
		//Initilisation de la matrice résultat a 0
		for (uiboucleLignes = 0; uiboucleLignes < uiMATnbLignes; uiboucleLignes++)
		{
			for (uiboucleColonnes = 0; uiboucleColonnes < uiMATnbColonnes; uiboucleColonnes++)
			{
				MATMatriceResultat.pMATtabValeurs[uiboucleLignes][uiboucleColonnes] = 0;
			}
		}
		// Calcul
		for (uiboucleLignes = 0; uiboucleLignes < uiNbLignes; uiboucleLignes++) {
			for (uiboucleColonnes = 0; uiboucleColonnes < uiNbColonnes; uiboucleColonnes++) {
				for (uiboucleElement = 0; uiboucleElement < uiNbColonnes; uiboucleElement++) {
					MATMatriceResultat.pMATtabValeurs[uiboucleLignes][uiboucleColonnes] += pMATtabValeurs[uiboucleLignes][uiboucleElement] * MATm1.pMATtabValeurs[uiboucleElement][uiboucleColonnes];
				}

			}

		}

	}

	catch (CException *EXCexception) {
		EXCexception->EXCAfficherException();
	}

	return MATMatriceResultat;
}

template<class nomType>
inline CMatrice<nomType> CMatrice<nomType>::operator*(double & dElem)
{
	unsigned int uinbColonnes = MATGetNbColonne();
	unsigned int uinbLignes = MATGetNbLigne();
	unsigned int uiLigne;
	unsigned int uiColonne;
	CMatrice<nomType> MATMatriceResultat(uiMATnbLignes, uinbColonnes, (char*)"double");

	for (uiLigne = 0; uiLigne < uinbLignes; uiLigne++) {
		for (uiColonne = 0; uiColonne < uinbColonnes; uiColonne++) {

			MATMatriceResultat.pMATtabValeurs[uiLigne][uiColonne] = pMATtabValeurs[uiLigne][uiColonne] * dElem;

		}

	}

	return MATMatriceResultat;
}

template<class nomType>
inline CMatrice<nomType> CMatrice<nomType>::operator/(double & dElem)
{
	unsigned int uiNbColonnes = MATGetNbColonne();
	unsigned int uiNbLignes = MATGetNbLigne();

	CMatrice<nomType> MATMatriceResultat(uiNbLignes, uiNbColonnes, (char*)"double");


	//initialisation de l'objet exception
	CException *EXCexception = new CException();
	EXCexception->EXCSetOperation('/');

	try {
		//EXCEPTIONS
			//division par 0
		if (dElem == 0) {
			EXCexception->EXCSetMessage((char*)"Division par 0!");
			throw (EXCexception);
		}

		//TRAITEMENT
		unsigned int uiLigne;
		unsigned int uiColonne;
		for (uiLigne = 0; uiLigne < uiNbLignes; uiLigne++) {
			for (uiColonne = 0; uiColonne < uiNbColonnes; uiColonne++) {

				MATMatriceResultat.pMATtabValeurs[uiLigne][uiColonne] = pMATtabValeurs[uiLigne][uiColonne] / dElem;

			}

		}

	}

	catch (CException *EXCexception) {
		EXCexception->EXCAfficherException();
	}

	return MATMatriceResultat;
}



template<class nomType>
void CMatrice<nomType>::MATCalculTransposee(CMatrice<nomType> MATm1)
{
	uiMATnbColonnes = MATm1.uiMATnbLignes;
	uiMATnbLignes = MATm1.uiMATnbColonnes;

	pMATtabValeurs = new nomType*[uiMATnbLignes];
	unsigned int uiboucle;

	for (uiboucle = 0; uiboucle < uiMATnbLignes; uiboucle++) {
		pMATtabValeurs[uiboucle] = new nomType[uiMATnbColonnes];
	}
	//CMatrice<nomType> MATMatriceResultat(uiNbLignes, uiNbColonnes, (char*)"double");


		//TRAITEMENT
	unsigned int uiboucleLignes;
	unsigned int uiboucleColonnes;
	//Initilisation de la matrice courante a 0
	for (uiboucleLignes = 0; uiboucleLignes < uiMATnbLignes; uiboucleLignes++)
	{
		for (uiboucleColonnes = 0; uiboucleColonnes < uiMATnbColonnes; uiboucleColonnes++)
		{
			pMATtabValeurs[uiboucleLignes][uiboucleColonnes] = 0;
		}
	}

	//calcul transposée
	for (uiboucleLignes = 0; uiboucleLignes < uiMATnbLignes; uiboucleLignes++) {
		for (uiboucleColonnes = 0; uiboucleColonnes < uiMATnbColonnes; uiboucleColonnes++) {

			pMATtabValeurs[uiboucleLignes][uiboucleColonnes] = MATm1.pMATtabValeurs[uiboucleColonnes][uiboucleLignes];

		}

	}




	//return MATMatriceResultat;
}

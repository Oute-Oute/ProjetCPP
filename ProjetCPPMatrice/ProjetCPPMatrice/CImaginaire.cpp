///
/// @file CImaginaire.cpp
/// @author NASSIRI Adam
/// @coauthor BLUMSTEIN Thomas
/// @date 2021-02-06
///

#include "CImaginaire.h"

CImaginaire::CImaginaire() {

}

CImaginaire::CImaginaire(CImaginaire &IMAimaginaire) {
	this->fIMAvaleur = IMAimaginaire.valeur
}

CImaginaire::CImaginaire(float fValeur) {
	this->fIMAvaleur = fValeur;
}

CImaginaire::~CImaginaire() {

}

float CImaginaire::IMAgetValeur() {
	return this->fIMAvaleur;
}

void CImaginaire::IMAsetValeur(float fValeur) {
	this->fIMAvaleur = fValeur;
}

void CImaginaire::IMAafficher() {
	 std::cout<< this->fIMAvaleur << "i" <<std::endl
}
/*
* Titre : clientRegulier.cpp - Travail Pratique #4
* Date :  mars 2019
* Auteur : Louis Roberge  && Jean-Sébastien Patenaude
*/
#include "ClientRegulier.h"

ClientRegulier::ClientRegulier()
{	nbPoints_ = 0;}

ClientRegulier::ClientRegulier(string_view nom, string_view prenom, int tailleGroupe, int npoints) 
	: Client(nom, prenom, tailleGroupe), nbPoints_(npoints){
}

ClientRegulier::~ClientRegulier() {}

int ClientRegulier::getNbPoints() const
{	return nbPoints_;}


void ClientRegulier::augmenterNbPoints(int bonus)
{	nbPoints_ += bonus;}


void ClientRegulier::afficherClient(ostream & os) const
{	static_cast<Client>(*this).afficherClient(os);}

double ClientRegulier::getReduction(const Restaurant & res, double montant, bool estLivraison){
	double reduction = 0.0;
	if (nbPoints_ > SEUIL_DEBUT_REDUCTION) {
		reduction = (-montant * TAUX_REDUC_REGULIER);
	}
	return reduction;
}

/*
* Date : 25 f�vrier 2019
* Auteur : AbdeB
*/
#ifndef CLIENT_PRESTIGE
#define CLIENT_PRESTIGE

#include "ClientRegulier.h"

#include "def.h"
class ClientPrestige : public ClientRegulier
{
public:
	ClientPrestige();
	ClientPrestige(string_view nom, string_view prenom, int tailleGroupe, int nbPoints, ZoneHabitation adresse); // TODO fait
    ~ClientPrestige(){};
	//Accesseur 
	ZoneHabitation getAdresseCode() const;

	//Autres Fonctions
    void afficherClient(ostream & os) const; // TODO fait
	string getAdressCodeString() const;
    double getReduction(const Restaurant & res, double montant, bool estLivraison); // TODO fait

private:
	ZoneHabitation adresse_;
};

#endif


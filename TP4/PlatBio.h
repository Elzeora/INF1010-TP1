/*
* Titre : plat.h - Travail Pratique #4
* Date :  mars 2019
* Auteur : Louis Roberge  && Jean-Sébastien Patenaude
*/
#ifndef PLAT_BIO_H
#define PLAT_BIO_H

#include <string>
#include <iostream>
#include "Plat.h"

using namespace std;

class PlatBio: public Plat {
public:
	// constructeurs
    PlatBio(string nom = "inconnu", double prix = 0, double cout = 0, double ecotaxe = 0); // TODO
    ~ PlatBio(); // TODO fait
	//getters 
	double getEcoTaxe() const;
	//setters 
	void setEcoTaxe(double ecoTaxe);
    virtual void afficherPlat(ostream& os) const;  // TODO fait
    double getPrixDeRevient();  // TODO fait
    virtual Plat * clone() const;  // TODO fait
protected:
	double ecoTaxe_;
};

#endif // !PLAT_VERT_H

/*
* Titre : Menu.h - Travail Pratique #2
* Date : 18 Janvier 2019
* Auteur : Allan BEDDOUK
*/

#ifndef MENU_H
#define MENU_H

#include "Plat.h"
#include <fstream>
#include <vector>

enum TypeMenu{Matin, Midi, Soir};
const int MAXPLAT = 5;
class Menu {
public:
	// constructeurs
	Menu();
	Menu(string fichier, TypeMenu type);

	//destructeur
	~Menu();

	//getters
	int getNbPlats() const;

	//affichage
	//void afficher() const; //A MODIFIER

	//methodes en plus
	Plat* trouverPlat(const string& nom) const; // A MODIFIER
	Plat * trouverPlatMoinsCher() const; // Utilise les vecteurs (NE PAS MODIFIER)
	//void ajouterPlat(Plat& plat); // A MODIFIER
	bool lireMenu(const string& fichier);

	//void afficher() const; //A MODIFIER
	friend ostream& operator<<(ostream& os, const Menu& menu);

	//operateur=
	Menu& operator=(Menu& menu);

	//operateur+=
	Menu& operator+=(Plat* plat);

	//nouvel attribut
	vector<Plat*> getListePlats() const;

private :
	// A MODIFIER
	//int capacite_;
	//Plat** listePlats_;
	vector<Plat*> listePlats_;
	int nbPlats_;
	TypeMenu type_;

};

#endif // !MENU_H
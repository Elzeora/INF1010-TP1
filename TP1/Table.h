/*
* Titre : Table.h - Travail Pratique #1
* Date : 09 Janvier 2019
* Auteur : David Dratwa
*/

#ifndef TABLE_H
#define TABLE_H

#include "Menu.h"
const  int MAXCAP = 5;
class Table {
public:
	//constructeurs 
	Table();
	Table(const int& id, const int& nbPlaces);

	//desructeur
	~Table();

	//getters 
	int getId()const;
	int getNbPlaces()const;
	bool estOccupee()const;

	//setters 
	void libererTable();
	void placerClient();
	void setId(const int& id);

	//autres methodes 
	void commander(Plat* plat);
	double getChiffreAffaire()const;

	//affichage
	void afficher()const;
private:
	Plat** commande_;
	int capacite_;
	int nbPlats_;

	int id_;
	int nbPlaces_;
	bool occupee_;
};
#endif // !TABLE_H

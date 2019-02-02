/****************************************************************************
 * Fichier: Table.cpp
 * Auteur: Louis Roberge
 * Date: 24 Janvier 2019
 * Description: Implémentation de la classe Table
 ****************************************************************************/
#include "Table.h"
#include <iostream>
#include <string>
using namespace std;


/****************************************************************************
 * Fonction: Table :: Table
 * Description: Constructeur par défaut
 * Paramètres: aucun
 * Retour: aucun
 ****************************************************************************/
Table::Table() {
	capacite_ = MAXCAP;
	id_ = -1;
	nbPlaces_ = 1;
	occupee_ = false;
	Plat** commande_ = new Plat*[capacite_];
}
/****************************************************************************
 * Fonction: Table::Table
 * Description: Constructeur par paramètres
 * Paramètres: - int id : valeur de id_ (IN)
 *             - int nbPlaces : valeur de nbPlaces_ (IN)
 * Retour: aucun
 ****************************************************************************/
Table::Table(int id, int nbPlaces) {
	id_ = id;
	nbPlaces_ = nbPlaces;
	nbPlats_ = 0;
	capacite_ = MAXCAP;
	commande_ = new Plat*[MAXPLAT];
	occupee_ = false;

}
/****************************************************************************
 * Fonction: Table::getid
 * Description: Retourne id_
 * Paramètres: aucun
 * Retour: (int) la valeur de id_
 ****************************************************************************/
int Table::getId() const {
	return id_;
}
/****************************************************************************
 * Fonction: Table::getNbPlaces
 * Description: Retourne nbPlaces_
 * Paramètres: aucun
 * Retour: (int) la valeur de nbPlaces_
 ****************************************************************************/
int Table::getNbPlaces() const {
	return nbPlaces_;
}
/****************************************************************************
 * Fonction: Table::estOccupee
 * Description: Retourne occupee_
 * Paramètres: aucun
 * Retour: (bool) la valeur de occupee_
 ****************************************************************************/
bool Table::estOccupee() const {
	return occupee_;
}
/****************************************************************************
 * Fonction: Table::libererTable
 * Description: libere la table donc la table n'est plus occupee
 * Paramètres: aucun
 * Retour:  aucun
 ****************************************************************************/
void Table::libererTable() {
	occupee_ = false;
}
/****************************************************************************
 * Fonction: Table::placerCilent
 * Description: place des clients donc la table est occupee
 * Paramètres: aucun
 * Retour:  aucun
 ****************************************************************************/
void Table::placerClient() {
	occupee_ = true;
}
/****************************************************************************
 * Fonction: Table::setId
 * Description: attribue un id a une table selon l'id donnee
 * Paramètres: - int id : valeur de id_ (IN)
 * Retour:  aucun
 ****************************************************************************/
void Table::setId(int id) {
	id_ = id;
}
/****************************************************************************
 * Fonction: Table::commander
 * Description: ajoute un Plat a un tableau de plat
 * Paramètres: -Plat plat : valeur du Plat (IN)
 * Retour:  aucun
 ****************************************************************************/
void Table::commander(Plat* pla) {

	if (nbPlats_ >= capacite_) {
		capacite_ *= 2;
		Plat **platTemp = new Plat*[capacite_];

		for (int i = 0; i < nbPlats_; i++) {
			platTemp[i] = commande_[i];
		}
		for (int i = 0; i < nbPlats_; i++) {
			delete platTemp[i];
		}
		delete[] commande_;
		commande_ = platTemp;
	}
	commande_[nbPlats_] = pla;
	nbPlats_++;
}
/****************************************************************************
 * Fonction: Table:: getChiffreAffaire
 * Description: retourne le chiffre d'affaire de la table
 * Paramètres: aucun
 * Retour:  Double gain : le chiffre d'affaire de la table
 ****************************************************************************/
double Table::getChiffreAffaire()const{
	double gain = 0;
	for (int i = 0; i < nbPlats_; i++) {
		gain += commande_[i]->getPrix() - commande_[i]->getCout();
	}
	return gain;
}
/****************************************************************************
 * Fonction: Table:: getChiffreAffaire
 * Description: retourne le chiffre d'affaire de la table
 * Paramètres: aucun
 * Retour:  Double gain : le chiffre d'affaire de la table
 ****************************************************************************/
void Table::afficher() const {

	cout << "        la table numero " << id_;
	if (occupee_) {
		cout << " est occupee ";
		if (nbPlats_ == 0) {
			cout << " Mais ils n'ont rien commande pour l'instant." << endl;
		}
		else {
			cout << " Voici la commande passee par les clients : " << endl;
			for (int i = 1; i <= nbPlats_; i++) {
				commande_[i - 1]->afficher();
			}

		}
	}
	else {
		cout << " est libre.";
	}
	cout << endl;
	cout << endl;
}









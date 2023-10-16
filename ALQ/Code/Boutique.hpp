#ifndef BOUTIQUE_GUARD
#define BOUTIQUE_GUARD

#include <iostream>
#include "Zone.hpp"
#include "Position.hpp"

using std::string;

/**
 * @brief Classe représentant une Boutique, qui est une classe fille de Zone
 * 
 * Ceci représente une boutique dans l'aéroport.
 * 
 */
class Boutique : public Zone
{
    int nombrePersonneMax; ///<Le nombre de personnes max dans la boutique
    string nomBoutique; ///<Le nom de la boutique
    int nombrePersonneActuel; ///<Le nombre de personnes actuelles dans la boutique
    
public:
    /**
     * @brief Retourne le nombre personnes max dans la boutique
     * 
     * @return le nombre max de personne dans la boutique
     */
    int getNbPersonneMax();
    
    /**
     * @brief Retourne le nombre de personnes actuelles dans la boutique
     * 
     * @return le nombre de personnes actuelles dans la boutique
     */
    int getNbPersonneActuelle();

    /**
     * @brief Retourne le nom de la boutique
     * 
     * @return le nom de la boutique
     */
    string getnomBoutique();

    /**
     * @brief Constructeur d'une boutique avec des paramètres données.
     * 
     * @param nbPersonne Le nombre max de personnes dans la boutique
     * @param nom Le nom de la boutique
     * @param p La position de la boutique
     */
    Boutique(int nbPersonne, string nom,Position p);

    /**
     * @brief Constructeur par défaut d'une boutique
     * 
     */
    Boutique();
};

#endif
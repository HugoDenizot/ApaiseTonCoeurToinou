#ifndef ZONEEMBARQUEMENT_GUARD
#define ZONEEMBARQUEMENT_GUARD
#include <iostream>
#include "Zone.hpp"
#include "Position.hpp"

using std::string;

/**
 * @brief Classe représentant une zone d'embarquement.
 * 
 * Cette classe permet de représenter une zone d'embarquement de l'aéroport.
 * 
 */
class ZoneEmbarquement : public Zone{
    int nombrePersonneMax; ///<Nombre max de personnes dans la zone d'embarquement
    int nombrePersonneActuelle; ///<Nombre de personnes acutelles dans la zone d'embarquement
    string nomZoneEmbarquement; ///< Nom de la zone d'embarquement.

    public:
        /**
         * @brief Retourne le nombre de personnes max dans la zone d'embarquement.
         * 
         * @return le nombre de personnes max. 
         */
        int getNombrePersonneMax();

        /**
         * @brief Retourne le nombre de personnes actuelles dans la zone d'embarquement.
         * 
         * @return le nombre de personnes actuelles. 
         */
        int getNbPersonneActuelle();

        /**
         * @brief Retourne le nom de la zone d'embarquement.
         * 
         * @return Le nom de la zone d'embarquement. 
         */
        string getnomZoneEmarquement();

        /**
         * @brief Constructeur d'une zone d'embarquement avec des valeurs précises.
         * 
         * @param nombrePersonne Le nombre de personnes max dans la zone.
         * @param nom Le nom de la zone.
         * @param p La position de la zone.
         */
        ZoneEmbarquement(int nombrePersonne, string nom,Position p);

        /**
         * @brief Constructeur par défaut d'une zone d'embarquement.
         * 
         */
        ZoneEmbarquement();
};

#endif
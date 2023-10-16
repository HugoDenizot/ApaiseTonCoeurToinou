#ifndef _MAP
#define _MAP

#include "Personne.hpp"
#include "Zone.hpp"
#include "Visiteur.hpp"

/**
 * @brief Classe qui représente la map.
 * 
 * Cette classe représente la map. Celle ci ne sera instancié qu'une seule
 * fois durant le programme
 * 
 */
class Map
{
    public :
    int nbpersonne; ///<Le nombre de personnes sur la map
    int nbzonne;    ///<Le nombre de zones dans la map
    int grille[20][20]; ///<La grille représentant la map
    Personne *tabpers[25]; ///<Tableau des personnes sur la map
    Zone *tabZone[25]; ///<Tableau des zones sur la map

    public:
        /**
         * @brief Constructeur par défaut d'une map.
         * 
         */
        Map();

        /**
         * @brief Méthode permettant d'afficher la map.
         * 
         */
        void AfficherMap();

        /**
         * @brief Cette méthode permet de savoir l'élément à une position donnée.
         * 
         * @param j La valeur de la ligne.
         * @param i La valeur de la colonne.
         * @return La valeur de l'élément à la position donnée.
         */
        int OnthisCase(int j,int i);

        /**
         * @brief 
         * 
         * @param p La personne à ajouter.
         * @return true S'il n'y a personne à cette position.
         * @return false S'il y a quelqu'un à cette position.
         */
        bool ajouterPers(Personne * p);

        /**
         * @brief Permet de supprimer une personne de la map
         * 
         * @param p La personne à supprimer de la map.
         */
        void deletePers(Personne *p);
};

#endif
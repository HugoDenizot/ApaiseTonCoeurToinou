#ifndef DOU_GUARD
#define DOU_GUARD

#include "Personne.hpp"
#include "Position.hpp"
#include "Map.hpp"
#include "Random_MT.hpp"
#include "Visiteur.hpp"

/**
 * @brief Classe représentant un douanier.
 *
 * Cette classe permet de représenter un douanier de l'aéroport. 
 * 
 */
class Douanier : public Personne
{
        bool enControle = false; ///<Cet attribut permet de savoir si le douanier en en controle ou non.
        Visiteur * personneControle = nullptr; ///< Cet attribut correspond à la personne contrôlée.
        int dureeControleActu = 0; ///<Permet de savoir la durée du contrôle actuel
        Visiteur * dejaControlle[50]; ///<Permet de savoir si un visiteur à déjà été contrôllé ou non.
        int nbPersonneControlle = 0; ///<Nombre de personne controllée.

public:
        /**
         * @brief Constructeur par défaut d'un douanier.
         * 
         * Permet de créer un douanier avec des valeurs par défaut.
         * 
         */
        Douanier();

        /**
         * @brief Constructeur d'un douanier en précisant le nom et le prénom de celui-ci.
         * 
         * @param nom Nom du douanier
         * @param prenom Prenom du douanier
         */
        Douanier(std::string nom, std::string prenom);

        /**
         * @brief Constructeur d'un douanier à une position donnée.
         * 
         * @param p La position où créer le douanier.
         */
        Douanier(Position p);

        /**
         * @brief Destructeur de douanier.
         * 
         * Permet de détruire et de libérer les tableaux du douanier.
         */
        ~Douanier();

        /**
         * @brief Permet au douanier de réaliser une action chaque tour de simulation.
         * 
         * @return Retourne forcément 0. 
         */
        int Action();
        

private:

        /**
         * @brief Permet d'obtenir le nombre de voisins et leur positions dans le tableau passé en paramètre.
         * 
         */
        void getVoisin(int &, Position[]);

        /**
         * @brief Retourne si le douanier est actuellement en contrôle ou non. 
         * 
         * @return true Si le douanier est en contrôle.
         * @return false Si le douanier n'est pas en contrôle.
         */
        bool getEnControle();

        /**
         * @brief Permet de modifier la valeur du contrôle du Douanier.
         * 
         * @param valControle la valeur du booleen a assigné.
         */
        void setEnControle(bool valControle);

        /**
         * @brief Permet déplacer aléatoirement le douanier dans une des 8 cases autour de lui.
         * 
         */
        void DeplacementAleatoire();

        /**
         * @brief Retourne la personne de la map à une position donnée.
         * 
         * @param p La position de la personne souhaité.
         * @return La personne à la position donnée ou null s'il y a personne.
         */
        Personne *  getVisiteurWithPos(Position p);
        bool checkAlreadyControle(Visiteur *);
};

// Probabilité fin de controle en fonction du temps

const double probaControle[8] = {0.2, 0.3, 0.5, 1}; ///<Ce tableau contient les probabilités d'un temps de contrôle du douanier.

//la map
extern Map m;
#endif
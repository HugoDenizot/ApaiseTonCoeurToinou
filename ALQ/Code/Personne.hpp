#ifndef PERS_GUARD
#define PERS_GUARD

#include "Position.hpp"
class Map;

/**
 * @brief Classe représentant une personne dans l'aéroport.
 * 
 * Cette classe représente n'importe quelle personne de l'aéroport.
 * 
 */
class Personne {

    std::string nom; ///<Le nom de la personne
    std::string prenom; ///<Le prénom de la personne
    int id; ///< L'id de la personne
    Position pos; ///<La position de la personne

    public:
        /**
         * @brief Constructeur de personne avec un nom et un prénom.
         * 
         * @param name nom de la personne.
         * @param prename prénom de la personne.
         */
        Personne(std::string name,std::string prename);

        /**
         * @brief Constructeur de personne à une position donnée
         * 
         * @param p La position où construire la personne.
         */
        Personne(Position p);

        /**
         * @brief Constructeur par défaut d'une personne.
         * 
         * Permet de créer une personne avec des données par défaut.
         */
        Personne();

        /**
         * @brief Retourne le nom de la personne.
         * 
         * @return Le nom de la personne. 
         */
        std::string getnom();

        /**
         * @brief Retourne le prénom de la personne.
         * 
         * @return Le prénom de la personne. 
         */
        std::string getprenom();

        /**
         * @brief Retourne l'id de la personne.
         * 
         * @return l'id de la personne.
         */
        int getid();

        /**
         * @brief Retourne la position de la personne.
         * 
         * @return La position de la personne. 
         */
        Position getPos();

        /**
         * @brief Méthode commune aux classes filles de Personne. Pour Personne ne
         * fait rien et retourne 0.
         * 
         * @return 0
         */
        virtual int Action() {return 0;};

        /**
         * @brief Destructeur de Personne. Ne fait rien de spécial mais nécessaire pour permettre l'héritage.
         * 
         */
        virtual ~Personne();

        /**
         * @brief Permet de déplacer une personne à une position donnée si cette dernière n'est pas déjà occupée.
         * 
         * @param p1 La position souhaité.
         * @return true Si la personne s'est déplacé.
         * @return false Si la personne ne s'est pas déplacé.
         */
        bool deplacerPersonne(Position p1);
    
    private:

        /**
         * @brief Modifie le nom d'une personne
         * 
         * @param n Nouveau nom souhaité pour la personne. 
         */
        void setNom(std::string n);

        /**
         * @brief Modifie le prénom d'une personne.
         * 
         * @param p Nouveau prénom de la personne.
         */
        void setPrenom(std::string p);

        /**
         * @brief Modifie la position d'une personne.
         * 
         * @param p Nouvelle position de la personne.
         */
        void setPos(Position p);

};

#endif
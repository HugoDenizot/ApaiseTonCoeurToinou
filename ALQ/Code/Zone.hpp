#ifndef _ZONE
#define _ZONE   

#include "Position.hpp"

/**
 * @brief Classe représentant une zone de l'aéroport.
 * 
 * Cette classe permet de représenter une zone de l'aéroport en général
 * 
 */
class Zone
{
    public:
        Position pos; ///<Position de la zone sur la map

    public:
        /**
         * @brief Retourne la position d'une zone.
         * 
         * @return La position de la zone.
         */
        Position getPos();

        /**
         * @brief Permet de changer la position d'une zone.
         * 
         * @param p La nouvelle position de la zone.
         */
        void setPos(Position p);

        /**
         * @brief Destructeur de base d'une zone.
         * 
         * Cette méthode est nécessaire notamment pour créer une des classes filles.
         * 
         */
        virtual ~Zone();
};

#endif
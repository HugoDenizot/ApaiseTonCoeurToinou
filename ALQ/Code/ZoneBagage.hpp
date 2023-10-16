#ifndef _ZONEBAGAGE
#define _ZONEBAGAGE

#include "Zone.hpp"
#include "Position.hpp"

/**
 * @brief Classe représentant une zone de bagages de l'aéroport.
 * 
 * Cette classe permet de représenter une Zone précise qui est une zone de bagages.
 * 
 */
class ZoneBagage : public Zone 
{

public:
    /**
     * @brief Constructeur par défaut d'une zone de bagage.
     * 
     */
    ZoneBagage();

    /**
     * @brief Constructeur d'une zone à une position donnée.
     * 
     * @param p La posiition de la zone de bagages.
     */
    ZoneBagage(Position p);
};

#endif
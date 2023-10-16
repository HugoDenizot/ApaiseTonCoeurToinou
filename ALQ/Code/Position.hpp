#ifndef POS_GUARD
#define POS_GUARD

/**
 * @brief Classe qui représente une position.
 * 
 * Cette classe permet de représenter une position en 2 dimensions.
 * 
 */
class Position
{

    int x; ///<Position x
    int y; ///<Position y

public:
    /**
     * @brief Récupère la valeur de la position X
     * 
     * @return La position X 
     */
    int getX();

    /**
     * @brief Récupère la valeur de la position Y
     * 
     * @return la position Y 
     */
    int getY();

    /**
     * @brief Modifie la valeur de la position X
     * 
     * @param posX Nouvelle valeur de la position X.
     */
    void setX(int posX);

    /**
     * @brief Modifie la valeur de la position y.
     * 
     * @param posY Nouvelle valeur de la position Y.
     */
    void setY(int posY);

    /**
     * @brief Constructeur d'une position à l'aide de deux valeurs
     * 
     * @param x La valeur X que l'on veut attribuer.
     * @param y La valeur Y que l'on veut attribuer.
     */
    Position(int x, int y);

    /**
     * @brief Constructeur par défaut d'une position qui positionne en 0,0
     * 
     */
    Position();
};

#endif
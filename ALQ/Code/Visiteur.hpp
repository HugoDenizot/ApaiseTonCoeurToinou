#ifndef VIS_GUARD
#define VIS_GUARD

#include "Personne.hpp"
#include "Random_MT.hpp"
#include "Boutique.hpp"
#include "ZoneBagage.hpp"

class Map;

/**
 * @brief Classe représentant un visiteur de l'aéroport.
 *
 *
 */
class Visiteur : public Personne
{

    int nbBagage; ///<Le nombre de bagages du visiteur
    int budget; ///< Le budget du visiteur
    int tempsAvantVol; ///<Le temps restant avant vol
    bool aDeposeBagages = false; ///< Un booléen permettant de savoir si il a déposé ses bagages ou non.
    Position posBoutiqueVoulu{-1, -1}; ///<Donne la position de sa boutique souhaitée.
    Position posBagagesVoulu{-1, -1}; ///<Donne la position de sa zone de bagages souhaitée
    Position posZEVoulu{-1, -1}; ///<Donne Donne la position de la Zone d'embarquement voulue.
    bool estControlle = false; ///<Booleen permettant de savoir si le visiteur est en train d'être controllé ou non.
    bool arrive = false; ///< Booleen permettant de savoir si le visiteur est arrivé ou non.

public:
    bool btk = false;
    bool gobtk = false;

public:
    /**
     * @brief Retourne le nombre de bagages du visiteur.
     *
     * @return Le nombre de bagage.
     */
    int getBagage();

    /**
     * @brief Retourne le budget du visiteur.
     *
     * @return Le budget du visiteur.
     */
    int getBudget();

    /**
     * @brief SModifie le budget du visiteur.
     *
     * @param bud Nouveau budget du visiteur.
     */
    void setBudget(int bud);

    /**
     * @brief Modifie le nombre de bagages du visiteur.
     *
     * @param bag Nouveau nombre de bagages du visiteur.
     */
    void setBagage(int bag);

    /**
     * @brief Constructeur d'un visiteur avec toutes les données importantes.
     *
     * @param name Nom du visiteur
     * @param prename Prenom du visiteur.
     * @param nbbag Le nombre de bagages du visiteur.
     * @param nbbud Le budget du visiteur.
     * @param tmp Le temps avant le vol.
     */
    Visiteur(std::string name, std::string prename, int nbbag, int nbbud, int tmp);
    /**
     * @brief Constructeur par défaut d'un visiteur avec des valeurs définies.
     *
     */
    Visiteur();
    /**
     * @brief Constructeur d'un visiteur à une position donnée avec un temps avant vol donné.
     *
     * @param p Position donnée
     * @param tmp Temps avant vol
     */
    Visiteur(Position p, int tmp);

    /**
     * @brief Action réalisé par un visiteur à chaque tour de la simulation.
     * 
     * @return 1 si il est arrivé au vol, 0 sinon. 
     */
    int Action();

    /**
     * @brief Destructeur par défaut du Visiteur.
     * 
     */
    ~Visiteur();

    /**
     * @brief Retourne si le visiteur se fait controller ou non.
     * 
     * @return true Si le visiteur est en train de se faire controller.
     * @return false Si le visiteur n'est pas en train de se faire controller.
     */
    bool getEstControl();

    /**
     * @brief Modifie la valeur du booleen indiquant si le visiteur se fait controller ou non.
     * 
     * @param ctrl Nouvelle valeur du booleen.
     */
    void setEstControl(bool ctrl);
};

#endif
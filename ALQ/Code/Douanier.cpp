#include <iostream>     // Inclusion d'un fichier standard
#include "Douanier.hpp" // Inclusion d'un fichier du répertoire courant

// Constructeur et Destructeur

Douanier::Douanier(std::string nom, std::string prenom) : Personne(nom, prenom), enControle{false}
{
}
Douanier::Douanier() {}

Douanier::Douanier(Position p) : Personne(p)
{
}

Douanier::~Douanier() {}

Personne *Douanier::getVisiteurWithPos(Position p)
{
    Personne *retour = nullptr;
    Position temp;
    for (int i = 0; i < m.nbpersonne; i++)
    {
        temp = m.tabpers[i]->getPos();
        if (temp.getX() == p.getX() && temp.getY() == p.getY())
        {
            retour = m.tabpers[i];
        }
    }
    return retour;
}

void Douanier::DeplacementAleatoire()
{
    int x = getPos().getX();
    int y = getPos().getY();
    double directionX = Random_MT::genrand_real2();
    double directionY = Random_MT::genrand_real2();
    // 33% de chance de se déplacer vers la gauche de rester sur place ou de se déplacer vers la droite
    if (directionX <= 0.33)
    {
        x--;
    }
    if (directionX >= 0.66)
    {
        x++;
    }
    if (directionY <= 0.33)
    {
        y--;
    }
    if (directionY >= 0.66)
    {
        y++;
    }
    // si la case est vide et que la case est dans la map
    if (x >= 0 && y >= 0 && x < 20 && y < 20 && m.OnthisCase(x, y) == 0)
    {
        deplacerPersonne(Position(x, y));
    }
}

// Fonction

void Douanier::getVoisin(int &nombreVoisin, Position voisin[])
{
    // tableau voisin de taille 8 = taille max des voisins possibles
    nombreVoisin = 0;
    int curseur = 0;
    Position posDounier = getPos();
    for (int i = posDounier.getY() - 1; i <= posDounier.getY() + 1; i++)
    {
        for (int j = posDounier.getX() - 1; j <= posDounier.getX() + 1; j++)
        {

            if (i >= 0 && j >= 0 && i < 20 && j < 20 && m.OnthisCase(j, i) == 1)
            {
                voisin[curseur] = Position(j, i);
                curseur++;
            }
        }
    }
    nombreVoisin = curseur;
}

bool Douanier::getEnControle()
{
    return enControle;
}

void Douanier::setEnControle(bool valControle)
{
    enControle = valControle;
}

bool Douanier::checkAlreadyControle(Visiteur *v)
{
    for (int i = 0; i < nbPersonneControlle; i++)
    {
        if (v == dejaControlle[i])
        {
            return true;
        }
    }
    return false;
}

int Douanier::Action()
{
    Position voisin[8];
    int nbVoisin = 0;

    getVoisin(nbVoisin, voisin);

    // si ila a un voisin et qu'il n'est pas en controle
    if (nbVoisin != 0 && !getEnControle())
    {
        // on choisi un voisin au hasard
        double voisinChoisi = Random_MT::genrand_real2() * nbVoisin;

        //  on le controle ou non 3 fois sur 4
        personneControle = (Visiteur *)getVisiteurWithPos(voisin[(int)voisinChoisi]);

        if (!checkAlreadyControle(personneControle) && !personneControle->getEstControl() && Random_MT::genrand_real2() <= 0.75)
        {

            // si pas deja en cours de controle

            // douanier en controle
            setEnControle(true);
            dureeControleActu = 0;
            // visiteur controllé
            personneControle->setEstControl(true);
            dejaControlle[nbPersonneControlle] = personneControle;
            nbPersonneControlle++;
        }
        else
        {
            DeplacementAleatoire();
        }
    }
    // sinon il se déplace car pas de voisin et il est pas en controle
    else if (nbVoisin == 0 && !getEnControle())
    {
        DeplacementAleatoire();
    }

    // si il est en controle
    else
    {
        if (Random_MT::genrand_real2() < probaControle[dureeControleActu])
        {
            setEnControle(false);
            personneControle->setEstControl(false);
            personneControle = nullptr;
        }
        else
        {
            std::cout << "Controle en cours" << std::endl;
            dureeControleActu++;
        }
    }
    return 0;
}

#include <iostream>     // Inclusion d'un fichier standard
#include "Visiteur.hpp" // Inclusion d'un fichier du répertoire courant
#include "Map.hpp"

extern Map m;

int Visiteur::getBagage()
{
    return nbBagage;
};

int Visiteur::getBudget()
{
    return budget;
};

Visiteur::Visiteur(std::string name, std::string prename, int nbbag, int nbbud, int tmp) : Personne(name, prename)
{

    nbBagage = nbbag;
    budget = nbbud;
    aDeposeBagages = false;
    arrive = false;
    tempsAvantVol = tmp;
}
void Visiteur::setBudget(int bud)
{
    budget = bud;
}

void Visiteur::setBagage(int bag)
{
    nbBagage = bag;
}

Visiteur::Visiteur()
{
}

Visiteur::Visiteur(Position p, int tmp) : Personne(p)
{
    tempsAvantVol = tmp;
}

int Visiteur::Action()
{
    int cpt;
    double rand;
    bool peuboug;
    if (posBoutiqueVoulu.getX() == -1 && posBoutiqueVoulu.getY() == -1)
    {
        cpt = 0;
        Zone *tabBoutique[25];
        for (int i = 0; i < m.nbzonne; i++)
        {
            if (Boutique *d = dynamic_cast<Boutique *>(m.tabZone[i]))
            {
                tabBoutique[cpt] = m.tabZone[i];
                cpt++;
            }
        }
        rand = Random_MT::genrand_real2();
        int rang = (cpt - 1) * rand;
        posBoutiqueVoulu = tabBoutique[rang]->getPos();
        posBoutiqueVoulu.setY(posBoutiqueVoulu.getY() - 1);
    }
    if (posZEVoulu.getX() == -1 && posZEVoulu.getY() == -1)
    {
        cpt = 0;
        Zone *tabZE[25];
        for (int i = 0; i < m.nbzonne; i++)
        {
            if (Boutique *d = dynamic_cast<Boutique *>(m.tabZone[i]))
            {
            }
            else
            {
                if (ZoneBagage *e = dynamic_cast<ZoneBagage *>(m.tabZone[i]))
                {
                }
                else
                {
                    tabZE[cpt] = m.tabZone[i];
                    cpt++;
                }
            }
        }
        rand = Random_MT::genrand_real2();
        int rang = (cpt - 1) * rand;
        posZEVoulu = tabZE[rang]->getPos();
        posZEVoulu.setY(posZEVoulu.getY() - 1);
    }
    if (posBagagesVoulu.getX() == -1 && posBagagesVoulu.getY() == -1)
    {
        cpt = 0;
        Zone *tabBagage[25];
        for (int i = 0; i < m.nbzonne; i++)
        {
            if (ZoneBagage *d = dynamic_cast<ZoneBagage *>(m.tabZone[i]))
            {
                tabBagage[cpt] = m.tabZone[i];
                cpt++;
            }
        }
        rand = Random_MT::genrand_real2();
        int rang = (cpt - 1) * rand;
        posBagagesVoulu = tabBagage[rang]->getPos();
        posBagagesVoulu.setY(posBagagesVoulu.getY() - 1);
        rand = Random_MT::genrand_real2();
        if (rand <= 0.75)
        {
            gobtk = true;
        }
    }
    if (estControlle == false)
    {

        if (arrive == true)
        {
            m.grille[getPos().getX()][getPos().getY()] = 0;
            return 1;
        }
        else if (tempsAvantVol > 45)
        {
            if (gobtk == true)
            {
                if (!btk)
                {
                    peuboug = deplacerPersonne(posBoutiqueVoulu);
                    if (getPos().getX() == posBoutiqueVoulu.getX() && getPos().getY() == posBoutiqueVoulu.getY())
                    {
                        btk = true;
                    }
                }

                else if (!aDeposeBagages)
                {
                    peuboug = deplacerPersonne(posBagagesVoulu);
                    if (getPos().getX() == posBagagesVoulu.getX() && getPos().getY() == posBagagesVoulu.getY())
                    {
                        aDeposeBagages = true;
                    }
                }
                else
                {
                    peuboug = deplacerPersonne(posZEVoulu);
                }
            }
            else
            {
                int ra = rand = (int)(Random_MT::genrand_real2() * 10) % 19;
                int rav = rand = (int)(Random_MT::genrand_real2() * 10) % 19;
                Position po{ra, rav};
                deplacerPersonne(po);
            }
        }
        else if (tempsAvantVol > 20)
        {
            if (!aDeposeBagages)
            {
                peuboug = deplacerPersonne(posBagagesVoulu);
                if (getPos().getX() == posBagagesVoulu.getX() && getPos().getY() == posBagagesVoulu.getY())
                {
                    aDeposeBagages = true;
                }
            }
            else
            {
                peuboug = deplacerPersonne(posZEVoulu);
                if (getPos().getX() == posZEVoulu.getX() && getPos().getY() == posZEVoulu.getY())
                {
                    arrive = true;
                }
            }
        }
        else
        {
            peuboug = deplacerPersonne(posZEVoulu);
            if (getPos().getX() == posZEVoulu.getX() && getPos().getY() == posZEVoulu.getY())
            {
                arrive = true;
            }
        }
    }
    tempsAvantVol -= 1;
    return 0;
}

Visiteur::~Visiteur() {}

bool Visiteur::getEstControl()
{
    return estControlle;
}

void Visiteur::setEstControl(bool ctrl)
{
    estControlle = ctrl;
}
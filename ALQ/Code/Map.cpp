#include <iostream>
#include "Map.hpp"

Map::Map() : nbpersonne{0}, nbzonne{0}
{

    for (int i = 0; i < 20; i++)
    {
        for (int j = 0; j < 20; j++)
        {
            grille[j][i] = 0;
        }
    }
}

void Map::AfficherMap()
{
    for (int i = 0; i < 20; i++)
    {
        for (int j = 0; j < 20; j++)
        {

            switch (grille[j][i])
            {
            case 0:
                std::cout << " . ";
                break;

            case 1:
                std::cout << " X ";
                break;

            case 2:
                std::cout << " D ";
                break;

            case 3:
                std::cout << " B ";
                break;

            case 4:
                std::cout << " L ";
                break;

            case 5:
                std::cout << " Z ";
                break;

            default:
                break;
            }
        }
        std::cout << std::endl;
    }
}

int Map::OnthisCase(int j, int i)
{

    return grille[j][i];
}

bool Map::ajouterPers(Personne *p)
{
    bool retour;
    Visiteur v;
    if (OnthisCase(p->getPos().getX(), p->getPos().getY()) == 1 || OnthisCase(p->getPos().getX(), p->getPos().getY()) == 2)
    {
        retour = false;
    }
    else
    {
        tabpers[nbpersonne] = p;
        nbpersonne++;
        retour = true;
        if (Visiteur *d = dynamic_cast<Visiteur *>(p))
        {
            grille[p->getPos().getX()][p->getPos().getY()] = 1;
        }
        else
        {
            grille[p->getPos().getX()][p->getPos().getY()] = 2;
        }
    }
    return retour;
}

void Map::deletePers(Personne *p)
{
    Personne *temp = tabpers[nbpersonne - 1];
    for (int i = 0; i < nbpersonne; i++)
    {
        if (tabpers[i] == p)
        {
            tabpers[i] = temp;
            tabpers[nbpersonne - 1] = nullptr;
            nbpersonne--;
        }
    }
}
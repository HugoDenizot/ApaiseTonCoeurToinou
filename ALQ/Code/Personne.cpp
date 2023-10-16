#include <iostream>     // Inclusion d'un fichier standard
#include "Personne.hpp" // Inclusion d'un fichier du répertoire courant
#include "Map.hpp"
extern Map m;

Personne::Personne(std::string name, std::string prename) : nom{name}, prenom{prename}
{
    std::cout << "Constructeur de personne" << std::endl;
}

Personne::Personne(Position p) : Personne("", "")
{
    pos = p;
}

Personne::Personne() {}

std::string Personne::getnom()
{
    return nom;
};

void Personne::setNom(std::string n)
{
    nom = n;
}

std::string Personne::getprenom()
{
    return prenom;
};

void Personne::setPrenom(std::string p)
{
    prenom = p;
}

int Personne::getid()
{
    return id;
};

Position Personne::getPos()
{
    return pos;
}

void Personne::setPos(Position p)
{
    pos = p;
}

bool Personne::deplacerPersonne(Position p1)
{
    bool retour;
    bool direction;
    Position futurpos = pos;
    if (p1.getX() >= 0 && p1.getY() >= 0 && p1.getX() <= 20 && p1.getY() <= 20)
    {
        if (pos.getX() != p1.getX())
        {
            if (pos.getX() - p1.getX() < 0)
            {
                futurpos.setX(futurpos.getX() + 1);
            }
            else
            {
                futurpos.setX(futurpos.getX() - 1);
            }
            direction = true;
        }
        else if (pos.getY() != p1.getY())
        {
            if (pos.getY() - p1.getY() < 0)
            {
                futurpos.setY(futurpos.getY() + 1);
            }
            else
            {
                futurpos.setY(futurpos.getY() - 1);
            }
            direction = false;
        }
        if (m.OnthisCase(futurpos.getX(), futurpos.getY()) != 0)
        {
            futurpos = pos;
            if (direction == true)
            {
                if (pos.getY() != p1.getY())
                {
                    if (pos.getY() - p1.getY() < 0)
                    {
                        futurpos.setY(futurpos.getY() + 1);
                    }
                    else
                    {
                        futurpos.setY(futurpos.getY() - 1);
                    }
                    if (m.OnthisCase(futurpos.getX(), futurpos.getY()) != 0)
                    {
                        retour = false;
                    }
                    else
                    {
                        m.grille[pos.getX()][pos.getY()] = 0;
                        setPos(futurpos);
                        if (Visiteur *d = dynamic_cast<Visiteur *>(this))
                        {
                            m.grille[futurpos.getX()][futurpos.getY()] = 1;
                        }
                        else
                        {
                            m.grille[futurpos.getX()][futurpos.getY()] = 2;
                        }
                        retour = true;
                    }
                }
            }
            if (direction == false)
            {
                if (pos.getX() != p1.getX())
                {
                    if (pos.getX() - p1.getX() < 0)
                    {
                        futurpos.setX(futurpos.getX() + 1);
                    }
                    else
                    {
                        futurpos.setX(futurpos.getX() - 1);
                    }
                    if (m.OnthisCase(futurpos.getX(), futurpos.getY()) != 0)
                    {
                        retour = false;
                    }
                    else
                    {
                        m.grille[pos.getX()][pos.getY()] = 0;
                        setPos(futurpos);
                        if (Visiteur *d = dynamic_cast<Visiteur *>(this))
                        {
                            m.grille[futurpos.getX()][futurpos.getY()] = 1;
                        }
                        else
                        {
                            m.grille[futurpos.getX()][futurpos.getY()] = 2;
                        }
                        retour = true;
                    }
                }
            }
        }
        else
        {
            m.grille[pos.getX()][pos.getY()] = 0;
            setPos(futurpos);
            if (Visiteur *d = dynamic_cast<Visiteur *>(this))
            {
                m.grille[futurpos.getX()][futurpos.getY()] = 1;
            }
            else
            {
                m.grille[futurpos.getX()][futurpos.getY()] = 2;
            }
            retour = true;
        }
    }
    else
    {
        retour = false;
    }
    return retour;
}

Personne::~Personne() {}

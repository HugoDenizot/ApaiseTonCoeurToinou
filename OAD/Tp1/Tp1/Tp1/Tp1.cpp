// Tp1.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include <fstream>
#include <string>
#include "fonc.h"

using namespace std;

int main()
{
    t_solution ma_solution;
    t_graphe mon_graphe;
    

    string const nomFichier("P:/OAD/Tp1/test.txt");
    ifstream monFlux(nomFichier.c_str());
    remplirGraf(mon_graphe);
    dijktra(mon_graphe, ma_solution, 1,9);

    if (monFlux)
    {
       /* string ligne; //Une variable pour stocker les lignes lues
        getline(monFlux, ligne);
        int nbsommet = atoi(ligne);
        for(int i = 0;i<)*/
    }
    else
    {
		std::cout << "ERREUR: Impossible d'ouvrir le fichier." << endl;
    }
    return 0;


}

// Exécuter le programme : Ctrl+F5 ou menu Déboguer > Exécuter sans débogage
// Déboguer le programme : F5 ou menu Déboguer > Démarrer le débogage

// Astuces pour bien démarrer : 
//   1. Utilisez la fenêtre Explorateur de solutions pour ajouter des fichiers et les gérer.
//   2. Utilisez la fenêtre Team Explorer pour vous connecter au contrôle de code source.
//   3. Utilisez la fenêtre Sortie pour voir la sortie de la génération et d'autres messages.
//   4. Utilisez la fenêtre Liste d'erreurs pour voir les erreurs.
//   5. Accédez à Projet > Ajouter un nouvel élément pour créer des fichiers de code, ou à Projet > Ajouter un élément existant pour ajouter des fichiers de code existants au projet.
//   6. Pour rouvrir ce projet plus tard, accédez à Fichier > Ouvrir > Projet et sélectionnez le fichier .sln.

// Tp2.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include <fstream>
#include <string>
#include <time.h>
#include "Header.h"


int main()
{
    instance la01;
    solution sla01;
    string flux = "../la01.txt";
    int hash_debut;
    srand(time(NULL));
    LectureFichier(flux, la01);
    srand(time(NULL));

    genererVecteur(la01, sla01);
    evaluer(la01, sla01);

    memset(tab_hash, 0, 1000000 * sizeof(int));

    hash_debut = calcul_hash(sla01, la01);

    tab_hash[hash_debut] = 1;

    //graSP(la01, sla01, 10, 1000, 15);
    recherche_locale(la01, sla01, 1000);
    printf("Meilleur cout %d", sla01.cout);
}

void LectureFichier(string monFichier, instance& T) {
    ifstream monFlux(monFichier);
    if (monFlux) {
        monFlux >> T.n;
        monFlux >> T.m;
        int cpt1 = 1;
        int cpt2;
        while (cpt1 <= T.n) {
            for (cpt2 = 1; cpt2 <= T.m; cpt2++) {
                monFlux >> T.mij[cpt1][cpt2];
                monFlux >> T.pij[cpt1][cpt2];
            }
            cpt1++;
        }
    }
    else {
        cout << "Erreur : impossible d'ouvrir le fichier en lecture " << endl;
    }
    return;
}

void afficher(instance& T) {
    for (int i = 1; i <= T.n; i++) {
        for (int j = 1; j <= T.m; j++) {
            printf("%d %d\t", T.mij[i][j], T.pij[i][j]);
        }
        printf("\n");
    }
}

void genererVecteur(instance& T, solution& s) {
    int cpt[nmax];
    int nbRep = T.n * T.m;
    int alea;
    int i = 1;
    bool valide;
    for (int i = 1; i < nmax; i++) {
        cpt[i] = T.m;
    }
    while (nbRep > 0) {
        valide = false;
        while (!valide) {
            alea = rand() % T.n + 1;
            if (cpt[alea] != 0) {
                s.vb[i] = alea;
                cpt[alea] -= 1;
                valide = true;
            }
        }
        i++;
        nbRep--;
    }
    /* for (int j = 1; j <= T.n * T.m; j++) {
         printf("%d ", s.vb[j]);
     }
     printf("\n");*/
}

void evaluer(instance& T, solution& s) {
    int i, j, m, p, q, date;
    int cpt[nmax + 1];
    int mach;
    int pm[nmax][2];
    for (i = 0; i < nmax; i++) {
        pm[i][0] = 0;
        pm[i][1] = 0;
    }
    memset(&s.tij[0][0], 0, nmax * mmax * sizeof(int));
    memset(cpt, 0, sizeof(cpt));
    s.cout = 0;
    for (i = 1; i <= T.n * T.m; i++) {
        j = s.vb[i];
        cpt[j] = cpt[j] + 1;
        if (cpt[j] > 1) {
            m = s.tij[j][cpt[j] - 1];
            if (m + T.pij[j][cpt[j] - 1] > s.tij[j][cpt[j]]) {
                s.tij[j][cpt[j]] = m + T.pij[j][cpt[j] - 1];
                s.pere[j][cpt[j]].li = j;
                s.pere[j][cpt[j]].col = cpt[j] - 1;
            }
        }
        mach = T.mij[j][cpt[j]];
        if (pm[mach][0] != 0 || pm[mach][1] != 0) {
            p = pm[mach][0];
            q = pm[mach][1];
            date = s.tij[p][q];
            if (date + T.pij[p][q] >= s.tij[j][cpt[j]]) {
                s.tij[j][cpt[j]] = date + T.pij[p][q];
                s.pere[j][cpt[j]].li = p;
                s.pere[j][cpt[j]].col = q;
            }
        }
        pm[mach][0] = j;
        pm[mach][1] = cpt[j];
    }
    for (i = 1; i <= T.n; i++) {
        if (s.tij[i][T.m] + T.pij[i][T.m] > s.cout) {
            s.cout = s.tij[i][T.m] + T.pij[i][T.m];
            s.pere[T.n + 1][T.m + 1].li = i;
            s.pere[T.n + 1][T.m + 1].col = T.m;
        }
    }
    //cout << "Reussite du programme, le cout est de  " << s.cout << endl;
}

int chercher(t_tuple i, solution& s, instance& T) {
    int j = 0;
    for (int cpt = 1; cpt <= T.n * T.m; cpt++) {
        if (s.vb[cpt] == i.li) {
            j++;
            if (j == i.col) {
                return cpt;
            }
        }
    }
}

void permuter(int i, int j, solution& sprime, solution& s, instance& T) {
    int aux;

    for (int k = 1; k <= T.n; k++) {
        for (int l = 1; l <= T.m; l++) {
            sprime.tij[k][l] = s.tij[k][l];
        }
    }

    for (int cpt = 1; cpt <= T.n * T.m; cpt++)
        sprime.vb[cpt] = s.vb[cpt];

    aux = sprime.vb[i];
    sprime.vb[i] = sprime.vb[j];
    sprime.vb[j] = aux;
}

int calcul_hash(solution& sprime, instance& T) {
    int hash = 0;
    for (int i = 1; i <= T.n; i++) {
        for (int j = 1; j <=T.m; j++) {
            hash +=pow(sprime.tij[i][j],2);
        }
    }
    hash = hash % 1000000;
    return hash;
}

void recherche_locale(instance& T, solution& s, int nbMaxIte) {
    solution sprime;

    int posI;
    int posJ;
    int stop = 0;
    int indice_hash;
    int c = 0;
    int cout_minimum = 9999;

    t_tuple i;
    t_tuple j;

    
    
    evaluer(T, s);

    for (int cpt = 1; cpt <= T.n; cpt++) {
        s.pere[cpt][1].li = 0;
        s.pere[cpt][1].col = 0;
    }
    
    i.li = T.n + 1;
    i.col = T.m + 1;
    
    j.li = s.pere[i.li][i.col].li;
    j.col = s.pere[i.li][i.col].col;

    if (cout_minimum > s.cout) {
        cout_minimum = s.cout;
    }

    
    while (stop == 0)
    {

        c++;

        if (T.mij[i.li][i.col] == T.mij[j.li][j.col]) {
            
            //printf("Machine i = %d piece de i : %d et Machine j =%d piece de j %d \n", i.col, i.li, j.col, j.li);
            
            posI = chercher(i, s, T);
            posJ = chercher(j, s, T);
            
            //printf("posI = %d et posJ=%d\n", posI, posJ);
            permuter(posI, posJ, sprime, s, T);

            indice_hash = calcul_hash(sprime, T);

            //printf("cle : %d\n", indice_hash);

            if (tab_hash[indice_hash] == 0) {
                
                evaluer(T, sprime);

                if (cout_minimum > sprime.cout) {
                    cout_minimum = sprime.cout;
                }

                //printf("\n\nCout en plein milieu %d\n\n", sprime.cout);
                
                tab_hash[indice_hash] = 1;
                if (sprime.cout > s.cout) {
                    i = j;
                    j.li = s.pere[i.li][i.col].li;
                    j.col = s.pere[i.li][i.col].col;
                }
                else {
                    for (int cpt = 1; cpt <= T.n * T.m; cpt++)
                        s.vb[cpt] = sprime.vb[cpt];
                   
                    i.li = T.n + 1;
                    i.col = T.m + 1;
                    j.li = s.pere[i.li][i.col].li;
                    j.col = s.pere[i.li][i.col].col;
                }
            }
            else {
               
                i = j;
                j.li = s.pere[i.li][i.col].li;
                j.col = s.pere[i.li][i.col].col;
            }


        }
        else {
            
            i = j;
            j.li = s.pere[i.li][i.col].li;
            j.col = s.pere[i.li][i.col].col;
        }
        if ((i.li == 0 && i.col == 0) || c == nbMaxIte) {
            stop = 1;
        }
    }
    s.cout = cout_minimum;
}

void genererVoisin(instance& T, solution& s, solution& voisin_sol) {
    int pos1;
    int pos2;
    int aux;
    for (int k = 1; k <= T.n; k++) {
        for (int l = 1; l <= T.m; l++) {
            voisin_sol.tij[k][l] = s.tij[k][l];
        }
    }
    for (int i = 1; i <= T.n * T.m; i++) {
        voisin_sol.vb[i] = s.vb[i];
    }
    pos1 =1+ rand() % (T.n*T.m);
    pos2 =1+ rand() % (T.n * T.m);

    while (voisin_sol.vb[pos1] == voisin_sol.vb[pos2]) {
        pos1 =1+ rand() % (T.n * T.m);
    }
    aux = voisin_sol.vb[pos1];
    voisin_sol.vb[pos1] = voisin_sol.vb[pos2];
    voisin_sol.vb[pos2] = aux;

}

void graSP(instance& T, solution& s, int nbels, int nb_iter, int nbVoisin) {
    int hashcode;
    solution s_els;
    solution voisin_sol;
    int nbvoisinscourant;
    int meilleur_cout = 9999;
    for (int i = 1; i < nb_iter; i++) {
        //printf("essaie %d\n", i);
        hashcode = calcul_hash(s, T);
        while (tab_hash[hashcode] == 1) {
            genererVecteur(T, s);
            evaluer(T, s);
            recherche_locale(T, s, 100);
            hashcode = calcul_hash(s, T);
        }
        if (meilleur_cout > s.cout) {
            meilleur_cout = s.cout;
        }
        s_els = s;
        for (int j = 1; j < nbels; j++) {
            nbvoisinscourant = 0;
            //printf("voisin %d\n", j);
            while (nbvoisinscourant != nbVoisin)
            {
                genererVoisin(T, s, voisin_sol);
                recherche_locale(T, voisin_sol, 100);
                if (meilleur_cout > voisin_sol.cout) {
                    meilleur_cout = voisin_sol.cout;
                }
                hashcode = calcul_hash(voisin_sol, T);

                if (tab_hash[hashcode] == 1) {
                }
                else {
                    nbvoisinscourant++;
                }
            }
            
        }
        
    }
        printf("Le meilleur cout est %d\n",meilleur_cout);
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
    
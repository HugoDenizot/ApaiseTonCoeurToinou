// Tp3.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//
#include "Tp3.h"


int main()
{
    srand(time(NULL));
    T_INST instance;
    T_Solution solution;
    lire_inst("HVRP_DLP_75.txt", instance);
    //generer_tour_geant(instance, solution);
    //tour_geant_random(instance, solution);
    tour_geant_retour(instance, solution);
    Split(instance, solution);
    printf("Le cout de la solution est %d\n", solution.count);    
    printf("\n");
    mirroir(instance, solution, 3, 7);
    Split(instance, solution);
    printf("Le cout de la solution apres 2OPT tour geant est %d\n", solution.count);
    deplacementSommet(instance, solution);
    Split(instance, solution);
    printf("Le cout de la solution apres le deplacement de sommet est %d\n", solution.count);
    printf("\n");
    //interTournee(instance, solution);
}


void lire_inst(string nom, T_INST& I) {
    ifstream monflux(nom);
    if (monflux) {
        monflux >> I.n;
        monflux >> I.nb_vehicules;
        monflux >> I.capa;
        for (int i = 0; i <= I.n; i++) {
            for (int j = 0; j <= I.n; j++) {
                monflux >> I.dist[i][j];
            }
        }
        int inutile;
        for (int i = 0; i <= I.n; i++) {
            monflux >> inutile;
            monflux >> I.d[i];
        }
    }
    else {
        cout << "Erreur lors de l'ouverture du fichier" << endl;
    }
}



void generer_tour_geant(T_INST& I, T_Solution& S) {
    int cpt[nmax_client];
    int taillecpt = I.n;
    int lastj;
    for (int i = 0; i <= I.n; i++) {
        cpt[i] = i;
    }
    S.tour_gen[0] = 0;
    for (int i = 1; i <= I.n; i++) {
        int depart = S.tour_gen[i - 1];
        int mini = 99999999;
        //Rechercher le sommet le plus proche du sommet depart;
        for (int j = 1; j <= taillecpt; j++) {
            if (I.dist[depart][cpt[j]] < mini) {
                mini = I.dist[depart][cpt[j]];
                lastj = j;
            }
        }
        S.tour_gen[i] = cpt[lastj];
        cpt[lastj] = cpt[taillecpt];
        taillecpt -= 1;
    }
    
    S.nb_tournees = 0;
    S.count = 0;

}

void tour_geant_random(T_INST& I, T_Solution& S) {
    int cpt[nmax_client];
    int taillecpt = I.n;
    int lastj;
    int j1 = I.n, j2 = I.n, j3 = I.n, j4 = I.n;
    float random;

    for (int i = 0; i <= I.n; i++) {
        cpt[i] = i;
    }
    S.tour_gen[0] = 0;
    for (int i = 1; i <= I.n; i++) {
        int depart = S.tour_gen[i - 1];
        int mini = 99999999;
        int voisin_1 = 99999999;
        int voisin_2 = 99999999;
        int voisin_3 = 99999999;
        int voisin_4 = 99999999;
        //Rechercher le sommet le plus proche du sommet depart;
        for (int j = 1; j <= taillecpt; j++) {
            if (I.dist[depart][cpt[j]] < voisin_1) {
                voisin_4 = voisin_3;
                voisin_3 = voisin_2;
                voisin_2 = voisin_1;
                voisin_1 = I.dist[depart][cpt[j]];
                j4 = j3;
                j3 = j2;
                j2 = j1;
                j1 = j;
            }
            else if (I.dist[depart][cpt[j]] < voisin_2) {
                voisin_4 = voisin_3;
                voisin_3 = voisin_2;
                voisin_2 = I.dist[depart][cpt[j]];
                j4 = j3;
                j3 = j2;
                j2 = j;
            }
            else if (I.dist[depart][cpt[j]] < voisin_3) {
                voisin_4 = voisin_3;
                voisin_3 = I.dist[depart][cpt[j]];
                j4 = j3;
                j3 = j;
            }
            else if (I.dist[depart][cpt[j]] < voisin_4) {
                voisin_4 = I.dist[depart][cpt[j]];
                j4 = j;
            }
        }
        random = rand() % 101;
        if (random < 80) {
            lastj = j1;
        }
        else {
            random = rand() % 101;
            if (random < 80) {
                lastj = j2;
            }
            else {
                random = rand() % 101;
                if (random < 80)
                {
                    lastj = j3;

                }
                else {
                    lastj = j4;
                }
            }
        }
        S.tour_gen[i] = cpt[lastj];
        cpt[lastj] = cpt[taillecpt];
        taillecpt -= 1;
    }
    S.nb_tournees = 0;
    S.count = 0;
}


void tour_geant_retour(T_INST& I, T_Solution& S) {
    int cpt[nmax_client];
    int taillecpt = I.n;
    int lastj;
    int j1 = I.n, j2 = I.n, j3 = I.n, j4 = I.n;
    float random;
    int voisin_1 = 99999999;
    int voisin_2 = 99999999;
    int voisin_3 = 99999999;
    int voisin_4 = 99999999;
    int result[5];

    int capautilise = 0;
    for (int i = 0; i <= I.n; i++) {
        cpt[i] = i;
    }
    S.tour_gen[0] = 0;
    for (int i = 1; i <= I.n; i++) {
        int depart = S.tour_gen[i - 1];
        int mini = 99999999;
        voisin_1 = 99999999;
        voisin_2 = 99999999;
        voisin_3 = 99999999;
        voisin_4 = 99999999;
        //Rechercher le sommet le plus proche du sommet depart;
        for (int j = 1; j <= taillecpt; j++) {
            if (I.dist[depart][cpt[j]] < voisin_1) {
                voisin_4 = voisin_3;
                voisin_3 = voisin_2;
                voisin_2 = voisin_1;
                voisin_1 = I.dist[depart][cpt[j]];
                j4 = j3;
                j3 = j2;
                j2 = j1;
                j1 = cpt[j];
            }
            else if (I.dist[depart][cpt[j]] < voisin_2) {
                voisin_4 = voisin_3;
                voisin_3 = voisin_2;
                voisin_2 = I.dist[depart][cpt[j]];
                j4 = j3;
                j3 = j2;
                j2 = cpt[j];
            }
            else if (I.dist[depart][cpt[j]] < voisin_3) {
                voisin_4 = voisin_3;
                voisin_3 = I.dist[depart][cpt[j]];
                j4 = j3;
                j3 = cpt[j];
            }
            else if (I.dist[depart][cpt[j]] < voisin_4) {
                voisin_4 = I.dist[depart][cpt[j]];
                j4 = cpt[j];
            }
        }
        result[1] = j1;
        result[2] = j2;
        result[3] = j3;
        result[4] = j4;
        int minj;
        int aux;
        int temp;
        int max;
        if (taillecpt > 4) {
            max = 4;
        }
        else {
            max = taillecpt;
        }
        for (int j = 1; j < max; j++) {
            minj = j;
            int min = I.dist[0][result[j]];
            for (int f = j + 1; f <= max; f++) {
                temp = I.dist[0][result[f]];
                if (I.dist[0][result[f]] < min) {
                    minj = f;
                    min = I.dist[0][result[f]];
                }
            }
            if (minj != j) {
                aux = result[j];
                result[j] = result[minj];
                result[minj] = aux;
            }
        }
        if (i < (I.n / 2)) {
            lastj = result[4];
        }
        else {
            lastj = result[1];
        }
        S.tour_gen[i] = cpt[lastj];
        int pos;
        for (int iter = 1; iter <= taillecpt; iter++) {
            if (cpt[iter] == lastj) {
                pos = iter;
            }
        }
        cpt[pos] = cpt[taillecpt];
        taillecpt -= 1;
    }
    S.tour_gen[I.n + 1] = 0;
    S.nb_tournees = 0;
    S.count = 0;
}

void Split(T_INST &t, T_Solution& s)
{
    int j, cout, charge, clientparcouru, nbTournee;

    int m[nmax_client + 1];
    int pere[nmax_client];
    m[0] = 0;

    for (int i = 1; i <= nmax_client; i++)
    {
        m[i] = 99999999;
    }

    for (int i = 0; i < t.n; i++)
    {
        j = i + 1;

        do
        {
            if (j == i + 1)
            {
                cout = t.dist[0][s.tour_gen[j]] + t.dist[s.tour_gen[j]][0];
                charge = t.d[s.tour_gen[j]];
                if (m[i] + cout < m[j])
                {
                    m[j] = m[i] + cout;
                    pere[j] = i;
                }
            }
            else
            {
                cout = cout - t.dist[s.tour_gen[j - 1]][0] + t.dist[s.tour_gen[j - 1]][s.tour_gen[j]] + t.dist[s.tour_gen[j]][0];
                charge = charge + t.d[s.tour_gen[j]];
                if (m[i] + cout < m[j])
                {
                    m[j] = m[i] + cout;
                    pere[j] = i;
                }
            }
            j = j + 1;
        } while (j <= t.n && (charge + t.d[s.tour_gen[j]] < t.capa));
    }

    pere[0] = 0;

    clientparcouru = 1;
    nbTournee = 0;
    int cour;

    while (clientparcouru <= t.n)
    {
        s.liste[nbTournee].nb = 0;
        s.liste[nbTournee].cost = 0;
        cour = pere[clientparcouru];
        while (pere[clientparcouru] == cour)
        {
            s.liste[nbTournee].nb++;
            s.liste[nbTournee].liste[s.liste[nbTournee].nb] = s.tour_gen[clientparcouru];
            clientparcouru++;
        }

        s.liste[nbTournee].liste[0] = 0;
        s.liste[nbTournee].liste[s.liste[nbTournee].nb + 1] = 0;
        nbTournee++;

    }

    int i = 0;
    j = 0;
    s.count = 0;
    while (i < nbTournee) {
        s.liste[i].cost = 0;
        for (int j = 0; j <= s.liste[i].nb; j++) {
            s.liste[i].cost += t.dist[s.liste[i].liste[j]][s.liste[i].liste[j + 1]];
        }
        s.count += s.liste[i].cost;
        i++;
    }
    s.nb_tournees = nbTournee;
}

void decalerGauche(T_INST &t, T_Solution& sol, int a) {
    for (int i = a; i < t.n; i++) {
        sol.tour_gen[i] = sol.tour_gen[i + 1];
    }
}

void decalerDroite(T_INST& t, T_Solution& s, int a) {
    for (int i = t.n; i > a; i--) {
        s.tour_gen[i] = s.tour_gen[i - 1];
    }
}

void deplacementSommet(T_INST& t, T_Solution& s) {
    int randomDepart = rand()%t.n;
    int randomArrive = rand() % t.n;
    int numeroSommet = s.tour_gen[randomDepart];
    decalerGauche(t, s, randomDepart);
    decalerDroite(t, s, randomArrive);
    s.tour_gen[randomArrive] = numeroSommet;
}

void afficherTourGen(T_INST &I, T_Solution &S) {
    printf("[");
    for (int i = 0; i <= I.n; i++) {
        printf("%d\t", S.tour_gen[i]);
    }
    printf("]\n");
}

void mirroir(T_INST& T, T_Solution& S, int depart, int arrive) {
    int temp;
    for (int i = 0; i <= (arrive - depart) / 2; i++) {
        temp = S.tour_gen[depart+i];
        S.tour_gen[depart+i] = S.tour_gen[arrive-i];
        S.tour_gen[arrive-i] = temp;
    }
}

void interTournee(T_INST& T, T_Solution& S) {
    T_TRIP t1, t2;

    int random1, random2;
    int sommet1, sommet2;

    random1 = rand() % S.nb_tournees;
    random2 = rand() % S.nb_tournees;
    while (random1 == random2) {
        random2 = rand() % S.nb_tournees;
    }
    t1 = S.liste[random1];
    t2 = S.liste[random2];
    sommet1 = rand() % t1.nb;
    sommet2 = rand() % t2.nb;

    printf("Tournée %d et tournée %d, sommet %d et sommet %d", random1, random2, sommet1, sommet2);

    int list1[nmax_client_par_tour];
    int list2[nmax_client_par_tour];
    int nblist1restant, nblist2restant;

    nblist1restant = t2.nb - sommet2;
    nblist2restant = t1.nb - sommet1;
    
    int i, j, lasti, lastj;

    for (i = 0; i <= sommet1; i++) {
        list1[i] = t1.liste[i];
    }

    for (j = 0; j <= sommet2; j++) {
        list2[j] = t2.liste[j];
    }

    lasti = i;
    lastj = j;
    int nbliste1 = sommet1 + nblist1restant;
    int nbliste2 = sommet2 + nblist2restant;
    while (nblist1restant > 0) {
        list1[i] = t2.liste[j];
        i++;
        j++;
        nblist1restant--;
    }
    list1[i] = 0;
    i = lasti;
    j = lastj;

    while (nblist2restant > 0) {
        list2[j] = t1.liste[i];
        i++;
        j++;
        nblist2restant--;
    }
    list2[j] = 0;
    memset(S.liste[random1].liste,-1, nmax_client_par_tour);
    memset(S.liste[random2].liste, -1, nmax_client_par_tour);
    for (i = 0; i <= nbliste1+1; i++) {
        S.liste[random1].liste[i] = list1[i];
    }
    for (i = 0; i <= nbliste2+1; i++) {
        S.liste[random2].liste[i] = list2[i];
    }
    S.liste[random1].nb = nbliste1;
    S.liste[random2].nb = nbliste2;
}
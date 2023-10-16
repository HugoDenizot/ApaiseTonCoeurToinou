#include <iostream>
#include <fstream>
#include <string>
#include <time.h>

using namespace std;

const int nmax_client = 500;
const int nmax_client_par_tour = 50;
const int nmax_trip = 50;

typedef struct T_INST {
	int n;
	int nb_vehicules;
	int capa;
	int dist[nmax_client][nmax_client];
	int d[nmax_client];//demande client
}T_INST;

typedef struct  T_TRIP {
	int nb; //Nombre de clients
	int cost;
	int liste[nmax_client_par_tour]; //Liste des clients
}T_TRIP;

typedef struct T_Solution {
	int nb_tournees;
	T_TRIP liste[nmax_trip];
	int marque[nmax_client];
	int count;
	int tour_gen[nmax_client];
	int pere[nmax_client];
}T_Solution;

void lire_inst(string nom, T_INST& I);
void generer_tour_geant(T_INST& I, T_Solution& S);
void tour_geant_random(T_INST& I, T_Solution& S);
void tour_geant_avec_retour_depot(T_INST& I, T_Solution& S);
void tour_geant_retour(T_INST& I, T_Solution& S);
void Split( T_INST& t, T_Solution& s);
void decalerGauche(T_INST& t, T_Solution& sol, int a);
void decalerDroite(T_INST& t, T_Solution& s, int a);
void deplacementSommet(T_INST& t, T_Solution& s);
void afficherTourGen(T_INST& I, T_Solution& S);
void mirroir(T_INST& T, T_Solution& S, int depart, int arrive);
void interTournee(T_INST& T, T_Solution& S);

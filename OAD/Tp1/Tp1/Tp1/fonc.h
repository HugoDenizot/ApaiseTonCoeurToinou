#pragma once

#include "fonc.h"

const int nmax = 50;
const int nmaxsucc = 10;
const int infini = 99999;



typedef struct t_graphe {
	int n;
	int ns[nmax];
	int d[nmax][nmaxsucc];
	int s[nmax][nmaxsucc];
}t_graphe;



typedef struct t_solution {
	int cout;
	int date[nmax];
	int pere[nmax];
}; t_solution;


void remplirGraf(t_graphe& graf);
void dijktra(t_graphe graf, t_solution& solu, int deb, int fin);
#pragma once
using namespace std;
const int nmax = 21;
const int mmax = 21;


int tab_hash[1000001];
typedef struct instance {
	int n;
	int m;
	int pij[nmax][mmax];
	int mij[nmax][mmax];
};

typedef struct {
	int li;
	int col;
}t_tuple;

typedef struct solution {
	int cout;
	int tij[nmax][mmax];
	t_tuple pere[nmax][mmax];
	int vb[nmax*mmax];
};






void LectureFichier(string monFichier, instance &T);
void afficher(instance& T);
void genererVecteur(instance& T, solution& s);
void evaluer(instance &T,solution& s);
void recherche_locale(instance& T,solution& s, int nbMaxIte);
int calcul_hash(solution& sprime, instance& T);
void graSP(instance& T, solution& s, int nbels, int nb_iter, int nbVoisin);
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>


typedef enum{
	male=0,
	femelle=1
}sexe_t;

typedef enum{
	mort=0,
	vivant=1
}vie_t;

typedef struct
{
	sexe_t sexe;
	int age;
	int portee_restante;
	int is_mature;
	vie_t en_vie;
}lapin_t;

lapin_t tab_lapins[500];
long nbLapin;

void Simulation(int nb_mois,int nb_lapin_adulte);
void creerLapin(int nb_lapin_adulte);
sexe_t choix_sexe();
void simulation_maladie_predateur();
void decalerGauche(int i);


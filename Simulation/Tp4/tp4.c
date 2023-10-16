/**
 * @file        tp3.c
 * @brief       Contient le code de toutes les fonctions permettant de mener à bien le tp3.
 * @details     Ce fichier contient toutes les fonctions permettant de réaliser des tirages aléatoires, ainsi que les fonctions nécessaires pour répondre aux questions du tp3.
 * @author      Hugo DENIZOT <hugo.denizot@etu.uca.fr>
 * @version     1.0
 * @date        2022
 * @copyright   GNU Public License.
 */



#include "tp4.h"

/* Period parameters */  
#define N 624
#define M 397
#define MATRIX_A 0x9908b0dfUL   /* constant vector a */
#define UPPER_MASK 0x80000000UL /* most significant w-r bits */
#define LOWER_MASK 0x7fffffffUL /* least significant r bits */

static unsigned long mt[N]; /* the array for the state vector  */
static int mti=N+1; /* mti==N+1 means mt[N] is not initialized */

/* initializes mt[N] with a seed */
void init_genrand(unsigned long s)
{
    mt[0]= s & 0xffffffffUL;
    for (mti=1; mti<N; mti++) {
        mt[mti] = 
        (1812433253UL * (mt[mti-1] ^ (mt[mti-1] >> 30)) + mti); 
        /* See Knuth TAOCP Vol2. 3rd Ed. P.106 for multiplier. */
        /* In the previous versions, MSBs of the seed affect   */
        /* only MSBs of the array mt[].                        */
        /* 2002/01/09 modified by Makoto Matsumoto             */
        mt[mti] &= 0xffffffffUL;
        /* for >32 bit machines */
    }
}

/* initialize by an array with array-length */
/* init_key is the array for initializing keys */
/* key_length is its length */
/* slight change for C++, 2004/2/26 */
void init_by_array(unsigned long init_key[], int key_length)
{
    int i, j, k;
    init_genrand(19650218UL);
    i=1; j=0;
    k = (N>key_length ? N : key_length);
    for (; k; k--) {
        mt[i] = (mt[i] ^ ((mt[i-1] ^ (mt[i-1] >> 30)) * 1664525UL))
          + init_key[j] + j; /* non linear */
        mt[i] &= 0xffffffffUL; /* for WORDSIZE > 32 machines */
        i++; j++;
        if (i>=N) { mt[0] = mt[N-1]; i=1; }
        if (j>=key_length) j=0;
    }
    for (k=N-1; k; k--) {
        mt[i] = (mt[i] ^ ((mt[i-1] ^ (mt[i-1] >> 30)) * 1566083941UL))
          - i; /* non linear */
        mt[i] &= 0xffffffffUL; /* for WORDSIZE > 32 machines */
        i++;
        if (i>=N) { mt[0] = mt[N-1]; i=1; }
    }

    mt[0] = 0x80000000UL; /* MSB is 1; assuring non-zero initial array */ 
}

/* generates a random number on [0,0xffffffff]-interval */
unsigned long genrand_int32(void)
{
    unsigned long y;
    static unsigned long mag01[2]={0x0UL, MATRIX_A};
    /* mag01[x] = x * MATRIX_A  for x=0,1 */

    if (mti >= N) { /* generate N words at one time */
        int kk;

        if (mti == N+1)   /* if init_genrand() has not been called, */
            init_genrand(5489UL); /* a default initial seed is used */

        for (kk=0;kk<N-M;kk++) {
            y = (mt[kk]&UPPER_MASK)|(mt[kk+1]&LOWER_MASK);
            mt[kk] = mt[kk+M] ^ (y >> 1) ^ mag01[y & 0x1UL];
        }
        for (;kk<N-1;kk++) {
            y = (mt[kk]&UPPER_MASK)|(mt[kk+1]&LOWER_MASK);
            mt[kk] = mt[kk+(M-N)] ^ (y >> 1) ^ mag01[y & 0x1UL];
        }
        y = (mt[N-1]&UPPER_MASK)|(mt[0]&LOWER_MASK);
        mt[N-1] = mt[M-1] ^ (y >> 1) ^ mag01[y & 0x1UL];

        mti = 0;
    }
  
    y = mt[mti++];

    /* Tempering */
    y ^= (y >> 11);
    y ^= (y << 7) & 0x9d2c5680UL;
    y ^= (y << 15) & 0xefc60000UL;
    y ^= (y >> 18);

    return y;
}

/* generates a random number on [0,0x7fffffff]-interval */
long genrand_int31(void)
{
    return (long)(genrand_int32()>>1);
}

/* generates a random number on [0,1]-real-interval */
double genrand_real1(void)
{
    return genrand_int32()*(1.0/4294967295.0); 
    /* divided by 2^32-1 */ 
}

/* generates a random number on [0,1)-real-interval */
double genrand_real2(void)
{
    return genrand_int32()*(1.0/4294967296.0); 
    /* divided by 2^32 */
}

/* generates a random number on (0,1)-real-interval */
double genrand_real3(void)
{
    return (((double)genrand_int32()) + 0.5)*(1.0/4294967296.0); 
    /* divided by 2^32 */
}

/* generates a random number on [0,1) with 53-bit resolution*/
double genrand_res53(void) 
{ 
    unsigned long a=genrand_int32()>>5, b=genrand_int32()>>6; 
    return(a*67108864.0+b)*(1.0/9007199254740992.0); 
} 
/* These real versions are due to Isaku Wada, 2002/01/09 added */

int fibonacci(int mois){
    int n0=0,n1=1;
    int cpt=2;
    int n_1,n_2,n;

    if(mois==0){
        return n0;
    }else if(mois==1){
        return n1;
    }else{
        n_1=n1;
        n_2=n0;

        printf("%d|%d",n0,n1);

        while(cpt<=mois){
            n=n_1+n_2;
            printf("|%d",n);
            n_2=n_1;
            n_1=n;

            cpt++;
        }

    }
    printf("\n");
    return n;
}

sexe_t choix_sexe(){
    float result;

    result=genrand_real2();
    if(result<0.5){
        return male;
    }else{
        return femelle;
    }
}


void creerLapin(int nb_lapin_adulte){
    int i;

    for(i=0;i<nb_lapin_adulte;i++){
        if(i%2==0){
            tab_lapins[nbLapin+i].sexe=0;
        }else{
            tab_lapins[nbLapin+i].sexe=1;
        }
        if(tab_lapins[nbLapin+i].sexe==male){
            tab_lapins[nbLapin+i].portee_restante=0;
        }else{
            tab_lapins[nbLapin+i].portee_restante=5+(8-5)*genrand_real2();
        }
        tab_lapins[nbLapin+i].age=12;
        tab_lapins[nbLapin+i].en_vie=vivant;
        tab_lapins[nbLapin+i].is_mature=1;

        printf("Lapin créé \n");
    }

    nbLapin+=nb_lapin_adulte;
}


void creerBebe(int nbBebe){
    int i;

    for(i=0;i<nbBebe;i++){
        tab_lapins[nbLapin+i].sexe=choix_sexe();
        if(
        tab_lapins[nbLapin+i].sexe==male){
            tab_lapins[nbLapin+i].portee_restante=0;
        }else{
            tab_lapins[nbLapin+i].portee_restante=5+(8-5)*genrand_real2();
        }
        tab_lapins[nbLapin+i].age=0;
        tab_lapins[nbLapin+i].en_vie=vivant;
        tab_lapins[nbLapin+i].is_mature=0;
        //printf("Lapin créé \n");
    }

    nbLapin+=nbBebe;
}


void simulation_maladie_predateur(){
    long i;
    float proba;

    for(i=0;i<nbLapin;i++){
        proba=genrand_real2();
        if(tab_lapins[i].age<12){
            if(proba<0.65){
                tab_lapins[i].en_vie=mort;
            }
        }else if(tab_lapins[i].age>12&&tab_lapins[i].age<120){
            if(proba<0.40){
                tab_lapins[i].en_vie=mort;
            }
        }else{
            if(proba<(0.40+((tab_lapins[i].age-120)/12*0.1))){
                tab_lapins[i].en_vie=mort;
            }
        }
    }
}

void procreer(int mois_en_cours){
    long i,j,h;
    float random;
    int trouve=0;
    int procree=0;

    mois_en_cours=mois_en_cours%12+1;
    
    for(long i=0;i<nbLapin;i++){
        if (tab_lapins[i].sexe==male&&tab_lapins[i].is_mature==1)
            {
                trouve=1;
                break;
            }
    }

    for(i=0;i<nbLapin;i++){

        if(tab_lapins[i].sexe==femelle&&tab_lapins[i].portee_restante>0&&procree!=1&&tab_lapins[i].is_mature==1){
            if(random<(tab_lapins[i].portee_restante/mois_en_cours)){
                h=i;
                procree=1;
            }
        }

        if(procree==1&&trouve==1){
            tab_lapins[h].portee_restante-=1;
            creerBebe(3+3*genrand_real2());
            procree=0;
        }
    }
}


void grandir(){
    long i;
    float random;

    for(i=0;i<nbLapin;i++){
        tab_lapins[i].age+=1;
        
        if(tab_lapins[i].is_mature==0){
            random=genrand_real2();
            if((tab_lapins[i].age==4&&random<0.25)||(tab_lapins[i].age==5&&random<0.50)||(tab_lapins[i].age==6&&random<0.75)||(tab_lapins[i].age==7)){
                tab_lapins[i].is_mature=1;
            }
        }

       /* if(tab_lapins[i].age==180){
            tab_lapins[i].en_vie=mort;
        }*/
    }
}

void viderLapinMort(){
    long i;

    for(i=0;i<nbLapin;i++){
        if(tab_lapins[i].en_vie==mort){
            decalerGauche(i);
            printf("Mort\n");
            nbLapin-=1;
        }
    }
}

void decalerGauche(int i){
    for(i;i<nbLapin;i++){
        tab_lapins[i]=tab_lapins[i+1];
    }
}

void tirages_nb_portee(){
    float random;

    random=genrand_real2();
    for(int i=0;i<nbLapin;i++){
        if(tab_lapins[i].sexe==femelle){
            if(random<0.125){
                tab_lapins[i].portee_restante=4;
            }else if(random<0.375){
                tab_lapins[i].portee_restante=5;
            }else if(random<0.625){
                tab_lapins[i].portee_restante=6;
            }else if(random<0.875){
                tab_lapins[i].portee_restante=7;
            }else{
                tab_lapins[i].portee_restante=8;
            }
        }
    }
}

void Simulation(int nb_mois,int nb_lapin_adulte){
    int cpt=0;
    nbLapin=0;
    creerLapin(nb_lapin_adulte);
    printf("Le lapin 1 est %d et le lapin 2 est %d\n",tab_lapins[0].sexe,tab_lapins[1].sexe);
    for(int i=0;i<=nb_mois;i++){
        if(i%12==0){
            tirages_nb_portee();
            //simulation_maladie_predateur();
            printf("Il y a %ld à la %d eme année\n",nbLapin,i/12);
        }
        //grandir();
        //viderLapinMort();
        procreer(i);

    }
    
}


/**
 * @brief       Cette fonction est la fonction main permettant de lancer nos différentes fonctions.
 * @details     Cette fonction va d'abord vérifier le nombre d'argument qui doit être de 2 (le nombre d'expériences et le nombre de tirages). Elle calcule aussi le temps qu'il aura fallu
 *              pour réaliser la fonction.
 * @param       On passe en paramètre les arguments du programme, qui contiendra le nombre d'expériences ainsi que le nombre de tirages.
 * @return      Cette fonction ne retourne rien mais affiche à la fin la durée de réalisation des fonctions appelées.
 * @author      Hugo DENIZOT
 * @date        2022
 */
int main(int argc, char const *argv[]){

    unsigned long init[4]={0x123, 0x234, 0x345, 0x456}, length=4;
    init_by_array(init, length);
    int result;
    int nb=144,nb2=2;

    //result=fibonacci(5);

    //printf("Le résultat est %d",result);

    Simulation(nb,nb2);
    
}

//Faire un time dans le rapport.
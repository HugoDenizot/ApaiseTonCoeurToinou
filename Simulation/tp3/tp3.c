/**
 * @file        tp3.c
 * @brief       Contient le code de toutes les fonctions permettant de mener à bien le tp3.
 * @details     Ce fichier contient toutes les fonctions permettant de réaliser des tirages aléatoires, ainsi que les fonctions nécessaires pour répondre aux questions du tp3.
 * @author      Hugo DENIZOT <hugo.denizot@etu.uca.fr>
 * @version     1.0
 * @date        2022
 * @copyright   GNU Public License.
 */


#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


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

/**
 * @brief       Cette fonction permet de calculer une valeur approximative de PI
 * @details     Dans cette fonction, nous allons tirés 2 doubles x et y, ce qui nous donnera les coordonnées d'un point. Si ce point est à l'intérieur du cercle de rayon 1
 *              alors on incrémente notre compteur de 1. On fait à la fin le ratio de notre compteur sur le nombre de lancer total multiplié par 4 (puisque cela ne représente qu'un quart de cercle).
 * @param       On passe en paramètre un long représentant le nombre de lancers que l'on souhaite réaliser.
 * @return      Le nombre retourné sera un double notre estimation de PI selon le nombre de lancers réalisé.
 * @author      Hugo DENIZOT
 * @date        2022
 */
double simPi(long n){

    double m=0;
    long i;
    double x;
    double y;

    for(i=0;i<n;i++){

        x=genrand_real2();
        y=genrand_real2();

        if(pow(x,2)+pow(y,2)<1)
            m+=1;

    }

    //printf("Pour %d tirages :%lf\n",n,4*m/(float)n);

    return 4*m/n;

}

/**
 * @brief       Cette fonction permet de calculer une valeur approximative de PI selon une moyenne
 * @details     Dans cette fonction, nous allons reprendre la fonction réalisée précédemment mais afin de réaliser cette fois-ci une estimation plus précise à l'aide d'une moyenne.
 *              On va donc réaliser plusieurs fois l'expérience de la question 1, et prendre la moyenne de tout nos résultats et choisir cette moyenne comme notre estimation de PI.
 * @param       On passe en paramètre un long n représentant le nombre de lancers que l'on souhaite réaliser, ainsi qu'un deuxième long nbExp représentant le nombre d'expériences
 *              que l'on souhaite réaliser.
 * @return      Cette fonction ne retourne rien mais affiche à la fin la moyenne avec le nombre d'expériences réalisées, ainsi que l'erreur absolue et relative selon la valeur de PI donné
 *              par la librairie math.c.
 * @author      Hugo DENIZOT
 * @date        2022
 */
void question2(long nbExp,long n){
    double moy=0;

    for(int i=0;i<nbExp;i++){

        moy+=simPi(n);


    }

    printf("La moyenne pour %d expériences est de %f\n",nbExp,moy/nbExp);

    double err_abs=M_PI-(moy/nbExp);
    printf("Erreur absolue : %f \n",err_abs);

    double err_rel=(moy/nbExp)/M_PI;
    printf("Erreur relative :%f \n",err_rel);

}

/**
 * @brief       Cette fonction permet de calculer un intervalle de confiance pour notre valeur de PI.
 * @details     Dans cette fonction, nous allons reprendre le principe utilisé dans la fonction de la question 2, en recalculant une moyenne mais cette fois ci en gardant toutes les
 *              valeurs de PI dans un tableau. Grâce à ça on va calculer une estimation sans biais. Enfin grâce à un tableau de valeur déjà défini on va donc pouvoir calculer notre 
 *              rayon de confiance à la moyenne.
 * @param       On passe en paramètre un long n représentant le nombre de lancers que l'on souhaite réaliser, ainsi qu'un deuxième long nbExp représentant le nombre d'expériences
 *              que l'on souhaite réaliser.
 * @return      Cette fonction ne retourne rien mais affiche à la fin l'intervalle de confiance de la moyenne comprenant toutes les valeurs de PI que nous acceptons.
 * @author      Hugo DENIZOT
 * @date        2022
 */
void question3(long nbExp, long n){
    
    double moy=0;
    double Xi[nbExp];
    double S=0;
    double val;
    int i;

    double t05[30]={12.706,4.303,3.182,2.776,2.571,5.447,2.365,2.308,2.262,2.228,
        2.201,2.179,2.160,2.145,2.131,2.120,2.110,2.101,2.093,2.086,2.080,2.074,
        2.069,2.064,2.060,2.056,2.052,2.048,2.045,2.042};
    double R;
    double t;

    for(i=0;i<nbExp;i++){

        val=simPi(n);
        Xi[i]=val;
        moy+=val;

    }

    moy=moy/nbExp;

    for(i=0;i<nbExp;i++){

        S+=pow(Xi[i]-moy,2);

    }

    S=S/(nbExp-1);

    //printf("moy: %f\n", moy);
    //printf("Liste des Xi :\n");


    //for(i=0;i<nbExp;i++)
    //    printf("\t %d:%f\n",i,Xi[i]);


    //printf("%f\n",S);

    if(nbExp<=30){
        t=t05[nbExp-1];
    }else if(nbExp<40){
        t=2.042;
    }else if(nbExp<80){
        t=2.021;
    }else if(nbExp<120){
        t=2.000;
    }else if(nbExp<9999){
        t=1.980;
    }else{
        t=1.96;
    }


    R=t*sqrt((S/nbExp));
    //printf("R: %f\n",R);

    printf("L'intervalle de confiance est [%f,%f]\n",(moy)-R,(moy)+R);
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
    time_t temps_avant, temps_apres;
    unsigned long secondes;

    if(argc!=3){
        printf("Il faut 2 arguments pour lancer le programme.\n");
    }else{
        temps_avant=time(NULL);

        // for(int i=10000;i<=10000000000;i=i*10)
            //     simPi(i);
    
        //question2(10,1000000);
        question3(atoi(argv[1]),atoi(argv[2]));

        temps_apres=time(NULL);
        secondes=(unsigned long) difftime(temps_apres, temps_avant);

        printf("La fonction s'est exécutés en %ld",secondes);
    }

    
}

//Faire un time dans le rapport.
#include "fonc.h"




 void remplirGraf(t_graphe &graf) {
	graf.n = 10;
	graf.ns[1] = 2;
	graf.ns[2] = 2;
	graf.ns[3] = 2;
	graf.ns[4] = 1;
	graf.ns[5] = 2;
	graf.ns[6] = 1;
	graf.ns[7] = 2;
	graf.ns[8] = 1;
	graf.ns[9] = 0;


	graf.d[1][1] = 10;
	graf.d[1][2] = 4;
	graf.d[2][1] = 1;
	graf.d[2][2] = 2;
	graf.d[3][1] = 4;
	graf.d[3][2] = 2;
	graf.d[4][1] = 12;
	graf.d[5][1] = 9;
	graf.d[5][2] = 3;
	graf.d[6][1] = 5;
	graf.d[7][1] = 3;
	graf.d[7][2] = 3;
	graf.d[8][1] = 3;



	graf.s[1][1] = 2;
	graf.s[1][2] = 4;
	graf.s[2][1] = 3;
	graf.s[2][2] = 5;
	graf.s[3][1] = 6;
	graf.s[3][2] = 8;
	graf.s[4][1] = 6;
	graf.s[5][1] = 3;
	graf.s[5][2] = 8;
	graf.s[6][1] = 7;
	graf.s[7][1] = 8;
	graf.s[7][2] = 9;
	graf.s[8][1] = 9;

}




 void dijktra(t_graphe graf, t_solution &solu, int deb,int fin) {


	 int t[10];
	 int m[10];
	 int so;
	 int jmin;

	 for (int i = 1; i < graf.n; i++) {

		 m[i] = infini;
		 t[i] = 0;
		 solu.pere[i] = -1;
	 }
	 m[deb] = 0;

	 for (int i = 1; i < graf.n; i++) {
	 
		 jmin = -1;
		 int valmin = infini;
		 for (int j = 0; j < graf.n; j++) {
			 if (m[j] < valmin && t[j] == 0) {
				 jmin = j;
				 valmin = m[j];
			 }
		 }
		 for (int k = 1; k < graf.ns[jmin];k++) {

			 so = graf.s[jmin][k];
			 if (m[jmin] + graf.d[jmin][so] < m[so]) {

				 m[so] = m[jmin] + graf.d[jmin][so];
				 solu.pere[so] = jmin;
			 }
		 }
		 t[jmin] = 1;
	 }
	 
 }

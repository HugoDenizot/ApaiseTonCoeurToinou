#include <iostream>
#include <string>
#include <unistd.h>
#include "Map.hpp"
#include "Personne.hpp"
#include "Position.hpp"
#include "Visiteur.hpp"
#include "Douanier.hpp"
#include "Random_MT.hpp"
#include "ZoneEmbarquement.hpp"
#include "ZoneBagage.hpp"
#include "Boutique.hpp"

using std::endl;
using std::cout;

Map m{};

int main(int, char **) {

    unsigned long         init[4]={0x123, 0x234, 0x345, 0x456},
                          length=4;

  Random_MT::init_by_array(init, length);

  Visiteur pers1(Position(0,0),80);
  Visiteur pers2(Position(0,15),80);
  Visiteur pers3(Position(0,9),80);
  Douanier persd(Position(2,0));
  Douanier persf(Position(10,10));

  ZoneEmbarquement ze1(100,"zonne emba 1",Position(15,19));
  ZoneEmbarquement ze2(100,"zonne emba 2",Position(17,19));
  ZoneBagage zb1(Position(2,19));
  ZoneBagage zb2(Position(4,19));
  Boutique b1(100,"boutique 1",Position(12,8));
  Boutique b2(100,"boutique 2",Position(12,13));
  Boutique b3(100,"boutique 3",Position(7,7));
  m.ajouterPers(&pers1);
  m.ajouterPers(&pers2);
  m.ajouterPers(&pers3);
  m.ajouterPers(&persf);
  m.ajouterPers(&persd);

  int temps = 0;
  int result;
  int test;
  Position info[9];


  while (temps < 70)
  {
    
    for(int i=0;i<m.nbpersonne;i++){
      result=m.tabpers[i]->Action();
      if(result==1){
        
        m.deletePers(m.tabpers[i]);
      }
    }
    system("clear");
    m.AfficherMap();

    temps++;
    sleep(1);
  }

  return 0;
  
}
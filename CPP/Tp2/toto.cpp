#include "catch.hpp"
#include "FilRouge.hpp"


Point ORIGINE{0,0};

TEST_CASE("Cercle", "[Cercle]") {
   int compteur = Forme::prochainId();
   Cercle c1;
   Cercle c2(0,0,3,3); 
   
   REQUIRE(c1.toString() == "CERCLE 0 0 1 1");
   REQUIRE(c2.toString() == "CERCLE 0 0 3 3");

   c2.setRayon(1);
   REQUIRE(c2.getRayon()   == 1  );
   REQUIRE(c2.toString()   == "CERCLE 0 0 2 2");
   REQUIRE(c2.getLargeur() == 2);
   REQUIRE(c2.getHauteur() == 2);  

   REQUIRE(Forme::prochainId() == (compteur+2) ); 
}
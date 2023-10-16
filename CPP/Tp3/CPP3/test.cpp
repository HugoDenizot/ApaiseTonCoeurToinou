#include "catch.hpp"
#include "producteur.hpp"

TEST_CASE("Producteur_Initialisation") {
  Producteur p;
  REQUIRE( p.getTravail() == 0);
}
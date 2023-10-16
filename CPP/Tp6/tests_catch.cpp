#include "catch.hpp"
#include <cstring>
#include <sstream> // a mettre en commentaire 
#include "Pile.hpp"
#include "Vecteur.hpp"

/*
TEST_CASE("Constructeur par defaut") {
   Pile p; // cela implique que par defaut la capacite de la pile n'est pas nulle => pas d exception
   
   CHECK(  p.empty() );
   CHECK(  0 == p.size() );
}*/
/*
// A faire quand on aura vu les exceptions
TEST_CASE("Exceptions de mauvaise construction") {

   REQUIRE_THROWS_AS( Pile(-1).empty(), std::invalid_argument );
   REQUIRE_THROWS_AS( Pile( 0).empty(), std::invalid_argument );
   
}

// A faire quand on aura vu les exceptions
TEST_CASE("Exception pile vide") {

   REQUIRE_THROWS_AS( Pile().pop(), std::invalid_argument );
   
}*/
/*
TEST_CASE("Live pile") {
    Pile p(10);

    CHECK(  p.empty() );
    CHECK(  0 == p.size() );

    p.push(5);

    CHECK( !p.empty() );
    CHECK( 1 == p.size() );
    CHECK( 5 == p.top() );

    p.push(2);
    p.push(1);

    CHECK( 3 == p.size() );
    CHECK( 1 == p.top() );

    p.pop();

    CHECK( 2 == p.size() );
    CHECK( 2 == p.top() );

    p.pop();
    p.pop();

    CHECK( 0 == p.size() );

}*/
/*
TEST_CASE ("Vecteur1") {
  const Vecteur v;
 
  REQUIRE ( v.capacity() >= 10 );
  REQUIRE ( v.size()     == 0  );

}


TEST_CASE ("Vecteur2" ) {
  Vecteur v(20);
 
  REQUIRE ( v.capacity() == 20 );
  REQUIRE ( v.size()     == 0  );
}*/

TEST_CASE ("Vecteur3" ) {
  Vecteur v(5);
 
/*  SECTION("ajout de quelques elements") {
    REQUIRE ( v.capacity() == 5 );

    for (int i=0; i<4; ++i)
      v.push_back(i*1.0);

    REQUIRE ( v.size()     == 4  );
  }

  SECTION("tableau un peu agrandi") {
    // on peut verifier que vecteur est bien un nouveau :-) 
  REQUIRE ( v.capacity() == 5 );
    for (int i=0; i<6; ++i)
      v.push_back(i*1.0);

    REQUIRE ( v.capacity()  == 10 );
    REQUIRE ( v.size()      == 6  );
  }
  
  SECTION("on verifie les valeurs dans le vecteur") {
    for (int i=0; i<25; ++i)
      v.push_back(i*1.0);

    REQUIRE( v.capacity() ==  40 );
    REQUIRE( v.size()     ==  25 );
    
    for (int i=0; i<25; ++i)
      CHECK(v[i] == Approx(i*1.0));  // :-)

  }*/

  SECTION("on verifie les exceptions") {
    REQUIRE_THROWS_AS( v[-1] == 0, Vecteur::OutOfRangeException); 
    REQUIRE_THROWS_AS( v [6] == 0, std::bad_alloc);  // :-)
  }
 
}

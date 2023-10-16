#include "catch.hpp"
#include "Cercle.hpp"
#include "Rectangle.hpp"
#include "Groupe.hpp"
#include <sstream>
using std::cout;
using std::endl;
using std::string;


Point ORIGINE{0,0};

// TEST_CASE("Polymorphisme", "[Forme]") {
//    Forme * f1 = new Cercle;
//    Forme * f2 = new Rectangle;

//    REQUIRE(f2->toString() == "RECTANGLE 0 0 1 1");
//    REQUIRE(f1->toString() == "CERCLE 0 0 1 1");

//    delete f1;
//    delete f2;
// }

TEST_CASE("aaaa", "[Forme]") {
   Groupe g;
   Rectangle *r=new Rectangle{0,0,1,1};
   Rectangle *r1=new Rectangle{0,0,2,2};
   Cercle *c=new Cercle{0,0,1,1};
   g.addForme(r);
   g.addForme(r1);
   g.addForme(c);
   REQUIRE(g.toString() == "GROUPE 0 0 0 0 RECTANGLE 0 0 1 1\nRECTANGLE 0 0 2 2\nCERCLE 0 0 1 1\n");
   delete r;
   delete r1;
   delete c;
}
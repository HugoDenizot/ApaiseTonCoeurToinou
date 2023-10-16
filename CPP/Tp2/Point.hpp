#include <iostream>  // Inclusion d'un fichier standard

using std::cout;
using std::endl;
class Point {
   // par défaut, tout est privé dans une "class"  
   int x;
   int y;
   static int compteur;
   
 private:
  int test;

 public:
  Point();
  Point(int a, int b);
  int getX();
  void setX(int a); 
  int getY();
  void setY(int a);
  void DeplacerDe(Point p);
  void DeplacerVers(Point p);
  static int getCompteur();
  int getTest();

 private:
  void setTest(int a);

};
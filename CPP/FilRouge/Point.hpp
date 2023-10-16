#ifndef _POINT
#define _POINT

#include <iostream>

class Point{
  int x;
  int y;

  public:
    Point(int i, int j);
    Point();
    int getX();
    int getY();
    void setX(int i);
    void setY(int i);
};

#endif
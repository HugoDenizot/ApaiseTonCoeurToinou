#include "Point.hpp"
#include <sstream>
using std::cout;
using std::endl;
using std::string;

Point::Point(int i, int j):x{i},y{j}{

}

Point::Point():x{0},y{0}{

}

int Point::getX(){
    return x;
}

int Point::getY(){
    return y;
}

void Point::setX(int i){
    x=i;
}

void Point::setY(int i){
    y=i;
}
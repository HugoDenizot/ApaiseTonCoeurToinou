#ifndef __CPP3_PRODUCTEUR_HPP__
#define __CPP3_PRODUCTEUR_HPP__

#include <iostream>

class Producteur {
    int static travail;

    public:
        void produire();
        int getTravail();

};

int travail=0;

#endif

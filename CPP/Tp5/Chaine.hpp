#ifndef CPP5__CHAINE_HPP
#define CPP5__CHAINE_HPP

#include <iostream>
#include <fstream>
#include <exception>

class Chaine  {
    public:
        int capacite;
        char* tab;
        class OutOfRangeException{};

    public:
        Chaine();
        Chaine(const char* inCs);
        Chaine(const int inCapacite);
        Chaine(const Chaine &uC);
        Chaine& operator=(const Chaine &uc);
        char& at(int index);
        //char const & operator[](int index);
        char &  operator[](int index);
        int getCapacite() const;
        char* c_str() const;
        const char* toCstr() const;
        void afficher() const;
        void afficher(std::ostream &o) const;
        ~Chaine();
};

Chaine operator+(const Chaine &a,const Chaine &b);

class null_pointer:public std::logic_error{
    public:
        null_pointer(char const * what):std::logic_error(what){}
        null_pointer():null_pointer("Pas de pointeur"){}
};
std::ostream& operator<<(std::ostream &o, const Chaine &c);
//std::ostream& operator<<(const Chaine &c);
#endif

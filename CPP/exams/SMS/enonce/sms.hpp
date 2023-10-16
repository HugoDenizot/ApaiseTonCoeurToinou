#ifndef __SMS
#define __SMS
#include <string>

class Telephone{
    public:
        std::string numero;
        Telephone(std::string numero);
        Telephone();
        std::string getNumero() const;
        void setNumero(std::string numero);
};

class Reseau{
    public:
        Telephone *tel[20];
        int nbTel;
        Reseau();
        std::string lister();
        void ajouter(std::string t);
        Telephone trouveTel(std::string num);
};

#endif
#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::string;
using std::endl;

/*int main(int, char **) {  // parametres muets
  string prenom;     // type chaines de caracteres"
  string nom;
  int age;

  cout << "Quel est votre prénom ?" << endl;
  cin  >> prenom;
  cout << "Quel est votre age ?" << endl;
  cin  >> age ;
  cout << "Quel est votre nom ?" << endl;
  cin  >> nom ;
  cout << "Bonjour "<< prenom << ":" << nom << endl;

  return 0;
}*/

/*int main(int, char **) {  // parametres muets
  string chaine_1;     // type chaines de caracteres"
  string chaine_2;

  cout << "Quel est votre premier mot ?" << endl;
  cin  >> chaine_1;
  cout << "Quel est votre deuxieme mot ?" << endl;
  cin  >> chaine_2 ;

  if(chaine_1<chaine_2)
  {
    cout << chaine_1 << " est plus petit lexicographiquement que " << chaine_2 << endl;
    cout << "Et sa taille est de "<< chaine_1.size() << endl;
  }
  else
  {
    cout << chaine_2 << " est plus petit lexicographiquement que " << chaine_1 << endl;
    cout << "Et sa taille est de "<< chaine_2.size() << endl;
  }

  return 0;
}*/

/* on peut utiliser le mot clé const pour définir la taille d'un tableau statique en C++ */
/* Jamais de #define pour cela */
/*const int TAILLE = 10;

int main(int, char **) {
  int tab[TAILLE];
  
  for (int i=0; i < TAILLE; ++i) {
    tab[i] = i %2;
    cout << tab[i] << " ";
  }

  cout << endl;

  return TAILLE;
}*/

/*int main() {

  char s[10];
  // std::string s;
  // char *      s;

  std::cin >> s;

  std::cout << "#" << s << "#" << std::endl;
  for (int i = 0; s[i]!='\0' ; ++i)
    std::cout << "@" << s[i] << "@" << (int)s[i] << "@" << std::endl;

  return 0;
}*/



/*int main(int, char**){
  int  a = 5;
  int &r = a;

  std::cin  >> r;
  std::cout << a;
}*/

/*void fonction1(int a) {
  std::cout << &a << std::endl;
}

void fonction2(int& a) {
  std::cout << &a << std::endl;
}

int main(int, char **) {
  int age = 45;

  std::cout << &age << std::endl;
  fonction1(age);
  fonction2(age);

  return 0;
}*/

/*void swapRef(int& a, int& b){
  int c=a;
  a=b;
  b=c;
}

void swapPoint(int* a, int* b){
  int c=*a;
  *a=*b;
  *b=c;
}

int main(int, char **) {
  int  a = 3;
  int  b = 5;
  int& c = a;


  std::cout << a << " " << b << " " << c << std::endl;
  swapRef(a,b);
  std::cout << a << " " << b << " " << c << std::endl;
  swapPoint(&a,&b);
  std::cout << a << " " << b << " " << c << std::endl;
  swapRef(a,c);
  c=6;
  std::cout << a << " " << b << " " << c << std::endl;
}
*/

/*int main(int, char **) {
   const int TAILLE = 500;

   int * p = new int[TAILLE];

   for(auto i = 0; i< TAILLE; ++i ) p[i] = i;
   for(auto i = 0; i< TAILLE; ++i ) cout << p[i] << endl;

   delete p;      
   //delete [] p;

   return 0;
}*/

int main(int, char **) {
   std::string   s1;
  std::string   s2("chaine 2");
  std::string   s3 = "chaine 3";
  getline(cin, s3);
  cout<<s3<<endl;
}
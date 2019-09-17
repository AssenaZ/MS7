#ifndef REQUETEOWN_H
#define REQUETEOWN_H
#include <string>
#include <iostream>

using namespace std;

class RequeteOWN
{
private:
    string ville;
    string pays;
    string cle;


public:
    RequeteOWN();
    inline void ModifierVille(string Uneville) {ville = Uneville;}
    inline void ModifierPays(string Unpays) {pays = Unpays;}
    ~RequeteOWN();
    string creerRequeteOWN();
    string previsionsRequeteOWN();

};

#endif // REQUETEOWN_H

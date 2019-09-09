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
    void ModifierVille(string Uneville);
    void ModifierPays(string Unpays);
    ~RequeteOWN();
    string creerRequeteOWN();

};

#endif // REQUETEOWN_H

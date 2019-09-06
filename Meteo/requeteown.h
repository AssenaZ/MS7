#ifndef REQUETEOWN_H
#define REQUETEOWN_H
#include <string>

using namespace std;

class RequeteOWN
{
private:
    string ville;
    string pays;
    string cle;
public:
    RequeteOWN();
    void ModifierVille(string ville);
    void ModifierPays(string pays);
    ~RequeteOWN();

};

#endif // REQUETEOWN_H

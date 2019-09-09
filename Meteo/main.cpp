#include <QCoreApplication>
#include "requeteown.h"
#include <iostream>
#include <string>

using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

string pays;
string ville;

    RequeteOWN requete;

    cout<< "Pays ?"<<endl;
    cin>> pays;
    requete.ModifierPays(pays);


    cout<< "Ville ?"<<endl;
    cin>> ville;
    requete.ModifierVille(ville);

    string req = requete.creerRequeteOWN();
    cout<<req;

    return a.exec();
}


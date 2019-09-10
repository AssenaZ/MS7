#include <QCoreApplication>
#include "requeteown.h"
#include "meteoown.h"
#include "SNClientHTTP.h"

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

string pays;
string ville;
string v;
string p;

    //RequeteOWN requete;

    cout<< "Pays ?"<<endl;
    cin>> pays;
    //requete.ModifierPays(pays);


    cout<< "Ville ?"<<endl;
    cin>> ville;
    //requete.ModifierVille(ville);

    /*string req = requete.creerRequeteOWN();
    cout<<req;

    SNClientHTTP clientOWN;

    clientOWN.connexionAuServeurParNomDeDomaine("api.openweathermap.org",80);
    clientOWN.envoyer(req);
    clientOWN.recevoir();
    cout<<clientOWN.CorpsReponse();

    ofstream MeteoCourante;
    MeteoCourante.open("Meteo.xml");
    MeteoCourante<< clientOWN.CorpsReponse();
    MeteoCourante.close();*/

    meteoOWN meteo;
    meteo.rechercher(ville,pays);


    return a.exec();
}


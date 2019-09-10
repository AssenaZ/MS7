#include "meteoown.h"
#include "requeteown.h"
#include "SNClientHTTP.h"


#include <iostream>
#include <fstream>
#include <string>

meteoOWN::meteoOWN()
{

}

void meteoOWN::rechercher(string v, string p)
{
    RequeteOWN requete;

    //cout<< "Pays ?"<<endl;
    //cin>> pays;
    requete.ModifierPays(p);


    //cout<< "Ville ?"<<endl;
    //cin>> ville;
    requete.ModifierVille(v);

    string req = requete.creerRequeteOWN();
    cout<<req;

    SNClientHTTP clientOWN;

    clientOWN.connexionAuServeurParNomDeDomaine("api.openweathermap.org",80);
    clientOWN.envoyer(req);
    clientOWN.recevoir();
    cout<<clientOWN.CorpsReponse();

    ofstream MeteoCourante;
    MeteoCourante.open("Meteo.xml");
    MeteoCourante<< clientOWN.CorpsReponse();
    MeteoCourante.close();
}

#include "meteoown.h"



#include <iostream>
#include <fstream>
#include <string>
using namespace std;

meteoOWN::meteoOWN()
{

}

void meteoOWN::rechercher(string v, string p)
{
    RequeteOWN requete;

    requete.ModifierPays(p);
    requete.ModifierVille(v);

    string req = requete.creerRequeteOWN();
    cout<<req;

    SNClientHTTP clientOWN;

    clientOWN.connexionAuServeurParNomDeDomaine("api.openweathermap.org",80);
    clientOWN.envoyer(req);
    clientOWN.recevoir();
    reponseXML = clientOWN.CorpsReponse();
    //cout<<reponseXML;

    ofstream MeteoCourante;
    MeteoCourante.open("Meteo.xml");
    MeteoCourante<< reponseXML;
    MeteoCourante.close();

    /*string balise;
    cout<<"First balise: "<<endl;
    cin>>balise;

    string balise2;
    cout<<"Second parameter : "<<endl;
    cin>>balise2;*/

    string reponse = extraireContenuEntreBalises("temperature", "value",0);
    //string reponse2 = extraireContenuEntreBalises("speed", "value",0);
    cout<<reponse;
    //cout<<reponse2;




  /*actuellement.temperature = extraireContenuEntreBalises("temperature","value",0);
  actuellement.vitesseVent = extraireContenuEntreBalises("speed","value",0);*/

}

string meteoOWN::extraireContenuEntreBalises(string balise,string balise2 ,int positionDepart)
{

    int positionDepartBalise = reponseXML.find(balise,positionDepart);
    int positionFinaleBalise = reponseXML.find("</"+balise+">",positionDepartBalise);
    string chaineFinale = reponseXML.substr(positionDepartBalise+balise.length(),positionFinaleBalise-positionDepartBalise-balise.length()-1);


   int positionDepartBalise2 = reponseXML.find(balise2,positionDepartBalise);
   int positionFinaleBalise2 = reponseXML.find("\"",positionDepartBalise2+balise2.length()+1+1);
   string chaineFinale2 = reponseXML.substr(positionDepartBalise2+balise2.length()+1+1,positionFinaleBalise2-positionDepartBalise2-balise2.length()-1-1);
   return chaineFinale2;


}


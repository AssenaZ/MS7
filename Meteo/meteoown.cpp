#include "meteoown.h"

#include <sstream>

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

    string req;
    req = requete.previsionsRequeteOWN();
    //cout<<req;

    SNClientHTTP clientOWN;


    clientOWN.connexionAuServeurParNomDeDomaine("api.openweathermap.org",80);
    clientOWN.envoyer(req);
    clientOWN.recevoir();

    ofstream MeteoCourante;
    MeteoCourante.open("PrevisionsMeteo.xml");
    MeteoCourante<< reponseXML;
    MeteoCourante.close();

    // saisi des balises souhaitées
    /*string balise;
    cout<<"First balise: "<<endl;
    cin>>balise;
    string balise2;
    cout<<"Second parameter : "<<endl;
    cin>>balise2;*/

    /*string reponse = extraireContenuEntreBalises("temperature", "value",0);
    string reponse2 = extraireContenuEntreBalises("speed", "value",0);
    cout<<reponse<<endl;
    cout<<reponse2<<endl;*/

  /*istringstream(extraireContenuEntreBalises("temperature","value",0)) >>  actuellement.temperature;
  istringstream(extraireContenuEntreBalises("temperature","max",0)) >>  actuellement.temperatureMax;
  istringstream(extraireContenuEntreBalises("temperature","min",0)) >>  actuellement.temperatureMin;
*/
 // istringstream(extraireContenuEntreBalises("windSpeed","mps",0)) >>  actuellement.vitesseVent;




  //-----------------------------------previsions---------------------------------------


   /* if (clientOWN.LongueurCorpsReponse() > 0)
    { cout << "OK" << endl;
    reponseXML = clientOWN.CorpsReponse();
    }
    else {"error";}
*/
   pos = reponseXML.find("time");

  for(int i=0; i<4; i++)
  {
      //cout<<pos<<endl;
      istringstream(extraireContenuEntreBalises("temperature","value",pos)) >>  previsions[i].temperature;
      istringstream(extraireContenuEntreBalises("temperature","max",pos)) >>  previsions[i].temperatureMax;
      istringstream(extraireContenuEntreBalises("temperature","min",pos)) >>  previsions[i].temperatureMin;
    // istringstream(extraireContenuEntreBalises("windSpeed","mps",0)) >>  actuellement.vitesseVent;

  pos = reponseXML.find("time",pos+1);

  }


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

ConditionsActuelles meteoOWN::Actuellement()
{
    return actuellement;
}

ConditionsAVenir meteoOWN::Previsions(int indice)
{
   return previsions[indice];
}


















#include <iostream>
#include <sstream>
#include <fstream>

#include "personaje.h"
#include "animal.h"
#include "objeto.h"
#include "puntos.h"
#include "enemigo.h"
#include "jugador.h"
#include "miembrotec.h"
#include "escenario.h"
#include "rpg.h"

using namespace std;
using namespace listasrpg;

void static Interactuar(Animal* gato);
void static Obtener(Objeto* objt);

int main(int argc, char* argv[])
{

  /*//Manejo de Personajes y objetos
  Animal gato(GATO);
  gato.getDescripcion();
  Interactuar(&gato);
  gato.getDescripcion();
  Puntos pt = gato.Atacar();
  pt.getPropiedades();
  gato.DamageReceived(&pt);
  gato.getDescripcion();

  //Arreglos de objetos para apuntar a un objeto existente
  Objeto *objt_dos = new Objeto("M","m");
  Objeto *arrObj[2];
  arrObj[0]=objt_dos;
  cout<<arrObj[0]->getNombre()<<endl<<endl;

  //Mandar un objeto para manipularlo en una funcion
  Objeto objt2("R","r");
  cout<<objt2.getNombre()<<endl;
  Obtener(&objt2);
  cout<<objt2.getNombre()<<endl;*/

  //////////////////////////////////////////////////////////

  /*//Apertura de Archivos
  string line;
  ifstream myFile;//objeto ifstream
  vector<string> tokens;
  myFile.open("creditos.txt");//Abre el archivo
  if (myFile.is_open()) 
  {
    while(!myFile.eof())
    {
      getline(myFile,line);
      cout<<line<<endl;
    }
  }
  else{cout<<"ERROR";}
  myFile.close();
  myFile.open("archivo_de_juego.csv");
  tokens = split(line, ',');
  if (myFile.is_open())
  {
    for (int i=0;i<3;i++)
    {
      getline(myFile, line);
      tokens = split(line, ',');
      cout<<tokens[0]<<endl;
    }
  }
  myFile.close();*/

  /////////////////////////////////////////////////////////

  /*//Sacar los datos de un Personaje por medio de un archivo
  //Este ejemplo funciona al leer un archivo con una línea con los parametros de un Personaje divididos con comas
  string line;
  ifstream myFile;//objeto ifstream
  vector<string> tokens;//Donde se van a guardar los elementos de las líneas
  Personaje *per;
  myFile.open("archivo_de_juego.csv");//Abre el archivo
  if (myFile.is_open())//Comprueba que está abierto el archivo
  {
    getline(myFile,line);
		tokens = split(line, ',');
		switch(stoi(tokens[0]))
    {
      case 1: 
      {
        Especie especie = static_cast<Especie>(stoi(tokens[1]));
        per = new Animal(especie);
        break;
      }
      case 2: 
      {
        TipoEnemigo enemy = static_cast<TipoEnemigo>(stoi(tokens[1]));
        per = new Enemigo(enemy);
        break;
      }
      case 3: 
      {
        cout<<(tokens[1])<<endl;
        AreaTec area = static_cast<AreaTec>(stoi(tokens[1]));
        per = new MiembroTec(tokens[2],tokens[3],area,tokens[4]);
        break;
      }
    }
  }
  else
  {
    cout<<"Error"<<endl;
  }
  per->Huir();*/

  /////////////////////////////////////////////////////////

  /*//Sacar los datos de un Objeto por medio de un archivo
  string line;
  //Este ejemplo funciona al leer un archivo con una línea con los parametros de un Objeto divididos con comas
  ifstream myFile;//objeto ifstream
  vector<string> tokens;//Donde se van a guardar los elementos de las líneas
  Objeto *objt;
  myFile.open("archivo_de_juego.csv");//Abre el archivo
  if (myFile.is_open())//Comprueba que está abierto el archivo
  {
    TipoPuntos tipoP;
    getline(myFile,line);
		tokens = split(line, ',');
    tipoP = static_cast<TipoPuntos>(stoi(tokens[0]));
    objt = new Objeto(tokens[1],tokens[2],tipoP,stof(tokens[3]));
  }
  else
  {
    cout<<"Error"<<endl;
  }
  objt->getPropiedades();*/
  
  ////////////////////////////////////////////////////////

  //Sacar los datos de un Escenario por medio de un archivo


  return 0;
}

void static Interactuar(Animal* gato)
{
  Puntos pt(HEALTH,10);
  pt.setUso("disminuir");
  gato->setSalud(&pt);
}

void static Obtener(Objeto* objt)
{
  objt->setNombre("Romeo");
}
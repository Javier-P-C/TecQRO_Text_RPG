/*-----------------------------------------
          Instrucciones archivos
-------------------------------------------
*Los enum tipoAlgo los puedes encontrar en el archivo rpg.h
-Declarar Personajes:
  Animales: int_tipoPersonaje,int_enum_tipoAnimal
  Enemigo: char_tipoPersonaje,int_enum_tipoEnemigo
  Miembro Tec: char_tipoPersonaje,int_enum_AreaTec,string_nombre,string_matricula,string_posicion
-Declarar Objetos:
  Objeto: int_tipoPuntos,string_nombre,string descripcion,float_cantPuntos
  +Antes del objeto debes especificar el nombre del escenario donde se va a cargar y el número de objetos que hay declarados. Ambas cosas separadas por comas.
-Declarar Escenarios:
  Escenario: string_nombre!string_descripcion
*/

#include <iostream>
#include <sstream>
#include <fstream>

#include "utility.h"

#include "personaje.h"
#include "animal.h"
#include "objeto.h"
#include "puntos.h"
#include "enemigo.h"
#include "jugador.h"
#include "miembrotec.h"
#include "escenario.h"
#include "engine.h"
#include "rpg.h"


using namespace std;
using namespace listasrpg;

int main(int argc, char* argv[])
{
  Engine partida("carga_de_escenarios.csv","carga_de_objetos.csv");
  
  

  /*string line;
  int cont = 0;
  ifstream myFile;//objeto ifstream
  vector<string> tokens;//Donde se van a guardar los elementos de las líneas
  Escenario *scene[2];
  myFile.open("archivo_de_juego.csv");//Abre el archivo
  if (myFile.is_open())//Comprueba que está abierto el archivo
  {
    getline(myFile,line);
    tokens = split(line, '!');
    cont = stoi(tokens[0]);
    for(int i=0;i<cont;i++)
    {
      getline(myFile,line);
      tokens = split(line, '!');
      cout<<"Llegue"<<endl;
      scene[i] = new Escenario(tokens[0],tokens[1]);
      cout<<scene[i]->getNombre()<<endl;
    }
  }
  else
  {
    cout<<"Error"<<endl;
  }
  myFile.close();
  for (int i=0;i<cont;i++)
  {
    cout<<scene[i]->getNombre()<<", "<<scene[i]->getDescripcion()<<endl<<endl;
  }
  scene[0]->getObjetos();
  scene[0]->getPersonajes();
  scene[1]->getObjetos();
  scene[1]->getPersonajes();

  myFile.open("carga_de_objetos.csv");
  if (myFile.is_open())//Comprueba que está abierto el archivo
  {
    bool encontrado = false;
    while((tokens[0]!=scene[0]->getNombre()) && !myFile.eof())
    {
      getline(myFile,line);
      tokens = split(line, ',');
      if (tokens[0]==scene[0]->getNombre())
      {
        encontrado = true;
      }
      cout<<tokens[0]<<endl;
    }

    if (encontrado == false)
    {
      cout<<endl<<"ERROR: Nombre de escenario no encontrado en archivo para carga de objetos"<<endl<<endl;
      goto exit;
    }
    cont = stoi(tokens[1]);
    for (int i=0;i<cont;i++)
    {
      TipoPuntos tipoP;
      Objeto *objeto;
      getline(myFile,line);
      tokens = split(line, ',');
      tipoP = static_cast<TipoPuntos>(stoi(tokens[0]));
      cout<<"Llegue"<<endl;
      objeto = new Objeto(tokens[1],tokens[2],tipoP,stof(tokens[3]));
      scene[0]->AgregarObjetos(objeto);
    }
  }
  else
  {
    cout<<"Error"<<endl;
  }
  
  exit: myFile.close();
  cout<<"Cerrado"<<endl;
  scene[0]->getObjetos();*/

  return 0;
}
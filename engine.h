#ifndef ENGINE_H
#define ENGINE_H

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
#include "rpg.h"

using namespace std;
using namespace listasrpg;

const unsigned cantScenes = 18; //Cantidad de escenarios que tiene el juego, lo puse afuera porque se ocupa mucho en esta clase y evita errores al cambiar la cantidad de escenarios

class Engine
{
  private:
  Escenario *scenes[cantScenes]; //Se establece la cantidad de escenarios del juego
  Escenario *sceneActual;
  public:
  void CargarEscenarios(string archivo);
  void CargarObjetos(string archivo);//Usa un archivo para cargarle los objetos al arreglo de escenarios

  //Constructores
  Engine(string archivoEscenarios,string objetosFile);
  Engine();

  //Destructor
  ~Engine();
};

Engine::Engine(string escenariosFile,string objetosFile)
{
  CargarEscenarios(escenariosFile);
  cout<<"Check 1"<<endl;
  CargarObjetos(objetosFile);
}

Engine::Engine()
{
  cout<<"Se ha creado una partida sin datos"<<endl;
}

Engine::~Engine()
{
}

void Engine::CargarEscenarios(string archivo)
{
  string line;
  int count = 0;
  ifstream myFile;//objeto ifstream
  vector<string> tokens;//Donde se van a guardar los elementos de las líneas
  myFile.open(archivo);//Abre el archivo
  if (myFile.is_open())//Comprueba que está abierto el archivo
  {
    getline(myFile,line);
    tokens = split(line, '!');
    count = stoi(tokens[0]);
    for(int i=0;i<count;i++)
    {
      getline(myFile,line);
      tokens = split(line, '!');
      //cout<<"Llegue"<<endl;   //Línea para debuguear
      scenes[i] = new Escenario(tokens[0],tokens[1]);
      //cout<<scenes[i]->getNombre()<<endl; //Línea para debuguear
    }
  }
  else
  {
    cout<<"ERROR: No se pudieron abrir los escenarios"<<endl;
  }
  myFile.close();
  /*for (int i=0;i<count;i++)  //Líneas para debuguear
  {
    cout<<scenes[i]->getNombre()<<", "<<scenes[i]->getDescripcion()<<endl<<endl;
  }*/
}

void Engine::CargarObjetos(string archivo)
{
  cout<<"Check 2"<<endl;
  for(int i=0;i<cantScenes;i++)
  {
    scenes[i]->CargarObjetos(archivo);
    cout<<"Check a."<<i<<endl;
  }
}

#endif

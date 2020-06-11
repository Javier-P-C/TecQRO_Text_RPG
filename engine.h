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
  //Jugador();
  public:
  void CargarEscenarios(string archivo);//Usa un archivo para cargar los escenarios del juego
  void CargarObjetos(string archivo);//Usa un archivo para cargarle los objetos al arreglo de Escenario
  void CargarPersonajes(string archivo);//Usa un archivo para cargarle los personajes al arreglo de Escenario

  //Constructores
  Engine(string archivoEscenarios,string objetosFile,string personajesFile);
  Engine();

  //Destructor
  ~Engine();
};

Engine::Engine(string escenariosFile,string objetosFile,string personajesFile)
{
  CargarEscenarios(escenariosFile);
  CargarObjetos(objetosFile);
  CargarPersonajes(personajesFile);
}

Engine::Engine()
{
  CargarEscenarios("plantilla_carga_escenarios.csv");
  CargarObjetos("plantilla_carga_objetos.csv");
  CargarPersonajes("plantilla_carga_personajes.csv");
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
  cout<<"Fin de carga de escenarios"<<endl;
}

void Engine::CargarObjetos(string archivo)
{
  for(int i=0;i<cantScenes;i++)
  {
    //cout<<"Check a."<<i<<endl; //Línea para debuguear
    scenes[i]->CargarObjetos(archivo);
    //cout<<"Check b."<<i<<endl; //Línea para debuguear
  }
  cout<<"Fin de carga de objetos"<<endl;
}

void Engine::CargarPersonajes(string archivo)
{
  for(int i=0;i<cantScenes;i++)
  {
    //cout<<"Check a."<<i<<endl; //Línea para debuguear
    scenes[i]->CargarPersonajes(archivo);
    //cout<<"Check b."<<i<<endl; //Línea para debuguear
  }
  cout<<"Fin de carga de personajes"<<endl;
}

#endif

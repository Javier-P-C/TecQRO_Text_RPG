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
  Jugador *player;
  public:
  void CargarEscenarios(string archivo);//Usa un archivo para cargar los escenarios del juego
  void CargarObjetos(string archivo);//Usa un archivo para cargarle los objetos al arreglo de Escenario
  void CargarPersonajes(string archivo);//Usa un archivo para cargarle los personajes al arreglo de Escenario
  void CrearJugador();//Si es una partida nueva se manda a este menú para hacer al jugador
  void MostrarJugador();
  void CargarJugador(string archivo);

  //Constructores
  Engine(string escenariosFile,string objetosFile,string personajesFile,string jugadorFile);
  Engine(string escenariosFile,string objetosFile,string personajesFile);
  Engine();

  //Destructor
  ~Engine();
};

Engine::Engine(string escenariosFile,string objetosFile,string personajesFile,string jugadorFile)
{
  CargarEscenarios(escenariosFile);
  CargarObjetos(objetosFile);
  CargarPersonajes(personajesFile);
  CargarJugador(jugadorFile);
}

Engine::Engine(string escenariosFile,string objetosFile,string personajesFile)
{
  CargarEscenarios(escenariosFile);
  CargarObjetos(objetosFile);
  CargarPersonajes(personajesFile);
  CrearJugador();
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

void Engine::CrearJugador()
{
  //Todas la variables que se necesitan para construir un jugador
  string name;
  string id;
  int estudios;
  AreaTec studies;
  float intel;
  float charm;
  float skill;
  float sentido;
  float espiritu;
  float integridad;

  bool correctAns = false;
  
  string description = "Jugador";
  string position = "alumno";

  cout<<"Bienvenido al proceso de inscripción del Tecnológico de Monterrey campus Querétaro"<<endl<<"Llena el siguiente formulario para continuar"<<endl<<"**Cada que escribas una respuesta pulsa la tecla Enter para que se registre**"<<endl;
  cout<<"Nombre: ";
  getline(cin,name);
  cout<<endl<<"Escoja una Matricula: ";
  getline(cin,id);
  while(!correctAns)
  {
    cout<<endl<<"Escoja el área de estudio a la que se quiere inscribir"<<endl<<"1.Ambiente Construido"<<endl<<"2.Ciencias Sociales"<<endl<<"3.Estudios Creativos"<<endl<<"4.Ingenierias"<<endl<<"5.Negocios"<<endl<<"6.Salud"<<endl;
    cin>>estudios;
    if ((estudios>6)||(estudios<0))
    {
      cout<<endl<<"Esa no es una opción disponible"<<endl;
    }
    else
    {
      correctAns = true;
    }
  }
  studies = static_cast<AreaTec>(estudios);
  
  if (studies==AMBIENTE_CONSTRUIDO)
  {
    intel = 10;
    charm = 8;
    skill = 12;
  }
  else if (studies==CIENCIAS_SOCIALES)
  {
    intel = 8;
    charm = 17;
    skill = 5;
  }
  else if (studies==ESTUDIOS_CREATIVOS)
  {
    intel = 5;
    charm = 15;
    skill = 10;
  }
  else if (studies==INGENIERIAS)
  {
    intel = 15;
    charm = 5;
    skill = 10;
  }
  else if (studies==NEGOCIOS)
  {
    intel = 10;
    charm = 15;
    skill = 5;
  }
  else if (studies==SALUD)
  {
    intel = 10;
    charm = 10;
    skill = 10;
  }
  
  sentido = 10;
  espiritu = 10;
  integridad = 10;
  
  player = new Jugador(name,description,id,studies,position,intel,charm,skill,sentido,espiritu,integridad);

  cout<<"Tu registro ha sido exitoso"<<endl;
  MostrarJugador();


}

void Engine::MostrarJugador()
{
  player->getDescripcion();
  player->getStats();
  cout<<endl<<endl;
}

void Engine::CargarJugador(string archivo)
{
  string line;
  ifstream myFile;
  vector<string> tokens;//Donde se van a guardar los elementos de las líneas
  myFile.open(archivo);
  if(myFile.is_open())
  {
    player = new Jugador();
  }
}

//string name, string description,string id,AreaTec area,string posicion,float intel,float charm,float skill,float sentido,float espiritu,float integridad

#endif

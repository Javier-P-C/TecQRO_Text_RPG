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
  Escenario *sceneActual; //El escenario con el que se interactua
  Jugador *player; //Jugador
  Personaje *interaccion[2]; //Guarda al jugador y otro personaje
  public:
  void CargarEscenarios(string archivo);//Usa un archivo para cargar los escenarios del juego
  void CargarObjetos(string archivo);//Usa un archivo para cargarle los objetos al arreglo de Escenario
  void CargarPersonajes(string archivo);//Usa un archivo para cargarle los personajes al arreglo de Escenario
  void CrearJugador();//Si es una partida nueva se manda a este menú para hacer al jugador
  void MostrarJugador();//Llama a la descripcion delJugador y sus estadisticas
  void CargarJugador(string archivo); //Carga los datos de player desde un archivo
  void Guardar();//Guarda los datos de player en un archivo
  void MostrarTodo();//Impreme Objetos, Personajes y escenas, se usa para debuguear
  void Comandos();
  void Moverse();
  //void Interacción();
  //Escenario* getDireccion(string nombre_lugar);
  //void CargarBrujula(string archivo);
  

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
  sceneActual=scenes[8];//Lugar donde inicia el jugador; Borrego Cósmico
  MostrarJugador();
}

Engine::Engine(string escenariosFile,string objetosFile,string personajesFile)
{
  CargarEscenarios(escenariosFile);
  CargarObjetos(objetosFile);
  CargarPersonajes(personajesFile);
  CrearJugador();
  sceneActual=scenes[8];//Lugar donde inicia el jugador; Borrego Cósmico
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
  
  /*for(int i=0;i<cantScenes;i++)
  {
    delete scenes[i];
  }
  //cout<<"Check "<<endl;
  delete player;
  delete sceneActual;*/
  //Segmentation fault (core dumped)
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
  cout<<"Carga de escenarios finalizada"<<endl;
}

void Engine::CargarObjetos(string archivo)
{
  for(int i=0;i<cantScenes;i++)
  {
    //cout<<"Check a."<<i<<endl; //Línea para debuguear
    scenes[i]->CargarObjetos(archivo);
    //cout<<"Check b."<<i<<endl; //Línea para debuguear
  }
  cout<<"Carga de objetos finalizada"<<endl;
}

void Engine::CargarPersonajes(string archivo)
{
  for(int i=0;i<cantScenes;i++)
  {
    //cout<<"Check a."<<i<<endl; //Línea para debuguear
    scenes[i]->CargarPersonajes(archivo);
    //cout<<"Check b."<<i<<endl; //Línea para debuguear
  }
  cout<<"Carga de personajes finalizada"<<endl;
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
    AreaTec tipoTec;
    getline(myFile,line);
    tokens = split(line, ',');
    tipoTec = static_cast<AreaTec>(stoi(tokens[3]));
    player = new Jugador(tokens[0],tokens[1],tokens[2],tipoTec,tokens[4],stof(tokens[5]),stof(tokens[6]),stof(tokens[7]),stof(tokens[8]),stof(tokens[9]),stof(tokens[10]));
  }
  else
  {
    cout<<"ERROR: No se pudo abrir el archivo para carga del jugador en Engine()."<<endl;
  }
  cout<<"Carga de jugador finalizada"<<endl;
}

void Engine::Guardar()
{
  int opcion;
  cout<<"Si continua se sobrescribiran los datos de la partida. No podrá deshacerlo. ¿Desea continuar?"<<endl<<"1.Sí"<<endl<<"2.No"<<endl;
  cin>>opcion;
  if (opcion==1)
  {
    ofstream myFile;
    myFile.open("jugador_guardado.csv");
    if(myFile.is_open())
    {
      int estudios = player->getArea();
      myFile<<player->getNombre()<<","<<player->getAtributoDescripcion()<<","<<player->getMatricula()<<","<<estudios<<","<<player->getPosicion()<<","<<player->getInteligencia()<<","<<player->getCarisma()<<","<<player->getDestreza()<<","<<player->getSentidoHumano()<<","<<player->getEspirituEmprendedor()<<","<<player->getIntegridadAcademica();
    }
    else
    {
      cout<<"ERROR: No se pudo guardar Engine()."<<endl;
    }
    myFile.close();
  }
  else{cout<<"No se ha guardado."<<endl;}
  cout<<"Proceso terminado"<<endl;
}

void Engine::MostrarTodo()
{
  for (int i=0;i<cantScenes;i++)
  {
    scenes[i]->getPersonajes();
  }
  for (int i=0;i<cantScenes;i++)
  {
    scenes[i]->getObjetos();
  }
  for (int i=0;i<cantScenes;i++)
  {
    scenes[i]->printContadores();
  }
}

void Engine::Comandos()
{
  cout<<"Bienvenido al Tecnológico de Monterrey Campus Querétaro"<<endl;
  string comando;
  while(comando!="SALIR")
  {
    cout<<endl<<"Estás en "<<sceneActual->getNombre()<<endl;
    cout<<endl<<"***Ecriba un comando o escriba AYUDA para desplegar la lista de comandos***"<<endl;
    cin>>comando;
    cout<<endl;
    if (comando=="MOVERSE")
    {
      Moverse();
    }
    else if(comando=="MIRAR")
    {
      cout<<sceneActual->getDescripcion()<<endl;
      sceneActual->getPersonajes();
      sceneActual->getObjetos();
    }
    else if(comando=="GUARDAR")
    {
      Guardar();
    }
    else if(comando=="AYUDA")
    {
      cout<<"MIRAR - Ver los alrededores"<<endl<<"MOVERSE - Cambiar de escenario"<<endl<<"GUARDAR - Guardar progreso del personaje"<<endl<<"SALIR - Terminar el juego"<<endl;
    }
  }
  cout<<endl<<"PARTIDA TERMINADA"<<endl;
}

void Engine::Moverse()
{
  int opcion;
  cout<<endl<<"¿Adonde quieres ir?"<<endl;
  for (int i=0;i<cantScenes;i++)
  {
    cout<<i<<": "<<scenes[i]->getNombre()<<endl;
  }
  cin>>opcion;
  cout<<endl;
  sceneActual=scenes[opcion];
}



#endif

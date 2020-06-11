#ifndef ESCENARIO_H
#define ESCENARIO_H

#include <iostream>
#include <sstream>

#include "utility.h"

#include "personaje.h"
#include "animal.h"
#include "objeto.h"
#include "puntos.h"
#include "enemigo.h"
#include "jugador.h"
#include "miembrotec.h"
#include "rpg.h"

using namespace std;
using namespace listasrpg;

class Escenario
{
  private:
  string nombre;
  string descripcion;
  int contP,contOb; //Contadores personajes, objetos
  Personaje *individuos[4];
  Objeto *objts[2];
  Escenario *brujula[4]; //Guarda los escenarios contiguos [0]=NORTE, [1]=SUR, [2]=ESTE, [3]=OESTE

  public:
  string getNombre();
  string getDescripcion();
  void getPersonajes(); //Imprime la lista de los personajes visibles
  void AgregarPersonaje(Personaje *per);
  void getObjetos();
  void AgregarObjetos(Objeto *articulo); //Imprime la lista de los objetos visibles
  void getBrujula();
  void AgregarBrujula(string direccion,Escenario *lugar);
  void CargarObjetos(string archivo); //Carga objetos que vienen de un archivo
  void CargarPersonajes(string archivo); //Carga personajes que vienen de un archivo


  //Constructores
  Escenario(string name, string description);
  Escenario();

  //Destructor
  ~Escenario();
};

Escenario::Escenario(string name, string description)
{
  nombre = name;
  descripcion = description;
  contP = 0;
  contOb = 0;
  for (int i=0;i<4;i++)
  {
    brujula[i] = new Escenario();
  }
}

Escenario::Escenario()
{
  nombre = "";
  descripcion = "";
  contP = 0;
  contOb = 0;
}

Escenario::~Escenario()
{
  for(int i=0;i<contP;i++)
  {
    delete individuos[i];
  }
  for (int i=0;i<contOb;i++)
  {
    delete objts[contOb];
  }
  for (int i=0;i<4;i++)
  {
    delete brujula[i];
  }
  contP = 0;
  contOb = 0;
}

string Escenario::getNombre()
{
  return nombre;
}

string Escenario::getDescripcion()
{
  return descripcion;
}

void Escenario::getPersonajes()
{
  stringstream aux;
  if (contP>0)
  {
    aux<<endl<<"-----------------"<<endl;
    aux<<"En '"<<nombre<<"' se encuentran: "<<endl;
    for (int i=0;i<contP;i++)
    {
      if (individuos[i]->getVisibilidad()==true)
      {
        aux<<"+"<<individuos[i]->getstrTipoPersonaje()<<endl;
      }
    }
    aux<<endl;
  }
  else
  {
    aux<<endl<<"-----------------"<<endl;
    aux<<"No hay nadie en este lugar."<<endl;
  }
  cout<<aux.str();
}

void Escenario::AgregarPersonaje(Personaje *per)
{
  if (contP!=4)
  {
    if(per->getTipoPersonaje()==1)
    {
      individuos[contP] = new Animal();
      individuos[contP] = per;
      contP++;
    }
    else if(per->getTipoPersonaje()==2)
    {
      individuos[contP] = new Enemigo();
      individuos[contP] = per;
      contP++;
    }
    else if(per->getTipoPersonaje()==3)
    {
      individuos[contP] = new MiembroTec();
      individuos[contP] = per;
      contP++;
    }
    else
    {
      cout<<"Personaje no especificado, no se pudo agregar a individuos[] en clase Escenario()"<<endl;
    }
  }
  else
  {
    cout<<"ERROR:Arreglo individuos[] lleno, no se puede agregar personaje "<<per->getTipoPersonaje()<<" en clase Escenario()"<<endl;
  }
}

void Escenario::getObjetos()
{
  stringstream aux;
  if(contOb>0)
  {
    aux<<"-----------------"<<endl;
    aux<<"Puedes ver los siguientes objetos: "<<endl;
    for (int i=0;i<contOb;i++)
    {
      if (objts[i]->getVisibilidad()==true)
      {
        aux<<"-"<<objts[i]->getNombre()<<endl;
      }
    }
    aux<<endl;
  }
  else
  {
    aux<<"-----------------"<<endl;
    aux<<"No ves objetos que puedas recoger."<<endl;
  }
  cout<<aux.str();
}

void Escenario::AgregarObjetos(Objeto *articulo)
{
  if(contOb<2)
  {
    objts[contOb] = new Objeto();
    objts[contOb] = articulo;
    cout<<"Objeto agregado a "<<nombre<<endl;
    contOb++;
  }
  else
  {
    cout<<"ERROR:Arreglo objts[] lleno, no se puede agregar objeto en clase Escenario()"<<endl;
  }
}

void Escenario::AgregarBrujula(string direccion,Escenario *lugar)
{
  if(direccion=="norte")
  {
    brujula[0] = lugar;
  }
  else if(direccion=="sur")
  {
    brujula[1] = lugar;
  }
  else if(direccion=="este")
  {
    brujula[2] = lugar;
  }
  else if(direccion=="oeste")
  {
    brujula[3] = lugar;
  }
  else
  {
    cout<<"ERROR: No se pudo agregar escenario a la brujula de '"<<nombre<<"' porque la direccion no corresponde con ninguno de los puntos cardinales. Clase Escenario()"<<endl;
  }
}

void Escenario::getBrujula()
{
  stringstream aux;
  aux<<"------------------"<<endl;
  aux<<"Los cuartos cercanos son: "<<endl;
  for (int i=0;i<4;i++)
  {
    if (brujula[i]!=NULL)
    {
      switch(i)
      {
        case 0: aux<<"Norte: "<<brujula[i]->getNombre()<<endl;
        case 1: aux<<"Sur: "<<brujula[i]->getNombre()<<endl;
        case 2: aux<<"Este: "<<brujula[i]->getNombre()<<endl;
        case 3: aux<<"Oeste: "<<brujula[i]->getNombre()<<endl;
      }
    }
    aux<<"------------------"<<endl;
  }
  cout<<aux.str();
}

void Escenario::CargarObjetos(string archivo)
{
  string line;
  int count = 0;
  ifstream myFile;//objeto ifstream
  vector<string> tokens;//Donde se van a guardar los elementos de las líneas
  myFile.open(archivo);
  if (myFile.is_open())//Comprueba que está abierto el archivo
  {
    bool encontrado = false;
    do
    {
      getline(myFile,line);
      tokens = split(line, ',');
      if (tokens[0]==nombre)
      {
        encontrado = true;
      }
      //cout<<tokens[0]<<endl; //Línea para debuguear
    }while((tokens[0]!=nombre) && !myFile.eof());

    if (encontrado == false)
    {
      cout<<endl<<"ERROR: Nombre de escenario,"<<nombre<<", no encontrado en archivo para carga de objetos. Clase Escenario()"<<endl<<endl;
      goto exit; //20 líneas abajo
    }
    count = stoi(tokens[1]);
    for (int i=0;i<count;i++)
    {
      TipoPuntos tipoP;
      Objeto *objeto;
      getline(myFile,line);
      tokens = split(line, ',');
      tipoP = static_cast<TipoPuntos>(stoi(tokens[0]));
      //cout<<"Llegue"<<endl; //Línea para debuguear
      objeto = new Objeto(tokens[1],tokens[2],tipoP,stof(tokens[3]));
      AgregarObjetos(objeto);
    }
  }
  else
  {
    cout<<"ERROR: Archivo para carga de objetos no encontrado en clase Escenario()"<<endl;
  }
  
  exit: myFile.close();
  //cout<<"Cerrado"<<endl; //Línea para debuguear
}

void Escenario::CargarPersonajes(string archivo)
{
  string line;
  int count = 0;
  ifstream myFile;//objeto ifstream
  vector<string> tokens;//Donde se van a guardar los elementos de las líneas
  myFile.open(archivo);
  if (myFile.is_open())//Comprueba que está abierto el archivo
  {
    bool encontrado = false;
    
    do
    {
      getline(myFile,line);
      tokens = split(line, ',');
      if (tokens[0]==nombre)
      {
        encontrado = true;
      }
      //cout<<tokens[0]<<endl; //Línea para debuguear
    }while((tokens[0]!=nombre) && !myFile.eof());
    
    if (encontrado == false)
    {
      cout<<endl<<"ERROR: Nombre de escenario, "<<nombre<< ", no encontrado en archivo para carga de personajes. Escenario()"<<endl<<endl;
      goto exit; //40 líneas abajo
    }
    count = stoi(tokens[1]);
    for (int i=0;i<count;i++)
    {
      Personaje* per;
      getline(myFile,line);
      tokens = split(line, ',');
      switch(stoi(tokens[0]))
      {
        case 1: 
        {
          Especie especie = static_cast<Especie>(stoi(tokens[1]));
          per = new Animal(especie);
          AgregarPersonaje(per);
          break;
        }
        case 2: 
        {
          TipoEnemigo enemy = static_cast<TipoEnemigo>(stoi(tokens[1]));
          per = new Enemigo(enemy);
          AgregarPersonaje(per);
          break;
        }
        case 3: 
        {
          AreaTec area = static_cast<AreaTec>(stoi(tokens[1]));
          per = new MiembroTec(tokens[2],tokens[3],area,tokens[4]);
          AgregarPersonaje(per);
          break;
        }
      }
    }
  }
  else
  {
    cout<<"ERROR: No se pudo abrir archivo para carga de personajes en clase Escenario()"<<endl;
  }
  
  exit: myFile.close();
  //cout<<"Cerrado"<<endl; //Línea para debuguear
}

#endif
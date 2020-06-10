#ifndef ESCENARIO_H
#define ESCENARIO_H

#include <iostream>
#include <sstream>

#include "personaje.h"
#include "animal.h"
#include "objeto.h"
#include "puntos.h"
#include "enemigo.h"
#include "jugador.h"
#include "miembrotec.h"
#include "rpg.h"

class Escenario
{
  private:
  string nombre;
  string descripcion;
  int contP,contOb;
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
  for (int i=0;i<4;i++)
  {
    brujula[i] = new Escenario();
  }
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
        aux<<"+"<<individuos[i]->getTipoPersonaje()<<endl;
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
    if(per->getTipoPersonaje()=='a')
    {
      individuos[contP] = new Animal();
      individuos[contP] = per;
      contP++;
    }
    else if(per->getTipoPersonaje()=='b')
    {
      individuos[contP] = new Enemigo();
      individuos[contP] = per;
      contP++;
    }
    else if(per->getTipoPersonaje()=='c')
    {
      individuos[contP] = new MiembroTec();
      individuos[contP] = per;
      contP++;
    }
    else
    {
      cout<<"Personaje no especificado, no se pudo agregar a individuos[]"<<endl;
    }
  }
  else
  {
    cout<<"ERROR:Arreglo individuos[] lleno, no se puede agregar personaje "<<per->getTipoPersonaje()<<endl;
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
    contOb++;
    cout<<"Objeto agregado a "<<nombre<<endl;
  }
  else
  {
    cout<<"ERROR:Arreglo objts[] lleno, no se puede agregar objeto"<<endl;
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
    cout<<"ERROR: No se pudo agregar escenario a la brujula de '"<<nombre<<"' porque la direccion no corresponde con ninguno de los puntos cardinales"<<endl;
  }
}

void Escenario::getBrujula()
{
  
}

#endif
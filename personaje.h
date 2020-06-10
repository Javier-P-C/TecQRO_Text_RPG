#ifndef PERSONAJE_H
#define PERSONAJE_H

#include <iostream>

#include "rpg.h"
#include "puntos.h"

using namespace std;
using namespace listasrpg;

class Personaje
{
  protected:
  string descripcion; //Descripcion corta del personaje
  int tipoPersonaje; //animal(1),enemigo(2),miembro Tec(3)

  private:
  float salud; //Puntos de vida
  bool visibilidad; //Determina si puede interactuar con el jugador
  string nombre; //Nombre del personaje

  public:
  virtual Puntos Atacar() = 0; //Manda los puntos de daño
  //virtual float Batalla()=0; //Crea la batalla entre el jugador
  virtual void Hablar()=0; //Imprime dialogo
  virtual void Huir()=0; //Acaba con la interacción con el jugador
  virtual void DamageReceived(Puntos *pt); //Llama al metodo para bajar la salud y manda un mensaje al jugador, recibe los puntos que vienen de los ataques de enemigos
  virtual void getDescripcion(); //Muestra los atributos relevantes del personaje
  string getNombre(); //Manda el nombre del personaje
  void setSalud(Puntos *pt); //Cambia los puntos de salud dependiendo de si son de daño o de cura
  float getSalud(); //Manda el valor de salud
  void CambiarVisibilidad(); //Cambia de false a true y viceversa la visibilidad
  bool getVisibilidad(); //Manda el valor de visibilidad
  char getTipoPersonaje();

  //Constructores
  Personaje(string name); //Usa los parametros recibidos, provee descripcion generica, vuelve visible al personaje, salud al 100
  Personaje(string name, string description); //Usa los parametros, vuelve visible al personaje, salud al 100
  Personaje(string name, string description, bool visibility); //Usa los parametros, salud al 100
  Personaje(); //Genera un personaje con valores vacios

  //Destrcutor
  ~Personaje();
};

Personaje::Personaje(string name)
{
  nombre = name;
  descripcion = "Personaje genérico";
  salud = 100;
  visibilidad = true;
}

Personaje::Personaje(string name, string description)
{
  nombre = name;
  descripcion = description;
  salud = 100;
  visibilidad = true;
}

Personaje::Personaje(string name, string description, bool visibility)
{
  nombre = name;
  descripcion = description;
  salud = 100;
  visibilidad = visibility;
}

Personaje::Personaje()
{
  nombre = "";
  descripcion = "";
  salud = 0;
  visibilidad = false;
}

Personaje::~Personaje()
{
}

/*void Personaje::Hablar()
{
  cout<<"Parece que "<<nombre<<" no quiere hablar contigo."<<endl;
}*/

/*void Personaje::Huir()
{

  cout<<nombre<<" ha huido"<<endl;
}*/
  
void Personaje::DamageReceived(Puntos *pt)
{
  setSalud(pt);
  cout<<nombre<<" ha recibido daño, salud: "<<salud<<"/100"<<endl;
}

void Personaje::getDescripcion()
{
  cout<<endl<<endl<<"-----------------"<<endl;
  cout<<"NOMBRE: "<<nombre<<endl;
  cout<<"DESCRIPCIÓN: "<<descripcion<<endl;
  
}

string Personaje::getNombre()
{
  return nombre;
}

void Personaje::setSalud(Puntos *pt)
{
  if (pt->getTipoP()==HEALTH)
  {
    if (pt->getUso()=="disminuir")
    {
      salud-=pt->getValor();
    }
    else if(pt->getUso()=="aumentar")
    {
      salud+=pt->getValor();
    }
    else if(pt->getUso()=="neutro")
    {
      cout<<"No hay efecto en la salud"<<endl;
    }
  }
  if (salud>100)
  {
    salud = 100;
  }
  if (salud<0)
  {
    salud = 0;
  }
}

float Personaje::getSalud()
{
  return salud;
}

void Personaje::CambiarVisibilidad()
{
  if (visibilidad==true)
  {
    visibilidad = false;
  }
  else
  {
    visibilidad = true;
  }
}

bool Personaje::getVisibilidad()
{
  return visibilidad;
}

char Personaje::getTipoPersonaje()
{
  return tipoPersonaje;
}

#endif
#ifndef OBJETO_H
#define OBJETO_H

#include <iostream>

#include "puntos.h"

using namespace std;
using namespace listasrpg;

class Objeto
{
  private:
  string nombre;
  string descripcion;
  Puntos bonificacion; //Es el efecto que tiene el objeto en el jugador
  bool visibilidad;

  public:
  string getNombre();
  string getDescripcion();
  Puntos getPuntos();
  void setNombre(string name);
  void CambiarVisibilidad();
  bool getVisibilidad();
  void getPropiedades();

  //Constructores
  Objeto(string name, string description,TipoPuntos tipoBonificacion, float cantPuntos);
  Objeto(string name, string description);
  Objeto(Objeto &otro);
  Objeto();

  //Destructor
  ~Objeto();
};

Objeto::Objeto(string name, string description,TipoPuntos tipoBonificacion, float cantPuntos)
{
  nombre = name;
  descripcion = description;
  bonificacion = Puntos(tipoBonificacion,cantPuntos);
  bonificacion.setUso("aumentar");
  visibilidad = true;
}

Objeto::Objeto(string name, string description)
{
  nombre = name;
  descripcion = description;
  bonificacion = Puntos();
  visibilidad = true;
}

Objeto::Objeto(Objeto &otro)
{
  nombre = otro.nombre;
  descripcion = otro.descripcion;
  bonificacion = otro.bonificacion;
  visibilidad = otro.visibilidad;
}

Objeto::Objeto()
{
  nombre = "---";
  descripcion = "No hay descripcion";
}

Objeto::~Objeto()
{
}

string Objeto::getNombre()
{
  return nombre;
}

string Objeto::getDescripcion()
{
  return descripcion;
}

Puntos Objeto::getPuntos()
{
  return bonificacion; //Mandado por direccion
}

void Objeto::setNombre(string name)
{
 nombre=name;
}

void Objeto::CambiarVisibilidad()
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

bool Objeto::getVisibilidad()
{
  return visibilidad;
}

void Objeto::getPropiedades()
{
  cout<<nombre<<","<<descripcion<<endl;
  bonificacion.getPropiedades();
}

#endif
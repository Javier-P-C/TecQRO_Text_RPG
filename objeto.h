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

  public:
  string getNombre();
  string getDescripcion();
  Puntos getPuntos();

  //Constructores
  Objeto(string name, string description,TipoPuntos tipoBonificacion, float cantPuntos);
  Objeto(string name, string description);
  Objeto();

  //Destructor
  ~Objeto();
};

Objeto::Objeto(string name, string description,TipoPuntos tipoBonificacion, float cantPuntos)
{
  nombre = name;
  descripcion = description;
  bonificacion = Puntos(tipoBonificacion,cantPuntos);
}

Objeto::Objeto(string name, string description)
{
  nombre = name;
  descripcion = description;
  bonificacion = Puntos();
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

#endif
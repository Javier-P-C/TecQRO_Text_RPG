#ifndef ESCENARIO_H
#define ESCENARIO_H

#include <iostream>

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
  Personaje *individuos[4];

  public:
  string getNombre();
  string getDescripcion();
  void getPersonajes(); //Imprime la lista de los personajes visibles
  void AgregarPersonaje();

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
}

Escenario::Escenario()
{
  nombre = "";
  descripcion = "";
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
  
}

#endif
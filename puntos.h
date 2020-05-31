#ifndef PUNTOS_H
#define PUNTOS_H

#include <iostream>

#include "rpg.h"

using namespace std;
using namespace listasrpg;

class Puntos
{
  private:
  TipoPuntos tipoP;
  float valor;

  public:
  TipoPuntos getTipoP();
  float getValor();

  //Constructores
  Puntos(TipoPuntos tipo, float cantidad); //Usa los parametros para los atributos
  Puntos(); //Tipo No Aplica, valor a 0
  Puntos(const Puntos &points);

  //Destructor
  ~Puntos();
};

Puntos::Puntos(TipoPuntos tipo, float cantidad)
{
  tipoP=tipo;
  valor=cantidad;
}

Puntos::Puntos()
{
  tipoP = NA;
  valor = 0;
}

Puntos::Puntos(const Puntos &otro)
{
  tipoP = otro.tipoP;
  valor = otro.valor;
}

Puntos::~Puntos()
{
}

TipoPuntos Puntos::getTipoP()
{
  return tipoP;
}

float Puntos::getValor()
{
  return valor;
}

#endif
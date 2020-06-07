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
  string uso; //aumentar,disminuir

  public:
  TipoPuntos getTipoP();
  float getValor();
  string getUso();
  void setUso(string use);

  //Constructores
  Puntos(TipoPuntos tipo, float cantidad); //Usa los parametros para los atributos
  Puntos(); //Tipo No Aplica, valor a 0
  Puntos(const Puntos &points);
  void SubirPuntos(float aumento);
  void BajarPuntos(float disminucion);

  //Destructor
  ~Puntos();
};

Puntos::Puntos(TipoPuntos tipo, float cantidad)
{
  tipoP=tipo;
  valor=cantidad;
  uso="neutro";
}

Puntos::Puntos()
{
  tipoP = NP;
  valor = 0;
  uso="neutro";
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

string Puntos::getUso()
{
  return uso;
}

void Puntos::setUso(string use)
{
 uso=use;
}

void Puntos::SubirPuntos(float aumento)
{
 valor+=aumento;
}

void Puntos::BajarPuntos(float disminucion)
{
  valor-=disminucion;
}

#endif
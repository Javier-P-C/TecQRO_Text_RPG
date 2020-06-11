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
  void getPropiedades();
  string getstrTipoPuntos();

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
  uso = otro.uso;
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

void Puntos::getPropiedades()
{
  if(uso=="aumentar")
  {
    cout<<"Aumenta "<<valor<<" puntos de "<<getstrTipoPuntos()<<endl;
  }
  else if(uso=="disminuir")
  {
    cout<<"Disminuye "<<valor<<" puntos de "<<getstrTipoPuntos()<<endl;
  }
  else if(uso=="neutro")
  {
    cout<<"Son "<<valor<<" puntos neutros de "<<getstrTipoPuntos()<<endl;
  }
  else
  {
    cout<<"Error en uso de puntos"<<endl;
  }
}

string Puntos::getstrTipoPuntos()
{
  string str;
  if(tipoP==HEALTH)
  {
    str = "salud";
  }
  else if(tipoP==SPIRIT)
  {
    str = "espíritu emprendedor";
  }
  else if(tipoP==SENSE)
  {
    str = "sentido humano";
  }
  else if(tipoP==INTEGRITY)
  {
    str = "integridad académica";
  }
  else if(tipoP==CHARM)
  {
    str = "carisma";
  }
  else if(tipoP==INTELLIGENCE)
  {
    str = "inteligencia";
  }
  else if(tipoP==SKILL)
  {
    str = "destreza";
  }
  else
  {
    str="NA";
  }
  return str;
}

#endif
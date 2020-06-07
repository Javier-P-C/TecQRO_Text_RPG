#ifndef MIEMBROTEC_H
#define MIEMBROTEC_H

#include <iostream>

#include "personaje.h"
#include "rpg.h"

using namespace std;
using namespace listasrpg;

class MiembroTec : public Personaje //NPC's y el jugador
{
  private:
  string matricula;
  string posicion; //alumno, profesor, directivo
  AreaTec area;

  public:
  void Hablar();
  void Huir();
  void getDescripcion();
  Puntos Atacar();
  string getstrArea();
  AreaTec getArea();

  //Constructores
  MiembroTec(string name, string description, bool visibility,string id,AreaTec area,string posicion);
  MiembroTec(string name, string description,string id,AreaTec area,string posicion);
  MiembroTec(string name,string id,AreaTec area,string posicion);
  MiembroTec(string id,AreaTec area,string posicion);
  MiembroTec();

  //Destructor
  ~MiembroTec();
};

MiembroTec::MiembroTec(string name, string description, bool visibility,string id,AreaTec area,string position)
           :Personaje(name,description,visibility)
{
  matricula = id;
  posicion = position;
  this->area = area;
}

MiembroTec::MiembroTec(string name, string description,string id,AreaTec area,string position)
           :Personaje(name,description)
{
  matricula = id;
  posicion = position;
  this->area = area;
}

MiembroTec::MiembroTec(string name,string id,AreaTec area,string position)
           :Personaje(name)
{
  matricula = id;
  posicion = position;
  this->area = area;
  descripcion="Miembro del Tec";
}

MiembroTec::MiembroTec(string id,AreaTec area,string position)
           :Personaje("---")
{
  matricula = id;
  posicion = position;
  this->area = area;
  descripcion="Miembro del Tec";
}

MiembroTec::MiembroTec()
{
  matricula = "";
  posicion = "";
  area = NAR;
}

MiembroTec::~MiembroTec()
{
}

void MiembroTec::getDescripcion()
{
  Personaje::getDescripcion();
  cout<<"Área: "<<getstrArea()<<endl;
  cout<<"Posición: "<<posicion<<endl;
  cout<<"Mátricula: "<<matricula<<endl;;
  cout<<"-----------------"<<endl<<endl;
}

string MiembroTec::getstrArea()
{
  string ar;
  if(area==AMBIENTE_CONSTRUIDO)
  {
    ar = "ambiente construido";
  }
  else if(area==CIENCIAS_SOCIALES)
  {
    ar = "ciencias Sociales";
  }
  else if(area==ESTUDIOS_CREATIVOS)
  {
    ar = "estudios creativos";
  }
  else if(area==INGENIERIAS)
  {
    ar = "ingeniería";
  }
  else if(area==NEGOCIOS)
  {
    ar = "negocios";
  }
  else if(area==SALUD)
  {
    ar = "salud";
  }
  else
  {
    ar = "NA";
  }
  return ar;
}

AreaTec MiembroTec::getArea()
{
  return area;
}

void MiembroTec::Hablar()
{
  if (posicion=="directivo"||"profesor")
  {
    cout<<"Saludos joven, que tenga un buen día."<<endl;
  }
  else
  {
    if(area==AMBIENTE_CONSTRUIDO)
    {
      cout<<"Hoy no dormí pero ha sido la mejor maqueta que he hecho."<<endl;
    }
    else if(area==CIENCIAS_SOCIALES)
    {
      cout<<"."<<endl;
    }
    else if(area==ESTUDIOS_CREATIVOS)
    {
      cout<<"."<<endl;
    }
    else if(area==INGENIERIAS)
    {
      cout<<"Tengo que estudiar quiza en otro momento."<<endl;
    }
    else if(area==NEGOCIOS)
    {
      cout<<"."<<endl;
    }
    else if(area==SALUD)
    {
      cout<<"No, no sé que tienes aún no me graduo. ¿Por qué siempre me pasa esto?"<<endl;
    }
  }
}

void MiembroTec::Huir()
{
  cout<<"El "<<posicion<<" de "<<getstrArea()<<" se ha ido."<<endl;
  CambiarVisibilidad();
}

Puntos MiembroTec::Atacar()
{
  Puntos pt(NP,0);
  return pt;
}

#endif

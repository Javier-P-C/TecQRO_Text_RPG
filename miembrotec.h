#ifndef MIEMBROTEC_H
#define MIEMBROTEC_H

#include <iostream>
#include <sstream>

#include "personaje.h"

using namespace std;
using namespace listasrpg;

class MiembroTec : public Personaje //NPC's y el jugador
{
  private:
  string matricula;
  string posicion; //alumno, profesor, directivo
  AreaTec area; //Area de estudio (ir a rpg.h para mayor información)
  bool player;

  public:
  void Hablar();
  virtual void Huir();
  void getDescripcion();
  string getstrTipoPersonaje();
  virtual Puntos Atacar();
  string getstrArea();
  AreaTec getArea();
  string getMatricula();
  string getPosicion();

  //Constructores
  //MiembroTec(string name, string description, bool visibility,string id,AreaTec area,string posicion);
  MiembroTec(string name, string description,string id,AreaTec area,string posicion);
  MiembroTec(string name,string id,AreaTec area,string posicion);
  MiembroTec(string id,AreaTec area,string posicion);
  MiembroTec();

  //Destructor
  ~MiembroTec();
};

/*MiembroTec::MiembroTec(string name, string description, bool visibility,string id,AreaTec area,string position)
           :Personaje(name,description,visibility)
{
  tipoPersonaje = 3;
  matricula = id;
  posicion = position;
  this->area = area;
  player=false;
}*/

MiembroTec::MiembroTec(string name, string description,string id,AreaTec area,string position)
           :Personaje(name,description)
{
  tipoPersonaje = 3;
  matricula = id;
  posicion = position;
  this->area = area;
  player=false;
}

MiembroTec::MiembroTec(string name,string id,AreaTec area,string position)
           :Personaje(name)
{
  tipoPersonaje = 3;
  matricula = id;
  posicion = position;
  this->area = area;
  descripcion="Miembro del Tec";
  player=false;
}

/*MiembroTec::MiembroTec(string id,AreaTec area,string position)
           :Personaje("---")
{
  tipoPersonaje = 3;
  matricula = id;
  posicion = position;
  this->area = area;
  descripcion="Miembro del Tec";
  player=false;
}*/

MiembroTec::MiembroTec()
{
  tipoPersonaje = 3;
  matricula = "";
  posicion = "";
  area = NAR;
  player=false;
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
  cout<<"-----------------"<<endl;
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
    ar = "ciencias sociales";
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
  if ((posicion=="directivo")||(posicion=="profesor"))
  {
    cout<<posicion<<": Saludos joven, que tenga un buen día."<<endl;
  }
  else
  {
    if(area==AMBIENTE_CONSTRUIDO)
    {
      cout<<posicion<<": Hoy no dormí pero ha sido la mejor maqueta que he hecho."<<endl;
    }
    else if(area==CIENCIAS_SOCIALES)
    {
      cout<<posicion<<": Soy científico... social."<<endl;
    }
    else if(area==ESTUDIOS_CREATIVOS)
    {
      cout<<posicion<<": El Tec me ha enseñado que la creatividad de estudia con lineamientos estrictos."<<endl;
    }
    else if(area==INGENIERIAS)
    {
      cout<<posicion<<": Tengo que estudiar quiza en otro momento."<<endl;
    }
    else if(area==NEGOCIOS)
    {
      cout<<posicion<<": ¿Te interesaría ganar dinero con un empredimiento?"<<endl;
    }
    else if(area==SALUD)
    {
      cout<<posicion<<": No, no sé que tienes, aún no me graduo. ¿Por qué siempre me pasa esto?"<<endl;
    }
  }
  if (player==true)
  {
    cout<<"*No hay nadie para hablar*"<<endl;
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

string MiembroTec::getstrTipoPersonaje()
{
  stringstream aux;
  aux<<"Miembro Tec ("<<getstrArea()<<")";
  return aux.str();
}

string MiembroTec::getMatricula()
{
  return matricula;
}

string MiembroTec::getPosicion()
{
  return posicion;
}

#endif

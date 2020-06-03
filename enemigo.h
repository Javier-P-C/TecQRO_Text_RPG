#ifndef ENEMIGO_H
#define ENEMIGO_H

#include <iostream>

#include "personaje.h"

using namespace std;

//Faltan dialogo
class Enemigo : public Personaje
{
  private:
  TipoEnemigo enemigo;
  TipoAlumno debilidad1;
  TipoAlumno debilidad2;
  TipoAlumno fortaleza1;
  TipoAlumno fortaleza2;
  TipoAlumno fortaleza3;

  public:
  Puntos Atacar(); //Manda los puntos de daño, puede usar un ataque especial, solo tipo Boss
  Puntos Atacar(TipoAlumno tipoAl); //Enemigos que no son Bosses usan este metodo
  //virtual float Batalla()=0; //Crea la batalla entre el jugador
  void Hablar(); //Imprime dialogo
  void getDescripcion();
  void Huir();//Acaba con la interacción con el jugador puede tirar un objeto
  void DamageReceived(Puntos *pt);//Recibe puntos de daño y dependiendo de la debilidad del enemigo los aumenta
  string getEnemigo(); //Pasa los TipoEnemigo a string

  //Constructores
  Enemigo(string name,TipoEnemigo enemy);
  Enemigo(string name,string description,TipoEnemigo enemy);
  Enemigo(string name,string description,bool visibility,TipoEnemigo enemy);
  Enemigo();

  //Destructor
  ~Enemigo();
};

Enemigo::Enemigo(string name,TipoEnemigo enemy)
        :Personaje(name)
{
  Puntos puntosAjuste(DAMAGE,50);
  setSalud(&puntosAjuste);
  puntosAjuste.~Puntos();
  enemigo=enemy;

  if(enemigo==COLADO)
  {
    descripcion = "";
    debilidad1 = NEGOCIOS;
    debilidad2 = SALUD;
    fortaleza1 = INGENIERIAS;
    fortaleza2 = AMBIENTE_CONSTRUIDO;
    fortaleza3 = CIENCIAS_SOCIALES;
  }
  else if(enemigo==HATER)
  {
    descripcion = "";
    debilidad1 = CIENCIAS_SOCIALES;
    debilidad2 = SALUD;
    fortaleza1 = NEGOCIOS;
    fortaleza2 = ESTUDIOS_CREATIVOS;
    fortaleza3 = INGENIERIAS;
  }
  else if(enemigo==VALEM)
  {
    descripcion = "";
    debilidad1 = CIENCIAS_SOCIALES;
    debilidad2 = ESTUDIOS_CREATIVOS;
    fortaleza1 = AMBIENTE_CONSTRUIDO;
    fortaleza2 = NEGOCIOS;
    fortaleza3 = NAL;
  }
  else if(enemigo==BORRACHO)
  {
    descripcion = "";
    debilidad1 = AMBIENTE_CONSTRUIDO;
    debilidad2 = INGENIERIAS;
    fortaleza1 = ESTUDIOS_CREATIVOS;
    fortaleza2 = SALUD;
    fortaleza3 = NAL;
  }
}

Enemigo::Enemigo(string name,string description,TipoEnemigo enemy)
        :Personaje(name,description)
{
  enemigo = enemy;
  if(enemigo==BOSS)
  {
    debilidad1 = NAL;
    debilidad2 = NAL;
    fortaleza1 = NAL;
    fortaleza2 = NAL;
    fortaleza3 = NAL;  
  }
  if(enemigo!=BOSS);//Marcar error
}

Enemigo::Enemigo(string name,string description,bool visibility,TipoEnemigo enemy)
        :Personaje(name,description,visibility)
{
  enemigo=enemy;

  if(enemigo!=BOSS)
  {
    Puntos puntosAjuste(DAMAGE,50);
    setSalud(&puntosAjuste);
    puntosAjuste.~Puntos();


    if(enemigo==COLADO)
    {
      descripcion = "";
      debilidad1 = NEGOCIOS;
      debilidad2 = SALUD;
      fortaleza1 = INGENIERIAS;
      fortaleza2 = AMBIENTE_CONSTRUIDO;
      fortaleza3 = CIENCIAS_SOCIALES;
    }
    else if(enemigo==HATER)
    {
      descripcion = "";
      debilidad1 = CIENCIAS_SOCIALES;
      debilidad2 = SALUD;
      fortaleza1 = NEGOCIOS;
      fortaleza2 = ESTUDIOS_CREATIVOS;
      fortaleza3 = INGENIERIAS;
    }
    else if(enemigo==VALEM)
    {
      descripcion = "";
      debilidad1 = CIENCIAS_SOCIALES;
      debilidad2 = ESTUDIOS_CREATIVOS;
      fortaleza1 = AMBIENTE_CONSTRUIDO;
      fortaleza2 = NEGOCIOS;
      fortaleza3 = NAL;
    }
    else if(enemigo==BORRACHO)
    {
      descripcion = "";
      debilidad1 = AMBIENTE_CONSTRUIDO;
      debilidad2 = INGENIERIAS;
      fortaleza1 = ESTUDIOS_CREATIVOS;
      fortaleza2 = SALUD;
      fortaleza3 = NAL;
    }
  }
  else
  {
    debilidad1 = NAL;
    debilidad2 = NAL;
    fortaleza1 = NAL;
    fortaleza2 = NAL;
    fortaleza3 = NAL; 
  }
}

Enemigo::Enemigo()
        :Personaje()
{
  debilidad1 = NAL;
  debilidad2 = NAL;
  fortaleza1 = NAL;
  fortaleza2 = NAL;
  fortaleza3 = NAL;
}

Enemigo::~Enemigo()
{
}

Puntos Enemigo::Atacar()
{
  if(enemigo!=BOSS)
  {
    //Mandar error
  }
  Puntos pt(DAMAGE,25);
  return pt;
}

Puntos Enemigo::Atacar(TipoAlumno tipoAl)
{
  Puntos pt(DAMAGE,10);
  if(enemigo==COLADO)
  {
    if((fortaleza1||fortaleza2||fortaleza3)==(INGENIERIAS||AMBIENTE_CONSTRUIDO||CIENCIAS_SOCIALES))
    {
      pt.SubirPuntos(8);
    }
  }
  else if(enemigo==HATER)
  {
     if((fortaleza1||fortaleza2||fortaleza3)==(NEGOCIOS||ESTUDIOS_CREATIVOS||INGENIERIAS))
    {
      pt.SubirPuntos(8);
    }
  }
  else if(enemigo==VALEM)
  {
    if((fortaleza1||fortaleza2||fortaleza3)==(AMBIENTE_CONSTRUIDO||NEGOCIOS))
    {
      pt.SubirPuntos(8);
    }
  }
  else if(enemigo==BORRACHO)
  {
    if((fortaleza1||fortaleza2||fortaleza3)==(ESTUDIOS_CREATIVOS||SALUD))
    {
      pt.SubirPuntos(8);
    }
  }
  return pt;
}

void Enemigo::Hablar()
{
   if(enemigo==COLADO)
  {
    cout<<"Bonitas instalaciones las del Tec tienen buenas paredes para mi arte urbano."<<endl;
  }
  else if(enemigo==HATER)
  {
    cout<<"Con lo inteligente que te ves no me queda duda que los del Tec pagan para pasar."<<endl;
  }
  else if(enemigo==VALEM)
  {
    cout<<"Vamonos a la capilla bro el examen argumentativo de hoy no vale mucho."<<endl;
  }
  else if(enemigo==BORRACHO)
  {
    cout<<"Deja de mirarme *eructo* solo essszz agua..."<<endl;
  }
}

void Enemigo::getDescripcion()
{
  Personaje::getDescripcion();
  cout<<"ENEMIGO: "<<getEnemigo()<<endl;
  cout<<"SALUD: "<<getSalud()<<endl;
  cout<<"-----------------"<<endl<<endl;
}

string Enemigo::getEnemigo()
{
  string enemy;
  if(enemigo==COLADO)
  {
    enemy = "colado";
  }
  else if(enemigo==HATER)
  {
    enemy = "hater";
  }
  else if(enemigo==VALEM)
  {
    enemy = "alumno irresponsable";
  }
  else if(enemigo==BORRACHO)
  {
    enemy = "borracho";
  }
  else if(enemigo==BOSS)
  {
    enemy = "BOSS";
  }
  return enemy;
}

void Enemigo::Huir()
{
  cout<<"El "<<getEnemigo()<<" ha huido"<<endl;
  CambiarVisibilidad();
}

void Enemigo::DamageReceived(Puntos *pt)
{
  if((debilidad1||debilidad2)==(NEGOCIOS||SALUD))
  {
    pt->SubirPuntos(5);
  }
  else if((debilidad1||debilidad2)==(CIENCIAS_SOCIALES||SALUD))
  {
    pt->SubirPuntos(5);
  }
  else if((debilidad1||debilidad2)==(CIENCIAS_SOCIALES||ESTUDIOS_CREATIVOS))
  {
    pt->SubirPuntos(5);
  }
  else if((debilidad1||debilidad2)==(AMBIENTE_CONSTRUIDO||INGENIERIAS))
  {
    pt->SubirPuntos(5);
  }
  setSalud(pt);
  cout<<"El "<<getEnemigo()<<" ha recibido daño, salud: "<<getSalud()<<"/100"<<endl;
}

#endif
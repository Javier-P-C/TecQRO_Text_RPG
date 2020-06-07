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
  AreaTec debilidad1;
  AreaTec debilidad2;
  AreaTec fortaleza1;
  AreaTec fortaleza2;
  AreaTec fortaleza3;

  public:
  Puntos Atacar(); //Manda los puntos de daño, puede usar un ataque especial, solo tipo Boss
  Puntos Atacar(AreaTec tipoAl); //Enemigos que no son Bosses usan este metodo
  //virtual float Batalla()=0; //Crea la batalla entre el jugador
  void Hablar(); //Imprime dialogo
  void getDescripcion();
  void Huir();//Acaba con la interacción con el jugador puede tirar un objeto
  void DamageReceived(Puntos *pt);//Recibe puntos de daño y dependiendo de la debilidad del enemigo los aumenta
  string getstrEnemigo(); //Pasa los TipoEnemigo a string

  //Constructores
  Enemigo(string name,TipoEnemigo enemy);
  Enemigo(TipoEnemigo enemy);
  //Solo los bosses pueden tener descripción aparte
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
    descripcion = "Se aprovecha de las instalaciones aunque no sea parte de la instiución.";
    debilidad1 = NEGOCIOS;
    debilidad2 = SALUD;
    fortaleza1 = INGENIERIAS;
    fortaleza2 = AMBIENTE_CONSTRUIDO;
    fortaleza3 = CIENCIAS_SOCIALES;
  }
  else if(enemigo==HATER)
  {
    descripcion = "Le gusta criticar al Tec, no escucha opiniones contrarias a la suya.";
    debilidad1 = CIENCIAS_SOCIALES;
    debilidad2 = SALUD;
    fortaleza1 = NEGOCIOS;
    fortaleza2 = ESTUDIOS_CREATIVOS;
    fortaleza3 = INGENIERIAS;
  }
  else if(enemigo==VALEM)
  {
    descripcion = "A pesar de ser alumno la escuela no le interesa, nadie sabe como no reprueba.";
    debilidad1 = CIENCIAS_SOCIALES;
    debilidad2 = ESTUDIOS_CREATIVOS;
    fortaleza1 = AMBIENTE_CONSTRUIDO;
    fortaleza2 = NEGOCIOS;
    fortaleza3 = NAL;
  }
  else if(enemigo==BORRACHO)
  {
    descripcion = "Nunca está en optimas condiciones, se encuentra más tiempo en las micheladas y en el OXXO de afuera que en el campus.";
    debilidad1 = AMBIENTE_CONSTRUIDO;
    debilidad2 = INGENIERIAS;
    fortaleza1 = ESTUDIOS_CREATIVOS;
    fortaleza2 = SALUD;
    fortaleza3 = NAL;
  }
  else if(enemigo==BOSS);//Marcar error
}

Enemigo::Enemigo(TipoEnemigo enemy)
        :Personaje("---")
{
  Puntos puntosAjuste(DAMAGE,50);
  setSalud(&puntosAjuste);
  puntosAjuste.~Puntos();
  enemigo=enemy;

  if(enemigo==COLADO)
  {
    descripcion = "Se aprovecha de las instalaciones aunque no sea parte de la instiución.";
    debilidad1 = NEGOCIOS;
    debilidad2 = SALUD;
    fortaleza1 = INGENIERIAS;
    fortaleza2 = AMBIENTE_CONSTRUIDO;
    fortaleza3 = CIENCIAS_SOCIALES;
  }
  else if(enemigo==HATER)
  {
    descripcion = "Le gusta criticar al Tec, no escucha opiniones contrarias a la suya.";
    debilidad1 = CIENCIAS_SOCIALES;
    debilidad2 = SALUD;
    fortaleza1 = NEGOCIOS;
    fortaleza2 = ESTUDIOS_CREATIVOS;
    fortaleza3 = INGENIERIAS;
  }
  else if(enemigo==VALEM)
  {
    descripcion = "A pesar de ser alumno la escuela no le interesa, nadie sabe como no reprueba.";
    debilidad1 = CIENCIAS_SOCIALES;
    debilidad2 = ESTUDIOS_CREATIVOS;
    fortaleza1 = AMBIENTE_CONSTRUIDO;
    fortaleza2 = NEGOCIOS;
    fortaleza3 = NAL;
  }
  else if(enemigo==BORRACHO)
  {
    descripcion = "Nunca está en optimas condiciones, se encuentra más tiempo en las micheladas y en el OXXO de afuera que en el campus.";
    debilidad1 = AMBIENTE_CONSTRUIDO;
    debilidad2 = INGENIERIAS;
    fortaleza1 = ESTUDIOS_CREATIVOS;
    fortaleza2 = SALUD;
    fortaleza3 = NAL;
  }
  else if(enemigo==BOSS);//Marcar error
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
  else if(enemigo!=BOSS);//Marcar error
}

Enemigo::Enemigo(string name,string description,bool visibility,TipoEnemigo enemy)
        :Personaje(name,description,visibility)
{
  enemigo=enemy;
 enemigo = enemy;
  if(enemigo==BOSS)
  {
    debilidad1 = NAL;
    debilidad2 = NAL;
    fortaleza1 = NAL;
    fortaleza2 = NAL;
    fortaleza3 = NAL;  
  }
  else if(enemigo!=BOSS);//Marcar error
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
  Puntos pt(HEALT,25);
  Puntos.setUso("disminuir");
  return pt;
}

Puntos Enemigo::Atacar(AreaTec tipoAl)
{
  Puntos pt(HEALT,10);
  Puntos.setUso("disminuir");
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
    cout<<getsrtEnemigo()<<": Bonitas instalaciones las del Tec tienen buenas paredes para mi arte urbano."<<endl;
  }
  else if(enemigo==HATER)
  {
    cout<<getsrtEnemigo()<<": Con lo inteligente que te ves no me queda duda que los del Tec pagan para pasar."<<endl;
  }
  else if(enemigo==VALEM)
  {
    cout<<getsrtEnemigo()<<": Vamonos a la capilla bro el examen argumentativo de hoy no vale mucho."<<endl;
  }
  else if(enemigo==BORRACHO)
  {
    cout<<getsrtEnemigo()<<": Deja de mirarme *eructo* solo essszz agua..."<<endl;
  }
  else if(enemigo==BOSS)
  cout<<getsrtEnemigo()<<": >:| *No parece muy contento*"<<endl;
}

void Enemigo::getDescripcion()
{
  Personaje::getDescripcion();
  cout<<"ENEMIGO: "<<getstrEnemigo()<<endl;
  cout<<"SALUD: "<<getSalud()<<endl;
  cout<<"-----------------"<<endl<<endl;
}

string Enemigo::getstrEnemigo()
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
  else
  {
    enemy = "NA";
  }
  return enemy;
}

void Enemigo::Huir()
{
  cout<<"El "<<getstrEnemigo()<<" ha huido"<<endl;
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
  cout<<"El "<<getstrEnemigo()<<" ha recibido daño, salud: "<<getSalud()<<"/100"<<endl;
}

#endif
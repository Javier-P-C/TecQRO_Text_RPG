#ifndef JUGADOR_H
#define JUGADOR_H

#include <iostream>

#include "miembrotec.h"

using namespace std;
using namespace listasrpg;

class Jugador : MiembroTec
{
  private:
  //Stats normales
  float inteligencia;
  float carisma;
  float destreza;
  //TecStats
  float sentidoHumano;
  float espirituEmprendedor;
  float integridadAcademica;
  bool stamina; //Permite usar su ataque especial una vez por combate

  public:
  Puntos Atacar();
  void getStats(); //Enlista las estadísticas del jugador
  void setInteligencia(Puntos *pt);
  void setCarisma(Puntos *pt);
  void setDestreza(Puntos *pt);
  void setSentidoHumano(Puntos *pt);
  void setEspirituEmprendedor(Puntos *pt);
  void setIntegridadAcademica(Puntos *pt);

  //Constructores
  Jugador(string name, string description,string id,AreaTec area,string posicion,float intel,float charm,float skill,float sentido,float espiritu,float integridad);
  Jugador();

  //Destructor
  ~Jugador();
};

Jugador::Jugador(string name, string description, string id,AreaTec area,string posicion,float intel,float charm,float skill,float sentido,float espiritu,float integridad)
        :MiembroTec(name,description,id,area,posicion)
{
  inteligencia = intel;
  carisma = charm;
  destreza = skill;
  sentidoHumano = sentido;
  espirituEmprendedor = espiritu;
  integridadAcademica = integridad;
}
Jugador::Jugador()
        :MiembroTec()
{
  inteligencia = 0;
  carisma = 0;
  destreza = 0;
  sentidoHumano = 0;
  espirituEmprendedor = 0;
  integridadAcademica = 0;
}

Jugador::~Jugador()
{
}

Puntos Jugador::Atacar()
{
  int opcion;
  Puntos pt(HEALTH,8);
  if (stamina==true)
  {
    cout<<"<<<¿Quieres usar ataque normal(1) o RAYO EMPRENDEDOR(2)? -El rayo solo se puede usar una vez por combate->>>"<<endl;
    cin>>opcion;
    if (opcion==2)
    {
      pt.SubirPuntos(2+(int)(inteligencia/10)+(int)(carisma/10)+(int)(destreza/10));
      cout<<"David Noel te ha bendecido con un rayo emprendedor, has emprendido un ataque contundente al enemigo."<<endl;
    }
  }
  else
  {
    pt.SubirPuntos(((int)(sentidoHumano/10)+(int)(espirituEmprendedor/10)+(int)(integridadAcademica/10))/2);
    cout<<"Has golpeado al enemigo."<<endl;
  }
  return pt;
}

void Jugador::getStats() //Enlista las estadísticas del jugador
{
  cout<<endl<<endl<<"-----------------"<<endl;
  cout<<endl<<endl<<"---ESTADÍSTICAS--"<<endl;
  cout<<endl<<endl<<"-----------------"<<endl;
  cout<<"Inteligencia: "<<inteligencia<<endl;
  cout<<"Carisma: "<<carisma<<endl;
  cout<<"Destreza: "<<destreza<<endl;
  cout<<endl<<endl<<"-TEC-ESTADÍSTICAS-"<<endl;
  cout<<"Sentido Humano: "<<sentidoHumano<<endl;
  cout<<"Espíritu Emprendedor: "<<espirituEmprendedor<<endl;
  cout<<"Integridad Académica: "<<integridadAcademica<<endl;
  cout<<"-----------------"<<endl;
  cout<<"-----------------"<<endl<<endl;
}
  
void Jugador::setInteligencia(Puntos *pt)
{
  if (pt->getTipoP()==INTELLIGENCE)
  {
    if (pt->getUso()=="disminuir")
    {
      inteligencia-=pt->getValor();
    }
    else if(pt->getUso()=="aumentar")
    {
      inteligencia+=pt->getValor();
    }
    else if(pt->getUso()=="neutro")
    {
      cout<<"No hay efecto en la inteligencia"<<endl;
    }
  }
  if (inteligencia>50)
  {
    inteligencia = 50;
  }
  if (inteligencia<0)
  {
    inteligencia = 0;
  }
}

void Jugador::setCarisma(Puntos *pt)
{
  if (pt->getTipoP()==CHARM)
  {
    if (pt->getUso()=="disminuir")
    {
      carisma-=pt->getValor();
    }
    else if(pt->getUso()=="aumentar")
    {
      carisma+=pt->getValor();
    }
    else if(pt->getUso()=="neutro")
    {
      cout<<"No hay efecto en el carisma"<<endl;
    }
  }
  if (carisma>50)
  {
    carisma = 50;
  }
  if (carisma<0)
  {
    carisma = 0;
  }
}

void Jugador::setDestreza(Puntos *pt)
{
  if (pt->getTipoP()==SKILL)
  {
    if (pt->getUso()=="disminuir")
    {
      destreza-=pt->getValor();
    }
    else if(pt->getUso()=="aumentar")
    {
      destreza+=pt->getValor();
    }
    else if(pt->getUso()=="neutro")
    {
      cout<<"No hay efecto en el carisma"<<endl;
    }
  }
  if (destreza>50)
  {
    destreza = 50;
  }
  if (destreza<0)
  {
    destreza = 0;
  }
}

void Jugador::setSentidoHumano(Puntos *pt)
{
  if (pt->getTipoP()==SENSE)
  {
    if (pt->getUso()=="disminuir")
    {
      sentidoHumano-=pt->getValor();
    }
    else if(pt->getUso()=="aumentar")
    {
      sentidoHumano+=pt->getValor();
    }
    else if(pt->getUso()=="neutro")
    {
      cout<<"No hay efecto en el carisma"<<endl;
    }
  }
  if (sentidoHumano>50)
  {
    sentidoHumano = 50;
  }
  if (sentidoHumano<0)
  {
    sentidoHumano = 0;
  }
}

void Jugador::setEspirituEmprendedor(Puntos *pt)
{
  if (pt->getTipoP()==SPIRIT)
  {
    if (pt->getUso()=="disminuir")
    {
      espirituEmprendedor-=pt->getValor();
    }
    else if(pt->getUso()=="aumentar")
    {
      espirituEmprendedor+=pt->getValor();
    }
    else if(pt->getUso()=="neutro")
    {
      cout<<"No hay efecto en el carisma"<<endl;
    }
  }
  if (espirituEmprendedor>50)
  {
    espirituEmprendedor = 50;
  }
  if (espirituEmprendedor<0)
  {
    espirituEmprendedor = 0;
  }
}

void Jugador::setIntegridadAcademica(Puntos *pt)
{
  if (pt->getTipoP()==INTEGRITY)
  {
    if (pt->getUso()=="disminuir")
    {
      integridadAcademica-=pt->getValor();
    }
    else if(pt->getUso()=="aumentar")
    {
      integridadAcademica+=pt->getValor();
    }
    else if(pt->getUso()=="neutro")
    {
      cout<<"No hay efecto en el carisma"<<endl;
    }
  }
  if (integridadAcademica>50)
  {
    integridadAcademica = 50;
  }
  if (integridadAcademica<0)
  {
    integridadAcademica = 0;
  }
}

#endif
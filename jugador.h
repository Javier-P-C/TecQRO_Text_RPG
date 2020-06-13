#ifndef JUGADOR_H
#define JUGADOR_H

#include <iostream>

#include "miembrotec.h"

using namespace std;
using namespace listasrpg;

class Jugador : public MiembroTec
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
  Objeto *inventario[5];
  int contInventario;

  public:
  Puntos Atacar();//Los puntos aumentan su valor dependiendo de las stats del jugador
  void getStats(); //Enlista las estadísticas del jugador
  void setInteligencia(Puntos pt);//Usa Puntos() para cambiar atributo
  void setCarisma(Puntos pt);//Usa Puntos() para cambiar atributo
  void setDestreza(Puntos pt);//Usa Puntos() para cambiar atributo
  void setSentidoHumano(Puntos pt);//Usa Puntos() para cambiar atributo
  void setEspirituEmprendedor(Puntos pt);//Usa Puntos() para cambiar atributo
  void setIntegridadAcademica(Puntos pt);//Usa Puntos() para cambiar atributo
  float getInteligencia(); //Manda valor float de atributo
  float getCarisma();//Manda valor float de atributo
  float getDestreza();//Manda valor float de atributo
  float getSentidoHumano();//Manda valor float de atributo
  float getEspirituEmprendedor();//Manda valor float de atributo
  float getIntegridadAcademica();//Manda valor float de atributo
  void CambiarStamina();//Pasa atributo stamina de true a false y viceversa
  bool getStamina();//Manda el valor actual de stamina, se usa para los combates Engine::Batalla()
  void AgregarInventario(Objeto *objt);//Recibe la dirección de un objeto para agregarlo a inventario[]
  void MostrarInventario();//Muestra los nombres de todos los objetos que tienes guardados

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
  stamina=true;
  contInventario=0;
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
  stamina=false;
  contInventario=0;
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
      cout<<"========================"<<endl;
      pt.SubirPuntos(2+(int)(inteligencia/10)+(int)(carisma/10)+(int)(destreza/10));
      cout<<endl<<"David Noel te ha bendecido con un rayo emprendedor, has emprendido un ataque contundente al enemigo."<<endl;
      CambiarStamina();
    }
    else
    {
      pt.SubirPuntos(((int)(sentidoHumano/10)+(int)(espirituEmprendedor/10)+(int)(integridadAcademica/10))/2);
      cout<<endl<<"Has golpeado al atacante."<<endl;
    }
  }
  else
  {
    pt.SubirPuntos(((int)(sentidoHumano/10)+(int)(espirituEmprendedor/10)+(int)(integridadAcademica/10))/2);
    cout<<endl<<"Has golpeado al enemigo."<<endl;
  }
  pt.setUso("disminuir");
  return pt;
}

void Jugador::getStats() //Enlista las estadísticas del jugador
{
  cout<<endl<<endl<<"-----------------"<<endl;
  cout<<"---ESTADÍSTICAS--";
  cout<<endl<<"-----------------"<<endl;
  cout<<"Vida: "<<getSalud()<<endl;
  cout<<"Inteligencia: "<<inteligencia<<endl;
  cout<<"Carisma: "<<carisma<<endl;
  cout<<"Destreza: "<<destreza<<endl;
  cout<<"------------------";
  cout<<endl<<"-TEC-ESTADÍSTICAS-"<<endl;
  cout<<"------------------"<<endl;
  cout<<"Sentido Humano: "<<sentidoHumano<<endl;
  cout<<"Espíritu Emprendedor: "<<espirituEmprendedor<<endl;
  cout<<"Integridad Académica: "<<integridadAcademica<<endl;
  cout<<"-----------------"<<endl;
  cout<<"-----------------"<<endl<<endl;
}
  
void Jugador::setInteligencia(Puntos pt)
{
  if (pt.getTipoP()==INTELLIGENCE)
  {
    if (pt.getUso()=="disminuir")
    {
      inteligencia-=pt.getValor();
      cout<<"Se te han bajado "<<pt.getValor()<<" puntos de inteligencia."<<endl;
    }
    else if(pt.getUso()=="aumentar")
    {
      inteligencia+=pt.getValor();
      cout<<"Se te han subido "<<pt.getValor()<<" puntos de inteligencia."<<endl;
    }
    else if(pt.getUso()=="neutro")
    {
      cout<<"No hay efecto en la inteligencia"<<endl;
    }
  }
  if (inteligencia>50)
  {
    cout<<"No puedes subir más la inteligancia."<<endl;
    inteligencia = 50;
  }
  if (inteligencia<0)
  {
    cout<<"No puedes bajar más la inteligancia."<<endl;
    inteligencia = 0;
  }
}

void Jugador::setCarisma(Puntos pt)
{
  if (pt.getTipoP()==CHARM)
  {
    if (pt.getUso()=="disminuir")
    {
      carisma-=pt.getValor();
      cout<<"Se te han bajado "<<pt.getValor()<<"puntos de carisma."<<endl;
    }
    else if(pt.getUso()=="aumentar")
    {
      carisma+=pt.getValor();
      cout<<"Se te han subido "<<pt.getValor()<<" puntos de carisma."<<endl;
    }
    else if(pt.getUso()=="neutro")
    {
      cout<<"No hay efecto en el carisma."<<endl;
    }
  }
  if (carisma>50)
  {
    cout<<"No puedes subir más el carisma."<<endl;
    carisma = 50;
  }
  if (carisma<0)
  {
    cout<<"No puedes bajar más el carisma"<<endl;
    carisma = 0;
  }
}

void Jugador::setDestreza(Puntos pt)
{
  if (pt.getTipoP()==SKILL)
  {
    if (pt.getUso()=="disminuir")
    {
      cout<<"Se te han bajado "<<pt.getValor()<<" puntos de destreza."<<endl;
      destreza-=pt.getValor();
    }
    else if(pt.getUso()=="aumentar")
    {
      cout<<"Se te han subido "<<pt.getValor()<<" puntos de destreza."<<endl;
      destreza+=pt.getValor();
    }
    else if(pt.getUso()=="neutro")
    {
      cout<<"No hay efecto en la destreza"<<endl;
    }
  }
  if (destreza>50)
  {
    cout<<"No puedes subir más la destreza"<<endl;
    destreza = 50;
  }
  if (destreza<0)
  {
    cout<<"No puedes bajar más la destreza"<<endl;
    destreza = 0;
  }
}

void Jugador::setSentidoHumano(Puntos pt)
{
  if (pt.getTipoP()==SENSE)
  {
    if (pt.getUso()=="disminuir")
    {
      cout<<"Se te han bajado "<<pt.getValor()<<" puntos de sentido humano."<<endl;
      sentidoHumano-=pt.getValor();
    }
    else if(pt.getUso()=="aumentar")
    {
      cout<<"Se te han subido "<<pt.getValor()<<" puntos de sentido humano."<<endl;
      sentidoHumano+=pt.getValor();
    }
    else if(pt.getUso()=="neutro")
    {
      cout<<"No hay efecto en el sentido humano."<<endl;
    }
  }
  if (sentidoHumano>50)
  {
    cout<<"No puedes subir más el sentido humano"<<endl;
    sentidoHumano = 50;
  }
  if (sentidoHumano<0)
  {
    cout<<"No puedes bajar más el sentido humano"<<endl;
    sentidoHumano = 0;
  }
}

void Jugador::setEspirituEmprendedor(Puntos pt)
{
  if (pt.getTipoP()==SPIRIT)
  {
    if (pt.getUso()=="disminuir")
    {
      cout<<"Se te han bajado "<<pt.getValor()<<" puntos de espíritu emprendedor."<<endl;
      sentidoHumano-=pt.getValor();
      espirituEmprendedor-=pt.getValor();
    }
    else if(pt.getUso()=="aumentar")
    {
      cout<<"Se te han subido "<<pt.getValor()<<" puntos de espíritu emprendedor."<<endl;
      espirituEmprendedor+=pt.getValor();
    }
    else if(pt.getUso()=="neutro")
    {
      cout<<"No hay efecto en el espíritu emprendedor."<<endl;
    }
  }
  if (espirituEmprendedor>50)
  {
    cout<<"No puedes subir más el espíritu emprendedor."<<endl;
    espirituEmprendedor = 50;
  }
  if (espirituEmprendedor<0)
  {
    cout<<"No puedes bajar más el espíritu emprendedor."<<endl;
    espirituEmprendedor = 0;
  }
}

void Jugador::setIntegridadAcademica(Puntos pt)
{
  if (pt.getTipoP()==INTEGRITY)
  {
    if (pt.getUso()=="disminuir")
    {
      cout<<"Se te han bajado "<<pt.getValor()<<" puntos de integridad académica."<<endl;
      integridadAcademica-=pt.getValor();
    }
    else if(pt.getUso()=="aumentar")
    {
      cout<<"Se te han subido "<<pt.getValor()<<" puntos de integridad académica."<<endl;
      integridadAcademica+=pt.getValor();
    }
    else if(pt.getUso()=="neutro")
    {
      cout<<"No hay efecto en la integridad académica."<<endl;
    }
  }
  if (integridadAcademica>50)
  {
    cout<<"No puedes subir más la integridad académica."<<endl;
    integridadAcademica = 50;
  }
  if (integridadAcademica<0)
  {
    cout<<"No puedes bajar más la integridad académica."<<endl;
    integridadAcademica = 0;
  }
}

float Jugador::getInteligencia()
{
  return inteligencia;
}

float Jugador::getCarisma()
{
  return carisma;
}

float Jugador::getDestreza()
{
  return destreza;
}

float Jugador::getSentidoHumano()
{
  return sentidoHumano;
}

float Jugador::getEspirituEmprendedor()
{
  return espirituEmprendedor;
}

float Jugador::getIntegridadAcademica()
{
  return integridadAcademica;
}

void Jugador::CambiarStamina()
{
  if(stamina==true){stamina = false;}
  else{stamina = true;}
}

bool Jugador::getStamina()
{
  return stamina;
}

void Jugador::AgregarInventario(Objeto *objt)
{
  if (contInventario<5) 
  {
    inventario[0]=objt;
    contInventario++;
    cout<<"Se guardó objeto en el inventario."<<endl;
  }
  else
  {
    cout<<"No se pudo guardar objeto, el inventario está lleno."<<endl;
  }
}

void Jugador::MostrarInventario()
{
  cout<<"En tu inventario tienes:"<<endl;
  for(int i=0;i<contInventario;i++)
  {
    cout<<"-"<<inventario[i]->getNombre()<<endl;
  }
  if(contInventario==0){cout<<"- Nada"<<endl;}
}

#endif
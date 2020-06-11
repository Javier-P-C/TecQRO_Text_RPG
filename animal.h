#ifndef ANIMAL_H
#define ANIMAL_H

#include <iostream>
#include <sstream>

#include "personaje.h"

//Cada que crees un animal se debe determinar su hostilidad
class Animal : public Personaje //gato, perro, ave
{
  private:
  Especie especie; //Ir a rpg.h para mayor información de Especie
  bool hostilidad;
  
  public:
  void DeterminarHostilidad(Puntos* spirit_pt); //Recibe los puntos de sentido humano del jugador
  void Huir(); //Acaba con la interacción con el jugador puede tirar un objeto
  void getDescripcion();//Sobrecarga del original
  void Hablar();
  string getstrTipoPersonaje();
  string getstrEspecie();//Manda un string en base a la especie
  bool getHostilidad();
  Puntos Acariciar(); //Puede dar puntos de sentido humano o daño dependideno del animal
  Puntos Atacar();


  //Constructores
  Animal(string name,Especie specie);//Usa los parametros, salud a 50
  Animal(string name);
  Animal(Especie specie);
  Animal();

  //Detructor
  ~Animal();
};

Animal::Animal(string name,Especie specie)
      :Personaje(name)
{
  tipoPersonaje = 1;
  Puntos puntosAjuste(HEALTH,75);
  puntosAjuste.setUso("disminuir");
  setSalud(&puntosAjuste);
  puntosAjuste.~Puntos();
  hostilidad = false;
  if(specie==GATO)
  {
    especie = GATO;
    descripcion="Un gato, cuatro patas, peludo, orejas, ya sabes... un gato. Son comunes en el campus.";
  }
  else if (specie==PERRO)
  {
    especie = PERRO;
    descripcion = "El mejor amigo del hombre, si te ataca debes considerar que tan buena persona eres";
  }
  else if (specie==AVE)
  {
    especie = AVE;
    descripcion = "Pequeño, con plumas, vuela";
  }
}

Animal::Animal(Especie specie)
       :Personaje("---")
{
  tipoPersonaje = 1;
  Puntos puntosAjuste(HEALTH,75);
  puntosAjuste.setUso("disminuir");
  setSalud(&puntosAjuste);
  puntosAjuste.~Puntos();
  hostilidad = false;
  
  if(specie==GATO)
  {
    especie = GATO;
    descripcion="Un gato, cuatro patas, peludo, orejas, ya sabes... un gato. Son comunes en el campus.";
  }
  else if (specie==PERRO)
  {
    especie = PERRO;
    descripcion = "El mejor amigo del hombe, si te ataca debes considerar que tan buena persona eres";
  }
  else if (specie==AVE)
  {
    especie = AVE;
    descripcion = "Pequeño, con plumas, vuela";
  }
}

Animal::Animal(string name)
      :Personaje(name)
{
  tipoPersonaje = 1;
  hostilidad = false;
  especie = NA;
}

Animal::Animal()
       :Personaje()
{
  tipoPersonaje = 1;
  especie = NA;
  hostilidad = false;
}

Animal::~Animal()
{
}

void Animal::Huir()
{
  cout<<"El "<<getstrEspecie()<<" ha huido"<<endl;
  CambiarVisibilidad();
}

void Animal::getDescripcion()
{
  Personaje::getDescripcion();
  cout<<"ESPECIE: "<<getstrEspecie()<<endl;
  cout<<"SALUD: "<<getSalud()<<endl;
  cout<<"HOSTIL: ";
  if (hostilidad==true)
  {
    cout<<"Sí"<<endl;
  }
  else
  {
    cout<<"No"<<endl;
  }
  cout<<"-----------------"<<endl;
}

void Animal::DeterminarHostilidad(Puntos* spirit_pt)
{
  if (especie==(GATO||AVE))
  {
    if (spirit_pt->getValor()<25)
    {
      hostilidad = true;
    }
    else
    {
      hostilidad = false;
    }
  }
  else if (especie==PERRO)
  {
    if (spirit_pt->getValor()<15)
    {
      hostilidad = true;
    }
    else
    {
      hostilidad = false;
    }
  }
}

string Animal::getstrEspecie()
{
  string esp;
  if(especie==GATO)
  {
    esp = "gato";
  }
  else if(especie==PERRO)
  {
    esp = "perro";
  }
  else if(especie==AVE)
  {
    esp = "ave";
  }
  return esp;
}

bool Animal::getHostilidad()
{
  return hostilidad;
}

Puntos Animal::Acariciar()
{
  if(especie==GATO)
  {
    cout<<"Al gato no le gusto tu caricia te ha rasguñado."<<endl;
    Puntos pt(HEALTH,5);
    pt.setUso("disminuir");
    Huir();
    return pt;
  }
  else if(especie==PERRO)
  {
    cout<<"Has alegrado al perro."<<endl;
    Puntos pt(SPIRIT,5);
    pt.setUso("aumentar");
    return pt;
  }
  else if(especie==AVE)
  {
    cout<<"El ave se ha ido."<<endl;
    Puntos pt(NP,0);
    Huir();
    return pt;
  }
}

void Animal::Hablar()
{
  if(especie==GATO)
  {
    cout<<"Miau... Miauuu..."<<endl;
  }
  else if(especie==PERRO)
  {
    cout<<"Guau, guau..."<<endl;
  }
  else if(especie==AVE)
  {
    cout<<"..."<<endl;
  }
}

Puntos Animal::Atacar()
{
  if(especie==GATO)
  {
    cout<<"El gato lanza un zarpazo."<<endl;
    Puntos pt(HEALTH,5);
    pt.setUso("disminuir");
    //pt.getPropiedades();
    return pt;
  }
  else if(especie==PERRO)
  {
    cout<<"El perro te ha mordido."<<endl;
    Puntos pt(HEALTH,8);
    pt.setUso("disminuir");
    return pt;
  }
}

string Animal::getstrTipoPersonaje()
{
  stringstream aux;
  aux<<"Animal ("<<getstrEspecie()<<")";
  return aux.str();
}

#endif
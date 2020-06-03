#ifndef ANIMAL_H
#define ANIMAL_H

#include <iostream>

#include "personaje.h"

//Cada que crees un animal se debe determinar su hostilidad
class Animal : public Personaje
{
  private:
  Especie especie;
  bool hostilidad;
  
  public:
  void DeterminarHostilidad(Puntos* spirit_pt); //Recibe los puntos de sentido humano del jugador
  void Huir(); //Acaba con la interacción con el jugador puede tirar un objeto
  void getDescripcion();//Sobrecarga del original
  void Hablar();
  string getEspecie();//Manda un string en base a la especie
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
  Puntos puntosAjuste(DAMAGE,75);
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
  Puntos puntosAjuste(DAMAGE,50);
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
  hostilidad = false;
  especie = NA;
}

Animal::Animal()
       :Personaje()
{
  especie = NA;
  hostilidad = false;
}

Animal::~Animal()
{
}

void Animal::Huir()
{
  cout<<"El "<<getEspecie()<<" ha huido"<<endl;
  CambiarVisibilidad();
}

void Animal::getDescripcion()
{
  Personaje::getDescripcion();
  cout<<"ESPECIE: "<<getEspecie()<<endl;
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
  cout<<"-----------------"<<endl<<endl;
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

string Animal::getEspecie()
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
    Puntos pt(DAMAGE,5);
    Huir();
    return pt;
  }
  else if(especie==PERRO)
  {
    cout<<"Has alegrado al perro."<<endl;
    Puntos pt(SPIRIT,5);
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
    Puntos pt(DAMAGE,5);
    return pt;
  }
  else if(especie==PERRO)
  {
    cout<<"El perro te ha mordido."<<endl;
    Puntos pt(DAMAGE,8);
    return pt;
  }
}

#endif
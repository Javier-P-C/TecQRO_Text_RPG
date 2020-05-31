#ifndef ANIMAL_H
#define ANIMAL_H

#include <iostream>

#include "personaje.h"

class Animal : public Personaje
{
  protected:
  string especie;

  private:
  bool hostilidad;

  public:
  virtual float Acariciar()=0; //Puede dar puntos de sentido humano o daño dependideno del animal
  virtual void Huir(); //Acaba con la interacción con el jugador puede tirar un objeto
  void getDescripcion();
  virtual void DeterminarHostilidad(float puntos); //Recibe los puntos de sentido humano del jugador
  string getEspecie();
  virtual float darPuntos(); //Da puntos de destreza o sentido humano

  //Constructores
  Animal(string name,string specie);//Usa los parametros, salud a 50
  Animal(string specie);
  Animal();

  //Detructor
  ~Animal();
};

Animal::Animal(string name,string specie)
      :Personaje(name)
{
  especie = specie;
  hostilidad = false;
}

Animal::Animal(string specie)
      :Personaje("---")
{
  especie = specie;
  hostilidad = false;
}

Animal::Animal()
       :Personaje()
{
  especie = "";
  hostilidad = false;
}

Animal::~Animal()
{
}

void Animal::Huir()
{
  cout<<"El "<<especie<<" ha huido"<<endl;
}

void Animal::getDescripcion()
{
  Personaje::getDescripcion();
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

void Animal::DeterminarHostilidad(float puntos)
{
  if (puntos<25)
  {
    hostilidad = true;
  }
  else
  {
    hostilidad = false;
  }
}

string Animal::getEspecie()
{
  return especie;
}

float Animal::darPuntos()
{
  return 3;
}

#endif
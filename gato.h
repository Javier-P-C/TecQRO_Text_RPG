#ifndef GATO_H
#define GATO_H

#include <iostream>

#include "personaje.h"
#include "animal.h"

class Gato : public Animal
{
  private:
  
  public:
  float Atacar(); //Manda los puntos de daño
  //virtual void Interactuar()=0; //Permite al jugador interactuar
  //virtual float Batalla(); //Crea la batalla entre el jugador
  void Hablar();
  float Acariciar(); 

  //Constructores
  Gato(string name);
  Gato();

  //Destructor
  ~Gato();
};

Gato::Gato(string name)
     :Animal(name)
{
  especie = "gato";
  descripcion="Un gato, cuatro patas, peludo, orejas, ya sabes... un gato. Son comunes en el campus.";
}

Gato::Gato()
     :Animal()
{
  especie = "gato";
  descripcion = "Un gato, cuatro patas, peludo, orejas, ya sabes... un gato. Son comunes en el campus.";
}

Gato::~Gato()
{
}

float Gato::Atacar()
{
  return 5;
}

void Gato::Hablar()
{
  cout<<"Miau... Miauuu..."<<endl;
}

float Gato::Acariciar()
{
  cout<<"Al gato no le gusto tu caricia te ha rasguñado"<<endl;
  Huir();
  return 5;
}

#endif
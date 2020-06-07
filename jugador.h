#ifndef JUGADOR_H
#define JUGADOR_H

#include <iostream>

#include "personaje.h"
#include "miembrotec.h"
#include "rpg.h"

using namespace std;

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

  public:
  float Atacar();
  
};

#endif
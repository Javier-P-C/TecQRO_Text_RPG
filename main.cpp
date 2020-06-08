#include <iostream>

#include "personaje.h"
#include "animal.h"
#include "objeto.h"
#include "puntos.h"
#include "enemigo.h"
#include "jugador.h"
#include "miembrotec.h"
#include "rpg.h"

using namespace std;
using namespace listasrpg;

void static Interactuar(Animal* gato);

int main(int argc, char* argv[])
{
  Animal gato(GATO);
  gato.getDescripcion();
  Interactuar(&gato);
  gato.getDescripcion();
  Puntos pt = gato.Atacar();
  pt.getPropiedades();
  gato.DamageReceived(&pt);
  gato.getDescripcion();
  return 0;
}

void static Interactuar(Animal* gato)
{
Puntos pt(HEALT,10);
pt.setUso("disminuir");
 gato->setSalud(&pt);
}
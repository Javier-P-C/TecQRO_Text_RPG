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
void static Obtener(Objeto* objt);

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

  Objeto objt1("H","h");
  Objeto *arrObj = new Objeto[2];
  arrObj[1]=objt1;
  cout<<(arrObj)->getNombre()<<endl<<endl;

   Objeto objt2("R","r");
   cout<<objt2.getNombre()<<endl;
   Obtener(&objt2);
   cout<<objt2.getNombre()<<endl;
  return 0;
}

void static Interactuar(Animal* gato)
{
  Puntos pt(HEALTH,10);
  pt.setUso("disminuir");
  gato->setSalud(&pt);
}

void static Obtener(Objeto* objt)
{
  objt->setNombre("Romeo");
}
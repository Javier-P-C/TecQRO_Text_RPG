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

void static Interactuar(Gato* gato);

int main(int argc, char* argv[])
{
  Gato gato1("Pedro");
  cout<<gato1.getSalud()<<endl;
  Interactuar(&gato1);
  cout<<gato1.getSalud()<<endl;
  Objeto objeto1("manzana", "roja brillante",DAMAGE, 5);
  Puntos pt = objeto1.getPuntos();
  TipoPuntos tp = pt.getTipoP();
  cout<<""<<tp<<endl;

  return 0;
}

void static Interactuar(Gato* gato)
{
  gato->setSalud(3,DAMAGE);
  cout<<gato->getSalud()<<endl;

}
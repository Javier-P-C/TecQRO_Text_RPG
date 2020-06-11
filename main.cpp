/*-----------------------------------------
          Instrucciones archivos
-------------------------------------------
-Declarar Personajes:
  Animales: int_tipoPersonaje,int_enum_tipoAnimal
  Enemigo: char_tipoPersonaje,int_enum_tipoEnemigo
  Miembro Tec: char_tipoPersonaje,int_enum_AreaTec,string_nombre,string_matricula,string_posicion
-Declarar Objetos:
  Objeto: int_tipoPuntos,string_nombre,string descripcion,float_cantPuntos
-Declarar Escenarios:
  Escenario: string_nombre!string_descripcion
*/

#include <iostream>
#include <sstream>
#include <fstream>

#include "utility.h"

#include "personaje.h"
#include "animal.h"
#include "objeto.h"
#include "puntos.h"
#include "enemigo.h"
#include "jugador.h"
#include "miembrotec.h"
#include "escenario.h"
#include "rpg.h"


using namespace std;
using namespace listasrpg;

int main(int argc, char* argv[])
{
  string line;
  int cont = 0;
  ifstream myFile;//objeto ifstream
  vector<string> tokens;//Donde se van a guardar los elementos de las líneas
  Escenario *scene[18];
  myFile.open("carga_de_escenarios.csv");//Abre el archivo
  if (myFile.is_open())//Comprueba que está abierto el archivo
  {
    getline(myFile,line);
    tokens = split(line, '!');
    cont = stoi(tokens[0]);
    for(int i=0;i<cont;i++)
    {
      getline(myFile,line);
      tokens = split(line, '!');
      cout<<"Llegue"<<endl;
      scene[i] = new Escenario(tokens[0],tokens[1]);
      cout<<scene[i]->getNombre()<<endl;
    }
  }
  else
  {
    cout<<"Error"<<endl;
  }
  myFile.close();
  for (int i=0;i<cont;i++)
  {
    cout<<scene[i]->getNombre()<<", "<<scene[i]->getDescripcion()<<endl<<endl;
  }
  scene[3]->getObjetos();
  scene[3]->getPersonajes();
  return 0;
}
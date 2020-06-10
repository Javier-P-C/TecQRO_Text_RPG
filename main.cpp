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
  Objeto *objt_dos = new Objeto("M","m");
  Objeto *arrObj[2];
  arrObj[0]=objt_dos;
  cout<<arrObj[0]->getNombre()<<endl<<endl;


  /*Objeto *objt;
  objt = new Objeto();
  Objeto ob("a","b",HEALTH,34);
  objt = &ob;
  delete objt;*/
  /*string line;
  ifstream myFile;//objeto ifstream
  vector<string> tokens;//Donde se van a guardar los elementos de las líneas
  Escenario *scene;
  myFile.open("archivo_de_juego.csv");//Abre el archivo
  if (myFile.is_open())//Comprueba que está abierto el archivo
  {
    getline(myFile,line);
		tokens = split(line, ',');
    scene = new Escenario(tokens[1],tokens[2],tipoP,stof(tokens[3]));
  }
  else
  {
    cout<<"Error"<<endl;
  }
  objt->getPropiedades();*/
  
  return 0;
}

/*-----------------------------------------
          Instrucciones archivos
-------------------------------------------
-Declarar Personajes:
  Animales: int_tipoPersonaje,int_enum_tipoAnimal
  Enemigo: char_tipoPersonaje,int_enum_tipoEnemigo
  Miembro Tec: char_tipoPersonaje,int_enum_AreaTec,string_nombre,string_matricula,string_posicion
-Declarar Objetos:
  Objeto: int_tipoPuntos,string_nombre,string descripcion,float_cantPuntos
*/
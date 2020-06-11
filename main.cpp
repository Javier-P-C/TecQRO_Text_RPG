/*-----------------------------------------
          Instrucciones archivos
-------------------------------------------
*Los enum tipoAlgo los puedes encontrar en el archivo rpg.h
-Declarar Personajes:
  Animales: int_tipoPersonaje(1),int_enum_tipoAnimal
  Enemigo: int_tipoPersonaje(2),int_enum_tipoEnemigo
  Miembro Tec: int_tipoPersonaje(3),int_enum_AreaTec,string_nombre,string_matricula,string_posicion
  +Antes del personaje debes especificar el nombre del escenario donde se va a cargar y el número de personajes que hay declarados. Ambas cosas separadas por comas.
-Declarar Objetos:
  Objeto: int_tipoPuntos,string_nombre,string descripcion,float_cantPuntos
  +Antes del objeto debes especificar el nombre del escenario donde se va a cargar y el número de objetos que hay declarados. Ambas cosas separadas por comas.
-Declarar Escenarios:
  Escenario: string_nombre!string_descripcion
-Declarar un Jugador
  Jugador: string_nombre,string_descripcion,srtring_matricula,AreaTec_area(Mayusculas),string_posicion,float_inteligencia,float_carisma,float_destreza,float_sentidoHumano,float_espirituEmprendedor,float_integridadAcademica
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
#include "engine.h"
#include "rpg.h"


using namespace std;
using namespace listasrpg;

int main(int argc, char* argv[])
{

  /*cout<<endl<<endl<<"............................................"<<endl;
  cout<<"Bienvenido a: TEC QRO: UNA AVENTURA DE ROL"<<endl;
  cout<<"............................................"<<endl;

  //Menu
  cout<<"1.Jugar"<<endl;
  cout<<"2.Créditos"<<endl;
  cout<<"3.Comandos del juego"<<endl;
  cout<<"4.Tutorial"<<endl;
  cout<<"............................................"<<endl<<endl;*/

  //Engine partida("carga_de_escenarios.csv","carga_de_objetos.csv","carga_de_personajes.csv",".csv");

  Engine partida("carga_de_escenarios.csv","carga_de_objetos.csv","carga_de_personajes.csv");
  

  return 0;
}
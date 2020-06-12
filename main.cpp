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
-Declarar la Brujula de los escenarios (Los cuartos contiguos)
  -Para que el programa sepa que empieza la declaración de una brújula se pone STOP,string_NombreDelEscenario
  -Luego se pone el identificador de dirección (Norte-0, Sur-1, Este-2, Oeste-3) y el nombre del escenario de corresponde a esa dirección
  int_identificador,string_nombre
*/

//Caso correcto, caso nulo y caso incorrecto

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

  Engine partida("carga_de_escenarios.csv","carga_de_objetos.csv","carga_de_personajes.csv","jugador_guardado.csv","carga_brujula_escenarios.csv");
  //partida.Guardar();
  //partida.MostrarTodo();
  partida.Comandos();
  //partida.~Engine();

  //Engine partida("carga_de_escenarios.csv","carga_de_objetos.csv","carga_de_personajes.csv");
  
  
  /*Escenario *scene;
  scene = new Escenario("Residencias","DESCRIPCION");

  string line;
  int count = 0;
  ifstream myFile;//objeto ifstream
  vector<string> tokens;//Donde se van a guardar los elementos de las líneas
  myFile.open("carga_brujula_escenarios.csv");
  if (myFile.is_open())//Comprueba que está abierto el archivo
  {
    bool encontrado = false;
    
    do
    {
      getline(myFile,line);
      tokens = split(line, ',');
      if ((tokens[0]=="STOP")&&(tokens[1]==scene->getNombre()))
      {
        encontrado = true;
      }
      //cout<<tokens[0]<<endl; //Línea para debuguear
    }while(((tokens[0]!="STOP")||(tokens[1]!=scene->getNombre())) && !myFile.eof());
    
    if (encontrado == false)
    {
      cout<<endl<<"ERROR: Nombre de escenario, no encontrado en archivo para cargar brújula. Escenario()"<<endl<<endl;
      goto exit; //40 líneas abajo
    }
    for(int i=0;i<4;i++)
    {
      getline(myFile,line);
      tokens = split(line, ',');
      Escenario *lugar;
      lugar= partida.getDireccion(tokens[1]);
      string dir;
      cout<<"CheckR"<<tokens[0]<<endl;
      if(stoi(tokens[0])==0){dir="norte";}
      else if(stoi(tokens[0])==1){dir="sur";}
      else if(stoi(tokens[0])==2){dir="este";}
      else if(stoi(tokens[0])==3){dir="oeste";}
      scene->AgregarBrujula(dir,lugar);
    }
    cout<<"CheckM"<<endl;
    scene->getBrujula();
  }
  else
  {
    cout<<"Archivo no encontrado"<<endl;
  }
  exit: myFile.close();
  cout<<"Cerrado"<<endl;*/
  return 0;
}
/*-----------------------------------------
          Instrucciones archivos
-------------------------------------------
*Los enum tipoAlgo los puedes encontrar en el archivo rpg.h
-Declarar Personajes:
  Animales: int_tipoPersonaje(1),int_enum_tipoAnimal
  Enemigo: int_tipoPersonaje(2),int_enum_tipoEnemigo
        -Si quieres declara un BOSS se hace de la siguiente manera
        BOSS: int_tipoPersonaje(2),int_enum_tipoEnemigo,string_nombre,string_descripcion
  Miembro Tec: int_tipoPersonaje(3),int_enum_AreaTec,string_nombre,string_matricula,string_posicion
  +Antes del personaje debes especificar el nombre del escenario donde se va a cargar y el número de personajes que hay declarados. Ambas cosas separadas por comas.
-Declarar Objetos:
  Objeto: int_tipoPuntos,string_nombre,string descripcion,float_cantPuntos
  +Antes del objeto debes especificar el nombre del escenario donde se va a cargar y el número de objetos que hay declarados. Ambas cosas separadas por comas.
-Declarar Escenarios:
  Escenario: string_nombre!string_descripcion
-Declarar un Jugador
  Jugador: string_nombre,string_descripcion,srtring_matricula,AreaTec_area(Mayusculas),string_posicion,float_inteligencia,float_carisma,float_destreza,float_sentidoHumano,float_espirituEmprendedor,float_integridadAcademica

//////La opción de brújula no lo permite la memoria del sitema, se queda pendiente para actualizaciones (Cuando entiendo como pedirle memoria al sitema) (Última versión con brújula: Último commit de 11 de junio 2020 en github)
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

  

  //Menu
  int elegir,auxiliar;
  while(elegir!=5)
  {
    cout<<endl<<endl<<"............................................"<<endl;
    cout<<"Bienvenido a: TEC QRO: UNA AVENTURA DE ROL"<<endl;
    cout<<"Menú"<<endl;
    cout<<"............................................"<<endl;
    cout<<"1.Nueva Partida"<<endl;
    cout<<"2.Partida Guardada"<<endl;
    cout<<"3.Comandos del juego (Instrucciones)"<<endl;
    cout<<"4.Créditos"<<endl;
    cout<<"5.Salir"<<endl;
    cout<<"............................................"<<endl<<endl;
    cin>>elegir;
    cout<<endl;

    if(elegir==1)
    {
      Engine partida("carga_de_escenarios.csv","carga_de_objetos.csv","carga_de_personajes.csv");
      partida.Comandos();
      partida.~Engine();
    }

    else if(elegir==2)
    {
      Engine partida("carga_de_escenarios.csv","carga_de_objetos.csv","carga_de_personajes.csv","jugador_guardado.csv");
      partida.Comandos();
      partida.~Engine();
    }

    else if(elegir==3)
    {
      string line;
      ifstream myFile;//objeto ifstream
      vector<string> tokens;
      myFile.open("instrucciones.txt");//Abre el archivo
      if (myFile.is_open()) 
      {
        while(!myFile.eof()) //Mientras el archivo no haya acabado
        {
          getline(myFile,line);
          cout<<line<<endl;
        }
      }
      else{cout<<"ERROR";}
      myFile.close();
    }

    else if(elegir==4)
    {
      string line;
      ifstream myFile;//objeto ifstream
      vector<string> tokens;
      myFile.open("creditos.txt");//Abre el archivo
      if (myFile.is_open()) 
      {
        while(!myFile.eof()) //Mientras el archivo no haya acabado
        {
          getline(myFile,line);
          cout<<line<<endl;
        }
      }
      else{cout<<"ERROR";}
      myFile.close();
    }
    cout<<"Presione un NÚMERO para continuar"<<endl;
    cin>>auxiliar;
    cout<<endl;
  }
  //partida.Guardar();
  //partida.MostrarTodo(); //Nos aseguramos que la carga haya sido correcta
  //partida.Comandos();
  //partida.GameOver();
  return 0;
}
#ifndef ESCENARIO_H
#define ESCENARIO_H

#include <iostream>
#include <sstream>

#include "utility.h"

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

class Escenario
{
  private:
  string nombre;
  string descripcion;
  int unsigned contP,contOb; //Contadores personajes, objetos
  Personaje *individuos[4];
  Objeto *objts[2];
  //Escenario *brujula[4]; //Guarda los escenarios contiguos [0]=NORTE, [1]=SUR, [2]=ESTE, [3]=OESTE

  public:
  string getNombre();//Manda el atributo nombre del escenario
  string getDescripcion();//Manda el atributo descripcion del escenario
  void getPersonajes(); //Imprime la lista de los personajes visibles
  void AgregarPersonaje(Personaje *per);//Se agrega un personaje al escenario
  void getObjetos();//Imprime la lista de los objetos visibles
  void AgregarObjetos(Objeto *articulo); //Se agrega un objeto al escenario
  void getBrujula(); //Muestra los cuartos cercanos
  void AgregarBrujula(string direccion,Escenario *lugar);
  void CargarObjetos(string archivo); //Carga objetos que vienen de un archivo
  void CargarPersonajes(string archivo); //Carga personajes que vienen de un archivo
  void printContadores(); //Imprime el valor de los contadores contOb y contP
  Personaje* DireccionPersonaje(int num);//Le manda el personaje que necesite Engine()
  bool DisponibilidadPersonajes();//Manda un true si al menos un personaje está visible si no manda un false
  Objeto* DireccionObjeto(int num);//Le manda la dirección del objeto al jugador
  bool DisponibilidadObjetos();

  //Constructores
  Escenario(string name, string description);
  Escenario();

  //Destructor
  ~Escenario();
};

Escenario::Escenario(string name, string description)
{
  nombre = name;
  descripcion = description;
  contP = 0;
  contOb = 0;
  /*for (int i=0;i<4;i++)
  {
    brujula[i] = new Escenario();
  }*/
}

Escenario::Escenario()
{
  nombre = "";
  descripcion = "";
  contP = 0;
  contOb = 0;
}

Escenario::~Escenario()
{
  if(contP>4){contP=4;}
  else if(contP<0){contP=0;}
  if(contOb>2){contOb=2;}
  else if(contOb<0){contOb=0;}
  cout<<"contadores"<<contP<<","<<contOb<<endl;
  cout<<"Destructor de Escenario fue llamado"<<endl;
  for(int i=0;i<contP;i++)
  {
    delete individuos[i];
  }
  for (int i=0;i<contOb;i++)
  {
    delete objts[i];
  }
  for (int i=0;i<4;i++)
  {
    //delete brujula[i];
  }
  contP = 0;
  contOb = 0;
}

string Escenario::getNombre()
{
  return nombre;
}

string Escenario::getDescripcion()
{
  return descripcion;
}

void Escenario::getPersonajes()
{
  stringstream aux;
  if (contP>0)
  {
    aux<<endl<<"-----------------"<<endl;
    aux<<"En '"<<nombre<<"' se encuentran: "<<endl;
    for (int i=0;i<contP;i++)
    {
      if (individuos[i]->getVisibilidad()==true)
      {
        aux<<"("<<i<<")"<<individuos[i]->getstrTipoPersonaje()<<endl;
      }
    }
    aux<<endl;
  }
  else
  {
    aux<<endl<<"-----------------"<<endl;
    aux<<"No hay nadie en este lugar."<<endl<<endl;
  }
  cout<<aux.str();
}

void Escenario::AgregarPersonaje(Personaje *per)
{
  if (contP!=4)
  {
    if(per->getTipoPersonaje()==1)
    {
      individuos[contP] = new Animal();
      individuos[contP] = per;
      contP++;
      //cout<<contP<<endl;//Línea para debuguear
    }
    else if(per->getTipoPersonaje()==2)
    {
      individuos[contP] = new Enemigo();
      individuos[contP] = per;
      contP++;
      //cout<<contP<<endl;//Línea para debuguear
    }
    else if(per->getTipoPersonaje()==3)
    {
      individuos[contP] = new MiembroTec();
      individuos[contP] = per;
      contP++;
      //cout<<contP<<endl;//Línea para debuguear
    }
    else
    {
      cout<<"Personaje no especificado, no se pudo agregar a individuos[] en clase Escenario()"<<endl;
    }
  }
  else
  {
    cout<<"ERROR:Arreglo individuos[] lleno, no se puede agregar personaje "<<per->getTipoPersonaje()<<" en clase Escenario()"<<endl;
  }
}

void Escenario::getObjetos()
{
  stringstream aux;
  if(contOb>0)
  {
    aux<<"-----------------"<<endl;
    aux<<"En '"<<nombre<<"' puedes ver los siguientes objetos: "<<endl;
    //cout<<contOb<<endl;
    for (int i=0;i<contOb;i++)
    {
      if (objts[i]->getVisibilidad()==true)
      {
        aux<<"("<<i<<")"<<objts[i]->getNombre()<<endl;
      }
    }
    aux<<endl;
  }
  else
  {
    aux<<"-----------------"<<endl;
    aux<<"En '"<<nombre<<"' no ves objetos que puedas recoger."<<endl;
  }
  cout<<aux.str();
}

void Escenario::AgregarObjetos(Objeto *articulo)
{
  if(contOb<2)
  {
    objts[contOb] = new Objeto();
    objts[contOb] = articulo;
    //cout<<"Objeto agregado a "<<nombre<<endl; //Línea para debuguear
    contOb++;
    //cout<<""<CONTADOR: <<contOb<<endl; //Línea para debuguear
  }
  else
  {
    cout<<"ERROR:Arreglo objts[] lleno, no se puede agregar objeto en clase Escenario()"<<endl;
  }
}

/*void Escenario::AgregarBrujula(string direccion,Escenario *lugar)
{
  if(direccion=="norte")
  {
    cout<<"Recibido"<<lugar->getNombre()<<lugar;
    brujula[0] = lugar;
  }
  else if(direccion=="sur")
  {
    lugar->getNombre();
    brujula[1] = lugar;
  }
  else if(direccion=="este")
  {
    lugar->getNombre();
    brujula[2] = lugar;
  }
  else if(direccion=="oeste")
  {
    lugar->getNombre();
    brujula[3] = lugar;
  }
  else
  {
    cout<<"ERROR: No se pudo agregar escenario a la brújula de '"<<nombre<<"' porque la direccion no corresponde con ninguno de los puntos cardinales. Clase Escenario()"<<endl;
  }
}*/

/*void Escenario::getBrujula()
{
  stringstream aux;
  aux<<"------------------"<<endl;
  aux<<nombre<<"Los cuartos cercanos son: "<<endl;
  for (int i=0;i<4;i++)
  {
    switch(i)
    {
      case 0: aux<<"Norte: "<<brujula[i]->getNombre()<<endl; break;
      case 1: aux<<"Sur: "<<brujula[i]->getNombre()<<endl; break;
      case 2: aux<<"Este: "<<brujula[i]->getNombre()<<endl; break;
      case 3: aux<<"Oeste: "<<brujula[i]->getNombre()<<endl; break;
    }
  }
  aux<<"------------------"<<endl;
  cout<<aux.str();
}*/

void Escenario::CargarObjetos(string archivo)
{
  string line;
  int count = 0;
  ifstream myFile;//objeto ifstream
  vector<string> tokens;//Donde se van a guardar los elementos de las líneas
  myFile.open(archivo);
  if (myFile.is_open())//Comprueba que está abierto el archivo
  {
    bool encontrado = false;
    do
    {
      getline(myFile,line);
      tokens = split(line, ',');
      if (tokens[0]==nombre)
      {
        encontrado = true;
      }
      //cout<<tokens[0]<<endl; //Línea para debuguear
    }while((tokens[0]!=nombre) && !myFile.eof());

    if (encontrado == false)
    {
      cout<<endl<<"ERROR: Nombre de escenario,"<<nombre<<", no encontrado en archivo para carga de objetos. Clase Escenario()"<<endl<<endl;
      goto exit; //20 líneas abajo
    }
    count = stoi(tokens[1]);
    for (int i=0;i<count;i++)
    {
      TipoPuntos tipoP;
      Objeto *objeto;
      getline(myFile,line);
      tokens = split(line, ',');
      tipoP = static_cast<TipoPuntos>(stoi(tokens[0]));
      //cout<<"Llegue"<<endl; //Línea para debuguear
      objeto = new Objeto(tokens[1],tokens[2],tipoP,stof(tokens[3]));
      AgregarObjetos(objeto);
    }
  }
  else
  {
    cout<<"ERROR: Archivo para carga de objetos no encontrado en clase Escenario()"<<endl;
  }
  
  exit: myFile.close();
  //cout<<"Cerrado"<<endl; //Línea para debuguear
}

void Escenario::CargarPersonajes(string archivo)
{
  string line;
  int count = 0;
  ifstream myFile;//objeto ifstream
  vector<string> tokens;//Donde se van a guardar los elementos de las líneas
  myFile.open(archivo);
  if (myFile.is_open())//Comprueba que está abierto el archivo
  {
    bool encontrado = false;
    
    do
    {
      getline(myFile,line);
      tokens = split(line, ',');
      if (tokens[0]==nombre)
      {
        encontrado = true;
      }
      //cout<<tokens[0]<<endl; //Línea para debuguear
    }while((tokens[0]!=nombre) && !myFile.eof());
    
    if (encontrado == false)
    {
      cout<<endl<<"ERROR: Nombre de escenario, "<<nombre<< ", no encontrado en archivo para carga de personajes. Escenario()"<<endl<<endl;
      goto exit; //40 líneas abajo
    }
    count = stoi(tokens[1]);
    for (int i=0;i<count;i++)
    {
      Personaje* per;
      getline(myFile,line);
      tokens = split(line, ',');
      switch(stoi(tokens[0]))
      {
        case 1: 
        {
          Especie especie = static_cast<Especie>(stoi(tokens[1]));
          per = new Animal(especie);
          AgregarPersonaje(per);
          break;
        }
        case 2: 
        {
          TipoEnemigo enemy = static_cast<TipoEnemigo>(stoi(tokens[1]));
          if (enemy==BOSS)
          {
            per = new Enemigo(tokens[2],tokens[3],enemy);
            AgregarPersonaje(per);
            break;
          }
          per = new Enemigo(enemy);
          AgregarPersonaje(per);
          break;
        }
        case 3: 
        {
          AreaTec area = static_cast<AreaTec>(stoi(tokens[1]));
          per = new MiembroTec(tokens[2],tokens[3],area,tokens[4]);
          AgregarPersonaje(per);
          break;
        }
      }
    }
  }
  else
  {
    cout<<"ERROR: No se pudo abrir archivo para carga de personajes en clase Escenario()"<<endl;
  }
  
  exit: myFile.close();
  //cout<<"Cerrado"<<endl; //Línea para debuguear
}

void Escenario::printContadores()
{
  cout<<contP<<"-"<<contOb<<endl;
}

Personaje* Escenario::DireccionPersonaje(int num)
{
  Personaje* per;
  per=individuos[num];
  return per;
}

bool Escenario::DisponibilidadPersonajes()
{
  for (int i=0;i<contP;i++)
  {
    if (individuos[i]->getVisibilidad()==true)
    {
      return true;
    }
  }
  return false;
}

Objeto* Escenario::DireccionObjeto(int num)
{
  Objeto* objt;
  objt=objts[num];
  return objt;
}

bool Escenario::DisponibilidadObjetos()
{
  if(contOb==0){return false;}
  for (int i=0;i<contOb;i++)
  {
    if (objts[i]->getVisibilidad()==true){return true;}
  }
  return false;
}

#endif
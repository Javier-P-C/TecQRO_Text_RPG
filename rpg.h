#ifndef RPG_H
#define RPG_H

//Si se agregan más opciones a los enums se deben modificar los metodos getstrEnum() de las clases derivadas de Personaje 
//Si se agrega un nuevo enum se debe agregar el método getstrEnum() en la clase correspondiente
//

namespace listasrpg
{
  //Los nombres de los enums deben ser decriptivos para simplificar la lectura del código
  enum variantes_de_puntos {NP,HEALTH,SPIRIT,SENSE,INTEGRITY,CHARM,INTELLIGENCE,SKILL}; //0-7

  enum especie_animal {NA,GATO,PERRO,AVE}; //0-3

  enum variante_de_enemigos {NE,COLADO,HATER,VALEM,BORRACHO,BOSS}; //0-5

  enum area_del_Tec {NAR,AMBIENTE_CONSTRUIDO,CIENCIAS_SOCIALES,ESTUDIOS_CREATIVOS,INGENIERIAS,NEGOCIOS,SALUD}; //0-6

  //Los typedef simplican la escritura de los enums en el resto del código
  typedef enum variantes_de_puntos TipoPuntos;
  typedef enum especie_animal Especie;
  typedef enum variante_de_enemigos TipoEnemigo;
  typedef enum area_del_Tec AreaTec;
}

#endif
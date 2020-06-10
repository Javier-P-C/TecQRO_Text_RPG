#ifndef RPG_H
#define RPG_H

namespace listasrpg
{
  enum variantes_de_puntos {NP,HEALTH,SPIRIT,SENSE,INTEGRITY,CHARM,INTELLIGENCE,SKILL}; //0-7

  enum especie_animal {NA,GATO,PERRO,AVE}; //0-3

  enum variante_de_enemigos {COLADO,HATER,VALEM,BORRACHO,BOSS}; //0-4

  enum area_del_Tec {NAR,AMBIENTE_CONSTRUIDO,CIENCIAS_SOCIALES,ESTUDIOS_CREATIVOS,INGENIERIAS,NEGOCIOS,SALUD}; //0-6

  typedef enum variantes_de_puntos TipoPuntos;
  typedef enum especie_animal Especie;
  typedef enum variante_de_enemigos TipoEnemigo;
  typedef enum area_del_Tec AreaTec;
}

#endif
#ifndef RPG_H
#define RPG_H

namespace listasrpg
{
  enum variantes_de_puntos {NP,HEALT,SPIRIT,SENSE,INTEGRITY,CHARM,INTELLIGENCE,SKILL};

  enum especie_animal {NA,GATO,PERRO,AVE};

  enum variante_de_enemigos {COLADO,HATER,VALEM,BORRACHO,BOSS};

  enum area_del_Tec {NAR,AMBIENTE_CONSTRUIDO,CIENCIAS_SOCIALES,ESTUDIOS_CREATIVOS,INGENIERIAS,NEGOCIOS,SALUD};

  typedef enum variantes_de_puntos TipoPuntos;
  typedef enum especie_animal Especie;
  typedef enum variante_de_enemigos TipoEnemigo;
  typedef enum area_del_Tec AreaTec;
}

#endif
#ifndef RPG_H
#define RPG_H

namespace listasrpg
{
  enum variantes_de_puntos {NP,DAMAGE,HEALTH,SPIRIT,SENSE,INTEGRITY,CHARM,INTELLIGENCE,SKILL};

  enum especie_animal {NA,GATO,PERRO,AVE};

  enum variante_de_enemigos {COLADO,HATER,VALEM,BORRACHO,BOSS};

  enum variante_de_alumno {NAL,AMBIENTE_CONSTRUIDO,CIENCIAS_SOCIALES,ESTUDIOS_CREATIVOS,INGENIERIAS,NEGOCIOS,SALUD};

  typedef enum variantes_de_puntos TipoPuntos;
  typedef enum especie_animal Especie;
  typedef enum variante_de_enemigos TipoEnemigo;
  typedef enum variante_de_alumno TipoAlumno;
}

#endif
#ifndef RPG_H
#define RPG_H

namespace listasrpg
{
  enum tipo_puntos {NP,DAMAGE,HEALTH,SPIRIT,SENSE,INTEGRITY,CHARM,INTELLIGENCE,SKILL};

  enum especie_animal {NA,GATO,PERRO,AVE};

  enum variante_de_enemigos {COLADO,HATER,VALEM,BORRACHO};

  typedef enum tipo_puntos TipoPuntos;
  typedef enum especie_animal Especie;
  typedef enum variante_de_enemigos TipoEnemigo;
}

#endif
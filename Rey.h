#ifndef REY_H
#define REY_H
#include "Pieza.h"

class Rey: public Pieza{
  public:
    Rey(string,int,string,int,int);
    bool validarMovimiento(int, int,Pieza* Tablero[][8]) override;
    bool esta_En_Jaque(int,int,Pieza* Tablero[][8]);
    bool validarEnroque(string, Pieza* Tablero[][8]);
    string imprime() override;
};

#endif
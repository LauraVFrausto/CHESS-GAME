#ifndef CABALLO_H
#define CABALLO_H
#include "Pieza.h"

class Caballo: public Pieza{
  public:
    Caballo(string etiqueta, int contador, string color, int x, int y);
    bool validarMovimiento(int x, int y, Pieza* Tablero[][8]) override;
    string imprime() override;
};

#endif
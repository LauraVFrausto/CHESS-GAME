#ifndef ALFIL_H
#define ALFIL_H
#include "Pieza.h"

class Alfil: public Pieza{
  public:
    Alfil(string etiqueta, int contador, string color, int x, int y);
    bool validarMovimiento(int x, int y, Pieza* Tablero[][8]) override;
    string imprime() override;
};

#endif
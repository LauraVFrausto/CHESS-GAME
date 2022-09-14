#ifndef REINA_H
#define REINA_H
#include "Pieza.h"

class Reina: public Pieza{
  public:
    Reina(string etiqueta, int contador, string color, int x, int y);
    bool validarMovimiento(int x, int y, Pieza* Tablero[][8]) override;
    string imprime() override;
};

#endif
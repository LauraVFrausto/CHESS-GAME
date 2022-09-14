#ifndef TORRE_H
#define TORRE_H
#include "Pieza.h"

class Torre: public Pieza{
  public:
    Torre(string,int, string, int, int);
    bool validarMovimiento(int x, int y, Pieza* Tablero[][8]) override;
    string imprime() override;
};

#endif
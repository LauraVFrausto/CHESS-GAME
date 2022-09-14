#ifndef PEON_H
#define PEON_H
#include "Pieza.h"

class Peon: public Pieza{
  public:
    Peon(string etiqueta, int contador, string color, int x, int y,bool avanceDoble);
    bool validarMovimiento(int x, int y,Pieza* Tablero[][8]) override;
    bool validarComidaPaso(int,int, Pieza* Tablero[][8]);
    bool getAvanceDoble();
    void setAvanceDoble();
    void setAvanceNormal();
    string imprime() override;

private:
  bool avanceDoble;
};

#endif
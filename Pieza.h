#ifndef PIEZA_H
#define PIEZA_H
#include <iostream>
#include <string>
#include <vector>
#define RED "\e[0;31m"

using namespace std;

class Pieza{
  private:
    string etiqueta,
           color;//0 negro y 1 blanco
    int contador,
        x,
        y;

  public:
    Pieza(string etiqueta, int contador, string color, int x, int y);
    string getEtiqueta();
    int getContador();
    string getColor();
    int getX();
    int getY();
    void setEtiqueta(string etiqueta);
    void setContador(int contador);
    void setColor(string color);
    void setX(int x);
    void setY(int y);
    virtual bool validarMovimiento(int x, int y, Pieza* Tablero[][8])=0;
    virtual string imprime()=0;
};

#endif
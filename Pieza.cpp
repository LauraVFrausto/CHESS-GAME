#include "Pieza.h"

Pieza::Pieza(string etiqueta, int contador, string color, int x, int y){
    this->etiqueta=etiqueta;
    this->contador=contador;
    this->color=color;
    this->x=x;
    this->y=y;
}
string Pieza::getEtiqueta(){
  return etiqueta;
}
int Pieza::getContador(){
  return contador;
}
string Pieza::getColor(){
  return color;
}
int Pieza::getX() {
    return x;
}

int Pieza::getY(){
    return y;
}

void Pieza::setEtiqueta(string etiqueta){
  this->etiqueta=etiqueta;
}

void Pieza::setContador(int contador){
  this->contador=contador;
}

void Pieza::setColor(string color){
  this->color=color;
}

void Pieza::setX(int x){
  this->x=x;
}

void Pieza::setY(int y){
  this->y=y;
}
#include "Caballo.h"

Caballo::Caballo(string etiqueta, int contador, string color, int x, int y):Pieza(etiqueta, contador, color, x, y){}

bool Caballo::validarMovimiento(int x, int y, Pieza* Tablero[][8]){
    int restaX= abs(getX()-x);
    int restaY= abs(getY()-y);
    if (((restaX==2 && restaY==1) || (restaX==1 && restaY==2)) && ((Tablero[y][x]==NULL) || (Tablero[y][x]->getColor()!= getColor()))){
        setX(x);
        setY(y);
        return true;  
    }else{
        return false;
    }
}

string Caballo::imprime(){
   if (getColor()=="Negras"){
        return RED "C";
    } 
    else{
        return "C";
    }
}
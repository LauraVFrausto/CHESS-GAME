#include "Peon.h"

Peon::Peon(string etiqueta, int contador, string color, int x, int y,bool avanceDoble) : Pieza(etiqueta,contador,color,x,y){
  this->avanceDoble=avanceDoble;
}

void Peon::setAvanceDoble( ){
  avanceDoble=true;
}
void Peon::setAvanceNormal(){
  avanceDoble=false;
}
bool Peon::getAvanceDoble(){
  return avanceDoble;
}
bool Peon::validarMovimiento(int x_New, int y_New,Pieza* Tablero[][8]){
  int paso = 1;
  if (getColor()=="Blancas"){//  si es blanco
    paso *= -1;
  }
  //Si el movimiento es para avanzar enfrente
  if(x_New == getX() && y_New == getY()+paso && Tablero[y_New][x_New]==NULL){
    setContador(getContador()+1);
    setX(x_New);
    setY(y_New); 
    return true;
  }
  //Comer en diagonal
  else if ((x_New == getX()+paso && y_New == getY()+paso && Tablero[y_New][x_New]!=NULL && Tablero[y_New][x_New]-> getColor()!=getColor()) || (x_New == getX()-paso && y_New == getY()+paso && Tablero[y_New][x_New]!=NULL && Tablero[y_New][x_New]-> getColor()!=getColor() ) ){
    int acom=getContador();
    setContador(acom+1);
    setX(x_New);
    setY(y_New);
    return true;
  }

  else if(x_New == getX() && y_New == getY()+2*paso && getContador()==0) {//Si el movimiento es para avanzar enfrente 2 casillas
    if(Tablero[y_New][x_New]==NULL && Tablero[y_New-1][x_New]==NULL){
      int acom=getContador();
      setContador(acom+1);
      setAvanceDoble();
      setX(x_New);
      setY(y_New);
      return true;
      
    }
  }
  return false;
}
  

bool Peon::validarComidaPaso(int x_New,int y_New, Pieza* Tablero[][8]){
  int paso = 1;
  if (getColor()=="Blancas"){//  si es blanco
    paso *= -1;
  }  
if(Peon* ptrPeon=dynamic_cast<Peon*>(Tablero[getY()][getX()+1])){
    if(ptrPeon->getAvanceDoble()){
      if(x_New ==getX()+1 && y_New == getY()+paso){
        setX(x_New);
        setY(y_New);
        return true;
      }
    }
    }

if(Peon* ptrPeon=dynamic_cast<Peon*>(Tablero[getY()][getX()-1])){
    if(ptrPeon->getAvanceDoble()){
      if(x_New == getX()-1 && y_New == getY()+paso){
        setX(x_New);
        setY(y_New);
        return true;
      }
    }
      }
return false;
  }

string Peon::imprime(){
   if (getColor()=="Negras"){
        return RED "p";
    } 
    else{
        return "p";
    }
}